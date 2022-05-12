#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 유클리드 호법
int GCD(int p, int q)
{
    if(q == 0)
        return p;
    return GCD(q, p % q);
}

int main(void)
{
    int N;
    cin >> N;
    // 숫자들을 저장할 벡터
    vector<int> numlist;
    // 정답을 저장할 벡터
    vector<int> ans;

    // 정수 입력 받기
    for(int i =0; i < N;i++)
    {
        int num;
        cin >> num;
        numlist.push_back(num);
    }
    // 오름차순으로 수를 정렬
    sort(numlist.begin(),numlist.end());

    // A[n] - A[n-1] = m * (A[n]/m - A[n-1]/m) 을 이용해 값을 구하기
    int g = numlist[1] - numlist[0];
    for (int i = 2; i < N; i++)
        g = GCD(g, numlist[i] - numlist[i-1]);
    
    // 결과를 저장
    for(int i = 1; i*i <= g; i++)
        if(g %i == 0)
        {
            ans.push_back(i);
            if(i != g/i)
                ans.push_back(g/i);
        }
    // 결과를 정렬하고 출력 
    sort(ans.begin(), ans.end());
    for(int i =0; i< ans.size(); i++)
        if(ans[i] != 1)
            cout << ans[i] << " ";
    cout << endl;
    return 0;
}