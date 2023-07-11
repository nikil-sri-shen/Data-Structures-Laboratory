# include <iostream>
# include <cstdlib>
using namespace std;
class node//node declaration
{
    int info;
    node* left;
    node* right;
public:
    node();
    friend class BST;
};
class BST
{
    node* root = NULL;
public://functions declaration
    void search(node*, int);
    void find(int, node**, node**);
    void insert(node*, node*);
    void del(int);
    void casea(node*, node*);
    void caseb(node*, node*);
    void casec(node*, node*);
    void preorder(node*);
    void inorder(node*);
    void postorder(node*);
    void show(node*, int);
    BST()
    {
        root = NULL;
    }
};
void BST::search(node* root, int data) //searching
{
    node* temp = new node;
    temp = root;
    while (temp != NULL)
    {
        if (temp->info == data)
        {
            cout << "\nData found at depth: " << endl;
            return;
        }
        else if (temp->info > data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "\n Data not found" << endl;
    return;
}
void BST::insert(node* tree, node* newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout << "Element already in the tree" << endl;
        return;
    }
    if (tree→info > newnode→info)
    {
        if (tree→l != NULL)
        {
            insert(tree→l, newnode);
        }
        else
        {
            tree→l = newnode;
            (tree→l)→l = NULL;
            (tree→l)→r = NULL;
            cout << "Node Added To Left" << endl;
            return;
        }
    }
    else
    {
        if (tree→r != NULL)
        {
            insert(tree→r, newnode);
        }
        else
        {
            tree→r = newnode;
            (tree→r)→l = NULL;
            (tree→r)→r = NULL;
            cout << "Node Added To Right" << endl;
            return;
        }
    }
}
void BST::del(int i)
{
    nod* par, * loc;
    if (r == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    find(i, &par, &loc);
    if (loc == NULL)
    {
        cout << "Item not present in tree" << endl;
        return;
    }
    if (loc→l == NULL && loc→r == NULL)
    {
        casea(par, loc);
        cout << "item deleted" << endl;
    }
    if (loc→l != NULL && loc→r == NULL)
    {
        caseb(par, loc);
        cout << "item deleted" << endl;
    }
    if (loc→l == NULL && loc→r != NULL)
    {
        caseb(par, loc);
        cout << "item deleted" << endl;
    }
    if (loc→l != NULL && loc→r != NULL)
    {
        casec(par, loc);
        cout << "item deleted" << endl;
    }
    free(loc);
}
void BST::casea(nod* par, nod* loc)
{
    if (par == NULL)
    {
        r = NULL;
    }
    else
    {
        if (loc == par→l)
            par→l = NULL;
        else
            par→r = NULL;
    }
}
void BST::caseb(nod* par, nod* loc)
{
    nod* child;
    if (loc→l != NULL)
        child = loc→l;
    else
        child = loc→r;
    if (par == NULL)
    {
        r = child;
    }
    else
    {
        if (loc == par→l)
            par→l = child;
        else
            par→r = child;
    }
}
void BST::casec(nod* par, nod* loc)
{
    nod* ptr, * ptrsave, * suc, * parsuc;
    ptrsave = loc;
    ptr = loc→r;
    while (ptr→l != NULL)
    {
        ptrsave = ptr;
        ptr = ptr→l;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc→l == NULL && suc→r == NULL)
        casea(parsuc, suc);
    else
        caseb(parsuc, suc);
    if (par == NULL)
    {
        r = suc;
    }
    else
    {
        if (loc == par→l)
            par→l = suc;
        else
            par→r = suc;
    }
    suc→l = loc→l;
    suc→r = loc→r;
}
void BST::preorder(nod* ptr)
{
    if (r == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        cout << ptr→info << " ";
        preorder(ptr→l);
        preorder(ptr→r);
    }
}
void BST::inorder(nod* ptr)//inorder traversal
{
    if (r == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr→l);
        cout << ptr→info << " ";
        inorder(ptr→r);
    }
}
void BST::postorder(nod* ptr)//postorder traversal
{
    if (r == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr→l);
        postorder(ptr→r);
        cout << ptr→info << " ";
    }
}
void BST::show(nod* ptr, int level)//print the tree
{
    int i;
    if (ptr != NULL)
    {
        show(ptr→r, level + 1);
        cout << endl;
        if (ptr == r)
            cout << "Root→: ";
        else
        {
            for (i = 0; i < level; i++)
                cout << " ";
        }
        cout << ptr→info;
        show(ptr→l, level + 1);
    }
}
int main()
{
    int c, n, item;
    BST bst;
    nod* t;
    while (1)
    {
        cout << "1.Insert Element " << endl;
        cout << "2.Delete Element " << endl;
        cout << "3.Search Element" << endl;
        cout << "4.Inorder Traversal" << endl;
        cout << "5.Preorder Traversal" << endl;
        cout << "6.Postorder Traversal" << endl;
        cout << "7.Display the tree" << endl;
        cout << "8.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            t = new nod;
            cout << "Enter the number to be inserted : ";
            cin >> t→info;
            bst.insert(r, t);
            break;
        case 2:
            if (r == NULL)
            {
                cout << "Tree is empty, nothing to delete" << endl;
                continue;
            }
            cout << "Enter the number to be deleted : ";
            cin >> n;
            bst.del(n);
            break;
        case 3:
            cout << "Search:" << endl;
            cin >> item;
            bst.search(r, item);
            break;
        case 4:
            cout << "Inorder Traversal of BST:" << endl;
            bst.inorder(r);
            cout << endl;
            break;
        case 5:
            cout << "Preorder Traversal of BST:" << endl;
            bst.preorder(r);
            cout << endl;
            break;
        case 6:
            cout << "Postorder Traversal of BST:" << endl;
            bst.postorder(r);
            cout << endl;
            break;
        case 7:
            cout << "Display BST:" << endl;
            bst.show(r, 1);
            cout << endl;
            break;
        case 8:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}