#include <iostream>
#include <vector>

using namespace std;
bool visited[100] = {false,};
vector<int> virus[100];
int cnt = 0;

void dfs(int v) 
{
	visited[v] = true;
	for (int i = 0; i < virus[v].size(); i++) 
    {
		int next = virus[v][i];
		if (!visited[next])
        {   
            dfs(next);
            cnt++;

        }
	}
}

int main(void)
{
    int C;
    int N;
    cin >> C >> N;
    for(int i= 0; i < N; i++)
    {
        int fri, sec;
        cin >> fri >> sec;
        virus[fri].push_back(sec);
        virus[sec].push_back(fri);
    }
    dfs(1);
    
    cout << cnt << "\n";

    return 0;
}