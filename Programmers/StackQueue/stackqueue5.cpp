#include <iostream>
#include <stack>

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int time = 0;
    int w = 0;
    queue<pair<int, int>>Q; //무게, 다리에 들어온 시간

    for (int i = 0; i < truck_weights.size(); ++i)
    {
        time++;
        //bridge_length가 다리 위에서 걸리는 시간
        if (time == Q.front().second + bridge_length) //다리 끝까지 갔을 때
        {
            w -= Q.front().first;
            Q.pop();
        }

        //다리 들어갈 수 없을 때
        while (w + truck_weights[i] > weight)
        {
            time = Q.front().second + bridge_length; //시간 업데이트
            w -= Q.front().first; //무게 업데이트
            Q.pop();
        }
        
        //들어올 수 있을 때
        w += truck_weights[i];
        Q.push({ truck_weights[i], time });
    }
    answer = Q.back().second + bridge_length;

    return answer;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << " " << q.back() << "\n";
    q.pop();
    cout << q.front() << " " << q.back() << "\n";
    
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
}