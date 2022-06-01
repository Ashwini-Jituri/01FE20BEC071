//count number of nodes in a tree
#include<stdio.h>
struct node
{ int data;
struct node *left,*right;
};


struct node * getnode()
{
    return malloc(sizeof(struct node));
}

void readinfo(struct node *p)
{
    scanf("%d",&p->data);
}


void displayinfo(struct node *p)
{
    printf("%d",p->data);
}

void freenode(struct node *p)
{
    free(p);
}

struct node *insertnode(struct node *par,struct node *nw)
{
    if(par==NULL)
    {
        return nw;
    }

    else if(nw->data<par->data)
    par->left=insertnode(par->left,nw);

    else if(nw->data>par->data)
    par->right=insertnode(par->right,nw);

    else
        {printf("node exists\n");
        freenode(nw);
        }
}

int countnode(struct node *cur)
{int count=0;
   if(cur!=NULL)
{  count=1+countnode(cur->left)+countnode(cur->right);
   return count;
}

else
    return 0;
}

int main()
{
    struct node * root,*nuw;
    root=NULL;
    int ch,count,data;
scanf("%d",&ch);
    while(ch==1)
  {
    switch(ch)
    {
        case 1:nuw=getnode();
               printf("enter data\n");
               nuw->data=scanf("%d",&data);
              nuw->left=nuw->right=NULL;
              root=insertnode(root,nuw);
              break;
    }
    count=countnode(root);
    printf("  %d",count);
}

}
