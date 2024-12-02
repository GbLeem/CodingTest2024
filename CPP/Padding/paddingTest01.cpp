#include <iostream>
using namespace std;

class A
{
	short a; //2
	int b;   //4
	int c;   //4
};

struct Name //3
{
	char name[3]; // 1*3
};

struct Point //8
{
	short point_x; //2 (+2)
	int point_y;   //4
};

struct Point2
{
	double point_x;
	int point_y;
};

struct Player //20
{
	char rank;   //1  
	short hp;    //2  
	//1 + 2 (+1)
	short mp;    //2
	//2 (+2)
	Point point; //8   -> Point의 int가 가장 큼
	//8

	Name name;   //3
	//3 (+1)

	//4*3 + 8 = 20
	

	//if) Point 대신 Poiont2를 쓰면
	//가장 큰 타입은 double로 8 바이트
	//rank + hp + mp (+3) = 8
	//Point = point_x + point_y (+4) = 16
	//name (+5) =8

	//결론 32 byte
};

int main()
{
	cout << sizeof(A) <<"\n"; //A에서 가장 큰 사이즈의 자료형 int 이므로 4byte로 패딩 -> 4*3 = 12
	cout << sizeof(Name) << "\n";
	cout << sizeof(Point) << "\n";
	cout << sizeof(Player) << "\n";


}