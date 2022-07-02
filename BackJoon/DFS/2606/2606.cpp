#include <iostream>
#include <vector>

using namespace std;
bool visited[101] = {false,};
vector<int> virus[101];
int cnt = 0;

// dfs의 알고리즘
void dfs(int v) 
{
	visited[v] = true;
	for (int i = 0; i < virus[v].size(); i++) 
    {
		int next = virus[v][i];
		if (!visited[next])
        {   
            dfs(next);
            // dfs를 진행하면서 노드의 갯수를 파악
            cnt++;

        }
	}
}

int main(void)
{
    // 노드의 갯수
    int C;
    // 간선의 갯수
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