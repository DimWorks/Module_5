Задание 5 по модулю 5: Написать модуль ядра для своей версии ядра, который будет обмениваться информацией с userspace через chardev. 
Результаты выложить на github 

Назовём дивайс TESTING, чтобы его было проще найти в списке девайсов.

Описание к Screen.png:

Используем команду "ls -l /dev/TESTING", чтобы вывести девайс
Получаем сообщение "ls: невозможно получить доступ к '/dev/TESTING': Нет такого файла или каталога"
Мы убедились, что такого девайса не существует в сестеме

Теперь, выполним вствку модуля в ядро: sudo insmod programm.ko

И снова повторим команду "ls -l /dev/TESTING"
Получаем: crw------- 1 root root 239, 0 авг 22 12:14 /dev/TESTING

Следовательно, модуль ядра работает корректно
