#include<bits/stdc++.h>
using namespace std;

class Base
{
private:
public:
    Base();
     virtual void method(int x);
     virtual void method(int c, int d);
};
Base::Base(){}
void Base::method(int x)
{
    cout << "May hu base ka method1" <<endl;
}
void Base::method(int y, int z)
{
    cout << "May hu base ka method2 i.e overloaded method" <<endl;
}

class Derieved : public Base
{
private:
public:
    void method(int x)
    {
        cout << "May hu derieved class ka method 1st" <<endl;
    }

    void method(int c, int d)
    {
        cout << "May hu derieved class ka method 2nd" << endl;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // Base *b = new Derieved(); // No problem... becuase its reference variable to derieved class...
    Derieved d;
    d.method(2);
    d.method(4, 5);// if you dont define it it derieved class you will get error ...comment method(int x, itn y) int derieved class.

    return 0;
}
