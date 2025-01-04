#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <map>
#include <mutex>
using namespace std::chrono_literals;

std::mutex mtx;

void refreshForecast(std::map<std::string, int>& forecastMap) {
    while (true) {
        std::lock_guard<std::mutex> lock(mtx);
        for (auto& item : forecastMap) {
            item.second += (rand() % 3 - 1);
            std::cout << item.first << " - " << item.second << "°F" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
        std::this_thread::sleep_for(2000ms);
    }
}

void predictWeather(int& temp) {
    if (temp <= 0) {
        std::cout << "Freezing conditions likely." << std::endl;
    } else if (temp <= 32) {
        std::cout << "Cold weather expected." << std::endl;
    } else if (temp <= 60) {
        std::cout << "Mild weather ahead." << std::endl;
    } else if (temp <= 85) {
        std::cout << "Warm weather expected." << std::endl;
    } else {
        std::cout << "Hot and possibly humid conditions." << std::endl;
    }
}

int main() {
    std::map<std::string, int> forecastMap = {
        {"Los Angeles", 76},
        {"New York City", 43},
        {"Miami", 78},
        {"Ann Arbor", 33}
    };

    std::thread bgWorker(refreshForecast, std::ref(forecastMap));

    while (true) {
        std::string city;
        std::cout << "Enter city name to predict weather (or type 'exit' to quit): ";
        std::cin >> city;

        if (city == "exit") {
            break;
        }

        std::lock_guard<std::mutex> lock(mtx);
        if (forecastMap.find(city) != forecastMap.end()) {
            int temp = forecastMap[city];
            std::cout << "Current temperature in " << city << ": " << temp << "°F" << std::endl;
            predictWeather(temp);
        } else {
            std::cout << "City not found in forecast data." << std::endl;
        }
    }

    bgWorker.detach();

    return 0;
}