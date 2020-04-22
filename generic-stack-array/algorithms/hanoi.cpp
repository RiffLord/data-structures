//  Uses a stack to iteratively calculate the solution to a Tower 
//  of Hanoi game with the number of disks provided by the user.
#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std;

enum pole { origin, support, destination };

//  The state of the game is represented by a
//  struct which will be stored in the stack
struct hanoi {
    int disks;
    pole org;
    pole sup;
    pole dest;
    int returnValue;
};

void printPole(pole p) {
    if (p == origin) cout << " origin ";
    else if (p == support) cout << " support ";
    else cout << " destination ";
}

//  Represents the movement of a disk from one pole
//  to another, incrementing the number of moves when
//  called.
void moveOriginToDest(pole o, pole d, int& moves) {
    moves++;
    cout << "move a disk from ";
    printPole(o);
    cout << "to";
    printPole(d);
    cout << endl;
}

void move(int n, pole o, pole s, pole d, int& m) {
    stack<hanoi> steps; //  Each step of the game is stored in a stack
    pole temp;
    hanoi gameState;

    step1:
        if (n == 1) {
            moveOriginToDest(o, d, m);
            goto step3;
        }
        gameState.disks = n;
        gameState.org = o;
        gameState.sup = s;
        gameState.dest = d;
        gameState.returnValue = 2;
        steps.push(gameState);
        n--;
        temp = d;
        d = s;
        s = temp;
        goto step1;

    step2:
        moveOriginToDest(o, d, m);
        gameState.disks = n;
        gameState.org = o;
        gameState.sup = s;
        gameState.dest = d;
        gameState.returnValue = 3;
        steps.push(gameState);
        n--;
        temp = o;
        o = s;
        s = temp;
        goto step1;

    step3:
        if (!steps.isEmpty()) {
            hanoi sp = steps.read();
            steps.pop();
            n = sp.disks;
            o = sp.org;
            d = sp.dest;
            s = sp.sup;
            switch (sp.returnValue) {
                case 2:
                    goto step2;
                case 3:
                    goto step3;
            }
        }
}

int main(int argc, char* argv[]) {
    istringstream ss(argv[1]);
    int disks;
    if (!(ss >> disks)) cerr << "Invalid number: " << argv[1] << endl;
    else if (!ss.eof()) cerr << "Trailing characters after number: " << argv[1] << endl;
    else {
        int minMoves = 0;
        cout << "for " << disks << " disks the movements required are:" << endl;
        move(disks, origin, support, destination, minMoves);
        cout << "no. of moves: " << minMoves << endl;
    }
}