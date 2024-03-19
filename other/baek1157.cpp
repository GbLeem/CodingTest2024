#include <iostream>
#include <string>

using namespace std;

int arr[26];
string word;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> word;
	
	for (size_t i = 0; i < word.size(); ++i)
	{
		if ((int)word[i] > 90)
		{
			word[i] = word[i] - 32;
		}

		arr[word[i] - 65]++;
	}
	
	int maxN = 0;
	char maxC = '?';

	for (int i = 0; i < 26; ++i)
	{
		if (maxN < arr[i])
		{
			maxN = arr[i];
			maxC = (char)(i + 97 - 32);
		}
	}	
	int cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (maxN == arr[i])
		{
			cnt++;			
		}
	}
	if (cnt >= 2)
	{
		cout << '?';
		return 0;
	}
	cout << maxC;
	return 0;
}