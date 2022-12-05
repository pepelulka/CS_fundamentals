#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef unsigned uint;
typedef uint64_t Set;

Set VOWELS =  ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
);


// Basic set functions
bool set_in(Set *x, uint index) {
    return (*x >> index) & 1;
}

void set_set(Set *x, uint index) {
    *x |= (1ULL << index);
}

void set_reset(Set *x, uint index) {
    *x &= ~(1ULL << index);
}

void set_clear(Set *x, uint index) {
    memset(x, 0, sizeof x);
}

void set_union(Set *x, Set *y) {
    *x |= *y;
}

void set_intersection(Set *x, Set *y) {
    *x &= *y;
}

void set_complement(Set *x) {
    *x = ~*x;
}

void set_difference(Set *x, Set *y) {
    *x &= ~*y;
}

// Main part of program

bool is_vowel(int code) {
    return !(set_in(&VOWELS, code));
}

bool check(char* string1, char* string2) {
    Set set1 = 0, set2 = 0;

    for (int ptr = 0;string1[ptr] != '\0';ptr++) {
        int code = (string1[ptr] - 'a');
        if (is_vowel(code)) set_set(&set1, code);
    }

    for (int ptr = 0;string2[ptr] != '\0';ptr++) {
        int code = (string2[ptr] - 'a');
        if (is_vowel(code)) set_set(&set2, code);
    }
    
    set_intersection(&set1, &set2);
    return set1 != 0;
}

void solve() {
    bool result = 0;
    char string1[10000], string2[10000];
    scanf("%s", string1); scanf("%s", string2);
    int previous = 1; // Who is previous now?

    while (1) {
        result = result || check(string1, string2);

        if (previous == 1) {
            if (scanf("%s", string1) == EOF) break;
            previous = 2;
        } else {
            if (scanf("%s", string2) == EOF) break;
            previous = 1;
        }
    }

    printf("%d", result);
}

int main(void) {
    solve();
    return 0;
}