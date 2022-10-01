# Отчет по лабораторной работе N 1-2 по курсу
# "Фундаментальная информатика"

Студент группы: M80-108Б-22, Рамалданов Рустамхан Ражудинович\
Контакты: mrpepelulka@gmail.com\
Работа выполнена: 19.09.2022\
Преподаватель: Сахарин Никита Александрович\

## 1. Тема

Программирование машин Тьюринга

## 2. Цель работы

Изучение и освоение машины Тьюринга и приобритение навыков, необходимых для
выполнения курсовых и лабораторных работ в машине Тьюринга.

## 3. Задание

Составить программу машины Тьюринга в четвёрках для перевода числа из троичной системы счисления в девятеричную.

## 4. Оборудование

Процессор: 11th Gen intel(R) Core(TM) i5-11400H @ 2.70GHz\
ОП: 16ГБ\
НМД: 512ГБ\
Монитор: 1920x1080\

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **5.15.0-47-generic**\
Интерпретатор команд: **bash**, версия **5.1.16**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\

## 6. Идея, метод, алгоритм решения задачи


Для решения поставленной задачи была проверена на практике работа основных комманд 
терминала ОС UNIX и написан скрипт на языке bash.


## 7. Сценарий выполнения работы


В лабораторной работе была создана директория test-directory, в ней созданы текстовые файлы и директория new-dir. С помощью основных командам терминала были продемонстрированы создание, удаление, запись и чтение файлов через терминал.

Использованные команды:

|Команда|Применение|
|-------|----------|
|`whoami`|Выводит имя пользователя|
|`ls`|Выводит содержимое рабочей директории|
|`pwd`|Выводит полный путь к рабочей директории|
|`cd`|Изменение текущей рабочей директории|
|`cp`|Копирование файлов и директорий|
|`mv`|Перемещение и переименование файлов и директорий|
|`man`|Просмотр справочных руководств системы|
|`rm`|Удаление файлов и директорий|
|`rmdir`|Удаление пустых директорий|
|`mkdir`|Создание директорий|
|`cat`|Конкатенация содержимого файлов|
|`touch`|Создание нового файла|
|`ps`|Выводит список текущих процессов|

Далее был создан скрипт, который здоровается с пользователем, выводит текущую директорию и показывает список файлов в ней. Текст скрипта приведен далее.

```                            
name=$(whoami)
my_dir=$(pwd)
echo "Hello $name"
echo "You're now in $my_dir"
echo "There is the list of files in the current directory:"
ls
```

## 8. Распечатка протокола

```
pepelulka@pepelulka-VirtualBox:~$ who
pepelulka tty2         2022-09-19 21:21 (tty2)
pepelulka@pepelulka-VirtualBox:~$ whoami
pepelulka
pepelulka@pepelulka-VirtualBox:~$ pwd
/home/pepelulka
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop  Documents  Downloads  Music  Pictures  Public  snap  Templates  Videos
pepelulka@pepelulka-VirtualBox:~$ mkdir test-directory
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    Downloads  Pictures  snap       test-directory
Documents  Music      Public    Templates  Videos
pepelulka@pepelulka-VirtualBox:~$ cd test-directory
pepelulka@pepelulka-VirtualBox:~/test-directory$ touch t1.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ cat > t1.txt
12345678
pepelulka
^C
pepelulka@pepelulka-VirtualBox:~/test-directory$ touch t2.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ cat > t2.txt
pepelulikus
ievievieviev
^C
pepelulka@pepelulka-VirtualBox:~/test-directory$ cat t1.txt
12345678
pepelulka
pepelulka@pepelulka-VirtualBox:~/test-directory$ touch t3.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ cat t1.txt t2.txt > t3.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ cat t3.txt
12345678
pepelulka
pepelulikus
ievievieviev
pepelulka@pepelulka-VirtualBox:~/test-directory$ cat -n t3.txt
     1	12345678
     2	pepelulka
     3	pepelulikus
     4	ievievieviev
pepelulka@pepelulka-VirtualBox:~/test-directory$ ls
t1.txt  t2.txt  t3.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ ls -l
total 12
-rw-rw-r-- 1 pepelulka pepelulka 19 сен 19 21:46 t1.txt
-rw-rw-r-- 1 pepelulka pepelulka 25 сен 19 21:47 t2.txt
-rw-rw-r-- 1 pepelulka pepelulka 44 сен 19 21:48 t3.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ mkdir new-dir
pepelulka@pepelulka-VirtualBox:~/test-directory$ cp t1.txt new-dir
pepelulka@pepelulka-VirtualBox:~/test-directory$ mv t2.txt new-dir
pepelulka@pepelulka-VirtualBox:~/test-directory$ ls
new-dir  t1.txt  t3.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ ls new-dir
t1.txt  t2.txt
pepelulka@pepelulka-VirtualBox:~/test-directory$ ps
    PID TTY          TIME CMD
   2062 pts/0    00:00:00 bash
   5681 pts/0    00:00:00 ps
pepelulka@pepelulka-VirtualBox:~/test-directory$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    2062    1994  0  80   0 -  4978 do_wai pts/0    00:00:00 bash
0 R  1000    5682    2062  0  80   0 -  5331 -      pts/0    00:00:00 ps
pepelulka@pepelulka-VirtualBox:~/test-directory$ cd new-dir
pepelulka@pepelulka-VirtualBox:~/test-directory/new-dir$ rm t1.txt
pepelulka@pepelulka-VirtualBox:~/test-directory/new-dir$ ls
t2.txt
pepelulka@pepelulka-VirtualBox:~/test-directory/new-dir$ cd ..
pepelulka@pepelulka-VirtualBox:~/test-directory$ rm -r new-dir 
pepelulka@pepelulka-VirtualBox:~/test-directory$ ls
t1.txt  t3.txt
```
Протокол работы скрипта:
```
pepelulka@pepelulka-VirtualBox:~/test$ ./test.sh
Hello pepelulka
You're now in /home/pepelulka/test
There is the list of files in the current directory:
t1.txt
t2.txt
test.sh
tt.txt
```
## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|   |               |            |           |                          |                         |             | 

## 10. Выводы

В результате лабораторной работы были изучены основные команды ОС UNIX. Были изучены команды для создания, редактирования, чтения и удаления файлов, перемещения по директориям. Это заложило фундамент для дальнейшего более глубокого изучения OS.
