#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    scanf("%s", str);  // Take the input string

    int freq[26] = {0}; // Array to store frequency of each lowercase letter

    /*
        Logic:
        Go through each character.
        If we’ve already seen this character (freq > 0), it's not unique.
        Otherwise, mark it as seen (freq[ch - 'a'] = 1).
    */

    int isUnique = 1; // Flag to check uniqueness, initially assume all characters are unique

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Check if this character already appeared
        if (freq[ch - 'a'] > 0) {
            isUnique = 0; // Duplicate found
            break;
        }

        freq[ch - 'a'] = 1; // Mark character as seen
    }

    // Output result
    if (isUnique) {
        printf("YES, all characters are unique\n");
    } else {
        printf("NO, duplicate characters found\n");
    }

    return 0;
}
