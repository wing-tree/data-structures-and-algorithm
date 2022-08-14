#include <cstdio>
#include <cstring>

void FirstRepeatedChar(char* str) {
    int count[256];
    int i, len(strlen(str));

    memset(count, 0, sizeof(count));

    for (i = 0; i < strlen(str); ++i) {
        if (count[str[i]] == 1) {
            printf("%c", str[i]);
            break;
        } else {
            count[str[i]]++;
        }
    }

    if (i == len) {
        printf("No repeated characters.");
    }
}
