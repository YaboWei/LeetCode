#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    int rev = 0;

    if (x == 0) {
        return 1;
    }
    if (x % 10 == 0) {
        return 0;
    }

    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return x == rev || x == rev/10;
}

int main()
{
    int val = 121;
    printf("%9d %s\n", val, isPalindrome(val) ? "Palindrome" : "no");
    val = 12321;
    printf("%9d %s\n", val, isPalindrome(val) ? "Palindrome" : "no");
    val = 123321;
    printf("%9d %s\n", val, isPalindrome(val) ? "Palindrome" : "no");
    val = 1233210000;
    printf("%9d %s\n", val, isPalindrome(val) ? "Palindrome" : "no");
}
