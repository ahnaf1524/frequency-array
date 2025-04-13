#include <stdio.h>

int main() {

// 📘 𝗧𝗵𝗲𝗼𝗿𝘆: What is a Frequency Array?
// A frequency array is a simple array that counts how many times each element occurs in another array or string.

// 🧠 Key Idea:
// If you're working with elements in a known range, like 0 to 9, or letters 'a' to 'z', you can use an array to store the count (frequency) of each element.

// The index of the frequency array represents the value or character, and the value at that index is the number of times it occurs.

  int arr[] = {1, 4, 2, 4, 3, 2, 1, 1};
  // ========= We want to know: =========
  // 1. How many times does 1 appear?
  // 2. How many times does 2 appear?
  // 3. ...and so on (only numbers 0–9 are allowed).
  int n = sizeof(arr) / sizeof (arr[0]);
  int freq[10] = {0}; // Frequency array for numbers 0 to 9
  // count frequency
  for(int i = 0; i < n; ++i) {
    freq[arr[i]]++;
  }
  // Print Frequency
  printf("Element\tFrequency\n");
  for(int i = 0; i < n; ++i) {
    if(freq[i] > 0) {
      printf("%d \t     %d\n", i, freq[i]);
    }
  } 

//   🧑‍🎓 Explanation
// We made an array freq[10] to store frequencies of numbers 0 to 9.

// Every time we see a number like arr[i] = 2, we do freq[2]++.

// After processing, freq[i] tells us how many times i appears in the array.
  return 0;
}