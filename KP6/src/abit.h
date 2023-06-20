#ifndef __ABIT__
#define __ABIT__

#include <stdbool.h>

typedef struct {
    char surname[40];
    char initials[2];
    bool gender; // 0 - female, 1 - male
    int schoolNumber;
    bool isMedalist;
    int marks[3]; // "64, 56, 88"
    bool essay;
} Abit;

#endif
