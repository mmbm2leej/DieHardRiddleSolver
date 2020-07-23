#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool statusCheck(int currentoney, int currentonex, int target) {


	if ((currentoney == target) || (currentonex == target)) {
		if (currentoney == target) std::cout << "\nCurrentoney is " << currentoney;
		else std::cout << "\nCurrentonex is " << currentonex;
		std::cout << "\n\nReached target.";
		return true;
	}
	else {
		std::cout << "Did not reach target yet.\n\n";
		return false;
	}
}

int main() {
	bool quit = false;
	char response = ' ';
	
	while (!quit) {

		int X, Y, placeholderjug, target;
		//enter values for each jug
		std::cout << "Please enter the size of jug X: " << std::endl;
		std::cin >> X;
		std::cout << "Please enter the size of jug Y: " << std::endl;
		std::cin >> Y;
		std::cout << "Please enter the target number: " << std::endl;
		std::cin >> target;
		if (X < Y) {
			placeholderjug = X;
			X = Y;
			Y = placeholderjug;
		}

		std::vector<std::vector<int>> vectorXY;
		std::vector<std::string> steps;

		int newx = X + 1;
		int newy = Y + 1;

		//make rows
		vectorXY.resize(newy);

		for (int i = 0; i < newy; ++i)
		{
			//make columns
			vectorXY[i].resize(newx);
		}

		//Begin
		std::cout << "Both jugs empty, filling jar X" << std::endl;
		steps.push_back("Starting by filling jug X");
		vectorXY[0][X] = 1;

		//to test what we have visually:
		for (int i = 0; i < newy; ++i) {
			for (int j = 0; j < newx; ++j) {
				std::cout << vectorXY[i][j] << " ";
			}
			std::cout << std::endl;
		}

		bool check = false;
		int stepcount = 1;
		int testx, testy;

		//currently infinite loop

		while (!check) {

			//checking stage
			for (size_t i = 0; i < vectorXY.size(); ++i) {
				for (size_t j = 0; j < vectorXY[0].size(); ++j) {
					if (vectorXY[i][j] != 0) {
						testy = i;
						testx = j;
					}
				}
			}

			check = statusCheck(testy, testx, target);
			if (check) break;

			std::cout << "Preaction: Current X is " << testx << std::endl;
			std::cout << "Preaction: Current Y is " << testy << std::endl;

			if (testy == Y) {
				std::cout << "Y is full, emptying Y" << std::endl;
				stepcount++;
				steps.push_back("Empty Jar Y");
				vectorXY[testy][testx] = 0;
				vectorXY[0][testx] = 1;

				//to test what we have visually:
				for (int i = 0; i < newy; ++i) {
					for (int j = 0; j < newx; ++j) {
						std::cout << vectorXY[i][j] << " ";
					}
					std::cout << std::endl;
				}
				std::cout << "Check = " << check << std::endl;
				continue;
			}
			else if (testx > 0) {
				std::cout << "Pouring X into Y" << std::endl;
				stepcount++;
				steps.push_back("Pour X into Y");
				int disty = Y - testy; int distx = testx; int mindist = std::min(disty, distx);
				vectorXY[testy][testx] = 0;
				vectorXY[testy + mindist][testx - mindist] = 1;

				//to test what we have visually:
				for (int i = 0; i < newy; ++i) {
					for (int j = 0; j < newx; ++j) {
						std::cout << vectorXY[i][j] << " ";
					}
					std::cout << std::endl;
				}
				std::cout << "Check = " << check << std::endl;
				continue;
			}
			else {
				std::cout << "X is 0, filling X" << std::endl;
				stepcount++;
				steps.push_back("Fill jar X");
				vectorXY[testy][testx] = 0;
				vectorXY[testy][X] = 1;

				//to test what we have visually:
				for (int i = 0; i < newy; ++i) {
					for (int j = 0; j < newx; ++j) {
						std::cout << vectorXY[i][j] << " ";
					}
					std::cout << std::endl;
				}
				std::cout << "Check = " << check << std::endl;
			}

		}
		std::cout << "\n\nPre-complete message- Check = " << check << std::endl;
		std::cout << "\n\nComplete! It took " << stepcount << " steps\n\n";

		for (size_t i = 0; i < steps.size(); ++i) {
			std::cout << "Step " << i+1 << ": "; std::cout << steps[i] << std::endl;
		}

		std::cout << "\n\n\nWould you like to start over?[Y/N]" << std::endl;
		std::cin >> response;
		if (response == 'N') return 0;


	}

	system("pause");
	return 0;
}
