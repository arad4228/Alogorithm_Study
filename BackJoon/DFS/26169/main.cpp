#include <iostream>
#include <algorithm>


bool checkEatTwoApple(int nMax, std::pair<int, int> pairLocation, int nApple, int nMove, int** arrAppleLocation)
{
    // 현재 좌표 정보를 받아온다.
    int x = pairLocation.first;
    int y = pairLocation.second;
    int isApple = arrAppleLocation[x][y];

    if(x < 0 || x >= nMax || y < 0 || y >= nMax || isApple == -1)
        return false;

    // 현재 위치에 사과가 있는지 파악하고,
    if(isApple == 1)
        nApple++;

    // 사과를 2개 먹었다면 종료
    if((nApple >= 2) && (nMove <= 3))
        return true;
    
    if(nMove >= 3)
        return false;

    // 배열을 복사
    int** arrCopyData = new int*[nMax];
    for(int i = 0; i < nMax; i++)
    {
        arrCopyData[i] = new int[nMax];
        std::copy(arrAppleLocation[i], arrAppleLocation[i] + nMax, arrCopyData[i]);
    }
    arrCopyData[x][y] = -1;

    // 찾은 결과
    bool result = false;
    if(!result)        // 상
    {
        std::pair<int, int> pairUp = pairLocation;
        pairUp.first -=1;
        result |= checkEatTwoApple(nMax, pairUp, nApple, nMove+1, arrCopyData);
    }
    if(!result)    // 하
    {
        std::pair<int, int> pairDown = pairLocation;
        pairDown.first +=1;
        result |= checkEatTwoApple(nMax, pairDown, nApple, nMove+1, arrCopyData);
    }
    if(!result)    // 좌
    {
        std::pair<int, int> pairLeft = pairLocation;
        pairLeft.second -= 1;
        result |= checkEatTwoApple(nMax, pairLeft, nApple, nMove+1, arrCopyData);
    }
    if(!result)    // 우
    {
        std::pair<int, int> pairRight = pairLocation;
        pairRight.second += 1;
        result |= checkEatTwoApple(nMax, pairRight, nApple, nMove+1, arrCopyData);
    }

    for(int i = 0; i < nMax; i++)
        delete[] arrCopyData[i];
    delete[] arrCopyData;
    // 없음
    return result;
}


int main(void)
{
    // 현재 위치에 대한 행과 열에 대한 데이터를 입력 받는다.
    // first: r, second: c;
    std::pair<int, int> pairLocation;
    int nMax = 5;

    // 데이터는 5 x 5 행렬 데이터임.
    int** arrAppleLocation = new int*[nMax];
    for(int i =0; i < nMax; i++)
        arrAppleLocation[i] = new int[nMax];
    
    // 행렬에 데이터를 삽입한다.
    for(int i =0; i < nMax; i++)
        for(int j = 0; j < nMax; j++)
            std::cin >> arrAppleLocation[i][j];

    // 현재 위치 정보를 받는다.
    std::cin >> pairLocation.first >> pairLocation.second;

    // 2개 이상의 사과를 먹을 수 있는지 확인.
    bool ret = checkEatTwoApple(nMax, pairLocation, 0, 0, arrAppleLocation);
    std::cout << (ret ? 1 : 0) << std::endl;

    return 0;
}