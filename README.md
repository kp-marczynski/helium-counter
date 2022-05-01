# helium-counter
## TL;DR
Realizacja zadania wyznaczania pojemności zadanej struktury kontenerów. 
Spośród sprawdzonych implementacji, najlepszą wydajność osiągnięto dla implementacji w języku C++.

## Zadanie
1. W magazynie ustawione są kontenery o znanej strukturze.
2. W przestrzenie między kontenerami wlewany jest płyn, przy założeniu, że płyn nie może wylać się ponad kontener. Przykładowo w strukturze [1,0,2] zmieści się 1 jednostka płynu, natomiast w strukturze [0,1,0,2,1,0,1,3,2,1,2,1] 6 jednostek.
3. Celem jest zaproponowanie możliwie najbardziej efektywnego sposobu na wyznaczenie maksymalnej ilości płynu, którą można przechować w zadanej strukturze.

## Opis rozwiązania
Algorytm w każdym obiegu pętli bierze pierwszy od lewej strony dostępny kontener (leftBound), 
a następnie szuka kolejnego kontenera o tej samej lub większej wysokości posuwając się po indeksach (indexShift) w prawą stronę. 
W trakcie szukania kontenera spełniającego podane kryterium, przy każdym przesunięciu zliczana jest dostępna przestrzeń (tempCount). 
Jeśli odpowiedni kontener zostanie znaleziony, zliczona przestrzeń zostaje dodana do całkowitego wyniku (totalCount), 
oraz zaktualizowana zostaje wartość indeksu (leftBound) od którego przeszukiwanie ma się rozpocząć w następnym obiegu pętli. 
Jeśli odpowiedni kontener nie zostanie znaleziony, indeks (leftBound) nie jest zmieniany i ustawiana jest flaga 
informująca o osiągnięciu maksymalnego indeksu przy przeszukiwaniu od lewej strony (maxLeftBoundReached). 
Jeżeli wspomniana flaga ma wartość "true", w następnym obiegu pętli przeszukiwanie od lewej strony jest pomijane. 
W każdym obiegu pętli następuje również przeszukiwanie kontenerów w analogiczny sposób od strony prawej do lewej. 
Przeszukiwanie kontenerów zostaje zakończone, gdy lewa i prawa granica dojdzie do wspólnego punktu (leftBound == rightBound). 
Pesymistyczna złożoność obliczeniowa wynosi 2n (w przypadku gdy pierwszy element od lewej strony jest najwyższym elementem), 
a optymistyczna 1n, gdzie "n" to rozmiar tablicy (containerStructure).

Algorytm został zaimplementowany w [C++](/src/cpp_counter.cpp), [kotlinie](/src/kotlin_counter.kt) i [pythonie](/src/python_counter.py). 
Aby porównać wydajność implementacji, testy wykonano dla tablic zawierających losowe 100 tysięcy cyfr. 
Średni czas wyniósł:
* C++ 2 ms
* Kotlin 4 ms
* Python 750 ms

Demo dla każdej wersji jest dostępne online:
* C++ [http://cpp.sh/7mlwf](http://cpp.sh/7mlwf)
* Kotlin [https://pl.kotl.in/sNb4HObs6](https://pl.kotl.in/sNb4HObs6)
* Python [https://www.online-python.com/5rgnNTubfU](https://www.online-python.com/5rgnNTubfU)
