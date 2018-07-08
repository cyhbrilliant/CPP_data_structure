#include <iostream>
#include <vector>
using namespace std;
#define NO 100000


int LINK[6][6] = {
	{NO, NO, 4, 28, NO, NO},
	{2, NO, NO, NO, 10, NO},
	{NO, 15, NO, NO, NO, 8},
	{NO, NO, NO, NO, NO, NO},
	{NO, NO, NO, 4, NO, NO},
	{NO, NO, NO, 13, 18, NO}};

int dist[6] = {NO, NO, NO, NO, NO, NO};
int distU[6] = {LINK[0][0], LINK[0][1], LINK[0][2], LINK[0][3], LINK[0][4], LINK[0][5]};
void UpdateDist(int node) {
	for (int i = 1; i < 6; i++) {
		if (distU[node]+LINK[node][i] < distU[i]) {
			distU[i] = distU[node]+LINK[node][i];
		}
	}
	dist[node] = distU[node];
	distU[node] = NO;
}

int ChooseNode() {
	int node = 0;
	int d = NO;
	for (int i = 1; i < 6; i++) {
		if (distU[i] < d) {
			node = i;
			d = distU[i];
		}
	}
	return node;
}

int main() {
	for (int i = 1; i < 6; i++) {
		UpdateDist(ChooseNode());
	}
	for (int i = 1; i < 6; i++) {
		cout << dist[i] << " ";
	}

}
