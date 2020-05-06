#include <iostream>
using namespace std;

int map[5][100] = {
{ 0,5,10,15,20,50,30,35,40,45,100,55,60,65,70,75,80,85,90,95,500,1000},
{ 50,275,250,300,150,175,75,80,85,90,95,500,1000}, // 50 갈림길
{ 300,350,400,500,1000}, // 300 갈림길
{ 100,150,125,300,350,400,500,1000} // 100 갈림길
};
bool used[1010];

int main()
{
	int n;
	cin >> n;
	int* dice = new int[n];
	int* each_turn_mal = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> dice[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> each_turn_mal[i];
	}
	int spot[5], row[5], col[5];
	bool keep_going = true;

	fill(&spot[0], &spot[0] + 5, 0);
	fill(&row[0], row + 5, 0);
	fill(col, col + 5, 0);

	for (int i = 0; i < n; i++) {
		used[spot[each_turn_mal[i]]] = false;
		col[each_turn_mal[i]] += dice[i];
		if (map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 1000 ||
			map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 0) {
			spot[each_turn_mal[i]] = 1000;
		}
		if (used[map[row[each_turn_mal[i]]][col[each_turn_mal[i]]]] == false) {
			used[map[row[each_turn_mal[i]]][col[each_turn_mal[i]]]] = true;
			spot[each_turn_mal[i]] = map[row[each_turn_mal[i]]][col[each_turn_mal[i]]];
		}
		else {
			cout << "-1";
			keep_going = false;
			break;
		}
		// cout << map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] << ' ';
		if (map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 50) {
			row[each_turn_mal[i]] = 1;
			col[each_turn_mal[i]] = 0;
		}
		if (map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 300) {
			row[each_turn_mal[i]] = 2;
			col[each_turn_mal[i]] = 0;
		}
		if (map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 100) {
			row[each_turn_mal[i]] = 3;
			col[each_turn_mal[i]] = 0;
		}
	}
	if (keep_going == false) {
		return 0;
	}
	int score = 0;
	for (int i = 1; i <= 4; i++) {
		score += map[row[i]][col[i]];
	}
	cout << score;
}