#include <iostream>

using namespace std;

// self num을 확인하기 위한 배열
// 초기화는 false인 0로 초기화.
bool selfnum[10001] = {0,};

// 입력 받은 정수에 대해 selfnum을 계산하는 함수
void self(int num)
{
     while(num < 10000)
    {
        num = num + (num/1000) + ((num/100)%10) + ((num/10)%10) +(num%10);
        selfnum[num] = 1;
    }
}

int main(void)
{
    // 1부터 10000까지 self num을 계산함 그러나 만약 이미 판정이 나있다면 넘어간다.
    for (int i = 1; i <= 10001; i++)
    {
        if(selfnum[i] == 0)
            self(i);
    }
   
    // 1~10000까지 판정식을 통해 아닌 숫자를 판별.
    for (int j = 1; j < 10000; j++)
        if (selfnum[j] == 0)
            cout << j << endl;
    return 0;
}