#include <iostream>
#include <vector>

#include "renderer.h"

using namespace std;

int main() {	
	int i;
	Renderer r(3, 4);
	r.render(0, 20);
	
	r.run();
	return 0;
}