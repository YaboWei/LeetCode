#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int myAtoi(char* str) {
    if (str == NULL) {
        return 0;
    }

    int len = strlen(str);
    if (len <= 0) {
        return 0;
    }

    int index = 0;
    int sum = 0;

    int negiv = str[0] == '-' ? 1 : 0;
    for (index = negiv; index < len; index++) {
        if (str[index] > '9' || str[index] < '0') {
            return 0;
        }
        sum = sum*10 + str[index] - '0';
    }

    if (negiv == 1) {
        sum = -sum;
    }

    return sum;
}

int main()
{
    printf("%s myAtoi: %d\n", "123ll", myAtoi("12311"));
    printf("%s myAtoi: %d\n", "-123ll", myAtoi("-12311"));
    printf("NULL myAtoi: %d\n", NULL, myAtoi(NULL));
    printf("\"\" myAtoi: %d\n", myAtoi(""));
}
