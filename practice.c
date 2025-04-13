#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAnagrams(char s1[], char s2[]) {
  
  if(strlen(s1) != strlen(s2)) return false;

  int freq[26] = {0};
  
  for(int i = 0; s1[i] != '\0'; ++i) {
    freq[s1[i] - 'a']++;
    freq[s2[i] - 'a']--;
  }

  for(int i = 0; i < 26; ++i) {
    if(freq[i] != 0) {
      return false;
    }
  }
  return true;
}


int main() {

  // "apple" --> "ppale" - anagram
  // "cow" --> "cows"  - anagram
  // len is same
  // both string have same character 
  // order doesn't matter
  // with same frequency (one char only once)

  char s1[100], s2[100];
  scanf("%s%s",s1, s2);

  if(areAnagrams(s1, s2)) {
    printf("Anagram\n");
  }
  else {
    printf("Not an anagram\n");
  }
  return 0;
}


