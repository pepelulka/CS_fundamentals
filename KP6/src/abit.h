#ifndef __ABIT__
#define __ABIT__

typedef struct {
    char surname[40];
    char initials[2];
    char gender; // 'M' or 'F'
    int schoolNumber;
    int isMedalist;
    int marks[3]; // "64, 56, 88"
    int essay;
} Abit;

#endif
