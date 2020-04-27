#include <iostream>
#include <queue>

#define MIN -1000000000
using namespace std;

char map[503][503];
char visit[503][503];
queue<pair<int, int>> bfs;
int pictures = 0;
int row, col;

int bfs_search(int x, int y) {
	pictures++;
	int p_size = 0;
	int first, second;
	while (!bfs.empty()) {
		first = bfs.front().first;
		second = bfs.front().second;

		bfs.pop();
		p_size++;
		if (first - 1 >= 0) {
			if (map[first - 1][second] == '1' && visit[first - 1][second] == 0) {
				visit[first - 1][second] = 1;
				bfs.push(make_pair(first - 1, second));
			}
		}
		if (second - 1 >= 0) {
			if (map[first][second-1] == '1' && visit[first][second-1] == 0) {
				visit[first][second-1] = 1;
				bfs.push(make_pair(first, second-1));
			}
		}
		if (second +1 < col) {
			if (map[first][second+1] == '1' && visit[first][second+1] == 0) {
				visit[first][second+1] = 1;
				bfs.push(make_pair(first, second+1));
			}
		}
		if (first+1<row) {
			if (map[first+1][second] == '1' && visit[first + 1][second] == 0) {
				visit[first + 1][second] = 1;
				bfs.push(make_pair(first + 1, second));
			}
		}
	}
	return p_size;
}

int main()
{
	int max_size = MIN;
	int size;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == '1' && visit[i][j] == 0) {
				visit[i][j] = 1;
				bfs.push(make_pair(i, j));
				size = bfs_search(i, j);
				if (size > max_size)
					max_size = size;
			}
		}
	}
	if (pictures == 0)
		max_size = 0;

	cout << pictures << '\n' << max_size;
}