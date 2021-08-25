#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Person
{
public:
	//이거 정석 해결법 찾아야됨
    string name;
    int age;
	//이거 기본 생성자 문제 못고치나..
    Person(string name = "홍길동", int age = 0) : name(name), age(age) {}
};

class Student : public Person
{
public:
    int kor;
    int eng;
    double avg;

    Student(string name = "홍길동", int age = 0, int kor = 0, int eng = 0) : Person(name, age), kor(kor), eng(eng)
    {
        avg = (double)((kor + eng) / 2);
    }
};

//밑에 datatype을 sizeof()로 계산할 수도 있다
void SWAP(void* A, void* B, int datatype)
{
	switch (datatype)
	{	//중괄호 안씌우면 로컬변수 선언이 안됨
	case 1: {char c; char* a = (char*)A; char* b = (char*)B; c = *a; *a = *b; *b = c; break; }
	case 4: {int c; int* a = (int*)A; int* b = (int*)B; c = *a; *a = *b; *b = c; break; }
	case 8: {double c; double* a = (double*)A; double* b = (double*)B; c = *a; *a = *b; *b = c; break; }
	case sizeof(Student) : {Student c; Student* a = (Student*)A; Student* b = (Student*)B; c = *a; *a = *b; *b = c; break; }
	default: printf("wrong datatype!"); break;
	}
}

void stuSort(Student* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{	//(a+i)-> : i번째 구조체 포인터 avg 값 참조
			if ((a + i)->avg < (a + j)->avg)
			{
				SWAP(a + i, a + j, sizeof(Student));
			}
		}
	}
}

int main()
{
	int num;
	int tmp;
	Student* stds;

	
	FILE* fin = fopen("C:\\Users\\phantasmist\\table1.txt", "r");
	FILE* fout = fopen("C:\\Users\\phantasmist\\table2.txt", "w+b");

	fscanf(fin, "%d", &num);
	stds = new Student[num];

	for (int i = 0; i < num; i++) fscanf(fin, "%s", stds[i].name); 
	for (int i = 0; i < num; i++) fscanf(fin, "%d", &stds[i].kor); 
	for (int i = 0; i < num; i++) fscanf(fin, "%d", &stds[i].eng);
	for (int i = 0; i < num; i++) stds[i].avg = (double)(stds[i].kor + stds[i].eng) / 2;

	
	fprintf(fout, "Before >> \n");
	fprintf(fout, "%-7s %-7s %-7s %-7s\n", "이름", "국어", "영어", "평균");
	//printf("%-7s %-7s %-7s %-7s\n", "이름", "국어", "영어", "평균");
	// 요 아래가 이상한건데..
	for (int i = 0; i < num; i++) 
	{
		fprintf(fout, "%7s %7d %7d %7.2f\n", stds[i].name, stds[i].kor, stds[i].eng, stds[i].avg);
		printf("%7s %7d %7d %7.2f\n", stds[i].name, stds[i].kor, stds[i].eng, stds[i].avg);
	}

	stuSort(stds, num);

	//stdout: 콘솔출력
	fprintf(fout, "After >> \n");
	//fprintf(fout, "%-7s %-7s %-7s %-7s\n", "이름", "국어", "영어", "평균");
	for (int i = 0; i < num; i++)
		fprintf(fout, "%7s %7d %7d %7.2f\n", stds[i].name, stds[i].kor, stds[i].eng, stds[i].avg);

	fcloseall(); // 파일 전부 닫기
}

