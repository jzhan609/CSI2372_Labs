#include <iostream>
#include <cmath>

using namespace std;

bool isAngstrom(int n) {
    int sum = 0, temp, remainder, digits = 0;
    temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, 3);
        temp /= 10;
    }
    return (sum == n);
}

int main() {
    int input;
    cout << "Please, enter your number: ";
    cin >> input;
    if (isAngstrom(input)) {
        cout << "This is an Armstrong number" << endl;
    }
    else {
        cout << "This is not an Armstrong number" << endl;
    }
    return 0;
}