#include <iostream>
#include <vector>

using namespace std;

long long pow(int A, int B,int C)
{
    if (B == 0)
        return 1;
    long long temp = pow(A,B/2,C);
    temp = temp * temp % C;
    if (B%2 == 0)
        return temp;
    else
        return temp * A %C;
}

int main(void)
{
    int A,B,C;
    int count = 0;
    cin >> A >> B >> C;
    cout << pow(A,B,C) << endl;
    return 0;
}