# include <iostream>
using namespace std;
#include<stdlib.h>
class CNode
{
    int rank;
    string name;
    string team;
    int run;
    int wic;
    CNode* left;
    CNode* right;
public:
    CNode(int,string,string,int,int);
    friend class CBST;
};
class CBST
{
    CNode* root;
public:
    CBST();
    CNode* getRoot();
    CNode* insert(CNode*, CNode*);
    CNode* deletion(CNode*,int);
    CNode* findMin(CNode*);
    void setRoot(CNode*);
    void preorder(CNode*);
    void postorder(CNode*);
    void inorder(CNode*);
};
CNode::CNode(int trank,string tname,string tteam,int trun,int twic)
{
    rank = trank;
    name = tname;
    team = tteam;
    run = trun;
    wic = twic;
    left = NULL;
    right = NULL;
}
CBST::CBST()
{
    root = NULL;
}
CNode* CBST::getRoot()
{
    return root;
}
void CBST::setRoot(CNode* temp)
{
    root = temp;
}
CNode* CBST:: findMin(CNode* temp)
{
    if (temp->left != NULL)
        findMin(temp->left);
    else
        return temp;
}

CNode* CBST::insert(CNode* temp, CNode* newNode)
{
    if (temp == NULL)
    {
        temp = newNode;
    }
    else
    {
        if (temp->rank < newNode->rank)
        {
            temp->right = insert(temp->right, newNode);
        }
        else if (temp->rank > newNode->rank)
        {
            temp->left = insert(temp->left, newNode);
        }
    }
    return temp;
}
CNode* CBST::deletion(CNode* temp, int key)
{
    if (temp == NULL)
    {
        return temp;
    }
    else
    {
        if (key < temp->rank)
        {
            temp->left = deletion(temp->left, key);
        }
        else if (key > temp->rank)
        {
            temp->right = deletion(temp->right, key);
        }
        else if (key == temp->rank)
        {

            if (temp->left == NULL and temp->right == NULL)
            {
                delete temp;
                temp = NULL;
                return temp;
            }
            else if (temp->left != NULL && temp->right != NULL)
            {
                CNode* succ = findMin(temp->right);
                temp->rank = succ->rank;
                temp->name = succ->name;
                temp->team = succ->team;
                temp->run = succ->run;
                temp->wic = succ->wic;
                temp->right = deletion(temp->right, succ->rank);
                return temp;
            }
            else
            {
                CNode* t = temp;
                if (temp->left == NULL)
                {
                    temp = temp->right;
                }
                else if (temp->right == NULL)
                {
                    temp = temp->left;
                }
                delete t;
                t = NULL;
                return temp;
            }
        }
        else
        {
            cout << "\nElement doesn't present";
        }
    }
}
void CBST::postorder(CNode* temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->name << "\t|";
        cout << temp->rank << "\t|";
        cout << temp->team << "\t|";
        cout << temp->run << "\t|";
        cout << temp->wic << "\t|\n";
    }
}
void CBST::preorder(CNode* temp)
{
    if (temp != NULL)
    {
        cout << temp->name << "\t|";
        cout << temp->rank << "\t|";
        cout << temp->team << "\t|";
        cout << temp->run << "\t|";
        cout << temp->wic << "\t|\n";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void CBST::inorder(CNode* temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->name << "\t|";
        cout << temp->rank << "\t|";
        cout << temp->team << "\t|";
        cout << temp->run << "\t|";
        cout << temp->wic << "\t|\n";
        inorder(temp->right);
    }
}
int main()
{
    int ch;
    int rank, run, wic, delrank;
    string name, team;
    CNode* res = NULL;
    CNode* temp = NULL;
    CBST obj;
    while (1)
    {
        cout << "\n________________________________________________________________________________________________________________________\n";
        cout << "\nMENU";
        cout << "\n1.Insertion";
        cout << "\n2.Deletion";
        cout << "\n3.Preorder";
        cout << "\n4.Postorder";
        cout << "\n5.Inorder";
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
                cout << "Enter runs of the player:";
                cin >> run;
                cout << "Enter wickets of the player:";
                cin >> wic;
                CNode* value = new CNode(rank,name,team,run,wic);
                temp = obj.getRoot();
                res = obj.insert(temp, value);
                obj.setRoot(res);
                break;
            }
            case 2:
            {
                cout<<"\nEnter the rank of the player to be deleted:";
                cin >> delrank;
                temp = obj.getRoot();
                res = obj.deletion(temp, delrank);
                break;
            }
            case 3:
            {
                cout << "\n____________________________________________________________________________________________________________________________";
                cout << "\nName\t|Rank\t|Team\t|Runs\t|Wicket|\t\n";
                cout << "____________________________________________________________________________________________________________________________\n";
                temp = obj.getRoot();
                obj.preorder(temp);
                break;
            }
            case 4:
            {
                cout << "\n____________________________________________________________________________________________________________________________";
                cout << "\nName\t|Rank\t|Team\t|Runs\t|Wicket|\t\n";
                cout << "____________________________________________________________________________________________________________________________\n";
                temp = obj.getRoot();
                obj.postorder(temp);
                break;
            }
            case 5:
            {
                cout << "\n____________________________________________________________________________________________________________________________";
                cout << "\nName\t|Rank\t|Team\t|Runs\t|Wicket|\t\n";
                cout << "____________________________________________________________________________________________________________________________\n";
                temp = obj.getRoot();
                obj.inorder(temp);
                break;
            }
        }
    }
    return 0;
}