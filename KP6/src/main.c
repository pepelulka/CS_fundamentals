#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>
#include <stdbool.h>

#include "abit.h"

char *stringComplement(char *str, int n) {
    int len = strlen(str);
    for (int ptr = len; ptr < n; ptr++) {
        str[ptr] = ' ';
        str[ptr + 1] = '\0';
    }
    return str;
}

void printBlank(int n) {
    for (int i = 0;i < n;i++) putchar(' ');
}

char* intToString(int val, int base) {
	static char buf[32] = {0};
    if (val == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }
	int i = 30;
    buf[31] = '\0';
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

// 20:8:3:11:8:7:7:7:15
const char * HEADER = "|Фамилия             |Инициалы|Пол|Номер школы|Медалист|Оценка1|Оценка2|Оценка3|Зачет Сочинение|\n";
const char * DELIM =  "|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|\n";

void printUsage() {
    printf("main <filename> -f - печать таблицы\nmain <filename> -p <p> - вычисление функции по заданию.\n");
}

void abitPrint(const Abit *abit) {
    assert(abit != NULL);
    putchar('|');
    char surname[21];
    strcpy(surname, abit->surname);
    printf("%s", stringComplement(surname, 20));
    putchar('|');
    printf("%c%c      ", abit->initials[0], abit->initials[1]);
    putchar('|');
    char charAbitGender;
    if (abit->gender) charAbitGender = 'M';
    else charAbitGender = 'F';
    printf("%c  ", charAbitGender);
    putchar('|');
    char *schnum = intToString(abit->schoolNumber, 10);
    printf("%s", stringComplement(schnum, 11));
    putchar('|'); //
    printf("%d       ", abit->isMedalist);
    putchar('|');
    char mark1[8];
    strcpy(mark1, intToString(abit->marks[0], 10));
    printf("%s", stringComplement(mark1, 7));
    putchar('|');
    char mark2[8];
    strcpy(mark2, intToString(abit->marks[1], 10));
    printf("%s", stringComplement(mark2, 7));
    putchar('|');
    char mark3[8];
    strcpy(mark3, intToString(abit->marks[2], 10));
    printf("%s", stringComplement(mark3, 7));
    putchar('|');
    printf("%d              ", abit->essay);
    putchar('|');
    putchar('\n');
}

void printTable(FILE *file) {
    Abit abit;
    printf("%s", HEADER);
    printf("%s", DELIM);
    while (fread (&abit, sizeof(Abit), 1, file) == 1) {
        abitPrint(&abit);
    }
    printf("%s", DELIM);
}

void func(FILE *file, int p) {
    Abit abit;
    printf("%s", HEADER);
    printf("%s", DELIM);
    while (fread (&abit, sizeof(Abit), 1, file) == 1) {
        int sum = abit.marks[0] + abit.marks[1] + abit.marks[2];
        if (sum < p && abit.isMedalist) abitPrint(&abit);
    }
    printf("%s", DELIM);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Rus");

    if (argc == 1) {
        printUsage();
        return 0;
    }
    int p = -1;
    int mode = 0; // 0 - not defined; 1 - file print; 2 - function; 3 - undetermined
    bool wasFilename = false;
    bool wasPreviousP = false;
    char filename[40];
    for (int i = 1;i < argc;i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (mode == 0) mode = 1;
            else mode = 3;
        } else if (strcmp(argv[i], "-p") == 0) {
            wasPreviousP = true;
        } else if (wasPreviousP) {
            if (mode == 0) mode = 2;
            else mode = 3;
            p = atoi(argv[3]);
        } else {
            wasFilename = true;
            strcpy(filename, argv[i]);
        }
        if (wasPreviousP && strcmp(argv[i], "-p") != 0) wasPreviousP = false;
    }
    if (wasFilename && mode == 1) {
        FILE *bin = fopen(filename, "r");
        if (bin) printTable(bin);
        else printf("Ошибка ввода.\n");
        fclose(bin);
    } else if (wasFilename && mode == 2) {
        FILE *bin = fopen(filename, "r");
        if (bin) func(bin, p);
        else printf("Ошибка ввода.\n");
        fclose(bin);
    } else {
        printUsage();
    }

    return 0;
}
