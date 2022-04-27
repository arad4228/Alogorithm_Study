#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    // 입력을 위한 변수
	int a, b;
	vector<int> list;
	cin >> a >> b;
    
    // 값을 벡터에 삽입
	int idx = 0;
	for (int i = 1; i <= 1000; i++)
		for (int j = 0; j < i && idx < 1000; j++) 
        {
			list.push_back(i);
            idx++;
		}

	int ans = 0;
	
	//구간 합
	for (int i = a-1; i <= b-1; i++)
    		ans += list[i];

	//정답 출력
	cout << ans << endl;
	return 0;
}