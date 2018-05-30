using namespace std;

#include "cell.h";

class TuringMachine {
private:	
	vector<char> inputTape;
	int readingHead;
	Cell transitions [25][9] = {
			{Cell(0, 'D', true), Cell(0, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(0, '#', true), Cell(24, '@', true), Cell(1, '@', false)},
			{Cell(24, 'D', true), Cell(1, '1', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(2, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(3, 'y', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(6, 'D', true), Cell(4, 'x', true), Cell(24, '0', true), Cell(3, 'x', false), Cell(4, 'y', true), Cell(24, 'z', true), Cell(3, '#', false), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(4, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(4, '#', true), Cell(4, '@', true), Cell(5, '0', false)},
			{Cell(24, 'D', true), Cell(5, '1', false), Cell(5, '0', false), Cell(24, 'x', true), Cell(5, 'y', false), Cell(24, 'z', true), Cell(3, '#', false), Cell(5, '@', false), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(6, '1', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(7, '#', false), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(8, 'x', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(9, 'y', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(8, 'y', true), Cell(24, 'z', true), Cell(8, '#', true), Cell(17, '@', false), Cell(24, 'B', true)},
			{Cell(16, 'D', true), Cell(10, 'z', true), Cell(24, '0', true), Cell(9, 'x', false), Cell(9, 'y', false), Cell(9, 'z', false), Cell(9, '#', false), Cell(24, '@', true), Cell(24, 'B',true)},
			{Cell(24, 'D', true), Cell(10, '1', true), Cell(10, '0', true), Cell(10, 'x', true), Cell(10, 'y', true), Cell(10, 'z', true), Cell(10, '#', true), Cell(10, '@', true), Cell(11, 'B', false)},
			{Cell(24, 'D', true), Cell(24, '1', true), Cell(12, 'z', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(12, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(12, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(13, '1', false)},
			{Cell(24, 'D', true), Cell(13, '1', false), Cell(12, 'z', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(13, 'z', false), Cell(24, '#', true), Cell(14, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(15, '1', false), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(14, '0', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(9, 'x', false), Cell(24, 'y', true), Cell(15, 'z', false), Cell(15, '#', false), Cell(15, '@', false), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(16, '1', true), Cell(24, '0', true), Cell(16, 'x', true), Cell(16, 'y', true), Cell(16, '1', true), Cell(16, '#', true), Cell(22, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(17, '1', true), Cell(24, 'z', true), Cell(18, '#', false), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(19, 'D', true), Cell(18, '1', false), Cell(24, '0', true), Cell(18, '1', false), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(19, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(19, '#', true), Cell(20, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(24, '1', true), Cell(20, '1', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(21, 'B', false)},
			{Cell(24, 'D', true), Cell(24, '1', true), Cell(24, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(24, 'B', true)},
			{Cell(24, 'D', true), Cell(22, '0', true), Cell(22, '0', true), Cell(24, 'x', true), Cell(24, 'y', true), Cell(24, 'z', true), Cell(24, '#', true), Cell(24, '@', true), Cell(23, 'B', false)},
			{Cell(24, 'D', true), Cell(23, '1', false), Cell(23, '0', false), Cell(24, 'x', true), Cell(23, 'y', false), Cell(24, 'z', true), Cell(24, '#', true), Cell(23, '@', false), Cell(24, 'B', true)},
			{}
	};

public:
	TuringMachine(int x, int y) {		
		readingHead = 0;
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
	}

	void render();
};

void TuringMachine::render() {
	for(int i = 0; i < inputTape.size(); i++) {
		cout << inputTape.at(i) << " ";		
	}
	cout << endl;
}