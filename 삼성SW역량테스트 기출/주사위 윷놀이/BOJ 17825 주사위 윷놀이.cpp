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

int save[1050000][11]; // [][1] ���� ����
int dice[11];
int max_score = -1000000;
int which_move[11];

int depth;
int arr[11]; // [1] ���� ����
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
		if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // �̹� ������ ���� ��� pass
			continue;
		}
		if (row[which_move[i]] >= 2) { // row�� 2 �̻��� ��
			if (row[which_move[i]] == 2) { // row�� 2�� ��
				if (dice[i] > row2_hval) { // ���� ���� row2�� ��� ��
					row[which_move[i]] = 1;
					col[which_move[i]] += 3 + dice[i] - row2_hval;
					if (used[row[which_move[i]]][col[which_move[i]]])
						return; // �� �ڸ��� ���� �̹� �����ϸ� �Լ� ����
					if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // �������� ���
						spot[which_move[i]][0] = 0; // end �ڸ��� ��ġ ���� �� ���� ���� �ݺ�������
						spot[which_move[i]][1] = 22;
						continue;
					}
					used[row[which_move[i]]][col[which_move[i]]] = true;
					// ���� X �̰� �� �ڸ��� �� ��� �� �̵�
				}
				else {// ������ �۾Ƽ� row2�������� ���� ��
					col[which_move[i]] += dice[i];
					if (used[row[which_move[i]]][col[which_move[i]]]) // �� ��ġ�� �� �̹� �������
						return;

					used[row[which_move[i]]][col[which_move[i]]] = true; // �� �ڸ� �� ��� �� �̵�
				}
			}
			else { // row == 3 �� ��
				if (dice[i] > row3_hval) { // ���� ū ��� row �̵�
					row[which_move[i]] = 1;
					col[which_move[i]] += 3 + dice[i] - row3_hval;
					if (used[row[which_move[i]]][col[which_move[i]]]) // ���̹� �ִ� ��� Ż��
						return;

					if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // �������� ���
						spot[which_move[i]][0] = 0;
						spot[which_move[i]][1] = 22;
						continue;
					}
					used[row[which_move[i]]][col[which_move[i]]] = true;
					// �������� �ƴϰ� �� ���°�� �� �ش���ġ�� �̵�
				}
				else { // ������ ���� ��� �ش� row������ �̵�
					col[which_move[i]] += dice[i];
					if (used[row[which_move[i]]][col[which_move[i]]])
						return;

					used[row[which_move[i]]][col[which_move[i]]] = true;
				}
			}
			spot[which_move[i]][0] = row[which_move[i]];
			spot[which_move[i]][1] = col[which_move[i]];
		}
		else { // row�� 0 Ȥ�� 1 �� ��
			col[which_move[i]] += dice[i];
			if (used[row[which_move[i]]][col[which_move[i]]]) // �̹� �ش���ġ�� �������� Ż��
				return;

			if (map[row[which_move[i]]][col[which_move[i]]] == 0) { // �������� ���
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
			// �ش���ġ ����ְ� �������� �ƴ� ��� �� �̵��ϰ� ��ġ ����

			if (map[row[which_move[i]]][col[which_move[i]]] == 10) { // 1�� ������
				row[which_move[i]] = 1;
				col[which_move[i]] = 0;
			}
			else if (map[row[which_move[i]]][col[which_move[i]]] == 20) { // 2�� ������
				row[which_move[i]] = 2;
				col[which_move[i]] = 0;
			}
			else if (map[row[which_move[i]]][col[which_move[i]]] == 30 &&
				row[which_move[i]] == 0) { // 3�� ������
				row[which_move[i]] = 3;
				col[which_move[i]] = 0;
			}
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