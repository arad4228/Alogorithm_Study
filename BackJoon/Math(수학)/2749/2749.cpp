#include <iostream>

using namespace std;
 
int fibo[1500000];
 
int main(void) 
{
    long long int n;
    cin >> n;
    // 피보나치 수열의 기본
    fibo[0] = 0;
    fibo[1] = 1;
    
    // 피사노 주기를 사용해 해결
    for (int i = 2; i < 1500000; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000;
 
    cout << fibo[n % 1500000] << endl;
    return 0;
}
