//doctest for Matrix class
#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "vector.hh"

TEST_CASE("konstruktor bezparametryczny")
{
  Matrix m;
  CHECK(m(0,0)==0 );
  CHECK(m(1,1)==0 );
}


TEST_CASE("konstruktor parametryczny")
{
  double args[2][2]={{1,2},{3,4}};
  Matrix m(args);
  CHECK(m(0,1)==2 );
  CHECK(m(1,1)==4 );
}

TEST_CASE("operator mnożenia")
{
    Vector r;
  double args[2][2]={{1,2},{3,4}};
  Matrix m(args);
  double args2[2]={1,2};
  Vector v(args2);
    r=m*v;

  CHECK(r[0]==5 );
  CHECK(r[1]==11 );
}

TEST_CASE("operator dodawania")
{
    Matrix r;
  double args[2][2]={{1,2},{3,4}};
  Matrix m(args);
  double args2[2][2]={{1,2},{3,4}};
  Matrix k(args2);
    r=m+k;

  CHECK(r(0,1)==4 );
  CHECK(r(1,1)==8 );
}

TEST_CASE("operator indeksowania 1")
{
  double args[2][2]={{1,2},{3,4}};
  double x,y;
  Matrix m(args);
  x=m(0,0); y=m(1,1);
  
  CHECK(x==1 );
  CHECK(y==4 );
}

TEST_CASE("operator indeksowania 2")
{
  double x=3,y=4;
  Matrix m;
  m(0,0)=x; m(1,1)=y;
  
  CHECK(m(0,0)==3 );
  CHECK(m(1,1)==4 );
}

TEST_CASE("operator indeksowania 3")
{
  double args[2][2]={{1,2},{3,4}};
  Matrix m(args);

    WARN_THROWS (m(10,5));
}

TEST_CASE("operator wyświetlania") {
    
    double args[2][2]={{1,2},{3,4}};
  Matrix m(args);
    
    std::ostringstream out;

    out << m;

    CHECK (out.str() == "    1.0000000000    2.0000000000    3.0000000000    4.0000000000");
}

TEST_CASE("operator wczytywania") {
    Matrix m;
    
    std::istringstream in("10");
    in >> m(0,0);

    std::ostringstream out;
    out << m(0,0);

    CHECK (out.str() == "10");      //niestety nie wiem czemu raz na wyjściu mamy liczby typu 1.0000000000, a raz po prostu 10 
}

TEST_CASE("metoda make")
{
  double args[2][2]={{1,2},{3,4}};
  //double r=sqrt(2)/2;   
  Matrix m(args);
  m.make(45);
  
  CHECK(m(0,0)==cos(M_PI/4) );
  CHECK(m(0,1)==-sin(M_PI/4) );
  CHECK(m(1,0)==sin(M_PI/4) );
  CHECK(m(1,1)==cos(M_PI/4) );
}