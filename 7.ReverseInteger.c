#include <stdio.h>

int reverse(int x) {
    int rev = 0;
    int sig = x > 0 ? 1 : -1;;
    if (x < 0) x = -x;
    while (x % 10 == 0) {
        x /= 10;
    }

    while (x) {
        rev = rev*10 + x % 10;
        x /= 10;
    }

    return rev*sig;
}

int main()
{
    printf("reverse(%d): %d\n", 123, reverse(123));
    printf("reverse(%d): %d\n", -123, reverse(-123));
    printf("reverse(%d): %d\n", 100, reverse(100));
    printf("reverse(%d): %d\n", -100, reverse(-100));
    printf("reverse(%d): %d\n", 1000000003 , reverse(1000000003 ));
}
