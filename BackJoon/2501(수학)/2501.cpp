#include <iostream>

int main(void)
{
    int n1, n2 = 0;
    std::cin >> n1 >> n2;

    int nlocation = 0;
    for(int i = 1; i <= n1; i++)
    {
        if(n1 % i == 0)
            nlocation++;
        else
            continue;
        if(nlocation == n2)
            std::cout << i << std::endl;
    }
    if(nlocation < n2)
        std::cout << "0" << std::endl;
    return 0;
}