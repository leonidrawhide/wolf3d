### Wolf3D

In this project we have to write our own version of Wolfenstein 3D engine.

Started:	September 2th 2020

Finished:	November 13th 2020

В основе работы движка лежит рейкастинг. Его нужно было переписать с нуля используя ограниченный набор функций.

![Alt Text](https://upload.wikimedia.org/wikipedia/commons/e/e7/Simple_raycasting_with_fisheye_correction.gif)


### Установка

Программа совместима с MacOS системами.
В терминале, после клонирования репозитория, запустите следующую команду:
```sh
$ cd wolf3d
$ make
```
Затем выберите доступную карту/версию выбрав из доступных в папке demos. Например:
```sh
$ ./wolf3d demos/demo1
```
Карта defect является неработающей картой, она создана для проверки работы проверяющей части программы.

Карты состоят из 1 и 0, где 0 - это пол, а 1 - это блок стены. В 4 разных направления направены разные текстуры (на юг, запад, север и восток).

![N|Solid](https://d.radikal.ru/d18/2105/e5/8f9da904009d.png) ![N|Solid](https://a.radikal.ru/a32/2105/08/713ca99547ef.png)
