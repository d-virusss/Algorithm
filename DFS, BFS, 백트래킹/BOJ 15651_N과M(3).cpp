#include <iostream>

using namespace std;

int N, M;
int arr[8];
int depth;

void dfs()
{
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		depth++;
		arr[depth] = i;
		dfs();
		depth--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	dfs();
}