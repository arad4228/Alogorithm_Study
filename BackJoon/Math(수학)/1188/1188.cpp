#include <iostream>

using namespace std;

// 최대 공약수 구하기
int GCD(int a, int b)
{
    if(a%b == 0)
        return b;
    return GCD(b, a%b);
}

int main(void)
{
    // 소시지와 평론가의 수를 받을 변수
    int N,M;
    cin >> N >> M;
    /*
        소시지를 하나로 생각한다면 결과적으로는 
        M명의 평론가 수에서 GCD(N,M)만큼 뺀 번 칼질을 해야한다.
    */
    cout << M - GCD(N,M) << endl;
    return 0;
}