#include <iostream>
#include <bitset>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<bitset<8>> convertIPv4StringToArray(string ipv4_str) {
    stringstream ss(ipv4_str);
    string segment;
    vector<bitset<8>> ip_array(4);

    int i = 0;
    while (getline(ss, segment, '.') && i < 4) {
        int value = stoi(segment);
        ip_array[i++] = bitset<8>(value);
    }

    return ip_array;
}

int main() {
    string ipv4_str;
    cout << "Enter an IPv4 address: ";
    getline(cin, ipv4_str);

    vector<bitset<8>> ip_array = convertIPv4StringToArray(ipv4_str);

    // check the class of the ip address based on the binary representation of the first element
    switch (ip_array[0].to_ulong() >> 5) {
        case 0b000:  // Class A
            cout << ipv4_str << " belongs to Class A." << endl;
            break;
        case 0b010:  // Class B
            cout << ipv4_str << " belongs to Class B." << endl;
            break;
        case 0b100:  // Class C
            cout << ipv4_str << " belongs to Class C." << endl;
            break;
        case 0b110:  // Class D
            cout << ipv4_str << " belongs to Class D." << endl;
            break;
        case 0b111:  // Class E
            cout << ipv4_str << " belongs to Class E." << endl;
            break;
        default:
            cout << "Invalid IPv4 address." << endl;
            break;
    }

    return 0;
}
