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
