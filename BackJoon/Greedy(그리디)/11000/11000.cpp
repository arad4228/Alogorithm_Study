#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    // 수업 시간을 담을 벡터
    vector< pair<int, int> >class_time;
    // 수업시간을 비교하기 위한 우선순위 큐
    priority_queue<int, vector<int>, greater<int> > pq_less;

    // 수업 시간을 전부 입력
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        class_time.push_back(make_pair(start, end));
    }
    // 수업시간을 오름차순으로 정렬
    sort(class_time.begin(), class_time.end());
    
    // 최대 구성할 수 있는 수업 시간에 첫번째 수업의 끝나는 시간을 입력
    pq_less.push(class_time[0].second);

    // 나머지 수업에 대해서
    for (int i =1; i < N; i++)
    {
        // 나머지 수업의 끝나는 시간을 넣고
        pq_less.push(class_time[i].second);
        // 만약 top의 시간이 지금 수업시간의 시작시간보다 작다면 pop
        if(pq_less.top() <= class_time[i].first)
        {
            pq_less.pop();
        }
    }
    cout << pq_less.size() << "\n";

    return 0;
}