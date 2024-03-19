#include <iostream>
#include <string>
using namespace std;

bool check(string &num, int arr[], int size) 
{
	int cnt = 0;

	for (int i = 0; i < num.size(); ++i)
	{
		if (arr[num[i] - '0'] == 0) 
			cnt++;
	}

	if (cnt == num.size())
		return true;
	else
		return false;
}
int arr[10] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;
	int M;
	cin >> M;	
	
	for (int i = 0; i < M; ++i)
	{
		int num;
		cin >> num;
		arr[num] ++;
	}

	int intN = stoi(N);
	int cur = 100;
	int cnt1 = 0;
	
	//100에서 이동
	if (intN < cur)
	{
		cnt1 = cur - intN;
	}
	else if(intN > cur)
	{
		cnt1 = intN - cur;
	}

	//번호 못쓸때
	if (M == 10)
	{
		cout << cnt1;
		return 0;
	}

	//번호 찾아가기
	int cnt2 = 0;
	int cnt3 = 0;

	//안고장남
	if (check(N, arr, M)) 
	{
		if (cnt1 < N.size())
			cout << cnt1;
		else
			cout << N.size();
		return 0;
	}
	else 
	{
		string N1 = N;
		string N2 = N;

		//작아지기
		while (!check(N1, arr, M))
		{
			int temp = stoi(N1);
			temp--;
			N1 = to_string(temp);
			cnt2++;
		}
		cnt2 += N1.size();
		
		//커지기 -> 0으로 해야하는 경우는 안끝남
		if(M == 9 && arr[0] == 0)
		{ 
			cnt3 = cnt2;
		}
		else
		{
			while (!check(N2, arr, M))
			{
				int temp = stoi(N2);
				temp++;
				N2 = to_string(temp);
				cnt3++;
			}
			cnt3 += N2.size();
		}
	}
	
	if (cnt2 > cnt3)
		cnt2 = cnt3;	

	if (cnt1 < cnt2)
		cout << cnt1;
	else
		cout << cnt2;
}