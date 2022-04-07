#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    string input = "";
    int thirtyN = 0;
    cin >> input;
    sort(input.rbegin(),input.rend());
    for(int i = 0; i< input.length();i++)
        thirtyN += input[i] - '0';
    if(input[input.size()-1] == '0' & thirtyN % 3 == 0)
        cout << input << endl;
    else
        cout << "-1" << endl;
    return 0;
}