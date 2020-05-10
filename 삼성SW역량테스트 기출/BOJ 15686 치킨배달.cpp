#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[52][52];
bool used[52][52]; // dfs에서 수열 만들 때 사용

bool visit[52][52];
int dist[52][52];
int N, M;
pair<int, int> p[15];
queue<pair<int, int>> q;

int min_chic_dis = 97987897;

int depth;

void clear_q() {
	while (!q.empty()) {
		q.pop();
	}
}

int get_chicken_distance() {
	int tmp_map[52][52];
	int chicken_score = 0;
	memset(tmp_map, 0, sizeof(tmp_map));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0 || map[i][j] == 1) {
				tmp_map[i][j] = map[i][j];
			}
		}
	}
	for (int i = 1; i < 14; i++) {
		if (p[i].first == 0 && p[i].second == 0) break;
		tmp_map[p[i].first][p[i].second] = 2;
	}
	int row, col;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tmp_map[i][j] == 1) {
				q.push(make_pair(i, j));
				memset(visit, 0, sizeof(visit));
				memset(dist, 0, sizeof(dist));
				dist[i][j] = 0;
				visit[i][j] = true;

				while (!q.empty()) {
					row = q.front().first;
					col = q.front().second;
					q.pop();
					if (row - 1 >= 1) {
						if (visit[row - 1][col] == false) {
							q.push(make_pair(row - 1, col));
							visit[row - 1][col] = true;
							dist[row - 1][col] = dist[row][col] + 1;
							if (tmp_map[row - 1][col] == 2) {
								chicken_score += dist[row - 1][col];
								clear_q();
								break;
							}
						}
					}
					if (col - 1 >= 1) {
						if (visit[row][col - 1] == false) {
							q.push(make_pair(row, col - 1));
							visit[row][col - 1] = true;
							dist[row][col - 1] = dist[row][col] + 1;
							if (tmp_map[row][col - 1] == 2) {
								chicken_score += dist[row][col - 1];
								clear_q();
								break;
							}
						}
					}
					if (row + 1 <= N) {
						if (visit[row + 1][col] == false) {
							q.push(make_pair(row + 1, col));
							visit[row + 1][col] = true;
							dist[row + 1][col] = dist[row][col] + 1;
							if (tmp_map[row + 1][col] == 2) {
								chicken_score += dist[row + 1][col];
								clear_q();
								break;
							}
						}
					}
					if (col + 1 <= N) {
						if (visit[row][col + 1] == false) {
							q.push(make_pair(row, col + 1));
							visit[row][col + 1] = true;
							dist[row][col + 1] = dist[row][col] + 1;
							if (tmp_map[row][col + 1] == 2) {
								chicken_score += dist[row][col + 1];
								clear_q();
								break;
							}
						}
					}
				}
			} // while문
		}
	}
	return chicken_score;
}

void dfs(int x, int y) {
	if (depth == M) {/*
		for (int i = 1; i <= M; i++) {
			cout << p[i].first << ' ' << p[i].second << endl;
		}
		cout << "score : " << score << endl;
		cout << '\n';*/

		int score = get_chicken_distance();

		if (min_chic_dis > score) {
			min_chic_dis = score;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 2 && used[i][j] == false && i>=x) {
				if (i == x && j <= y)
					continue;
				depth++;
				used[i][j] = true;
				p[depth].first = i;
				p[depth].second = j;
				dfs(i, j);
				depth--;
				used[i][j] = false;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 0);
	cout << min_chic_dis;
}