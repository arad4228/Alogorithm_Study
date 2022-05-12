#include <iostream>

using namespace std;

int teleport(int x, int y,int move)
{
    if(x == y)
        return;
    if(move == 0)
        teleport(x+1,y,move+1);
    move = ;
}

int main(void)
{
    // 테스트 케이스횟수를 저장할 공간
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
         // 시작 좌표와 끝의 좌표를 위한 변수
        int x, y;
        cin >> x >> y;
        int result = teleport(x,y,0);
        cout << result << endl;
    }
    return 0;
}