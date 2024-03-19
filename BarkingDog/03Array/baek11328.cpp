//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int N;
//	cin >> N;
//
//	while (N--)
//	{
//		string str1, str2;
//		int arr[26] = { 0, };
//
//		bool possible = true;
//		cin >> str1 >> str2;
//
//		for (const auto s : str1)
//			arr[(int)s - 97]++;
//		for (const auto s : str2)
//			arr[(int)s - 97]--;
//
//		for (const auto a : arr)
//		{
//			if (a != 0)
//			{
//				possible = false;
//			}
//		}
//		if (possible)
//			cout << "Possible\n";
//		else
//			cout << "Impossible\n";
//	}
//}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--)
	{
		string str1, str2;
		int arr[26] = { 0, };
		bool possible = true;

		cin >> str1 >> str2;

		if (str1.size() != str2.size())
		{
			cout << "Impossible\n";
			continue;
		}

		else
		{			
			for (int i = 0; i < str1.size(); ++i)
			{
				arr[(int)str1[i] - 97]++;
				arr[(int)str2[i] - 97]--;
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			if (arr[i] != 0) //홀수
			{
				cout << "Impossible\n";
				possible = false;
				break;
			}
		}
		if (possible)
			cout << "Possible\n";
	}
}