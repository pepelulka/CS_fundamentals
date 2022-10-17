# Отчёт по лабораторной работе №3 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>M80-108Б-22, Рамалданов Рустамхан Ражудинович, № по списку 17</ins> 

<b>Контакты e-mail:</b> <ins>mrpepelulka@gmail.com</ins>

<b>Работа выполнена:</b> «19» <ins>сентября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>4 (хорошо)</ins>

<b>Отчет сдан</b> «1» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>4 (хорошо)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Сети и телекоммуникации в ОС UNIX
## 2. Цель работы
Изучение различных команд для взаимодействия с удалённой машиной
## 3. Задание (вариант № —)
Изучить и применить на практике команды для установки соединения с удаленной машиной, для отправки команд на нее и передачи файлов и директорий.
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
<b>Прикладные системы и программы:</b> -- <br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/pepelulka<br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

Для решения поставленной задачи были опробованы на практике команды для установки соединения с удаленной машиной. Были опробованы некоторые основные команды терминала на удаленной машине.
Разными способами были переданы файлы и директории на удаленную машину. Опробованы
инструменты для архивации файлов.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 

Для тестирования команд удаленного управления были запущены две виртуальные машины с 
установленными на них операционными системами Linux, соединенных в одну виртуальную 
локальную сеть. С помощью команды `$ ifconfig` были получены их адреса в локальной сети.
Для начала было установлено соединение между двумя машинами через ssh и попробовал основные
команды терминала.
Далее был создан файл file.txt и передан его с помощью scp на другую машину. Далее была создана
директория somedir с двумя файлами и передана удаленной машине.
Для практики с sftp было установлено соединение sftp, отправлен файл удаленной машине и принят
файл от нее.
Далее была заархивирована папка somedir, с помощью sftp был передан архив на удаленную машину и с
помощью ssh распакован там.
Также была освоена работа с командой iconv.

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

## 8. Распечатка протокола 

Работа с ssh:
```
pepelulka@pepelulka-VirtualBox:~$ ping 192.168.56.101
PING 192.168.56.101 (192.168.56.101) 56(84) bytes of data.
64 bytes from 192.168.56.101: icmp_seq=1 ttl=64 time=0.922 ms
64 bytes from 192.168.56.101: icmp_seq=2 ttl=64 time=0.655 ms
64 bytes from 192.168.56.101: icmp_seq=3 ttl=64 time=0.616 ms
64 bytes from 192.168.56.101: icmp_seq=4 ttl=64 time=1.58 ms
64 bytes from 192.168.56.101: icmp_seq=5 ttl=64 time=0.660 ms
64 bytes from 192.168.56.101: icmp_seq=6 ttl=64 time=1.84 ms
64 bytes from 192.168.56.101: icmp_seq=7 ttl=64 time=0.545 ms
64 bytes from 192.168.56.101: icmp_seq=8 ttl=64 time=0.600 ms
64 bytes from 192.168.56.101: icmp_seq=9 ttl=64 time=0.830 ms
64 bytes from 192.168.56.101: icmp_seq=10 ttl=64 time=1.61 ms
64 bytes from 192.168.56.101: icmp_seq=11 ttl=64 time=0.677 ms
64 bytes from 192.168.56.101: icmp_seq=12 ttl=64 time=1.65 ms
64 bytes from 192.168.56.101: icmp_seq=13 ttl=64 time=0.640 ms
64 bytes from 192.168.56.101: icmp_seq=14 ttl=64 time=1.73 ms
64 bytes from 192.168.56.101: icmp_seq=15 ttl=64 time=0.620 ms
64 bytes from 192.168.56.101: icmp_seq=16 ttl=64 time=1.93 ms
64 bytes from 192.168.56.101: icmp_seq=17 ttl=64 time=0.658 ms
^C
--- 192.168.56.101 ping statistics ---
17 packets transmitted, 17 received, 0% packet loss, time 16147ms
rtt min/avg/max/mdev = 0.545/1.044/1.931/0.513 ms
pepelulka@pepelulka-VirtualBox:~$ ifconfig
enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.56.102  netmask 255.255.255.0  broadcast 192.168.56.255
        inet6 fe80::70e:a728:af93:256a  prefixlen 64  scopeid 0x20<link>
        ether 08:00:27:5c:bc:54  txqueuelen 1000  (Ethernet)
        RX packets 543  bytes 70522 (70.5 KB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 356  bytes 51805 (51.8 KB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 36725  bytes 2621764 (2.6 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 36725  bytes 2621764 (2.6 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

pepelulka@pepelulka-VirtualBox:~$ ssh 192.168.56.101
pepelulka@192.168.56.101's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

123 updates can be applied immediately.
18 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Failed to connect to https://changelogs.ubuntu.com/meta-release-lts. Check your Internet connection or proxy settings

Last login: Sun Sep 25 20:40:38 2022 from 127.0.0.1
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    Downloads  Pictures  snap          Templates  test-directory  лабы
Documents  Music      Public    somefile.txt  test       Videos
pepelulka@pepelulka-VirtualBox:~$ cat somefile
cat: somefile: No such file or directory
pepelulka@pepelulka-VirtualBox:~$ cat somefile.txt
sometext
pepelulka@pepelulka-VirtualBox:~$ cat 
asfdasd
asfdasd
pepelulka@pepelulka-VirtualBox:~$ cat "something" > somefile.txt
cat: something: No such file or directory
pepelulka@pepelulka-VirtualBox:~$ echo "something" > somefile.txt
pepelulka@pepelulka-VirtualBox:~$ cat somefile.txt
something
pepelulka@pepelulka-VirtualBox:~$ pwd
/home/pepelulka
pepelulka@pepelulka-VirtualBox:~$ 
logout
Connection to 192.168.56.101 closed.
pepelulka@pepelulka-VirtualBox:~$
```

Работа с scp:
```
pepelulka@pepelulka-VirtualBox:~$ touch file.txt
pepelulka@pepelulka-VirtualBox:~$ echo "some text" > file.txt
pepelulka@pepelulka-VirtualBox:~$ cat file.txt
some text
pepelulka@pepelulka-VirtualBox:~$ scp file.txt 192.168.56.101:
pepelulka@192.168.56.101's password: 
file.txt                                                                 100%   10     3.1KB/s   00:00    
pepelulka@pepelulka-VirtualBox:~$ ssh 192.168.56.101
pepelulka@192.168.56.101's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

123 updates can be applied immediately.
18 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Failed to connect to https://changelogs.ubuntu.com/meta-release-lts. Check your Internet connection or proxy settings

Last login: Sun Sep 25 22:45:09 2022 from 192.168.56.102
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    Downloads  Music     Public  somefile.txt  test            Videos
Documents  file.txt   Pictures  snap    Templates     test-directory  лабы
pepelulka@pepelulka-VirtualBox:~$ cat file.txt
some text
pepelulka@pepelulka-VirtualBox:~$ mkdir somedir
pepelulka@pepelulka-VirtualBox:~$ cd somedir
pepelulka@pepelulka-VirtualBox:~/somedir$ touch file1.txt
pepelulka@pepelulka-VirtualBox:~/somedir$ touch file2.txt
pepelulka@pepelulka-VirtualBox:~/somedir$ ls
file1.txt  file2.txt
pepelulka@pepelulka-VirtualBox:~/somedir$ cd ..
pepelulka@pepelulka-VirtualBox:~$ scp -r somedir 192.168.56.101:
pepelulka@192.168.56.101's password: 
file1.txt                                                                100%    0     0.0KB/s   00:00    
file2.txt                                                                100%    0     0.0KB/s   00:00    
pepelulka@pepelulka-VirtualBox:~$ ssh 192.168.56.101
pepelulka@192.168.56.101's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

123 updates can be applied immediately.
18 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Failed to connect to https://changelogs.ubuntu.com/meta-release-lts. Check your Internet connection or proxy settings

Last login: Sun Sep 25 22:59:08 2022 from 192.168.56.102
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    Downloads  Music     Public  somedir       Templates  test-directory  лабы
Documents  file.txt   Pictures  snap    somefile.txt  test       Videos
pepelulka@pepelulka-VirtualBox:~$ cd somedir
pepelulka@pepelulka-VirtualBox:~/somedir$ ls
file1.txt  file2.txt
pepelulka@pepelulka-VirtualBox:~/somedir$ 
logout
Connection to 192.168.56.101 closed.
```

Работа с sftp:
```
pepelulka@pepelulka-VirtualBox:~$ sftp 192.168.56.101
pepelulka@192.168.56.101's password: 
Connected to 192.168.56.101.
sftp> ls
Desktop          Documents        Downloads        Music            Pictures         Public           
Templates        Videos           file.txt         ftp_test.txt     snap             somedir          
somefile.txt     test             test-directory   лабы         
sftp> pwd
Remote working directory: /home/pepelulka
sftp> get ftp_test.txt
Fetching /home/pepelulka/ftp_test.txt to ftp_test.txt
ftp_test.txt                                                             100%    9     3.3KB/s   00:00    
sftp> put somefile2.txt
Uploading somefile2.txt to /home/pepelulka/somefile2.txt
somefile2.txt                                                            100% 2922     3.3MB/s   00:00    
sftp> ^D
```

Работа с tar:
```
pepelulka@pepelulka-VirtualBox:~$ tar -cf somedir.tar somedir
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    f1.txt        Music     python-prog  somedir.tar    somefile4.txt  Videos
Documents  file.txt      Pictures  snap         somefile2.txt  somefile.txt
Downloads  ftp_test.txt  Public    somedir      somefile3.txt  Templates
pepelulka@pepelulka-VirtualBox:~$ scp somedir.tar 192.168.56.101:
pepelulka@192.168.56.101's password: 
somedir.tar                                                              100%   10KB   3.5MB/s   00:00    
pepelulka@pepelulka-VirtualBox:~$ ssh 192.168.56.101
pepelulka@192.168.56.101's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-47-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

123 updates can be applied immediately.
18 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Failed to connect to https://changelogs.ubuntu.com/meta-release-lts. Check your Internet connection or proxy settings

Last login: Sun Sep 25 23:11:51 2022 from 192.168.56.102
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    Downloads  ftp_test.txt  Pictures  snap     somedir.tar    somefile.txt  test            Videos
Documents  file.txt   Music         Public    somedir  somefile2.txt  Templates     test-directory  лабы
pepelulka@pepelulka-VirtualBox:~$ tar -xf somedir.tar
pepelulka@pepelulka-VirtualBox:~$ ls
Desktop    Downloads  ftp_test.txt  Pictures  snap     somedir.tar    somefile.txt  test            Videos
Documents  file.txt   Music         Public    somedir  somefile2.txt  Templates     test-directory  лабы
pepelulka@pepelulka-VirtualBox:~$ cd somedir
pepelulka@pepelulka-VirtualBox:~/somedir$ ls 
f1.txt  f2.txt  file1.txt  file2.txt
pepelulka@pepelulka-VirtualBox:~/somedir$
```

Работа с iconv:
```
pepelulka@pepelulka-VirtualBox:~$ touch iconv.txt
pepelulka@pepelulka-VirtualBox:~$ echo "sometext" > iconv.txt
pepelulka@pepelulka-VirtualBox:~$ iconv -c -f koi8-r -t cp1251 iconv.txt
sometext
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 19.09.2022 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы
Благодаря лабораторной работе были изучены основныу команды работы с удаленной машиной в OS UNIX. Была освоена работа с утилитой tar для архивирования файлов и утилитой iconv для смены кодировки файлов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
