#include <iostream>
#include <vector>
#include <algorithm>

// 능력치 차이를 계산하는 함수
int calculateDifference(int** ability, int* team, int n){
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        // 0번팀의 능력치를 계산함.
        for (int j = i + 1; j < n; j++) 
            if (team[i] == team[j]) 
            {
                if (team[i]) {
                    diff += ability[i][j] + ability[j][i];
                } else {
                    diff -= ability[i][j] + ability[j][i];
                }
            }
    }
    // 두팀의 능력치 차를 반환.
    return std::abs(diff);

}

int main(void)
{
    // n명의 사람이 있을 때 팀을 나누는 문제.
    int n;
    std::cin >> n;

    // 누가 누구팀인지 확인하기 위한 리스트
    // 팀은 0과 1로 구분
    int* listTeam = new int[n];

    int diff = 999999;
    // 능력치를 저장하기 위한 배열을 생성
    int** ability = new int*[n];
    for(int i =0; i < n; i++)
    {
        // 각 행에 대한 메모리 할당을 수행
        ability[i] = new int[n];
        for (int j = 0; j < n; j++)
            // 내부에 데이터 삽입
            std::cin >> ability[i][j];
    }

    // 모든 능력치를 저장했다면, 능력치 차이가 최소되는 팀을 계산.
    // 먼저 팀을 설정하고, 능력치 차이를 계산함.
    std::vector<bool> v(n);
    // n/2개의 숫자를 뽑기위한 장치
    std::fill(v.begin(), v.begin() + n/2, true);

    do {
        for (int i = 0; i < n; ++i) {
            // 0번팀인지 1번팀인지 확인
            if (v[i]) {
                listTeam[i] = 0;
            } else {
                listTeam[i] = 1;
            }
        }

        // 팀간의 능력치 차이를 계산
        int ret = calculateDifference(ability, listTeam, n);
        if(ret < diff)
            diff = ret;

    } while (std::prev_permutation(v.begin(), v.end()));

    std::cout << diff << std::endl;

    // 할당된 메모리 해제
    delete[] listTeam;
    for (int i = 0; i < n; i++)
        delete[] ability[i];
    delete[] ability;
    return 0;
}