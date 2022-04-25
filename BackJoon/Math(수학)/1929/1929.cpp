#include <iostream>
#include <cmath>

using namespace std;
// 소수인지 확인하는 배열
bool primeNum[1000001];

int main(void) {
	// 사용자의 입력을 받을 공간
	int M, N;
	cin >> M >> N;
    // 초기화
	for (int i = M; i <= N; i++) {
		primeNum[i] = true;
	}
	// 소수인지 확인하는 로직
	primeNum[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = i + i; j <= N; j += i) {
			primeNum[j] = false;
		}
	}
	// 결과 출력
	for (int i = M; i <= N; i++) {
		if (primeNum[i]) printf("%d\n", i);
	}
}