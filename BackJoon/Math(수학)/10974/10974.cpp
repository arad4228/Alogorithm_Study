#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // N에 대한 입력을 받을 변수
    int N;
    cin >> N;
    // 1~N까지 값을 담을 벡터 변수 선언
    vector<int> numlist;
    // 1~N까지 오름차순으로 값을 대입.
    for(int i = 1; i <= N; i++)
        numlist.push_back(i);
    do{
        // 순열조합을 출력 조합이 있을 때까지
        for(int i =0; i < numlist.size(); i++)
            cout << numlist[i] << " ";
        cout << "\n";
    }while(next_permutation(numlist.begin(), numlist.end()));
    return 0;
}