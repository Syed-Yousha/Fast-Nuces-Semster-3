#include <iostream>
using namespace std;


class BookPrice{
	string bookname;
	int price;
	
	public:
			
		BookPrice(){}
		BookPrice(string b, int p): bookname(b), price(p)
		{} 

		BookPrice(const BookPrice &obj)
		{
			this->bookname = bookname;
			this->price = price;
		}
		
		
		//For safety
		BookPrice operator = (const BookPrice &obj)
		{
			
			if(this != &obj)
			{
					
				this->bookname = obj.bookname;
				this->price = obj.price;
			}
			
			return *this;
			
		}
		
		
		
		void display()
		
		{
			cout<<"\nPrice is: "<<price;
			cout<<"\nBookname is: "<<bookname;
			
		}
		
		~BookPrice()
		{
			cout<<"\nDestructor";
		}
};


int main()
{
	BookPrice a("Sherlock Holmes", 250);
	BookPrice b = a;
	
//	a = BookPrice("Rumi", 250);
	
	
	cout<<endl<<&a;
	cout<<endl<<&b;
	
	a.display();
	b.display();
	
}
