#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // 몇개의 데이터를 입력 받을지에 대한 변수
    int N;
    cin >> N;
    
    // id값을 1~i번째까지 더한 값에 7로 나눈 값을 저장할 7개의 vector 각각 나머지 값이 0~6에 해당
    vector<int> id_mul_mod[7];
    // 총합을 위한 변수
    int sum = 0;
    // 결과 값을 위한 변수
    int result = 0;
    // 값을 입력 받음.
    for(int i = 1; i <= N; i++)
    {
        int id;
        cin >> id;
        sum += id;
        sum %= 7;
        id_mul_mod[sum].push_back(i);
    }
    // 만약 모든 합이 0으로 나눠지는 값에 대해 result와 값을 비교해 변경
    if(id_mul_mod[0].size())
        result = max(result, id_mul_mod[0].back());

    // 나머지 값에 대해 결과를 수행
    // 1 < j일때 id_mul_mod[i] == id_mul_mod[j]이면 7의 배수임을 사용 
    for(int i = 1; i <= 7;i++)
        if(id_mul_mod[i].size())
            result = max(result, id_mul_mod[i].back() - id_mul_mod[i][0]);

    // 결과를 출력하기
    cout << result << endl;
    return 0;
}