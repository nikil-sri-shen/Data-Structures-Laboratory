#include <iostream>
using namespace std;
class CQueue
{
	int* arr;
	int maxcapacity;
	int front = -1;
	int rear = -1;
public:
	CQueue(int n);
	~CQueue()
	{
		delete arr;
	}
	int input(int);
	int isFull();
	int isEmpty();
	int Rear();
	int enqueue(int);
	int dequeue();
	int makeEmpty();
	int display();
};
CQueue::CQueue(int n)
{
	maxcapacity = n;
	arr = new int[n];
	front = -1;
	rear = -1;
	for (int i = 0; i < n; i++)
	{
		arr[i] = -1;
	}
}
int CQueue::input(int s)
{
	rear = s;
	front = 0;
	if (rear <= maxcapacity)
	{
		cout << "\nEnter the elements:\n";
		for (int i = 0; i < rear; i++)
		{
			cin >> arr[i];
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int CQueue::isFull()
{
	if (maxcapacity == rear)
		return 1;
	else
		return 0;
}
int CQueue::isEmpty()
{
	if (rear == -1 || front == -1)
		return 1;
	else
		return 0;
}
int CQueue::enqueue(int val)
{
	if (isFull())
	{
		return 0;
	}
	else if (isEmpty())
	{
		front++;
		rear++;
		arr[rear] = val;
		return 1;
	}
	else
	{
		arr[rear] = val;
		rear++;
		return 1;
	}
}
int CQueue::dequeue()
{
	if (isEmpty())
	{
		return 0;
	}
	else if (front == 0 && rear == 0)
	{
		arr[rear] = -1;
		front = -1;
		rear = -1;
		return 1;
	}
	else
	{
		arr[front] = -1;
		front++;
		return 1;
	}
}
int CQueue::Rear()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		return arr[rear - 1];
	}
}
int CQueue::makeEmpty()
{
	for (int i = 0; i < maxcapacity; i++)
	{
		arr[i] = -1;
	}
	front = -1;
	rear = -1;
	return 1;
}
int CQueue::display()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < rear; i++)
			cout << arr[i] << "\t";
		return 1;
	}
}
int main()
{
	int val, n, s, res, ch;
	cout << "\n___________________________________\n";
	cout << "\n\t***WELCOME***\n";
	cout << "\n___________________________________\n";
	cout << "Enter the max.capacity of the array:\n";
	cin >> n;
	CQueue aObj(n);
	while (1)
	{
		cout << "\n___________________________________\n";
		cout << "\n\t***MENU***\n";
		cout << "\n1.Create Queue.";
		cout << "\n2.Enqueue.";
		cout << "\n3.Dequeue.";
		cout << "\n4.Rear.";
		cout << "\n5.Make Queue Empty.";
		cout << "\n6.Display the List";
		cout << "\n7.Exit";
		cout << "\nEnter your Choice:\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			repeat:
			cout << "\nEnter the size of elements to be entered:\n";
			cin >> s;
			res = aObj.input(s);
			if (res == 0)
			{
				cout << "\nSize is greater than maximum capacity, Please enter valid size.";
				goto repeat;
			}
			aObj.display();
			break;
		}
		case 2:
		{
			cout << "\nEnter the element to be pushed:\n";
			cin >> val;
			res = aObj.enqueue(val);
			if (res == 0)
			{
				cout << "Queue is full!!!.\n";
			}
			else
			{
				cout << "Enqueue is successfull";
			}
			aObj.display();
			break;
		}
		case 3:
		{
			res = aObj.dequeue();
			if (res == 0)
			{
				cout << "\nQueue is Empty!!!";
			}
			else
			{
				cout << "\nDequeue is successfull";
			}
			aObj.display();
			break;
		}
		case 4:
		{
			res = aObj.Rear();
			if (res == 0)
			{
				cout << "\nQueue is Empty";
			}
			else
			{
				cout << "\nRear element is " << res;
			}
		}
		case 5:
		{
			res = aObj.makeEmpty();
			if (res == 1)
			{
				cout << "\nMaking Queue empty is successfull.";
			}
			else
			{
				cout << "\nMaking Queue empty is not successfull.";
			}
			break;
		}
		case 6:
		{
			cout << "\nDisplaying Elements of the Stack:\n";
			res = aObj.display();
			if (res == 0)
			{
				cout << "\nQueue is Empty!!!.";
			}
			else if (res == 1)
			{
				cout << "\nDisplaying elements of queue is successfull.";
			}
			else
			{
				cout << "\nDisplaying elements of queue is not successfull.";
			}
			break;
		}
		case 7:
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