#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    int result=0;
    cin >> N;
    vector <int> times;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        times.push_back(num);
    }
    sort(times.begin(),times.end());

    for (int i  = 0; i< N;i++)
    {
        result += times.at(i)*(N-i);
    }
    cout << result << endl;
    return 0;
}