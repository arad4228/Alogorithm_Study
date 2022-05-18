#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll N, k, Op, ans = 1;
ll factorial[21] = {1};
ll ck[21];

int main()
{
    cin >> N >> Op;
    vector <ll> comb(N+1);
    for(int i = 1; i <= N; i++) 
        factorial[i] = factorial[i-1] * i; 

    // 임의의 번째의 순열을 출력하기
    if(Op == 1){
        cin >> k; 
        
        for(int i = 1; i <= N; i++) //i번째 자리
            for(int j = 1; j <= N; j++) // j의 수
            { 
                if(ck[j]) 
                    continue;
                if(factorial[N-i] < k) //skip마다 n-i!씩 빼줌
                    k -= factorial[N-i];
                else{
                    comb[i] = j;
                    ck[j] = 1;
                    break;
                }
            }

        for(int i = 1; i <= N; i++) 
            cout << comb[i] << ' ';
        cout << "\n";

    }
    // 임의의 수열에 대해 몇번째 순열인지 출력.
    else{
        for(int i = 1; i <= N; i++) 
            cin >> comb[i];

        for(int i = 1; i <= N; i++){
            for(int j = 1; j < comb[i]; j++)
                if(ck[j]) continue;
                    ans += factorial[N-i];
            ck[comb[i]] = 1;
        }
        cout << ans << '\n';
    }
}