#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	int answer = 0;
	int arr1[26] = { 0, }, arr2[26] = { 0, };
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); ++i)
	{
		arr1[(int)str1[i] - 97]++;
	}
	for (int i = 0; i < str2.size(); ++i)
	{
		arr2[(int)str2[i] - 97]++;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (arr1[i] != arr2[i])
		{
			if (arr1[i] > arr2[i])
				answer += (arr1[i] - arr2[i]);
			else
				answer += (arr2[i] - arr1[i]);
		}
	}
	cout << answer;
}