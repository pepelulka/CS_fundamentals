# Отчёт по лабораторной работе №21 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Рамалданов Рустамхан Ражудинович, № по списку: 15</ins>

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «28» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «28» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Программирование на интерпретируемых командных языках

## 2. Цель работы

Составить программу выполнения заданных действий над файлами на одном из интерпретируемом командном языке ОС UNIX - Bash

## 3. Задание (Вариант 16)

Удаление файлов с указанным префиксом и с максимальными размерами, пока общий размер остающихся файлов не станет меньше заданного числа.

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


## 6. Идея, метод, алгоритм решения задачи

1. Считываются аргументы. Переходим к шагу 2.
2. Если аргументов не хватает, выводится сообщение об этом, иначе переходим к шагу 3.
3. Пока размер файлов с указанным префиксом больше указанного максимального размера, находим самый большой файл с указанным префиксом и удаляем его.

## 7. Сценарий выполнения работы

```
#!/bin/bash

prefix=$1
max_size=$2
flag=$3

if [[ -z $prefix ]] || [[ -z $max_size ]]
then
    echo "Missing arguments"
    echo "Usage: ./main.sh <prefix> <max-size>"
else
    if [ -n "$flag" ] && [ $flag == "-a" ]
    then
        ans=#
        while true
        do
            echo "Are you sure? [Y/n]"
            read ans
            case "$ans" in
                Y) break;;
                n) echo "Quit..." &&  exit 0;;
            esac
        done
        if [[ ans == "n" ]]
        then
            exit 0
        fi
    fi
    echo "Removing files..."
    while [[ `find . -type f -name "$prefix*" | xargs wc -c | awk '{print $1}' | head -1` -gt "$max_size" ]] || [[ `find . -type f -name "$prefix*" | xargs wc -c | grep total | awk '{print $1}'` -gt "$max_size" ]]
    do
        max_file=`find . -type f -name "$prefix*" -printf "%s\t%p\n" | sort -n | tail -1 | awk '{print $2}'`
        rm $max_file
    done
fi

```

## 8. Распечатка протокола

```
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ wc *.txt
  0   1  21 abba.txt
  0   1  33 abc.txt
  0   1   9 ab.txt
  0   1 114 delta.txt
  0   1 137 z.txt
  0   5 314 total
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ bash main.sh ab 10
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ ls
ab.txt  delta.txt  main.sh  z.txt
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ wc *.txt
  0   1   9 ab.txt
  0   1 114 delta.txt
  0   1 137 z.txt
  0   3 260 total
///////
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ wc *.txt
  0   1  21 abba.txt
  0   1  33 abc.txt
  0   1   9 ab.txt
  0   1 114 delta.txt
  0   1 137 z.txt
  0   5 314 total
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ bash main.sh ab 5
pepelulka@pepelulka:~/Desktop/labs/tmp_labs/Lab21-Bash_script/test$ wc *txt
  0   1 114 delta.txt
  0   1 137 z.txt
  0   2 251 total
```

## 9. Дневник отладки

| № | Лаб.Или Дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Дом. | 12.06.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

### Защита

<b>Div 2</b>

[1837A](https://codeforces.com/contest/1837/submission/207162249)
[1837B](https://codeforces.com/contest/1837/submission/207231351)

Дорешка:

[1837C](https://codeforces.com/contest/1837/submission/209870900)

## 11. Выводы

Благодаря лабораторной работе были получениы базовые навыки написания Bash-скриптов. Был изучен синтаксис языка Bash.

<b>Подпись студента:</b> ___________
