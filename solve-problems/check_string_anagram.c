/*
📘 Anagram Rule:
--------------------------------------------------
🔹 Two strings are anagrams if:
   1️⃣ They contain the **same characters**
   2️⃣ Each character appears **exactly the same number of times**
   3️⃣ The **order can be different**

📥 Input/Output Examples:
--------------------------------------------------
🔹 Input:   s1 = "listen", s2 = "silent"
🔹 Output:  YES ✅

🔹 Input:   s1 = "hello", s2 = "bello"
🔹 Output:  NO ❌

🧠 Concept: Frequency Array Technique
--------------------------------------------------
✅ Use a frequency array of size 26 (for letters 'a' to 'z')

🔄 Steps:
1. For every character in `s1`, increment the frequency:
     freq[s1[i] - 'a']++;

2. For every character in `s2`, decrement the frequency:
     freq[s2[i] - 'a']--;

🔍 Logic Behind It:
- Adding characters from `s1` increases the count.
- Subtracting characters from `s2` decreases the count.
- If both strings are perfect anagrams, **all values in freq[] become zero**.

❌ If any value in freq[] is not zero → the strings are NOT anagrams.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//  if two strings are anagrams
bool areAnagrams(char s1[], char s2[]) {
  // Step 1: Check if lengths are different → Not anagrams
  if(strlen(s1) != strlen(s2)) return false;

  // Step 2: Declare a frequency array of size 26 (for 'a' to 'z')
  // freq[0] → 'a', freq[1] → 'b', ..., freq[25] → 'z'
  int freq[26] = {0};

  // Step 3: Loop through both strings
  for(int i = 0; s1[i] != '\0'; ++i) {
    /*
      ✅ s1[i] - 'a' gives the index for character s1[i]
         - Example: if s1[i] = 'c'
           → 'c' - 'a' = 2
           → So, freq[2] is used for 'c'
      
      ✅ This converts characters into array indexes from 0 to 25
         'a' → 0, 'b' → 1, ..., 'z' → 25
    */

    // ✅ Add 1 for each character in s1
    freq[s1[i] - 'a']++;

    // ✅ Subtract 1 for each character in s2
    freq[s2[i] - 'a']--;

    /*
      🧠 Why subtract for s2?
      → We are canceling out the characters.
      → Adding for s1 and subtracting for s2 should result in 0
         if both strings have the same characters with the same frequency.

      🎯 Example:
      s1 = "abc", s2 = "cab"
      freq['a'-'a'] = +1 then -1 → 0
      freq['b'-'a'] = +1 then -1 → 0
      freq['c'-'a'] = +1 then -1 → 0

      🎯 Example:
      s1 = "abc", s2 = "cabb"

      freq['a' - 'a'] = +1 then -1 → 0
      freq['b' - 'a'] = +1 then -1 → 0
      freq['c' - 'a'] = +1 then -1 → 0
      freq['b' - 'a'] = -1 again   → -1 ❌

      🔍 Explanation:
      - One extra 'b' in s2 causes imbalance.
      - freq[] should have all zeros if anagrams.
      - Here, freq[1] = -1 → Not anagram.

    */
  }

  // Step 4: Check if all values in freq[] are 0
  for(int i = 0; i < 26; ++i) {
    if(freq[i] != 0) {
      // ❌ If any count is not 0 → strings are not anagrams
      return false;
    }
  }

  // ✅ All counts are 0 → strings are anagrams
  return true;
}

int main() {
  char str1[100], str2[100];

  scanf("%s%s", str1, str2);

  if(areAnagrams(str1, str2)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}



/*
🧠 Frequency Array Visualization for Anagram Check

Imagine freq[] as a set of 26 buckets — one for each lowercase letter from 'a' to 'z'.

🔢 Step-by-step Example:

1. String 1: "listen"
   - Go through each character and put a marble (increment) in the corresponding bucket.
   - Example:
     'l' → freq['l' - 'a']++ → freq[11]++
     'i' → freq['i' - 'a']++ → freq[8]++
     ...
   - After processing "listen", freq[] looks like:
     a:0 b:0 c:0 d:0 e:1 f:0 g:0 h:0 i:1 j:0 k:0 l:1 m:0 n:1 o:0 ...
     s:1 t:1 u:0 v:0 w:0 x:0 y:0 z:0

2. String 2: "silent"
   - For each character, take out a marble (decrement) from the same bucket.
   - If strings are true anagrams, all bucket values will return to 0.
   - After "silent":
     All letters cancel out and freq[] becomes all zeros.

✅ Conclusion:
If every value in freq[] is 0 after adding from s1 and subtracting from s2,
then the strings are anagrams.

🚫 If Not Anagrams:
Example: s1 = "hello", s2 = "bello"
   - 'h' will remain +1
   - 'b' will become -1
   - Result: Not all zero → Not anagrams

🔁 Summary:
✔ Add letters from s1 (freq[c - 'a']++)
✔ Subtract letters from s2 (freq[c - 'a']--)
✔ If final freq[] has only zeros → Anagrams
✔ If any freq[i] != 0 → Not anagrams
*/
