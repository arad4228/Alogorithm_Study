#include <iostream>

using namespace std;

int main(void)
{
    // 설탕을 입력 받을 인자.
    int N;
    // 5Kg, 3Kg의 갯수 기본적으로 0으로 초기화
    int FiveKg, ThreeKg = 0;
    // 설탕의 무게를 입력 받는다.
    cin >> N;
    // 최대의 5Kg을 가질 수 있는 수를 구함.
    FiveKg = N/5;

    while(true)
    {
        // 만약 5kg의 갯수가 음수라면 정확하게 만들 수 없음.
        if (FiveKg < 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        // 그렇지 않으면 무게를 만들 수 있기에 5Kg를 제외한 무게가 3kg으로 만들 수 있는 지 검사
        if((N - (FiveKg * 5)) % 3 == 0)
        {
            ThreeKg = (N - (FiveKg * 5)) / 3;
            break;
        }
        // 만들 수 없다면 5Kg을 하나 제거
        FiveKg--;
    }
    cout << FiveKg+ThreeKg << endl;
    return 0;
}