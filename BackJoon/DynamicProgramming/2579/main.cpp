#include <iostream>

int main(void)
{
    // 전체 계단 수
    int nStep;
    std::cin >> nStep;

    // 계단에 대한 점수
    int* arrScore = new int[nStep];
    for(int i =0; i < nStep; i++)
        // 각 계단에 대한 점수를 입력받는다.
        std::cin >> arrScore[i];

    // 계단을 올라가면서 얻는 점수들을 저장하는 배열
    int* arrMaxScore = new int[nStep];

    arrMaxScore[0] = arrScore[0];
    if (nStep <= 2) // 계단이 2개 이하인 경우 모두 밟기
    {
        arrMaxScore[nStep-1] = arrMaxScore[nStep-2] + arrScore[nStep-1];
        std::cout << arrMaxScore[nStep-1] << std::endl;
    }
    else
    {
        // 두번째 계단은 무조건 밟아야 한다.
        arrMaxScore[1] = arrMaxScore[0] + arrScore[1];
        // 세번째 계단은 달라짐.
        // 0 -> 2 or 1 -> 2
        arrMaxScore[2] = std::max(arrScore[0] + arrScore[2], arrScore[1] + arrScore[2]);

        for(int i = 3; i < nStep; i++)
            // i-2 -> i or i-3 -> i-1 -> i
            arrMaxScore[i] = std::max(arrMaxScore[i-2] + arrScore[i], arrMaxScore[i-3] + arrScore[i-1] + arrScore[i]);
        // 마지막 계단까지 올라가는데 얻을 수 있는 최대 점수를 출력한다.
        std::cout << arrMaxScore[nStep-1] << std::endl;
    }

    delete[] arrScore;
    delete[] arrMaxScore;
    return 0;
}