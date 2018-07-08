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

vector<int> FINISH;	

bool isIN(int node) {
	bool isin = false;
	for (vector<int>::iterator it = FINISH.begin(); it != FINISH.end(); it++) {
		if (*it == node) {
			isin = true;
		}
	}
	return isin;
}	

void FindNext() {
	int least = NO+1;
	int nodeY;
	int nodeX;
	for (vector<int>::iterator it = FINISH.begin(); it != FINISH.end(); it++) {
		for (int i = 0; i < 7; i++) {
			if (isIN(i)) {
				continue;
			}
			if (LINK[*it][i] < least) {
				least = LINK[*it][i];
				nodeY = i;
				nodeX = *it;
			}
		}
	}
	cout << nodeX << "----" << nodeY << "     value = " << LINK[nodeX][nodeY] << endl;
	FINISH.push_back(nodeY);
}

int main() {
	FINISH.push_back(0);
	for (int i = 0; i < 6; i++) {
		FindNext();
	}
	return 0;
}