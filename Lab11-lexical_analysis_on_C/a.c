#include <stdio.h>

int contain(char* str, int size, char c) {
    for (int i = 0;i < size;i++) {
        if (str[i] == c) return 1;
    }
    return 0;
}

int isdel(char c) {
    return contain(" ,\t\n", 4, c);
}

int isdigit3(char c) {
    return contain("012", 3, c);
}

void handler(char* str, int size) {
    int c1 = 1, c2 = 0, sc = 1;
    if (size == 0) sc = 0;
    if (size == 1 && (str[0] != '0')) sc = 0;
    
    if (!contain("012+-", 5, str[0])) c1 = 0;
    for (int i = 1;i < size - 1;i++) {
        if (!isdigit3(str[i])) c1 = 0;
    }
    if (size > 0 && str[size - 1] == '0') c2 = 1;

    if (c1 && c2 && sc) {
        printf("%s\n", str);
    }
}

int main() {
    char buffer[32];
    int i = 0;
    char cur = getchar();

    while (cur != EOF) {
        if (isdel(cur)) {
            buffer[i] = '\0';
            handler(buffer, i);
            i = 0;
        }
        else {
            buffer[i] = cur;
            i++;
        }
        cur = getchar();
    }

    buffer[i] = '\0';
    handler(buffer, i);
    
    return 0;
}