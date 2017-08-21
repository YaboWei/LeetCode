#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    if (s == NULL) {
        return false;
    }
    int len = strlen(s);
    if (len <= 0) {
        return false;
    }
    char* stack = malloc(len);
    memset(stack, 0, len);

    int i = 0;
    int head = 0;

    while (i < len) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            printf("push %c\n", s[i]);
            stack[head++] = s[i];
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (strlen(stack) <= 0) {
                return false;
            }

            printf("get %c\n", s[i]);
            switch (s[i]) {
                case ')':
                    if (stack[head-1] == '(') {
                        printf("pop up %c\n", stack[head-1]);
                        stack[head--] = '\0'; // pop up '('
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (stack[head-1] == '[') {
                        printf("pop up %c\n", stack[head-1]);
                        stack[head--] = '\0'; // pop up '('
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (stack[head-1] == '{') {
                        printf("pop up %c\n", stack[head-1]);
                        stack[head--] = '\0'; // pop up '('
                    } else {
                        return false;
                    }
                    break;
            }
        } else {
            return false;
        }
        i++;
    }

    if (head != 0) {
        return false;
    }

    return true;
}

int main()
{
    char* Parentheses = "{()[]{}}";
    printf("%s is %s\n", Parentheses, isValid(Parentheses) ? "valid" : "invalid");
    return 0;
}
