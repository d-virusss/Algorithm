#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int depth;
int arr[9];
int output[9];
bool used[9];

void dfs()
{
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << output[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (used[i]) {
			continue;
		}
		depth++;
		used[i] = true;
		output[depth] = arr[i];
		dfs();
		depth--;
		used[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(&arr[0], &arr[N]);

	dfs();
}