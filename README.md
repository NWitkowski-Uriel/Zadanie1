# ReadMe for zadanie1.c

## Opis programu

Program `zadanie1.c` służy do analizy danych z pliku binarnego zawierającego sygnały w dziedzinie czasu. Program wczytuje dane z pliku, przetwarza je, a następnie wyświetla histogramy przedstawiające amplitudę sygnału w funkcji czasu. Program umożliwia również odjęcie wartości bazowej (baseline) od sygnału.

Użycie programu
Program domyślnie wczytuje dane z pliku wave_0.dat. 

Po uruchomieniu program wyświetli liczbę zdarzeń (events) w pliku.

Program zapyta, czy chcesz odjąć wartość bazową (baseline) od sygnału. Wpisz y (tak) lub n (nie).

Program wyświetli histogramy dla każdego zdarzenia. Kliknij dwukrotnie na histogram, aby przejść do następnego zdarzenia.

Program wyświetli wartość bazową dla każdego zdarzenia oraz liczbę pozostałych zdarzeń do wyświetlenia.

Struktura kodu
Funkcja zadanie1: Główna funkcja programu, która wykonuje całą logikę wczytywania danych, przetwarzania ich i wyświetlania histogramów.

Wczytywanie danych: Program wczytuje dane z pliku binarnego i oblicza liczbę zdarzeń.

Obliczanie wartości bazowej: Dla każdego zdarzenia program oblicza wartość bazową na podstawie pierwszych 50 próbek.

Tworzenie histogramów: Program tworzy histogramy dla każdego zdarzenia, z możliwością odjęcia wartości bazowej.

Wyświetlanie wyników: Program wyświetla histogramy w oknie graficznym i pozwala użytkownikowi przechodzić między zdarzeniami.
