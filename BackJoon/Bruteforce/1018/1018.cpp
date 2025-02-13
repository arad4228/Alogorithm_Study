#include <iostream>

// MN보드를 8x8로 잘라 최소한으로 색칠하는 것을 구하는 함수
int changeChess(char chess[8][8])
{
    int count = 0;
    // r: row, c: column
    for(int r = 0; r < 8; r+=2)
        for(int c = 0; c < 8; c+=2)
        {   
            // 현재 시점을 기준으로 오른쪽, 아래, 대각선 데이터를 비교함.
            // 오른쪽 색과 같다면, 하나 증가함.
            if(chess[r][c] == chess[r][c+1])
            {
                if(chess[r][c+1] == 'B')
                    chess[r][c+1] = 'W';
                else
                    chess[r][c+1] = 'B';
                count++;
            }
            // 아래의 색과 동일하다면, 하나 증가
            if(chess[r][c] == chess[r+1][c])
            {
                if(chess[r+1][c] == 'B')
                    chess[r+1][c] = 'W';
                else
                    chess[r+1][c] = 'B';
                count++;
            }
            // 대각선방향의 데이터와 색이 같지 않다면 하나 증가
            if(chess[r][c] != chess[r+1][c+1])
            {
                if(chess[r+1][c+1] == 'B')
                    chess[r+1][c+1] = 'W';
                else
                    chess[r+1][c+1] = 'B';
                count++;
            }

            if(c == 6)
                continue;
            // 검사된 2x2의 옆의 데이터와 같은지 비교
            // 원점과 오른쪽 상단 데이터 비교
            if(chess[r][c] != chess[r][c+2])
            {
                if(chess[r][c+2] == 'B')
                    chess[r][c+2] = 'W';
                else
                    chess[r][c+2] = 'B';
                count++;
            }
            // 왼쪽 하단과 오른쪽 하단 데이터 비교
            if(chess[r+1][c] != chess[r+1][c+2])
            {
                if(chess[r+1][c+2] == 'B')
                    chess[r+1][c+2] = 'W';
                else
                    chess[r+1][c+2] = 'B';
                count++;
            }

            if(r == 6)
                continue;
            // 원점과 왼쪽 하단 데이터 비교
            if(chess[r][c] != chess[r+2][c])
            {
                if(chess[r+2][c] == 'B')
                    chess[r+2][c] = 'W';
                else
                    chess[r+2][c] = 'B';
                count++;
            }
            // 오른쪽 상단과 오른쪽 하단 데이터 비교
            if(chess[r][c+1] != chess[r+2][c+1])
            {
                if(chess[r+2][c+1] == 'B')
                    chess[r+2][c+1] = 'W';
                else
                    chess[r+2][c+1] = 'B';
                count++;        
            }
                
        }
    return count;
}

int main()
{
    // 현재 체스판의 크기
    int n, m;
    std::cin >> n >> m;
    
    // MxN 체스판을 저장할 공간을 생성함.
    char** originChess = new char*[n];
    // 임시로 사용할 고정된 8x8 체스판
    char copyChess[8][8] = {0,};
    char flipedChess[8][8] = {0, };
    // Row들이 생성되었다면, 내부에 Column 데이터를 채운다.
    for(int i = 0; i < n; i++)
    {
        originChess[i] = new char[m];
        for(int j = 0; j < m; j++)
            std::cin >> originChess[i][j];
    }

    // 최소한으로 색칠하는 횟수
    int ret = 999999999;

    // 전체 8x8만큼 잘라서 색칠하는 횟수를 비교함.
    for(int i = 0; i <= n-8; i++)
        for(int j = 0; j <= m-8; j++)
        {
            // 8x8 체스판을 복사함
            for(int k = 0; k < 8; k++)
            {
                for(int l = 0; l < 8; l++)
                {
                    copyChess[k][l] = originChess[i+k][j+l];
                    flipedChess[k][l] = originChess[i+k][j+l];
                }
            }

            int count = changeChess(copyChess);
            if(ret > count)
                ret = count;

            if(flipedChess[0][0] == 'B')
                flipedChess[0][0] = 'W';
            else
                flipedChess[0][0] = 'B';

            count = changeChess(flipedChess);
            if (ret > count+1)
                ret = count+1;
        }

    std::cout << ret << std::endl;

    for(int i = 0; i < n; i++)
        delete[] originChess[i];
    delete[] originChess;

    return 0;
}