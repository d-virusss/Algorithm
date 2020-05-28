#include <stdio.h>
#include <stdlib.h>

double A[102][102];
int R[102][102];

typedef struct node{
	struct node* left;
	int data;
	struct node* right;
}node;

node* tree(int row, int col) {
	int k = R[row][col];
	if (k == 0)
		return NULL;
	else {
		node* p= (node*)malloc(sizeof(node));
		p->data = k;
		p->left = tree(row, k-1);
		p->right = tree(k + 1, col);
		return p;
	}
}
void preorder(node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

double get_minimum(int row, int col)
{
	double min = 12312.123;
	int moving_col = row - 1;
	int moving_row = row + 1;
	double tmp;
	for (int i = 0; i <= col - row; i++) {
		tmp = A[row][moving_col++] + A[moving_row++][col];
		if (tmp < min) {
			min = tmp;
			R[row][col] = row + i;
		}
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

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &A[i][i]);
		R[i][i] = i;
	}

	for (int dgnl = 1; dgnl <= n - 1; dgnl++) {
		for (int row = 1; row <= n - dgnl; row++) {
			int col = row + dgnl;
			A[row][col] = get_minimum(row, col);
		}
	}

	node* root = tree(1, n);
	minavg = A[1][n];
	
	printf("%.3lf ", minavg);
	preorder(root);

	return 0;
}