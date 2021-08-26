void swapVal(int a, int b);
void swapRef(int &a, int &b);
void swapRef(int *a, int *b);

class Point
{
    //default ���� �����ڰ� private��
    int x;
    int y;
public:
    //�����ں���..
    Point(int x = 0, int y = 0) : x(x)
    {
        this->y = y;
    }
    int X() { return x; }
    int Y() { return y; }

    void SetX(int x) { this->x = x; }
    void SetY(int y) { this->y = y; }
    //private x, y�� ���� ����
    double distance(Point p) //����Ʈ p���� �Ÿ�
    {
        int delta_x = (x - p.x) * (x - p.x);
        int delta_y = (y - p.y) * (y - p.y);

        double dist = sqrt(delta_x + delta_y); // sqrt: math.h �ʿ�
        return dist;
    }
};

class Point3D : public Point // Point class ���
{
private:
    int z;

public:
    Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z)
    {}
    int Z() { return z; }
    void SetZ(int z) { this->z = z; }
    //Point�� private ������ �������� �Ұ���
    double distance(Point3D p) //����Ʈ p���� �Ÿ�
    {
        int delta_x = (X() - p.X()) * (X() - p.X());
        int delta_y = (Y() - p.Y()) * (Y() - p.Y());
        int delta_z = (z - p.z) * (z - p.z);

        double dist = sqrt(delta_x + delta_y + delta_z);
        return dist;
    }

};

//���� �޸� �Ҵ� ����
class Person
{
private:
    int Number; //ID��ȣ
    char Name[20]; // char *name;
    int Age;

public:
    Person(int num): Number(num), Age(0)
    {
        strcpy(Name, "ȫ�浿");
    }
    Person(int num, char* str, int a) : Number(num), Age(a)
    {
        strcpy(Name, str);
    }

    int age() { return Age; }
    char* name() { return Name; }
    void setAge(int a) { Age = a; } 
    void setName(char *str) 
    {   
        strcpy(Name, str);
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
    Student(int num, int kor, int eng): Person(num)
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

//���� ���� ����
class PersonEX
{
private:
    int Number; //ID��ȣ
    char* Name; // malloc/new ������ ���� �Ҵ� �ʿ�
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
        delete[] Name; //�޸� ��ȯ
        Name = new char[strlen(str)]; 
        strcpy(Name, str);
    }

};
