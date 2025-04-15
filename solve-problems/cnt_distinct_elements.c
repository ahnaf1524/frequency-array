// Count Distinct Elements
#include <stdio.h>
#define MAX 100

int main() {

  int a[] = {1, 2, 2, 3, 1, 4, 5};
  int len = sizeof(a) / sizeof(a[0]);

  int freq[MAX] = {0};

  for(int i = 0; i < len; ++i) {
    freq[a[i]]++;
  }

  int distinct_cnt = 0;

  for(int i = 0; i < len; ++i) {
    if(freq[i]  > 0) {
      distinct_cnt++;
    }
  }

  printf("%d\n",distinct_cnt);
  return 0;
}
