#include <iostream>

int getDigitSum(int n)
{
    int count = n;
    do{
        count += n % 10;
        n = n / 10;
    }while (n > 0);
    return count;
}

int main(void)
{
    int n;
    int test = 1;
    std::cin >> n;
    for(int i = 1; i < n; i++)
    {
        if(n == getDigitSum(i))
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << "0" << std::endl;
    return 0;
}