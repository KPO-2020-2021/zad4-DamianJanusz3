#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "vector.hh"
#include "cuboid.hh"
#include "scene.hh"


TEST_CASE("konstruktor bezparametryczny")
{
  Scene f;
  /*Matrix<double,3> v;*/ Vector<double,3> g;
  CHECK(f.cube(0)==g );
  CHECK(f.matrixx(0,1)==0 );
  CHECK(f.matrixx(2,2)==1 );
}


TEST_CASE("konstruktor parametryczny, bryła i macierz obrotu")
{
    
    double arg1[]={1,2,3}; double arg2[]={3,4,5}; 
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2);
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);

  double args[3][3]={{1,2,3},{1,5,3},{7,2,3}};
  Matrix<double,3> v(args);

Scene sc(f,v);
  
  CHECK(sc.cube(0)==vec1 );
  CHECK(sc.cube(1)==vec2 );
  CHECK(sc.matrixx(0,1)==2 );
  CHECK(sc.matrixx(2,0)==7 );
}


TEST_CASE("operator wyświetlania") {
    
    Cuboid f;
    double args[3][3]={{1,2,3},{1,5,3},{7,2,3}};
    Matrix<double,3> v(args);
    Scene sc(f,v);
    std::ostringstream out;

    out << sc;

    CHECK (out.str() == "    1.0000000000    2.0000000000    3.0000000000    1.0000000000    5.0000000000    3.0000000000    7.0000000000    2.0000000000    3.0000000000");
}


TEST_CASE("metoda amount") {
    
    Cuboid f;
    double args[3][3]={{0,1,0},{0,0,-1},{-1,0,0}};
    Matrix<double,3> v(args);
    Scene sc(f,v);
    sc=sc.amount(3);

    CHECK(sc.matrixx(0,0)==1 );
    CHECK(sc.matrixx(1,1)==1 );
    CHECK(sc.matrixx(2,0)==0 );
}