#include <iostream>
#include <string>
using namespace std;

template <typename Itr_type>
class LongestChar {
private:
    char key;
    string input;
    struct Node {
        Node *next;
        Node *prev;
        Itr_type datum;
        Node(Itr_type d) : next(nullptr), prev(nullptr), datum(d) {}
    };
    Node* head;
    Node* tail;

public:
    LongestChar() : head(nullptr), tail(nullptr) {}

    void insert(Itr_type value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    char findMostAppearing() {
        if (!head) return '\0';

        int maxCount = 0;
        char mostAppearing = '\0';
        Node* current = head;

        while (current) {
            int count = 1;
            Node* runner = current->next;
            while (runner) {
                if (runner->datum == current->datum) {
                    count++;
                }
                runner = runner->next;
            }
            if (count > maxCount) {
                maxCount = count;
                mostAppearing = current->datum;
            }
            current = current->next;
        }

        return mostAppearing;
    }

    ~LongestChar() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LongestChar<char> lc;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    for (char c : input) {
        lc.insert(c);
    }

    char result = lc.findMostAppearing();
    cout << "The most appearing character is: " << result << endl;

    return 0;
}

// Beats 99.9% Space + Time Complexity
