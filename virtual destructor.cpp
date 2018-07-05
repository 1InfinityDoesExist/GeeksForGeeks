
//we should use virtual destructor if we call delete on a base class pointer which points to a derived class.


/*
A destructor gets called when an object goes out of
scope or when we call delete on an object pointer.

When any derived class object goes out of scope, the destructor of that derived class gets called first.
It then calls its parent class destructor
so memory allocated to the object is properly released.

But, if we call delete on a base pointer which points to a derived class object, the base class destructor
gets called first (for non-virtual function).

*/
#include<bits/stdc++.h>
using namespace std;

class Base
{
private:
public:
    Base(){
        cout << "Base Constructor hu may" <<endl;
    }
    virtual ~Base(){
        cout << "Base destructor hu may" <<endl;
    }

    /*~Base(){
        cout << "Base destructor hu may" <<endl;
    }*/
};
class Derived : public Base
{
private:
public:
    Derived(){
        cout << "Derived constructor hu may" <<endl;
    }
    ~Derived(){
        cout<< "Derived destructor hu may" << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Base *b = new Derived();
    delete b;
    return 0;
}
