#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}
*head;
 /*head of thingy*/ 
 
  
void insert(int num)
{
	/*creates the node to add and the iterator*/
	struct node *toInsert=(struct node *)malloc(sizeof(struct node));
    struct node *iter;
	
	/*adds num to the node to insert and makes the iterator at the head*/
	toInsert->data=num;
    iter=head;
	
	/* if linked list is empty or the first element is larger than the input*/
	
	if (iter==NULL || head->data>num)
	{
		head=toInsert;
		head->next=iter;
		
		
	}
	/* else if the first is a duplicate*/
	else if (iter->data==num)
	{
		return;
	}
	else
	{
		/* traverse while it is not null*/
		while (iter!=NULL)
		{   
	/* duplicate check*/
			if (iter->data==num)
			{
				return;
			}				
			if (iter->data <=num && (iter->next == NULL || iter->next->data > num)) 
			{
				toInsert->next=iter->next;
				iter->next=toInsert;
				return;
			}
			iter=iter->next;
		}
	}
	
	
	

}
 
 
 
void delete(int num)
{
    struct node *temp; 
	struct node *prev;
    temp=head;
	
	/* while it is not null, traverse thingy*/
    while(temp!=NULL)
    {
		/* if it's equal, delete it and free it*/
    if(temp->data==num)
    {
        if(temp==head)
        {
			head=temp->next;
			free(temp);
        return;
        }
        else
        {
			prev->next=temp->next;
			free(temp);
        return;
        }
    }
    else
    {
        prev=temp;
        temp= temp->next;
    }
    }
    return;
}
 
 
void  display(struct node *root)
{
    root=head;
    if(root==NULL)
    {
		return;
    }
    while(root!=NULL)
    {
		printf("%d",root->data);
		if (root->next!=NULL)
			printf("	");
		root=root->next;
    }
    
}
 
 
 

   
int main(int argc, char** argv)
{
	
	FILE *fp = fopen(argv[1],"r");
	char del[]="d";
	char in[]="i";

	
	
	char key[10];
	char num[10];
	while( fscanf(fp, "%s", key) != EOF && fscanf(fp, "%s", num) != EOF)        
		{     
			if ((strcmp(&key,&in)!=0) && (strcmp(&key,&del)!=0))
			{
				printf("error");
				return 0;
			}
			
			if (strcmp(&in,&key)==0)
			{
				int temp=atoi(num);
				insert(temp);
			}
			else
			{
				int temp=atoi(num);
				delete(temp);
			}      
		}                     

	fclose(fp);
	display(head);
	exit(0);
	
}


