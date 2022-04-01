#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    // 총 미팅룸의 숫자 
    int total_meeting_room;
    // 구성할 수 있는 회의는 최소 1개부터 시작한다.
    int result = 1;
    // 값 저장과 비교를 위한 공간.
    int from, to;

    cin >> total_meeting_room;
    // <int, int>쌍으로 시작시간과 끝나는 시간을 저장할 벡터 변수
    vector < pair<int,int> > meeting_room;

    // 값을 제공
    for (int i = 0; i < total_meeting_room; i++)
    {
        cin >> from >> to;
        meeting_room.push_back(pair<int,int> (from,to));
    }

    // 역순으로 정렬.
    sort(meeting_room.rbegin(),meeting_room.rend());

    // 시작값은 첫번째 원소로 저장.
    from = meeting_room[0].first;
    for (int j =1; j < total_meeting_room;j++)
    {
        // 마무리 값은 다음 원소의 마무리값으로 저장
        to = meeting_room[j].second;
        /*
            해당 값을 비교하고 결과가 만족하면 값을 증가
            이후 비교하는 시작값을 변경
        */
        if(to <= from)
        {
            result++;
            from = meeting_room[j].first;
        }
    }
    
    cout << result << endl;
    return 0;
}
