#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool areAnagrams(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;

    vector<int> freq(26, 0);

    for (size_t i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
        freq[s2[i] - 'a']--;
    }

    for (int count : freq) {
        if (count != 0) return false;
    }

    return true;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "YES, they are anagrams." << endl;
    else
        cout << "NO, they are not anagrams." << endl;

    return 0;
}