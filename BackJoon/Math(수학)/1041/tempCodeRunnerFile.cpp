#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    int Die[6];
    int maxDie= 0;
    long long result = 0;
    for (int i  =0; i < 6; i++)
    {
        cin >> Die[i];
        result += Die[i];
        maxDie = max(maxDie, Die[i]);

    }
    if(N == 1)
    {
        cout << result - maxDie << "\n";
        return 0;
    }
    else
    {
        result = 0;
        sort(&Die[0], &Die[5]);
        int min1 = Die[0];
        int min2 = Die[1];
        int min3 = Die[2];
        result += (min1 + min2 + min3)*4;
        result += (min1 + min2)* (4*((N-1)+(N-2)));
        result += min1 * (4*(N-1)*(N-2) + (N-2)*(N-2));
        cout << result << "\n";
    }
    return 0;
}