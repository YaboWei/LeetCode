#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 20

char* convert(const char* s, int numRows) {
    int l, r, str_index = 0;
    char* zigzag = (char*)malloc(numRows * ROW);
    char* conv_str = (char*)malloc(100);
    memset(zigzag, 0, numRows * ROW);

    if (numRows % 2 == 0) {
        return "";
    }

    printf("%s\n", s);
    for (l = 0; l < ROW; l++) {
        for (r = 0; r < numRows; r++) {
            if (s[str_index] == '\0') {
                goto finished;
            }
            if (l % 2 == 0) {
                zigzag[r*ROW+l] = s[str_index++];
            } else {
                if (r == (numRows/2)) {
                    zigzag[r*ROW+l] = s[str_index++];
                } else {
                    zigzag[r*ROW+l] = ' ';
                }
            }
        }
    }

finished:
    str_index = 0;
    for (r = 0; r < numRows; r++) {
        for (l = 0; l < ROW; l++) {
            printf("%c ", zigzag[r*ROW+l]);
            if (zigzag[r*ROW+l] != '\0' && zigzag[r*ROW+l] != ' ') {
                conv_str[str_index++] = zigzag[r*ROW+l];
            }
        }
        printf("\n");
    }
    conv_str[str_index] = '\0';

    return conv_str;
}

int main()
{
    const char* str = "PAYPALISHIRING";
    printf("%s\n", convert(str, 3));
}
