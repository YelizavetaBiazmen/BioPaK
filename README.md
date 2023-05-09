# BioPaK
![Флорариум](florarium.jpg "Florarium")
## Программа для умной подсветки флорариума https://ru.wikipedia.org/wiki/%D0%A4%D0%BB%D0%BE%D1%80%D0%B0%D1%80%D0%B8%D1%83%D0%BC
Cytat z wikipedii:

Florarium, terrarium roślinne - specjalny zamknięty pojemnik wykonany ze szkła lub innych przezroczystych materiałów przeznaczony do przechowywania i hodowli roślin. Wewnątrz tworzy się określona wilgotność i temperatura. Często używany do uprawy kapryśnych roślin tropikalnych.

Jak działa podświetlenie:
Podświetlenie oparte jest na Arduino. Istnieje kilka trybów:
1. - nie świeci.
2. regulowana jasność.
Trzecie światło tylko w ciągu dnia.
4. maksymalna jasność.
Podświetlenie wykorzystuje pasek 12V RGB. (Kontrola mosfety Cherer). Zastosowano potencjometr do zmiany poziomu stężenia, fotorezystor do wykrywania światła dziennego oraz dwie diody LED do wyświetlania numeru trybu w formacie binarnym.
Plik BIOPAK.ino zawiera program główny.
Pliki RGBLed.cpp i RGBLed.h to biblioteki, które należy pobrać podczas pracy z programem.
Pliki w formacie jpg (florarium.jpg i schema.jpg) są przeznaczone do wyświetlania wynikowego schematu i florarium.


