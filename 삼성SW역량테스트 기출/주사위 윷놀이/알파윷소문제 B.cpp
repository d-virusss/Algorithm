#include <iostream>

using namespace std;

int map[55] = { 0,
5, 10,15,20,50,
30,35,40,45,100,
55,60,65,70,75,
80,85,90,95,500,
1000 }; // 22개의 원소 map[21]이 마지막

int main()
{
	int n, spot = 0;
	cin >> n;
	int* dice = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> dice[i];
	}
	for (int i = 0; i < n; i++) {
		if (spot >= 21) break;
		spot += dice[i];
		if (spot >= 21) {
			cout << "1000";
			break;
		}
		cout << map[spot] << ' ';
	}

}