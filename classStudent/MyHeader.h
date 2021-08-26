#include <iostream>
using namespace std;

//Prototype 들
void swapVal(int a, int b);
void swapRef(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapRef(int& a, int& b) //포인터 안씀
{
    int tmp = a;
    a = b;
    b = tmp;
}


class Point
{
    //default 제어 지시자가 private임
    int x;
    int y;
public:
    //생성자부터..
    Point(int x = 0, int y = 0) : x(x)
    {
        this->y = y;
    }
    int X() { return x; }
    int Y() { return y; }

    void SetX(int x) { this->x = x; }
    void SetY(int y) { this->y = y; }
    //private x, y에 접근 가능
    double distance(Point p) //포인트 p와의 거리
    {
        int delta_x = (x - p.x) * (x - p.x);
        int delta_y = (y - p.y) * (y - p.y);

        double dist = sqrt(delta_x + delta_y); // sqrt: math.h 필요
        return dist;
    }
};

class Point3D : public Point // Point class 상속
{
private:
    int z;

public:
    Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z)
    {}
    int Z() { return z; }
    void SetZ(int z) { this->z = z; }
    //Point의 private 변수에 직접접근 불가능
    double distance(Point3D p) //포인트 p와의 거리
    {
        int delta_x = (X() - p.X()) * (X() - p.X());
        int delta_y = (Y() - p.Y()) * (Y() - p.Y());
        int delta_z = (z - p.z) * (z - p.z);

        double dist = sqrt(delta_x + delta_y + delta_z);
        return dist;
    }

};

//정적 메모리 할당 버전
class Person
{
private:
    int Number; //ID번호
    string Name; // char *name;
    int Age;

public:
    Person(int num, string str = "홍길동", int a = 0) : Number(num), Age(a)
    {
        Name = str;
    }

    int age() { return Age; }
    string name() { return Name; }
    void setAge(int a) { Age = a; } 
    void setName(string str) 
    {   
        Name = str;
    }
};

class Student : public Person
{
private:
    int Kor;
    int Eng;
    int Tot;
    double Avg;
    int Rank;

    void calc() {
        Tot = Kor + Eng;
        Avg = Tot / 2;
    }

public:
    Student(int num, int kor, int eng, string str="홍길동", int age = 0) : Person(num, str, age)
    {
        this->Kor = kor;
        this->Eng = eng;
        calc();
    }
    int kor() { return Kor; }
    int eng() { return Eng; }
    int tot() { return Tot; }
    double avg() { return Avg; }
    int rank() { return Rank; }
    void setKor(int k) { Kor = k; calc(); }
    void setEng(int e) { Eng = e; calc(); }
    void setRank(int r) { Rank = r; }

};

//동적 생성 버전
class PersonEX
{
private:
    int Number; //ID번호
    char* Name; // malloc/new 등으로 동적 할당 필요
    int Age;

public:
    PersonEX(int num, char* str, int a) : Number(num), Age(a)
    {
        Name = new char[strlen(str)]; 
        strcpy(Name, str);
    }
    ~PersonEX()
    {
        delete Name;
    }
    int age() { return Age; }
    char* name() { return Name; }
    void setAge(int a) { Age = a; }

    void setName(char* str)
    {
        delete[] Name; //메모리 반환
        Name = new char[strlen(str)]; 
        strcpy(Name, str);
    }

};
