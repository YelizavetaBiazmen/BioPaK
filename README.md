# BioPaK
![Флорариум](florarium.jpg "Флорариум")
## Program for smart florarium lighting https://ru.wikipedia.org/wiki/%D0%A4%D0%BB%D0%BE%D1%80%D0%B0%D1%80%D0%B8%D1%83%D0%BC
Quote from wikipedia:
>Florarium, plant terrarium - a special closed container made of glass or other transparent materials and intended for keeping and breeding plants. Inside, a certain humidity and temperature are created. Often used to grow whimsical tropical plants.

### How does the backlight work:
The backlight is based on Arduino. There are several modes:   
1st - it doesn't light.  
2nd adjustable brightness.  
3rd lights only if it's a day.   
4th maximum brightness.  
Для подсветки используется RGB лента  12 в. (управление черер мосфеты). Используется Потенциометр для изменения уровня яркости, Фото-резистер для определения дневного света и два светодиода для отображения номера режима в бинарном формате.  
Файл BIOPAK.ino содержит в себе основную программу.  
Файлы RGBLed.cpp и RGBLed.h являются библиотеками, которые необходимо скачать при работе с программой.  
Файлы формата jpg (florarium.jpg и schema.jpg) предназначены для показа получившейся схемы и флорариума.
![Схема](schema.jpg "Флорариум - cхема")


