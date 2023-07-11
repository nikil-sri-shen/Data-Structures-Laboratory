/**************************************************************
*    This is simple program to demostrate working of Stack    *
*                 using Array implementation                  *
***************************************************************/
#include <iostream>
using namespace std;
class CStack
{
   private:	
	int* arr;//pointer varaible to dynamically allocate memory
	int maxcapacity;//vaaraible to store maximum capacity of the stack
	int top;//variable to store size of the stack
   public:
	CStack(int n);//parameterised constructor to create a stack and 'n' is the max.capacity
	~CStack()//destructor
	{
		delete arr;
	}
	int input(int s);//function to get inputs and 's' in the size of the stack
	int isFull();//helper function to check whether stack is full or not
	int isEmpty();//helper function to check whether stack is empty or not
	int push(int val);//function to push element into the stack and 'val' is the element to be pushed
	int pop();//function to pop element from the stack
	int peak();//function to find peak element of the stack
	int makeEmpty();//function to make the stack empty
	int display();//function to display elements of the stack
};
CStack::CStack(int n)
{
	maxcapacity = n;//setting maxcapaity to the value given by the user
	arr = new int[n];//dynamcically allocating memory for the stack array
	top = 0;//setting top to 0
	for (int i = 0; i < n; i++)
		arr[i] = -1;
}
int CStack::input(int s)
{
	top = s;//setting top to the size given by the user
	if (top <= maxcapacity)//checking whether the given size is less than max capacity
	{
		cout << "\nEnter the elements:\n";
		for (int i = 0; i < top; i++)//getting inputs
			cin >> arr[i];
	}
	else
	{
		return 0;
	}
}
int CStack::isFull()
{
	if (maxcapacity == top)//if maxcapacity and top are same then stack is full
		return 1;
	else
		return 0;
}
int CStack::isEmpty()
{
	if (top == 0)//if top is equal to zero the stack is empty
		return 1;
	else
		return 0;
}
int CStack::push(int val)
{
	if (isFull())//check whether the stack is full or not
	{
		return 0;
	}
	else if (isEmpty())//check whether the stack is empty or not
	{
		arr[0] = val;//pushing element in the first position
		top++;
		return 1;
	}
	else
	{
		arr[top] = val;//pushing element in the top position
		top++;
		return 1;
	}
}
int CStack::pop()
{
	if (isEmpty())//check whether the stack is empty or not
	{
		return 0;
	}
	else if (top == 1)//check whether there is only one element in the stack
	{
		arr[0] = -1;//making the only element to empty
		top--;
		return 1;
	}
	else
	{
		arr[top - 1] = -1;//making the top element to empty
		top--;
		return 1;
	}
}
int CStack::peak()
{
	if (isEmpty())//check whether the stack is empty or not
	{
		return 0;
	}
	else
	{
		return arr[top - 1];
	}
}
int CStack::makeEmpty()
{
	for (int i = 0; i < maxcapacity; i++)
	{
		arr[i] = -1;
	}
	top = 0;
	return 1;
}
int CStack::display()
{
	if (isEmpty())//check whether the stack is empty or not
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < top; i++)
			cout << arr[i] << "\t";
		return 1;
	}
}
int main()
{
	int val, n, s, res, ch;
	cout << "\n____________________________________________________________________\n";
	cout << "\t\tWELCOME";
	cout << "\n____________________________________________________________________\n";
	cout << "Enter the max.capacity of the array:\n";
	cin >> n;
	CStack aObj(n);
	while (1)
	{
		cout << "\n________________________________________________________________\n";
		cout << "\n\t***MENU***\n";
		cout << "\n1.Create Stack.";
		cout << "\n2.Push.";
		cout << "\n3.Pop.";
		cout << "\n4.Peak.";
		cout << "\n5.Make Stack Empty.";
		cout << "\n6.Display the Stack";
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
			cout << "\nDisplaying Elements of the Stack:\n";
			aObj.display();
			break;
		}
		case 2:
		{
			cout << "\nEnter the element to be pushed:\n";
			cin >> val;
			res = aObj.push(val);
			if (res == 0)
			{
				cout << "Stack is full!!!.\n";
			}
			else
			{
				cout << "Push is successfull";
				cout << "\nDisplaying Elements of the Stack:\n";
				aObj.display();
			}
			break;
		}
		case 3:
		{
			res = aObj.pop();
			if (res == 0)
			{
				cout << "\nStack is Empty!!!";
			}
			else
			{
				cout << "\nPop is successfull";
				cout << "\nDisplaying Elements of the Stack:\n";
				aObj.display();
			}
			break;
		}
		case 4:
		{
			res = aObj.peak();
			if (res == 0)
			{
				cout << "\nStack is Empty.";
			}
			else
			{
				cout << "\nPeak element is " << res;
			}
			break;
		}
		case 5:
		{
			res = aObj.makeEmpty();
			if (res == 1)
			{
				cout << "\nMaking Stack empty is successfull.";
			}
			else
			{
				cout << "\nMaking Stack empty is not successfull.";
			}
			break;
		}
		case 6:
		{
			cout << "\nDisplaying Elements of the Stack:\n";
			res = aObj.display();
			if (res == 0)
			{
				cout << "\nStack is Empty!!!.";
			}
			else if (res == 1)
			{
				cout << "\nDisplaying elements of stack is successfull.";
			}
			else
			{
				cout << "\nDisplaying elements of stack is not successfull.";
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