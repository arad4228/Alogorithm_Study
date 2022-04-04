#include <iostream>
#include <string>
using namespace std;
 
int main(void) 
{
    // 수식을 입력 받을 변수
    string formula;
    cin >> formula;
    
    // 결과 값을 출력할 변수
    int result = 0;
    // 숫자를 저장하기 위한 변수
    string num;
    // '-'인지 판단하기 위한 변수
    bool isMinus = false;
 
    for (int i = 0; i <= formula.size(); i++) 
    {
        // 만약 '-', '+'연산자 또는 식의 끝이라면
        if (formula[i] == '-' || formula[i] == '+' || i==formula.size()) {
            // 만약 검사하는 변수 값이 참이라면
            if (isMinus) 
            {
                // 결과에 string to int를 사용해 값을 변경하고 값을 뺀다.
                result -= stoi(num);
                // 숫자를 위한 공간을 비워준다.
                num = "";
            }
            // 그렇지 않으면
            else 
            {
                // 동일한 작업을 진행하되 값은 더한다.
                result += stoi(num);
                num = "";
            }
        }
        // 연산자 또는 식의 마지막이 아니라면
        else 
        {
            // 숫자를 저장하는 공간에 i번째 값을 저장.
            num += formula[i];
        }

        // 만약 '-'자 라면 minus를 확인하기 위한 변수를 true로 변경한다.
        if (formula[i] == '-') 
        {
            isMinus = true;
        }    
    }
    
    cout << result << endl;
    return 0;
}
