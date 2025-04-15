#include <stdio.h>

int main() {
  int arr[] = {1, 3, 2, 1, 4, 1, 3, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  int freq[10] = {0};

  for(int i = 0; i < n; ++i) {
    freq[arr[i]]++;
  }
  
  int maxFreq = 0, mostFrequent = -1;
  for(int i = 0; i < n; ++i) {
    if(freq[i] > maxFreq) {
      maxFreq = freq[i];
      mostFrequent = i;
    }
  }
  printf("Most Frequent Element: %d (Frequency : %d)\n",mostFrequent,maxFreq);
  return 0;
}