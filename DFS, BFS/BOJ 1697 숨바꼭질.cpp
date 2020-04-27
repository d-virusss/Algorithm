#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int dist[100010];
bool check[100010];
int main()
{
	queue<int> Q;
	int N, K;
	cin >> N >> K;
	Q.push(N);
	dist[N] = 0;
	check[N] = true;
	while (!Q.empty()) {
		int x;
		x = Q.front();
		Q.pop();
		if (x - 1 >= 0) {
			if (!check[x-1]) {
				Q.push(x - 1);
				check[x - 1] = 1;
				dist[x - 1] = dist[x] + 1;
				if ((x - 1) == K)
					break;
			}
		}
		if (x + 1 <= 100000) {
			if (!check[x+1]) {
				Q.push(x + 1);
				check[x + 1] = 1;
				dist[x + 1] = dist[x] + 1;
				if ((x + 1) == K)
					break;
			}
		}
		if (x * 2 <= 100000) {
			if (!check[x*2]) {
				Q.push(x * 2);
				check[x * 2] = 1;
				dist[2 * x] = dist[x] + 1;
				if ((x * 2) == K)
					break;
			}
		}
	}

	cout << dist[K];
	
	return 0;
}