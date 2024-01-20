#include <iostream>

long int findMAX_N(long int S)
{
    long int maxCount = 0;
    long int nSum = 0;
    long int i = 1;
    do 
    {
        maxCount++;
        nSum += i;
        i++;
    }while(nSum + i < S);
    if(nSum + i == S)
        maxCount +=1;
    return maxCount;
}

int main(void)
{
    long int S;
    scanf("%ld", &S);
    printf("%ld\n", findMAX_N(S));
    return 0;
}