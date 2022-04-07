#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string input = "";
    long long thirtyN;
    cin >> input;
    sort(input.rbegin(),input.rend());
    thirtyN = stoll(input);
    if(input[input.size()-1] == '0' & thirtyN % 3 == 0)
        cout << input << endl;
    else
        cout << "-1" << endl;
    return 0;
}