#include <iostream>
#include <cmath>

using namespace std;

bool prime[(123456*2+1)];

int main(void)
{
    // bool 조건을 true로 초기화
    fill_n(prime, 2 * 123456 + 1, 1);
	// 소수가 아닌 것을 걸러주는  로직
	for (int i = 2; i <= sqrt(123456*2); i++)
    {
        if(prime[i] == 1)
            for(int j = i*2; j <= (2*123456); j+=i)
                prime[j] = 0;
    }

    while(1)
    {
        // 소수의 갯수를 출력하길 원하는 값에 대한 변수
        int N;
        cin >> N;
        // 소수의 갯수를 출력하기 위한 변수
        int cnt = 0;
        if(N == 0)
            break;
        
        // 소수의 갯수를 확인
        for(int k = N+1; k <= 2*N; k++)
        {
            if(prime[k]==1)
                cnt++;
        }  
        cout << cnt << endl;
    }
    return 0;
}