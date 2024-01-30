#include <iostream>
using namespace std;

class Student
{
	string name, roll;
	int marks;
	
	public:

		Student(){}		
		Student(string n, string r, int m): name(n), roll(r), marks(m)
		{}
		
		void display()
		{
			cout<<"\nName: "<<name;
			cout<<"\nRoll no. : "<<roll;
			cout<<"\nMarks : "<<marks;
		}
};


int main()
{
	string name, roll;
	int marks, size;
	

	cout<<"\nEnter the size of class: ";
	cin>>size;

	Student *stud = new Student[size];
	
	cout<<"\n============ Student inputs ============\n\n";
    for (int i = 0; i < size; i++)
    {

		cout<<"\n =========== Student #"<< i+1<<" ==========="; 

        cout<<"\n Enter the name of student: ";
        cin>>name;
        cout<<"\n Enter the id of student: ";
        cin>>roll;
		cout<<"\n Enter the marks of student: ";
        cin>>marks;

		stud[i] = Student(name, roll, marks);        
    }


	for (int i = 0; i < size; i++)
	{
		cout<<"\n =========== Student #"<< i+1<<" ==========="; 
		stud[i].display();
	}
	

	return 0;		
}
