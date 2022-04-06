#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    // 숫자 문자열을 받을 string 변수
    string input = "";
    // 30의 배수인지 확인할 변수
    int thirtyN = 0;
    cin >> input;

    // 입력 받은 값에서 모든 값을 더함
    for (int i =0; i< input.length(); i++)
    {
        thirtyN += input[i] - '0';
    }
    
    // 문자열을 역순 정렬
    sort(input.rbegin(),input.rend());
    
    // 만약 마지막 값이 0이 거나 모든 총합이 3으로 나눠진다면 30의 배수.
    if (input[input.length()-1] == '0' & thirtyN %3 == 0)
        cout << input << endl;   
    // 그것이 아니라면 30의 배수가 아니다.
    else
        cout << "-1" << endl;  
    return 0;
}