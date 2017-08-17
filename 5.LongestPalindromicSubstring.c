#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    char* h = malloc(256);
    strcpy(h, s);

    int len = strlen(s);
    if (len <= 0) {
        return "";
    }

    int start, end;
    int i, j, max_sub_len = 0;
    for (i = 0; i < len; i++) {
        int sub_len = 0;
        for (j = i+1; j < len; j++) {
            if (s[i] == s[j]) {
                sub_len = j - i;
                break;
            }
        }
        if (max_sub_len < sub_len) {
            start = i;
            end = j;
            max_sub_len = sub_len;
        }
    }

    if (max_sub_len > 0) {
        h[end+1] = '\0';
        return h + start;
    }

    return "";
}

int main()
{
    const char* str1 = "abcabcbb";
    const char* str2 = "bbbbb";
    const char* str3 = "pwwkew";
    const char* str4 = "babad";
    const char* str5 = "cbbd";

    printf("%20s: |%s|\n", str1, longestPalindrome(str1));
    printf("%20s: |%s|\n", str2, longestPalindrome(str2));
    printf("%20s: |%s|\n", str3, longestPalindrome(str3));
    printf("%20s: |%s|\n", str4, longestPalindrome(str4));
    printf("%20s: |%s|\n", str5, longestPalindrome(str5));
}
