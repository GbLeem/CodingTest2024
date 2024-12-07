#include <iostream>
using namespace std;

int board[10] = { 3,1,2,4,8,9,6,11,5,10 };

void Print()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << board[i] << " ";
	}
	cout << "\n";
}
void bubble_sort()
{
	while (1)
	{
		int cnt = 0; //sort 되었는지 체크
		for (int i = 0; i < 10 - 1; ++i)
		{
			if (board[i] > board[i + 1])
			{
				int temp = board[i + 1];
				board[i + 1] = board[i];
				board[i] = temp;
			}
			else
				cnt++;
		}
		if (cnt == 9)
			break;
	}
}

int main()
{
	Print();
	bubble_sort();
	Print();
}