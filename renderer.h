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

	void render();
};

void Renderer::render() {
	tm->render();
}