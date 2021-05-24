//doctests for Vector class//

#include "../tests/doctest/doctest.h"
#include "vector.hh"

// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.

TEST_CASE("konstruktor bezparametryczny")
{
  Vector<double,3> v;
  CHECK(v[0]==0 );
  CHECK(v[1]==0 );
  CHECK(v[2]==0 );
}


TEST_CASE("konstruktor parametryczny")
{
  double args[3]={1,2,3};
  Vector<double,3> v(args);
  CHECK(v[0]==1 );
  CHECK(v[1]==2 );
  CHECK(v[2]==3 );
}


TEST_CASE("operator dodawania")
{
    Vector<double,2> r;
  double args[2]={1,2};
  Vector<double,2> v(args);
  Vector<double,2> w(args);
  r=w+v;
  CHECK(r[0]==2 );
  CHECK(r[1]==4 );
}

TEST_CASE("operator odejmowania")
{
    Vector<double,2> r;
  double args[2]={1,2};
  double args2[2]={-1,-2};
  Vector<double,2> v(args2);
  Vector<double,2> w(args);
  r=w-v;
  CHECK(r[0]==2 );
  CHECK(r[1]==4 );
}

TEST_CASE("operator mnożenia")
{
    Vector<double,2> r;
  double args[2]={1,2};
  const double v=2;
  
  Vector<double,2> w(args);
  r=w*v;
  CHECK(r[0]==2 );
  CHECK(r[1]==4 );
}

TEST_CASE("operator dzielenia")
{
    Vector<double,2> r;
  double args[2]={1,2};
  const double v=2;
  
  Vector<double,2> w(args);
  r=w/v;
  CHECK(r[0]==0.5 );
  CHECK(r[1]==1 );
}

TEST_CASE("operator indeksowania 1")
{
  double args[2]={1,2};
  double x,y;
  Vector<double,2> w(args);
  x=w[0]; y=w[1];
  
  CHECK(x==1 );
  CHECK(y==2 );
}

TEST_CASE("operator indeksowania 2")
{
  double x=3,y=4;
  Vector<double,2> w;
  w[0]=x; w[1]=y;
  
  CHECK(w[0]==3 );
  CHECK(w[1]==4 );
}

TEST_CASE("operator indeksowania 3")
{
  double args[2]={1,2};
  Vector<double,2> w(args);

    WARN_THROWS (w[4]);
}

TEST_CASE("operator wyświetlania") {
    
    double args[2]={1,2};
  Vector<double,2> w(args);
    
    std::ostringstream out;

    out << w[0];

    CHECK (out.str() == "1");
}

TEST_CASE("operator wczytywania") {
    Vector<double,2> w;
    
    std::istringstream in("10");
    in >> w[0];

    std::ostringstream out;
    out << w[0];

    CHECK (out.str() == "10"); 
}

TEST_CASE("operator & - liczenie długości")
{
    double r;
  double args[3]={1,2,1};
  double args2[3]={4,6,1};
  Vector<double,3> v(args);
  Vector<double,3> w(args2);
    r=w&v;

    CHECK(r==5);
}

TEST_CASE("operator porównania")
{
  double args[2]={1,2};
  double args2[2]={1,2};
  Vector<double,2> v(args);
  Vector<double,2> w(args2);
  
  CHECK(v==w);
 
}