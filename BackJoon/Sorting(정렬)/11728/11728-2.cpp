#include <iostream> 

using namespace std; 
int a_index=0, b_index=0; 
int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // 정수의 크기를 입력 받을 변수
    int N, M;
    cin >>N>>M; 
    
    // 각각의 배열을 생성한다.
    int a[N+1],b[M+1]; 
    
    // 각각의 배열안에 값을 삽입
    for (int i=0;i<N;i++) 
        cin >> a[i];

    for (int i=0;i<M;i++) 
        cin >> b[i];

    // 각 배열의 값을 순차적으로 비교하며 작은 원소를 출력
    while(a_index < N && b_index < M) 
    { 
        if(a[a_index]<=b[b_index]) 
            cout << a[a_index++] << " "; 
        else 
            cout << b[b_index++] << " "; 
    } 
    // 남아있는 원소들을 출력
    while(a_index<N) 
        cout << a[a_index++] << " "; 

    while(b_index<M) 
        cout << b[b_index++] << " "; 
    cout << endl;
    return 0;
}