#include<iostream>
using namespace std;
#include<stdlib.h>
class hashing
{
	int size;
	int maxcapacity;
	int* arr;
public:
	hashing(int);
	int isFull();
	int isEmpty();
	int linearInsert(int);
	int quadraticInsert(int);
	int linearHashFunc(int);
	int quadraticHashFunc(int);
	int display();
};
hashing::hashing(int n)
{
	maxcapacity = n;
	for (int i = 0; i < maxcapacity; i++)
	{
		arr[i] = 0;
	}
}
int hashing::isFull()
{
	if (size == maxcapacity)
	{
		return 1;
	}
	else
		return 0;
}
int hashing::isEmpty()
{
	if (size == 0)
	{
		return 1;
	}
	else
		return 0;
}
int hashing::linearInsert(int val)
{
	int temp;
	if (isFull())
	{
		return 0;
	}
	else
	{
		if (arr[size] != 0)
		{
			temp = linearHashFunc(val);
			if (temp != -1)
			{
				arr[temp] = val;
				return 1;
			}
			else
				return -1;			
		}
		else
		{
			arr[size] = val;
		}
		return 1;
	}
}
int hashing::linearHashFunc(int val)
{
	if (isFull())
	{
		return 0;
	}
	else
	{
		int temp;
		temp = val % maxcapacity;
		if (arr[temp] == 0)
		{
			return temp;
		}
		else
		{
			for (int i = 0; i <= 7; i++)
			{
				temp = temp + i;
				if (arr[temp == 0])
				{
					return temp;
				}
			}
			return 0;
		}
	}
}
int hashing::display()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < maxcapacity; i++)
		{
			cout << arr[i] << "\t";
		}
		return 1;
	}
}
int main()
{
	int val, n, res, ch;
	cout << "\n___________________________________\n";
	cout << "\n\t***WELCOME***\n";
	cout << "\n___________________________________\n";
	cout << "Enter the max.capacity of the array:\n";
	cin >> n;
	hashing aObj(n);
	while (1)
	{
		cout << "\n___________________________________\n";
		cout << "\n\t***MENU***\n";
		cout << "\n1.Insert.";
		cout << "\n2.Display.";
		cout << "\n3.Exit.";
		cout << "\nEnter your Choice:\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\nEnter the element to be inserted:\n";
			cin >> val;
			res = aObj.linearInsert(val);
			if (res == 0)
			{
				cout << "Hash table is full!!!.\n";
			}
			else
			{
				cout << "Insertion is successfull";
			}
			break;
		}
		case 2:
		{
			res = aObj.display();
			if (res == 0)
			{
				cout << "\nHash table is Empty!!!";
			}
			else
			{
				cout << "\nDisplay is successfull";
			}
			break;
		}
		case 3:
		{
			cout << "\nProgram Ends";
			exit(0);
			break;
		}
		default:
		{
			cout << "Invalid input!!!";
			break;
		}
		}
	}
	return 0;
}