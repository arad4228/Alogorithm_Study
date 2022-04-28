#include <iostream>

using namespace std;

int main(void)
{
    // Case의 수를 세기위한 변수
    int i = 1;
    while(1)
    {
        // P일동안 L일 사용가능, V는 휴가일
        int L, P, V;
        cin >> L >> P >> V;
        // 탈출 조건
        if(L == 0 & P == 0 & V == 0)
            break;
        // 즐길 수 있는 일은 휴가일에 연속된 P일이 몇번 있는지 계산
        int result = (V/P) * L;
        // 이후 남은 일 수가 L보다 작으면 나머지 값을 더하고 
        if(V%P < L)
            result += (V%P);
        // 그것이 아니라면 L일을 더한다.
        else
            result += L;
        cout << "Case " << i << ": " << result << endl;
        i++;
    }
    return 0;
}