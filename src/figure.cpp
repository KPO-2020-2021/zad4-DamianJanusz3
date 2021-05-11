#include "size.hh"

#include "figure.hh"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <math.h>
#define MIN_DIFF 0.00001





/******************************************************************************
 |  Konstruktor klasy Figure.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablicę wektorów zerowych.                                            |
 *///
Figure::Figure() {
    Vector<double,SIZE> v;
    for (int i = 0; i < VERTICES; ++i) {
        
            vertices[i] = v;
            
        
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Figure.                                   |
 |  Argumenty:                                                                |
 |      tmp - jednowymiarowa tablica z elementami typu vector.                |
 |  Zwraca:                                                                   |
 |      tablicę wypelniona wartosciami podanymi w argumencie.                 |
 */
Figure::Figure(Vector<double,SIZE> tmp[VERTICES]) {
    for (int i = 0; i < VERTICES; ++i) {
        
            vertices[i] = tmp[i];
        
    }
}



/******************************************************************************
 |  Konstruktor parametryczny klasy Figure.                                   |
 |  Argumenty:                                                                |
 |      tmp - jednowymiarowa tablica z elementami typu double.                |
 |  Zwraca:                                                                   |
 |      tablicę wypelniona wartosciami podanymi w argumencie.                 |
 */
Figure::Figure(double tmp[VERTICES]) {
    for (int i = 0; i < VERTICES; ++i) {
        
            leng[i] = tmp[i];
        
    }
}


/******************************************************************************
 |  Metoda obliczająca długości między wszystkimi wierzchołkami.              |
 |  Argumenty:                                                                |
 |      rect - zmienna posiadająca tablicę wektorów wspołrzędnych, między     |
 |  którymi liczymy długości
 |  Zwraca:                                                                   |
 |      zmienną typu figure posiadającą zapisane wektory współrzędnych ORAZ   |
 |  tablicę z długościami między wierzchołkami
 */
Figure Figure::length (Figure rect)  {
    Figure result;
    for (int i=0; i<VERTICES; ++i) {
        result.vertices[i]=this->vertices[i] ;
    }
    for (int i=0; i<VERTICES; ++i) {
        result.leng[i]= this->vertices[i] & this->vertices[i+1];
        
    }
    
   
    rect=rect;
    return result;
}


/******************************************************************************
 |  Przeciążenie operatora == w celu porównania długości boków.               |
 |  Argumenty:                                                                |
 |      m - zmienna typu figure posiadająca długości, które porównujemy        |
 |  Zwraca:                                                                   |
 |      true jeśli boki są sobie równe                               |
    false jeśli nie są równe
 */
bool  Figure::operator == (  Figure m)  {

if (abs(this->leng[0] - m.leng[2]) <= MIN_DIFF && abs(this->leng[1] - m.leng[3]) <= MIN_DIFF) 
    return true;

  else
    return false;
}



/******************************************************************************
 |  metoda realizująca przesunięcie o wektor.                                   |
 |  Argumenty:                                                                |
 |      move1 - wektor przesunięcia                                           |
 |  Zwraca:                                                                   |
 |      zmienną typu figure po przesunięciu o wektor                             |
 */
Figure Figure::move ( Vector<double,SIZE> move1)  {
    Figure result;
    for (int i=0; i<VERTICES; ++i)
    result.vertices[i]=this->vertices[i]+move1;
    
    return result;
}

/******************************************************************************
 |  metoda realizująca obrót danej figury o zadany kąt i zadaną ilość razy.   |
 |  Argumenty:                                                                |
 |      m - macierz obrotu                                                      |
 |      amount - ilość wykonań obrotu 
 |  Zwraca:                                                                   |
 |      zmienną typu figure po obróceniu o zadany kąt i zadaną ilość razy       |   
 */
Figure Figure::rotate (Matrix<double, SIZE> m, int amount) {
    
    for(int k=0; k<amount; ++k) {
    for (int i=0; i<VERTICES; ++i) {
    this->vertices[i]= m * this->vertices[i];
    }
}
    return *this;
}


/******************************************************************************
 |  metoda realizująca wczytywanie współrzędnych wierzchołków ze strumienia   |
 |      do zmiennej typu figure
 |  Argumenty:                                                                |
 |      strmi - strumień wejściowy                                             |
 |      strmo - strumień wyjściowy 
 |  Zwraca:                                                                   |
 |      nic                                                                    |   
 */
 void Figure::read( std::istream& strmi, std::ostream& strmo) {
strmo<< "wczytywanie wspolrzednych wierzcholkow prostokata" <<std::endl;
  for (int w=0; w < VERTICES-1; ++w) {
      
    strmo << "podaj wspolrzedne wierzcholka nr " << w+1 << std::endl;
    strmi >> this->vertices[w];
    if (strmi.fail()==true) {
      for ( int i=0; (std::cin.fail()==true && i<=1); ++i){
      strmi.clear();
      strmi.ignore(99999,'\n');
      strmo << "Błędny sposób zapisu spróbuj jeszcze raz!"<< std::endl;
      strmi >> this->vertices[w];
      }
      }
  }
  this->vertices[VERTICES-1]=this->vertices[0];
  
}


/******************************************************************************
 |  metoda realizująca wyświetlanie długości w zależności od ich długości.   |
 |  Argumenty:                                                                |
 |      rectangle - zmiennatypu figure posiadająca tablicę długości,            |
 |       które wyświetlimy
 |  Zwraca:                                                                   |
 |      nic                                                                    |   
 */
void Figure::showlength (Figure rectangle, std::ostream& strmo) const{
if ( std::max(rectangle.leng[0], rectangle.leng[1])==rectangle.leng[0] && std::max(rectangle.leng[0], rectangle.leng[1])!=rectangle.leng[1]) {
if ( (rectangle == rectangle)==true) {
       
 strmo << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[0] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[2] << std::endl;
 strmo << std::endl;
 strmo << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[1] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[3] << std::endl;
}
else {
 strmo << "Dlugosci bokow nie sa sobie rowne" << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[0] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[2] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[1] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[3] << std::endl;
}
}
else if (std::max(rectangle.leng[0], rectangle.leng[1])==rectangle.leng[1] && std::max(rectangle.leng[0], rectangle.leng[1])!=rectangle.leng[0]){
if ( (rectangle == rectangle)==true ) {
 strmo << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[1] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[3] << std::endl;
 strmo << std::endl;
 strmo << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[0] << std::endl;
 strmo << "Dlugosc drugiego boku: " <<std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[2] << std::endl;  
}
else {
 strmo << "Dlugosci bokow nie sa sobie rowne" << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[0] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[2] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[1] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[3] << std::endl;
}
}
else if (std::max(rectangle.leng[0], rectangle.leng[1])==rectangle.leng[1] && std::max(rectangle.leng[0], rectangle.leng[1])==rectangle.leng[0]){
if ( (rectangle == rectangle)==true ) {
 strmo << "Mamy kwadrat" << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[1] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[3] << std::endl;
 strmo << "Dlugosc trzeciego boku: " <<  std::setw(16) << std::fixed << std::setprecision(10) <<rectangle.leng[0] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[2] << std::endl;  
}
else {
 strmo << "Dlugosci bokow nie sa sobie rowne" << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[0] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[2] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[1] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << rectangle.leng[3] << std::endl;
}
}

}





/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const Vector<double,SIZE> &Figure::operator () (int index) const {
    if (index < 0 || index >= VERTICES) {
        //std::cerr << "Error: Figura? jest poza zasiegiem!" << std::endl;
        throw std::runtime_error("Figura jest poza zasiegiem");
    } 
    return vertices[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
Vector<double,SIZE> &Figure::operator () (int index) {
    return const_cast<Vector<double,SIZE> &>(const_cast<const Figure *>(this)->operator () (index));
}

/******************************************************************************
 |  Funktor tablicy długości.                                                          |
 |  Argumenty:                                                                |
 |      index - index tablicy.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc tablicy w danym miejscu jako stala.                   |
 */
const double &Figure::operator [] (int index) const {
    if (index < 0 || index >= VERTICES) {
        //std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        throw std::runtime_error("Figura jest poza zasiegiem");
    } 
    return leng[index];
}


/******************************************************************************
 |  Funktor tablicy długości.                                                 |
 |  Argumenty:                                                                |
 |      index - index tablicy.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc tablicy w danym miejscu.                                       |
 */
double &Figure::operator[](int index) {
    return const_cast<double &>(const_cast<const Figure *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - zmienna typu figure.                                                         |
 */
std::ostream &operator << (std::ostream &out, Figure const &tmp) {
    for (int i = 0; i < VERTICES; ++i) {
        out  << std::setw(16) << std::fixed << std::setprecision(10) << tmp(i) <<"\n";
    }

    

    return out;
}
