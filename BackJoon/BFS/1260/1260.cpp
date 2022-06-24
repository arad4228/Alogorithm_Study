#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[1001] = {false};
vector<int> graph[1001];

// Dfs 알고리즘
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

// Bfs알고리즘
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
    // 입출력 향상
    ios::sync_with_stdio(0);
	cin.tie(0);

    // 각 변수에 대한 공간을 받음
    int N, M, V;
    cin >> N >> M >> V;
    // 각 벡터에 시작과 끝값을 넣어줌
    for (int i = 0; i < M; i++)
    {
        int st, ed;
        cin >> st >> ed;
        graph[st].push_back(ed);
        graph[ed].push_back(st);
    }
    // 낮은 순서대로 정렬을 진행
    for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	dfs(V);
	cout << '\n';
    // 방문노드 이력을 제거
	memset(visited, false, sizeof(visited));
	bfs(V);
    cout << '\n';
    return 0;
}