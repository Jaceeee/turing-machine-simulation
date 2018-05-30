#include <iostream>
#include <vector>

#include "renderer.h"

using namespace std;

int main() {	
	int i;
	Renderer r(3, 4);
	r.render(0, 20);
	string st = "";

	i = 4;
	while(i > 0) {
		st += "\b\b";		
		i--;
	}
	
	cout << st;
	cin >> i;
	return 0;
}