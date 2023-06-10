# Отчёт по лабораторной работе №20 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Стандартные утилиты UNIX для обработки файлов
## 2. Цель работы
Изучить основные команды обработки текстовых файлов ОС UNIX.
## 3. Задание (вариант № 15)
Подготовить нетривиальные текстовые файлы для иллюстрации работы 3-х утилит (xargs, find, split). Запротоколировать подготовленные примеры и иллюстрации работы для 20-ти утилит пакетного режима с распечаткой используемых текстовых файлов.
## 4. Оборудование:
<b>Процессор:</b> 11th Gen intel(R) Core(TM) i5-11400H @ 2.70GHz<br/>
<b>ОП:</b> 16 ГБ<br/>
<b>SSD:</b> 512 ГБ<br/>
<b>Адрес:</b> 192.168.56.1 <br/>
<b>Монитор:</b> 1920x1080<br/>
<b>Графика:</b> Nvidia GeForce RTX 3050 Ti Laptop GPU <br/>

## 5. Программное обеспечение:

<b>Операционная система семейства:</b> linux(ubuntu) версии 5.15.0-47-generic<br/>
<b>Интерпретатор команд:</b> bash версия 5.1.16<br/>
<b>Система программирования:</b> не использовалась версия —<br/>
<b>Редактор текстов:</b> emacs версия 25.2.2<br/>
<b>Утилиты операционной системы:</b> nano, ls, cd, touch, gcc <br/>
<b>Прикладные системы и программы:</b> GNU C compiler <br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/pepelulka<br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Развернутое описание трех команд:

### xargs

Базовый синтаксис:

первая_команда \| xargs флаги вторая_команда аргументы

Описание работы:

Сначала выполняется любая первая команда и весь её вывод по туннелю передается в xargs. Затем этот вывод разбивается на строки и для каждой строки вызывается вторая команда, а полученная строка передаётся ей в аргументах.

Флаги:

* -0, --null - использовать в качестве разделителя нулевой символ. Обычно он находится в конце строки. По умолчанию, в качестве разделителя используется пробел, перевод строки или табуляция;
* -a, --arg-file - прочитать аргументы, которые надо передать команде из файла;
* -d, --delimiter - использовать нестандартный разделитель строк;
* -E, -e, --eof - индикатор конца файла, все символы после вхождения этой строки игнорируются;
* -l, --max-lines - количество строк, передающихся в одну команду по умолчанию все;
* -n, --max-args - количество параметров, которые передаются в одну команду, по умолчанию все;
* -o, --open-tty - открывать новый терминал для дочерних процессов;
* -p, --interactive - спрашивать пользователя о запуске каждой следующей команды;
* -r, --no-run-if-empty - если входной поток данных пустой, команда не будет выполнена;
* --show-limits - посмотреть ограничения на длину параметров в командной строке;
* -t, --verbose - максимально подробный вывод утилиты.

### find

Базовый синтаксис:

find [директория] [флаги] критерий шаблон [действие]

Описание работы:

Команда для поиска файлов и каталогов на основе специальных условий. Ее можно использовать в различных обстоятельствах, например, для поиска файлов по разрешениям, владельцам, группам, типу, размеру и другим подобным критериям.

Флаги:

* -P - никогда не открывать символические ссылки.
* -L - получает информацию о файлах по символическим ссылкам. Важно для дальнейшей обработки, чтобы обрабатывалась не ссылка, а сам файл.
* -maxdepth - максимальная глубина поиска по подкаталогам, для поиска только в текущем каталоге установите 1.
* -depth - искать сначала в текущем каталоге, а потом в подкаталогах.
* -mount искать файлы только в этой файловой системе.
* -version - показать версию утилиты find.
* -print - выводить полные имена файлов.
* -type f - искать только файлы.
* -type d - поиск папки в Linux.

Критерии:

* -name - поиск файлов по имени.
* -perm - поиск файлов в Linux по режиму доступа.
* -user - поиск файлов по владельцу.
* -group - поиск по группе.
* -mtime - поиск по времени модификации файла.
* -atime - поиск файлов по дате последнего чтения.
* -nogroup - поиск файлов, не принадлежащих ни одной группе.
* -nouser - поиск файлов без владельцев.
* -newer - найти файлы новее чем указанный.
* -size - поиск файлов в Linux по их размеру.

### split

Базовый синтаксис:

split флаги /местоположение/исходного/файла /путь/к/конечной/папке/префикс_имени

Описание работы:

Данная команда разбивает один большой файл на несколько маленьких.

Флаги:

* -a, --suffix-length – задать длину суффикса (количество символов) в имени части файла. По умолчанию это 2 символа.
* --additional-suffix – указать дополнительный суффикс.
* -b, --bytes – разбить файл на части равного указанного размера. Единица измерения – 1 байт, 1000 байт записывается как KB, 1024 как K. По аналогии есть MB (M), GB (G) и так далее.
* -C, --line-bytes – разбить файл на части не более указанного размера, не разделяя строки/записи внутри него.
* -d – использовать числовой суффикс в имени конечного файла вместо алфавитного. Отсчет начинается с нуля.
* --numeric-suffixes – то же самое, что и -d, но еще задаётся начальное число для отсчета.
* -x – использовать hex-префикс вместо алфавитного. Начальное значение – 0.
* --hex-suffixes – то же самое, что и -x, но начальное значение задаётся вручную.
* -e, --elide-empty-files – не создавать пустые файлы при выполнении опции -n.
* -l, --lines – установить максимальное количество строк/записей итогового файла. По умолчанию команда split разбивает файл на 1000 строк.
* -n, --number – разбить файл на чанки (указанное количество частей).
* -t, --separator – установить свой разделительный символ вместо новой строки.
* --verbose – выводить информацию о новых файлах перед их созданием.
* --version – посмотреть версию утилиты.


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

1. ```cmp``` – сравнение двух файлов байт за байтом
2. ```wc``` – обработка входного потока или файла
3. ```diff``` – определеяет изменения в файлах, которые необходимо сделать, чтобы они стали идентичными
4. ```cpp``` – процессор для языка С
5. ```sort``` – сортировка текста
6. ```tail``` – выводит последние N строк файла (по умолчанию - последние 10 строк)
7. ```tee``` – запись вывода любой команды в один или несколько файлов
8. ```od``` – печать файла в восьмеричном формате (по умолчанию)
9. ```sum``` – подсчет контрольной суммы и блоков в файлеы
10. ```cut``` – позволяет вырезать части строк из указанных файлов
11. ```du``` – оценка занимаемого файлового пространства
12. ```gzip``` – архивирование файлов
13. ```join``` – поиск отношений в двух файлах
14. ```paste``` – вставка колонок
15. ```head``` – выводит первые N строк файла (по умолчанию - первые 10 строк)
16. ```tr``` – транслитерация
17. ```uniq``` – создание пустого файла, изменение модификации и времени доступа для любого файла
18. ```df``` – получение полной сводной информации об использовании доступного и используемого дискового пространства файловой системы
19. ```comm``` – объединение соответствующих строк файлов по горизонтали
20. ```mktemp``` – создание временных файлов или каталогов

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола

```
pepelulka@pepelulka:~/Desktop/sandbox$ ls
a  a.txt  b  b.txt  c
pepelulka@pepelulka:~/Desktop/sandbox$ cat a.txt
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
pepelulka@pepelulka:~/Desktop/sandbox$ split -n 4 a.txt
pepelulka@pepelulka:~/Desktop/sandbox$ ls
a  a.txt  b  b.txt  c  xaa  xab  xac  xad
pepelulka@pepelulka:~/Desktop/sandbox$ wc -l a.txt xaa xab xac xad
15 a.txt
 4 xaa
 5 xab
 3 xac
 3 xad
30 total
pepelulka@pepelulka:~/Desktop/sandbox$ cat xaa
1
2
3
4
5pepelulka@pepelulka:~/Desktop/sandbox$ cat xab

6
7
8
9
pepelulka@pepelulka:~/Desktop/sandbox$ ls | xargs
a a.txt b b.txt c xaa xab xac xad
pepelulka@pepelulka:~/Desktop/sandbox$ find a -name "*.meow" | xargs echo
a/l.meow a/t.meow
pepelulka@pepelulka:~/Desktop/sandbox$ find a -name "*.txt" | xargs rm
pepelulka@pepelulka:~/Desktop/sandbox$ find a -name "*.meow" | xargs rm
pepelulka@pepelulka:~/Desktop/sandbox$ find a -name "*.meow" | xargs echo

pepelulka@pepelulka:~/Desktop/sandbox$ find
.
./xad
./xaa
./b
./c
./a.txt
./xac
./a
./a/ba
./a/ca
./b.txt
./xab
pepelulka@pepelulka:~/Desktop/sandbox$ find . -type d -name a
./a
pepelulka@pepelulka:~/Desktop/sandbox$ find . -type d -name ba
./a/ba
pepelulka@pepelulka:~/Desktop/sandbox$ find . -type f -name "*.txt"
./a.txt
./b.txt
pepelulka@pepelulka:~/Desktop/sandbox$ find . -empty -name "*"
./b
./c
./a/ba
./a/ca
pepelulka@pepelulka:~/Desktop/sandbox$ find . -size +100c -size -200c
pepelulka@pepelulka:~/Desktop/sandbox$ find . -size +1c -size -10c
./xad
./xaa
./xac
./xab
pepelulka@pepelulka:~/Desktop/sandbox$ find . -size +3c -size -10c
./xad
./xaa
./xac
./xab
pepelulka@pepelulka:~/Desktop/sandbox$ find . -size +10c -size -10c
pepelulka@pepelulka:~/Desktop/sandbox$ find . -name "*.txt" -exec grep "2" {} \;
2
12
pepelulka@pepelulka:~/Desktop/sandbox$ ls
a  a.txt  b  b.txt  c  xaa  xab  xac  xad
pepelulka@pepelulka:~/Desktop/sandbox$ cd b
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
pepelulka@pepelulka:~/Desktop/sandbox/b$ nano file1
pepelulka@pepelulka:~/Desktop/sandbox/b$ nano file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
Meow 1
meowmeow 2
ZZZ 14
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2
Meow 1
meowmwo
pepelulka@pepelulka:~/Desktop/sandbox/b$ cmp file1 file2
file1 file2 differ: byte 13, line 2
pepelulka@pepelulka:~/Desktop/sandbox/b$ cmp -l file1 file2
13 145 167
15 167  12
cmp: EOF on file2 after byte 15
pepelulka@pepelulka:~/Desktop/sandbox/b$ wc file1
 3  6 25 file1
pepelulka@pepelulka:~/Desktop/sandbox/b$ wc -l file1
3 file1
pepelulka@pepelulka:~/Desktop/sandbox/b$ wc -w file1
6 file1
pepelulka@pepelulka:~/Desktop/sandbox/b$ wc -c file1
25 file1
pepelulka@pepelulka:~/Desktop/sandbox/b$ nano a.c
pepelulka@pepelulka:~/Desktop/sandbox/b$ nano a_m.c
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat a.c
#include <stdio.h>

int main() {
	printf("Hello world!\n");
}
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat a_m.c
#include <stdio.h>

int main() {
	printf("MEOW\n");
	printf("Hello world!\n");
}

pepelulka@pepelulka:~/Desktop/sandbox/b$ diff a.c a_m.c
3a4
> 	printf("MEOW\n");
5a7
>
pepelulka@pepelulka:~/Desktop/sandbox/b$ diff -u a.c a_m.c
--- a.c	2023-06-10 17:39:43.120223986 +0300
+++ a_m.c	2023-06-10 17:40:22.855559434 +0300
@@ -1,5 +1,7 @@
 #include <stdio.h>

 int main() {
+	printf("MEOW\n");
 	printf("Hello world!\n");
 }
+
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  file1  file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls | tee file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ pwd | tee -a file2
/home/pepelulka/Desktop/sandbox/b
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  file1  file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2
Meow 1
meowmwo
/home/pepelulka/Desktop/sandbox/b
pepelulka@pepelulka:~/Desktop/sandbox/b$ echo "Who wants to live forever?" | cur -c 1,2,3,10
Command 'cur' not found, did you mean:
  command 'cwr' from snap cwr (0.4.2)
  command 'sur' from deb subtle (0.11.3224-xi-2.2build4)
  command 'csr' from deb rheolef (7.1-7build1)
  command 'ctr' from deb containerd (1.5.9-0ubuntu3.1)
  command 'car' from deb ucommon-utils (7.0.0-20ubuntu2)
  command 'cpr' from deb node-cpr (3.0.1-4)
  command 'cyr' from deb console-cyrillic (0.9-17.2)
  command 'cu' from deb cu (1.07-27build3)
  command 'cu' from deb opencu (3-2)
  command 'ccr' from deb codecrypt (1.8-1build2)
  command 'cup' from deb cup (0.11b-20160615-2)
  command 'cura' from deb cura (4.13.0-1)
  command 'cut' from deb coreutils (8.32-4.1ubuntu1)
  command 'ur' from deb libur-perl (0.470+ds-2)
  command 'curl' from deb curl (7.81.0-1ubuntu1.7)
See 'snap info <snapname>' for additional versions.
pepelulka@pepelulka:~/Desktop/sandbox/b$ echo "Who wants to live forever?" | cut -c 1,2,3,10
Who
pepelulka@pepelulka:~/Desktop/sandbox/b$ nano tab
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat tab
Meow, man, woman
Clear, clean, cleaning
arch, and, a
pepelulka@pepelulka:~/Desktop/sandbox/b$ cut -d ',' -f 1 tab
Meow
Clear
arch
pepelulka@pepelulka:~/Desktop/sandbox/b$ echo "some cool words" > tab
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat tab
some cool words
pepelulka@pepelulka:~/Desktop/sandbox/b$ cut -d '' -f 1,3 tab
some cool words
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  file1  file2  tab
pepelulka@pepelulka:~/Desktop/sandbox/b$ gzip tab
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  file1  file2  tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ gzip -k file1
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  file1  file1.gz  file2  tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2
Meow 1
meowmwo
/home/pepelulka/Desktop/sandbox/b
pepelulka@pepelulka:~/Desktop/sandbox/b$ echo file2
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2 > echo
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  echo  file1  file1.gz  file2  tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2 | echo

pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2 | sort
/home/pepelulka/Desktop/sandbox/b
Meow 1
meowmwo
pepelulka@pepelulka:~/Desktop/sandbox/b$ comm file1
comm: missing operand after ‘file1’
Try 'comm --help' for more information.
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls
a.c  a_m.c  echo  file1  file1.gz  file2  tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ comm file1 file2
a.c
a_m.c
file1
file2
	Meow 1
	meowmwo
comm: file 2 is not in sorted order
	/home/pepelulka/Desktop/sandbox/b
comm: input is not in sorted order
pepelulka@pepelulka:~/Desktop/sandbox/b$ mktemp
/tmp/tmp.gzeM46jZxX
pepelulka@pepelulka:~/Desktop/sandbox/b$ mktemp -d
/tmp/tmp.K7HJ0bpr10
pepelulka@pepelulka:~/Desktop/sandbox/b$ ls -la /tmp/tmp.K7HJ0bpr10
total 48
drwx------  2 pepelulka pepelulka  4096 июн 10 17:48 .
drwxrwxrwt 23 root      root      40960 июн 10 17:48 ..
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ sum file1
06723     1
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ tail file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ tail -n2 file1
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ tail -lines=+2 file1
tail: invalid option -- 'l'
Try 'tail --help' for more information.
pepelulka@pepelulka:~/Desktop/sandbox/b$ tail --lines=+2 file1
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ tail -c 10 file1
le1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ nano pe
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat pe
pepe
pepe
PEPE
pepe
lulka
LulKa
lulka

pepelulka@pepelulka:~/Desktop/sandbox/b$ uniq pe
pepe
PEPE
pepe
lulka
LulKa
lulka

pepelulka@pepelulka:~/Desktop/sandbox/b$ uniq -ce pe
uniq: invalid option -- 'e'
Try 'uniq --help' for more information.
pepelulka@pepelulka:~/Desktop/sandbox/b$ uniq -c pe
      2 pepe
      1 PEPE
      1 pepe
      1 lulka
      1 LulKa
      1 lulka
      1
pepelulka@pepelulka:~/Desktop/sandbox/b$ uniq -D pe
pepe
pepe
pepelulka@pepelulka:~/Desktop/sandbox/b$ uniq -u pe
PEPE
pepe
lulka
LulKa
lulka

pepelulka@pepelulka:~/Desktop/sandbox/b$ df
Filesystem     1K-blocks     Used Available Use% Mounted on
tmpfs            1600880     2512   1598368   1% /run
/dev/nvme0n1p3  84083928 43054080  36712616  54% /
tmpfs            8004384    29324   7975060   1% /dev/shm
tmpfs               5120        4      5116   1% /run/lock
/dev/nvme0n1p1    101590    31818     69772  32% /boot/efi
tmpfs            1600876      164   1600712   1% /run/user/1000
pepelulka@pepelulka:~/Desktop/sandbox/b$ df -h
Filesystem      Size  Used Avail Use% Mounted on
tmpfs           1,6G  2,5M  1,6G   1% /run
/dev/nvme0n1p3   81G   42G   36G  54% /
tmpfs           7,7G   29M  7,7G   1% /dev/shm
tmpfs           5,0M  4,0K  5,0M   1% /run/lock
/dev/nvme0n1p1  100M   32M   69M  32% /boot/efi
tmpfs           1,6G  164K  1,6G   1% /run/user/1000
pepelulka@pepelulka:~/Desktop/sandbox/b$ df .
Filesystem     1K-blocks     Used Available Use% Mounted on
/dev/nvme0n1p3  84083928 43054080  36712616  54% /
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ head -v file1
==> file1 <==
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ head -n 2 file1
a.c
a_m.c
pepelulka@pepelulka:~/Desktop/sandbox/b$ head -c 13 file1
a.c
a_m.c
filpepelulka@pepelulka:~/Desktop/sandbox/b$ touch od.txt
pepelulka@pepelulka:~/Desktop/sandbox/b$ echo "12345" > od.txt
pepelulka@pepelulka:~/Desktop/sandbox/b$ od -b od.txt
0000000 061 062 063 064 065 012
0000006
pepelulka@pepelulka:~/Desktop/sandbox/b$ od -c od.txt
0000000   1   2   3   4   5  \n
0000006
pepelulka@pepelulka:~/Desktop/sandbox/b$ od -i od.txt
0000000   875770417        2613
0000006
pepelulka@pepelulka:~/Desktop/sandbox/b$ od -An od.txt
 031061 032063 005065

pepelulka@pepelulka:~/Desktop/sandbox/b$ cpp a.c
# 0 "a.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "a.c"
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 486 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 559 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 487 "/usr/include/features.h" 2 3 4
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 209 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4

# 209 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 37 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 39 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 1 3 4




# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 40 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 41 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 42 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 43 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 44 "/usr/include/stdio.h" 2 3 4
# 52 "/usr/include/stdio.h" 3 4
typedef __gnuc_va_list va_list;
# 63 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 77 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;






typedef __fpos_t fpos_t;
# 133 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 134 "/usr/include/stdio.h" 2 3 4
# 143 "/usr/include/stdio.h" 3 4
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
# 178 "/usr/include/stdio.h" 3 4
extern int fclose (FILE *__stream);
# 188 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 205 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;




extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 222 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));






extern int fflush (FILE *__stream);
# 239 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 258 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 293 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 308 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 328 "/usr/include/stdio.h" 3 4
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
# 403 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));





# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 119 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
# 431 "/usr/include/stdio.h" 2 3 4



extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 459 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));





extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 513 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);






extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 538 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);
# 549 "/usr/include/stdio.h" 3 4
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);
# 565 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
# 632 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;







extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
# 702 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);







extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);
# 736 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 760 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 786 "/usr/include/stdio.h" 3 4
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;



extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;







extern void perror (const char *__s);




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 823 "/usr/include/stdio.h" 3 4
extern int pclose (FILE *__stream);





extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;






extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
# 867 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 885 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 902 "/usr/include/stdio.h" 3 4

# 2 "a.c" 2


# 3 "a.c"
int main() {
 printf("Hello world!\n");
}

pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file2
Meow 1
meowmwo
/home/pepelulka/Desktop/sandbox/b
pepelulka@pepelulka:~/Desktop/sandbox/b$ paste file1 file2
a.c	Meow 1
a_m.c	meowmwo
file1	/home/pepelulka/Desktop/sandbox/b
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ paste -d '_' file1 file2
a.c_Meow 1
a_m.c_meowmwo
file1_/home/pepelulka/Desktop/sandbox/b
file2_
pepelulka@pepelulka:~/Desktop/sandbox/b$ paste -s file1 file2
a.c	a_m.c	file1	file2
Meow 1	meowmwo	/home/pepelulka/Desktop/sandbox/b
pepelulka@pepelulka:~/Desktop/sandbox/b$ du *
4	a.c
4	a_m.c
4	echo
4	file1
4	file1.gz
4	file2
4	od.txt
4	pe
4	tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ du --apparent-size *
1	a.c
1	a_m.c
1	echo
1	file1
1	file1.gz
1	file2
1	od.txt
1	pe
1	tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ du --apparent-size -b *
62	a.c
82	a_m.c
49	echo
22	file1
43	file1.gz
49	file2
6	od.txt
39	pe
40	tab.gz
pepelulka@pepelulka:~/Desktop/sandbox/b$ tr a b
aaasdadsa adsad asd
bbbsdbdsb bdsbd bsd
pepelulka@pepelulka:~/Desktop/sandbox/b$ tr -d [:lower:]
sadASDSADasdasdSDSADsda
ASDSADSDSAD
pepelulka@pepelulka:~/Desktop/sandbox/b$ cat file1
a.c
a_m.c
file1
file2
pepelulka@pepelulka:~/Desktop/sandbox/b$ tr 'fe' 'pk' < file1
a.c
a_m.c
pilk1
pilk2
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 10.06.23 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

<b>Защита</b>

## 11. Выводы
Было выяснено, что OC UNIX не только имеет прекрасные средства программирования, но и обладает массой простых утилит, позволяющих выполнять многие сложные работы с файлами без программирования путем последовательного и конвейерного выполнения этих программ. Были изучены некоторые из них. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________
