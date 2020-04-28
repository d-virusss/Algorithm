#include <iostream>
#include <queue>

using namespace std;

int dist[22][22];
int map[22][22];
int shark_size = 2;
int eaten_count;
bool mom_call = false;
int moved;
int num;

queue<pair<int, int>> q;

void clear() {
	while (!q.empty()) {
		q.pop();
	}
}
void catch_fish(int x, int y) {
	eaten_count++;
	moved += dist[x][y];
	map[x][y] = 9;
	clear();
}

void bfs(int x, int y)
{
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		if (row - 1 >= 0) {
			if (dist[row - 1][col] == -1 && map[row - 1][col] <= shark_size) {
				dist[row - 1][col] = dist[row][col] + 1;
				q.push(make_pair(row - 1, col));
				if (map[row - 1][col] < shark_size && map[row-1][col] > 0) {
					catch_fish(row - 1, col);
					return;
				}
			}
		}
		if (col - 1 >= 0) {
			if (dist[row][col - 1] == -1 && map[row][col - 1] <= shark_size) {
				dist[row][col - 1] = dist[row][col] + 1;
				q.push(make_pair(row, col - 1));
				if (map[row][col - 1] < shark_size && map[row][col-1] > 0) {
					catch_fish(row, col - 1);
					return;
				}
			}
		}
		if (col + 1 < num) {
			if (dist[row][col + 1] == -1 && map[row][col + 1] <= shark_size) {
				dist[row][col + 1] = dist[row][col] + 1;
				q.push(make_pair(row, col + 1));
				if (map[row][col + 1] < shark_size && map[row][col+1] > 0) {
					catch_fish(row, col + 1);
					return;
				}
			}
		}
		if (row + 1 < num) {
			if (dist[row + 1][col] == -1 && map[row + 1][col] <= shark_size) {
				dist[row + 1][col] = dist[row][col] + 1;
				q.push(make_pair(row + 1, col));
				if (map[row + 1][col] < shark_size && map[row + 1][col] > 0) {
					catch_fish(row + 1, col);
					return;
				}
			}
		}
	}
	mom_call = true;
}

int main()
{
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		//memset(dist, 0, sizeof(dist) );
		fill(dist[0], dist[0] + (22 * 22), -1);
		if (mom_call == true)
			break;
		if (eaten_count == shark_size) {
			shark_size++;
			eaten_count = 0;
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (map[i][j] == 9) {
					dist[i][j] = 0;
					bfs(i, j);
					i = num;
					j = num;
				}
			}
		}
	}

	cout << moved;

	return 0;
}