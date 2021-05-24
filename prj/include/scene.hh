#pragma once

/*!
 * \file
 * \brief Definicja klasy Scene
 * 
 * Plik zawiera definicję klasy Scene
 */

#include "size.hh"
#include "matrix.hh"
#include "vector.hh"
#include "cuboid.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "vertices.hh"

/*!
 * Scene to Cuboid i macierz obrotu
 */
class Scene {
    public:
    Cuboid cube;
    Matrix<double,3> matrixx;


/*! 
* Konstruktor parametryczny klasy Cuboid
*/
    Scene(Cuboid tmp1, Matrix<double,3> tmp);
/*! 
* Konstruktor bezparametryczny klasy Cuboid
*/
    Scene(); 
/*! 
* Metoda modyfikująca macierz obrotu w zależności od liczby powtórzeń
*/
    Scene amount(int am);      
};
/*! 
* Operator wyświetlania
*/
std::ostream &operator<<(std::ostream &out, Scene const &sc);