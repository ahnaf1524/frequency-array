// Most Frequent Character in a String

#include <stdio.h>
#include <string.h>
#define MAX 1005
int main() {

  char str[1005];
  scanf("%s", str);

  int len = strlen(str);

  int freq[26] = {0};

  for(int i = 0; str[i] != '\0'; ++i) {
    char ch = str[i];
    freq[ch - 'a']++;
  }

  int maxFreq = 0;
  char maxFreqChar;

  for(int i = 0; i < len; ++i) {
    if(freq[i] > maxFreq) {
      maxFreq = freq[i];
      maxFreqChar = i + 'a';
    }
  }

  printf("%c\n",maxFreqChar);
  return 0;
}

/*
    Logic:
    1. Count how many times each character appears using a freq array.
    2. Then, go through the freq array to find the character with the highest count.
    3. Convert the index (0–25) back to actual characters ('a'–'z') using (i + 'a').
*/
