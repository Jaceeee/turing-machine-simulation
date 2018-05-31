using namespace std;

#include "cell.h"

class TuringMachine {
private:	
	vector<char> inputTape;
	int readingHeadIndex;
	int currentState;
	int symbolId;	
	Cell transitions[25][9] = {
			/*0*/{Cell(0, 'D', true), Cell(0, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(0, '#', true), Cell(24, '@', true), Cell(1, '@', false)},
			/*1*/{Cell(24, 'D', true), Cell(1, '1', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(2, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*2*/{Cell(24, 'D', true), Cell(3, 'y', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*3*/{Cell(6, 'D', true), Cell(4, 'x', true), Cell(24, '0', true), Cell(3, 'x', false), Cell(4, 'y', true), Cell(24, 'z', true), Cell(3, '#', false), Cell(24, '@', true), Cell(24, 'B', true)},
			/*4*/{Cell(24, 'D', true), Cell(4, '1', true), Cell(4, '0', true), Cell(4, 'x', true), Cell(4, 'y', true), Cell(24, 'z', true), Cell(4, '#', true), Cell(4, '@', true), Cell(5, '0', false)},
			/*5*/{Cell(24, 'D', true), Cell(5, '1', false), Cell(5, '0', false), Cell(24, 'x', true), Cell(5, 'y', false), Cell(24, 'z', true), Cell(3, '#', false), Cell(5, '@', false), Cell(24, 'B', true)},
			/*6*/{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(6, '1', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(7, '#', false), Cell(24, '@', true), Cell(24, 'B', true)},
			/*7*/{Cell(24, 'D', true), Cell(8, 'x', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*8*/{Cell(24, 'D', true), Cell(9, 'y', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(8, 'y', true), Cell(24, 'z', true), Cell(8, '#', true), Cell(17, '@', false), Cell(24, 'B', true)},
			/*9*/{Cell(16, 'D', true), Cell(10, 'z', true), Cell(24, '0', true), Cell(9, 'x', false), Cell(9, 'y', false), Cell(9, 'z', false), Cell(9, '#', false), Cell(24, '@', true), Cell(24, 'B',true)},
			/*10*/{Cell(24, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(11, 'B', false)},
			/*11*/{Cell(24, 'D', true), Cell(11, '1', false), Cell(12, 'z', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*12*/{Cell(24, 'D', true), Cell(12, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(12, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(13, '1', false)},
			/*13*/{Cell(24, 'D', true), Cell(13, '1', false), Cell(12, 'z', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(13, 'z', false), Cell(24, '#', true), Cell(14, '@', true), Cell(24, 'B', true)},
			/*14*/{Cell(24, 'D', true), Cell(15, '1', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(14, '0', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*15*/{Cell(24, 'D', true), Cell(15, '1', false), Cell(15, '0', false), Cell(9, 'x', false), Cell(15, 'y', false), Cell(15, 'z', false), Cell(15, '#', false), Cell(15, '@', false), Cell(24, 'B', true)},
			/*16*/{Cell(24, 'D', true), Cell(16, '1', true), Cell(24, '0', true), Cell(16, 'x', true), Cell(16, 'y', true), Cell(16, '1', true), Cell(16, '#', true), Cell(22, '@', true), Cell(24, 'B', true)},
			/*17*/{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(17, '1', false), Cell(24, 'z', true), Cell(18, '#', false), Cell(24, '@', true), Cell(24, 'B', true)},
			/*18*/{Cell(19, 'D', true), Cell(18, '1', false), Cell(24, '0', true), Cell(18, '1', false), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*19*/{Cell(24, 'D', true), Cell(19, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(19, '#', true), Cell(20, '@', true), Cell(24, 'B', true)},
			/*20*/{Cell(24, 'D', true), Cell(24, '1', true), Cell(20, '1', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(21, 'B', false)},
			/*21*/{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			/*22*/{Cell(24, 'D', true), Cell(22, '0', true), Cell(22, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(23, 'B', false)},
			/*23*/{Cell(24, 'D', true), Cell(23, '1', false), Cell(23, '0', false), Cell(24, 'x', true), Cell(23, 'y', false), Cell(24, 'z', true), Cell(8, '#', true), Cell(23, '@', false), Cell(24, 'B', true)},
			/*24*/{Cell(24, 'D', true), Cell(23, '1', false), Cell(23, '0', false), Cell(24, 'x', true), Cell(23, 'y', false), Cell(24, 'z', true), Cell(24, '#', true), Cell(23, '@', false), Cell(24, 'B', false)}
		};

	Cell initialTransitions[11][9] = {
		/*0*/{Cell(10, 'D', true), Cell(1, 'x', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(1, 'y', true), Cell(10, '@', true), Cell(10, 'B', false)},
		/*1*/{Cell(10, 'D', true), Cell(1, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(1, '#', true), Cell(10, '@', true), Cell(2, 'B', false)},
		/*2*/{Cell(10, 'D', true), Cell(3, 'B', true), Cell(10, '0', true), Cell(7, 'D', true), Cell(8, 'D', true), Cell(10, 'z', true), Cell(5, 'B', true), Cell(10, '@', true), Cell(10, 'B', false)},
		/*3*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(4, '1', false)},
		/*4*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(2, 'B', false)},
		/*5*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(6, '#', false)},
		/*6*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(2, 'B', false)},
		/*7*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(9, '1', false)},
		/*8*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(9, '#', false)},
		/*9*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(10, 'B', false)},
		/*10*/{Cell(10, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(10, 'B', false)}		
	};

	// Cell secondProblemTransitions
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

		cout << endl;
	}
}

void TuringMachine::runTape() {	
	cout << "Initial tape status:" << endl;
	render(0, 30);

	cout << endl;

	while(currentState != 10) {
		Cell currentCell = initialTransitions[currentState][getCurrentSymbolId()];

		inputTape[readingHeadIndex] = currentCell.getReplacement();

		readingHeadIndex = (currentCell.isDirection()) 
						? readingHeadIndex + 1 
						: readingHeadIndex - 1;

		currentState = currentCell.getNextState();

		render(0, 30);

		cout << "Tape index: " << readingHeadIndex << endl;
		cout << "Current State: " << currentState << endl;
		cout << "Current Symbol: " << inputTape.at(readingHeadIndex) << endl;
		cout << "Direction: " << currentCell.isDirection() << endl;

		cout << endl;
	}

	currentState = 0;

	while(currentState != 24) {

		Cell currentCell = transitions[currentState][getCurrentSymbolId()];

		inputTape[readingHeadIndex] = currentCell.getReplacement();

		readingHeadIndex = (currentCell.isDirection()) 
						? readingHeadIndex + 1 
						: readingHeadIndex - 1;

		currentState = currentCell.getNextState();

		render(0, 30);
		cout << "Tape index: " << readingHeadIndex << endl;
		cout << "Current State: " << currentState << endl;
		cout << "Current Symbol: " << inputTape.at(readingHeadIndex) << endl;
		cout << "Direction: " << currentCell.isDirection() << endl;

		cout << endl;		
	}	
}

int TuringMachine::getCurrentSymbolId() {
	char symbol = inputTape.at(readingHeadIndex);

	if (symbol == 'D') {
		return 0;
	}
	else if (symbol == '1') {
		return 1;
	}
	else if (symbol == '0') {
		return 2;
	}
	else if (symbol == 'x') {
		return 3;
	}
	else if (symbol == 'y') {
		return 4;
	} 
	else if (symbol == 'z') {
		return 5;
	}
	else if (symbol == '#') {
		return 6;
	}
	else if (symbol == '@') {
		return 7;
	}
	else if (symbol == 'B') {
		return 8;
	}
}