#include <stdio.h>

void swap(char* string, int ind1, int ind2) {
    char temp = string[ind1];
    string[ind1] = string[ind2];
    string[ind2] = temp;
}

void solve() {
    char buffer[40];
    int ptr = 0;
    char cur;
    
    cur = getchar();
    while (cur != '\n') {
        buffer[ptr] = cur; ptr++;
        cur = getchar();
    }
    buffer[ptr] = '\0';
    swap(buffer, 0, ptr - 1);
    printf(buffer);
}

int main() {
    solve();
    return 0;
}  