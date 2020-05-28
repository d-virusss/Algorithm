#include <stdio.h>
#include <stdlib.h>

double opt[103][103];
char row[103], col[103];
char route[104];
double gap_penalty, mismatch_penalty;
double min_penalty;
int m, n;
char p_row[103], p_col[103];

void get_route()
{
	int x = 0, y = 0;
	int k = 0;
	if (m >= n) {
		while (1)
		{
			if ((x == m) && (y == n)) break;
			if (row[x] == col[y]) {
				if (opt[x][y] == (opt[x + 1][y + 1])) {
					x++, y++, route[k++] = 'm';
				}
				else if ((opt[x][y] == (opt[x + 1][y] + gap_penalty)) && (x < m)) {
					x++, route[k++] = 'd';
				}
				else {
					y++, route[k++] = 'r';
				}
			}
			else {
				if (opt[x][y] == (opt[x + 1][y + 1] + mismatch_penalty)) {
					x++, y++, route[k++] = 'm';
				}
				else if ((opt[x][y] == (opt[x + 1][y] + gap_penalty)) && (x < m)) {
					x++, route[k++] = 'd';
				}
				else {
					y++, route[k++] = 'r';
				}
			}
		}
	}
	else {
		while (1)
		{
			if ((x == m) && (y == n)) break;
			if (row[x] == col[y]) {
				if (opt[x][y] == (opt[x + 1][y + 1])) {
					x++, y++, route[k++] = 'm';
				}
				else if ((opt[x][y] == (opt[x][y + 1] + gap_penalty)) && (y < n) ) {
					y++, route[k++] = 'r';
				}
				else {
					x++, route[k++] = 'd';
				}
			}
			else {
				if (opt[x][y] == (opt[x + 1][y + 1] + mismatch_penalty)) {
					x++, y++, route[k++] = 'm';
				}
				else if ((opt[x][y] == (opt[x][y + 1] + gap_penalty)) && (y < n)) {
					y++, route[k++] = 'r';
				}
				else {
					x++, route[k++] = 'd';
				}
			}
		}
	}
}

void get_alignment()
{
	int k = 0;
	int x = 0, y = 0;
	while (route[k] != 0)
	{
		if (route[k] == 'm') {
			p_row[k] = row[x];
			p_col[k] = col[y];
			x++, y++, k++;
		}
		else if (route[k] == 'd') {
			p_row[k] = row[x];
			p_col[k] = '-';
			x++; k++;
		}
		else if (route[k] == 'r') {
			p_row[k] = '-';
			p_col[k] = col[y];
			y++, k++;
		}
	}
}

double get_min(double d, double v, double h)
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
	scanf("%d %d ", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf(" %c", &row[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf(" %c", &col[i]);
	}
	scanf(" %lf", &gap_penalty);
	scanf(" %lf", &mismatch_penalty);
	for (int i = m; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			if (i >= m)
				opt[i][j] = gap_penalty * (n - j);
			else if (j >= n)
				opt[i][j] = gap_penalty * (m - i);
			else {
				if (row[i] == col[j])
					opt[i][j] = get_min(opt[i + 1][j + 1], opt[i + 1][j] + gap_penalty, opt[i][j + 1] + gap_penalty);
				else
					opt[i][j] = get_min(opt[i + 1][j + 1] + mismatch_penalty, opt[i + 1][j] + gap_penalty, opt[i][j + 1] + gap_penalty);
			}
		}
	}
	min_penalty = opt[0][0];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%3.0lf", opt[i][j]);
		}
		printf("\n");
	}

	get_route();
	get_alignment();
	printf("%.1lf ", min_penalty);
	printf("%s ", route);
	printf("%s ", p_row);
	printf("%s", p_col);

	return 0;
}