#include <iostream>
#include "MyHeader.h"

using namespace std;

void showClass(Student &st1) //reference 아규먼트
{
	cout << "name: " << st1.name() << "  ";
	cout << "kor: " << st1.kor() << "  ";
	cout << "eng: " << st1.eng() << "  ";
	cout << "avg: " << st1.avg() << "  ";
	cout << "tot: " << st1.tot() << "  ";
	//cout << "rank: " << st1.rank() << endl;
}

void main() 
{
	Student st1(0, 80, 73, "홍길동", 3);
	//showClass(st1);


	int num, age, kor, eng;
	char name[20]; // 인코딩 ANSI로 할 것
	int cnt = 0;
	char buf[300];
	Student* stu[100]; //4byte짜리 포인터의 배열이 됨
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
				//실제메모리 위치를 바꾸는게 아니라 포인터만 바꿔서 편하게 가자
				swapRef((int*)stu[i], (int*)stu[j]);
			}
		}
	}

	cout << "After\n";
	for (int i = 0; i < cnt; i++)
	{
		showClass(*stu[i]);
	}

}