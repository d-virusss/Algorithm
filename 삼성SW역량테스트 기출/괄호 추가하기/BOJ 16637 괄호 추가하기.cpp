#include <bits/stdc++.h>

using namespace std;

int cal(int a, char b, int c) {
	int result;
	switch (b) {
	case '+':
		result = (a) + (c);
		break;
	case '-':
		result = (a) - (c);
		break;
	case '*':
		result = (a) * (c);
		break;
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int len;
	cin >> len;
	char input[20];
	int s[20] = { 0, };
	int result;
	int tmp;
	for (int i = 1; i < len+1; i++) {
		cin >> input[i];
	}
	for (int i = 1; i < len + 1; i++) {
		s[i] = input[i];
	}
	char fir, sec;
	int a, b, c;
	char check = 0; // 1이면 뒤 연산부터 계산한다는 의미
	if (len > 5) {
		for (int i = 1; i < len-5; i += 2) {
			a = s[i];
			fir = s[i + 1];
			b = s[i + 2];
			sec = s[i + 3];
			c = s[i + 4];
			if (check == 1) {
				s[i + 2] = cal(s[i] - 48, s[i + 1], s[i + 2] - 48);
				s[i + 2] += 48;
				check = 0;
				continue;
			}
			if (fir == '-' && sec == '*' && c == '0')
				check = 1; // 뒤 연산에 괄호친다는 의미
			else if (fir == '*' && sec == '+' && a > '1' && c != '0')
				check = 1;
			else if (fir == '-' && sec == '-' && b < c)
				check = 1;
			if (check == 0) {
				s[i + 2] = cal(s[i]-48, s[i + 1], s[i + 2]-48);
				s[i + 2] += 48;
			}
			else if (check == 1) {
				s[i + 4] = cal(s[i + 2]-48, s[i + 3], s[i + 4]-48);
				s[i + 4] += 48;
				s[i + 3] = s[i + 1];
				s[i + 2] = s[i];
			}
		}
	}
	if (len >= 5) {
		if (check == 1) {
			result = cal(cal(s[len - 4] - 48, s[len - 3], s[len - 2] - 48), s[len - 1], s[len] - 48);
		}
		else if (check == 0) {
			if ((s[len - 3] == '-' && s[len - 1] == '*' && s[len] - 48 == 0) ||
				(s[len - 3] == '*' && s[len - 1] == '+') ||
				(s[len - 3] == '-' && s[len - 1] == '-' && s[len - 2] < s[len])) {
				check = 1;
			}
			if (check == 1) {
				tmp = cal(s[len - 2] - 48, s[len - 1], s[len] - 48);
				result = cal(s[len - 4] - 48, s[len - 3], tmp);
			}
			else if (check == 0) {
				result = cal(cal(s[len - 4] - 48, s[len - 3], s[len - 2] - 48), s[len - 1], s[len] - 48);
			}
		}
	}
	else if(len == 1)
		result = s[1]-48;
	else if (len == 3)
		result = cal(s[1]-48, s[2], s[3]-48);

	cout << result;

	return 0;

}