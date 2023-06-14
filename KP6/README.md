# Отчёт по заданию №6 по курсовому проекту по циклу дисциплин «Информатика»

<b>Студент группы:</b> <ins>М80-108Б-22 Формалёв Александр Сергеевич, № по списку 19</ins>

<b>Контакты e-mail:</b> <ins>lyadiez@mail.ru</ins>

<b>Работа выполнена:</b> «31» <ins> мая </ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins></ins>

<b>Отчет сдан</b> «1» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема

Обработка последовательной файловой структуры на языке Си

## 2. Цель работы

Разработать последовательную структуру данных для представления простейшей базы данных на
файлах в СП Си в соответствии с заданным вариантом.

## 3. Задание

Составить программу генерации внешнего
нетекстового файла заданной структуры, содержащего представительный набор записей.
Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие для
запроса `p` и распечатать результат.

Действие по выборке данных из файла оформить в виде отдельной программы с параметрами запроса,
вводимыми из стандартного входного текстового файла, или получаемыми из командной строки UNIX.
Второй способ задания параметров обязателен для работ, оцениваемых на хорошо и отлично. Параметры
задаются с помощью ключей `–f [name]` (имя обрабатываемого файла) или `–p [parameter]` (параметры конкретного варианта
задания). Получение параметров из командной строки производится с помощью стандартных библиотечных
функций `argс` и `argv`.

Cтруктуры данных и константы, совместно используемые программами, следует вынести в отдельный
заголовочный файл.

В процессе отладки и тестирования рекомендуется использовать команды обработки текстовых файлов
ОС UNIX и переадресацию ввода-вывода. Сгенерированные и отформатированные тестовые данные
необходимо заранее поместить в текстовые файлы и распечатывать при протоколировании. Рекомендуется
подобрать реальные или правдоподобные тестовые данные. Число наборов тестовых данных должно быть не
менее трёх. Имя файла с бинарными данными является обязательным параметром второй программы.

**Содержимое и структура файла:**

Сведения о вступительных экзаменах абитуриентов: фамилия, инициалы, пол, номер школы, наличие
медали, оценки в баллах и зачет/незачет по сочинению.

**Действие**

Найти абитуриентов-немедалистов, суммарный балл которых выше среднего.

## 4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ

HDD: 952 ГБ

Монитор: 3840x2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: -

Редактор текстов:

Местонахождение и имена файлов программ и данных на домашнем компьютере: -

## 6. Идея, метод, алгоритм решения:

Программа содержит два исполняемых файла: один переводит из текстового формата в бинарный, другой обрабатывает бинарный файл.

## 7. Сценарий выполнения работы:

Makefile:
```

```

main.c:
```src:main.c
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

```

abit.h:
```src:abit.h
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

```

abit_dump.c:
```src:abit_dump.c
#include <stdio.h>
#include <locale.h>

#include "abit.h"

// delimiter - ;

int readBase (Abit *abit, FILE *file) {
	int res = fscanf(file, "%[^;];%c%c;%c;%d;%d;%d;%d;%d;%d\n",
                           abit->surname,
                           &abit->initials[0],
                           &abit->initials[1],
                           &abit->gender,
                           &abit->schoolNumber,
                           &abit->isMedalist,
                           &abit->marks[0],
                           &abit->marks[1],
                           &abit->marks[2],
                           &abit->essay);
	return res == 10;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");

	if (argc != 3) {
		printf("Неверный ввод.\n");
		return 1;
	}
	Abit abit;
	FILE *base = fopen(argv[1], "r");
	FILE *bin = fopen(argv[2], "w");
	if (!base) {
		perror("Не удается открыть файл\n");
		return 2;
	}

	while (readBase (&abit, base)) {
		fwrite(&abit, sizeof(Abit), 1, bin);
	}
	fclose(bin);
	fclose(base);
	return 0;
}

```

data/abits.txt:
```
Pepelulka;RR;M;157;1;88;96;98;1
Lelepupka;LL;F;8;0;43;39;27;0
Formalev;AH;M;107;1;80;60;100;1
Khalimov;IH;M;1;0;10;10;100;1
Meowov;HH;M;14;1;60;60;80;1
Khaeva;VO;F;52;1;90;90;90;1
Osipova;HZ;F;12;0;80;90;90;1
Bityukov;UA;M;14;0;40;50;60;1
Bortakovskiy;AS;M;153;1;60;50;40;1
Chapalda;MS;F;13;0;11;14;15;0
Sharaputdinov;AS;M;39;1;27;44;56;1
Mazaev;VS;M;44;1;89;98;89;0
Miroshnikov;DS;M;73;0;76;87;98;1
Blinov;OM;M;11;0;76;78;87;0
Blinova;MO;F;41;0;56;65;87;1
Terentiev;TV;M;11;1;56;76;90;1
Popov;SS;M;88;1;50;50;50;0
Averyanov;SS;M;54;1;56;56;56;1
Magomedkhanov;MM;M;8;0;87;87;87;0
Ramaldanov;RR;M;46;0;88;96;93;1
```

## 8. Распечатка протокола

```
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./abit_dump ../../data/abits.txt abits_bin
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./main print abits_bin
|Фамилия             |Инициалы|Пол|Номер школы|Медалист|Оценка1|Оценка2|Оценка3|Зачет Сочинение|
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
|Pepelulka           |RR      |M  |157        |1       |88     |96     |98     |1              |
|Lelepupka           |LL      |F  |8          |0       |43     |39     |27     |0              |
|Formalev            |AH      |M  |107        |1       |80     |60     |100    |1              |
|Khalimov            |IH      |M  |1          |0       |10     |10     |100    |1              |
|Meowov              |HH      |M  |14         |1       |60     |60     |80     |1              |
|Khaeva              |VO      |F  |52         |1       |90     |90     |90     |1              |
|Osipova             |HZ      |F  |12         |0       |80     |90     |90     |1              |
|Bityukov            |UA      |M  |14         |0       |40     |50     |60     |1              |
|Bortakovskiy        |AS      |M  |153        |1       |60     |50     |40     |1              |
|Chapalda            |MS      |F  |13         |0       |11     |14     |15     |0              |
|Sharaputdinov       |AS      |M  |39         |1       |27     |44     |56     |1              |
|Mazaev              |VS      |M  |44         |1       |89     |98     |89     |0              |
|Miroshnikov         |DS      |M  |73         |0       |76     |87     |98     |1              |
|Blinov              |OM      |M  |11         |0       |76     |78     |87     |0              |
|Blinova             |MO      |F  |41         |0       |56     |65     |87     |1              |
|Terentiev           |TV      |M  |11         |1       |56     |76     |90     |1              |
|Popov               |SS      |M  |88         |1       |50     |50     |50     |0              |
|Averyanov           |SS      |M  |54         |1       |56     |56     |56     |1              |
|Magomedkhanov       |MM      |M  |8          |0       |87     |87     |87     |0              |
|Ramaldanov          |RR      |M  |46         |0       |88     |96     |93     |1              |
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./main print abits_bin 250
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./main func abits_bin 250
|Фамилия             |Инициалы|Пол|Номер школы|Медалист|Оценка1|Оценка2|Оценка3|Зачет Сочинение|
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
|Formalev            |AH      |M  |107        |1       |80     |60     |100    |1              |
|Meowov              |HH      |M  |14         |1       |60     |60     |80     |1              |
|Bortakovskiy        |AS      |M  |153        |1       |60     |50     |40     |1              |
|Sharaputdinov       |AS      |M  |39         |1       |27     |44     |56     |1              |
|Terentiev           |TV      |M  |11         |1       |56     |76     |90     |1              |
|Popov               |SS      |M  |88         |1       |50     |50     |50     |0              |
|Averyanov           |SS      |M  |54         |1       |56     |56     |56     |1              |
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./main func abits_bin 275
|Фамилия             |Инициалы|Пол|Номер школы|Медалист|Оценка1|Оценка2|Оценка3|Зачет Сочинение|
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
|Formalev            |AH      |M  |107        |1       |80     |60     |100    |1              |
|Meowov              |HH      |M  |14         |1       |60     |60     |80     |1              |
|Khaeva              |VO      |F  |52         |1       |90     |90     |90     |1              |
|Bortakovskiy        |AS      |M  |153        |1       |60     |50     |40     |1              |
|Sharaputdinov       |AS      |M  |39         |1       |27     |44     |56     |1              |
|Terentiev           |TV      |M  |11         |1       |56     |76     |90     |1              |
|Popov               |SS      |M  |88         |1       |50     |50     |50     |0              |
|Averyanov           |SS      |M  |54         |1       |56     |56     |56     |1              |
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./main func abits_bin 300
|Фамилия             |Инициалы|Пол|Номер школы|Медалист|Оценка1|Оценка2|Оценка3|Зачет Сочинение|
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
|Pepelulka           |RR      |M  |157        |1       |88     |96     |98     |1              |
|Formalev            |AH      |M  |107        |1       |80     |60     |100    |1              |
|Meowov              |HH      |M  |14         |1       |60     |60     |80     |1              |
|Khaeva              |VO      |F  |52         |1       |90     |90     |90     |1              |
|Bortakovskiy        |AS      |M  |153        |1       |60     |50     |40     |1              |
|Sharaputdinov       |AS      |M  |39         |1       |27     |44     |56     |1              |
|Mazaev              |VS      |M  |44         |1       |89     |98     |89     |0              |
|Terentiev           |TV      |M  |11         |1       |56     |76     |90     |1              |
|Popov               |SS      |M  |88         |1       |50     |50     |50     |0              |
|Averyanov           |SS      |M  |54         |1       |56     |56     |56     |1              |
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
pepelulka@pepelulka:~/Desktop/labs/repo/KP6/build/bin$ ./main func abits_bin 200
|Фамилия             |Инициалы|Пол|Номер школы|Медалист|Оценка1|Оценка2|Оценка3|Зачет Сочинение|
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
|Bortakovskiy        |AS      |M  |153        |1       |60     |50     |40     |1              |
|Sharaputdinov       |AS      |M  |39         |1       |27     |44     |56     |1              |
|Popov               |SS      |M  |88         |1       |50     |50     |50     |0              |
|Averyanov           |SS      |M  |54         |1       |56     |56     |56     |1              |
|--------------------|--------|---|-----------|--------|-------|-------|-------|---------------|
```

## 9. Замечания автора по существу работы

## 10.Вывод работы:

После выполнения работы, были получены навыки обработки бинарных файлов в Си, а так же строгой обработки ползовательского ввода.

<b>Подпись студента:</b> ________________

