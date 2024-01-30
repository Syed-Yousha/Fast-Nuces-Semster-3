#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number>" << endl;
        return 1;
    }

    int num = atoi(argv[1]);

    cout << "Odd Numbers: ";
    for (int i = 1; i <= num; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Even Numbers: ";
    for (int i = 2; i <= num; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
