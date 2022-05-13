#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int first[1000001];
int second[1000001];
int main(void)
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    // 원소의 크기를 입력받을 변수
    int N, M;
    cin >> N >> M;
    // 결과를 담을 벡터 추가
    vector<int> result;

    // 각각 값을 삽입
    for (int i = 0; i < N; i++)
        cin >> first[i];
    for (int i = 0; i < M; i++)
        cin >> second[i];

    // 각배열의 원소들을 결과 벡터에 삽입
    for(int i=0;i< N;i++) 
        result.push_back(first[i]);
    
    for(int i=0;i<M;i++) 
        result.push_back(second[i]);

    // 오름차순으로 정렬
    sort(result.begin(),result.end());

    // 값을 출력.
    for(int j =0 ; j< N+M; j++)
        cout << result[j] << " ";
    cout << endl;
    return 0;
}