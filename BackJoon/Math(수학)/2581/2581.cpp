#include <iostream>

int arrNonPrimeChecker[10000] = {0, 1, };

void checkPrime(int last)
{
    for(int i = 2 ; i < last; i++)
    {
        if(arrNonPrimeChecker[i] == 0)
            for(int p = 2; i*p <= last; p++)
                arrNonPrimeChecker[p*i] = 1;
    }
}

int main(void)
{
    int n1, n2 = 0;
    std::cin >> n1 >> n2;
    checkPrime(n2);
    
    int ret = 0;
    int nMinPrime = 0;
    for(int  i = n1; i <= n2; i++)
        if(arrNonPrimeChecker[i] == 0)
        {
            ret += i;
            if(nMinPrime == 0)
                nMinPrime = i;
        }
            
    if(ret == 0)
        std::cout << "-1" << std::endl;
    else
    {
        std::cout << ret << std::endl;
        std::cout << nMinPrime << std::endl;
    }

    return 0;
}