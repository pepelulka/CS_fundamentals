#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_del(char c) {
    return (c == ' ') || (c == '\t') || (c == '\n') || (c == ',');
}

void swap(char* string, int ind1, int ind2) {
    char temp = string[ind1];
    string[ind1] = string[ind2];
    string[ind2] = temp;
}

void swap_and_print(char* buffer) {
    if (buffer[0] == '-' || buffer[0] == '+') swap(buffer, 1, strlen(buffer) - 1);
    else swap(buffer, 0, strlen(buffer) - 1);
    printf("%s\n", buffer);
}

void solve() {
    int ptr = 0;
    char cur;
    char buffer[12];

    cur = getchar();
    while (cur != EOF) {
        if (is_del(cur) && ptr != 0) {
            buffer[ptr] = '\0';
            swap_and_print(buffer);
            ptr = 0;
        }
        else if (!is_del(cur)) {
            buffer[ptr] = cur;
            ptr++;
        }
        cur = getchar();
    }
}

int main() {
    solve();
    return 0;
}  