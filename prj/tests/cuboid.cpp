// doctests for Cuboid class

#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "vector.hh"
#include "cuboid.hh"


TEST_CASE("konstruktor bezparametryczny")
{
  Cuboid f;
  Vector<double,3> v;
  CHECK(f(0)==v );
  CHECK(f(2)==v );
}


TEST_CASE("konstruktor parametryczny, wierzchołki")
{
    double arg1[]={1,2,3}; double arg2[]={3,4,5}; 
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2);
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);
  
  CHECK(f(0)==vec1 );
  CHECK(f(1)==vec2 );
}

TEST_CASE("konstruktor parametryczny, długości boków")
{
    double arg1[]={1,2};  
  Cuboid f(arg1);
  
  CHECK(f[0]==1);
  CHECK(f[1]==2 );
}

TEST_CASE("metoda length")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,1}; double arg3[]={1,4,5};
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); Vector<double,3> vec3(arg3);
  Vector<double,3> ar[]={vec1,vec2,vec3};
  Cuboid f(ar);
  f=f.length(f);
  
  CHECK(f[0]==5);
  CHECK(f[1]==5);
}

TEST_CASE("operator porównania")
{
  Cuboid f;
  f[0]=10; f[1]=22; f[2]=10; f[3]=22;
  
  CHECK(f[0]==f[2]);
  CHECK(f[1]==f[3]);
}

TEST_CASE("metoda move")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,6}; double arg3[]={2,3,4}; double arg4[]={5,7,9}; double arg5[]={1,2,3};
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); Vector<double,3> vec5(arg3); Vector<double,3> vec6(arg4);Vector<double,3> vec7(arg5);
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);
  //Vector<double,3> v; 
  f.move(vec7);
  
  CHECK(f(0)==vec5);
  CHECK(f(1)==vec6);
}

TEST_CASE("metoda mid")
{
  double arg1[]={50,50,10}; double arg2[]={100,50,10}; double arg3[]={50,120,10}; double arg4[]={100,120,10};
  double arg5[]={50,120,110}; double arg6[]={100,120,110}; double arg7[]={50,50,110}; double arg8[]={100,50,110};double arg9[]={50,50,10}; double arg10[]={100,50,10}; double args[]={75,85,60};
  Vector<double,SIZE> vec1=arg1; Vector<double,SIZE> vec2=arg2; Vector<double,SIZE> vec3=arg3;
  Vector<double,SIZE> vec4=arg4; Vector<double,SIZE> vec5=arg5; Vector<double,SIZE> vec6=arg6;
  Vector<double,SIZE> vec7=arg7; Vector<double,SIZE> vec8=arg8; Vector<double,SIZE> vec9=arg9; Vector<double,SIZE> vec10=arg10; Vector<double,SIZE> vecs=args;
  Vector<double,SIZE> ar[]={vec1,vec2,vec3,vec4,vec5, vec6,vec7,vec8,vec9,vec10};
  Cuboid f(ar);
  Vector<double,3> v; 
  v=f.mid();
  
  CHECK(v==vecs);
  
}

TEST_CASE("metoda rotate")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,6}; double arg3[]={-1,-1,1}; double arg4[]={-4,-5,6};
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); Vector<double,3> vec5(arg3); Vector<double,3> vec6(arg4);
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);
  Matrix<double,3> m; m.make3DZ(180);
  f.rotate(m, 3);
  
  CHECK(f(0)==vec5);
  CHECK(f(1)==vec6);
}

TEST_CASE("metoda rotate2")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,6}; double arg3[]={1,-1,-1}; double arg4[]={4,-5,-6};
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); Vector<double,3> vec5(arg3); Vector<double,3> vec6(arg4);
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);
  Matrix<double,3> m; m.make3DX(-180);
  f.rotate(m, 3);
  
  CHECK(f(0)==vec5);
  CHECK(f(1)==vec6);
}

TEST_CASE("metoda rotate3")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,6}; double arg3[]={-1,1,-1}; double arg4[]={-4,5,-6};
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); Vector<double,3> vec5(arg3); Vector<double,3> vec6(arg4);
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);
  Matrix<double,3> m; m.make3DY(-180);
  f.rotate(m, 3);
  
  CHECK(f(0)==vec5);
  CHECK(f(1)==vec6);
}


TEST_CASE("metoda read")
{
  Cuboid f;

std::istringstream in("10 2 5");

    std::ostringstream out;
f.read(in, out);
double args[3]={10, 2, 5};
    Vector<double,3> v(args);

  CHECK(f(0)==v);
}


TEST_CASE("metoda showlength")
{
  Cuboid f;
  f[0]=10; f[3]=10; f[6]=10; f[9]=10; f[1]=22; f[4]=22; f[7]=22; f[10]=22; f[2]=33; f[5]=33; f[8]=33; f[11]=33;

    std::ostringstream out;
 f.showlength(f,out);

  CHECK(out.str() == "Dluzsze przeciwlegle boki sa sobie rowne.\nDlugosc pierwszego boku:    22.0000000000\nDlugosc drugiego boku:    22.0000000000\nDlugosc trzeciego boku:    22.0000000000\nDlugosc czwartego boku:    22.0000000000\n\nKrotsze przeciwlegle boki sa sobie rowne.\nDlugosc pierwszego boku:    10.0000000000\nDlugosc drugiego boku:    10.0000000000\nDlugosc trzeciego boku:    10.0000000000\nDlugosc czwartego boku:    10.0000000000\n\nPoprzeczne przeciwlegle boki sa sobie rowne.\nDlugosc pierwszego boku:    33.0000000000\nDlugosc drugiego boku:    33.0000000000\nDlugosc trzeciego boku:    33.0000000000\nDlugosc czwartego boku:    33.0000000000\n");
}

TEST_CASE("metoda showlength2")
{
  Cuboid f;
  f[0]=10; f[3]=10; f[6]=10; f[9]=10; f[1]=28; f[4]=22; f[7]=22; f[10]=22; f[2]=33; f[5]=33; f[8]=33; f[11]=33;

    std::ostringstream out;
 f.showlength(f,out);

  CHECK(out.str() == "Dlugosci bokow nie sa sobie rowne\n   10.0000000000~~   10.0000000000~~   10.0000000000~~   10.0000000000\n   28.0000000000~~   22.0000000000~~   22.0000000000~~   22.0000000000\n   33.0000000000~~   33.0000000000~~   33.0000000000~~   33.0000000000\n");
}

TEST_CASE("operator indeksowania () 1")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,6}; 
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); 
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);
  double args[3]={1,1,1}; double args2[3]={4,5,6};
  Vector<double,3> q(args); Vector<double,3> e(args2);
  Vector<double,3> w,v;
  w=f(0); v=f(1);
  
  CHECK(w==q );
  CHECK(v==e );
}

TEST_CASE("operator indeksowania () 2")
{
  Cuboid f;
  double args[3]={1,1,1}; double args2[3]={4,5,6};
  Vector<double,3> q(args); Vector<double,3> e(args2);
  Vector<double,3> w=q; Vector<double,3> v=e;
  f(0)=q; f(1)=e;
  
  CHECK(f(0)==w );
  CHECK(f(1)==v );
}

TEST_CASE("operator indeksowania () 3")
{
  double arg1[]={1,1,1}; double arg2[]={4,5,6}; 
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); 
  Vector<double,3> ar[]={vec1,vec2};
  Cuboid f(ar);

    WARN_THROWS (f(20));
}

TEST_CASE("operator indeksowania [] 1")
{
  Cuboid f;
  double w,e;
  f[0]=10;f[1]=26;
  w=f[0]; e=f[1];
  
  CHECK(w==10 );
  CHECK(e==26 );
}

TEST_CASE("operator indeksowania [] 2")
{
  Cuboid f;
  double w=11, e=14;
  f[0]=w; f[1]=e;
  
  CHECK(f[0]==11 );
  CHECK(f[1]==14 );
}

TEST_CASE("operator indeksowania [] 3")
{
  Cuboid f;
  f[0]=10;f[1]=26;

    WARN_THROWS (f[20]);
}

TEST_CASE("operator wyświetlania") {
    
    double arg1[]={1,1,1}; double arg2[]={4,5,6}; double arg3[]={1,1,1}; double arg4[]={4,5,6}; double arg5[]={1,1,1}; 
  Vector<double,3> vec1(arg1); Vector<double,3> vec2(arg2); Vector<double,3> vec3(arg3); Vector<double,3> vec4(arg4); Vector<double,3> vec5(arg5);Vector<double,3> vec6(arg1); Vector<double,3> vec7(arg2); Vector<double,3> vec8(arg3); Vector<double,3> vec9(arg4); Vector<double,3> vec10(arg5);
  Vector<double,3> ar[]={vec1,vec2,vec3,vec4,vec5,vec6,vec7,vec8,vec9,vec10};
  Cuboid f(ar);
    
    std::ostringstream out;

    out << f;

    CHECK (out.str() == "    1.0000000000    1.0000000000    1.0000000000\n    4.0000000000    5.0000000000    6.0000000000\n\n    1.0000000000    1.0000000000    1.0000000000\n    4.0000000000    5.0000000000    6.0000000000\n\n    1.0000000000    1.0000000000    1.0000000000\n    1.0000000000    1.0000000000    1.0000000000\n\n    4.0000000000    5.0000000000    6.0000000000\n    1.0000000000    1.0000000000    1.0000000000\n\n    4.0000000000    5.0000000000    6.0000000000\n    1.0000000000    1.0000000000    1.0000000000\n\n");
}