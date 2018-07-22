
//User function Template for C++
void check_name(student k)
{
    //Add your code here.
    string firstName = k.first_name;
    string secondName = k.last_name;
    sort(firstName.begin(), firstName.end());
    sort(secondName.begin(), secondName.end());
    if(firstName == secondName)
    {
        cout << "ANAGRAM" << endl;
    }
    else
    {
        cout << "NOT ANAGRAM" <<endl;
    }
    return;
}
