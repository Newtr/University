#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *left, *right;
};

void ShowTree(Node *&Tree){
    if (Tree!=NULL)
    {
        ShowTree(Tree->left);
        cout<<Tree->x<<"\t";
        ShowTree(Tree->right);
    }
    
}

void AddNode(int x, Node *&Tree){
    if (NULL==Tree)
    {
        Tree = new Node;
        Tree->x=x;
        Tree->left=Tree->right=NULL;
    }
    if (x<Tree->x)
    {
        if (Tree->left != NULL)
        {
            AddNode(x,Tree->left);
        }
        else
        {
            Tree->left = new Node;
            Tree->left->left=Tree->left->right=NULL;
            Tree->left->x=x;
        }
    }
    if (x>Tree->x)
    {
        if (Tree->right != NULL)
        {
            AddNode(x,Tree->right);
        }
        else
        {
            Tree->right = new Node;
            Tree->right->right = Tree->right->left=NULL;
            Tree->right->x=x;
        }
    }
    
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->x)
        root->left = deleteNode(root->left, key);
    else if (key > root->x)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
    

        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->x = temp->x;
        root->right = deleteNode(root->right, temp->x);
    }
    return root;
}

void rightLeafSum(Node *root, int *sum, int *number){
    if(!root)
        return;
    if(root->right)
        if(root->right->right && root->right->left)
        {
            *sum = root->right->right->x+root->right->left->x;
            *number = root->right->x;
        }
    rightLeafSum(root->right, sum, number);
}

int max(int x, int y) { 
    return (x >= y) ? x : y;
}

int height(Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int AVL(Node* root) {
    if (root == NULL)
        return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && AVL(root->left) && AVL(root->right)) return 1;
    return 0;
}

void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->x);
    }
}

int main(){
    Node *Tree = NULL;
    int kolvo, UserElement,choose;
    cout<<"1) Osnovnoe Zadanie 2)Sbalansirovanost' 3)Nishodiazii\n";
    cin>>choose;
    int summ=0,num=0;
    cout<<"How much elements: "<<endl;
    cin>>kolvo;
    while (kolvo!=0)
    {
        cout<<"Enter Element: ";
        cin>>UserElement;
        AddNode(UserElement,Tree);
        kolvo--;
    }
    ShowTree(Tree);
    cout<<endl;
    switch (choose)
    {
    case 1:
    rightLeafSum(Tree,&summ,&num);
    ShowTree(Tree);
    cout<<"\nSum = "<<summ<<"\tNumber = "<<num<<endl;
    deleteNode(Tree,num);
    ShowTree(Tree);
        break;
    case 2:
        if(AVL(Tree))
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        break;
    case 3:
        postOrderTravers(Tree);
        break;
    }
    return 0;
}
