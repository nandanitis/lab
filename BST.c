#include <stdio.h>
#include<stdlib.h>

struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};

struct tree *root=NULL;
int countleaf=0;//leaf counting
int level=0;//search

void insertbst()
{
    int x;
    struct tree *curr,*prev=NULL,*p;
    printf("Enter element to be inserted in BST:\t");
    scanf("%d",&x);
    p=(struct tree *)malloc(sizeof(struct tree));
    p->info=x;
    p->right=NULL;
    p->left=NULL;
    if(root==NULL)
    {
        root=p;
    }
    else
    {
        curr=root;
        while(curr!=NULL)
        {
            prev=curr;
            if(x<curr->info)
                curr=curr->left;
            else
                curr=curr->right;
        }
        if(x<prev->info)
            prev->left=p;
        else
            prev->right=p;
    }
}

void createbst()
{
    int size;
    printf("Enter number of elements to be inserted in BST:\t");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        insertbst();
    }
}

struct tree* deletenode(struct tree *root,int x)
{
    struct tree *temp; //temp is for relinking
    if(root == NULL) return NULL;

    if(x < root->info)
    root->left = deletenode(root->left,x);

    else if(x > root->info)
    root->right=deletenode(root->right,x);

    else //x==root->info
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        else //two children
        {
            temp=root->right;  //smallest element from right subtree
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            root->info=temp->info;
            root->right=deletenode(root->right,temp->info);
        }
    }
    return root;
}

// void deletebst()        non-recursive deletion
// {
//     struct tree *temp=root,*prev=root;
//     int x;
//     printf("Enter element to be deleted:\t");
//     scanf("%d",&x);
//     if(root==NULL)
//     {
//         printf("Empty\n");
//         return ;
//     }
//     while(temp->info!=x)
//     {
//         prev=temp;
//         if(x < temp->info)
//             temp=temp->left;
//         else
//             temp=temp->right;
//     }

//     if(temp->left==NULL && temp->right==NULL)
//     {
//         if(x<prev->info)
//             prev->left=NULL;
//         else
//             prev->right=NULL;
//         free(temp);
//     }
//     else if(temp->left==NULL && temp->right!=NULL)
//     {
//         if(x<prev->info)
//             prev->left=temp->right;
//         else
//             prev->right=temp->right;

//         free(temp);

//     }
//     else if(temp->left!=NULL && temp->right==NULL)
//     {
//         if(x<prev->info)
//             prev->left=temp->left;
//         else
//             prev->right=temp->left;

//         free(temp);
//     }
//     else
//     {
//         struct tree *temp2,*prev2;
//         temp2=temp->right;
//         while(temp2->left!=NULL)
//         {   
//             prev2=temp2;
//             temp2=temp2->left;
//         }

//         temp->info=temp2->info;

//         if(temp2->info<prev2->info)
//         {
//             prev2->left=NULL;
//         }

//         else
//         {
//             prev2->right=NULL;
//         }        
//         free(temp2);

        
//     }
// }

void preorder(struct tree *root)
{
    if(root!=NULL)
    {   
        printf("%d\t",root->info);    
        preorder(root->left);
        preorder(root->right);
        
    }
}

void inorder(struct tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}

 

void postorder(struct tree *root)
{
    if(root!=NULL)
    {       
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}

void countleafbst(struct tree *root)
{
    if(root!=NULL)
    {
        countleafbst(root->left);
        if(root->left==NULL && root->right==NULL)
            countleaf++;
        countleafbst(root->right);
    }
}

void maxbst()
{
    struct tree *temp=root;
    if(root==NULL)
        printf("Empty bst\n");
    else
    {
        while(temp->right!=NULL)
            temp=temp->right;
        printf("Max element is %d\n",temp->info);
    }
}

void minbst()
{
    struct tree *temp=root;
    if(root==NULL)
        printf("Empty bst\n");
    else
    {
        while(temp->left!=NULL)
            temp=temp->left;
        printf("Min element is %d\n",temp->info);
    }
}

void searchBST(struct tree *root,int x)
{
    // if(root==NULL) return NULL;
    // if(x<root->info) 
    // {
    //     searchBST(root->left,x);
    //     level++;
    // }
    // else if(x>root->info)
    // {
    //     searchBST(root->right,BST);
    //     level++;
    // }
    // else
    //     return level;
    
    int level=0;
    struct tree *temp=root;
    if(root==NULL)
    {
        printf("no tree\n");
    }
    else
    {
        while(temp!=NULL && temp->info!=x)
        {
            if(x>temp->info)
            {
                temp=temp->right;
                level ++;
            }
            else
            {
                temp=temp->left;
                level++;
            }
        }
        if(temp==NULL)
        {
            printf("no node found\n");
        }
        else
        {
            printf("element found at level%d",level);
        }
    }
}

int main()
{
    while(1)
    {
        int c;
        printf("\n1.Insert\n2.Create\n3.Delete\n4.Preorder\n5.Inorder\n6.Postorder\n7.Number of leaves\n8.Max element\n9.Min element\n10.Search element\n11.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:insertbst();
            break;
            case 2:createbst();
            break;
            case 3:int x;
            printf("Enter element to be deleted:\t");
            scanf("%d",&x);
            root=deletenode(root,x);
            break;
            case 4:
            preorder(root);
            break;
            case 5:
            inorder(root);
            break;
            case 6:
            postorder(root);
            break;
            case 7:countleafbst(root);
            printf("Number of leaves:%d\n",countleaf);
            break;
            case 8:maxbst();
            break;
            case 9:minbst();
            break;
            case 10:int y;
            printf("Enter element to be searched\n");
            scanf("%d",&y);
            searchBST(root,y);
            break;
            default:exit(0);
            break;
        }
    }
    

}


