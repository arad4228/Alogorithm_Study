#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool prime[1299710];

int main(void)
{
    int T;
    // 시작은 모두 소수로 초기화
    fill_n(prime,1299711, true);
    // prime을 담아둘 벡터
    vector<int> prime_list;
    // 소수 찾기
    for(int i =2; i <= sqrt(1299710); i++)
        for(int j= i+i; j <= 1299710; j+=i)
            prime[j] = false;
    // 소수를 벡터에 삽입
    for(int i = 2; i < 1299710; i++)
        if(prime[i])
            prime_list.push_back(i);
            
    // 테스트 케이스 입력
    cin >> T;
    for(int i =0; i < T; i++)
    {
        // 테스트 케이스에 대한 결과 출력
        int K;
        cin >> K;
        if(prime[K] == true)
        {
            cout << "0" << endl;
            continue;
        }
           
        int start, last;
        for(int j = 0; j < prime_list.size(); j++)
        {
            if(prime_list[j] > K)
            {
                start = prime_list[j-1];
                last = prime_list[j];
                break;
            }
        }
        cout << last - start << endl;
    }

    return 0;
}