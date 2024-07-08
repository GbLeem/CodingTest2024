////n^2 배열 자르기
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//vector<vector<int>> board;
//
//vector<int> solution(int n, long long left, long long right)
//{
//    vector<int> answer;    
//    board.resize(n);
//    
//    for (int i = 0; i < n; ++i)
//    {                       
//        board[i].assign(n, -1);
//    }
//
//    for (int i = 0; i < n; ++i)
//    {        
//        for (int j = 0; j <= i; ++j)
//        {
//            if (board[i][j] == -1)
//            {
//                board[i][j] = j + 1;
//            }
//        }
//    }
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            cout << board[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    return answer;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    solution(3, 2, 5);
//}