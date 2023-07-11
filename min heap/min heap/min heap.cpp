#include<iostream>
using namespace std;
#include<stdlib.h>
class minHeap
{
	int size;
	int maxcapacity;
	int* arr;
public:
	minHeap(int);
	int isFull();
	int isEmpty();
	int insert(int);
	int deleteMin();
	void percolateDown(int);
	int display();
};
minHeap::minHeap(int n)
{
	maxcapacity = n+1;
	size = 0;
	arr = new int[n + 1];
	for (int i = 0; i < maxcapacity; i++)
	{
		arr[i] = -1;
	}
}
int minHeap::isFull()
{
	if (size == maxcapacity)
	{
		return 1;
	}
	else
		return 0;
}
int minHeap::isEmpty()
{
	if (size == 0)
	{
		return 1;
	}
	else
		return 0;
}
int minHeap::insert(int val)
{
	if (isFull())
	{
		return 0;
	}
	else
	{
		int hole;
		for (hole = size + 1; hole > 1 && val<arr[hole / 2]; hole = hole / 2)
		{
			arr[hole] = arr[hole / 2];
		}
		arr[hole] = val;
		size++;
		return 1;
	}
}
int minHeap::deleteMin()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		arr[1] = arr[size];
		size--;
		percolateDown(1);
		return 1;
	}
}
void minHeap::percolateDown(int gap)
{
	int child;
	int temp = arr[gap];
	for (gap = 1; gap * 2 <= size; gap = child)
	{
		child = gap * 2;
		if (child != size && arr[child + 1] < arr[child])
		{
			child++;
		}
		if (arr[child] < temp)
		{
			arr[gap] = arr[child];
		}
		else
			break;
	}
	arr[gap] = temp;
}
int minHeap::display()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		for (int i = 1; i <= size; i++)
		{
			cout << arr[i] <<"\t";
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
	minHeap aObj(n);
	while (1)
	{
		cout << "\n___________________________________\n";
		cout << "\n\t***MENU***\n";
		cout << "\n1.Insert.";
		cout << "\n2.Display.";
		cout << "\n3.DeleteMin.";
		cout << "\n4.Exit.";
		cout << "\nEnter your Choice:\n";
		cin >> ch;
		switch (ch)
		{
			case 1:
			{
				cout << "\nEnter the element to be inserted:\n";
				cin >> val;
				res = aObj.insert(val);
				if (res == 0)
				{
					cout << "Heap is full!!!.\n";
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
					cout << "\nHeap is Empty!!!";
				}
				else
				{
					cout << "\nDisplay is successfull";
				}
				break;
			}
			case 3:
			{
				res = aObj.deleteMin();
				if (res == 0)
				{
					cout << "\nHeap is Empty";
				}
				else
				{
					cout << "\nDeleteMin is successful";
				}
				break;
			}
			case 4:
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