#include <iostream>
#include <vector>

void blackJack(int n, int m, std::vector<int> vecCardList)
{
    int resultMax = 0;
    for(int i = 0; i < n; i++)
    {
        int innerMax = vecCardList[i];
        if(innerMax > m)
            continue;
        for(int j = i+1; j < n; j++)
        {
            if(innerMax+vecCardList[j] > m)
                continue;
            innerMax += vecCardList[j];
            for(int k = j+1; k < n; k++)
            {
                if(innerMax + vecCardList[k] > m)
                    continue;
                if(innerMax+vecCardList[k] > resultMax)
                    resultMax = innerMax+vecCardList[k];
            }
            innerMax -= vecCardList[j];
        }
    }
    std::cout << resultMax << std::endl;
}

int main(void)
{
    int n, m;
    std::vector<int> vecCardlist;
    std::cin >> n >> m;
    vecCardlist.resize(n);
    for(int i = 0; i < n; i++)
        std::cin >> vecCardlist[i];
    
    blackJack(n, m, vecCardlist);
    return 0;   
}