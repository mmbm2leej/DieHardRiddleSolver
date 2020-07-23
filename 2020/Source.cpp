#include <iostream>
#include <vector>
#include <algorithm> 

#define vofi std::vector<int>

void print2dvec(std::vector<vofi> v) {
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			std::cout << v[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

int stepCount(int jugx, int jugy, int target) {
	if ((jugx <= 0) || (jugy <= 0) || (target <= 0)) {
		std::cout << "All values must be greater than zero.\n";
		return -1;
	}
	if ((jugx % 2 == 0) && (jugy % 2 == 0) && (target % 2 != 0)) {
		std::cout << "You can't use even sized jugs to find an odd sized goal.\n";
		return -1;
	}

	int rows, cols, newx = jugx + 1, newy = jugy + 1;
	int smaller, larger, steps = 0;

	//determine smaller and larger
	if (jugx <= jugy) {
		smaller = newx;
		larger = newy;
		rows = newx;
		cols = newy;
	}
	else {
		smaller = newy;
		larger = newx;
		rows = newy;
		cols = newx;
	}

	//rows is always smaller than columns
	vofi row(cols);
	std::vector<vofi> billiardTable(rows, row);
	//print2dvec(billiardTable);

	int currX = 0, currY = 0;	//our marker
	while ((currX != target) && (currY != target)) {

		if (currX == billiardTable[0].size() - 1) {
			currX = 0;
			std::cout << "Emptying the " << larger-1 << " gallon jar.\n";
		}
		
		else if (currY == 0) {
			currY = billiardTable.size() - 1;
			std::cout << "Filling the " << smaller-1 << " gallon jar.\n";
		}

		else {
			int diffX = (billiardTable[currY].size() - 1) - currX;
			int lesser = std::min(diffX, currY);
			currX += lesser;
			currY -= lesser;
			std::cout << "Pouring the " << smaller-1 << " gallon into the " << larger-1 << std::endl;
		}

		std::cout << "Larger: " << currX << ", Smaller: " << currY << "\n\n";
		steps++;
	}



	return steps;
}

int main() {
	int myX = 31, myY = 46, targ = 42;

	std::cout << stepCount(myX, myY, targ) << " steps.";

	return 0;
}

/*
3 actions can be taken

-empty col(billX) straight left(deplete bX)
-fill col with row(add bY to bX, deplete bY) whichever is smaller
fill row(billY) straight down (billY = max)

*/