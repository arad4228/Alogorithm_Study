#include <iostream>
#include <deque>
#include <vector>

// 연산의 횟수 계산
int finOperationNumber(std::deque<int>* queueBiDirection, std::vector<int> vecPopUpList)
{
    // 초기의 결과는 무조껀 0으로 설정.
    int nResult = 0;
    // 크기와 몇개의 수를 뽑을지 확인
    int nPopUpData = vecPopUpList.size();
    
    // 뽑아야하는 수만큼 반복
    for(int i = 0; i < nPopUpData; i++)
    {
        int targetIndex = 0;
        // 해당 수의 위치를 찾음
        for (int j = 0; j < queueBiDirection->size(); j++) {
            if (queueBiDirection->at(j) == vecPopUpList[i]) {
                targetIndex = j;
                break;
            }
        }

        // 왼쪽으로 이동하는 경우와 오른쪽으로 이동하는 경우 중 더 적은 횟수를 선택
        if (targetIndex < queueBiDirection->size() - targetIndex) {
            // 왼쪽으로 이동
            for (int j = 0; j < targetIndex; j++) {
                int frontValue = queueBiDirection->front();
                queueBiDirection->pop_front();
                queueBiDirection->push_back(frontValue);
                nResult++;
            }
        } else {
            // 오른쪽으로 이동
            for (int j = 0; j < queueBiDirection->size() - targetIndex; j++) {
                int backValue = queueBiDirection->back();
                queueBiDirection->pop_back();
                queueBiDirection->push_front(backValue);
                nResult++;
            }
        }

        // 해당 수를 뽑아냄
        queueBiDirection->pop_front();
    }

    return nResult;   
}

int main(void)
{
    // N: 원소의 수, M: 뽑아내려는 원소수
    int N, M;
    // 구분자를 통해 데이터를 입력받음.
    std::cin >> N >> M;

    // 양방향 큐를 지원하기 위한 벡터 사용.
    std::deque<int> queueBiDirection;
    // 뽑아내려는 수를 저장하기 위한 벡터 사용.
    std::vector<int> vecPopUpList;

    // 데이터 삽입
    for (int i = 0; i < N; i++)
        queueBiDirection.push_back(i+1);

    // 뽑아 내려는 수 저장
    for (int i = 0; i < M; i++)
    {
        int temp;
        std::cin >> temp;
        vecPopUpList.push_back(temp);
    }

    // 2, 3번 연산의 결과 찾기.
    std::cout << finOperationNumber(&queueBiDirection, vecPopUpList) << std::endl;
    queueBiDirection.clear();
    vecPopUpList.clear();
    return 0;

}