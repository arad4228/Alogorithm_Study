#include <iostream>
#include <string>

int main(void)
{
    // 전체 문장과 탐색할 문장을 입력받는다.
    std::string strSentence, strTarget;
    std::getline(std::cin, strSentence);
    std::getline(std::cin, strTarget);

    // 전체 문장에서 탐색할 문장이 최대 몇번 등장하는지 찾는다.
    // 최대 등장 횟수에 대한 변수
    int nStringLen = strSentence.length();
    int nTargetLen = strTarget.length();

    // 전체 문장의 시작부터 끝까지 탐색할 문장을 찾음.
    int maxCount =0;
    for(int i =0; i < nStringLen; i++)
    {
        int nCount = 0;
        int innerPos = i;
        int nFindIndex = 0;
        // 탐색할 문장이 있는지 i번째 위치부터 탐색하여 찾는다.
        while(true)
        {
            nFindIndex = strSentence.find(strTarget, innerPos + nFindIndex);
            // 찾는 문장이 없다면, 빠져나온다.
            if (nFindIndex == std::string::npos)
            {
                break;
            }
            // 그렇지 않으면, 값을 증가시킨다.
            nCount++;
            nFindIndex += nTargetLen;
        }
        if (maxCount < nCount)
        {
            maxCount = nCount;
        }
    }
    std::cout << maxCount << std::endl;
    return 0;
}