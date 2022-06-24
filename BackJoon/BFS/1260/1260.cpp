#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[1001] = {false};
vector<int> graph[1001];

void dfs(int v) 
{
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < graph[v].size(); i++) 
    {
		int next = graph[v][i];
		if (!visited[next])
			dfs(next);
	}
}

void bfs(int v) 
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) 
    {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++) 
        {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int st, ed;
        cin >> st >> ed;
        graph[st].push_back(ed);
        graph[ed].push_back(st);
    }
    for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	dfs(V);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	bfs(V);
    cout << '\n';
    return 0;
}