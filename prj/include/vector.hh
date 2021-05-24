#pragma once

/*!
 * \file
 * \brief Definicja klasy Vector
 * 
 * Plik zawiera definicję klasy Vector i wszystkie jej metody
 */

#include "size.hh"
#include <iostream>
#include<iomanip>
#include <cmath>
#include <initializer_list>
#include <cstdlib>
#define MIN_DIFF 0.00001

/*!
 * Vector to tablica jednowymiarowa danego typu o danym rozmiarze
 */
template <typename type, /*unsigned*/ int size1>
class Vector {

private:

    type size[size1];     //Tablica wektora

public:

/*! 
 * Konstruktor bezparametryczny klasy Vector
 */
    Vector();
/*! 
 * Konstruktor parametryczny klasy Vector
 */
    Vector(double [SIZE]);
/*! 
 * Operator dodawania dwóch wektorów
 */
    Vector operator + (const Vector &v);
/*! 
 * Operator odejmowania dwóch wektorów
 */
    Vector operator - (const Vector &v);
/*! 
 * Operator mnożenia wektora przez liczbę
 */
    Vector operator * (const type &tmp);
/*! 
 * Operator dzielenia wektora przez liczbę
 */
    Vector operator / (const type &tmp);
/*! 
 * Operator indeksowania const
 */
    const type &operator [] ( /*unsigned*/ int index) const;
/*! 
 * Operator indeksowania
 */
    type &operator [] (/*unsigned*/ int index);
/*! 
 * Operator odpowiedzialny za obliczanie odległości między punktami
 */
    type operator & (const Vector &v) const;
/*! 
 * Operator porównania dwóch wektorów
 */
    bool  operator == ( const Vector &m) const;

};

//template <typename type, /*unsigned*/ int size1>
//std::ostream &operator << (std::ostream &out, const Vector<type,size1> &tmp);

//template <typename type, /*unsigned*/ int size1>
//std::istream &operator >> (std::istream &in, Vector<type,size1> &tmp);

/*! 
* Konstruktor bezparametryczny klasy Vector.         
* \param[in]  - brak                                                     
*  Wypełnia wektor wartościami 0.       
*/
 template <typename type, int size1>
Vector<type,size1>::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
}


/*! 
* Konstruktor parametryczny klasy Vector.         
* \param[in]  - tmp[SIZE] tablica wypełniona wartościami                                                     
* Wypełnia wektor wartościami z podanej tablicy.        
*/
template <typename type, int size1>
Vector<type,size1>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
}



/*! 
* Realizuje dodawanie dwoch wektorow.        
* \param[in]  - this - pierwszy skladnik dodawania,
* \param[in]  - v - drugi skladnik dodawania.                                                  
* \return Zwraca wektor będący sumą podanych składników      
*/
template <typename type,  int size1>
Vector<type,size1> Vector<type,size1>::operator + (const Vector &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}


/*! 
* Realizuje odejmowanie dwoch wektorow.        
* \param[in]  - this - pierwszy skladnik odejmowania,
* \param[in]  - v - drugi skladnik odejmowania.                                                  
* \return Zwraca wektor będący różnicą podanych składników      
*/
template <typename type,  int size1>
Vector<type,size1> Vector<type,size1>::operator - (const Vector &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}



/*! 
* Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.        
* \param[in]  - this - pierwszy skladnik mnozenia (wektor),
* \param[in]  - tmp - drugi skladnik mnozenia (liczba typu double).                                                  
* \return Zwraca wektor będący iloczynem wektora i liczby      
*/
template <typename type,  int size1>
Vector<type,size1> Vector<type,size1>::operator * (const type &tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/*! 
* Realizuje dzielenie wektora przez liczbę        
* \param[in]  - this - licznik dzielenia (wektor),
* \param[in]  - tmp - mianownik dzielenia (liczba typu double).                                                  
* \return Zwraca wektor będący ilorazem wektora i liczby      
*/
template <typename type, int size1>
Vector<type,size1> Vector<type,size1>::operator / (const type &tmp) {
    Vector result;

    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}



/*! 
* Funktor wektora.       
* \param[in]  - index - index wektora.                                                 
* \return Zwraca wartosc wektora w danym miejscu tablicy jako stala.      
*/
template <typename type, int size1>
 const type &Vector<type,size1>::operator [] ( int index) const {
    if (index < 0 || index >= SIZE) {
        //std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        throw std::runtime_error("Wektor jest poza zasiegiem!");
    } 
    return size[index];
}



/*! 
* Funktor wektora.       
* \param[in]  - index - index wektora.                                                 
* \return Zwraca wartosc wektora w danym miejscu tablicy.      
*/
template <typename type,  int size1>
type &Vector<type,size1>::operator[]( int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}



/*! 
* Przeciazenie operatora << 
* Wyswietla wektor na standardowe wyjście.     
* \param[in]  - out - strumien wyjsciowy,        
* \param[in]  - tmp - wektor.                                         
* \return Zwraca strumien wyjsciowy,      
*/
template <typename type,  int size1>
std::ostream &operator << (std::ostream &out, Vector<type,size1> const &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        out << std::setw(16) << std::fixed << std::setprecision(10) << tmp[i];//\n
    }
    return out;
}



/*! 
* Przeciazenie operatora >> 
* Wczytuje wektor ze standardowego wejścia do zmiennej     
* \param[in]  - in - strumien wejsciowy,        
* \param[in]  - tmp - wektor.                                         
* \return Zwraca strumien wejsciowy,      
*/
template <typename type,  int size1>
std::istream &operator >> (std::istream &in, Vector<type,size1> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}


/*! 
* Przeciazenie operatora &    
* Wylicza długość między punktami okreslonymi wektorami
* \param[in]  - this - pierwszy wektor,        
* \param[in]  - v - drugi wektor.                                         
* \return Odległość miedzy punktami jako liczbę typu double,      
*/
template <typename type,  int size1>
type Vector<type,size1>::operator & (const Vector<type,size1> &v) const {
    double result;
    
    result= sqrt(pow(this->size[0] - v.size[0], 2) + pow(this->size[1] - v.size[1], 2) + pow(this->size[2] - v.size[2], 2));
    
    return result;
}


/******************************************************************************
 |  Przeciążenie operatora ==                |
 |  Argumenty:                                                                |
 |      m - zmienna typu vector         |
 |  Zwraca:                                                                   |
 |      true jeśli wpółrzędne takie same                               |
    false w przeciwnym wypadku
 */
/*! 
* Przeciążenie operatora ==   
* Realizuje porównanie współrzędnych dwóch wektorów
* \param[in]  - this - pierwszy wektor,        
* \param[in]  - m - drugi wektor.                                         
* \return true -jeśli wektory są takie same
* false - w przeciwnym wypadku      
*/
template <typename type,  int size1>
bool  Vector<type,size1>::operator == ( const Vector &m) const {

//for (int i=0; i<SIZE; ++i) { 
if (abs(this->size[0] - m.size[0]) <= MIN_DIFF && abs(this->size[1] - m.size[1]) <= MIN_DIFF && abs(this->size[2] - m.size[2]) <= MIN_DIFF ) 
    return true;

  else
    return false;
//}
//return true;
}