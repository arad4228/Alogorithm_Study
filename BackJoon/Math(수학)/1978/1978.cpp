#include <iostream>

using namespace std;

int main(void)
{
    // 주어진 수에 대해 입력을 받을 변수
    int N;
    cin >> N;
    // 소수의 갯수를 출력할 변수
    int count = 0;
    // 입력을 받으면 동시에 소수를 확인히고 소수이면 count를 1증가.
    for (int i = 0; i < N;i++)
    {
        int num;
        bool check = false;
        cin >> num;
        if(num == 1)
            continue;

        for (int j = 2; j< num;j++)
        {
            if(num % j == 0)
            {
                check = true;
                break;
            }
                
        }
        if(check == false)
            count++;
    }
    cout << count << endl;
    return 0;
}