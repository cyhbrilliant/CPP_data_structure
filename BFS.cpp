#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int LINK[7][7] = {
	{0, 1, 1, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0}};

deque<int> LIST;
vector<int> FINISH;
int visit[7] = {0, 0, 0, 0, 0, 0, 0};

void BFS(int i) {
	for (int j = 0; j < 7; j++) {
		if (LINK[i][j] == 1 && visit[j] == 0) {
			visit[j] = 1;
			FINISH.push_back(j);
			LIST.push_back(j);
		}
	}
	while (!LIST.empty()) {
		int index = LIST.front();
		LIST.pop_front();
		BFS(index);
	}
}
		

int main() {
	for (int i = 0; i < 7; i++) {
		if (visit[i] == 1) {
			continue;
		}
		visit[i] = 1;
		FINISH.push_back(i);
		BFS(i);
	
	}
	for (vector<int>::iterator it = FINISH.begin(); it != FINISH.end(); it++) {
		cout << *it << " -> ";
	}
	return 0;
}