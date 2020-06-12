#include <iostream>
#include <queue>

using namespace std;

int n;
int weight_matrix[16][16];
int min_length;

typedef struct {
	int level;
	int path[16];
	int bound;
}node;

struct cmp
{
	bool operator()(node &a, node &b) {
		return a.bound > b.bound;
	}
};

void input_matrix() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> weight_matrix[i][j];
		}
	}
	return;
}

int bound(int node) { // 한계값 구하는 함수

}

int get_length() { // 경로를 알 때 이동길이구하는 함수

}


void TSP() {
	priority_queue <node, vector<node>, cmp > pq;

}

int main()
{
	cin >> n;
	input_matrix();
	TSP();

	return 0;
}