def are_anagrams(s1, s2):
    if len(s1) != len(s2):
        return False

    freq = [0] * 26

    for i in range(len(s1)):
        freq[ord(s1[i]) - ord('a')] += 1
        freq[ord(s2[i]) - ord('a')] -= 1

    for count in freq:
        if count != 0:
            return False

    return True

def main():
    str1 = input("Enter first string: ")
    str2 = input("Enter second string: ")

    if are_anagrams(str1, str2):
        print("YES, they are anagrams.")
    else:
        print("NO, they are not anagrams.")

if __name__ == "__main__":
    main()