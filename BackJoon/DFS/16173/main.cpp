#include <iostream>

bool finded = false;

// 맵의 크기와 현재 위치, 맵 데이터를 제공함.
bool findRoutingPath(int nSize, std::pair<int, int> pairLocation, int** arrMapData)
{
    // 움직이는 것은 오른쪽, 아래밖에 없음.
    int x = pairLocation.second;
    int y = pairLocation.first;
    int nJump = arrMapData[x][y];
        
    // 오른쪽, 아래로 움직일 경우가 없다면 false 리턴.
    if((x + nJump >= nSize) && (y + nJump >= nSize))
        return false;


    // 끝에 도달했다면 
    if((x == nSize-1) && (y == nSize-1))
    {
        finded = true;
        return true;
    }

    // 이동할 방법이 없다면
    if (nJump == 0)
        return false;

    // 이미 길을 찾았다면.
    if(finded)
        return true;

    // 오른쪽으로 이동하는 경우
    if(x + nJump < nSize)
    {
        std::pair<int, int> pairRight = pairLocation;
        pairRight.second += nJump;
        if(findRoutingPath(nSize, pairRight, arrMapData))
            return true;
    }

    // 아래로 이동하는 경우
    if(y + nJump < nSize)
    {
        std::pair<int, int> pairDown = pairLocation;
        pairDown.first += nJump;
        if(findRoutingPath(nSize, pairDown, arrMapData))
            return true;
    }

    // 모두 실패한 경우
    return false;
}

int main(void)
{
    // 제공되는 구역의 크기
    int nSize;
    std::cin >> nSize;
    
    // 맵 데이터를 저장할 변수
    int** arrMapData = new int*[nSize];
    for(int i = 0; i < nSize; i++)
    {
        // 각각의 줄에 해당하는 공간을 만들고, 변수를 삽입함.
        arrMapData[i] = new int[nSize];
        for(int j = 0; j < nSize; j++)
            std::cin >> arrMapData[i][j];
    }

    // 맵 데이터를 구성했다면, 초기 위치를 설정함.
    std::pair<int, int> pairLocation;
    // second: x, first: y
    pairLocation.first = 0;
    pairLocation.second = 0;

    bool ret = findRoutingPath(nSize, pairLocation, arrMapData);
    if(ret)
        std::cout << "HaruHaru" << std::endl;
    else
        std::cout << "Hing" << std::endl;

    // 사용한 데이터는 삭제함.
    for(int i = 0; i < nSize; i++)
        delete[] arrMapData[i];
    delete[] arrMapData;
    return 0;
}