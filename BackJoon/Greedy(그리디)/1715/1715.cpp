#include <iostream>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

int main(void)
{
    // 현재 카드의 갯수를 저장할 변수
    int N;
    cin >> N;
    
    // 카드리스트를 저장할 우선순위 큐
    priority_queue<int,vector<int>, greater<int> > cardlist;
    // 결과를 도출할 변수
    int result = 0;

    // 카드의 갯수를 입력
    for (int i = 0; i< N;i++)
    {
        int cards;
        cin >> cards;
        cardlist.push(cards);
    }

    // 카드리스트의 값이 1개가 있지 않는 동안
    // == 결과값
    while(cardlist.size() > 1)
    {
        // 맨 앞의 두 값을 빼서 더하여 다시 큐에 넣고 결과에 값을 더하는 과정 반복
        int temp = cardlist.top();
        cardlist.pop();
        temp += cardlist.top();
        cardlist.pop();
        cardlist.push(temp);
        result += temp;
    }
    cout << result << endl;
    return 0;
}