# Отчёт по лабораторной работе №5 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>M80-108Б-22, Рамалданов Рустамхан Ражудинович, № по списку 17</ins> 

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «26» <ins>сентября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Программирование машин Тьюринга
## 2. Цель работы
Изучение и освоение машины Тьюринга и приобритение навыков, необходимых для
выполнения курсовых и лабораторных работ в машине Тьюринга.
## 3. Задание (вариант № 37)
Составить программу машины Тьюринга в четвёрках для перевода числа из троичной системы счисления в девятеричную.
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
<b>Утилиты операционной системы:</b> ssh, scp, sftp, tar, iconv<br/>
<b>Прикладные системы и программы:</b> jstu4 <br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/pepelulka<br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Для решения поставленой задачи изначально число было скопировано для сохранений нормированности. Потом скопированное число было было переведено в 9-ую систему счисления последовательным
переводом кусков числа по две цифры.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 

1. По цифрам скопировать исходное число справа от него.
2. Пройтись по скопированному числу, переводя последовательно по две цифры в 9-чную систему счисления.
3. Соединить цифры, чтобы получить нужное число справа от исходного.

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

## 8. Распечатка протокола 

```
00, , ,start_copy_program

start_main_program, ,$,start_main_program
start_main_program,$,<,start_main_program

start_main_program,0, ,h0 
start_main_program,1, ,h1
start_main_program,2, ,h2


h,0, ,h0 
h,1, ,h1
h,2, ,h2
h, , ,right_end_of_n


h0, ,<,h0_
h1, ,<,h1_
h2, ,<,h2_


h0_, , ,right_put0_end_of_n
h1_, , ,right_put1_end_of_n 
h2_, , ,right_put2_end_of_n


right_put0_end_of_n, ,>,put0_end_of_n
right_put1_end_of_n, ,>,put1_end_of_n
right_put2_end_of_n, ,>,put2_end_of_n


put0_end_of_n, ,0,end_of_n
put1_end_of_n, ,1,end_of_n
put2_end_of_n, ,2,end_of_n


h0_,0,0,next_d 
h0_,1,3,next_d 
h0_,2,6,next_d


h1_,0,1,next_d 
h1_,1,4,next_d 
h1_,2,7,next_d


h2_,0,2,next_d 
h2_,1,5,next_d 
h2_,2,8,next_d


next_d,0,<,h
next_d,1,<,h
next_d,2,<,h
next_d,3,<,h
next_d,4,<,h
next_d,5,<,h
next_d,6,<,h
next_d,7,<,h
next_d,8,<,h


right_end_of_n, ,>,end_of_n

end_of_n,0,>,hook
end_of_n,1,>,hook
end_of_n,2,>,hook
end_of_n,3,>,hook
end_of_n,4,>,hook
end_of_n,5,>,hook
end_of_n,6,>,hook
end_of_n,7,>,hook
end_of_n,8,>,hook


hook,$, ,go_to_n 
hook, ,>,hook

hook,0, ,resp0 
hook,1, ,resp1
hook,2, ,resp2
hook,3, ,resp3
hook,4, ,resp4
hook,5, ,resp5
hook,6, ,resp6
hook,7, ,resp7
hook,8, ,resp8

resp0, ,<,resp0
resp0,0,>,put0
resp0,1,>,put0
resp0,2,>,put0
resp0,3,>,put0
resp0,4,>,put0
resp0,5,>,put0
resp0,6,>,put0
resp0,7,>,put0
resp0,8,>,put0

resp1, ,<,resp1
resp1,0,>,put1
resp1,1,>,put1
resp1,2,>,put1
resp1,3,>,put1
resp1,4,>,put1
resp1,5,>,put1
resp1,6,>,put1
resp1,7,>,put1
resp1,8,>,put1

resp2, ,<,resp2
resp2,0,>,put2
resp2,1,>,put2
resp2,2,>,put2
resp2,3,>,put2
resp2,4,>,put2
resp2,5,>,put2
resp2,6,>,put2
resp2,7,>,put2
resp2,8,>,put2

resp3, ,<,resp3
resp3,0,>,put3
resp3,1,>,put3
resp3,2,>,put3
resp3,3,>,put3
resp3,4,>,put3
resp3,5,>,put3
resp3,6,>,put3
resp3,7,>,put3
resp3,8,>,put3

resp4, ,<,resp4
resp4,0,>,put4
resp4,1,>,put4
resp4,2,>,put4
resp4,3,>,put4
resp4,4,>,put4
resp4,5,>,put4
resp4,6,>,put4
resp4,7,>,put4
resp4,8,>,put4

resp5, ,<,resp5
resp5,0,>,put5
resp5,1,>,put5
resp5,2,>,put5
resp5,3,>,put5
resp5,4,>,put5
resp5,5,>,put5
resp5,6,>,put5
resp5,7,>,put5
resp5,8,>,put5

resp6, ,<,resp6
resp6,0,>,put6
resp6,1,>,put6
resp6,2,>,put6
resp6,3,>,put6
resp6,4,>,put6
resp6,5,>,put6
resp6,6,>,put6
resp6,7,>,put6
resp6,8,>,put6

resp7, ,<,resp7
resp7,0,>,put7
resp7,1,>,put7
resp7,2,>,put7
resp7,3,>,put7
resp7,4,>,put7
resp7,5,>,put7
resp7,6,>,put7
resp7,7,>,put7
resp7,8,>,put7

resp8, ,<,resp8
resp8,0,>,put8
resp8,1,>,put8
resp8,2,>,put8
resp8,3,>,put8
resp8,4,>,put8
resp8,5,>,put8
resp8,6,>,put8
resp8,7,>,put8
resp8,8,>,put8


put0, ,0,right_n_hook
put1, ,1,right_n_hook
put2, ,2,right_n_hook
put3, ,3,right_n_hook
put4, ,4,right_n_hook
put5, ,5,right_n_hook
put6, ,6,right_n_hook
put7, ,7,right_n_hook
put8, ,8,right_n_hook


right_n_hook, ,>,hook
right_n_hook,0,>,hook
right_n_hook,1,>,hook
right_n_hook,2,>,hook
right_n_hook,3,>,hook
right_n_hook,4,>,hook
right_n_hook,5,>,hook
right_n_hook,6,>,hook
right_n_hook,7,>,hook
right_n_hook,8,>,hook


go_to_n, ,<,go_to_n
go_to_n,0,>,end
go_to_n,1,>,end
go_to_n,2,>,end
go_to_n,3,>,end
go_to_n,4,>,end
go_to_n,5,>,end
go_to_n,6,>,end
go_to_n,7,>,end
go_to_n,8,>,end


end, ,#,end

start_copy_program, ,$,right_first_lhook 


right_first_lhook,$,<,first_lhook


first_lhook,0,<,first_lhook
first_lhook,1,<,first_lhook
first_lhook,2,<,first_lhook


first_lhook, ,>,first_lhook_ret


first_lhook_ret,0,/,lhook_ret0
first_lhook_ret,1,/,lhook_ret1
first_lhook_ret,2,/,lhook_ret2


lhook_ret0,/,>,lhook_ret0
lhook_ret0,0,>,lhook_ret0
lhook_ret0,1,>,lhook_ret0
lhook_ret0,2,>,lhook_ret0
lhook_ret0,$,>,lhook_ret0

lhook_ret0, ,0,lhook0


lhook_ret1,/,>,lhook_ret1
lhook_ret1,0,>,lhook_ret1
lhook_ret1,1,>,lhook_ret1
lhook_ret1,2,>,lhook_ret1
lhook_ret1,$,>,lhook_ret1

lhook_ret1, ,1,lhook1


lhook_ret2,/,>,lhook_ret2
lhook_ret2,0,>,lhook_ret2
lhook_ret2,1,>,lhook_ret2
lhook_ret2,2,>,lhook_ret2
lhook_ret2,$,>,lhook_ret2

lhook_ret2, ,2,lhook2



lhook0,0,<,lhook0
lhook0,1,<,lhook0
lhook0,2,<,lhook0
lhook0,$,<,lhook0

lhook0,/,0,right_ret_lhook


lhook1,0,<,lhook1
lhook1,1,<,lhook1
lhook1,2,<,lhook1
lhook1,$,<,lhook1

lhook1,/,1,right_ret_lhook


lhook2,0,<,lhook2
lhook2,1,<,lhook2
lhook2,2,<,lhook2
lhook2,$,<,lhook2

lhook2,/,2,right_ret_lhook


right_ret_lhook,0,>,lhook_ret
right_ret_lhook,1,>,lhook_ret
right_ret_lhook,2,>,lhook_ret


lhook_ret,$, ,right_go_to_right_end
lhook_ret,0,/,lhook_ret0
lhook_ret,1,/,lhook_ret1
lhook_ret,2,/,lhook_ret2


right_go_to_right_end, ,>,go_to_right_end


go_to_right_end,0,>,go_to_right_end
go_to_right_end,1,>,go_to_right_end
go_to_right_end,2,>,go_to_right_end
go_to_right_end, , ,start_main_program
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 26.09.2022 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы
Были освоены навыки составления программ для машины Тьюринга. Было лучше изучено понятие алгоритма и вычислимости. Был освоен эмулятор машины Тьюринга.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
