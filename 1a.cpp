#include<iostream>
#include<string>
using namespace std;

int* part_ip(string ip)
{
    int* c = new int[4];
    int i=0;
    int j=0;
    string temp;
    do
    {
        if (ip[i] == '.')
        {
            c[j] = stoi(temp);
            if (c[j]>255 || c[j]<0)
            {
                cout<<"ERR: Invalid IP"<<endl;
                break;
            }            
            temp.clear();
            j++;
        }
        else
        {
            if(isdigit(ip[i]))
                temp.push_back(ip[i]);
            else
            {   
                cout<<"ERR: Alphabet Found!"<<endl;
                break;
            }
        }
        i++;
        
    } while (i<ip.length());
    c[j] = stoi(temp);
    return c;
}

int bin_conv()

int main(int argc, char const *argv[])
{
    string ip;
    cin>>ip;
    int* ip_parts = part_ip(ip);
    for (int i = 0; i < 4; i++)
    {
        cout<<ip_parts[i];
    }
    bin_conv(ip_parts)
    return 0;
}

