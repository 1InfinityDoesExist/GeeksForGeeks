#include<bits/stdc++.h>
using namespace std;

class MyException : public exception{
private:
    const char *msg;
    MyException(){};
public:
    MyException(const char *s) throw():msg(s){}
    const char *what() const throw(){
        return msg;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 20;
    int y = 0;
    try{
        if(y ==  0)
        {

            throw MyException("kya hey ye ");
          //  MyException m;
           // throw m;
        }
        else{
            cout << x+y <<endl;
        }
    }catch(exception &e){
        cout << e.what() <<endl;
    }
    return 0;
}
