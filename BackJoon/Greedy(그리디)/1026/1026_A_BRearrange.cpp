#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // 몇개의 원소가 있는지 받을 변수
    int N;
    // 총 결과를 출력할 변수
    int result = 0;
    cin >> N;

    // 각 배열을 담을 벡터 변수
    vector <int> tresure_map_A;
    vector <int> tresure_map_B;

    // A와 B행에 값을 입력 받는다.
    for (int i = 0; i < N ; i++)
    {
        int num;
        cin >> num;
        tresure_map_A.push_back(num);
    }
    for (int i = 0; i < N ; i++)
    {
        int num;
        cin >> num;
        tresure_map_B.push_back(num);
    }

    // 방법 1. A는 오름차순으로 B는 내림차순으로 배열
    sort(tresure_map_A.begin(),tresure_map_A.end());
    sort(tresure_map_B.rbegin(),tresure_map_B.rend());

    // 결과는 오름차순으로 정렬된 A행과 내림차순으로 정렬된 B행을 곱해진 값을 더하는 것.
    for(int i = 0; i < N;i++)
        result = result + tresure_map_A[i]*tresure_map_B[i];
    
    cout << result << endl;

    return 0;
}