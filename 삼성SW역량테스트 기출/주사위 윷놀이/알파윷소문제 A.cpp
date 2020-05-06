#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int save[1050000][12];
int arr[12];
int depth;
int row=1;

void dfs() {
    if (depth == 10) {
        for (int i = 1; i <= 10; i++) {
            save[row][i] = arr[i];
        }
        row++; return;
        /*for (int i = 1; i <= 10; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';*/
    }
    for (int i = 1; i <= 4; i++) {
        depth++;
        arr[depth] = i;
        dfs();
        depth--;
    }
}

int main() {
    //Please Enter Your Code Here
    int num;
    cin >> num;
    dfs();

    for (int i = 1; i <= 10; i++) {
        cout << save[num][i] << ' ';
    }

    return 0;
}