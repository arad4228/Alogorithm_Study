#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N;i++)
    {
        int num;
        bool check = false;
        cin >> num;
        if(num == 1)
            continue;

        for (int j = 2; j< num;j++)
        {
            if(num % j == 0)
            {
                check = true;
                break;
            }
                
        }
        if(check == false)
            count++;
    }
    cout << count << endl;
    return 0;
}