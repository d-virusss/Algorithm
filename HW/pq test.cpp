#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int level;
	int path[16];
	int bound;
}node;

struct cmp
{
	bool operator()(node& a, node& b) {
		return a.bound > b.bound;
	}
};

int main()
{
	priority_queue<node, vector<node>, cmp> pq;

	node a, b, c, d, e;
	a.bound = 10;
	b.bound = 2;
	c.bound = 4;
	d.bound = 13;
	e.bound = 11;
	pq.push(a);
	pq.push(b);
	pq.push(c);
	pq.push(d);
	pq.push(e);


	while(!pq.empty() ){
		cout << pq.top().bound << '\n';
		pq.pop();
	}

	return 0;
}