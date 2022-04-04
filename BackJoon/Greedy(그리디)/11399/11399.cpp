#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    // 몇명인지 정보를 받을 변수
    int N;
    // 총 대기시간에 대한 결과를 저장할 변수
    int result=0;
    // 몇명의 정보를 입력을 받는다.
    cin >> N;
    // 각 ATM의 인출에 걸리는 정보를 저장하기 위한 벡터
    vector <int> times;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        times.push_back(num);
    }
    // 벡터들을 오름차순으로 정렬한다.
    sort(times.begin(),times.end());

    /*
        총 걸리는 시간은 i번째 원소 * (N-i)를 모두 더한 결과
        ex) 1 2 3 3 4 -> 1*5 + 2*4 + 3*3 + 3*2 + 4*1
    */
    for (int i  = 0; i< N;i++)
    {
        result += times.at(i)*(N-i);
    }
    cout << result << endl;
    return 0;
}