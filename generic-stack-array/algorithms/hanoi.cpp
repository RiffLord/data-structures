//  Recursively calculates the solution to a Tower of Hanoi
//  game with the number of disks provided by the user.

/*
    Transforming a recursive procedure to an iterative one requires
        - the creation of a stack after the initial begin
        - the substitution of each recursive call with a series of
          instructions which:
          - save the values of the local parameters and the label of               the instruction following the recursive call into the stack
          - assign the appropriate values to the parameters
            - the code relating to the sequence of instruction for                   this call is executed
          - jump to the instruction following the stack creation
        - the introduction before the final end of instructions which,
          in case the stack is not empty, pop from it the stored                 values and jump to the instruction whose label is equal to             the return point
 */

 /*
    Type definitions:
    hanoi: structured type with the components
        numberOfDisks: integer
        pole:          origin, support, destination
        return:        integer

    move(int n, pole origin, pole destination, pole support)
        stack.init()
    1:    if (n == 1)
            moveSrcToDest
            goto 3
        hanoi.numberOfDisks = n
        hanoi.origin = origin
        hanoi.support = support
        hanoi.destination = destination
        hanoi.return = 2
        stack.push(hanoi)
        n = n - 1
        temp = destination
        destination = support
        support = temp
        goto 1
    2:  moveSrcToDest()
            hanoi.numberOfDisks = n
            hanoi.source = source
            hanoi.support = support
            hanoi.destination = destination
            hanoi.return = 3
            stack.push(hanoi)
            n = n - 1
            temp = source
            source = support
            support = temp
            goto 1
    3:  if !stack.isEmpty()
            hanoi = stack.read()
            stack.pop()
            n = hanoi.numberOfDisks
            source = hanoi.source
            destination = hanoi.destination
            support = hanoi.support
            case hanoi.return of
                2: goto 2
                3: goto 3
  */
#include <iostream>
#include <sstream>

using namespace std;

enum pole { origin, support, destination };

void printPole(pole p) {
    if (p == origin) cout << " origin ";
    else if (p == support) cout << " support ";
    else cout << " destination ";
}

void moveOriginToDest(pole o, pole d) {
    cout << "move a disk from ";
    printPole(o);
    cout << "to";
    printPole(d);
    cout << endl;
}

void move(int n, pole o, pole s, pole d, int& m) {
    if (n == 1) {
        moveOriginToDest(o, d);
        m++;
    } else {
        move(n - 1, o, d, s, m);
        moveOriginToDest(o, d);
        m++;
        move(n - 1, s, o, d, m);
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