#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>

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
    printf("<имя исполняемого файла> print <имя бинарного файла> - вывод таблицыя\n<имя исполняемого файла> func <имя бинарного файла> <p> - вычисление функции по заданию.\n");
}

void abitPrint(Abit *abit) {
    assert(abit != NULL);
    putchar('|');
    char surname[21];
    strcpy(surname, abit->surname);
    printf("%s", stringComplement(surname, 20));
    putchar('|');
    printf("%c%c      ", abit->initials[0], abit->initials[1]);
    putchar('|');
    printf("%c  ", abit->gender);
    putchar('|');
    char *schnum = intToString(abit->schoolNumber, 10);
    printf("%s", stringComplement(schnum, 11));
    putchar('|');
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

    if (argc < 3) printUsage();
    if (argc == 3 && strcmp(argv[1], "print") == 0) {
        FILE *bin = fopen(argv[2], "r");
        if (bin) printTable(bin);
        else printf("Ошибка ввода.\n");
    } else if (argc == 4 && strcmp(argv[1], "func") == 0) {
        FILE *bin = fopen(argv[2], "r");
        if (bin) func(bin, atoi(argv[3]));
        else printf("Ошибка ввода.\n");
    }

    return 0;
}
