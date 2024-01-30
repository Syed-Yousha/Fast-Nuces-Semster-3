#include <iostream>
using namespace std;

class Node
{
public:
	string book;
	Node *next;

	Node(string book) : book(book), next(NULL) {}
};

class Library
{

public:
	Node *head;
	Node *tail;

	Library()
	{
		head = NULL;
		tail = NULL;
	}

	void insert_tail(string book)
	{
		Node *n = new Node(book);

		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}
		cout << "\nInserted at tail";
	}

	void del_front()
	{
		Node *d = head;
		head = head->next;
		d->next = NULL;
		delete d;
	}

	bool search_book(string key)
	{
		Node *temp = head;

		while (temp != NULL)
		{
			if (temp->book == key)
			{

				cout << "\nBook Existed";
				return true;
			}
			temp = temp->next;
		}

		cout << "\n Name not found!";
		return false;
	}

	bool search_book(int key)
	{
		Node *temp = head;
		int i = 0;

		while (temp != NULL)
		{
			if (i == key)
			{
				cout << "\nat position #" << i + 1 << " Book found named: " << temp->book;
				return true;
			}

			temp = temp->next;
			i++;
		}

		cout << "\nBook not found at position #" << key + 1;
		return false;
	}

	void display()
	{

		Node *temp;
		temp = head;

		cout << "\n\n======== Displaying entire Book catalogue ========\n\n";
		while (temp != NULL)
		{
			cout << "\n name of book: " << temp->book;
			temp = temp->next;
		}
	}
};

int main()
{
	Library obj;
	//Adding book
	obj.insert_tail("Sherlock Holmes");
	obj.insert_tail("Forty rules of love");
	obj.insert_tail("Romeo juliet");
	obj.insert_tail("the alchemist");

	//Searching
	obj.search_book("Forty rules of love");
	obj.search_book(1);
	obj.display();

	//Deleting a book
	obj.del_front();
	obj.display();

	return 0;
}
