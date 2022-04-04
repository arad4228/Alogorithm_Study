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

    // 방법 2: A에 대한 벡터를 오름차순으로 정렬을 진행하고 B에서 큰값을 찾아 값을 꺼내고 인덱스를 찾아 삭제해 결과를 구하기.

    sort(tresure_map_A.begin(),tresure_map_A.end());

    for(int i = 0; i < N; i++)
    {
        int Max_B;
        Max_B = max_element(tresure_map_B.begin(),tresure_map_B.end())- tresure_map_B.begin();
        result = result + tresure_map_A[i]*tresure_map_B[Max_B];
        tresure_map_B.erase(tresure_map_B.begin() + Max_B);
    }
    cout << result << endl;
    return 0;
}