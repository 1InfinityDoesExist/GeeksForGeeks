#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char data[500];
    ifstream ifile;
    ifile.open("file.txt");
    while(!ifile.eof()){
        ifile.getline(data, 500);
        cout << data <<endl;
    }
    ifile.close();
    return 0;
}
