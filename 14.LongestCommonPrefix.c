#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    char* comPre = malloc(100);
    char* first_str = strs[0];
    int minLen = 100;
    for (i = 0; i < strsSize; i++) {
        int len = strlen(strs[0]);
        if (len <= 0) return "";
        if (minLen > len) minLen = len;
    }

    i = 0;
    while (i <= minLen) {
        char c = first_str[i];
        int j = 0;
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] == "\0" || strs[j][i] != c) {
                comPre[i] = '\0';
                return comPre;
            }
            comPre[i] = c;
        }

        i++;
    }

    return "";
}

int main()
{
    char* strs[] = {"leets", "leetcode", "leetc", "leeds"};
    printf("longestCommonPrefix: %s\n", longestCommonPrefix(strs, sizeof(strs)/sizeof(char*)));
}
