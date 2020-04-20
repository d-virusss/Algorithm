#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int num_of_tower;
	int tower_height;
	stack<pair<int, int> > S;
	cin >> num_of_tower;
	for (int i = 1; i < num_of_tower+1; i++) {
		cin >> tower_height;
		while (!S.empty()) {
			if (S.top().second > tower_height) {
				cout << S.top().first << ' ';
				S.push(make_pair(i, tower_height));
				break;
			}
			else {
				S.pop();
			}
		}
		if (S.empty()) {
			S.push(make_pair(i, tower_height));
			cout << 0 << ' ';
		}
	}
}