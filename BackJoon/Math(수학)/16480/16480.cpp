#include <iostream>

using namespace std;

int main(void)
{
    // 외접원의 반지름
    long R;
    // 내접원의 반지름
    long r;
    cin >> R >> r;

    // 내접원과 외접원 거리의 공식은 D^2 = R^2 -2Rr(오일러 공식)
    cout << R*(R-2*r) << endl;
    return 0;
}