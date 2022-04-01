#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    // 동전의 갯수와 금액을 입력 받을 변수
    int N, K;
    // 총 제공할 동전의 갯수
    int count = 0;
    // 동전들의 모음을 저장할 벡터
    vector <int> coin;
    // 동전의 갯수와 금액을 입력받는다.
    cin >> N >> K;

    for (int i =0;i < N; i++)
    {
        int temp;
        cin >> temp;
        coin.push_back(temp);
    }
    // 동전의 가장 큰 금액부터 거슬러 가장 적은 동전의 총합을 게산
    for (int i = N-1; i >= 0; i--)
    {
        count += K / coin.at(i);
        K %= coin.at(i);
    }
    cout << count << endl;
    return 0;
}