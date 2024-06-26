//A = {-1, 6, 3, 4, 7, 4};
//invA = {4, 7, 4, 3, 6, -1};
//(0,1) -> A[1] < A[0] -> 6 < -1
//(0,2) -> 3 < -1
//(0,3) -> 4 < -1
//(0,4) -> 7 < -1
//(0,5) -> 4 < -1

//(1,2) -> 3 < 6
//(1,3) -> 4 < 6
//(1,4) -> 7 < 6
//(1,5) -> 4 < 6

//(2,3) -> 4 < 3
//(2,4) -> 7 < 3
//(2,5) -> 4 < 3

//(3,4) -> 7 < 4
//(3,5) -> 4 < 4

//(4,5) -> 4 < 7

//=============================================
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;

//bool isused[100002];
//int arr[100002];
//int ans = 0;
//int cnt = 0;
//길이가 m 
//1~n까지 자연수


// <Back Tracking> O(N**2)
//void func(int k, vector<int>& A)
//{	
//	cnt++;
//	if (k == 2)
//	{
//		if (A[arr[1] - 1] < A[arr[0] - 1])
//		{
//			ans++;
//		}
//		return;
//	}
//	int st = 1;
//	if (k != 0)
//		st = arr[k - 1] + 1;
//
//	for (int i = st; i <= A.size(); ++i)
//	{
//		if (!isused[i])
//		{
//			arr[k] = i;
//			isused[i] = 1;
//			func(k + 1, A);
//			isused[i] = 0;
//		}
//	}
//}
//int solution(vector<int>& A)
//{
//	func(0, A);	
//	if (cnt > 1'000'000'00)
//		return -1;
//	return ans;
//}



//int arr[100002];
//int isused[100002];
//vector<bool> temp;
//
//int solution(vector<int>& A)
//{
//    const int r = 2; //m
//    int cnt = 0;
//    int ans = 0;
//
//    for (int i = 0; i < A.size(); i++) // 뒤에 false가 n-r개 채워지고 뒤에 true 가 r개 채워진다.
//        temp.push_back(i < r ? 0 : 1);
//
//    do 
//    {
//        if (cnt > 1'000'000'000)
//            return ans;
//        cnt++;
//        vector<int>v;
//        for (int i = 0; i < A.size(); ++i) 
//        {            
//            if (temp[i] == 0)
//            {             
//                v.push_back(i);
//            }
//            if (v.size() == 2)
//            {
//                //cout << v[1] << " " << v[0] << "\n";
//                if (A[v[1]] < A[v[0]])
//                    ans++;
//                v.clear();
//            }            
//        }        
//    } while (next_permutation(temp.begin(), temp.end()));   
//    
//    return ans;
//}

//int main()
//{
//	vector<int> A = { -1, 6, 3, 4, 7, 4 };
//	cout << solution(A);    
//}

#include<vector>
using namespace std;

int temp[1000001];
int merge(vector<int>& A, int st, int en)
{
    int mid = (st + en) / 2;
    int inv_count = 0; //정렬 안된 쌍 발견했을때 1 증가

    //arr[st:mid] 와 arr[mid:en]은 정렬되어있을때 arr[st:en]정렬하기

    int idx1 = st; //st : mid 값
    int idx2 = mid; // mid : en 값

    for (int i = st; i < en; ++i)
    {
        if (idx1 == mid)
            temp[i] = A[idx2++];
        else if (idx2 == en)
            temp[i] = A[idx1++];
        else if (A[idx1] <= A[idx2])
            temp[i] = A[idx1++];
        else
        {
            temp[i] = A[idx2++];
            inv_count = inv_count + (mid - idx1);
        }
    }
    for (int i = st; i < en; ++i)
        A[i] = temp[i];

    return inv_count;
}

int merge_sort(vector<int>& A, int st, int en)
{
    int ans = 0;
    if (A.empty())
        return 0;
    if (st + 1 == en)
        return 0;
    int mid = (st + en) / 2;
    ans += merge_sort(A, st, mid);
    ans += merge_sort(A, mid, en);
    ans += merge(A, st, en);

    return ans;
}

int solution(vector<int>& A)
{
    int answer = merge_sort(A, 0, A.size());
    if (answer > 1'000'000'000)
        return -1;
    return answer;
}

int main()
{
    vector<int> A = { };
    vector<int> A1 = { 1, 20, 6, 4, 5 };
    vector<int> A2 = { -1,6,3,4,7,4 };
    cout << solution(A) << "\n"; //0
    cout << solution(A1) << '\n'; //5
    cout << solution(A2) << '\n'; //4
}