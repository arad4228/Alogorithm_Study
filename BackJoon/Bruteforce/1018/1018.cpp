#include <iostream>

int changeChess(char** chess, int n, int m)
{
    int count = 0;

    for(int i = n; i < m+8; i+=2)
        for(int j = m; j < m+8; j+=2)
        {
            if(chess[i][j] == chess[i][j+1])
                count++;
            if(chess[i][j] == chess[i+1][j])
                count++;
            if(chess[i+1][j+1] != chess[i][j])
                count++;
        }

    return count;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    char** chess = new char*[n];
    for(int i = 0; i < n; i++)
    {
        chess[i] = new char[m];
        for(int j = 0; j < m; j++)
            std::cin >> chess[i][j];
    }

    int ret = 999999;
    for(int i = 0; i <= n-8; i++)
        for(int j = 0; j <= m-8; j++)
        {
            int count = changeChess(chess, i , j);
            if(ret > count)
                ret = count;
        }

    std::cout << ret << std::endl;

    for(int i = 0; i < n; i++)
        delete[] chess[i];
    delete[] chess;

    return 0;
}
