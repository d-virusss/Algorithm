#include <bits/stdc++.h>

using namespace std;

int is_there[500001];
int ans[500001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	stack<int> S;
	int topsize, topindex, num, var, max = -1;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> var;
		S.push(var);
		is_there[i + 1] = 1;
		if (var > max) {
			max = var;
			is_there[i + 1] = 0;
		} // is_there 배열의 원소값이 1이면 왼쪽에 더 높은 tower가 있음을 나타냄
	}
	topsize = S.top();
	topindex = num;
	for (int i = num; i > 0; i--) {
		if (is_there[topindex] == 0) {
			topsize = S.top();
			topindex = i;
		}
		S.pop();
		if (!S.empty()) {
			if (S.top() > topsize) {
				for (int j = topindex; j >= i; j--) {
					ans[j] = S.size();
				}
				topsize = S.top();
				topindex = S.size();
			}
			//if(S.top() > )
		}
		else {
			if (is_there[2] == 1)
				ans[2] = 1;
		}
	}
	for (int i = 0; i < num; i++) {
		cout << ans[i + 1] << ' ';
	}

	return 0;
}