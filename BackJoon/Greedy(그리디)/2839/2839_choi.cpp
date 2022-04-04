#include <iostream>

using namespace std;

/* 
    Semin Choi 정답
    https://github.com/guitarcode/Baekjoon-Algorithm/blob/main/src/%EC%84%A4%ED%83%95%EB%B0%B0%EB%8B%AC/BOJ2839.java
*/
int main(void)
{
    // N kg
    int N;
    // N에 대한 정보를 받는다.
    cin >> N;
    
    int count = 5000;
    /* 
        i는 5Kg의 갯수.
        반복문에서 적어도 1번은 동작하게 하여 5보다 작은 3Kg에서 대응하게 한다.
    */
    for (int i = 0, loop = N/5; i <= loop; i++)
    {
        if(N % 3 == 0)
            count = count > i+ N/3 ? i+ N/3 : count;
        N-=5;
    }
    if(count == 5000)
        cout << "-1" << endl;
    else
        cout << count << endl;
    return 0;
}