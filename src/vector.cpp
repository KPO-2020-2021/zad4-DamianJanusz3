#include "size.hh"
#include "vector.hh"

#include <iomanip>
#include <iostream>
#include <cstdlib>

#define MIN_DIFF 0.00001
#define SIZE 2


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 *///
 /*template <typename type, int size1>
Vector<type,size1>::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
}*/


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
/*template <typename type, int size1>
Vector<type,size1>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
}*/


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
/*template <typename type,  int size1>
Vector<type,size1> Vector<type,size1>::operator + (const Vector &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}*/


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
/*template <typename type,  int size1>
Vector<type,size1> Vector<type,size1>::operator - (const Vector &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}*/


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
/*template <typename type,  int size1>
Vector<type,size1> Vector<type,size1>::operator * (const type &tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}*/


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
/*template <typename type, int size1>
Vector<type,size1> Vector<type,size1>::operator / (const type &tmp) {
    Vector result;

    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}*/


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
/*template <typename type, int size1>
 const type &Vector<type,size1>::operator [] ( int index) const {
    if (index < 0 || index >= SIZE) {
        //std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        throw std::runtime_error("Wektor jest poza zasiegiem!");
    } 
    return size[index];
}*/


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
/*template <typename type,  int size1>
type &Vector<type,size1>::operator[]( int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}*/


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
/*template <typename type,  int size1>
std::ostream &operator << (std::ostream &out, Vector<double,SIZE> const &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        out << std::setw(16) << std::fixed << std::setprecision(10) << tmp[i];//\n
    }
    return out;
}*/


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
/*template <typename type,  int size1>
std::istream &operator >> (std::istream &in, Vector<double,SIZE> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}*/

/******************************************************************************
 |  Przeciazenie operatora &                                                 |
 |  wylicza długość między punktami
 |  Argumenty:                                                                |
 |      v- wektor posiadający współrzędne do których liczymy długość          |
 |  Zwraca:                                                             |
 |  długość między danymi punktami
 */
// jest to tylko dla przestrzeni 2d czyli SIZE=2
/*template <typename type,  int size1>
type Vector<type,size1>::operator & (const Vector<type,size1> &v) const {
    double result;
    
    result= sqrt(pow(this->size[0] - v.size[0], 2) + pow(this->size[1] - v.size[1], 2));
    
    return result;
}*/


/******************************************************************************
 |  Przeciążenie operatora ==                |
 |  Argumenty:                                                                |
 |      m - zmienna typu vector         |
 |  Zwraca:                                                                   |
 |      true jeśli wpółrzędne takie same                               |
    false w przeciwnym wypadku
 */
/*template <typename type,  int size1>
bool  Vector<type,size1>::operator == ( const Vector &m) const {

for (int i=0; i<SIZE; ++i) { 
if (abs(this->size[0] - m.size[0]) <= MIN_DIFF && abs(this->size[1] - m.size[1]) <= MIN_DIFF ) 
    return true;

  else
    return false;
}
return true;
}*/