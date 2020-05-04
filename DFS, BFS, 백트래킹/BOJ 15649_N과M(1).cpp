#include <iostream>

using namespace std;

int N, M;
int depth;
int arr[9];
bool used[9];

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
		if (used[i]) {
			continue;
		}
		depth++;
		arr[depth] = i;
		used[i] = true;
		dfs();
		used[i] = false;
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