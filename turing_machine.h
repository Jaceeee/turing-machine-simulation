using namespace std;

#include "cell.h"

class TuringMachine {
private:	
	vector<char> inputTape;
	int readingHeadIndex;
	int currentState;
	int symbolId;
	Cell transitions[25][9];
public:
	TuringMachine(int x, int y) {		
		readingHeadIndex = 0;
		int t = x;

		while(t > 0) {
			inputTape.push_back('1');
			t--;
		}


		inputTape.push_back('#');

		t = y;
		while(t > 0) {
			inputTape.push_back('1');
			t--;
		}

		t = 100000;
		while(t > 0) {
			inputTape.push_back('B');
			t--;
		}
	}

	void render(int, int);
	void runTape();
	int getCurrentSymbolId();
};

void TuringMachine::render(int x, int y) {
	if(x <= y && x >= 0 && y >= 0) {
		for(int i = x; i <= y; i++) {
			cout << inputTape.at(i) << " ";		
		}

		// cout << endl;
	}
}

// void TuringMachine::runTape() {
	// while(currentState != 24) {
	// 	if(transitions[currentState][getCurrentSymbolId()].get)
	// }
	// execute finishing code for reject
// }

// int TuringMachine::getCurrentSymbolId() {
// 	char symbol = inputTape.at(readingHeadIndex);

// 	if (symbol == 'D') {
// 		return 0;
// 	}
// 	else if (symbol == '1') {
// 		return 1;
// 	}
// 	else if (symbol == '0') {
// 		return 2;
// 	}
// 	else if (symbol == 'x') {
// 		return 3;
// 	}
// 	else if (symbol == 'y') {
// 		return 4;
// 	} 
// 	else if (symbol == 'z') {
// 		return 5;
// 	}
// 	else if (symbol == '#') {
// 		return 6;
// 	}
// 	else if (symbol == '@') {
// 		return 7;
// 	}
// 	else if (symbol == 'B') {
// 		return 8;
// 	}
// }