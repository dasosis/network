#include <iostream>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    char ip_address[INET_ADDRSTRLEN];
    cout << "Enter the IP address in dotted decimal format: ";
    cin >> ip_address;

    char subnet_mask[INET_ADDRSTRLEN];
    cout << "Enter the subnet mask in dotted decimal format: ";
    cin >> subnet_mask;

    // Convert the IP address and subnet mask to binary format
    struct in_addr ip_address_bin, subnet_mask_bin;
    inet_pton(AF_INET, ip_address, &ip_address_bin);
    inet_pton(AF_INET, subnet_mask, &subnet_mask_bin);

    // Calculate the network ID by performing a bitwise AND operation on the IP address and subnet mask
    struct in_addr network_id_bin;
    network_id_bin.s_addr = ip_address_bin.s_addr & subnet_mask_bin.s_addr;

    // Convert the network ID back to string format
    char network_id[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &network_id_bin, network_id, INET_ADDRSTRLEN);

    // Print the network ID and all IP addresses in the network
    cout << "Network ID: " << network_id << endl;
    cout << "All IP addresses in the network:" << endl;
    for (int i = 1; i < 255; i++) {
        struct in_addr ip_address_i;
        ip_address_i.s_addr = network_id_bin.s_addr + htonl(i);
        char ip_address_str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &ip_address_i, ip_address_str, INET_ADDRSTRLEN);
        cout << ip_address_str << endl;
    }

    return 0;
}
