#include <vector>
#include <string>
using namespace std;

bool checkPalindrome(string str) {
    int i = 0;
    int j = str.size() - 1;

    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

void allPalindromesPermutation(string s, int start, vector<string>& temp, vector<vector<string>>& ans) {
    if (start == s.size()) {
        ans.push_back(temp);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        string sub = s.substr(start, end - start + 1);

        if (checkPalindrome(sub)) {
            temp.push_back(sub);
            allPalindromesPermutation(s, end + 1, temp, ans);
            temp.pop_back();  // Backtrack after the recursive call
        }
    }
}

vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> ans;
    vector<string> temp;
    allPalindromesPermutation(S, 0, temp, ans);
    return ans;
}