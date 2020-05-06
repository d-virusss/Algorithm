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
	int dice[11];
	int each_turn_mal[11];
	int* score = new int[n];
	int max_score = -1;

	fill(&score[0], score + n, 0);

	for (int j = 0; j < n; j++) {

		for (int i = 0; i < 10; i++) {
			cin >> dice[i];
		}
		for (int i = 0; i < 10; i++) {
			cin >> each_turn_mal[i];
		}
		int spot[5], row[5], col[5];
		bool keep_going = true;

		fill(&spot[0], &spot[0] + 5, 0);
		fill(&row[0], row + 5, 0);
		fill(col, col + 5, 0);
		fill(used, used + 1010, false);

		for (int i = 0; i < 10; i++) {
			used[spot[each_turn_mal[i]]] = false;
			col[each_turn_mal[i]] += dice[i];
			if (map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 1000 ||
				map[row[each_turn_mal[i]]][col[each_turn_mal[i]]] == 0) {
				spot[each_turn_mal[i]] = 1000;
				continue;
			}
			if (used[map[row[each_turn_mal[i]]][col[each_turn_mal[i]]]] == false) {
				used[map[row[each_turn_mal[i]]][col[each_turn_mal[i]]]] = true;
				spot[each_turn_mal[i]] = map[row[each_turn_mal[i]]][col[each_turn_mal[i]]];
			}
			else {
				score[j] = -1;
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
			continue;
		}
		for (int i = 0; i < 4; i++) {
			score[j] += spot[i+1];
		}
		if (score[j] > max_score) {
			max_score = score[j];
		}
	}

	cout << max_score;
}