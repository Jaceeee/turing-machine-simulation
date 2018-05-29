using namespace std;

#include "cell.h"

class TuringMachine {
private:	
	vector<char> inputTape;
	int readingHead;
	Cell* transitions;
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