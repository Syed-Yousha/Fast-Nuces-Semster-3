#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int score;
    Node* next;

    Node() {}
    Node(string name, int score)
    {
        this->name = name;
        this->score = score;
        next = NULL;
    }
};


class Array{
	public:
	string name;
	int score;
};

class Singly
{
public:
    Node* head;
    Node* tail;

    Singly()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(string name, int score)
    {
        Node* tmp = new Node(name, score);

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void display()
    {
        Node* tmp = head;

        cout << "\n\nStudent Data:\n";
        while (tmp != NULL)
        {
            cout << tmp->name << ": " << tmp->score << endl;
            tmp = tmp->next;
        }
    }

    // Radix Sort
    int get_max(Array *arr, int size)
    {
        int max = arr[0].score;
        for (int i = 1; i < size; i++)
        {
            if (arr[i].score > max)
            {
                max = arr[i].score;
            }
        }
        return max;
    }

    void count_sort(Array *arr, const int size, int div)
    {
        Array *output = new Array[size];
        int count[10] = {0};

        for (int i = 0; i < size; i++)
        {
            count[(arr[i].score / div) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[(arr[i].score / div) % 10] - 1].score = arr[i].score;
            output[count[(arr[i].score / div) % 10] - 1].name = arr[i].name;
			count[(arr[i].score / div) % 10]--;
        }

        for (int i = 0; i < size; i++)
        {
            arr[i].score = output[i].score;
        	arr[i].name = output[i].name;
		}
    }

    void RadixSort(Array *arr, int size)
    {
        int m = get_max(arr, size);

        for (int div = 1; m / div > 0; div *= 10)
            count_sort(arr, size, div);
    }

    void convert_array(const int size)
    {
        Node* tmp = head;
        Array *arr = new Array[size];
        int i = 0;

        while (tmp != NULL)
        {
        	arr[i].name = tmp->name;
            arr[i].score = tmp->score;
            tmp = tmp->next;
            i++;
        }

        RadixSort(arr, size);

        // Update scores in linked list 
        tmp = head;
        i = 0;
        while (tmp != NULL)
        {
        	tmp->name = arr[i].name;
            tmp->score = arr[i].score;
            tmp = tmp->next;
            i++;
        }
    }
};

int main()
{
    Singly obj;
    obj.add_node("Yousha", 99);
    obj.add_node("B", 80);
    obj.add_node("thomas", 79);
    obj.add_node("yoo", 81);
    obj.add_node("Dazai", 98);

    obj.convert_array(5);
    obj.display();

    return 0;
}

