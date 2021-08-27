#include <iostream>
#include "MyHeader.h"

using namespace std;

void showClass(Student &st1) //reference �ƱԸ�Ʈ
{
	cout << "name: " << st1.name() << "  ";
	cout << "kor: " << st1.kor() << "  ";
	cout << "eng: " << st1.eng() << "  ";
	cout << "avg: " << st1.avg() << "  ";
	cout << "tot: " << st1.tot() << "  ";
	cout << "rank: " << st1.rank() << endl;
}

void main() 
{
	string st = "string";

	Student st1(0, 80, 73, "ȫ�浿", 3);
	//showClass(st1);
	int num, age, kor, eng;
	char name[20]; // ���ڵ� ANSI�� �� ��
	int cnt = 0;
	char buf[300];
	Student* stu[100]; //4byte¥�� �������� �迭�� ��
	// vs. Student stu[100];

	FILE* fp = fopen("C:\\Users\\phantasmist\\tableX.txt", "r");
	fgets(buf, 250, fp);
	cout << "Before\n";
	while (1)
	{
		if (fscanf(fp, "%d %s %d %d %d", &num, name, &age, &kor, &eng) < 1) break;
		//cout << name << endl;
		stu[cnt++] = new Student(num, kor, eng, name, age);
		showClass(*stu[cnt - 1]);
	}
	//Class Sort
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (stu[i]->avg() < stu[j]->avg())
			{
				//�����޸� ��ġ�� �ٲٴ°� �ƴ϶� �����͸� �ٲ㼭 ���ϰ� ����
				//swapRef((int*)&stu[i], (int*)&stu[j]); //&stu[i]: stu[i]�� ����Ű�� �ּ�
				//swap(stu[i], stu[j]); //������ ������ int Ÿ���ΰ�(4byte�ϱ�)
				swapRef((int&)stu[i], (int&)stu[j]);
				

			}
		}
	}

	cout << "\nAfter\n";
	for (int i = 0; i < cnt; i++)
	{
		showClass(*stu[i]);
	}

}