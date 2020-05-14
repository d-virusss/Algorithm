#include <stdio.h>

double opt[103][103];
char row[103], col[103];
double gap_penalty, mismatch_penalty;
double min_penalty;

double min(double d, double v, double h)
{
	double min_val = 789789456.123;
	if (d < min_val)
		min_val = d;
	if (v < min_val)
		min_val = v;
	if (h < min_val)
		min_val = h;
	return min_val;
}

int main()
{
	int m, n;
	scanf_s("%d %d ", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf_s(" %c", &row[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf_s(" %c", &col[i]);
	}
	scanf_s(" %lf", &gap_penalty);
	scanf_s(" %lf", &mismatch_penalty);
	for (int i = m; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			if (i >= m)
				opt[i][j] = gap_penalty * (n - j);
			else if (j >= n)
				opt[i][j] = gap_penalty * (m - i);
			else {
				if(row[i] == col[j])
					opt[i][j] = min(opt[i + 1][j + 1], opt[i + 1][j]+gap_penalty, opt[i][j + 1]+gap_penalty);
				else
					opt[i][j] = min(opt[i + 1][j + 1]+mismatch_penalty, opt[i + 1][j]+gap_penalty, opt[i][j + 1]+gap_penalty);
			}
		}
	}
	min_penalty = opt[0][0];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%5.1lf", opt[i][j]);
		}
		printf("\n");
	}
	printf("%.1lf", min_penalty);

	return 0;
}