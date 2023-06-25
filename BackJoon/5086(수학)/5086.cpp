#include <iostream>

int main(void)
{
    while(true)
    {
        int n1, n2 = 0;
        std::cin >> n1 >> n2;
        if(n1 == 0 || n2 == 0)
            break;
        else
        {
            bool isFactor = false;
            bool isMultiple = false;
            std::cout << "Enter isFactor: " << isFactor << " isMultiple: " << isMultiple << std::endl;
            if(n2 % n1 == 0)
                isFactor = true;
            if(n1 % n2 == 0)
                isMultiple = true;

            if(isFactor == true)
                std::cout << "factor" << std::endl;
            else if(isMultiple == true)
                std::cout << "multiple" << std::endl;
            else
                std::cout << "neither" << std::endl;
            std::cout << "After isFactor: " << isFactor << " isMultiple: " << isMultiple << std::endl;
            // isFactor = false;
            // isMultiple = false;
        }
    }
    return 0;
}