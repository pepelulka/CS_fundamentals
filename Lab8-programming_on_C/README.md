# Отчёт по лабораторной работе №8 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>M80-108Б-22, Рамалданов Рустамхан Ражудинович, № по списку 17</ins> 

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «26» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>______</ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>______</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Системы программирования на языке Си.
## 2. Цель работы
Изучение системы программирования на Си.
## 3. Задание 
Написать простейшую программу на языке Си, скомпилировать ее и запустить.
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

Написать простейшую программу на языке Си, скомпилировать ее и запустить.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 

Код программы: 
```src:a.c
#include <stdio.h>

int main() {
    int a, b;
    
    printf("Enter two integers\n");

    scanf("%d %d", &a, &b);

    printf("%d", a + b);

    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

## 8. Распечатка протокола 

```
C:\Users\user\Desktop>gcc -Wall -Wpedantic -Wextra -Werror -std=c18 a.c  

C:\Users\user\Desktop>a.exe
Enter two integers
2 3
5
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 26.10.2022 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы

В процессе выполнения лабораторной работы были изучены особенности работы с написанием программ на языке Си. Были изучены основы синтаксиса языка, получены базовые навыки написания программ на языке Си. Был опробован на практике компилятор GCC. Были изучены основные этапы компиляции и сборки программ на языке Си.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
