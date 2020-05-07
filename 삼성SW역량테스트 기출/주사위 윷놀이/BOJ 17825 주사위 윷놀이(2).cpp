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
int dice[11];
int max_score = -1000000;
int which_move[11];

int depth;
int arr[11]; // [1] ���� ����


void cal_score() {
	int score = 0;
	int row[5], col[5];
	fill(row, row + 5, 0);
	fill(col, col + 5, 0);
	int spot[5][2]; // ���� ��ġ ���� �ϴ� �迭 
	//row_index�� � �������� ǥ���ϰ� col_index�� ���� ���� ��ġ�� row, col��ǥ�̴�.
	memset(spot, 0, sizeof(spot));
	memset(used, false, sizeof(used));

	int row2_hval = 2;
	int row3_hval = 3;

	for (int i = 1; i <= 10; i++) {
		used[spot[which_move[i]][0]][spot[which_move[i]][1]] = false;
		if (map[spot[which_move[i]][0]][spot[which_move[i]][1]] == 40) {
			used[0][20] = false;
			used[1][7] = false;
		}
		if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // �̹� ������ ���� ��� pass
			return;
		}

		if (row[which_move[i]] == 2) { // row�� 2�� ��
			if (dice[i] > row2_hval) { // ���� ���� row2�� ��� ��
				row[which_move[i]] = 1;
				col[which_move[i]] += 3 + dice[i] - row2_hval;
			}
			else {// ������ �۾Ƽ� row2�������� ���� ��
				col[which_move[i]] += dice[i];
			}
		}
		else if(row[which_move[i]] == 3){ // row == 3 �� ��
			if (dice[i] > row3_hval) { // ���� ū ��� row �̵�
				row[which_move[i]] = 1;
				col[which_move[i]] += 3 + dice[i] - row3_hval;
			}
			else { // ������ ���� ��� �ش� row������ �̵�
				col[which_move[i]] += dice[i];
			}
		}
		else {
			col[which_move[i]] += dice[i];
		}

		if (used[row[which_move[i]]][col[which_move[i]]])
			return; // �� �ڸ��� ���� �̹� �����ϸ� �Լ� ����
		if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // �������� ���
			row[which_move[i]] = 0;
			col[which_move[i]] = 22;
			continue;
		}
		if (map[row[which_move[i]]][col[which_move[i]]] == 40) {
			used[0][20] = true;
			used[1][7] = true;
		}
		used[row[which_move[i]]][col[which_move[i]]] = true;
		spot[which_move[i]][0] = row[which_move[i]];
		spot[which_move[i]][1] = col[which_move[i]];

		if (map[row[which_move[i]]][col[which_move[i]]] == 10) { // 1�� ������
			row[which_move[i]] = 1;
			col[which_move[i]] = 0;
		}
		else if (map[row[which_move[i]]][col[which_move[i]]] == 20) { // 2�� ������
			row[which_move[i]] = 2;
			col[which_move[i]] = 0;
		}
		else if (map[row[which_move[i]]][col[which_move[i]]] == 30
			&& row[which_move[i]] == 0) { // 3�� ������
			row[which_move[i]] = 3;
			col[which_move[i]] = 0;
		}
		score += map[row[which_move[i]]][col[which_move[i]]]; // ���� ����ִ� ��ġ�� ���� �ջ�
	}
	if (score > max_score) {
		max_score = score;
		/*for (int i = 1; i <= 10; i++) {
			cout << which_move[i] << ' ';
		}
		cout << "score : " << max_score << '\n';*/
	}
}

void dfs() {
	if (depth == 10) {
		for (int i = 1; i <= 10; i++) {
			which_move[i] = arr[i];
		}
		cal_score();
		return;
	}
	for (int i = 1; i <= 4; i++) {
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

	for (int i = 1; i <= 10; i++) {
		cin >> dice[i];
	}
	dfs();
	cout << max_score;
}