int strStr(char* haystack, char* needle) {
    int i, len = strlen(haystack), need_len = strlen(needle);
    if (len <= 0 || need_len <= 0) {
        return -1;
    }

    for (i = 0; i < len - need_len; i++) {
        if (strncmp(haystack+i, needle, need_len) == 0) {
            return i;
        }
    }
}

int main()
{
    char* haystack = "abcdbcdbdb";
    char* needle = "bd";

    int start = strStr(haystack, needle);
    if (start >= 0) {
        printf("find needle '%s' at %d pos\n", needle, start);
    } else {
        printf("'%s' not found in '%s'\n", needle, haystack);
    }
}
