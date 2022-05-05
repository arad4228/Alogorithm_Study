#include <iostream> 

using namespace std; 

int main(void) 
{
    int n; 
    int arr[1000], sum = 0;
    cin >> n; 

    // 배열에 모든 값을 집어 넣는다.
    for (int i = 0; i < n; i++) 
    { 
        cin >> arr[i]; 
        sum += arr[i]; 
    } 
    // 전체 모든 값의 합은 모두 더한 값에 /2 한 값임을 이용.
    sum /= 2; 
    // 
    for (int i = 0; i < n; i++) 
    { 
        int tmp = 0; 
        for (int j = 0; j < n; j += 2) 
            tmp += arr[(i + j) % n];
        cout << tmp - sum << endl; 
    }
    return 0;
}