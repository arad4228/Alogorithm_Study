#include <iostream>
#include <algorithm>

using namespace std;

// 길이가 다를 때 남아있는 값을 더하는 함수
void remain(string &s, string &o, int &len, int &carry) {
	for (; len >= 0; len--) {
		int val = s[len] - '0' + carry;
	    o.push_back(val % 10 + '0');
		carry = val / 10;
	}
}

int main(void)
{
    // 2개의 변수 A,B 그리고 결과를 위한 변수
    string A,B,result= "";
    // 값을 입력 받음
    cin >> A >> B;
    // 입력 받은 변수에 대한 길이 저장
    int Alen = A.length()-1;
    int Blen = B.length()-1;
    // 이는 올림수를 위한 변수
    int carry = 0;

    // 둘의 길이가 0이 아닐동안 동작.
    for(;Alen >= 0 & Blen >= 0; Alen--,Blen--)
    {
        // 입력받은 값의 뒤부터 덧셈 + 올림수
        int val = A[Alen] - '0' + B[Blen] -'0' + carry;
        carry = 0;
        // 만약 올림수가 있다면 올림수를 만들고 
        if(val / 10 == 1)
            carry = 1;
        // 올림수 제외 나머지 값을 결과에 집어 넣음
        result.push_back(val%10 +'0');
    }
    // A, B의 나머지 길이에 대해 덧셈.
    remain(A, result, Alen, carry);
    remain(B, result, Blen, carry);

    // 마무리의 결과에서 올림수가 있다면 올림수를 결과에 반영
    if(carry == 1)
        result.push_back('1');
    
    // 뒤부터 더해 앞으로 넣었으니 결과를 역전.
    reverse(result.begin(),result.end());
    
    cout << result << endl;
    return 0;
}