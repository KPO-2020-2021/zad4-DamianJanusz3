// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "figure.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 *///



/*!
 * Zapis wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] strm - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] rectan - zmienna typu figure zapisywana do strumienia wyjściowego.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void savetostream( std::ostream& strm, Figure rectan) {
  strm <<std::setw(16) << std::fixed << std::setprecision(10)<< rectan << std::endl;
}

/*!
 * Zapis wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] rectan - zmienna typu figure zapisywana do strumienia wyjściowego.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool savetofile(const char *filename, Figure rectan) {
  std::ofstream  filestream;

  filestream.open(filename);
  if (!filestream.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  savetostream(filestream, rectan);

  filestream.close();
  return !filestream.fail();
}


int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  



PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  
typedef Vector<double,2u>  Vector2D;
  double angle;
  int amount;
  Matrix<double,SIZE> matt;
  Vector2D vecc;
  Figure rectan;
  char action;

//*********tu na wszeli wypadek zainicjalizowana jest  zmienna rectan z zerami*********//
  double arg1[]={0,0}; double arg2[]={0,0}; double arg3[]={0,0}; double arg4[]={0,0};
  Vector<double,SIZE> vec1=arg1; Vector<double,SIZE> vec2=arg2; Vector<double,SIZE> vec3=arg3;
  Vector<double,SIZE> vec4=arg4; Vector<double,SIZE> vec5=arg4;
  Vector<double,SIZE> ar[]={vec1,vec2,vec3,vec4,vec5};
  rectan = Figure(ar);








  /***** część związana z mnożeniem macierzy i liczeniem wyznacznika*********
 double args[3][3]={{1,2,5},{2,3,6},{7,8,9}}; double args2[3][3]={{1,2,2},{1,2,2},{1,2,2}};
  Matrix m( args); Matrix p(args2); Matrix r;
r=multiply(m,p,1);
std::cout<< r;

  Vector v;
  int n=2;
  v=m.gaussdet(n);
std::cout <<v<< std::endl;
*/


//wczytanie prostokąta z cin
  rectan.read(std::cin, std::cout);


  savetostream(std::cout,rectan);//zapis prostokąta 

  std::cout<< std::endl;
  rectan=rectan.length(rectan);
  rectan.showlength(rectan, std::cout);

  if (!savetofile("../datasets/prostokat.dat",rectan)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');//////////////wyświetlenie na gnuplocie

  std::cout<< std::endl;
  std::cout << "o - obrot prostokata o zadany kat" << std::endl;
  std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
  std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout << "m - wyswietl menu" << std::endl;
  std::cout << "k - koniec dzialania programu" << std::endl;
  std::cout<< std::endl;

  


do {

std::cout << std::endl;
std::cout <<"Twoj wybor? (m - menu) > ";
  std::cin >> action;
  std::cout << std::endl;

switch (action) {

case 'm': {       //menu
       std::cout << "o - obrot prostokata o zadany kat" << std::endl;
       std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
       std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
       std::cout << "m - wyswietl menu" << std::endl;
       std::cout << "k - koniec dzialania programu" << std::endl;
       break;
}

case 'p': {       //przesunięcie o wektor
  std::cout << " Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb tzn. wspolrzednej x oraz y " << std::endl;
  std::cin >> vecc;

      if (std::cin.fail()==true) {
      for ( int i=0; (std::cin.fail()==true && i<=1); ++i){
      std::cin.clear();
      std::cin.ignore(99999,'\n');
      std::cout << "Błędny sposób zapisu spróbuj jeszcze raz!"<< std::endl;
      std::cin >> vecc;
      }
      }
  
  rectan=rectan.move(vecc);
  std::cout<< std::endl;
  rectan=rectan.length(rectan);
  rectan.showlength(rectan, std::cout);
  savetostream(std::cout,rectan);//////////////zapis prostokąta do pliku
  if (!savetofile("../datasets/prostokat.dat",rectan)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');//////////////wyświetlenie na gnuplocie
  break;
}

case 'o': {           //obrót
  std::cout << "Podaj wartosc kata obrotu w stopniach: ";
  std::cin>>angle;

      if (std::cin.fail()==true) {
      for (int i=0; (std::cin.fail()==true && i<=1); i++){
      std::cin.clear();
      std::cin.ignore(99999,'\n');
      std::cout << "Błędny sposób zapisu spróbuj jeszcze raz!"<< std::endl;
      std::cin >> angle;
      }
      }
  
  std::cout << "Ile razy operacja obrotu ma byc powtorzona: ";
  std::cin>>amount;

      if (std::cin.fail()==true) {
      for (int i=0; (std::cin.fail()==true && i<=1); i++){
      std::cin.clear();
      std::cin.ignore(99999,'\n');
      std::cout << "Błędny sposób zapisu spróbuj jeszcze raz!"<< std::endl;
      std::cin >> amount;
      }
      }

  matt.make2D(angle);
  rectan.rotate(matt, amount);
  std::cout<< std::endl;
  rectan=rectan.length(rectan);
  rectan.showlength(rectan, std::cout);
  savetostream(std::cout,rectan);//////////////zapis prostokąta do pliku
  if (!savetofile("../datasets/prostokat.dat",rectan)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');//////////////wyświetlenie na gnuplocie
  break;
}

case 'w': {         //wyświetlenie współrzędnych
  std::cout << "ostatnia linijka to powtorzona wspolrzedna nr 1"<< std::endl;
  std::cout << rectan;
  
  //////////////wyświetlenie na gnuplocie
  break;
}

case 'k': {               //zamknięcie programu
  std::cout << "Koniec dzialania programu" << std::endl;
  break;
}
}


}while(action!='k');





  
  // Z bazy projektu-wydmuszki Boiler Plate C++:
  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
