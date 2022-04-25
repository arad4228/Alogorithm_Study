#include <iostream>

using namespace std;

char math[1001] = {0,};

int main(void)
{
    // 정수 N과 출력 번수 K를 입력 받는다.
    int N, K;
    cin >> N >> K;
    int count = 0;

    // i = 2부터 시작한다.
    for(int i = 2; i<= N;i++)
        for(int j =i; j<= N; j+=i)
        {
            if (!math[j])
            {
                math[j] = 1;
                count++;
            }
            if(count == K)
            {
                cout << j << endl;
                return 0;
            }
        }
    
    return 0;
}