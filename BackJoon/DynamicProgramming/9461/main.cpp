#include <iostream>

int main(void)
{
    // 총 테스트 갯수
    int nTest;
    int nMaxTest = 100;
    std::cin >> nTest;

    // 데이터를 저장할 공간.
    long* arrTestCases = new long[nMaxTest];
    // 3번 케이스까지는 제공됨
    arrTestCases[0] = 1;
    arrTestCases[1] = 1;
    arrTestCases[2] = 1;

    for(int i = 0; i < nTest; i++)
    {
        // 테스트 케이스를 입력 받음.
        int nTarget;
        std::cin >> nTarget;
        // 3보다 작다면, 출력.
        if(nTarget < 3)
        {
            std::cout << arrTestCases[nTarget-1] << std::endl;
            continue;
        }

        // 3번 케이스부터 계산하기
        for(int j = 3; j < nTarget; j++)
            // j = j-2 + j-3의 결과임.
            arrTestCases[j] = arrTestCases[j-2] + arrTestCases[j-3];

        std::cout << arrTestCases[nTarget-1] << std::endl;
    }

    delete[] arrTestCases;
    return 0;
}