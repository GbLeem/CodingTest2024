#include <iostream>
using namespace std;

//int getInvCount(int arr[], int n)
//{
//    int inv_count = 0;
//    for (int i = 0; i < n - 1; i++)
//        for (int j = i + 1; j < n; j++)
//            if (arr[i] > arr[j])
//                inv_count++;
//
//    return inv_count;
//}
//// Driver Code
//int main()
//{
//    int arr[] = { 1, 20, 6, 4, 5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    cout << " Number of inversions are "
//        << getInvCount(arr, n);
//    return 0;
//}

//int _mergeSort(int arr[], int temp[], int left, int right);
//int merge(int arr[], int temp[], int left, int mid,
//    int right);
//
//// This function sorts the
//// input array and returns the
//// number of inversions in the array
//int mergeSort(int arr[], int array_size)
//{
//    //int temp[array_size];
//    int* temp = new int[array_size];
//    return _mergeSort(arr, temp, 0, array_size - 1);
//}
//
//// An auxiliary recursive function
//// that sorts the input array and
//// returns the number of inversions in the array.
//int _mergeSort(int arr[], int temp[], int left, int right)
//{
//    int mid, inv_count = 0;
//    if (right > left) {
//        // Divide the array into two parts and
//        // call _mergeSortAndCountInv()
//        // for each of the parts
//        mid = (right + left) / 2;
//
//        // Inversion count will be sum of
//        // inversions in left-part, right-part
//        // and number of inversions in merging
//        inv_count += _mergeSort(arr, temp, left, mid);
//        inv_count += _mergeSort(arr, temp, mid + 1, right);
//
//        // Merge the two parts
//        inv_count += merge(arr, temp, left, mid + 1, right);
//    }
//    return inv_count;
//}
//
//// This function merges two sorted arrays
//// and returns inversion count in the arrays.
//int merge(int arr[], int temp[], int left, int mid,
//    int right)
//{
//    int i, j, k;
//    int inv_count = 0;
//
//    i = left;
//    j = mid;
//    k = left;
//    while ((i <= mid - 1) && (j <= right)) 
//    {
//        if (arr[i] <= arr[j]) 
//        {
//            temp[k++] = arr[i++];
//        }
//        else 
//        {
//            temp[k++] = arr[j++];
//
//            // this is tricky -- see above
//            // explanation/diagram for merge()
//            inv_count = inv_count + (mid - i);
//        }
//    }
//
//    // Copy the remaining elements of left subarray
//    // (if there are any) to temp
//    while (i <= mid - 1)
//        temp[k++] = arr[i++];
//
//    // Copy the remaining elements of right subarray
//    // (if there are any) to temp
//    while (j <= right)
//        temp[k++] = arr[j++];
//
//    // Copy back the merged elements to original array
//    for (i = left; i <= right; i++)
//        arr[i] = temp[i];
//
//    return inv_count;
//}
//int main()
//{
//    int arr[] = { -1, 6, 3, 4, 7, 4 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int ans = mergeSort(arr, n);
//    cout << " Number of inversions are " << ans;
//    return 0;
//}
//==============================================
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
    cout << solution(A)<<"\n"; //0
    cout << solution(A1)<<'\n'; //5
    cout << solution(A2) << '\n'; //4
}
