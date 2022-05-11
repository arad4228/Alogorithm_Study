#include <iostream>

using namespace std;

long long dp[201][201];

int main(void)
{
    // N과 K를 입력 받을 변수
    int N, K;
    cin >> N >> K;
    
    // 첫번째는 무조껀 1개를 뽑는다.
    for(int i = 0; i < 1; i++)
        for(int j =0; j <= 200; j++)
            dp[i][j] = 1;

    // 수들의 연관 규칙에 따라 값을 계산한다.
    for(int i = 1; i <=N; i++)
        for(int j = 1; j <= K; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }

    // 결과를 출력한다.
    cout << dp[N][K]<< endl;
    return 0;
}