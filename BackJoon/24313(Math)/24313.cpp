#include <iostream>

int main(void)
{
    int a0, a1 = 0;
    int c, n0 = 0;
    bool isCorrect =  true;
    std::cin >> a1 >> a0 >> c >> n0;

    for(int i = n0; i < n0+100; i++)
    {
        if(a1*i+a0 > c*i)
            isCorrect = false;
    }
    if(isCorrect)
        std::cout << "1" << std::endl;
    else
        std::cout << "0" << std::endl;
        
    return 0;
}