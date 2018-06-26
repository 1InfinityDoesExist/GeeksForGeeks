#include<bits/stdc++.h>
using namespace std;

int main(){
    int n (8);
    //cin >> n;
    string binary = bitset<8>(n).to_string();
    cout << binary << endl;

    // remove all zero front front
    binary.erase(0, binary.find_first_not_of('0'));
    cout << binary <<endl;


    //second way to find binary number...

    int num;
    num = 8;
    string str = "";
    while(num)
    {
        str = (num%2 == 0 ? "0" : "1")  + str;
        num = num/2;
    }
    cout << str << endl;


    // binary to decimal....

    unsigned long long int decimal = bitset<8>(binary).to_ulong();
    cout << decimal << endl;
    return 0;
}
