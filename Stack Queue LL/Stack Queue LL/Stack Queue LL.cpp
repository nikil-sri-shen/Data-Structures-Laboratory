#include <iostream>
using namespace std;
#include<stdlib.h>
class CStackNode
{
	int rank;
	string name;
	string team;
	int run;
	int wic;
	CStackNode* next;
public:
	CStackNode();
	friend class CStack;
};
class CStack
{
	CStackNode* head;
	CStackNode* top;
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
CStackNode::CStackNode()
{
	rank = 0;
	name = " ";
	team = " ";
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
		push(rank, name, team, run, wic);
	}
	return 1;
}
int CStack::push(int rank, string name, string team, int run, int wic)
{
	CStackNode* n = new CStackNode;
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
		CStackNode* temp;
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
		CStackNode* temp;
		CStackNode* prev;
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
		cout << top->wic << "\t|\n";
		return 1;
	}
}
int CStack::display()
{
	if (isEmpty())
	{
		return 0;
	}
	CStackNode* temp = head;
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
class CQueueNode
{
	int rank;
	string name;
	string team;
	int run;
	int wic;
	CQueueNode* next;
public:
	CQueueNode();
	friend class CQueue;
};
class CQueue
{
	CQueueNode* head;
	CQueueNode* front;
	CQueueNode* rear;
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
CQueueNode::CQueueNode()
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
	CQueueNode* n = new CQueueNode;
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
		CQueueNode* temp;
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
	CQueueNode* temp;
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
		cout << rear->wic << "\t|\n";
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
	CQueueNode* temp = head;
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
	int ch;
	repeat:
	while (1)
	{
		cout << "\n________________________________________________________________\n";
		cout << "\n\t***MENU***\n";
		cout << "\n1.Stack.";
		cout << "\n2.Queue.";
		cout << "\n3.Exit.";
		cout << "\nEnter your Choice:\n";
		cin >> ch;
		switch (ch)
		{
			case 1:
			{
				int sch, sres, sn;
				int srank, srun, swic;
				string sname, steam;
				CStack sobj;
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
					cin >> sch;
					switch (sch)
					{
						case 1:
						{
							cout << "\nEnter the number of players:";
							cin >> sn;
							sres = sobj.input(sn);
							if (sres == 1)
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
							cin >> srank;
							cout << "Enter name of the player:";
							cin >> sname;
							cout << "Enter team of the player:";
							cin >> steam;
							cout << "Enter runs of the player:";
							cin >> srun;
							cout << "Enter wickets of the player:";
							cin >> swic;
							sres = sobj.push(srank, sname, steam, srun, swic);
							if (sres == 1)
							{
								cout << "\nPushing of player is successfull.";
							}
							else
								cout << "\nPushing of player is not successfull.";
							break;
						}
						case 3:
						{
							sres = sobj.pop();
							if (sres == 0)
							{
								cout << "\nStack is Empty.";
							}
							else
								cout << "\nPoping of player is successfull.";
							break;
						}
						case 4:
						{
							sres = sobj.peak();
							if (sres == 0)
							{
								cout << "\nStack is Empty.So,Can't Display the List.";
							}
							else
								cout << "\nPeak is Displayed Successfully.";
							break;
						}
						case 5:
						{
							sres = sobj.makeEmpty();
							if (sres == 1)
							{
								cout << "\nStack is made Empty.";
							}
							else if (sres == 0)
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
							sres = sobj.display();
							if (sres == 0)
							{
								cout << "\nStack is Empty.So,Can't Display the List.";
							}
							else
								cout << "\nStack is Displayed Successfully.";
							break;
						}
						case 7:
						{
							cout << "\nStack Program Ends!!!";
							goto repeat;
							break;
						}
						default:
						{
							cout << "\nInvalid input!!!";
							break;
						}
					}
				}
			}
			case 2:
			{
				int qch, qres, qn;
				int qrank, qrun, qwic;
				string qname, qteam;
				CQueue qobj;
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
					cin >> qch;
					switch (qch)
					{
						case 1:
						{
							cout << "\nEnter the number of players:";
							cin >> qn;
							qres = qobj.input(qn);
							if (qres == 1)
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
							cin >> qrank;
							cout << "Enter name of the player:";
							cin >> qname;
							cout << "Enter team of the player:";
							cin >> qteam;
							cout << "Enter runs of the player:";
							cin >> qrun;
							cout << "Enter wickets of the player:";
							cin >> qwic;
							qres = qobj.enqueue(qrank, qname, qteam, qrun, qwic);
							if (qres == 1)
							{
								cout << "\nEnqueuing of player is successfull.";
							}
							else
								cout << "\nEnqueuing of player is not successfull.";
							break;
						}
						case 3:
						{
							qres = qobj.dequeue();
							if (qres == 0)
							{
								cout << "\nQueue is Empty.";
							}
							else
								cout << "\nDeQueuing of player is successfull.";
							break;
						}
						case 4:
						{
							qres = qobj.Rear();
							if (qres == 0)
							{
								cout << "\nQueue is Empty.So,Can't Display the elements.";
							}
							else
								cout << "\nRear is Displayed Successfully.";
							break;
						}
						case 5:
						{
							qres = qobj.makeEmpty();
							if (qres == 1)
							{
								cout << "\nQueue is made Empty.";
							}
							else if (qres == 0)
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
							qres = qobj.display();
							if (qres == 0)
							{
								cout << "\nQueue is Empty.So,Can't Display the elements.";
							}
							else
								cout << "\nQueue is Displayed Successfully.";
							break;
						}
						case 7:
						{
							cout << "\nQueue Program Ends!!!";
							goto repeat;
							break;
						}
						default:
						{
							cout << "\nInvalid input!!!";
							break;
						}
					}
				}
			}
			case 3:
			{
				cout << "\nProgram Ends!!!";
				exit(0);
				break;
			}
			default:
			{
				cout << "\nInvalid Input";
				break;
			}
		}
	}
	return 0;
}