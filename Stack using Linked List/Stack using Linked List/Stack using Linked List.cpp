#include <iostream>
using namespace std;
#include<stdlib.h>
class CNode
{
	int rank;
	string name;
	string team;
	string nat;
	int run;
	int wic;
	float avg;
	float eco;
	CNode* next;
public:
	CNode();
	friend class CStack;
};
class CStack
{
	CNode* head;
	CNode* top;
public:
	CStack();
	int isEmpty();
	int input(int);
	int push(int, string, string, int, int);
	int pop();
	int peak();
	int makeEmpty();
	int display();
};
CNode::CNode()
{
	rank = 0;
	name = " ";
	team = " ";
	nat = " ";
	run = 0;
	wic = 0;
	next = NULL;
}
CStack::CStack()
{
	head = NULL;
	top = NULL;
}
int CStack::isEmpty()
{
	if (head == NULL || top == NULL)
	{
		return 1;
	}
	else
		return 0;
}
int CStack::input(int n)
{
	int res;
	int rank, run, wic;
	string name, nat, team;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the values of player " << i+1 << " to be inserted : ";
		cout << "\nEnter rank of the player:";
		cin >> rank;
		cout << "Enter name of the player:";
		cin >> name;
		cout << "Enter team of the player:";
		cin >> team;
		cout << "Enter runs of the player:";
		cin >> run;
		cout << "Enter wickets of the player:";
		cin >> wic;
		push(rank, name, team, run, wic);
	}
	return 1;
}
int CStack::push(int rank, string name, string team, int run, int wic)
{
	CNode* n = new CNode;
	n->rank = rank;
	n->name = name;
	n->team = team;
	n->run = run;
	n->wic = wic;
	n->next = NULL;
	if (isEmpty())
	{
		head = n;
		top = n;
		n = NULL;
		return 1;
	}
	else
	{
		CNode* temp;
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		top = n;
		n = NULL;
		delete n;
		return 1;
	}
}
int CStack::pop()
{
	if (isEmpty())
	{
		return 0;
	}
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
		top = NULL;
		return 1;
	}
	else
	{
		CNode* temp;
		CNode* prev;
		prev = head;
		temp = head->next;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		top = prev;
		prev->next = NULL;
		prev = NULL;
		delete temp;
		temp = NULL;
		return 1;
	}
}
int CStack::makeEmpty()
{
	if (isEmpty())
	{
		return 0;
	}
	while (head->next != NULL)
	{
		pop();
	}
	delete head;
	head = NULL;
	top = NULL;
	return 1;
}
int CStack::peak()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		cout << "_________________________________________________________________";
		cout << "\nName\t|Rank\t|Team\t|Runs\t|Wicket\t|\n";
		cout << "_________________________________________________________________\n";
		cout << top->name << "\t|";
		cout << top->rank << "\t|";
		cout << top->team << "\t|";
		cout << top->run << "\t|";
		cout << top->wic << "\t|";
		return 1;
	}
}
int CStack::display()
{
	if (isEmpty())
	{
		return 0;
	}
	CNode* temp = head;
	cout << "_________________________________________________________________";
	cout << "\nName\t|Rank\t|Team\t|Runs\t|Wicket|\n";
	cout << "_________________________________________________________________\n";
	while (temp != NULL)
	{
		cout << temp->name << "\t|";
		cout << temp->rank << "\t|";
		cout << temp->team << "\t|";
		cout << temp->run << "\t|";
		cout << temp->wic << "\t|";
		temp = temp->next;
	}
	return 1;
}
int main()
{
	int ch, res, n;
	int rank, run, wic;
	string name, team, res1;
	CStack obj;
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
			cout << "\nEnter the number of players:";
			cin >> n;
			res = obj.input(n);
			if (res == 1)
			{
				cout << "\nPlayers details are pushed successfully";
			}
			else
			{
				cout << "\nPlayers details are not pushed successfully";
			}
			break;
		}
		case 2:
		{
			cout << "\nEnter the values of player to be inserted:";
			cout << "\nEnter rank of the player:";
			cin >> rank;
			cout << "Enter name of the player:";
			cin >> name;
			cout << "Enter team of the player:";
			cin >> team;
			cout << "Enter runs of the player:";
			cin >> run;
			cout << "Enter wickets of the player:";
			cin >> wic;
			res = obj.push(rank, name, team, run, wic);
			if (res == 1)
			{
				cout << "\nPushing of player is successfull.";
			}
			else
				cout << "\nPushing of player is not successfull.";
			break;
		}
		case 3:
		{
			res = obj.pop();
			if (res == 0)
			{
				cout << "\nStack is Empty.";
			}
			else
				cout << "\nPoping of player is successfull.";
			break;
		}
		case 4:
		{
			res = obj.peak();
			if (res == 0)
			{
				cout << "\nStack is Empty.So,Can't Display the List.";
			}
			else
				cout << "\nPeak is Displayed Successfully.";
			break;
		}
		case 5:
		{
			res = obj.makeEmpty();
			if (res == 1)
			{
				cout << "\nStack is made Empty.";
			}
			else if(res == 0)
			{
				cout << "\nStack is already Empty";
			}
			else
			{
				cout << "\nStack is not made Empty.";
			}
			break;
		}
		case 6:
		{
			res = obj.display();
			if (res == 0)
			{
				cout << "\nStack is Empty.So,Can't Display the List.";
			}
			else
				cout << "\nStack is Displayed Successfully.";
			break;
		}
		case 7:
		{
			cout << "\nProgram ends!!!";
			exit(0);
			break;
		}
		default:
		{
			cout << "\nInvalid input!!!";
			break;
		}
		}
	}
	return 0;
}