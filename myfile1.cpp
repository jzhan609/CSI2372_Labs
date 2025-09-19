# include <iostream>
# include <string>
using namespace std;

string convertInt(int value, bool toOctal) {
    string result;
    if (toOctal) {
        // Octal conversion
        if (value == 0) return "0";
        int temp = value;
        while (temp > 0) {
            result = to_string(temp % 8) + result;
            temp /= 8;
        }
    } else {
        // Hexadecimal conversion
        if (value == 0) return "0";
        int temp = value;
        const char* hexDigits = "0123456789abcdef";
        while (temp > 0) {
            result = hexDigits[temp % 16] + result;
            temp /= 16;
        }
    }
    return result;
}

int main() {
    cout << "Size in bytes of a character: " << sizeof(char) << endl;
    cout << "Size in bytes of an Integer: " << sizeof(int) << endl;
    cout << "Size in bytes of a float: " << sizeof(float) << endl;
    cout << "Size in bytes of a double: " << sizeof(double) << endl;
    cout << "Size in bytes of a short Integer: " << sizeof(short) << endl;
    cout << "Size in bytes of an unsigned integer: " << sizeof(unsigned int) << endl;

    cout << "Enter an Integer: ";
    int input;
    cin >> input;
    cout << "Number in decimal: " << input << endl;
    cout << "Number in octal: " << oct << input << endl;
    cout << "Number in hexa: " << hex << input << endl;
    // Define a new variable for the octal representation
    
    string as_octal = convertInt(input, true);
    string as_hex = convertInt(input, false);
    cout << "Number in decimal: " << input << endl;
    cout << "Number in octal: " << as_octal << endl;
    cout << "Number in hexa: " << as_hex << endl;

    cout << "Enter a real number: ";
    double real_input;
    cin >> real_input;
    cout << real_input << endl;  
    cout << scientific << real_input << endl;

    cout << "Enter a character: ";
    char char_input;
    cin >> char_input;
    cout << char_input << endl;
    cout << static_cast<int>(char_input) << endl;

    return 0;
}