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
//split//
pepelulka@pepelulka:~/gh$ cat file2.txt
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
16
pepelulka@pepelulka:~/gh$ ls
file2.txt
pepelulka@pepelulka:~/gh$ split -n 4 file2.txt
pepelulka@pepelulka:~/gh$ ls
file2.txt  xaa  xab  xac  xad
pepelulka@pepelulka:~/gh$ wc -l file2.txt  xaa  xab  xac  xad
16 file2.txt
 4 xaa
 5 xab
 3 xac
 4 xad
32 итого
//xargs//
pepelulka@pepelulka:~$ ls 'Рабочий стол' | xargs
c8_2.c c8_3.c etst.txt fff.txt file1.txt file2.txt new.txt pepelulka pr1.c sca.txt test1.txt tests45.txt trtr.txt vr.log
pepelulka@pepelulka:~$ find test -name "*.txt" | xargs echo
test/two.txt test/one.txt test/three.txt
pepelulka@pepelulka:~/test$ ls
'file.a b' file.txt one.txt three.txt two.txt
file.png one three two
pepelulka@pepelulka:~/test$ cd ..
pepelulka@pepelulka:~$ find test -name "file.*" | xargs ls
ls: cannot access 'test/file.a': No such file or directory
ls: cannot access 'b': No such file or directory
test/file.png test/file.txt
pepelulka@pepelulka:~$ find test -name "file.*" -print0 | xargs 0 ls -1
'test/file.a b'
test/file.png
test/file.txt
//find//
pepelulka@pepelulka:~$ find
.
./lb12.c~
./dogs.txt
...
...
...
./l01/chrome1/buzz.txt
./l01/p2.txt
./l01/chrome3
./to_mom.txt
./congratulation.txt
./eng_word.txt
pepelulka@pepelulka:~$ find . -type d -name "l*"
./l02
./l01
pepelulka@pepelulka:~$ find . -type f -name "*.c"
./prog_2.c
./copy_prog_1.c
./prog_1.c
./lb12.c
pepelulka@pepelulka:~$ find . -type f -name "*.c" -o -type -d
find: Unknown argument to -type: -
pepelulka@pepelulka:~$ find . -type f -name "*.c" -o -type d
.
./prog_2.c
./l02
./l02/chrome1
./l02/chrome2
./copy_prog_1.c
./prog_1.c
./lb12.c
./l01
./l01/chrome1
./l01/chrome3
pepelulka@pepelulka:~$ find . -empty
./l02/p1.txt
./l02/p3.txt
./l02/chrome1/exe.txt
./l02/chrome1/foo.txt
./l02/chrome2/foo.txt
./tmp.wVLdUS7uPk
./rus_word.txt
./l01/p1.txt
./l01/p3.txt
./l01/chrome1/buzz.txt
./l01/p2.txt
./l01/chrome3
pepelulka@pepelulka:~$ find . -empty -name "*.txt"
./l02/p1.txt
./l02/p3.txt
./l02/chrome1/exe.txt
./l02/chrome1/foo.txt
./l02/chrome2/foo.txt
./rus_word.txt
./l01/p1.txt
./l01/p3.txt
./l01/chrome1/buzz.txt
./l01/p2.txt
pepelulka@pepelulka:~$ find . -size +100c -size -200c
./poem.txt
./res1.txt
./res.txt
./dir.patch
pepelulka@pepelulka:~$ find . -type f -ctime -2 -amin -30 -exec ls -l {} +
-rw-rw-r-- 1 ann ann 564 фев 27 19:14 ./copy_prog_1.c.orig
-rw-rw-r-- 1 ann ann 198 фев 27 19:37 ./dir.patch
pepelulka@pepelulka:~$ find . -name "*stud*" -exec grep "B" {} \;
2 B
3 B
6 ABDC
8 BC
6 BADC
pepelulka@pepelulka:~$ find . -name "*stud*" -exec grep "B" {} +
./answers_stud2.txt:2. B
./answers_stud2.txt:3. B
./answers_stud2.txt:6. ABDC
./answers_stud2.txt:8. BC
./answers_stud1.txt:6. BADC
pepelulka@pepelulka:~$ find . -name "*.orig"
./copy_prog_1.c.orig
pepelulka@pepelulka:~$ find . -name "*.orig" -exec mv {} {}.c \;
pepelulka@pepelulka:~$ find . -name "*.orig*"
./copy_prog_1.orig.c
pepelulka@pepelulka:~$ find . -cmin -10
.
./copy_prog_1.orig.c
pepelulka@pepelulka:~$ find . -cmin -10 | xargs grep "main"
grep: .: Это каталог
./copy_prog_1.orig.c:int main(){
pepelulka@pepelulka:~$ find ~/ -type f -name "tmp.*" -printf '%TY-%Tm-%Td %TT %p\n' | sort -r
//cmp//
pepelulka@pepelulka:~$ cat file1.txt
Петр 1
Ярослав 23
Анастасия 34
Мария 54
Иван 77

pepelulka@pepelulka:~$ cat file2.txt
1 Первый
23 Крымский
34 Доброва
54 Молоканова
77 Корочкин

pepelulka@pepelulka:~$ cmp file1.txt file2.txt
file1.txt file2.txt различаются: байт 1, строка 1
pepelulka@pepelulka:~$ cmp -l file1.txt file2.txt
 1 320  61
 2 237  40
 4 265 237
 5 321 320
 6 202 265
 9  40 320
10  61 262
11  12 321
12 320 213
13 257 320
14 321 271
15 200  12
16 320  62
17 276  63
18 321  40
19 201 320
20 320 232
21 273 321
22 320 200
23 260 321
24 320 213
25 262 320
26  40 274
27  62 321
28  63 201
29  12 320
30 320 272
31 220 320
32 320 270
33 275 320
34 320 271
35 260  12
36 321  63
37 201  64
38 321  40
39 202 320
40 320 224
41 260 320
42 321 276
43 201 320
44 320 261
45 270 321
46 321 200
47 217 320
48  40 276
49  63 320
50  64 262
51  12 320
52 320 260
53 234  12
54 320  65
55 260  64
56 321  40
57 200 320
58 320 234
59 270 320
60 321 276
61 217 320
62  40 273
63  65 320
64  64 276
65  12 320
66 320 272
67 230 320
68 320 260
69 262 320
70 320 275
71 260 320
72 320 276
73 275 320
74  40 262
75  67 320
76  67 260
78  12  67
cmp: EOF в file1.txt после байта 78
//wc//
pepelulka@pepelulka:~$ wc file1.txt
10 10 21 file1.txt
pepelulka@pepelulka:~$ wc -l file1.txt
10 file1.txt
pepelulka@pepelulka:~$ wc -w file1.txt
10 file1.txt
pepelulka@pepelulka:~$ wc -c file1.txt
21 file1.txt
//diff//
pepelulka@pepelulka:~$ cat c8_2.c
#include <stdio.h>

int main() {
	printf("Hello, world!");
}
pepelulka@pepelulka:~$ cat c8_3.c
#include <stdio.h>

int main() {
	printf("Hello, World!");
	int a = 10;
	return 0;
}
pepelulka@pepelulka:~$ diff c8_2.c c8_3.c
4c4,6
< 	printf("Hello, world!");
---
> 	printf("Hello, World!");
> 	int a = 10;
> 	return 0;
pepelulka@pepelulka:~$ diff -u c8_2.c c8_3.c
--- c8_2.c	2023-03-01 15:43:31.353162804 +0300
+++ c8_3.c	2023-03-01 15:43:28.297119510 +0300
@@ -1,5 +1,7 @@
 #include <stdio.h>
 
 int main() {
-	printf("Hello, world!");
+	printf("Hello, World!");
+	int a = 10;
+	return 0;
 }
//tee//
pepelulka@pepelulka:~$ ls -la | tee file1.txt
итого 292
drwxr-x--- 16 vika vika  4096 фев 20 14:48 .
drwxr-xr-x  4 root root  4096 сен 13 23:53 ..
-rw-rw-r--  1 vika vika   542 ноя 20 21:17 1010
-rw-rw-r--  1 vika vika   799 ноя 12 12:12 11.c
-rw-rw-r--  1 vika vika  1678 ноя 20 20:28 11_pepe.c
-rw-rw-r--  1 vika vika   492 ноя 20 19:54 11_pepe.c.save
-rw-rw-r--  1 vika vika   227 ноя 23 15:14 12.1.c
-rw-rw-r--  1 vika vika   710 дек  5 21:25 12.2.c
-rw-rw-r--  1 vika vika   612 ноя 29 18:00 12.c
-rw-rw-r--  1 vika vika     8 ноя 22 20:42 12lab.txt
-rw-rw-r--  1 vika vika  2113 дек 10 10:25 13.c
-rw-rw-r--  1 vika vika  1095 дек 13 23:07 14.c
-rw-rw-r--  1 vika vika  1981 дек 13 23:12 14test.txt
-rw-rw-r--  1 vika vika   955 дек 15 15:40 15.c
-rw-rw-r--  1 vika vika  2426 дек 15 15:40 15test.txt
-rw-rw-r--  1 vika vika  1946 фев 19 20:43 20.txt
-rw-rw-r--  1 vika vika  1582 дек 21 16:46 3_1.c
-rw-rw-r--  1 vika vika  1723 дек 21 21:49 3.c
-rw-rw-r--  1 vika vika    39 дек 22 11:20 4.c
-rwxrwxr-x  1 vika vika 16200 дек 21 21:49 a.out
-rw-rw-r--  1 vika vika   133 ноя 20 20:12 a.txt
-rw-rw-r--  1 vika vika   212 окт 29 13:59 ba.c
-rw-------  1 vika vika  6826 фев 19 20:43 .bash_history
-rw-r--r--  1 vika vika   220 сен 13 23:53 .bash_logout
-rw-r--r--  1 vika vika  3771 сен 13 23:53 .bashrc
-rw-rw-r--  1 vika vika    54 ноя 20 21:16 b.txt
-rw-r--r--  1 vika vika   205 окт 22 12:24 c8_2.c
-rw-rw-r--  1 vika vika  1822 окт 22 12:29 c8_3.c
-rw-r--r--  1 vika vika   199 окт 22 15:04 c8.txt
drwx------ 13 vika vika  4096 сен 17 12:19 .cache
drwx------ 17 vika vika  4096 сен 17 12:19 .config
drwxrwxr-x  4 vika vika  4096 сен 30 18:20 Direct
-rw-rw-r--  1 vika vika   687 ноя 23 15:19 etst.txt
-rw-rw-r--  1 vika vika  1573 ноя  6 20:58 fff.txt
-rw-rw-r--  1 vika vika     0 фев 20 14:51 file1.txt
-rw-rw-r--  1 vika vika   189 фев 20 14:44 file2.txt
-rw-------  1 vika vika   360 сен 23 17:40 .gnuplot_history
-rw-rw-r--  1 vika vika    67 сен 23 17:40 .gnuplot-wxt
-rw-r--r--  1 vika vika   214 ноя 12 14:55 lab_10.c
-rw-rw-r--  1 vika vika  1282 ноя  6 20:57 lab9.c
-rw-rw-r--  1 vika vika   266 окт 20 17:27 lab.c
-rw-------  1 vika vika    20 сен 23 17:14 .lesshst
drwx------  3 vika vika  4096 сен 14 02:59 .local
-rwxr-xr-x  1 vika vika 37040 ноя  5  2019 nam
-rw-rw-r--  1 vika vika   459 окт 27 16:38 namkh1.nam
-rw-rw-r--  1 vika vika     0 окт 27 16:38 nam.out
drwxrwxr-x  2 vika vika  4096 сен 30 18:14 new
-rw-rw-r--  1 vika vika     6 фев 20 14:48 oddd.txt
-rw-r--r--  1 vika vika   807 сен 13 23:53 .profile
drwx------  4 vika vika  4096 сен 14 03:00 snap
-rw-r--r--  1 vika vika     0 сен 13 21:00 .sudo_as_admin_successful
-rw-rw-r--  1 vika vika  3627 дек 10 10:25 test1.txt
-rw-rw-r--  1 vika vika  1574 дек  5 21:27 tests45.txt
-rw-------  1 vika vika  1699 ноя 20 19:11 .viminfo
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Видео
drwxr-xr-x  3 vika vika  4096 сен 17 12:22 Документы
drwxr-xr-x  3 vika vika  4096 фев 19 20:10 Загрузки
drwxr-xr-x  3 vika vika  4096 сен 23 17:14 Изображения
-rw-rw-r--  1 vika vika  1222 ноя 12 11:17 лабораторная работа 11
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Музыка
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Общедоступные
drwxr-xr-x  2 vika vika  4096 сен 15 16:39 Рабочий стол
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Шаблоны
pepelulka@pepelulka:~$ cat file1.txt
итого 292
drwxr-x--- 16 vika vika  4096 фев 20 14:48 .
drwxr-xr-x  4 root root  4096 сен 13 23:53 ..
-rw-rw-r--  1 vika vika   542 ноя 20 21:17 1010
-rw-rw-r--  1 vika vika   799 ноя 12 12:12 11.c
-rw-rw-r--  1 vika vika  1678 ноя 20 20:28 11_pepe.c
-rw-rw-r--  1 vika vika   492 ноя 20 19:54 11_pepe.c.save
-rw-rw-r--  1 vika vika   227 ноя 23 15:14 12.1.c
-rw-rw-r--  1 vika vika   710 дек  5 21:25 12.2.c
-rw-rw-r--  1 vika vika   612 ноя 29 18:00 12.c
-rw-rw-r--  1 vika vika     8 ноя 22 20:42 12lab.txt
-rw-rw-r--  1 vika vika  2113 дек 10 10:25 13.c
-rw-rw-r--  1 vika vika  1095 дек 13 23:07 14.c
-rw-rw-r--  1 vika vika  1981 дек 13 23:12 14test.txt
-rw-rw-r--  1 vika vika   955 дек 15 15:40 15.c
-rw-rw-r--  1 vika vika  2426 дек 15 15:40 15test.txt
-rw-rw-r--  1 vika vika  1946 фев 19 20:43 20.txt
-rw-rw-r--  1 vika vika  1582 дек 21 16:46 3_1.c
-rw-rw-r--  1 vika vika  1723 дек 21 21:49 3.c
-rw-rw-r--  1 vika vika    39 дек 22 11:20 4.c
-rwxrwxr-x  1 vika vika 16200 дек 21 21:49 a.out
-rw-rw-r--  1 vika vika   133 ноя 20 20:12 a.txt
-rw-rw-r--  1 vika vika   212 окт 29 13:59 ba.c
-rw-------  1 vika vika  6826 фев 19 20:43 .bash_history
-rw-r--r--  1 vika vika   220 сен 13 23:53 .bash_logout
-rw-r--r--  1 vika vika  3771 сен 13 23:53 .bashrc
-rw-rw-r--  1 vika vika    54 ноя 20 21:16 b.txt
-rw-r--r--  1 vika vika   205 окт 22 12:24 c8_2.c
-rw-rw-r--  1 vika vika  1822 окт 22 12:29 c8_3.c
-rw-r--r--  1 vika vika   199 окт 22 15:04 c8.txt
drwx------ 13 vika vika  4096 сен 17 12:19 .cache
drwx------ 17 vika vika  4096 сен 17 12:19 .config
drwxrwxr-x  4 vika vika  4096 сен 30 18:20 Direct
-rw-rw-r--  1 vika vika   687 ноя 23 15:19 etst.txt
-rw-rw-r--  1 vika vika  1573 ноя  6 20:58 fff.txt
-rw-rw-r--  1 vika vika     0 фев 20 14:51 file1.txt
-rw-rw-r--  1 vika vika   189 фев 20 14:44 file2.txt
-rw-------  1 vika vika   360 сен 23 17:40 .gnuplot_history
-rw-rw-r--  1 vika vika    67 сен 23 17:40 .gnuplot-wxt
-rw-r--r--  1 vika vika   214 ноя 12 14:55 lab_10.c
-rw-rw-r--  1 vika vika  1282 ноя  6 20:57 lab9.c
-rw-rw-r--  1 vika vika   266 окт 20 17:27 lab.c
-rw-------  1 vika vika    20 сен 23 17:14 .lesshst
drwx------  3 vika vika  4096 сен 14 02:59 .local
-rwxr-xr-x  1 vika vika 37040 ноя  5  2019 nam
-rw-rw-r--  1 vika vika   459 окт 27 16:38 namkh1.nam
-rw-rw-r--  1 vika vika     0 окт 27 16:38 nam.out
drwxrwxr-x  2 vika vika  4096 сен 30 18:14 new
-rw-rw-r--  1 vika vika     6 фев 20 14:48 oddd.txt
-rw-r--r--  1 vika vika   807 сен 13 23:53 .profile
drwx------  4 vika vika  4096 сен 14 03:00 snap
-rw-r--r--  1 vika vika     0 сен 13 21:00 .sudo_as_admin_successful
-rw-rw-r--  1 vika vika  3627 дек 10 10:25 test1.txt
-rw-rw-r--  1 vika vika  1574 дек  5 21:27 tests45.txt
-rw-------  1 vika vika  1699 ноя 20 19:11 .viminfo
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Видео
drwxr-xr-x  3 vika vika  4096 сен 17 12:22 Документы
drwxr-xr-x  3 vika vika  4096 фев 19 20:10 Загрузки
drwxr-xr-x  3 vika vika  4096 сен 23 17:14 Изображения
-rw-rw-r--  1 vika vika  1222 ноя 12 11:17 лабораторная работа 11
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Музыка
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Общедоступные
drwxr-xr-x  2 vika vika  4096 сен 15 16:39 Рабочий стол
drwxr-xr-x  2 vika vika  4096 сен 14 02:59 Шаблоны
pepelulka@pepelulka:~$ cat oddd.txt
12543
pepelulka@pepelulka:~$ pwd | tee -a oddd.txt
/home/vika
pepelulka@pepelulka:~$ cat oddd.txt
12543
/home/vika
pepelulka@pepelulka:~$ ls
 1010             20.txt     fff.txt      tests45.txt
 11.c             3_1.c      file1.txt    Видео
 11_pepe.c        3.c        file2.txt    Документы
 11_pepe.c.save   4.c        lab_10.c     Загрузки
 12.1.c           a.out      lab9.c       Изображения
 12.2.c           a.txt      lab.c       'лабораторная работа 11'
 12.c             ba.c       nam          Музыка
 12lab.txt        b.txt      namkh1.nam   Общедоступные
 13.c             c8_2.c     nam.out     'Рабочий стол'
 14.c             c8_3.c     new          Шаблоны
 14test.txt       c8.txt     oddd.txt
 15.c             Direct     snap
 15test.txt       etst.txt   test1.txt
pepelulka@pepelulka:~$ date | tee file1.txt file2.txt
Пн 20 фев 2023 14:52:48 MSK
pepelulka@pepelulka:~$ cat file1.txt file2.txt
Пн 20 фев 2023 14:52:48 MSK
Пн 20 фев 2023 14:52:48 MSK
//cut//
pepelulka@pepelulka:~$ echo "I want my poer to be unlimited" | cut -c 1,2,14,25,26,29,30
I rimed
pepelulka@pepelulka:~$ echo "I want my power to be unlimited" | cut -c 1,2,14,25,26,29,30
I elite
pepelulka@pepelulka:~$ echo "I am not a loser" | cut -c 1-5,10-16
I am a loser
pepelulka@pepelulka:~$ cat file1.txt
man: many: map: more
and: any: all: art
fine: father: future: floor
green: grass: gloss: glow
pepelulka@pepelulka:~$ cut -d ':' -f 1 file1.txt | sort
and
fine
green
man
pepelulka@pepelulka:~$ cut -d ':' -f 1-3 file1.txt
man: many: map
and: any: all
fine: father: future
green: grass: gloss
pepelulka@pepelulka:~$ echo "Some cool and interesting words" > sca.txt
pepelulka@pepelulka:~$ cat sca.txt
Some cool and interesting words
pepelulka@pepelulka:~$ cut -d '' -f 1,5 sca.txt
Some words
//gzip//
pepelulka@pepelulka:~$ gzip a.txt
pepelulka@pepelulka:~$ ls
 1010             3_1.c      file1.txt    tests45.txt
 11.c             3.c        file2.txt    trtr.txt
 11_pepe.c        4.c        gh           words.txt
 11_pepe.c.save   aa.txt     lab_10.c     Видео
 12.1.c           a.out      lab9.c       Документы
 12.2.c           a.txt.gz   lab.c        Загрузки
 12.c             ba.c       nam          Изображения
 12lab.txt        b.txt      namkh1.nam  'лабораторная работа 11'
 13.c             c8_2.c     nam.out      Музыка
 14.c             c8_3.c     new          Общедоступные
 14test.txt       c8.txt     oddd.txt    'Рабочий стол'
 15.c             Direct     sca.txt      Шаблоны
 15test.txt       etst.txt   snap
 20.txt           fff.txt    test1.txt
pepelulka@pepelulka:~$ gzip -k 14test.txt
pepelulka@pepelulka:~$ ls
 1010             20.txt     fff.txt      test1.txt
 11.c             3_1.c      file1.txt    tests45.txt
 11_pepe.c        3.c        file2.txt    trtr.txt
 11_pepe.c.save   4.c        gh           words.txt
 12.1.c           aa.txt     lab_10.c     Видео
 12.2.c           a.out      lab9.c       Документы
 12.c             a.txt.gz   lab.c        Загрузки
 12lab.txt        ba.c       nam          Изображения
 13.c             b.txt      namkh1.nam  'лабораторная работа 11'
 14.c             c8_2.c     nam.out      Музыка
 14test.txt       c8_3.c     new          Общедоступные
 14test.txt.gz    c8.txt     oddd.txt    'Рабочий стол'
 15.c             Direct     sca.txt      Шаблоны
 15test.txt       etst.txt   snap
pepelulka@pepelulka:~$ gzip -v c8.txt
c8.txt:	 20.6% -- replaced with c8.txt.gz
pepelulka@pepelulka:~$ gzip -d a.txt.gz
pepelulka@pepelulka:~$ ls
 1010             20.txt      fff.txt      test1.txt
 11.c             3_1.c       file1.txt    tests45.txt
 11_pepe.c        3.c         file2.txt    trtr.txt
 11_pepe.c.save   4.c         gh           words.txt
 12.1.c           aa.txt      lab_10.c     Видео
 12.2.c           a.out       lab9.c       Документы
 12.c             a.txt       lab.c        Загрузки
 12lab.txt        ba.c        nam          Изображения
 13.c             b.txt       namkh1.nam  'лабораторная работа 11'
 14.c             c8_2.c      nam.out      Музыка
 14test.txt       c8_3.c      new          Общедоступные
 14test.txt.gz    c8.txt.gz   oddd.txt    'Рабочий стол'
 15.c             Direct      sca.txt      Шаблоны
 15test.txt       etst.txt    snap
 //sort//
pepelulka@pepelulka:~$ echo -e "hight\nbrown\nlight\nmap\nnine\nMap\napple\npie\nvictory" > words.txt
pepelulka@pepelulka:~$ cat words.txt
hight
brown
light
map
nine
Map
apple
pie
victory
pepelulka@pepelulka:~$ sort words.txt
apple
brown
hight
light
map
Map
nine
pie
victory
pepelulka@pepelulka:~$ sort -r words.txt
victory
pie
nine
Map
map
light
hight
brown
apple
pepelulka@pepelulka:~$ cat file1.txt
man: many: map: more
and: any: all: art
fine: father: future: floor
green: grass: gloss: glow
pepelulka@pepelulka:~$ sort -k4 file1.txt
and: any: all: art
fine: father: future: floor
green: grass: gloss: glow
man: many: map: more
//comm//
pepelulka@pepelulka:~$ comm file1.txt file2.txt
		1
	1
		2
		3
		4
		5
		6
		7
		8
		9
comm: данные файла 1 не отсортированы
10
comm: входные данные не отсортированы
pepelulka@pepelulka:~$ comm -1 file1.txt file2.txt
	1
1
	2
	3
	4
	5
	6
	7
	8
	9
comm: данные файла 1 не отсортированы
comm: входные данные не отсортированы
pepelulka@pepelulka:~$ comm -2 file1.txt file2.txt
	1
	2
	3
	4
	5
	6
	7
	8
	9
comm: данные файла 1 не отсортированы
10
comm: входные данные не отсортированы
pepelulka@pepelulka:~$ comm -3 file1.txt file2.txt
	1
comm: данные файла 1 не отсортированы
10
comm: входные данные не отсортированы
//mktemp//
pepelulka@pepelulka:~$ mktemp
/tmp/tmp.FABvXrFDgT
pepelulka@pepelulka:~$ mktemp -d
/tmp/tmp.mJXe7m449l
pepelulka@pepelulka:~$ ls -la /tmp/tmp.mJXe7m449l
итого 8
drwx------  2 vika vika 4096 мар  1 15:32 .
drwxrwxrwt 21 root root 4096 мар  1 15:32 ..
//sum//
pepelulka@pepelulka:~$ cat file1.txt
Петр 1
Ярослав 23
Анастасия 34
Мария 54
Иван 77
pepelulka@pepelulka:~$ sum file1.txt
15673     1
pepelulka@pepelulka:~
//tail//
pepelulka@pepelulka:~$ cat file2.txt
gihi
hi
hiiiiiiii
fhvjmv bdj
fdnfdsdjkdccm,c
hihihihi
fnvhfjdnvhi
ihihihndnv
vyuiijfkfhvuid
dsvgyfujknfvbhjck
csdvbh cvyufikvb
cdsdjvuifjknefdc
cjkvdsdudyjc
vsdnhjdkvmd
sxcp;s.,cmj
hcfhcjm
pepelulka@pepelulka:~$ tail file2.txt
fnvhfjdnvhi
ihihihndnv
vyuiijfkfhvuid
dsvgyfujknfvbhjck
csdvbh cvyufikvb
cdsdjvuifjknefdc
cjkvdsdudyjc
vsdnhjdkvmd
sxcp;s.,cmj
hcfhcjm
pepelulka@pepelulka:~$ tail -n5 file2.txt
cdsdjvuifjknefdc
cjkvdsdudyjc
vsdnhjdkvmd
sxcp;s.,cmj
hcfhcjm
pepelulka@pepelulka:~$ tail --lines=+5 file2.txt
fdnfdsdjkdccm,c
hihihihi
fnvhfjdnvhi
ihihihndnv
vyuiijfkfhvuid
dsvgyfujknfvbhjck
csdvbh cvyufikvb
cdsdjvuifjknefdc
cjkvdsdudyjc
vsdnhjdkvmd
sxcp;s.,cmj
hcfhcjm
pepelulka@pepelulka:~$ tail -c 30 file2.txt
dnhjdkvmd
sxcp;s.,cmj
hcfhcjm
//uniq//
pepelulka@pepelulka:~$ cat file1.txt
Hello everybody
HellO everYBOdy
HELLO eveRybody
How are you
How are you
How are you
HoW aRe yoU
IM finE
im fine
im fine
im fine
im fine
im fine
pepelulka@pepelulka:~$ uniq file1.txt
Hello everybody
HellO everYBOdy
HELLO eveRybody
How are you
HoW aRe yoU
IM finE
im fine
pepelulka@pepelulka:~$ uniq -c file1.txt
      1 Hello everybody
      1 HellO everYBOdy
      1 HELLO eveRybody
      3 How are you
      1 HoW aRe yoU
      1 IM finE
      5 im fine
pepelulka@pepelulka:~$ uniq -D file1.txt
How are you
How are you
How are you
im fine
im fine
im fine
im fine
im fine
pepelulka@pepelulka:~$ uniq -u file1.txt
Hello everybody
HellO everYBOdy
HELLO eveRybody
HoW aRe yoU
IM finE
//df//
pepelulka@pepelulka:~$ df
Файл.система   1K-блоков Использовано  Доступно Использовано% Cмонтировано в
tmpfs             601928         2016    599912            1% /run
/dev/nvme0n1p5  17540944      9078648   7545920           55% /
tmpfs            3009636            0   3009636            0% /dev/shm
tmpfs               5120            4      5116            1% /run/lock
/dev/nvme0n1p6   6797864      1003800   5427472           16% /home
/dev/nvme0n1p1    262144        33360    228784           13% /boot/efi
/dev/nvme0n1p3 473999996    321294076 152705920           68% /windows
tmpfs             601924         2404    599520            1% /run/user/1000
pepelulka@pepelulka:~$ df -h
Файл.система   Размер Использовано  Дост Использовано% Cмонтировано в
tmpfs            588M         2,0M  586M            1% /run
/dev/nvme0n1p5    17G         8,7G  7,2G           55% /
tmpfs            2,9G            0  2,9G            0% /dev/shm
tmpfs            5,0M         4,0K  5,0M            1% /run/lock
/dev/nvme0n1p6   6,5G         981M  5,2G           16% /home
/dev/nvme0n1p1   256M          33M  224M           13% /boot/efi
/dev/nvme0n1p3   453G         307G  146G           68% /windows
tmpfs            588M         2,4M  586M            1% /run/user/1000
pepelulka@pepelulka:~$ df .
Файл.система   1K-блоков Использовано Доступно Использовано% Cмонтировано в
/dev/nvme0n1p6   6797864      1004080  5427192           16% /home
//head//
pepelulka@pepelulka:~$ cat file2.txt
gihi
hi
hiiiiiiii
fhvjmv bdj
fdnfdsdjkdccm,c
hihihihi
fnvhfjdnvhi
ihihihndnv
pepelulka@pepelulka:~$ head -v file2.txt
==> file2.txt <==
gihi
hi
hiiiiiiii
fhvjmv bdj
fdnfdsdjkdccm,c
hihihihi
fnvhfjdnvhi
ihihihndnv
pepelulka@pepelulka:~$ head -n 6 file2.txt
gihi
hi
hiiiiiiii
fhvjmv bdj
fdnfdsdjkdccm,c
hihihihi
pepelulka@pepelulka:~$ head --lines=-7 file2.txt
gihi
pepelulka@pepelulka:~$ head -c 24 file2.txt
gihi
hi
hiiiiiiii
fhvjmv
//od//
pepelulka@pepelulka:~$ echo "12543" >> oddd.txt
pepelulka@pepelulka:~$ od -b oddd.txt
0000000 061 062 065 064 063 012
0000006
pepelulka@pepelulka:~$ od -c oddd.txt
0000000   1   2   5   4   3  \n
0000006
pepelulka@pepelulka:~$ od -i oddd.txt
0000000   875901489        2611
0000006
pepelulka@pepelulka:~$ od -An -c oddd.txt
   1   2   5   4   3  \n
//cpp//
pepelulka@pepelulka:~$ cat c8_2.c
#include <stdio.h>

int main() {
	printf("Hello, world!");
}
pepelulka@pepelulka:~$ cpp c8_2.c
# 0 "c8_2.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "c8_2.c"
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

# 2 "c8_2.c" 2


# 3 "c8_2.c"
int main() {
 printf("Hello, world!");
}
pepelulka@pepelulka:~$ cpp -P c8_2.c

typedef long unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
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
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
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
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int fclose (FILE *__stream);
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
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
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));
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
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
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
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void perror (const char *__s);
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);

int main() {
 printf("Hello, world!");
}
//join//
pepelulka@pepelulka:~$ cat file1.txt
Петр 1
Ярослав 23
Анастасия 34
Мария 54
Иван 77

pepelulka@pepelulka:~$ cat file2.txt
1 Первый
23 Крымский
34 Доброва
54 Молоканова
77 Корочкин

pepelulka@pepelulka:~$ join -t' ' -1 2 -2 1 file1.txt file2.txt
1 Петр Первый
23 Ярослав Крымский
34 Анастасия Доброва
54 Мария Молоканова
77 Иван Корочкин
//paste//
pepelulka@pepelulka:~$ cat file1.txt
man
and
fine
green
pepelulka@pepelulka:~$ cat file2.txt
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
16
pepelulka@pepelulka:~$ paste file1.txt file2.txt
man	1
and	2
fine	3
green	4
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
	16
pepelulka@pepelulka:~$ paste -d '_' file1.txt file2.txt
man_1
and_2
fine_3
green_4
_5
_6
_7
_8
_9
_10
_11
_12
_13
_14
_15
_16
pepelulka@pepelulka:~$ paste -s file1.txt file2.txt
man	and	fine	green
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16
//du//
pepelulka@pepelulka:~$ du *
4	1010
4	11.c
4	11_pepe.c
4	11_pepe.c.save
4	12.1.c
4	12.2.c
4	12.c
4	12lab.txt
4	13.c
4	14.c
4	14test.txt
4	15.c
4	15test.txt
20	20.txt
4	3_1.c
4	3.c
4	4.c
4	aa.txt
16	a.out
4	a.txt
4	ba.c
4	b.txt
4	c8_2.c
4	c8_3.c
4	c8.txt
4	Direct/file22.txt
4	Direct/f2
16	Direct
4	etst.txt
4	fff.txt
4	file1.txt
4	file2.txt
24	gh
4	lab_10.c
4	lab9.c
4	lab.c
40	nam
4	namkh1.nam
0	nam.out
4	new
4	oddd.txt
pepelulka@pepelulka:~$ du --apparent-size *
1	1010
1	11.c
2	11_pepe.c
1	11_pepe.c.save
1	12.1.c
1	12.2.c
1	12.c
1	12lab.txt
3	13.c
2	14.c
2	14test.txt
1	15.c
3	15test.txt
18	20.txt
2	3_1.c
2	3.c
1	4.c
1	aa.txt
16	a.out
1	a.txt
1	ba.c
1	b.txt
1	c8_2.c
2	c8_3.c
1	c8.txt
4	Direct/file22.txt
4	Direct/f2
13	Direct
1	etst.txt
2	fff.txt
1	file1.txt
1	file2.txt
5	gh
1	lab_10.c
2	lab9.c
1	lab.c
37	nam
1	namkh1.nam
0	nam.out
4	new
1	oddd.txt
1	sca.txt
pepelulka@pepelulka:~$ du --apparent-size -b *
542	1010
799	11.c
1678	11_pepe.c
492	11_pepe.c.save
227	12.1.c
710	12.2.c
612	12.c
8	12lab.txt
2113	13.c
1095	14.c
1981	14test.txt
955	15.c
2426	15test.txt
18178	20.txt
1582	3_1.c
1723	3.c
39	4.c
15	aa.txt
16200	a.out
133	a.txt
212	ba.c
54	b.txt
205	c8_2.c
1822	c8_3.c
199	c8.txt
4096	Direct/file22.txt
4096	Direct/f2
12362	Direct
687	etst.txt
1573	fff.txt
78	file1.txt
98	file2.txt
4174	gh
214	lab_10.c
1282	lab9.c
266	lab.c
37040	nam
459	namkh1.nam
0	nam.out
4096	new
17	oddd.txt
32	sca.txt
//tr//
pepelulka@pepelulka:~$ tr a b
and aaaa any many
bnd bbbb bny mbny
pepelulka@pepelulka:~$ tr -d [:lower:]
DGCHJNCBHcjujdndbgUDUCJCJ
DGCHJNCBHUDUCJCJ
pepelulka@pepelulka:~$ echo "One Two Tree" >> trtr.txt
pepelulka@pepelulka:~$ cat trtr.txt
One Two Tree
pepelulka@pepelulka:~$ tr 'nTwo' 'lOle' < trtr.txt
Ole Ole Oree
pepelulka@pepelulka:~$ echo "abcdefghigklmn" >> aa.txt
pepelulka@pepelulka:~$ tr 'a-z' 'd-za-c' < aa.txt
defghijkljnopq
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 17.03.23 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

<b>Защита</b>

## 11. Выводы
Было выяснено, что OC UNIX не только имеет прекрасные средства программирования, но и обладает массой простых утилит, позволяющих выполнять многие сложные работы с файлами без программирования путем последовательного и конвейерного выполнения этих программ. Были изучены некоторые из них. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________