#include <iostream>
#include <string>


int main(void)
{
    // 몇번째 영화제목에 들어가는 수인지 받는 인자
    int N;
    std::cin >> N;
    int count = 1;
    // 기본 부터 시작함
    int result = 666;
    while(true)
    {
        // 만약 N번째 종말의 수를 찾았다면.
        if (count == N)
        {
            std::cout << result << std::endl;
            break;
        }
        result++;
        if (std::to_string(result).find("666") != -1)
        // 만약 종말의 수를 찾았다면 count를 증가시킨다.
            count++;
    }
    return 0;
}