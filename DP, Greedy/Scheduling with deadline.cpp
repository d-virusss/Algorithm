#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <algorithm>

using namespace std;

int set_num;
int* opt_schedule;
int* tmp_schedule;
int k = 1;

typedef struct schedule {
	int job;
	int deadline;
	int profit;
}sch;
sch* schedules;
sch* opt_order;

void set()
{
	for (int i = 0; i < set_num; i++) {
		tmp_schedule[i] = opt_schedule[i];
	}
}
bool feasible(int len)
{
	int* deadline = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) {
		deadline[i] = schedules[tmp_schedule[i]-1].deadline;
	}
	sort(deadline, deadline+len);
	for (int i = 0; i < len; i++) {
		if (deadline[i] < i + 1) {
			k--;
			return false;
		}
	}
	return true;
}
bool cmp(sch a, sch b)
{
	return a.deadline < b.deadline;
}

void set_order()
{
	opt_order = new sch[k];
	for (int i = 0; i < k; i++) {
		opt_order[i] = schedules[opt_schedule[i]-1];
	}
	sort(opt_order, opt_order + k, cmp);
}

int get_total_profit()
{
	int total = 0;
	for (int i = 0; i < k; i++) {
		total += opt_order[i].profit;
	}
	return total;
}
void print_order()
{
	for (int i = 0; i < k; i++) {
		printf(" %d", opt_order[i].job);
	}
}
int main()
{
	int total_profit=0;
	scanf("%d", &set_num);
	schedules = (sch*)malloc(sizeof(sch) * set_num);
	opt_schedule = (int*)malloc(sizeof(int) * set_num);
	tmp_schedule = (int*)malloc(sizeof(int) * set_num);
	fill(opt_schedule, opt_schedule + set_num, 0);

	for (int i = 0; i < set_num; i++) {
		scanf(" %d %d %d", &schedules[i].job, &schedules[i].deadline, &schedules[i].profit);
	}
	opt_schedule[0] = schedules[0].job;

	for (int i = 1; i < set_num; i++) {
		set();
		tmp_schedule[k++] = schedules[i].job;
		if (feasible(k))
			opt_schedule[k-1] = tmp_schedule[k-1];
	}
	set_order();
	total_profit = get_total_profit();
	printf("%d", total_profit);
	print_order();

	return 0;
}