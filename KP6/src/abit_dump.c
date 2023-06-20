#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "abit.h"

// delimiter - ;

bool readBase (Abit *abit, FILE *file) {
	char charGender;
	int intIsMedalist;
	int intEssay;
	int res = fscanf(file, "%[^;];%c%c;%c;%d;%d;%d;%d;%d;%d\n",
                           abit->surname,
                           &abit->initials[0],
                           &abit->initials[1],
                           &charGender,
                           &abit->schoolNumber,
                           &intIsMedalist,
                           &abit->marks[0],
                           &abit->marks[1],
                           &abit->marks[2],
                           &intEssay);
	if (res == 10) {
		if (charGender == 'M')
			abit->gender = true;
		else
			abit->gender = false;
		abit->isMedalist = (bool)intIsMedalist;
		abit->essay = (bool)intEssay;
		return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");

	if (argc != 3) {
		printf("Неверный ввод.\n");
		return 1;
	}
	Abit abit;
	memset(&abit, '0', sizeof(Abit));
	FILE *base = fopen(argv[1], "r");
	if (!base) {
		perror("Не удается открыть файл\n");
		return 2;
	}
	FILE *bin = fopen(argv[2], "w");
	if (!bin) {
		perror("Не удается открыть файл\n");
		fclose(base);
		return 2;
	}

	while (readBase (&abit, base)) {
		fwrite(&abit, sizeof(Abit), 1, bin);
	}
	fclose(bin);
	fclose(base);
	return 0;
}
