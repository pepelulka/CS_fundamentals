# Отчёт по лабораторной работе №2 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>M80-108Б-22, Рамалданов Рустамхан Ражудинович, № по списку 17</ins> 

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «19» <ins>сентября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Операционная среда OC UNIX
## 2. Цель работы
Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.
## 3. Задание (вариант № —)
Работа с директориями. Создание, удаление директорий и перемещение по ним. Манипуляции с файлами. Навигация в файловой системе ОС UNIX. Построение графиков с помощью утилиты gnuplot, протоколирование сеансов.
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
<b>Утилиты операционной системы:</b> cd, pwd, ls, cp, mv, mkdir, rmdir, cat, man, ps, rm<br/>
<b>Прикладные системы и программы:</b> gnuplot<br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/pepelulka<br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Для решения поставленной задачи была проверена на практике работа основных комманд 
терминала ОС UNIX и написан скрипт на языке bash.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 

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

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

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

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 19.09.2022 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы
В результате лабораторной работы были изучены основные команды ОС UNIX. Были изучены команды для создания, редактирования, чтения и удаления файлов, перемещения по директориям. Были 
получены базовые навыки по работы с конвейерами и перенаправлением ввода/вывода. Были изучены основные концепции ОС UNIX.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
