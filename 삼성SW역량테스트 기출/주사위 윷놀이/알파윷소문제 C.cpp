#include <iostream>
using namespace std;

int map[5][100] = { 
{ -1,5,10,15,20,50,30,35,40,45,100,55,60,65,70,75,80,85,90,95,500,1000},
{ -1,275,250,300,150,175,75,80,85,90,95,500,1000}, // 50 갈림길
{ -1,350,400,500,1000}, // 300 갈림길
{ -1,150,125,300,350,400,500,1000} // 100 갈림길
};

int main()
{
	int n;
	int row = 0, col = 0;
	cin >> n;
	int* dice = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> dice[i];
	}
	for (int i = 0; i < n; i++) {
		col += dice[i];
		if (map[row][col] == 1000 || map[row][col] == 0) {
			cout << "1000";
			break;
		}
		cout << map[row][col] << ' ';
		if (map[row][col] == 50) {
			row = 1;
			col = 0;
		}
		else if (map[row][col] == 300) {
			row = 2;
			col = 0;
		}
		else if (map[row][col] == 100) {
			row = 3;
			col = 0;
		}
	}
}