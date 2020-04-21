#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	vector<int> v;
	int set_num;

	cin >> set_num;
	for (int i = 0; i < set_num; i++) {
		string func, arr_str;
		int arr_size;
		int num;
		v.clear();
		int R_check = 0;
		bool err_check = false;
		cin >> func; // 함수 뭐 부를지 입력 받음
		cin >> arr_size;
		if (arr_size == 0) {
			cin >> arr_str;
		}
		else {
			for (int j = 0; j < arr_size; j++) {
				if (j == 0)
					cin.ignore(10, '\n');
				if (j < arr_size - 1)
					getline(cin, arr_str, ',');
				else
					getline(cin, arr_str, ']');
				arr_str[0] = ' ';
				num = stoi(arr_str);
				v.push_back(num);
			}
		}
		for (auto k : func) {
			if (k == 'R') {
				R_check++;
			}
			else if (k == 'D') {
				vector<int>::iterator iter = v.begin();
				vector<int>::reverse_iterator r_iter = v.rbegin();
				if (v.begin() == v.end()) {
					err_check = true;
					break;
				}
				if (R_check % 2 == 0) {
					iter = v.erase(iter);
				}//앞에서부터 제거
				else if (R_check % 2 == 1) {
					v.erase((r_iter + 1).base());
					r_iter = v.rbegin();
				}
			}
		}
		if (err_check == true) {
			cout << "error\n";
		}
		else if (v.begin() == v.end() && arr_size ==0)
			cout << "[]\n";
		else {
			if (R_check % 2 == 0) {
				cout << '[';
				for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
					if (it == v.end() - 1)
						cout << *it;
					else
						cout << *it << ',';
				}
				cout << ']';
			}
			else {
				cout << '[';
				for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++) {
					if (rit == v.rend() - 1)
						cout << *rit;
					else
						cout << *rit << ',';
				}
				cout << "]\n";
			}
		}
	}

	return 0;
}