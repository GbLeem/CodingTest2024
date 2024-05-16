#include <vector>
#include <iostream>
#include <string>
using namespace std;

//ACGT -> 65 67 71 84

//O(N*M)
//vector<int> solution(string& S, vector<int>& P, vector<int>& Q)
//{
//    vector<int> ans;
//    
//    for (int i = 0; i < P.size(); ++i)
//    {
//        int start = P[i];
//        int end = Q[i];
//           
//        int minVal = (int)'T';
//
//        if (start == end)
//            minVal = (int)S[start];
//        else
//        {
//            for (int j = start; j <= end; ++j)
//            {
//                if (minVal > (int)S[j])
//                {
//                    minVal = (int)S[j];
//                }
//            }
//        }
//        
//        switch (minVal)
//        {
//        case 65:
//            minVal = 1;
//            break;
//        case 67:
//            minVal = 2;
//            break;
//        case 71:
//            minVal = 3;
//            break;
//        case 84:
//            minVal = 4;
//            break;
//        }
//        ans.push_back(minVal);
//    }
//    return ans;
//}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) 
{
	const int A_VAL = 1;
	const int C_VAL = 2;
	const int G_VAL = 3;
	const int T_VAL = 4;

	// Have to track these values separately, this costs us space complexity
	// but saves us time complexity.  Can't do this simply with prefix_sums with
	// single  vector of fundamental type (or at least I am not clever enough to see it)
	int N = S.size();
	vector<int> A(N, -1);
	vector<int> C(N, -1);
	vector<int> G(N, -1);
	vector<int> T(N, -1);

	int aLastIndex = -1;
	int cLastIndex = -1;
	int gLastIndex = -1;
	int tLastIndex = -1;

	// Complexity of this operation is O(N)
	for (int n = 0; n < N; n++) {
		switch (S[n]) {
		case 'A':
			aLastIndex = n;
			break;
		case 'C':
			cLastIndex = n;
			break;
		case 'G':
			gLastIndex = n;
			break;
		case 'T':
			tLastIndex = n;
			break;
		default:
			break;
		}
		A[n] = aLastIndex;
		C[n] = cLastIndex;
		G[n] = gLastIndex;
		T[n] = tLastIndex;
	}

	int M = P.size();
	vector<int> result(M, 0);

	// Complexity of this operation is O(M+1) ==> O(M)
	for (int m = 0; m < M; m++) {
		int l = P[m];
		int r = Q[m];

		// Check if the last seen index is greater or less than the left value
		// If it is then that is the nucleotide for this space.  Done in order
		// of lowest to highest impact factor.
		// LOGIC:  
		//   1. A[r] cannot be greater than the n at that location.
		//      See assignment above, so no need to check it separately
		//   2. A[r] will be equal to l if A was last seen at index l
		//   3. A[r] will be less than l if A was last seen before index l
		//   4. A[r] will be greater than l if A was seen after l up to and including r
		if (A[r] >= l) {
			result[m] = A_VAL;
		}
		else if (C[r] >= l) {
			result[m] = C_VAL;
		}
		else if (G[r] >= l) {
			result[m] = G_VAL;
		}
		else if (T[r] >= l) {
			result[m] = T_VAL;
		}
	}

	return result;
}

int main()
{
    /*vector<int> P = { 2,5,0 };
    vector<int> Q = { 4,5,6 };
    string S = "CAGCCTA";*/
    vector<int> P = { 0, 0, 1 };
    vector<int> Q = { 0, 1, 1 };
    string S = "TC";
    vector<int> ans = solution(S, P, Q);

    for (auto a : ans)
    {
        cout << a << " ";
    }
}