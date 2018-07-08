#include <iostream>
#include <vector>
using namespace std;
#define NO 100000


int LINK[4][4] = {
	{0, 1, NO, 4},
	{NO, 0, 9, 2},
	{3, 5, 0, 8},
	{NO, NO, 6, 0}};
int dist[4][4];

void UpdateDist(int node) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (LINK[i][node]+LINK[node][j] < LINK[i][j]) {
				LINK[i][j] = LINK[i][node]+LINK[node][j];
			}
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		UpdateDist(i);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
				cout << LINK[i][j] << " "; 
		}
		cout << endl;
	}

	return 0;
}
