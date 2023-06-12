# WDPprojekt
Dokumentacja projektu TicTacToe
Kinga Janicka
Natalia Jakubiec

1: Kompilacja projektu i uruchomienie programu
Aby skompilować program potrzebne są:
•	paczka z plikami źródłowymi (TicTacToe.zip)
•	program Visual Studio Community (2022) z workload'em Desktop Development with C++.
•	najnowsza wersja biblioteki SFML (SFML 2.5.1, Visual C++ 15 (2017) – 64-bit)

	Kroki w celu kompilacji (Windows):
1.	Rozpakować paczkę z plikami źródłowymi.
2.	Otworzenie projektu w programie Visual Studio (plik z rozszerzeniem .sln).
3.	Wybranie wersji Release, x64.
4.	Zbudowanie projektu.

	Kroki w celu kompilacji (Linux, Ubuntu 22):
1.	Rozpakować paczkę z plikami źródłowymi.
2.	Zainstalować pakiet poleceniem sudo apt-get install libsfml-dev.
3.	Zbudowanie projektu poleceniem make.

	W celu uruchomienia programu należy w programie Visual Studio wcisnąć przycisk Uruchom bez Debugowania (Ctrl + F5) lub uruchomić plik wykonywalny powstały w wyniku procesu kompilacji (linux).

2: Obsługa programu i możliwe przypadki

	Ekran widoczny po uruchomieniu programu został przedstawiony na rysunku poniżej:
	Na ekranie widoczne są trzy przyciski – dwa pozwalające rozpocząć grę w odpowiednim trybie oraz jeden pozwalający wyjśc z programu (można to uczynić także wciskając przycisk Escape).

	Tryb dla 1 gracza:
	Po rozpoczęciu gry w tym trybie, na ekranie ukazuje się plansza do gry oraz informacja o tym, którego gracza dotyczy obecna tura (domyślnie użytkownik rozpoczyna, oraz posługuje się symbolem X).
	Aby wykonać ruch należy za pomocą myszy kliknąć w wybrany kwadrat. Po chwili algorytm odpowie swoim ruchem. Plansza po jednej "wymianie ruchów" została przedstawiona na rysunku poniżej:
	Po zakończeniu gry, na ekranie zostaje wyświetlona informacja o wygranej (lub remisie) oraz prośba o wciśnięcie lewego przycisku myszy w dowolnym miejscu w celu przejścia dalej (powrotu do Menu).

	
	Tryb dla dwóch graczy:
	Tryb dla dwóch graczy działa analogicznie do trybu pierwszego, z tą różnicą, że w każdej turze kliknięcie lewym przyciskiem myszy po najechaniu kursorem na odpowiedni kwadrat ustawia kolejny symbol.

