#include <stdio.h>
#include <stdlib.h>
// 12 75 30 42 77 5 10 50 96 3 35
struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};

struct BSTNode *root = NULL;
static int nodess = 0;
static int leaf = 0;
static int parent = 0;
static int onechi= 0;

void display()
{

    printf("\n 1) Insert Element into the tree ");
    printf("\n 2) Traverse the Binary Tree");
    printf("\n 3) Find the Maximum Element in the Tree ");
    printf("\n 4)  Find the Minimum Element in the Tree ");
    printf("\n 5)  Count number of nodes    ");
    printf("\n 6)  Number Of Leaf Nodes     ");
    printf("\n 7)  Number Of Parent Nodes     ");
    printf("\n 8)  Height Of The Tree     ");
    printf("\n 9) Number of parents with one child");
    printf("\n 10) Delete a Node From the tree");

    printf("\n  -1 to Exit  ");
}

void insert(int item) 
{
    struct BSTNode *cur = root, *prev;
    struct BSTNode *new_Node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    new_Node->data = item;
    new_Node->left = NULL;
    new_Node->right = NULL;
    if (root == NULL)
    {
        root = new_Node;
        return;
    }
    while (cur != NULL)
    {
        prev = cur;
        if (cur->data < item)
            cur = cur->right;
        else
            cur = cur->left;
    }
    if (prev->data < item)
        prev->right = new_Node;
    else
        prev->left = new_Node;
}

void inorder(struct BSTNode *root) 
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct BSTNode *root) 
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct BSTNode *root) 
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int find_max()
{
    struct BSTNode *cur = root;
    if (root == NULL)
    {
        return -1;
    }
    while (cur->right != NULL)
    {
        cur = cur->right;
    }
    return cur->data;
}

int find_min()
{
    struct BSTNode *cur = root;
    if (root == NULL)
    {
        return -1;
    }
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur->data;
}

int count(struct BSTNode *root) 
{
    if (root != NULL)
    {
        count(root->left);
        nodess++;
        count(root->right);
    }
    return nodess;
}



int leafNodes(struct BSTNode *root) 
{
    if (root != NULL)
    {
        leafNodes(root->left);
        leafNodes(root->right);
        if(root->left==NULL && root->right==NULL) leaf++;
    }
    return leaf;
}
int parentNodes(struct BSTNode *root) 
{
    if (root != NULL)
    {
        parentNodes(root->left);
        parentNodes(root->right);
        if(root->left!=NULL || root->right!=NULL) parent++;
    }
    return parent;
}
int oneChild(struct BSTNode *root) 
{
  
    if (root != NULL)
    {
        oneChild(root->left);
        oneChild(root->right);
        if(root->left==NULL && root->right!=NULL) onechi++;
        if(root->right==NULL && root->left!=NULL) onechi++;
       
    }
    return onechi;
}


int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int getheight(struct BSTNode *root)
{
    if (root == NULL)
        return -1;
    return max(getheight(root->left), getheight(root->right)) + 1;
}





int main()
{

    int num, option, number;
    display();
    printf(" Your OPTION :  ");
    scanf("%d", &option);
    while (option != -1)
    {
        switch (option)
        {

        case 1:
            printf("\n How many Elements do you want to insert into the tree  : ");
            scanf("%d", &num);
            printf("\n Enter the %d elements with spaces : ", num);
            for (int i = 0; i < num; i++)
            {
                scanf("%d", &number);
                insert(number);
            }
            break;

        case 2:
            printf("\n Traversal using inorder : ");
            inorder(root);
            printf("\n Traversal using preorder : ");
            preorder(root);
            printf("\n Traversal using postorder : ");
            postorder(root);
            break;

        case 3:
            number = find_max();
            printf("\n Maximum Element is %d ", number);
            break;

        case 4:
            number = find_min();
            printf("\n Minimum Element is %d ", number);
            break;

        case 5:
            number = count(root);
            printf("\n Number of nodes is %d ", number);
            break;

        case 6:
            number = leafNodes(root);
            printf("\n Number of leaf nodes is %d ", number);
            break;

        case 7:
            number = parentNodes(root);
            printf("\n Number of Parent nodes is %d ", number);
            break;

        case 8:
            number = getheight(root);
            printf("\n Height of the tree is %d ", number);
            break;

        case 9:
            number = oneChild(root);
            printf("\n Number of parents with single child is %d ", number);
            break;

        case 10:
            printf("\n How many Element to delete  : ");
            scanf("%d", &num);
            printf("\n Number of parents with single child is %d ", number);
            break;

        default:
            printf("\n Wrong option, Please try again ");
        }

        display();
        printf("\n Your OPTION :  ");
        scanf("%d", &option);
    }
    return 0;
}