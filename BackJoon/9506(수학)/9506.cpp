#include <iostream>
#include <vector>

int main(void)
{
    int num = 0;
    while(true)
    {
        std::cin >> num;
        if(num == -1)
            break;
        else
        {
            int nSum = 0;
            std::vector<int> vecDivide;        
            for(int i = 1; i < num; i++)
            {
                if(num % i == 0)
                {
                    nSum += i;
                    vecDivide.push_back(i);
                }
            }
            if(nSum == num)
            {
                std::cout << num << " = " << vecDivide[0];
                for(int j = 1; j < vecDivide.size(); j++)
                    std::cout << " + " << vecDivide[j];
            }
            else
                std::cout << num << " is NOT perfect.";
            std::cout << std::endl;
        }
    }
    return 0;
}