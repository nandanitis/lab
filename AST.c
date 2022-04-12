#include <stdio.h>
#include<stdlib.h>

struct atree
{
    int info;
    struct atree *left;
    struct atree *right;
    int balfac;  //balance factor(for rotation)
};

struct atree *root=NULL;

int big(int a,int b)
{
    if(a<b)
    return b;
    else
    return a;  
}

int height(struct atree *root)
{
    if(root==NULL)
        return -1;//using return 0 we get levels as 1,2,3 or else its 0,1,2
    else
        return(1+big(height(root->left),height(root->right)));
}

struct atree *lrotation(struct atree *x)
{
    struct atree *y,*z;
    y=x->right;
    z=y->left;
    y->left=x;
    x->right=z;
    x->balfac=height(x->left)-height(x->right);
    y->balfac=height(y->left)-height(y->right);
    return y;
}

struct atree *rrotation(struct atree *x)
{
    struct atree *y,*z;
    y=x->left;
    z=y->right;
    y->right=x;
    x->left=z;
    x->balfac=height(x->left)-height(x->right);
    y->balfac=height(y->left)-height(y->right);
    return y;
}
struct atree *arrange(struct atree *root,int x)
{
    int balance;
    root->balfac=height(root->left)-height(root->right);
    balance=root->balfac;

    if(balance>1 && x<root->left->info)  //left side is heavier,x inserted left
        return rrotation(root);

    if(balance<-1 && x>root->right->info) // right side is heavier,x inserted right
        return lrotation(root);

    if(balance>1 && x>root->left->info) //left side is heavier,x inserted right
    {
        root->left=lrotation(root->left);
        return rrotation(root);
    }

    if(balance<-1 && x<root->right->info) //right side is heavier,x inserted left
    {
        root->right=rrotation(root->right);
        return lrotation(root);
    }
    return root;
}

struct atree *insertast(struct atree *root,int x)
{
    struct atree *p;
    if(root==NULL)
    {
        p=(struct atree *)malloc(sizeof(struct atree));
        p->info=x;
        p->right=NULL;
        p->left=NULL;
        p->balfac=0;
        return p;
    }

    else if(x<root->info)
    {
        root->left=insertast(root->left,x);
        root=arrange(root,x);
    }

    else if(x>root->info)
    {
        root->right=insertast(root->right,x);
        root=arrange(root,x);
    }
    return root;
}

void inorder(struct atree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}

void preorder(struct atree *root)
{
    if(root!=NULL)
    {   
        printf("%d\t",root->info);    
        preorder(root->left);
        preorder(root->right);
        
    }
}

int main()
{
    while(1)
    {
        int c;
        printf("\n1.Insert in AVL Search Tree\n2.Inorder\n3.Preorder\n4.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            int x;
            printf("Enter element to be inserted in AVL Search Tree:\t");
            scanf("%d",&x);
            root=insertast(root,x);
            break;
            case 2:
            inorder(root);
            break;
            case 3:
            preorder(root);
            break;
            default:
            exit(0);
            break;
        }
    }
    

}