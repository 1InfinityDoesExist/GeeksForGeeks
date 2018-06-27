//Null pointer is a value, while void pointer is a type

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    //NULL Pointer is a pointer which is pointing to nothing
    int *ptr = NULL;

    //wild pointer...
    //A pointer which has not been initialized to anything (not even NULL) is known as wild pointer

    int *kter; // is wild pointer...
    int x = 10;
    kter = &x; // now kter is not a wild pointer...
    cout << *kter << "  " << kter <<endl;

    //Dangling Pointer...
    int y = 20;
    int *yter = &y;
    free(yter); // dangling pointer...
    yter = NULL; // no more dangling pointer...

    //void pointer ...
    //a pointer that points to some data location in storage, which doesn’t have any specific type

    int a = 10;
    float b = 10.45;

    void *p;
    p = &a;
    cout << p << "  "<< *((int *)p) << endl;

    p = &b;
    cout << p << "  "<< *((float *)p) << endl;
    return 0;
}
