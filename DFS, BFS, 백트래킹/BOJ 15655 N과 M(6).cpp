#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int output[9];
int depth;

void dfs(int root) {
	if (depth == M) {
		for (int i = 1; i <= M; i++) {
			cout << output[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] <= root) {
			continue;
		}
		depth++;
		output[depth] = arr[i];
		dfs(arr[i]);
		depth--;
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
	dfs(0);
}