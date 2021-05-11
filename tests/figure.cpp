// doctests for Figure class

#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "vector.hh"
#include "figure.hh"


TEST_CASE("konstruktor bezparametryczny")
{
  Figure f;
  Vector v;
  CHECK(f(0)==v );
  CHECK(f(2)==v );
}


TEST_CASE("konstruktor parametryczny, wierzchołki")
{
    double arg1[]={1,2}; double arg2[]={3,4}; 
  Vector vec1(arg1); Vector vec2(arg2);
  Vector ar[]={vec1,vec2};
  Figure f(ar);
  
  CHECK(f(0)==vec1 );
  CHECK(f(1)==vec2 );
}

TEST_CASE("konstruktor parametryczny, długości boków")
{
    double arg1[]={1,2};  
  Figure f(arg1);
  
  CHECK(f[0]==1);
  CHECK(f[1]==2 );
}

TEST_CASE("metoda length")
{
  double arg1[]={1,1}; double arg2[]={4,5}; 
  Vector vec1(arg1); Vector vec2(arg2);
  Vector ar[]={vec1,vec2};
  Figure f(ar);
  f=f.length(f);
  
  CHECK(f[0]==5);
}

TEST_CASE("operator porównania")
{
  Figure f;
  f[0]=10; f[1]=22; f[2]=10; f[3]=22;
  
  CHECK(f[0]==f[2]);
  CHECK(f[1]==f[3]);
}

TEST_CASE("metoda rotate")
{
  double arg1[]={1,1}; double arg2[]={4,5}; double arg3[]={-1,-1}; double arg4[]={-4,-5};
  Vector vec1(arg1); Vector vec2(arg2); Vector vec5(arg3); Vector vec6(arg4);
  Vector ar[]={vec1,vec2};
  Figure f(ar);
  Matrix m; m.make(180);
  f.rotate(m, 3);
  
  CHECK(f(0)==vec5);
  CHECK(f(1)==vec6);
}

TEST_CASE("metoda rotate2")
{
  double arg1[]={1,1}; double arg2[]={4,5}; double arg3[]={-1,-1}; double arg4[]={-4,-5};
  Vector vec1(arg1); Vector vec2(arg2); Vector vec5(arg3); Vector vec6(arg4);
  Vector ar[]={vec1,vec2};
  Figure f(ar);
  Matrix m; m.make(-180);
  f.rotate(m, 3);
  
  CHECK(f(0)==vec5);
  CHECK(f(1)==vec6);
}


TEST_CASE("metoda read")
{
  Figure f;

std::istringstream in("10 2");

    std::ostringstream out;
f.read(in, out);
double args[2]={10, 2};
    Vector v(args);

  CHECK(f(0)==v);
}


TEST_CASE("metoda showlength")
{
  Figure f;
  f[0]=10; f[1]=22; f[2]=10; f[3]=22;

    std::ostringstream out;
 f.showlength(f,out);

  CHECK(out.str() == "Dluzsze przeciwlegle boki sa sobie rowne.\nDlugosc pierwszego boku:    22.0000000000\nDlugosc drugiego boku:    22.0000000000\n\nKrotsze przeciwlegle boki sa sobie rowne.\nDlugosc pierwszego boku:    10.0000000000\nDlugosc drugiego boku:    10.0000000000\n");
}

TEST_CASE("metoda showlength2")
{
  Figure f;
  f[0]=11; f[1]=22; f[2]=10; f[3]=22;

    std::ostringstream out;
 f.showlength(f,out);

  CHECK(out.str() == "Dlugosci bokow nie sa sobie rowne\n   11.0000000000~~   10.0000000000\n   22.0000000000~~   22.0000000000\n");
}

TEST_CASE("operator indeksowania () 1")
{
  double arg1[]={1,1}; double arg2[]={4,5}; 
  Vector vec1(arg1); Vector vec2(arg2); 
  Vector ar[]={vec1,vec2};
  Figure f(ar);
  double args[2]={1,1}; double args2[2]={4,5};
  Vector q(args); Vector e(args2);
  Vector w,v;
  w=f(0); v=f(1);
  
  CHECK(w==q );
  CHECK(v==e );
}

TEST_CASE("operator indeksowania () 2")
{
  Figure f;
  double args[2]={1,1}; double args2[2]={4,5};
  Vector q(args); Vector e(args2);
  Vector w=q; Vector v=e;
  f(0)=q; f(1)=e;
  
  CHECK(f(0)==w );
  CHECK(f(1)==v );
}

TEST_CASE("operator indeksowania () 3")
{
  double arg1[]={1,1}; double arg2[]={4,5}; 
  Vector vec1(arg1); Vector vec2(arg2); 
  Vector ar[]={vec1,vec2};
  Figure f(ar);

    WARN_THROWS (f(7));
}

TEST_CASE("operator indeksowania [] 1")
{
  Figure f;
  double w,e;
  f[0]=10;f[1]=26;
  w=f[0]; e=f[1];
  
  CHECK(w==10 );
  CHECK(e==26 );
}

TEST_CASE("operator indeksowania [] 2")
{
  Figure f;
  double w=11, e=14;
  f[0]=w; f[1]=e;
  
  CHECK(f[0]==11 );
  CHECK(f[1]==14 );
}

TEST_CASE("operator indeksowania [] 3")
{
  Figure f;
  f[0]=10;f[1]=26;

    WARN_THROWS (f[7]);
}

TEST_CASE("operator wyświetlania") {
    
    double arg1[]={1,1}; double arg2[]={4,5}; double arg3[]={1,1}; double arg4[]={4,5}; double arg5[]={1,1}; 
  Vector vec1(arg1); Vector vec2(arg2); Vector vec3(arg3); Vector vec4(arg4); Vector vec5(arg5);
  Vector ar[]={vec1,vec2,vec3,vec4,vec5};
  Figure f(ar);
    
    std::ostringstream out;

    out << f;

    CHECK (out.str() == "    1.0000000000    1.0000000000\n    4.0000000000    5.0000000000\n    1.0000000000    1.0000000000\n    4.0000000000    5.0000000000\n    1.0000000000    1.0000000000\n");
}