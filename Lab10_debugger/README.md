# Отчёт по лабораторной работе №10 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>M80-108Б-22, Рамалданов Рустамхан Ражудинович, № по списку 17</ins> 

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «3» <ins>декабря</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>______</ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>______</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Отладчик системы программирования ОС UNIX.
## 2. Цель работы
Отладка программы на языке Си с помощью утилиды gdb.
## 3. Задание 
Провести отладку программы с помощью утилиты gdb.
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
<b>Утилиты операционной системы:</b> gcc, gdb <br/>
<b>Прикладные системы и программы:</b> GNU C compiler <br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/pepelulka<br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Основные команды утилиты gdb:
1. ```run``` - запуск программы
2. ```break``` - установка точки остановы
3. ```continue``` - продолжение выполнения программы до ближайшей точки остановы
4. ```print``` - выводит значение входного выражения
5. ```set var``` - устанавливает значение переменной
6. ```delete``` - удаляет точки остановы с заданными номерами
7. ```quit``` - выход

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 

Код отлаживаемой программы: 
```src:a.c
#include <stdio.h>

struct State {
    int i, j, l;
};

struct Band {
    int lower, upper;
};

int sign(int a) {
    if (a < 0) return -1;
    if (a > 0) return 1;
    return 0;
}

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

int mod(int a, int b) {
    return a - (a / b) * b;
}

int max(int a, int b) {
    if (a < b) return b;
    return a;
}

int min(int a, int b) {
    return (a + b) - max(a, b);
}

void entered_msg(struct State st, int k) {
    printf("(i, j) has entered the area, i = %d, j = %d, l = %d, k = %d \n", st.i, st.j, st.l, k);
}

void iter(struct State* st, int ck) {
    int ci = st->i, cj = st->j, cl = st->l;
    st->i = abs(ci - cl) + min(mod(cj, 10), mod(cl * ck, 10)) - 20;
    st->j = mod(max(ck - ci, min(cj, max(ci - cl, cj - cl))), 30);
    st->l = mod(cl * cl, 20) - mod(max(ci, cj), ck + 1);
}

void out(struct State st) {
    printf("(%d, %d, %d) \n", st.i, st.j, st.l);
}

void trace(struct State st, struct Band bnd) {
    int flag = 0;
    if (check(st, bnd)) {
        flag = 1;
        entered_msg(st, 0);
    }
    for (int k = 1;(k <= 50) && (flag == 0);k++) {
        iter(&st, k);
        out(st);
        if (check(st, bnd)) {
            flag = 1;
            entered_msg(st, k);
            break;
        }
    }
    if (flag == 0) {
        printf("(i, j) hasn't entered the area, i = %d, j = %d, l = %d \n", st.i, st.j, st.l);
    }
}
                    
int main() {
    struct State st = {-30, -4, 12};
    struct Band bnd = {-20, -10};
    trace(st, bnd);
    return 0;
}
```

Попробуем поставить одну безусловную точку остановы и одну точку остановы с условием.

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

## 8. Распечатка протокола 

Протокол отладки:
```
C:\Users\user\Desktop\Универ\лабы по инфе\labs\10>gcc -g a.c

C:\Users\user\Desktop\Универ\лабы по инфе\labs\10>gdb a.exe
GNU gdb (GDB) 10.2
Built by Equation Solution <http://www.Equation.com>.
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.exe...
(gdb) break trace 
Breakpoint 1 at 0x1400017f7: file a.c, line 55.
(gdb) run
Starting program: C:\Users\user\Desktop\Универ\лабы по инфе\labs\10\a.exe 
[New Thread 3432.0x3558]
warning: Can not parse XML library list; XML support was disabled at compile time

Thread 1 hit Breakpoint 1, trace (st=..., bnd=...) at a.c:55
warning: Source file is more recent than executable.
55          int flag = 0;
(gdb) print st
$1 = {i = -30, j = -4, l = 12}
(gdb) print bnd
$2 = {lower = -20, upper = -10}
(gdb) continue
Continuing.
(18, 1, 4)
(-5, 1, 16)
(2, 8, 15)
(-7, 2, 2)
(-11, 12, 2)
(-5, 17, -1)
(-23, 17, 0)
(3, 1, -8)
(-11, 6, 1)
(-8, 21, -5)
(-22, 21, -4)
(-10, 4, 8)
(2, 23, 0)
(-18, 23, -8)
(-10, 3, -3)
(-21, 26, 6)
(9, 8, 8)
(-15, 9, -5)
(-15, 4, -4)
(i, j) has entered the area, i = -15, j = 4, l = -4, k = 19
[Thread 3432.0x3558 exited with code 0]
[Inferior 1 (process 3432) exited normally]
(gdb) info break
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x00007ff6dd3417f7 in trace at a.c:55
        breakpoint already hit 1 time
(gdb) delete 1
(gdb) info break
No breakpoints or watchpoints.
(gdb) break 61 if k == 5
Breakpoint 3 at 0x7ff6dd34184d: file a.c, line 61.
(gdb) run
Starting program: C:\Users\user\Desktop\Универ\лабы по инфе\labs\10\a.exe 
[New Thread 7404.0x1d38]
(18, 1, 4)
(-5, 1, 16)
(2, 8, 15)
(-7, 2, 2)

Thread 1 hit Breakpoint 3, trace (st=..., bnd=...) at a.c:61
61              iter(&st, k);
(gdb) print st 
$3 = {i = -7, j = 2, l = 2}
(gdb) set vat st.i = 100000
No symbol "vat" in current context.
(gdb) set var st.i = 100000   
(gdb) print st
$4 = {i = 100000, j = 2, l = 2}
(gdb) continue
Continuing.
(99978, 2, 0)
(99958, 2, -4)
(99934, 2, 10)
(99904, 2, -7)
(99888, 2, 5)
(99863, 2, -3)
(99843, 2, -2)
(99821, 2, 1)
(99802, 2, 0)
(99782, 2, -7)
(99764, 2, 3)
(99743, 2, 1)
(99724, 2, -4)
(99706, 2, 4)
(99684, 2, 10)
(99654, 2, -18)
(99644, 2, -12)
(99632, 2, -4)
(99614, 2, 8)
(99588, 2, -10)
(99578, 2, -8)
(99558, 2, 2)
(99538, 2, -14)
(99530, 2, 6)
(99506, 2, -4)
(99490, 2, -11)
(99480, 2, -1)
(99459, 2, -17)
(99455, 2, 0)
(99435, 2, -20)
(99435, 2, -3)
(99410, 2, -7)
(99388, 2, 7) 
(99363, 2, -7)
(99347, 2, 6)
(99321, 2, 12)
(99291, 2, -29)
(99292, 2, -3)
(99266, 2, -19)
(99259, 2, -40)
(99279, 2, -37)
(99294, 2, -6)
(99278, 2, -14)
(99270, 2, 12)
(99240, 2, -16)
(99236, 2, -29)
(i, j) hasn't entered the area, i = 99236, j = 2, l = -29
[Thread 7404.0x1d38 exited with code 0]
[Inferior 1 (process 7404) exited normally]
(gdb) quit
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 03.12.2022 | 18:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы

В процессе выполнения лабораторной работы были получены навыки работы с отладчиком системы программирования ОС UNIX отладчиком gdb. Были получены базовые понятия об отладке программ на Си, получены
базовые навыки для отладки программ в будущем.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
