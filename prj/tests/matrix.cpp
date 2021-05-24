//doctest for Matrix class
#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "matrix3x3.hh"
#include "vector.hh"

TEST_CASE("konstruktor bezparametryczny")
{
  Matrix<double, 3> m;
  CHECK(m(0,0)==1 );
  CHECK(m(1,1)==1 );
  CHECK(m(2,1)==0 );
}


TEST_CASE("konstruktor parametryczny")
{
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);
  CHECK(m(0,1)==2 );
  CHECK(m(1,1)==4 );
  CHECK(m(2,1)==6 );
}

TEST_CASE("operator mnożenia przez wektor")
{
    Vector <double, 3> r;
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);
  double args2[3]={1,2,3};
  Vector <double, 3> v(args2);
    r=m*v;

  CHECK(r[0]==14 );
  CHECK(r[1]==26 );
  CHECK(r[2]==36 );
}

TEST_CASE("operator dodawania")
{
    Matrix<double, 3> r;
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);
  double args2[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> k(args2);
    r=m+k;

  CHECK(r(0,1)==4 );
  CHECK(r(1,1)==8 );
  CHECK(r(2,0)==6 );
}

TEST_CASE("operator indeksowania 1")
{
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  double x,y,z;
  Matrix<double, 3> m(args);
  x=m(0,0); y=m(1,1); z=m(2,0);
  
  CHECK(x==1 );
  CHECK(y==4 );
  CHECK(z==3 );
}

TEST_CASE("operator indeksowania 2")
{
  double x=3,y=4,z=6;
  Matrix<double, 3> m;
  m(0,0)=x; m(1,1)=y; m(2,0)=z;
  
  CHECK(m(0,0)==3 );
  CHECK(m(1,1)==4 );
  CHECK(m(2,0)==6 );
}

TEST_CASE("operator indeksowania 3")
{
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);

    WARN_THROWS (m(10,5));
}

TEST_CASE("operator wyświetlania") {
    
    double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);
    
    std::ostringstream out;

    out << m;

    CHECK (out.str() == "    1.0000000000    2.0000000000    3.0000000000    3.0000000000    4.0000000000    5.0000000000    3.0000000000    6.0000000000    7.0000000000");
}

TEST_CASE("operator wczytywania") {
    Matrix<double, 3> m;
    
    std::istringstream in("10");
    in >> m(0,0);

    std::ostringstream out;
    out << m(0,0);

    CHECK (out.str() == "10");      //niestety nie wiem czemu raz na wyjściu mamy liczby typu 1.0000000000, a raz po prostu 10 
}

TEST_CASE("metoda make3DZ")
{ 
  Matrix<double, 3> m;
  m.make3DZ(45);
  
  CHECK(m(0,0)==cos(M_PI/4) );
  CHECK(m(0,1)==-sin(M_PI/4) );
  CHECK(m(1,0)==sin(M_PI/4) );
  CHECK(m(1,1)==cos(M_PI/4) );
  CHECK(m(2,2)==1 );
  CHECK(m(2,0)==0 );
}

TEST_CASE("metoda make3DX")
{
  Matrix<double, 3> m;
  m.make3DX(45);
  
  CHECK(m(1,1)==cos(M_PI/4) );
  CHECK(m(1,2)==-sin(M_PI/4) );
  CHECK(m(2,1)==sin(M_PI/4) );
  CHECK(m(2,2)==cos(M_PI/4) );
  CHECK(m(0,0)==1 );
  CHECK(m(2,0)==0 );
}

TEST_CASE("metoda make3DY")
{
  Matrix<double, 3> m;
  m.make3DY(45);
  
  CHECK(m(0,0)==cos(M_PI/4) );
  CHECK(m(0,2)==sin(M_PI/4) );
  CHECK(m(2,0)==-sin(M_PI/4) );
  CHECK(m(2,2)==cos(M_PI/4) );
  CHECK(m(1,1)==1 );
  CHECK(m(2,1)==0 );
}

TEST_CASE("operator mnożenia macierzy przez macierz")
{
    Matrix<double, 3> r;
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);
  Matrix<double, 3> v(args);
    r=m*v;

  CHECK(r(0,0)==16 );
  CHECK(r(1,1)==52 );
  CHECK(r(2,0)==42 );
}

TEST_CASE("metoda clear")
{
  double args[3][3]={{1,2,3},{3,4,5},{3,6,7}};
  Matrix<double, 3> m(args);
  m.clear();

  CHECK(m(0,0)==1 );
  CHECK(m(1,1)==1 );
  CHECK(m(2,1)==0 );
}
