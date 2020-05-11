#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int  T, N, M;
int map[12][12];
vector<int> faucet;
vector<int> dir;
bool cleand[12][12];

int depth;

int min_uncleaned;

void shoot_water(int row, int col, int shoot_dir) {
	int tmp_row = row;
	int tmp_col = col;
	if (map[row][col] == 1) {
		if (shoot_dir == 1) {
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
		}
		else if (shoot_dir == 2) {
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
		}
		else if (shoot_dir == 3) {
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
		}
		else if (shoot_dir == 4) {
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
		}
	}
	else if (map[row][col] == 2) {
		if (shoot_dir == 1) {
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
		}
		else if (shoot_dir == 2) {
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
		}
	}
	else if (map[row][col] == 3) {
		if (shoot_dir == 1) {
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
		}
		else if (shoot_dir == 2) {
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
		}
		else if (shoot_dir == 3) {
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
		}
		else if (shoot_dir == 4) {
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
		}
	}
	else if (map[row][col] == 4) {
		if (shoot_dir == 1) {
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
		}
		else if (shoot_dir == 2) {
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
		}
		else if (shoot_dir == 3) {
			while (1) {
				if (col + 1 > M || map[row][col + 1] == 6)
					break;
				cleand[row][++col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
		}
		else if (shoot_dir == 4) {
			while (1) {
				if (row + 1 > N || map[row + 1][col] == 6)
					break;
				cleand[++row][col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (col - 1 == 0 || map[row][col - 1] == 6)
					break;
				cleand[row][--col] = true;
			}
			row = tmp_row;
			col = tmp_col;
			while (1) {
				if (row - 1 == 0 || map[row - 1][col] == 6)
					break;
				cleand[--row][col] = true;
			}
		}
	}
	else if (map[row][col] == 5) {
		while (1) {
			if (row - 1 == 0 || map[row - 1][col] == 6)
				break;
			cleand[--row][col] = true;
		}
		row = tmp_row;
		col = tmp_col;
		while (1) {
			if (col + 1 > M || map[row][col + 1] == 6)
				break;
			cleand[row][++col] = true;
		}
		row = tmp_row;
		col = tmp_col;
		while (1) {
			if (row + 1 > N || map[row + 1][col] == 6)
				break;
			cleand[++row][col] = true;
		}
		row = tmp_row;
		col = tmp_col;
		while (1) {
			if (col - 1 == 0 || map[row][col - 1] == 6)
				break;
			cleand[row][--col] = true;
		}
	}
}
int cleaing_start() {
	memset(cleand, 0, sizeof(cleand));
	int k = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != 6 && map[i][j] != 0 && map[i][j] != 5) { // 수도꼭지 일때
				shoot_water(i, j, dir[k]);
				k++;
			}
			else if (map[i][j] == 5) {
				shoot_water(i, j, 5);
			}
		}
	}
	int uncleaned = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0 && cleand[i][j] == false)
				uncleaned++;
		}
	}
	return uncleaned;
}
void dfs() {
	if (depth == faucet.size()) {
		int score =	cleaing_start();
		/*for (int i = 0; i < dir.size(); i++) {
			cout << dir[i] << ' ';
		}
		cout << '\n';*/
		min_uncleaned = min(score, min_uncleaned);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (faucet[depth] == 2 && i > 2) continue;
		depth++;
		dir[depth - 1] = i;
		dfs();
		depth--;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N >> M;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
				if (map[i][j] != 6 && map[i][j] != 0 && map[i][j] != 5) {
					faucet.push_back(map[i][j]);
				}
			}
		}
		/*cout << faucet.size() << '\n';
		for (int i = 0; i < faucet.size(); i++) {
			cout << faucet[i] << '\n';
		}
		cout << '\n';*/
		dir.resize(faucet.size());
		min_uncleaned = 987987987;
		dfs();

		cout << "#" << k+1 << ' ' << min_uncleaned << '\n';
	}
}