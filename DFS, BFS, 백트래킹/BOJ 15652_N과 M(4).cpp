#include <iostream>

using namespace std;

int N, M;
int arr[9];
int depth;

void dfs(int root)
{
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (i < root) {
			continue;
		}
		depth++;
		arr[depth] = i;
		dfs(i);
		depth--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	dfs(0);
}