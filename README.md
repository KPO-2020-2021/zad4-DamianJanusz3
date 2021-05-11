## Informacje dla sprawdzającego
#-kilka metod zrobionych jest "na sztywno", bez uogólnień bo zwyczajnie nie miałyby sensu w innych
#warunkach. Przykładem jest metoda showlength bez sensu gdyby było 5 boków
#-operator wyświetlania obsługuje wyświetlanie na cout i wpisywanie do pliku. Stąd przy #wyświetlaniu wierzchołków w programie mamy ich 5


#NA POTRZEBY SPRAWDZENIA MODYFIKACJI I MNOŻENIA MACIERZY TRZEBA ZMIENIĆ "SIZE"  NP. NA WARTOŚĆ 3. 
#W TYM MOMENCIE CZĘŚĆ WYKONUJĄCA TE OPERACJE W PLIKU main.cpp JEST ZAKOMENTOWANA WIĘC TRZEBA TO #ZMIENIĆ, PONADTO TRZEBA WYŁĄCZYĆ TESTY DLA MACIERZY BO POWODUJĄ WTEDY BŁĘDY


## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```

Things to remember:
* changes to zad3/CMakeLists.txt with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/lacze_do_gnuplota
    src/Matrix2x2.cpp
    src/Rectangle .cpp
    src/Vector2D.cpp
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp
)
set(LIBRARY_NAME zad3)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to zad3/tests/CMakeLists.txt with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    Wektor2D.cpp
    Macierz2x2.cpp
    Prostokat.cpp
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

