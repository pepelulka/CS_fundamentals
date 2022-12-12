#include <stdio.h>
#include <string.h>

void swap(char* string, int ind1, int ind2) {
    char temp = string[ind1];
    string[ind1] = string[ind2];
    string[ind2] = temp;
}

void input(char* buffer) {
    int ptr = 0;
    char cur;
    cur = getchar();
    while (cur != '\n') {
        buffer[ptr] = cur; ptr++;
        cur = getchar();
    }
    buffer[ptr] = '\0';
}

int main() {
    char buffer[12];
    input(buffer);
    if (buffer[0] != '-' && buffer[0] != '+') swap(buffer, 1, strlen(buffer) - 1);
    else swap(buffer, 0, strlen(buffer) - 1);
    printf(buffer);
    return 0;
}  