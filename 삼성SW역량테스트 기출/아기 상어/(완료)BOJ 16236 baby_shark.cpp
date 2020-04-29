#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dist[22][22];
int map[22][22];
int shark_size = 2;
int eaten_count;
bool mom_call = false;
int moved;
int num;

queue<pair<int, int>> q;
vector<pair<int, pair<int, int>>> v;

void catch_fish(int x, int y) { // vector¿¡ »ðÀÔ
	v.push_back(make_pair(dist[x][y], make_pair(x, y)));
}
void eat_fish() {
	if (v.empty()) {
		mom_call = true; return;
	}
	sort(v.begin(), v.end());
	int fish_row = v.front().second.first;
	int fish_col = v.front().second.second;
	eaten_count++;
	moved += dist[fish_row][fish_col];
	map[fish_row][fish_col] = 9;
	v.clear();
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
				}
			}
		}
		if (col - 1 >= 0) {
			if (dist[row][col - 1] == -1 && map[row][col - 1] <= shark_size) {
				dist[row][col - 1] = dist[row][col] + 1;
				q.push(make_pair(row, col - 1));
				if (map[row][col - 1] < shark_size && map[row][col-1] > 0) {
					catch_fish(row, col - 1);
				}
			}
		}
		if (col + 1 < num) {
			if (dist[row][col + 1] == -1 && map[row][col + 1] <= shark_size) {
				dist[row][col + 1] = dist[row][col] + 1;
				q.push(make_pair(row, col + 1));
				if (map[row][col + 1] < shark_size && map[row][col+1] > 0) {
					catch_fish(row, col + 1);
				}
			}
		}
		if (row + 1 < num) {
			if (dist[row + 1][col] == -1 && map[row + 1][col] <= shark_size) {
				dist[row + 1][col] = dist[row][col] + 1;
				q.push(make_pair(row + 1, col));
				if (map[row + 1][col] < shark_size && map[row + 1][col] > 0) {
					catch_fish(row + 1, col);
				}
			}
		}
	}
	eat_fish();
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
					map[i][j] = 0;
					i = num;
					j = num;
				}
			}
		}
	}

	cout << moved;

	return 0;
}