#include <iostream>

using namespace std;

int main(void)
{
    // 입력을 받을 두 분수를 위한 공간.
    int A[2], B[2];
    // 값을 입력 받기
    for(int i =0;i<2;i++)
        cin >> A[i] >> B[i];
    
    // 두 분모사이에 GCD를 구하기 위한 공간 설정
    int x = B[0];
    int y = B[1];
    // GCD 구하기
    while(y)
    {
        int result = x%y;
        x = y;
        y = result;
    }
    // GCD를 통한 최소 공배수 구해 두 분수의 합을 정의
    int Bo = (B[0]* B[1]) / x;
    int Ao = A[0] *(Bo / B[0]) + A[1] *(Bo / B[1]);
    // 기약 분수를 구하기 위해 분모, 분자 사이의 GCD구하기
    x = Bo;
    y = Ao;
    while(y)
    {
        int result = x%y;
        x = y;
        y = result;
    }
    // 결과 출력
    cout << Ao/x << " " << Bo/x << endl; 
    return 0;
}