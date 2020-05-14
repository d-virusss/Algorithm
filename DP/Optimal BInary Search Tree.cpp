#include <stdio.h>

double A[102][102];

double get_minimum(int row, int col)
{
	double min = 12312.123;
	int moving_col = row - 1;
	int moving_row = row + 1;
	double tmp;
	for (int i = 0; i <= col - row; i++) {
		tmp = A[row][moving_col++] + A[moving_row++][col];
		if (tmp < min)
			min = tmp;
	}
	for (int i = row; i <= col; i++) {
		min += A[i][i];
	}
	return min;
}

int main()
{
	int n;
	double minavg;

	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%lf", &A[i][i]);
	}

	for (int dgnl = 1; dgnl <= n - 1; dgnl++) {
		for (int row = 1; row <= n - dgnl; row++) {
			int col = row + dgnl;
			A[row][col] = get_minimum(row, col);
		}
	}
	minavg = A[1][n];

	printf("%.3lf", minavg);
	return 0;
}