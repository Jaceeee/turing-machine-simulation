using namespace std;

class Cell {

private:
    int nextState; // where to got from current state
    char replacement; // any valid character replacement
    bool direction; // False = Left ; True = Right

public:
    Cell(int nextState, char replacement, bool direction) : nextState(nextState), replacement(replacement),
                                                            direction(direction) {}

    int getNextState() const {
        return nextState;
    }

    char getReplacement() const {
        return replacement;
    }

    bool isDirection() const {
        return direction;
    }

};