// Leet Code Medium: Longest Palindrome Substring ()
#include <iostream>
using namespace std;

class Solution {
public:
  string longestPalindrome (string s) {
    // We Solve This By Using Central Expansion!
    
    // Base Case: s.length() == 0 || 1
    int len = s.length();
    if (len <= 1) {
      return s; // Longest Substring would be itself.
    }

    auto centralExpansion = [&](int lhs, int rhs) {
      while (lhs >= 0 && rhs < len && s[lhs] == s[rhs]) {
        lhs--;
        rhs++;
      }
      return s.substr(lhs+1, rhs-lhs-1);
    };

    string max = s.substr(0, 1);
    for (size_t i = 0; i <= s.length()-1; ++i) {
      string odd = centralExpansion(i, i);
      string even = centralExpansion(i, i+1);
      if (odd.length() > max.length()) {
        max = odd;
      } if (even.length() > max.length()) { // CONTINUE THE CASE FOR EDGE CASE(S)
        max = even;
      }
    }
    return max;
  }
};

// Time Complexity: O(n^2)
// Status? ACCEPTED