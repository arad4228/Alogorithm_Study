#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // 몇번의 테스트를 실행할지 저장하는 변수
    int T;
    cin >> T;

    // T번동안 반복
    for (int i = 0; i< T; i++)
    {
        // 몇번의 반복을 진행할지 저장할 변수
        int N;
        // 첫번째는 무조껀 당선 -> 정렬을 하므로 서류 1등 
        int count = 1;
        // 서류, 면접 등수를 저장할 변수들
        int first, second;
        
        // 서류와 면접 등수를 저장할 벡터 변수
        vector < pair<int, int> > ordering;
        cin >> N;

        // N번 반복해 입력을 받는다.
        for (int j = 0; j < N; j++)
        {
            cin >> first >> second;
            ordering.push_back(pair<int, int>(first,second));
        }

        // 벡터의 첫번째 변수를 기점으로 오름차순으로 정렬
        sort(ordering.begin(),ordering.end());

        // 비교를 위해 첫번째 사람의 면접 등수를 저장
        int temp = ordering[0].second;
        for (int j = 1; j < N;j++)
        {
            // 만약 첫번째 면접 등수보다 높다면 값을 증가하고 값을 변경.
            if(ordering[j].second < temp)
            {
                count++;
                temp = ordering[j].second;
                if(temp == 1)
                    break;
            }
        }
        cout << count << endl;
    }
    return 0;
}