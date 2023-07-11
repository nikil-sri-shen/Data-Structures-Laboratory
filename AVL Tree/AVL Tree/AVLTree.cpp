#include<iostream>
using namespace std;
class Treenode
{
public:
    Treenode();
    int rank;
    string name;
    string team;
    Treenode* left;
    Treenode* right;
    int height;
};
Treenode::Treenode()
{
    rank = 0;
    name = " ";
    team = " ";
    left = NULL;
    right = NULL;
    height = 0;
}
class Avl
{
public:
    Treenode* insert(Treenode* root, int rank, string, string);
    Treenode* search(Treenode* root, int rank);
    Treenode* findMax(Treenode* root);
    Treenode* findMin(Treenode* root);
    int getBalanceFactor(Treenode* N);
    int max(int a, int b);
    int height(Treenode* N);
    void inOrder(Treenode* root);
    void postOrder(Treenode* root);
    void preOrder(Treenode* root);
    Treenode* leftRotate(Treenode* k1);
    Treenode* LR(Treenode*);
    Treenode* RL(Treenode*);
    Treenode* rightRotate(Treenode* k2);
};
int Avl::height(Treenode* N)
{
    if (N == NULL)
    {
        return -1;
    }
    else
    {
        return N->height;
    }
}
int Avl::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void Avl::inOrder(Treenode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->rank << "\t" << root->name << " \t" << root->team << endl;
        inOrder(root->right);
    }
}
void Avl::postOrder(Treenode* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->rank << "\t" << root->name << "\t" << root->team << endl;
    }
}
void Avl::preOrder(Treenode* root)
{
    if (root != NULL)
    {
        cout << root->rank << "\t" << root->name << "\t" << root->team << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
Treenode* Avl::findMin(Treenode* root)
{
    Treenode* temp = root;
    if (temp->left != NULL)
    {
        findMin(temp->left);
    }
    else
    {
        return root;
    }
}
Treenode* Avl::findMax(Treenode* root)
{
    Treenode* temp = root;
    if (temp->right != NULL)
    {
        findMax(temp->right);
    }
    else
    {
        return root;
    }
}
Treenode* Avl::leftRotate(Treenode* k1)
{
    Treenode* k2 = k1->right;
    Treenode* temp = k2->left;
    k2->left = k1;
    k1->right = temp;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    return k2;
}
Treenode* Avl::rightRotate(Treenode* k2)
{
    Treenode* k1 = k2->left;
    Treenode* temp = k1->right;
    k1->right = k2;
    k2->left = temp;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    return k1;
}
Treenode* Avl::LR(Treenode* k3)
{
    k3->left = leftRotate(k3->left);
    return rightRotate(k3);
}
Treenode* Avl::RL(Treenode* k3)
{
    k3->right = rightRotate(k3->right);
    return leftRotate(k3);
}
int Avl::getBalanceFactor(Treenode* N)
{
    return height(N->left) - height(N->right);
}
Treenode* Avl::insert(Treenode* root, int r, string nm, string t)
{
    Treenode* temp = new Treenode();
    Treenode* n = root;
    if (n == NULL)
    {
        temp->rank = r;
        temp->name = nm;
        temp->team = t;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (r < n->rank)
    {
        n->left = insert(n->left, r, nm, t);
    }
    else if (r > n->rank)
    {
        n->right = insert(n->right, r, nm, t);
    }
    else
    {
        return n;
    }
    int Balance = getBalanceFactor(n);
    if (Balance > 1)
    {
        if (r < n->left->rank)
        {
            n = rightRotate(n);
        }
        else
        {
            n = LR(n);
        }
    }
    if (Balance < -1)
    {
        if (r > n->right->rank)
        {
            n = leftRotate(n);
        }
        else
        {
            n = RL(n);
        }
    }
    n->height = max(height(n->left), height(n->right)) + 1;
    return n;
}
Treenode* Avl::search(Treenode* root, int r)
{
    Treenode* temp = root;
    if (temp == NULL || temp->rank == r)
    {
        return temp;
    }
    else if (temp->rank < r)
    {
        search(temp->right, r);
    }
    else if (temp->rank > r)
    {
        search(temp->left, r);
    }
}
int main()
{
    Avl* a = new Avl();
    int ch, r;
    string nm, t;
    Treenode* N;
    Treenode* root;
    root = NULL;
    cout << endl;
    do
    {
        cout << endl;
        cout << "\n________________________\n";
        cout << "Enter the SI No to access that program" << endl;
        cout << "\n________________________\n";
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Last Element" << endl;
        cout << "4.First Element" << endl;
        cout << "5.Preorder" << endl;
        cout << "6.postorder" << endl;
        cout << "7.Inorder" << endl;
        cout << "8.Exit " << endl;
        cout << endl;
        cout << "Enter your choice ..:";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "\nENTER Rank:";
            cin >> r;
            cout << "\nEnter Player Name:";
            cin >> nm;
            cout << "\nEnter Team of Laptop:";
            cin >> t;
            root = a->insert(root, r, nm, t);
            break;
        }
        case 2:
        {
            cout << "\n ENTER Player TO BE SEARCHED  :";
            cin >> r;
            N = a->search(root, r);
            if (N == NULL)
            {
                cout << "\n\nPlayer NOT FOUND....." << endl;
            }
            else
            {
                cout << "\n\nPlayer IS FOUND..." << endl;
                cout << "\nRank::" << N->rank;
                cout << "\nPlayer NAME::" << N->name;
                cout << "\nPlayer TEAM::" << N->team << endl;
            }
            break;
        }
        case 3:
        {
            Treenode* max;
            max = a->findMax(root);
            cout << "\n LAST Element:" << max->rank << " " << max->name << " " << max->team << endl;
            break;
        }
        case 4:
        {
            Treenode* min;
            min = a->findMin(root);
            cout << "\n FIRST Element   :" << min->rank << " " << min->name << " " << min->team << endl;
            break;
        }
        case 5:
        {
            cout << "\n PRE ORDER:" << endl;
            cout << endl;
            a->preOrder(root);
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "\n POST ORDER:" << endl;
            cout << endl;
            a->postOrder(root);
            cout << endl;
            break;
        }
        case 7:
        {
            cout << "\n IN ORDER:" << endl;
            cout << endl;
            a->inOrder(root);
            cout << endl;
            break;
        }
        default:
        {
            cout << "\nEnter the correct option" << endl;
            cout << endl;
        }

        }
    } while (ch < 8);
}
