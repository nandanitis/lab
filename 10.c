

#include <stdio.h>
#include <stdlib.h>

struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};
struct BSTNode *root = NULL;

void display()
{

    printf("\n 1) Insert Element into the tree ");
    printf("\n 2) Traverse the Binary Tree");
    printf("\n 3) Delete The Element in the Tree ");
    printf("\n  -1 to Exit  ");
}

void insert(int item) // inserting nodes into a BST
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

void inorder(struct BSTNode *root) // inorder traversal
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct BSTNode* find_min(struct BSTNode *root )
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

struct BSTNode *deleteNode(struct BSTNode *root, int key)
{
    struct BSTNode *temp;
    if (root == NULL)
        return NULL;
    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            temp = find_min(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{

    int num, option, number,key;
     struct BSTNode *curr;
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
            break;

        case 3:
            printf("\n Enter the Value to be deleted in the BST : ");
            scanf("%d",&key);
            curr=deleteNode(root,key);
            if(curr==NULL)
            {
                
                printf("Element not deleted");
            }
            else{
                printf("Element sucessfully Deleted");
            }
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









AVL Tree

#include<stdio.h>
#include<stdlib.h>
struct avl
{
    struct avl *left;
    int info;
    struct avl *right;
    int bal;
};
struct avl *root=NULL;
int max(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
int height(struct avl *root)
{
    if(root==NULL)
    return -1;
    return max(height(root->right),height(root->left))+1;
}
struct avl *left(struct avl *x)
{
    struct avl *y,*z;
    y=x->right;
    z=y->left;
    y->left=x;
    x->right=z;
    x->bal=height(x->left)-height(x->right);
    y->bal=height(y->left)-height(y->right);
    return y;
}
struct avl *right(struct avl *x)
{
    struct avl *y,*z;
    y=x->left;
    z=y->right;
    y->right=x;
    x->left=z;
    x->bal=height(x->left)-height(x->right);
    y->bal=height(y->left)-height(y->right);
    return y;
}
struct avl *get(int n)
{
    struct avl *newnode;
    newnode->info=n;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->bal=0;
    return newnode;
}
struct avl *insert(struct avl *root,int n)
{
    if(root==NULL)
    return get(n);
    if(n<root->info)
    root->left=insert(root->left,n);
    else if(n>root->info)
    root->right=insert(root->right,n);
    else
    return root;
    root->bal=height(root->left)-height(root->right);
    int bal=root->bal;
    if(bal>1 && root->left->info>n)
    {
        return right(root);
    }
    else if(bal<-1 && root->right->info<n)
    return left(root);
    else if(bal<-1 && root->right->info>n)
    {
        root->right= right(root->right);
        return left(root);
    }
    else if(bal>1 && root->left->info<n)
    {
        root->left=left(root->left);
        return right(root);
    }
    return root;
}
void inorder(struct avl *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d  , %d ",root->info,root->bal);
    inorder(root->right);
}
void main()
{
    int n,choice;
    printf("hi");
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter a number");
            scanf("%d",&n);
            root=insert(root,n);
            break;
            case 2:
            inorder(root);
            break;
            default:
            exit(0);
        }
    }
}