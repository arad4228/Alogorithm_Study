#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    // 정수를 입력 받을 변수
    int N;
    
    // 입력이 들어오는 동안 반복
    while(cin >> N)
    {
        // 1로만 이뤄진 값에서 N의 배수가 되는 첫번째를 찾기 위해 사용하는 변수
        int div = 1;
        // 총 합에 대한 변수
        int cnt = 1;
        // 찾을 때까지 반복
        while(1)
        {
            if (div % N == 0)
                break;
            // (A+B)%C = (A%C + B%C)를 사용
            div = ((div*10)+1) % N;
            cnt++;
        }   
        cout << cnt << endl; 
    } 
    return 0;
}