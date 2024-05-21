//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <set>
//#include <cmath>
//using namespace std;
//
//int solution(vector<int>& A, int X)
//{
//	map<int, int> m;
//	set<int> s;
//	vector<int> temp;
//	int ans = 0;
//
//	if (A.size() < 4)
//		return 0;
//	for (int i = 0; i < A.size(); ++i)
//	{		
//		//길이랑 갯수 넣은 map
//		if (count(A.begin(), A.end(), A[i]) < 2)
//			continue;
//		else
//			m.insert({ A[i], count(A.begin(), A.end(), A[i]) });
//	}
//	//(2 4) (6 2)
//	for (auto mi : m)	
//		s.insert(mi.first);		
//	for (auto si : s)
//		temp.push_back(si); //2 6
//
//	sort(temp.begin(), temp.end());
//
//	//길이 하나 선택하면 그걸로 X보다 큰 목장 만들수 있을 때 울타리 갯수 빼기
//	vector<int> Sum;
//	for (int i = 0; i < temp.size(); ++i) // 2 6
//	{		
//		int length = ceil((double)X / temp[i]); // 2보다 큰 것
//		map<int, int> t(m);
//
//		t[temp[i]] -= 2;
//		if (lower_bound(temp.begin(), temp.end(), length) != temp.end())
//		{
//			//length 보다 같거나 큰 최초의 인덱스
//			int idx = lower_bound(temp.begin(), temp.end(), length) - temp.begin();
//			//cout << "index: " << idx << "\n";
//			while (1)
//			{
//				int tempSum = 0;
//				if (idx >= temp.size())
//					break;
//				else if (t[temp[idx]] >= 2)
//				{
//					t[temp[idx]] -= 2;
//					tempSum = temp[i] + temp[idx];
//					if (find(Sum.begin(), Sum.end(), tempSum) != Sum.end())
//						break;
//					Sum.push_back(tempSum);
//					ans++;
//				}
//				idx++;
//			}
//		}
//	}	
//	return ans;
//}
//
//int main()
//{
//	vector<int> a = { 1,2,5,1,1,2,3,5,1 }; //1 1 1 1 2 2 3 5 5
//	vector<int> a1 = { 2,2,6,6 };
//	vector<int> a2 = { 1,2,2,5,5,9 };
//	vector<int> a3 = { 6,6,6,6,6,6 };
//	
//	cout << solution(a, 5) << "\n";     //2
//	cout << solution(a1, 4) << "\n";    //1
//	cout << solution(a2, 4) << "\n";    //1
//	cout << solution(a3, 10) << "\n";   //1
//}

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int>& A, int X)
{
    if (A.size() < 2) { return 0; }

    // reduce double fences to single array
    std::unordered_map<int, int> fenceCnt;
    for (auto const& a : A)
    {
        if (fenceCnt.find(a) != fenceCnt.end()) { fenceCnt[a]++; }
        else { fenceCnt[a] = 1; }
    }
    vector<int> fence;
    for (auto const& it : fenceCnt)
    {
        for (int i = 0; i < it.second / 2; i++)
        {
            fence.push_back(it.first);
        }
    }
    std::sort(fence.begin(), fence.end());

    // count reuseble fence as suffix, e.g., square pen
    int sz = fence.size();
    int cntR = 0;
    vector<int> suffixCnt(sz, 0);
    int lastFence = fence[sz - 1];

    for (int i = sz - 2; i >= 0; i--)
    {
        if (fence[i] == lastFence) { cntR++; }
        suffixCnt[i] = cntR;
        lastFence = fence[i];
    }

    // use BS to find the suitable fence for each
    int ret = 0;
    for (auto it = fence.begin(); it != fence.end(); it++)
    {
        // skip same length fence
        if ((it != fence.begin()) && (*it == *std::prev(it)))
            continue;

        auto lower = std::lower_bound(std::next(it), fence.end(), (X + *it - 1) / *it);

        // can build area larger than X
        if (lower != fence.end())
        {
            int ind = std::distance(fence.begin(), lower);
            ret += sz - ind - suffixCnt[ind];
            if (ret > 1000000000)
            {
                ret = -1;
                break;
            }
        }
    }
    return ret;
}

int main()
{
    vector<int> a = { 1,2,5,1,1,2,3,5,1 }; //1 1 1 1 2 2 3 5 5
    vector<int> a1 = { 2,2,6,6 };
    vector<int> a2 = { 1,2,2,5,5,9 };
    vector<int> a3 = { 6,6,6,6,6,6 };

    cout << solution(a, 5) << "\n";     //2
    cout << solution(a1, 4) << "\n";    //1
    cout << solution(a2, 4) << "\n";    //1
    cout << solution(a3, 10) << "\n";   //1
}