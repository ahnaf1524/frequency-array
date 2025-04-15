#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%s", str);  // Read the input string

    int freq[26] = {0}; // Array to count frequency of each lowercase letter (a-z)

    // Step 1: Count frequency of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        freq[ch - 'a']++; // Convert character to index (0 for 'a', 1 for 'b', ..., 25 for 'z')
    }

    int oddCount = 0; // To count how many characters have an odd frequency

    // Step 2: Count how many characters occur an odd number of times
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    /*
        🔍 Logic Explanation:
        ---------------------
        To form a palindrome:
        - All characters must appear an even number of times.
        - At most ONE character can appear an odd number of times (for the middle position in odd-length palindromes).
        => So, if the number of characters with odd frequency is more than 1, we can't form a palindrome.

        ✅ oddCount <= 1 → YES, can be rearranged into a palindrome
        ❌ oddCount > 1  → NO, cannot be rearranged into a palindrome
    */

    // Step 3: Output result based on the number of odd-frequency characters
    if (oddCount <= 1) {
        printf("YES, can be rearranged to a palindrome\n");
    } else {
        printf("NO, cannot be rearranged to a palindrome\n");
    }

    return 0;
}
