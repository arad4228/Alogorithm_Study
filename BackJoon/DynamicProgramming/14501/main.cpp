#include <iostream>
#include <algorithm>

int main(void)
{
    // 퇴사하는 날짜
    int n;
    std::cin >> n;

    // 시간과 금액에 대한 정보를 저장할 데이터 공간
    int* time = new int[n];
    int* profit = new int[n];
    // 최대 이익을 저장하기 위한 공간
    long* dp = new long[n+1];

    for(int i = 0; i < n; i++)
    {
        // 시간 데이터와 금액 데이터
        std::cin >> time[i] >> profit[i];
        dp[i] = 0;
    }

    // i = time으로 간주
    for(int i = 0; i < n; i++)
    {
        // 일을 수행하지 않은 경우
        dp[i + 1] = std::max(dp[i + 1], dp[i]);

        // 일을 수행한 경우(최대 N+1일까지 수행 가능함)
        if(i+time[i] <= n)
            dp[i + time[i]] = std::max(dp[i + time[i]], dp[i] + profit[i]);
    }

    std::cout << dp[n] << std::endl; // 퇴사일 기준 최대 이익 출력

    // 사용한 시간과 금액은 삭제.
    delete[] time;
    delete[] profit;
    delete[] dp;
    return 0;
}