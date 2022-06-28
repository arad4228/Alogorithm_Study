#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int N;
    int seq[1000001], ans[1000001];
    stack<int> stack;
    cin >> N;
    for(int i =0; i < N; i++)
        cin >> seq[i];
    
    for(int i = N-1; i >= 0; i--)
    {
        while(!stack.empty() && stack.top() <= seq[i])
            stack.pop();
        
        if(stack.empty())
            ans[i] = -1;
        else
            ans[i] = stack.top();
        stack.push(seq[i]);
    }
    for(int i =0; i< N;i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}