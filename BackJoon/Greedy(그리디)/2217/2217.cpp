#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // 갯수를 입력 받을 변수
    int N;
    // 결과를 도출할 변수
    int result = 0;
    // 로프의 리스트를 가질 벡터 변수
    vector <int> rope_list;

    cin >> N;
    for(int i = 0; i < N;i++)
    {
        int rope;
        cin >> rope;
        rope_list.push_back(rope);
    }
    
    // 로프길이를 오름차순으로 정리
    sort(rope_list.begin(),rope_list.end());

    // Max(rope_list[i]*N-i) -> Max(10*2, 15*1) 
    for (int i = 0; i< N;i++)
    {
        int max_num = rope_list[i]*(N-i);
        if(result < max_num)
            result = max_num;
    }
    cout << result << endl;
    return 0;
}