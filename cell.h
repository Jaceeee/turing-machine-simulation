using namespace std;

class Cell {

private:
    int nextState; // where to got from current state
    char replacement; // any valid character replacement
    bool direction; // False = Left ; True = Right

public:
    Cell(int nextState, char replacement, bool direction) {
    	this->nextState = nextState;
    	this->replacement = replacement;
    	this->direction = direction;
    }

    int getNextState() {
        return nextState;
    }

    char getReplacement() {
        return replacement;
    }

    bool isDirection() {
        return direction;
    }
};