#pragma once

/*!
 * \file
 * \brief Uszczególnienie szablonu dla typu double i rozmiaru 3.
 * 
 * Plik zawiera definicję Matrix3x3
 */

#include "matrix.hh"

typedef Matrix<double,3>  Matrix3x3;


/*! 
* Przeciazenie operatora <<  uszczególnione 
* Wyświetla macierz3x3 na standardowe wyjście  
* \param[in]  - out - strumien wyjsciowy,
* \param[in]  - mat - macierz.                                                 
* \return Zwraca strumien wyjsciowy     
*/
std::ostream &operator<<(std::ostream &out, const Matrix<double, SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << std::setw(16) << std::fixed << std::setprecision(10) << mat(i, j); 
        }
        std::cout << std::endl;
    }
    return out;
}