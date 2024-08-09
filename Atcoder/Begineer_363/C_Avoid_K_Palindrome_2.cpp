#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring is a palindrome
bool isPalindrome(const string& str, int start, int len) {
    for (int i = 0; i < len / 2; ++i) {
        if (str[start + i] != str[start + len - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Function to check if any substring of length k is a palindrome
bool containsPalindrome(const string& s, int k) {
    for (int i = 0; i <= s.length() - k; ++i) {
        if (isPalindrome(s, i, k)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    // Sort the string to generate permutations in lexicographical order
    sort(s.begin(), s.end());

    int ans = 0;

    do {
        if (!containsPalindrome(s, k)) {
            ans++;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << endl;
    return 0;
}
