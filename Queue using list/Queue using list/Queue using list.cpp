#include <iostream>
using namespace std;
#include<stdlib.h>
class CNode
{
	int rank;
	string name;
	string team;
	int run;
	int wic;
	CNode* next;
public:
	CNode();
	friend class CQueue;
};
class CQueue
{
	CNode* head;
	CNode* front;
	CNode* rear;
public:
	CQueue();
	int isEmpty();
	int input(int);
	int enqueue(int, string, string, int, int);
	int dequeue();
	int Rear();
	int makeEmpty();
	int display();
};
CNode::CNode()
{
	rank = 0;
	name = " ";
	team = " ";
	run = 0;
	wic = 0;
	next = NULL;
}
CQueue::CQueue()
{
	head = NULL;
	front = NULL;
	rear = NULL;
}
int CQueue::isEmpty()
{
	if (head == NULL)
	{
		return 1;
	}
	else
		return 0;
}
int CQueue::input(int n)
{
	int res;
	int rank, run, wic;
	string name, nat, team;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the values of player " << i + 1 << " to be inserted : ";
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
		enqueue(rank, name, team, run, wic);
	}
	return 1;
}
int CQueue::enqueue(int rank, string name, string team, int run, int wic)
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
		front = n;
		rear = n;
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
		rear = n;
		n = NULL;
		delete n;
		return 1;
	}
}
int CQueue::dequeue()
{
	CNode* temp;
	if (isEmpty())
		return 0;
	else
	{
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			rear = NULL;
			front = NULL;
			return 1;
		}
		else
		{
			temp = head;
			head = head->next;
			front = head;
			delete temp;
			temp = NULL;
			return 1;
		}
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
		cout << "_________________________________________________________________";
		cout << "\nName\t|Rank\t|Team\t|Runs\t|Wicket\t|\n";
		cout << "_________________________________________________________________\n";
		cout << rear->name << "\t|";
		cout << rear->rank << "\t|";
		cout << rear->team << "\t|";
		cout << rear->run << "\t|";
		cout << rear->wic << "\t|";
		return 1;
	}
}
int CQueue::makeEmpty()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		while (head->next != NULL)
		{
			dequeue();
		}
		delete head;
		head = NULL;
		front = NULL;
		rear = NULL;
		return 1;
	}
}
int CQueue::display()
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
		cout << temp->wic << "\t|\n";
		temp = temp->next;
	}
	return 1;
}
int main()
{
	int ch, res, n;
	int rank, run, wic;
	string name, team, res1;
	CQueue obj;
	while (1)
	{
		cout << "\n________________________________________________________________\n";
		cout << "\n\t***MENU***\n";
		cout << "\n1.Create Queue.";
		cout << "\n2.Enqueue.";
		cout << "\n3.DeQueue.";
		cout << "\n4.Rear.";
		cout << "\n5.Make Queue Empty.";
		cout << "\n6.Display the Queue";
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
				cout << "\nPlayers details are enqueued successfully";
			}
			else
			{
				cout << "\nPlayers details are not enqueued successfully";
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
			res = obj.enqueue(rank, name, team, run, wic);
			if (res == 1)
			{
				cout << "\nEnqueuing of player is successfull.";
			}
			else
				cout << "\nEnqueuing of player is not successfull.";
			break;
		}
		case 3:
		{
			res = obj.dequeue();
			if (res == 0)
			{
				cout << "\nQueue is Empty.";
			}
			else
				cout << "\nDeQueuing of player is successfull.";
			break;
		}
		case 4:
		{
			res = obj.Rear();
			if (res == 0)
			{
				cout << "\nQueue is Empty.So,Can't Display the elements.";
			}
			else
				cout << "\nRear is Displayed Successfully.";
			break;
		}
		case 5:
		{
			res = obj.makeEmpty();
			if (res == 1)
			{
				cout << "\nQueue is made Empty.";
			}
			else if(res == 0)
			{
				cout << "\nQueue is already Empty.";
			}
			else
			{
				cout << "\nQueue is not made Empty.";
			}
			break;
		}
		case 6:
		{
			res = obj.display();
			if (res == 0)
			{
				cout << "\nQueue is Empty.So,Can't Display the elements.";
			}
			else
				cout << "\nQueue is Displayed Successfully.";
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