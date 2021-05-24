/*!
 * \file
 * \brief plik źródłowy
 * 
 * Plik zawiera wszystkie metody klasy Cuboid
 */

#include "size.hh"

#include "cuboid.hh"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <math.h>
#define MIN_DIFF 0.00001



/*! 
* Konstruktor bezparametryczny klasy Cuboid.      
* \param[in]  - brak,  
* Wypełnia tablicę wektorami zerowymi     
*/
Cuboid::Cuboid() {
    Vector<double,SIZE> v;
    for (int i = 0; i < VERTICES; ++i) {
        
            vertices[i] = v;
            
        
    }
}


/*! 
* Konstruktor parametryczny klasy Cuboid.      
* \param[in]  - tmp - jednowymiarowa tablica z elementami typu vector, 
* Wypełnia tablicę wektorów wartosciami podanymi w argumencie.     
*/
Cuboid::Cuboid(Vector<double,SIZE> tmp[VERTICES]) {
    for (int i = 0; i < VERTICES; ++i) {
        
            vertices[i] = tmp[i];
        
    }
}



/*! 
* Konstruktor parametryczny klasy Cuboid.      
* \param[in]  - tmp - jednowymiarowa tablica z elementami typu double.                                                 
* Wypełnia tablicę długości wartosciami podanymi w argumencie.     
*/
Cuboid::Cuboid(double tmp[SIDES]) {
    for (int i = 0; i < SIDES; ++i) {
        
            leng[i] = tmp[i];
        
    }
}



/*! 
* Metoda obliczająca długości między wszystkimi wierzchołkami.     
* \param[in]  - tmp - zmienna posiadająca tablicę wektorów wspołrzędnych, między którymi liczymy długości                                                 
* \return zwraca zmienną typu Cuboid posiadającą zapisane wektory współrzędnych ORAZ tablicę z długościami między wierzchołkami    
*/
Cuboid Cuboid::length (Cuboid tmp)  {
    Cuboid result;
    for (int i=0; i<VERTICES; ++i) {
        result.vertices[i]=this->vertices[i] ;
    }
    
    result.leng[0]= this->vertices[0] & this->vertices[1];
    result.leng[3]= this->vertices[2] & this->vertices[3];
    result.leng[6]= this->vertices[4] & this->vertices[5];
    result.leng[9]= this->vertices[6] & this->vertices[7];
    result.leng[1]= this->vertices[0] & this->vertices[2];
    result.leng[4]= this->vertices[1] & this->vertices[3];
    result.leng[7]= this->vertices[4] & this->vertices[6];
    result.leng[10]= this->vertices[5] & this->vertices[7];
    result.leng[2]= this->vertices[0] & this->vertices[6];
    result.leng[5]= this->vertices[1] & this->vertices[7];
    result.leng[8]= this->vertices[2] & this->vertices[4];
    result.leng[11]= this->vertices[3] & this->vertices[5];
   
    tmp=tmp;
    return result;
}



/*! 
* Przeciążenie operatora == w celu porównania długości boków.   
* \param[in]  - this - zmienna typu Cuboid, do której porównujemy   
* \param[in]  - m - zmienna typu Cuboid posiadająca długości, które porównujemy
* \return  true jeśli boki są sobie równe
*           false jeśli nie są równe
*/
bool  Cuboid::operator == (  Cuboid m)  {

if ( abs(this->leng[0] - m.leng[3]) <= MIN_DIFF && abs(this->leng[3] - m.leng[6]) <= MIN_DIFF && abs(this->leng[6] - m.leng[9]) <= MIN_DIFF
    && abs(this->leng[1] - m.leng[4]) <= MIN_DIFF && abs(this->leng[4] - m.leng[7]) <= MIN_DIFF && abs(this->leng[7] - m.leng[10]) <= MIN_DIFF
    && abs(this->leng[2] - m.leng[5]) <= MIN_DIFF && abs(this->leng[5] - m.leng[8]) <= MIN_DIFF && abs(this->leng[8] - m.leng[11]) <= MIN_DIFF
    ) 
    return true;

  else
    return false;
}



/*! 
* metoda realizująca przesunięcie o wektor.   
* \param[in]  - this - zmienna typu Cuboid   
* \param[in]  - move1 - wektor przesunięcia  
* \return  zwraca zmienną typu Cuboid po przesunięciu o wektor
*/
Cuboid Cuboid::move ( Vector<double,SIZE> move1)  {
    Cuboid result;
    for (int i=0; i<VERTICES; ++i)
    result.vertices[i]=this->vertices[i]+move1;
    
    return result;
}


/*! 
* metoda realizująca obrót danej bryły o zadany kąt i zadaną ilość razy.   
* \param[in]  - this - zmienna typu Cuboid   
* \param[in]  - m - macierz obrotu  
* \param[in]  - amount - ilość wykonań obrotu
* \return  zwraca  zmienną typu Cuboid po obróceniu o zadany kąt i zadaną ilość razy
*/
Cuboid Cuboid::rotate (Matrix<double, SIZE> m, int amount) {
    
    for(int k=0; k<amount; ++k) {
    for (int i=0; i<VERTICES; ++i) {
    this->vertices[i]= m * this->vertices[i];
    }
}
    return *this;
}



/*! 
* metoda realizująca wczytywanie współrzędnych wierzchołków ze strumienia do zmiennej typu Cuboid. 
* \param[in]  - this - zmienna typu Cuboid   
* \param[in]  - strmi - strumień wejściowy  
* \param[in]  - strmo - strumień wyjściowy
* \return  NIC
*/
 void Cuboid::read( std::istream& strmi, std::ostream& strmo) {
strmo<< "wczytywanie wspolrzednych wierzcholkow prostokata" <<std::endl;
  for (int w=0; w < VERTICES-2; ++w) {
      
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
  this->vertices[VERTICES-2]=this->vertices[0];
  this->vertices[VERTICES-1]=this->vertices[1];
  
}



/*! 
* metoda realizująca wyświetlanie długości w zależności od ich długości. 
* \param[in]  - tmp - zmiennatypu Cuboid posiadająca tablicę długości, które wyświetlimy
* \return  NIC
*/
void Cuboid::showlength (Cuboid tmp, std::ostream& strmo) const{
if ( std::max(tmp.leng[0], tmp.leng[1])==tmp.leng[0] && std::max(tmp.leng[0], tmp.leng[1])!=tmp.leng[1]) {
if ( (tmp == tmp)==true) {
       
 strmo << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[0] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[3] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[6] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[9] << std::endl;
 strmo << std::endl;
 strmo << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[1] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[4] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[7] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[10] << std::endl;
 strmo << std::endl;
 strmo << "Poprzeczne przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[2] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[5] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[8] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[11] << std::endl;
}
else {
 strmo << "Dlugosci bokow nie sa sobie rowne" << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[0] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[3] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[6] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[9] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[1] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[4] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[7] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[10] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[2] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[5] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[8] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[11] << std::endl;
}
}
else if (std::max(tmp.leng[0], tmp.leng[1])==tmp.leng[1] && std::max(tmp.leng[0], tmp.leng[1])!=tmp.leng[0]){
if ( (tmp == tmp)==true ) {
 strmo << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[1] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[4] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[7] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[10] << std::endl;
 strmo << std::endl;
 strmo << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[0] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[3] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[6] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[9] << std::endl; 
 strmo << std::endl;
 strmo << "Poprzeczne przeciwlegle boki sa sobie rowne." << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[2] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[5] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[8] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[11] << std::endl;
}
else {
 strmo << "Dlugosci bokow nie sa sobie rowne" << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[0] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[3] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[6]  << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[9] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[1] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[4] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[7] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[10] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[2] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[5] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[8] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[11] << std::endl;
}
}
else if (std::max(tmp.leng[0], tmp.leng[1])==tmp.leng[1] && std::max(tmp.leng[0], tmp.leng[1])==tmp.leng[0]){
if ( (tmp == tmp)==true ) {
 strmo << "Mamy kwadrat" << std::endl;
 strmo << "Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[1] << std::endl;
 strmo << "Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[4] << std::endl;
 strmo << "Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[7] << std::endl;
 strmo << "Dlugosc czwartego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[10] << std::endl;
 strmo << std::endl;
 strmo << "Dlugosc piątego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[0] << std::endl;
 strmo << "Dlugosc szóstego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[3] << std::endl;
 strmo << "Dlugosc siódmego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[6] << std::endl;
 strmo << "Dlugosc ósmego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[9] << std::endl;  
}
else {
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[0] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[3] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[6] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[9] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[1] << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[4] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[7] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[10] << std::endl;
 strmo << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[2] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[5] 
 << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[8] << std::endl << "~~" << std::setw(16) << std::fixed << std::setprecision(10) << tmp.leng[11] << std::endl;
}
}

}



/*! 
*  metoda realizująca obliczanie środka prostopadłościanu. 
* \param[in]  - this - dyskretnie przekazana zmienna typu Cuboid
* \return  zwraca wektor charakterystyczny figury (środek bryły)
*/
Vector<double,SIZE> Cuboid::mid() {
    Vector<double,SIZE> tmp;
    int i;
    for ( i=0; i < VERTICES-2; ++i) {
        tmp=tmp + this->vertices[i];
    }
    tmp=tmp/i;
    return tmp;
}




/*! 
*  Operator indeksowania const dla wierzchołków
* \param[in]  - index - indeks tablicy.
* \return  zwraca wartosc w danym miejscu tablicy jako stala. 
*/
const Vector<double,SIZE> &Cuboid::operator () (int index) const {
    if (index < 0 || index >= VERTICES) {
        //std::cerr << "Error: Figura? jest poza zasiegiem!" << std::endl;
        throw std::runtime_error("Figura jest poza zasiegiem");
    } 
    return vertices[index];
}



/*! 
*  Operator indeksowania dla wierzchołków
* \param[in]  - index - indeks tablicy.
* \return  zwraca wartosc w danym miejscu tablicy. 
*/
Vector<double,SIZE> &Cuboid::operator () (int index) {
    return const_cast<Vector<double,SIZE> &>(const_cast<const Cuboid *>(this)->operator () (index));
}



/*! 
*  Operator indeksowania const dla długości boków
* \param[in]  - index - indeks tablicy.
* \return  zwraca wartosc w danym miejscu tablicy jako stala. 
*/
const double &Cuboid::operator [] (int index) const {
    if (index < 0 || index >= SIDES) {
        //std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
        throw std::runtime_error("Figura jest poza zasiegiem");
    } 
    return leng[index];
}



/*! 
*  Operator indeksowania dla długości boków
* \param[in]  - index - indeks tablicy.
* \return  zwraca wartosc w danym miejscu tablicy . 
*/
double &Cuboid::operator[](int index) {
    return const_cast<double &>(const_cast<const Cuboid *>(this)->operator[](index));
}



/*! 
*  Przeciazenie operatora <<  
* do wyświetlania wierzchołków na standardowe wyjście i do streamu plikowego
* \param[in]  - out - strumien wyjsciowy,
* \param[in]  - tmp - zmienna typu Cuboid. 
* \return  zwraca strumien wyjsciowy.
*/
std::ostream &operator << (std::ostream &out, Cuboid const &tmp) {
    for (int i = 0; i < VERTICES; i+=2) {
        out  << std::setw(16) << std::fixed << std::setprecision(10) << tmp(i) <<"\n";
        out  << std::setw(16) << std::fixed << std::setprecision(10) << tmp(i+1) <<"\n";
        out << "\n";
    }

    return out;
}

