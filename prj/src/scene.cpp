/*!
 * \file
 * \brief plik źródłowy
 * 
 * Plik zawiera wszystkie metody klasy Scene
 */

#include "size.hh"

#include "scene.hh"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <math.h>


 /*! 
* Konstruktor bezparametryczny klasy Scene.      
* \param[in]  - brak,                                                 
* inicjuje pole cube czystą zmienną typu Cuboid oraz macierz obrotu macierzą jednostkową     
*/
Scene::Scene() {
    Cuboid v;  Matrix<double,3> m;
    cube = v; matrixx=m; 
}



/*! 
* Konstruktor parametryczny klasy Scene.      
* \param[in]  - tmp1 - zmienna typu Cuboid, 
* \param[in]  - tmp - zmienna typu Matrix3x3,                                                
* Przypisuje odpowiednim polom wartości przekazane przez argumenty     
*/
Scene::Scene(Cuboid tmp1,Matrix<double,3> tmp) {
    cube = tmp1;
     matrixx = tmp;
}



/*! 
*  Przeciazenie operatora <<  
* do wyświetlania macierzy rotacji
* \param[in]  - strm - strumien wyjsciowy,
* \param[in]  - sc - zmienna typu Scene. 
* \return  zwraca strumien wyjsciowy.
*/
std::ostream &operator<<(std::ostream &strm, const Scene &sc) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            strm << std::setw(16) << std::fixed << std::setprecision(10) << sc.matrixx(i, j); 
        }
        std::cout << std::endl;
    }
    return strm;
}


/*! 
* Metoda modyfikująca macierz obrotu w zależności od liczby powtórzeń      
* \param[in]  - this - zmienna typu Scene, 
* \param[in]  - am - zmienna typu int określająca liczbę powtórzeń,                                                
* \return  zwraca nową macierz obrotu.     
*/
Scene Scene::amount(int am) {
    Scene result;
    result.cube=this->cube;
    if (am>0) {
for (int q=0;q<am;++q) {
    result.matrixx=this->matrixx*result.matrixx;
}
    }
    else {;}
return result;
}