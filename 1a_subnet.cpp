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

    // determine the network and broadcast addresses based on the subnet mask
    bitset<32> subnet_mask;
    switch (ip_array[0].to_ulong() >> 5) {
        case 0b000:  // Class A
            subnet_mask = bitset<32>("11111111000000000000000000000000");
            break;
        case 0b010:  // Class B
            subnet_mask = bitset<32>("11111111111111110000000000000000");
            break;
        case 0b100:  // Class C
            subnet_mask = bitset<32>("11111111111111111111111100000000");
            break;
        default:
            cout << "Invalid IPv4 address." << endl;
            return 0;
    }

    bitset<32> ip_address(ip_array[0].to_ulong() << 24 | ip_array[1].to_ulong() << 16 | ip_array[2].to_ulong() << 8 | ip_array[3].to_ulong());
    bitset<32> network_address = ip_address & subnet_mask;
    bitset<32> broadcast_address = network_address | ~subnet_mask;

    // print the network and broadcast addresses
    cout << "Network address: " << (network_address >> 24).to_ulong() << "." << ((network_address >> 16) & bitset<8>("11111111")).to_ulong() << "." << ((network_address >> 8) & bitset<8>("11111111")).to_ulong() << "." << (network_address & bitset<8>("11111111")).to_ulong() << endl;
    cout << "Broadcast address: " << (broadcast_address >> 24).to_ulong() << "." << ((broadcast_address >> 16) & bitset<8>("11111111")).to_ulong() << "." << ((broadcast_address >> 8) & bitset<8>("11111111")).to_ulong() << "." << (broadcast_address & bitset<8>("11111111")).to_ulong() << endl;

    return 0;
}
