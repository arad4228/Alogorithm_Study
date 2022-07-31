#include <iostream>

using namespace std;

bool checker(int n)
{
    if (n < 100)
        return true;
    else{
        int a[3];
        a[0] = n % 10;
        a[1] = (n % 100) / 10;
        a[2] = n / 100;
        // 첫번째 자리와 두번째 자리의 차와 두번째와 세번째 자리의 차를 비교
        if ((a[2] - a[1]) == (a[1] - a[0]))
            return true;
        else
            return false;
    }
}

int main(void)
{
    int N;
    cin >> N;
    int count = 0;
    for(int i=1; i <= N; i++)
        if(checker(i))
            count++;

    cout << count << endl;
    return 0;
}
