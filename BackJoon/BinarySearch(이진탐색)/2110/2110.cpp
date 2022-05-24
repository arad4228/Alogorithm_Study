#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N, C;
    int left, right;
    int idx = 0;
    cin >> N >> C;
    vector<int> house(N);
    for(int i =0; i < N; i++)
        cin >> house[i];

    // 오름차순으로 정리하기
    sort(house.begin(), house.end());

    // 해결 로직
    left = 0, right = house[N-1];
    while (left <= right) {
		int iptime_cnt = 1;
		int pre_idx = 0;
		int mid = (left + right) / 2;
		for (idx = 1; idx < N; ++idx) 
			if (house[idx] - house[pre_idx] >= mid) 
            {
				pre_idx = idx;
				iptime_cnt++;
			}
		if (iptime_cnt >= C)
			left = mid + 1;
		else 
            right = mid - 1;
	}
	cout << right << "\n";	
    return 0;
}