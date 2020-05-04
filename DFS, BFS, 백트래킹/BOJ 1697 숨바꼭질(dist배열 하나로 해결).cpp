#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int dist[100010];
int main()
{
	fill(dist, dist + 100010, -1);
	queue<int> Q;
	int N, K;
	cin >> N >> K;
	Q.push(N);
	dist[N] = 0;
	while (!Q.empty()) {
		int x;
		x = Q.front();
		Q.pop();
		if (x - 1 >= 0) {
			if (dist[x-1] == -1) {
				Q.push(x - 1);
				dist[x - 1] = dist[x] + 1;
				if ((x - 1) == K)
					break;
			}
		}
		if (x + 1 <= 100000) {
			if (dist[x+1] == -1) {
				Q.push(x + 1);
				dist[x + 1] = dist[x] + 1;
				if ((x + 1) == K)
					break;
			}
		}
		if (x * 2 <= 100000) {
			if (dist[x*2] == -1) {
				Q.push(x * 2);
				dist[2 * x] = dist[x] + 1;
				if ((x * 2) == K)
					break;
			}
		}
	}

	cout << dist[K];
	
	return 0;
}