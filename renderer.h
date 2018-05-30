#include <iostream>

#include "turing_machine.h"

using namespace std;

class Renderer {
private:	
	TuringMachine* tm;	
public:
	Renderer(int x, int y) {		
		tm = new TuringMachine(x, y);
	}

	void render(int, int);
	void run();
};

void Renderer::render(int x, int y) {
	tm->render(x, y);
}

void Renderer::run() {
	tm->runTape();
}