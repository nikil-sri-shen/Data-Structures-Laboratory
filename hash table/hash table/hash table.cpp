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
	size = 0;
	arr = new int[n];
	for (int i = 0; i < maxcapacity; i++)
	{
		arr[i] = -1;
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
	int res;
	if (isFull())
	{
		return 0;
	}
	else
	{
		res = linearHashFunc(val);
		if (res != -1)
		{
			return 1;
		}
		else
			return -1;
	}
}
int hashing::quadraticInsert(int val)
{
	int res;
	if (isFull())
	{
		return 0;
	}
	else
	{
		res = quadraticHashFunc(val);
		if (res != -1)
		{
			return 1;
		}
		else
			return -1;
	}
}
int hashing::linearHashFunc(int val)
{
	int key;
	key = val % maxcapacity;
	int temp = key;
	int count = 0;
	while (size < maxcapacity && count <= maxcapacity)
	{
		if (arr[key] < 0)
		{
			arr[key] = val;
			size++;
			return 1;
		}
		else
		{
			key = temp + count;
			key = key % maxcapacity;
			count++;;
		}
	}
	return -1;
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
int hashing::quadraticHashFunc(int val)
{
	int key;
	key = val % maxcapacity;
	int temp = key;
	int count = 0;
	while (size < maxcapacity && count < maxcapacity)
	{
		if (arr[key] < 0)
		{
			arr[key] = val;
			size++;
			return 1;
		}
		else
		{
			key = temp + (count * count);
			key = key % maxcapacity;
			count++;
		}
	}
	return -1;
}
int main()
{
	int ch;
	cout << "\n___________________________________\n";
	cout << "\n\t***WELCOME***\n";
	cout << "\n___________________________________\n";
	while (1)
	{
		cout << "\n\t***MENU***\n";
		cout << "\n1.Linear Probing.";
		cout << "\n2.Quadratic Probing.";
		cout << "\n3.Exit.";
		cout << "\nEnter your Choice:\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			int val, n, res, ch;
			cout << "Enter the max.capacity of the array:\n";
			cin >> n;
			hashing aObj(n);
			while (1)
			{
				cout << "\nLinear Probing";
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
					else if (res == -1)
					{
						cout << "\nCollision occurs and insertion is not possible";
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
		}
		case 2:
		{

			int val, n, res, ch;
			cout << "\nQuadratic Probing";
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
					res = aObj.quadraticInsert(val);
					if (res == 0)
					{
						cout << "Hash table is full!!!.\n";
					}
					else if (res == -1)
					{
						cout << "\nCollision occurs and insertion is not possible";
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