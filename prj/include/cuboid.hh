#pragma once

/*!
 * \file
 * \brief Definicja klasy Cuboid
 * 
 * Plik zawiera definicję klasy Cuboid
 */

#include "size.hh"
#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "vertices.hh"

/*!
 * Cuboid to tablica wektorów wierzchołków i tablica długości boków bryły
 */
class Cuboid {

private:
    Vector<double,SIZE> vertices [VERTICES];               
    double leng [SIDES];
public:
/*! 
* Konstruktor parametryczny klasy Cuboid
*/
    Cuboid(Vector<double,SIZE> [VERTICES]);            
/*! 
* Konstruktor parametryczny klasy Cuboid
*/
    Cuboid(double tmp[SIDES]);
/*! 
* Konstruktor bezparametryczny klasy Cuboid
*/
    Cuboid();                               
/*! 
* metoda obliczająca długości boków
*/
    Cuboid length (Cuboid tmp) ; 
/*! 
* operator indeksowania const dla wierzchołków
*/
    const Vector<double,SIZE> &operator () (int index) const;
/*! 
* operator indeksowania dla wierzchołków
*/
    Vector<double,SIZE> &operator () (int index);
/*! 
* operator indeksowania const dla długości boków
*/
    const double &operator [] (int index) const;
/*! 
* operator indeksowania dla długości boków
*/
    double &operator[](int index);
/*! 
* operator porównania
*/
    bool  operator == ( Cuboid m);
/*! 
* metoda odpowiedzialna za przesuwanie bryły
*/
    Cuboid move ( Vector<double,SIZE> move1);
/*! 
* metoda odpowiedzialna za rotację bryły
*/
    Cuboid rotate (Matrix<double, SIZE> m , int amount);
/*! 
* metoda odpowiedzialna za wyświetlenie długości boków
*/
    void showlength (Cuboid tmp, std::ostream& strmo) const;
/*! 
* metoda odpowiedzialna za wczytywanie współrzędnych wierzchołków
*/
    void read( std::istream& strmi, std::ostream& strmo);
/*! 
* metoda odpowiedzialna za wyznaczanie punktu środkowego bryły
*/
    Vector<double,SIZE> mid();
    
};


/*! 
* przeciążenie operatora wyświetlania
*/
std::ostream &operator << (std::ostream &out, Cuboid const &tmp);
