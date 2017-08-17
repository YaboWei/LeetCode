int lengthOfLongestSubstring(char* s) {
    char h[256] = {0};

    int len = strlen(s);
    if (len <= 0) {
        return len;
    }

    int i, j, max_sub_len = 0;
    for (i = 0; i < len; i++) {
        int sub_len = 0;
        memset(h, 0, sizeof(h));
        for (j = i; j < len; j++) {
            if (h[s[j]] != 0) {
                if (max_sub_len < sub_len) {
                    max_sub_len = sub_len;
                }
                break;
            }
            h[s[j]]++;
            sub_len++;
        }
    }
    return max_sub_len;
}

int main()
{
    const char* str1 = "abcabcbb";
    const char* str2 = "bbbbb";
    const char* str3 = "pwwkew";

    printf("%20s: %d\n", str1, lengthOfLongestSubstring(str1));
    printf("%20s: %d\n", str2, lengthOfLongestSubstring(str2));
    printf("%20s: %d\n", str3, lengthOfLongestSubstring(str3));
}
