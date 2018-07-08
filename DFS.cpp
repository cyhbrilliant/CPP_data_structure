#include <iostream>
#include <vector>
using namespace std;

int LINK[7][7] = {
	{0, 1, 1, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}};

vector<int> FINISH;
int visit[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int i) {
	for (int j = 0; j < 7; j++) {
		if (LINK[i][j] == 1 && visit[j] == 0) {
			visit[j] = 1;
			FINISH.push_back(j);
			DFS(j);
		}
	}
}


int main() {
		
	for (int i = 0; i < 7; i++) {
		if (visit[i] == 1) {
			continue;
		}
		visit[i] = 1;
		FINISH.push_back(i);
		DFS(i);
		cout << "x" << endl;
	}
	for (vector<int>::iterator it = FINISH.begin(); it != FINISH.end(); it++) {
		cout << *it << " -> ";
	}
 
	return 0;
}