#include <iostream>
#include <vector>
using namespace std;
#define NO 100000

int LINK[7][7] = {
	{NO, 6, NO, 2, 6, NO, NO},
	{6, NO, 4, NO, NO, NO, NO},
	{NO, 4, NO, 10, NO, 5, NO},
	{2, NO, 10, NO, 8, 1, NO},
	{6, NO, NO, 8, NO, 3, 5},
	{NO, NO, 5, 1, 3, NO, 3},
	{NO, NO, NO, NO, 5, 3, NO}};

int Comp[7] = {0, 1, 2, 3, 4, 5, 6};
void UpdateComp(int X, int Y) {
	int CompX = Comp[X];
	int CompY = Comp[Y];
	for (int i = 0; i < 7; i++) {
		if (Comp[i] == CompY) {
			Comp[i] = CompX;
		}
	}
}

void FindNext() {
	int least = NO+1;
	int nodeY;
	int nodeX;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (Comp[i] == Comp[j]) {
				continue;
			}
			if (LINK[i][j] < least) {
				least = LINK[i][j];
				nodeY = j;
				nodeX = i;
			}
		}
	}
	cout << nodeX << "----" << nodeY << "     value = " << LINK[nodeX][nodeY] << endl;
	UpdateComp(nodeX, nodeY);
}

int main() {
	for (int i = 0; i < 6; i++) {
		FindNext();
	}
	return 0;
}