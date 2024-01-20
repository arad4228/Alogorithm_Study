#include <iostream>

char arrNonPrimeChecker[10000000] = {0, 1, 0, };

void checkPrime(int last)
{
    for(int i = 2; i <= last; i++)
    {
        if(arrNonPrimeChecker[i] == 0)
            for(int p = 2; i*p <= last; p++)
                arrNonPrimeChecker[p*i] = 1;
    }
}

int main(void)
{
    int n;
    std::cin >> n;
    checkPrime(n);

    for(int i = 2; i <= n; i++)
    {
        if(arrNonPrimeChecker[i] == 0 || n != 0)
        {
            while(n % i == 0)
            {   
                std::cout << i << std::endl;
                n = n / i;
            }
        }
    }
    return 0;
}