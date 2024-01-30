#include <iostream>
using namespace std;

class Admission_depart
{

    string name, id;

    public:

    Admission_depart(){}
    Admission_depart(string n, string i):name(n),id(i)
    {}

    void get_details()
    {
        cout<<"\nStudent name is: "<<name;
        cout<<"\nStudent id is: "<<id;
    }


};

int main()
{

    int size = 3;
    string name;
    string id;

    Admission_depart *stud = new Admission_depart[size];

    cout<<"\n============ Student inputs ============\n\n";
    for (int i = 0; i < size; i++)
    {

        cout<<"\n =========== Student #"<< i+1<<" ==========="; 

        cout<<"\n Enter the name of student: ";
        cin>>name;
        cout<<"\n Enter the id of student: ";
        cin>>id;

        stud[i] = Admission_depart(name, id);
        
    }


    cout<<"\n============ Student info ============\n\n";
        for (int i = 0; i < size; i++)
    { 
        stud[i].get_details();
    }
    
    delete[] stud;
    return 0;

}