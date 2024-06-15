//#include<iostream>
//
////[1차] 캐시
//#include <string>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int solution(int cacheSize, vector<string> cities)
//{
//    int answer = 0;
//    vector<string> cache;
//    queue<string> qcache;
//
//    if (cacheSize == 0)
//        return cities.size() * 5;
//
//    //대문자 처리
//    for (int i = 0; i < cities.size(); ++i)
//    {
//        for (auto &c : cities[i])
//        {
//            if(islower(c)) //소문자면 대문자로 바꾸기
//                c -= 32;
//        }
//    }
//
//    for (int i = 0; i < cities.size(); ++i)
//    {
//        if (find(cache.begin(), cache.end(), cities[i]) != cache.end()) //찾음
//        {
//            answer += 1;
//            if (cache.size() < cacheSize) //비었을때 -> 순서 바꿔주기
//            {
//                cache.erase(remove(cache.begin(), cache.end(), cities[i]));
//                cache.push_back(cities[i]);
//
//                while (!qcache.empty())
//                    qcache.pop();
//
//                for (int j = 0; j < cache.size(); ++j)
//                    qcache.push(cache[j]);
//            }
//            else if (cache.size() == cacheSize) //다 찼을때
//            {
//                qcache.pop();
//                qcache.push(cities[i]);
//                cache.clear();
//
//                queue<string> tq = qcache;
//                while (!tq.empty())
//                {
//                    cache.push_back(tq.front());
//                    tq.pop();
//                }
//            }
//        }
//        else if (find(cache.begin(), cache.end(), cities[i]) == cache.end()) //못찾음
//        {
//            answer += 5;
//            if (cache.size() < cacheSize)
//            {
//                qcache.push(cities[i]);
//                cache.push_back(cities[i]);
//            }
//            else if (cache.size() == cacheSize)
//            {
//                qcache.pop();
//                qcache.push(cities[i]);
//                cache.clear();
//
//                queue<string> tq = qcache;
//                while (!tq.empty())
//                {
//                    cache.push_back(tq.front());
//                    tq.pop();
//                }
//            }
//        }
//    }
//    return answer;
//}
//
//int main()
//{
//    vector<string> v1 = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
//    vector<string> v2 = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
//    vector<string> v3 = { "Jeju", "Pangyo", "NewYork", "newyork" };
//    vector<string> v4 = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
//    vector<string> v5 = { "a","b","c","b","a" };
//    vector<string> v6 = { "A", "B", "C", "A", "D", "G", "A" };
//    vector<string> v7 = { "seoul", "seoul", "seoul", "tokyo", "seoul", "tokyo" };
//    vector<string> v8 = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Seoul", "Pangyo", "Seoul", "NewYork", "Seoul" };
//    vector<string> v9 = { "a", "b", "c", "a" };
//    vector<string> v10 = { "a", "a", "a", "b", "b", "b", "c", "c", "c" };
//    vector<string> v11 = { "A","B","A" };
//    cout << solution(3, v1) << "\n";
//    cout << solution(3, v2) << "\n";
//    cout << solution(2, v3) << "\n";
//    cout << solution(0, v4) << "\n";
//    cout << solution(5, v5) << '\n';
//    cout << solution(3, v6) << "\n";
//    cout << solution(3, v7) << "\n";
//    cout << solution(3, v8) << "\n";
//    cout << solution(5, v9) << "\n";
//    cout<< solution(2, v10) << "\n";
//    cout << solution(3, v11) << "\n"; //11
//}