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
	friend class CList;
};
class CList
{
	CNode* head;
public:
	CList();
	int isEmpty();
	CNode* search(int);
	int insertFront(int, string, string, string, int, int, float, float);
	int insertEnd(int, string, string, string, int, int, float, float);
	int insertAfter(int, int, string, string, string, int, int, float, float);
	int findPosition(int);
	string findElement(int);
	int deleteFront();
	int deleteEnd();
	int deleteByPosition(int);
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
	avg = 0.0;
	eco = 0.0;
	next = NULL;
}
CList::CList()
{
	head = NULL;
}
int CList::isEmpty()
{
	if (head == NULL)
	{
		return 1;
	}
	else
		return 0;
}
CNode* CList::search(int after)
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		CNode* temp = head;
		while (temp->rank != after && temp->next != NULL)
		{
			temp = temp->next;
		}
		if (temp->rank == after)
		{
			return temp;
		}
		else if (temp->rank != after && temp->next == NULL)
		{
			return NULL;
		}
		else
		{
			return NULL;
		}
	}
}
int CList::insertFront(int rank, string name, string team, string nat, int run, int wic, float avg, float eco)
{
	CNode* n = new CNode();
	n->rank = rank;
	n->name = name;
	n->team = team;
	n->nat = nat;
	n->run = run;
	n->wic = wic;
	n->avg = avg;
	n->eco = eco;
	n->next = NULL;
	if (isEmpty())
	{
		head = n;
		n = NULL;
		return 1;
	}
	else
	{
		n->next = head;
		head = n;
		n = NULL;
		delete n;
		return 1;
	}
}
int CList::insertEnd(int rank, string name, string team, string nat, int run, int wic, float avg, float eco)
{
	CNode* n = new CNode;
	n->rank = rank;
	n->name = name;
	n->team = team;
	n->nat = nat;
	n->run = run;
	n->wic = wic;
	n->avg = avg;
	n->eco = eco;
	n->next = NULL;
	if (isEmpty())
	{
		head = n;
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
		n = NULL;
		delete n;
		return 1;
	}
}
int CList::insertAfter(int aft, int rank, string name, string team, string nat, int run, int wic, float avg, float eco)
{
	CNode* n = new CNode;
	n->rank = rank;
	n->name = name;
	n->team = team;
	n->nat = nat;
	n->run = run;
	n->wic = wic;
	n->avg = avg;
	n->eco = eco;
	n->next = NULL;
	if (isEmpty())
	{
		head = n;
		n = NULL;
		return 1;
	}
	else
	{
		CNode* temp = head;
		while (temp->rank != aft && temp->next != NULL)
		{
			temp = temp->next;
		}
		if (temp->rank == aft)
		{
			if (temp->next == NULL)
			{
				temp->next = n;
			}
			else
			{
				n->next = temp->next;
				temp->next = n;
			}
			return 1;
		}
		else
			return 2;
	}
}
int CList::findPosition(int val)
{
	int count = 1;
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		if (head->rank == val)
		{
			return count;
		}
		else
		{
			CNode* temp = head;
			while (temp->rank != val && temp->next != NULL)
			{
				temp = temp->next;
				count++;
			}
			if (temp->rank == val)
			{
				return count;
			}
			else
				return -1;
		}
	}
}
string CList::findElement(int pos)
{
	int count = 1;
	if (isEmpty())
	{
		return "Empty";
	}
	else
	{
		if (pos == 1)
		{
			return head->name;
		}
		else
		{
			CNode* temp = head;
			while (count != pos && temp->next != NULL)
			{
				temp = temp->next;
				count++;
			}
			if (count == pos)
			{
				return temp->name;
			}
			else
				return "Not present";
		}
	}
}
int CList::deleteFront()
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
			return 1;
		}
		else
		{
			temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
			return 1;
		}
	}
}
int CList::deleteEnd()
{
	if (isEmpty())
	{
		return 0;
	}
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
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
		prev->next = NULL;
		prev = NULL;
		delete temp;
		temp = NULL;
		return 1;
	}
}
int CList::deleteByPosition(int pos)
{
	int count = 1;
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		if (pos == 1)
		{
			CNode* temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
			return 1;
		}
		else
		{
			CNode* temp = head;
			CNode* prev = NULL;
			while (pos != count && temp->next != NULL)
			{
				prev = temp;
				temp = temp->next;
				count++;
			}
			if (pos == count)
			{
				prev->next = temp->next;
				delete temp;
				temp = NULL;
				prev = NULL;
				return 1;
			}
			else
				return 2;
		}
	}
}
int CList::display()
{
	if (isEmpty())
	{
		return 0;
	}
	CNode* temp = head;
	cout << "____________________________________________________________________________________________________________________________";
	cout << "\nName\t|Rank\t|Team\t|Nation\t|Runs\t|Wicket\t|Average|Economy|\n";
	cout << "____________________________________________________________________________________________________________________________\n";
	while (temp->next != NULL)
	{
		cout << temp->name << "\t|";
		cout << temp->rank << "\t|";
		cout << temp->team << "\t|";
		cout << temp->nat << "\t|";
		cout << temp->run << "\t|";
		cout << temp->wic << "\t|";
		cout << temp->avg << "\t|";
		cout << temp->eco << "\t|\n";
		temp = temp->next;
	}
	cout << temp->name << "\t|";
	cout << temp->rank << "\t|";
	cout << temp->team << "\t|";
	cout << temp->nat << "\t|";
	cout << temp->run << "\t|";
	cout << temp->wic << "\t|";
	cout << temp->avg << "\t|";
	cout << temp->eco << "\t|\n";
	return 1;
}
int main()
{
	int ch, val, res, pos, aft;
	int rank, run, wic;
	string name, nat, team, res1;
	float avg, eco;
	CList obj;
	while (1)
	{
		cout << "\n________________________________________________________________________________________________________________________";
		cout << "\nMENU";
		cout << "\n1.Insertion at front";
		cout << "\n2.Insertion at end";
		cout << "\n3.Insertion after a element";
		cout << "\n4.Find position";
		cout << "\n5.Find element";
		cout << "\n6.Deletion at front";
		cout << "\n7.Deletion at end";
		cout << "\n8.Deletion by position";
		cout << "\n9.Display";
		cout << "\n10.Exit";
		cout << "\nEnter your choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "\nEnter the values of player to be inserted:";
			cout << "\nEnter rank of the player:";
			cin >> rank;
			cout << "Enter name of the player:";
			cin >> name;
			cout << "Enter team of the player:";
			cin >> team;
			cout << "Enter nation of the player:";
			cin >> nat;
			cout << "Enter runs of the player:";
			cin >> run;
			cout << "Enter wickets of the player:";
			cin >> wic;
			cout << "Enter average of the player:";
			cin >> avg;
			cout << "Enter economy of the player:";
			cin >> eco;
			res = obj.insertFront(rank, name, team, nat, run, wic, avg, eco);
			if (res == 1)
			{
				cout << "\nInsertion of player at front is successfull.";
			}
			else
				cout << "\nInsertion of player at front is not successfull.";
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
			cout << "Enter nation of the player:";
			cin >> nat;
			cout << "Enter runs of the player:";
			cin >> run;
			cout << "Enter wickets of the player:";
			cin >> wic;
			cout << "Enter average of the player:";
			cin >> avg;
			cout << "Enter economy of the player:";
			cin >> eco;
			res = obj.insertEnd(rank, name, team, nat, run, wic, avg, eco);
			if (res == 1)
			{
				cout << "\nInsertion of player at end is successfull.";
			}
			else
				cout << "\nInsertion of player at end is not successfull.";
			break;
		}
		case 3:
		{
			cout << "\nEnter the player rank after which new player should be inserted:";
			cin >> aft;
			cout << "\nEnter the values of player to be inserted:";
			cout << "\nEnter rank of the player:";
			cin >> rank;
			cout << "Enter name of the player:";
			cin >> name;
			cout << "Enter team of the player:";
			cin >> team;
			cout << "Enter nation of the player:";
			cin >> nat;
			cout << "Enter runs of the player:";
			cin >> run;
			cout << "Enter wickets of the player:";
			cin >> wic;
			cout << "Enter average of the player:";
			cin >> avg;
			cout << "Enter economy of the player:";
			cin >> eco;
			res = obj.insertAfter(aft, rank, name, team, nat, run, wic, avg, eco);
			if (res == 1)
			{
				cout << "\nInsertion of player after " << aft << " is successfull.";
			}
			else if (res == 2)
				cout << "\nPlayer does not present.";
			else
				cout << "\nList is Empty.";
			break;
		}
		case 4:
		{
			cout << "\nEnter the player rank for which position has to found:";
			cin >> val;
			res = obj.findPosition(val);
			if (res == 0)
			{
				cout << "\nList is Empty";
			}
			else if (res == -1)
				cout << "\nPlayer is not present.";
			else
				cout << "\nThe Player's position is " << res;
			break;
		}
		case 5:
		{
			cout << "\nEnter the player positon for which rank has to be found:";
			cin >> val;
			res1 = obj.findElement(val);
			if (res1 == "Empty")
			{
				cout << "\nList is Empty";
			}
			else if (res1 == "Not present")
				cout << "\nNo Player is present in the given position.";
			else
				cout << "\nPlayer present in the given position is " << res1;
			break;
		}
		case 6:
		{
			res = obj.deleteFront();
			if (res == 0)
			{
				cout << "\nList is Empty.";
			}
			else
				cout << "\nDeletion of player at front is successfull.";
			break;
		}
		case 7:
		{
			res = obj.deleteEnd();
			if (res == 0)
			{
				cout << "\nList is Empty.";
			}
			else
				cout << "\nDeletion of player at end is successfull.";
			break;
		}
		case 8:
		{
			cout << "\nEnter the player position at which player should be deleted:";
			cin >> pos;
			res = obj.deleteByPosition(pos);
			if (res == 1)
			{
				cout << "\nDeletion of player at position " << pos << " is successfull.";
			}
			else if (res == 2)
				cout << "\nDeletion of player is not possible as position is greater than size or smaller than 1.";
			else
				cout << "\nList is Empty";
			break;
		}
		case 9:
		{
			res = obj.display();
			if (res == 0)
			{
				cout << "\nList is Empty.So,Can't Display the List.";
			}
			else
				cout << "\nList is Displayed Successfully.";
			break;
		}
		case 10:
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