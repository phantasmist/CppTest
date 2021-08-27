#include<math.h>

//Swap ����: ��Ŀ ������ ��..
/*
void swapVal(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swapRef(int& a, int& b) //������ �Ⱦ�
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swapRef(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
*/


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
    Point operator+(Point p)
    {
        int x = this->x + p.x;
        int y = this->y + p.y;
        return Point(x, y);
    }
    Point operator+=(Point p)
    {
        x += p.x; y += p.y;
        return *this; //this�� �ڽ��� ����Ű�� �����ʹϱ�
    }
    //scalar multiplication
    Point operator*(int s)
    {
        return Point((this->x) * s, (this->y) * s);
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