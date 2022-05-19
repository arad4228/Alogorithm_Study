#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    // overflow를 처리하기 위한 공간 할당
    long long N;
    cin >> N;
    int Die[6];
    int maxDie= 0;
    long long result = 0;
    for (int i  =0; i < 6; i++)
    {
        cin >> Die[i];
        result += Die[i];
        maxDie = max(maxDie, Die[i]);

    }
    // N이 1일 경우에 대해 예외처리
    if(N == 1)
        cout << result - maxDie << "\n";
    else
    {
        // 일반적인 경우에 대해 처리
        result =0;
        Die[0] = min(Die[0], Die[5]);
		Die[1] = min(Die[1], Die[4]);
		Die[2] = min(Die[2], Die[3]);
    
		sort(Die, Die + 3);
		int sum1 = Die[0];
		int sum2 = sum1 + Die[1];
		int sum3 = sum2 + Die[2];

        // 3면은 4개
        // 2면은 4*(N-2)+ 4*(N-1)개
        // 1면은 4*((N-1)(N-2) + (N-2)(N-2)))개가 존재;
		result += sum3 * 4;
		result += sum2 * (4 * (N-2) + 4 * (N -1));
		result += sum1 * (4 * (N-1)*(N-2) + (N-2)*(N-2));

		cout << result;
    }
    return 0;
}