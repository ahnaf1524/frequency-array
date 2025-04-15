#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

  char str[1001];
  scanf("%s");

  int freq[26] = {0};

  for(int i = 0; str[i] != '\0'; ++i) {
    char ch = str[i];
    freq[ch - 'a']++;
  }

  bool isUnique = 1;
  for(int i = 0; i < 26; ++i) {
    char ch = str[i];
    if(freq[ch - 'a'] > 0) {
      isUnique = false;
      break;
    }
    isUnique = true;
  }
   if (isUnique) {
        printf("YES, all characters are unique\n");
    } else {
        printf("NO, duplicate characters found\n");
    }
  return 0;
}


