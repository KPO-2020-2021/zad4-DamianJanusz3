#pragma once

/*!
 * \file
 * \brief Definicja klasy Matrix
 * 
 * Plik zawiera definicję klasy Matrix i wszyskie jej metody
 */

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include<iomanip>


/*!
 * Matrix to tablica dwuwymiarowa danego typu o danym rozmiarze
 */
template <typename type1,  int size2>
class Matrix {

private:
    type1 value[size2][size2];               // Wartosci macierzy

public:
/*! 
 * Konstruktor parametryczny klasy Matrix
 */
    Matrix(double [SIZE][SIZE]);            
/*! 
 * Konstruktor bezparametryczny klasy Matrix
 */
    Matrix();                               
/*! 
 * Operator mnożenia przez wektor
 */
    Vector<double,SIZE> operator * (Vector<double,SIZE> tmp);           
/*! 
 * Operator dodawania macierzy
 */
    Matrix operator + (Matrix tmp);
/*! 
 * Operator indeksowania
 */
    type1  &operator () (unsigned int row, unsigned int column);
/*! 
 * Operator indeksowania const
 */    
    const type1 &operator () (unsigned int row, unsigned int column) const;
/*! 
 * Metoda tworząca macierz obrotu o zadany kąt wokół osi Z
 */
    void make3DZ (type1 alfa);
/*! 
 * Metoda tworząca macierz obrotu o zadany kąt wokół osi Y
 */
    void make3DY (type1 alfa);
/*! 
 * Metoda tworząca macierz obrotu o zadany kąt wokół osi X
 */
    void make3DX (type1 alfa);
/*! 
 * Metoda obliczająca wyznacznik metodą gaussa
 */
    Vector<double,SIZE> gaussdet (int n);
/*! 
 * Operator mnożenia macierzy przez macierz
 */
    Matrix operator * (Matrix m);
/*! 
 * Metoda czyszcząca macierz
 */
    void clear();

};

//template <typename type1, unsigned int size2>
//Matrix<type1, size2> multiply (Matrix<type1, size2> m, Matrix<type1, size2> v, double amount );

//template <typename type1, unsigned int size2>
//std::istream &operator>>(std::istream &in, Matrix<type1, size2> &mat);

//template <typename type1, unsigned int size2>
//std::ostream &operator<<(std::ostream &out, Matrix<type1, size2> const &mat);



/*! 
* Realizuje obliczanie wyznacznika macierzy metodą gaussa       
* \param[in]  - this - macierz,
* \param[in]  - n - ilość niewiadomych.                                                  
* \return Zwraca wektor będący wyznacznikiem macierzy     
*/
template <typename type1,  int size2>
Vector<double,SIZE> Matrix<type1, size2>::gaussdet (int n) {
/* Applying Gauss Elimination */
Vector<double,SIZE> x;
int i,j,k;
double ratio;



	 for(i=1;i<=n-1;++i)
	 {
		  if(this->value[i][i] == 0.0)
		  {
			   //std::cout<<"Mathematical Error!";
               throw std::runtime_error("0 na glownej przekatnej");
			   //exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = this->value[j][i]/this->value[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		this->value[j][k] = this->value[j][k] - ratio*this->value[i][k];
			   }
		  }
	 }
     //return *this;
	 /* Obtaining Solution by Back Substitution Method */
	 x[n] = this->value[n][n+1]/this->value[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = this->value[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - this->value[i][j]*x[j];
		  }
		  x[i] = x[i]/this->value[i][i];
	 }
return x;
}


 
/*! 
* Realizuje mnozenie macierzy przez wektor.        
* \param[in]  - this - macierz, czyli pierwszy skladnik mnozenia,
* \param[in]  - tmp - wektor, czyli drugi skladnik mnozenia.                                                  
* \return Zwraca wektor będący iloczynem podanych składników      
*/
template <typename type1,  int size2>
Vector<double,SIZE> Matrix<type1, size2>::operator * (Vector<double,SIZE> tmp) {
    Vector<double,SIZE> result;
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}



/*! 
* Przeciążenie dodawania macierzy        
* \param[in]  - this - macierz, czyli pierwszy skladnik dodawania,
* \param[in]  - tmp - macierz, czyli drugi skladnik dodawania.                                                  
* \return Zwraca  Macierz - sumę dwóch podanych macierzy.      
*/
template <typename type1,  int size2>
Matrix<type1, size2> Matrix<type1, size2>::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}



/*! 
* Konstruktor bezparametryczny klasy Matrix.      
* \param[in]  - brak,                                                 
* Wypełnia tablicę w ten sposób, że tworzy macierz jednostkową      
*/
 template <typename type1,  int size2>
Matrix<type1, size2>::Matrix() {
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (i==j) {value[i][j] = 1;}
            else
            value[i][j] = 0;
        }
    }
}



/*! 
* Konstruktor parametryczny klasy Matrix.      
* \param[in]  - tmp - dwuwymiarowa tablica z elementami typu double.                                                 
* Wypełnia macierz wartościami z tablicy podanej w argumencie     
*/
template <typename type1,  int size2>
Matrix<type1, size2>::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}




/*! 
* Funktor macierzy     
* \param[in]  - row - numer wiersza.
* \param[in]  - column - numer kolumny.                                                 
* \return Zwraca  wartosc macierzy w danym miejscu tablicy.     
*/
template <typename type1, int size2>
type1 &Matrix<type1, size2>::operator()(unsigned int row, unsigned int column) {

    if (row >= size2) {
        //std::cout << "Error: Macierz jest poza zasiegiem"; 
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    if (column >= size2) {
        //std::cout << "Error: Macierz jest poza zasiegiem";
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    return value[row][column];
}



/*! 
* Funktor macierzy     
* \param[in]  - row - numer wiersza.
* \param[in]  - column - numer kolumny.                                                 
* \return Zwraca  wartosc macierzy w danym miejscu tablicy jako stała.     
*/
template <typename type1,  int size2>
const type1 &Matrix<type1, size2>::operator () (unsigned int row, unsigned int column) const {

    if (row >= size2) {
        //std::cout << "Error: Macierz jest poza zasiegiem";
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    if (column >= size2) {
        //std::cout << "Error: Macierz jest poza zasiegiem";
        throw std::runtime_error("Macierz jest poza zasiegiem");
        exit(0); 
    }

    return value[row][column];
}




/*! 
* Przeciazenie operatora >>     
* \param[in]  - in - strumien wejsciowy,
* \param[in]  - mat - macierz.                                                 
* \return Zwraca strumien wejsciowy     
*/
template <typename type1,  int size2>
std::istream &operator>>(std::istream &in,Matrix<double, SIZE> &mat) {
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}



/*! 
* Przeciazenie operatora <<  
* Wyświetla macierz na standardowe wyjście  
* \param[in]  - out - strumien wyjsciowy,
* \param[in]  - mat - macierz.                                                 
* \return Zwraca strumien wyjsciowy     
*/
template <typename type1,  int size2>
std::ostream &operator<<(std::ostream &out, const Matrix<type1, SIZE> &mat) {
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cout << std::setw(16) << std::fixed << std::setprecision(10) << mat(i, j); 
        }
        std::cout << std::endl;
    }
    return out;
}



/*! 
* Metoda make3DZ  
* tworzy macierz obrotu o zadany kąt alfa wokół osi OZ  
* \param[in]  - this - macierz,
* \param[in]  - alfa - kat obrotu.                                                 
* Modyfikuje daną macierz tworząc z niej macierz obrotu     
*/
template <typename type1,  int size2>
void Matrix<type1, size2>::make3DZ (type1 alfa) {
    double alfainrad = alfa * M_PI /180;
    this->value[0][0]= cos( alfainrad);
    this->value[0][1]=(-1)*( sin( alfainrad));
    this->value[1][0]= sin( alfainrad);
    this->value[1][1]= cos( alfainrad);   
    
}


/*! 
* Metoda make3DY  
* tworzy macierz obrotu o zadany kąt alfa wokół osi OY  
* \param[in]  - this - macierz,
* \param[in]  - alfa - kat obrotu.                                                 
* Modyfikuje daną macierz tworząc z niej macierz obrotu     
*/
template <typename type1,  int size2>
void Matrix<type1, size2>::make3DY (type1 alfa) {
    double alfainrad = alfa * M_PI /180;
    this->value[0][0]= cos( alfainrad);
    this->value[0][2]= sin( alfainrad);
    this->value[2][0]= (-1)*(sin( alfainrad));
    this->value[2][2]= cos( alfainrad);   
    
}


/*! 
* Metoda make3DX  
* tworzy macierz obrotu o zadany kąt alfa wokół osi OX  
* \param[in]  - this - macierz,
* \param[in]  - alfa - kat obrotu.                                                 
* Modyfikuje daną macierz tworząc z niej macierz obrotu     
*/
template <typename type1,  int size2>
void Matrix<type1, size2>::make3DX (type1 alfa) {
    double alfainrad = alfa * M_PI /180;
    this->value[1][1]= cos( alfainrad);
    this->value[1][2]=(-1)*( sin( alfainrad));
    this->value[2][1]= sin( alfainrad);
    this->value[2][2]= cos( alfainrad);   
    
}


/******************************************************************************
 |  Funkcja multiply - mnoży macierz obrotu z wektorem                        |
 |  Argumenty:                                                                |
 |      m - macierz obrotu                                                    |
 |      v - wektor                                                            |
 |      amount - ilość powtórzeń mnożenia                                     |
 |  Zwraca:                                                                   |
 |      wektor v po obrocie wokół środka układu współrzędnych.                |
 */
/*template <typename type1,  int size2>
Matrix<type1, size2> multiply (Matrix<type1, size2> m, Matrix<type1, size2> v,  double amount ) {

int k=0;
Matrix<double, SIZE> result;
while (k < amount) {
    result=m*v;
    ++k;
}
    return result;
}*/


/*! 
* Realizuje mnozenie macierzy przez macierz.        
* \param[in]  - this - macierz, czyli pierwszy skladnik mnozenia,
* \param[in]  - m - macierz - drugi skladnik mnozenia.                                                  
* \return Zwraca macierz będącą iloczynem podanych składników      
*/
template <typename type1,  int size2>
Matrix<type1, size2> Matrix<type1, size2>::operator * (Matrix<type1, size2> m) {
Matrix result;

for(int i = 0; i < size2; ++i ) {
    for(int j = 0; j < size2; ++j )
    {
      double l = 0;
      for(int k = 0; k < size2; ++k ) {
        l += this->value[i][k] * m.value[k][j];
      }
      result.value[i][j] = l;
    }
}
return result;

}

/*! 
* Czyści macierz tzn. robi z niej macierz jednostkową        
* \param[in]  - this - macierz, czyli pierwszy skladnik mnozenia,                                                 
* Wypełnia tablicę w ten sposób, że tworzy macierz jednostkową      
*/
template <typename type1,  int size2>
void Matrix<type1, size2>::clear() {
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (i==j) {value[i][j] = 1;}
            else
            value[i][j] = 0;
        }
    }
}

