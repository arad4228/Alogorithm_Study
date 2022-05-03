#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // N, K를 입력 받을 변수
    int N, K;
    cin >> N >> K;
    // 입력받는 정수들을 저장할 벡터 변수
    vector<int> numlist;

    // 값을 입력
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numlist.push_back(temp);
    }
    // 내림차순으로 정렬
    sort(numlist.rbegin(),numlist.rend());

    int result = 0;
    // 결과는 가장 큰 값부터 선정하는 것.
    for (int i = 0; i < K; i++)
        result += numlist[i];
    // 가장 큰값을 설정하면 결국은 해당 값 앞에 k=2 1,0으로 빠짐.
    // 이를 이용해서 값을 계산
    cout << result - (K *(K-1)/2) << endl;
    return 0;
}