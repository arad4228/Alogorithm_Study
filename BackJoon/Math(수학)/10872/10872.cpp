#include <iostream>

using namespace std;

int main(void)
{
    // 입력을 받을 공간.
    int num;
    // 결과를 저장하기 위한 공간.
    int result =1;
    // 입력을 받음.
    cin >> num;

    // 팩토리얼 계산에서 n 1이하면 1을 출력.
    if(num <= 1)
    {
        cout << "1" << endl;
        return 0;
    }
    // 그렇지 않으면 정상적으로 팩토리 계산
    else
    {
        for(int i = 2; i <= num;i++)
            result = result * i;
    }
    // 결과 출력
    cout << result << endl;
    return 0;
}