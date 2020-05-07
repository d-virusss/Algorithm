#include <iostream>
#include <cstring>
using namespace std;

int map[4][30] = {
	{-1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
	{10,13,16,19,25,30,35,40}, // [1][4] = 25
	{20,22,24}, // [2][3] = 25
	{30,28,27,26} // [3][4] = 25
};
bool used[4][30];

int save[1050000][11]; // [][1] 부터 시작
int dice[11];
int max_score = -1000000;
int which_move[11];

int depth;
int arr[11]; // [1] 부터 시작
int count_save;

void dfs() {
	if (depth == 10) {
		for (int i = 1; i <= 10; i++) {
			save[count_save][i] = arr[i];
		}
		count_save++; return;
	}
	for (int i = 1; i <= 4; i++) {
		depth++;
		arr[depth] = i;
		dfs();
		depth--;
	}
}
void cal_score(int turn) {
	int score = 0;
	int row[5], col[5];
	fill(row, row + 5, 0);
	fill(col, col + 5, 0);
	int spot[5][2];
	memset(spot, 0, sizeof(spot));
	memset(used, false, sizeof(used));
	int row2_hval = 2;
	int row3_hval = 3;

	for (int i = 1; i <= 10; i++) {
		which_move[i] = save[turn][i];
	}
	for (int i = 1; i <= 10; i++) {
		if (map[spot[which_move[i]][0]][spot[which_move[i]][1]] == 40) {
			used[0][20] = false;
			used[1][7] = false;
		}
		used[spot[which_move[i]][0]][spot[which_move[i]][1]] = false;
		if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // 이미 도착한 말일 경우 pass
			continue;
		}
		if (row[which_move[i]] >= 2) { // row가 2 이상일 때
			if (row[which_move[i]] == 2) { // row가 2일 때
				if (dice[i] > row2_hval) { // 눈금 값이 row2를 벗어날 때
					row[which_move[i]] = 1;
					col[which_move[i]] += 3 + dice[i] - row2_hval;
					if (used[row[which_move[i]]][col[which_move[i]]])
						return; // 갈 자리에 말이 이미 존재하면 함수 종료
					if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // 도착했을 경우
						spot[which_move[i]][0] = 0; // end 자리로 위치 갱신 후 다음 차례 반복문으로
						spot[which_move[i]][1] = 22;
						continue;
					}
					used[row[which_move[i]]][col[which_move[i]]] = true;
					// 도착 X 이고 갈 자리도 빈 경우 말 이동
				}
				else {// 눈금이 작아서 row2범위내에 있을 때
					col[which_move[i]] += dice[i];
					if (used[row[which_move[i]]][col[which_move[i]]]) // 갈 위치에 말 이미 있을경우
						return;

					used[row[which_move[i]]][col[which_move[i]]] = true; // 갈 자리 빈 경우 말 이동
				}
			}
			else { // row == 3 일 때
				if (dice[i] > row3_hval) { // 눈금 큰 경우 row 이동
					row[which_move[i]] = 1;
					col[which_move[i]] += 3 + dice[i] - row3_hval;
					if (used[row[which_move[i]]][col[which_move[i]]]) // 말이미 있는 경우 탈출
						return;

					if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // 도착점인 경우
						spot[which_move[i]][0] = 0;
						spot[which_move[i]][1] = 22;
						continue;
					}
					used[row[which_move[i]]][col[which_move[i]]] = true;
					// 도착점도 아니고 말 없는경우 말 해당위치로 이동
				}
				else { // 눈금이 작은 경우 해당 row내에서 이동
					col[which_move[i]] += dice[i];
					if (used[row[which_move[i]]][col[which_move[i]]])
						return;

					used[row[which_move[i]]][col[which_move[i]]] = true;
				}
			}
			spot[which_move[i]][0] = row[which_move[i]];
			spot[which_move[i]][1] = col[which_move[i]];
		}
		else { // row가 0 혹은 1 일 때
			col[which_move[i]] += dice[i];
			if (used[row[which_move[i]]][col[which_move[i]]]) // 이미 해당위치에 말있으면 탈출
				return;

			if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // 도착점인 경우
				spot[which_move[i]][0] = 0;
				spot[which_move[i]][1] = 22;
				continue;
			}
			if (map[row[which_move[i]]][col[which_move[i]]] == 40) {
				used[0][20] = true;
				used[1][7] = true;
			}
			used[row[which_move[i]]][col[which_move[i]]] = true;
			spot[which_move[i]][0] = row[which_move[i]];
			spot[which_move[i]][1] = col[which_move[i]];
			// 해당위치 비어있고 도착점도 아닌 경우 말 이동하고 위치 갱신

			if (map[row[which_move[i]]][col[which_move[i]]] == 10) { // 1번 교차로
				row[which_move[i]] = 1;
				col[which_move[i]] = 0;
			}
			else if (map[row[which_move[i]]][col[which_move[i]]] == 20) { // 2번 교차로
				row[which_move[i]] = 2;
				col[which_move[i]] = 0;
			}
			else if (map[row[which_move[i]]][col[which_move[i]]] == 30 &&
				row[which_move[i]] == 0) { // 3번 교차로
				row[which_move[i]] = 3;
				col[which_move[i]] = 0;
			}
		}
		score += map[row[which_move[i]]][col[which_move[i]]]; // 말이 밟고있는 위치의 점수 합산
	}
	if (score > max_score) {
		max_score = score;
		/*for (int i = 1; i <= 10; i++) {
			cout << which_move[i] << ' ';
		}
		cout << "score : " << max_score << '\n';*/
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 10; i++) {
		cin >> dice[i];
	}
	dfs(); //
	for (int i = 0; i < 1050000; i++) {
		if (save[i][1] == 0)
			break;
		cal_score(i);
	}

	cout << max_score;
}