#include <cstdio> //stdioh.h 대신 쓸 수 있음
#include <iostream>   // 괄호(<>): 컴파일러 기본경로
//#include "MyHeader.h" // 따옴표(""): 상대경로
#include "MyLib.cpp"

using namespace std;


int main()
{
    /*
    cout << "Hello CPP!\n\n";
    int a, b;
    a = 10;
    b = 20;

    cout << "초깃값 a: " << a << "초깃값 b: "<<b<<endl;

    swapVal(a, b);
    cout << "swapVal\n중간값 a: " << a << "중간값 b: " << b << endl;

    swapRef(a, b);
    printf("swapRef(ref)\n결과값: a: %d 결과값 b: %d\n", a, b);
    //cout << "swapRef\n결과값 a: " << a << "결과값 b: " << b << endl;

    swapRef(&a, &b);
    printf("swapRef(ptr)\n결과값: a: %d 결과값 b: %d\n", a, b);
    */

    Point p1; // Point p1(); 도 가능
    Point p2(10, 20);
    Point* p3 = new Point(20, 30);
    printf("Point class 변수의 동적 할당: p3(%d, %d)\n", p3->X(), p3->Y());
    printf("distance b/w p1(%d, %d) and  p2(%d, %d) is %f\n", p1.X(), p1.Y(), p2.X(), p2.Y(), p1.distance(p2));

    Point3D pp1;
    Point3D pp2(10, 20, 30);
    Point3D *pp3 = new Point3D;
    printf("Point3D class 변수의 동적 할당: pp3(%d, %d, %d)\n", pp3->X(), pp3->Y(), pp3->Z());
    printf("distance b/w pp1(%d, %d, %d) and  pp2(%d, %d, %d) is %f\n" ,
        pp1.X(), pp1.Y(), pp1.Z(), pp2.X(), pp2.Y(), pp2.Z(), pp1.distance(pp2));

}
