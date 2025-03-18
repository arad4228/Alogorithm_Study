#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    // 과목 수와 미일리지를 입력받는다.
    int n, m;
    std::cin >> n >> m;

    // 각 과목별로 수강인원과 최대 수강인원을 저장하는 벡터
    std::vector<std::pair<int, int> > vecPeopleMaxPeople;
    // 각 과목에 대한 마일리지를 저장하는 2차원 리스트
    int** arrMilege = new int*[n];
    for(int i = 0; i < n; i++)
    {
        // 각 과목에 대한 수강인원과 최대인원을 입력 받음
        std::pair<int, int> pairPeopleMaxPeople;
        std::cin >> pairPeopleMaxPeople.first >> pairPeopleMaxPeople.second;

        // 벡터에 데이터를 저장하기.
        vecPeopleMaxPeople.push_back(pairPeopleMaxPeople);

        // 해당 과목에 대한 사용자들의 마일리지 사용량을 저장함.
        arrMilege[i] = new int[pairPeopleMaxPeople.first];
        for(int j = 0; j < pairPeopleMaxPeople.first; j++)
            std::cin >> arrMilege[i][j];
    }

    // 모든 데이터 정렬
    for (int i = 0; i < n; i++)
        // 정렬 수행
        std::sort(arrMilege[i], arrMilege[i] + vecPeopleMaxPeople[i].first, std::greater<int>());
    
    // 각 과목별로 마일리지를 투자해 수강 하는 알고리즘
    int nResult = 0;
    // 각 과목을 수강하기 위해 필요한 절대적인 마일리지 값
    int* arrNeedMilege = new int[n];

    for(int i = 0; i < n; i++)
    {
        // 강의를 수강한 인원
        int nPeople = vecPeopleMaxPeople[i].first;
        // 각 강의의 최대 인원
        int nMaxPeople = vecPeopleMaxPeople[i].second;
        // 만약 인원이 찼다면
        if (nPeople > nMaxPeople)
            // 각 강의를 수강하기 위해 필요한 최소값.
            arrNeedMilege[i] = arrMilege[i][nMaxPeople-1];

        // 인원이 남는다면 1로 설정함.
        else
            arrNeedMilege[i] = 1;
    }

    // 다시 오름차순으로 정렬하여, 최대 수강수를 선택힘.
    std::sort(arrNeedMilege, arrNeedMilege + n);
    
    int nSumMilege = 0;
    for(int i = 0; i < n; i++)
    {
        nSumMilege += arrNeedMilege[i];
        if (nSumMilege > m)
            break;
        nResult++;
    }

    std::cout << nResult << std::endl;

    // 사용된 메모리는 정리할 것.
    delete[] arrMilege;
    delete[] arrNeedMilege;
    vecPeopleMaxPeople.clear();
    vecPeopleMaxPeople.shrink_to_fit();
    return 0;
}