#include <iostream>

using namespace std;

int main(void)
{
    // x, y의 값을 입력 받는다.
    int x,y;
    cin >> x >> y;
    // 나머지 결과를 저장할 임시 변수
    int result;
    // x,y의 원본 값을 저장할 임시 변수
    int tx, ty;
    tx = x;
    ty = y;
    // GCD구하기(유클리드 호제법)
    while(y)
    {
        result = x%y;
        x = y;
        y = result;
    }
    cout << x << endl;
    // 최소 공배수 구하기
    cout << tx * ty /x << endl;
    return 0;
}