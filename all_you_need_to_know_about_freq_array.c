#include <stdio.h>

int main() {

  // ✅ 1. Index = Value Mapping
  // In frequency arrays, index represents the element, and the value at that index is the count.
  int a[] = {10 , 20 , 10 , 30 , 20};
  int freq[50] = {0}; // initially all zero
  freq[10] = 2;
  freq[20] = 2;
  freq[30] = 1;
  // In frequency arrays, index represents the element, and the value at that index is the count.
  // ✅ 2. Only Works for Known Small Ranges
  // Good: digits (0-9), letters ('a'-'z'), small values (≤ 1000)
  // Bad: large values (like 10^6 or negative numbers)
  //  In such cases, use `unordered_map` in C++
  //✅ 3. Can Be Used for Any Type
  // i) Numbers → freq[arr[i]]++
  // ii) Characters → freq[ch - 'a']++ (for 'a' to 'z')
  // iii) ASCII → freq[ch]++ (use 128 or 256 size)
  // iv) Matrix/Grid values → freq[grid[i][j]]++

  return 0;
}