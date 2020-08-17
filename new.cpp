#include<iostream>
#include<stdlib.h>

using namespace std;

class list
{
   public:
           struct node
					{
						int rollno;
							 node *next;
					} *first, *last, *temp, *temp1,*save,*ptr,*flag, *z;

    list();
    ~list();
    
	void create(int);
    void insertstart();
    void insertcenter(int);
    void insertend();
    void deletestart();
    void deletecenter(int);
    void deleteend();
    void search(int);
    void reverse();
    void count();
    void display();
};

list::list()
{
    first=NULL;
    last=NULL;
    
}

list :: ~list()
{
    cout<<"Memory has been cleared.";
}
void list :: create(int n)
{
	temp = new node;
	temp-> rollno=n;
	temp->next= NULL;
}

void list :: insertstart()
{
    

    if(first==NULL)
        first=last=temp;

    else
    {
        temp->next=first;
        first=temp;
    }

}

void list :: insertcenter(int abc)
{
    int count=1;

    

    temp1=first;
    while(count<abc-1)
    {
        temp1=temp1->next;
        count++;
    }
	 temp->next=temp1->next;

    temp1->next=temp;
   

}


void list :: insertend()
{
 

    if(first==NULL)
        first=last=temp;

    else
    {
        last->next=temp;
        last=temp;
    }
}


void list :: deletestart()
{
    
    if(first==NULL)
        cout<<" this list is empty.";

    else if(first==last)
    {
        first=last=temp1;
		delete temp1;
		cout<<"node deleted";

    }

    else
    {
        temp1=first;
		first=first->next;
        delete temp1;
        
    }
}

void list :: deletecenter(int abc)
{
    int count=1;
   
    if(first==NULL)
        cout<<"List is empty.";

    
    else
    {
        temp1=first;
        while(count<abc-1)
        {
            temp1=temp1->next;
            count++;
        }
        temp1->next=(temp1->next)->next;
        delete (temp->next);

    }
}

void list:: deleteend()
{

   
    if(first==NULL)
        cout<<"List is empty.";

    else if(first==last)
    {
		first=last=temp1;
		delete temp1; 
        cout<<"Deleted : ";
        first=NULL;
        last=NULL;
    }

    else
    {
        z=first;
        temp1=last;
        while(z->next!=last)
        {
            z=z->next;
        }
		last=z;
		z->next= NULL;
		
        delete temp1;
        
    }
}

void list :: count()
{
    int z=0;
    temp1=first;

    while(temp1!=NULL)
    {
        z++;
        temp1=temp1->next;
    }
    cout<<"No of items: "<<z;
}

void list :: search(int search)
{
    temp1=first; int count=0;
    while(temp1->next!=NULL)
    {
            count++;
            if(temp1->rollno==search)
        {
            cout<<"Item position : "<<count;
            break;
        }
        temp1=temp1->next;
    }
	if(temp1==last)
		cout<<"item not  found";
    if(count==0)
        cout<<"Item not found.";
}

void list :: reverse()
{
  
	temp1=first;
	ptr=last;
    while(temp1!=ptr)
    {
     temp1=temp1->next;
	if(temp1->next==ptr)
	{	
		ptr->next=temp1;
		ptr=temp1;
		temp1=first;
	}
	if(temp1==ptr)
	temp1->next=first;
	first->next= NULL;
	save=last;
	last=first;
	first=save; 
	delete save;
    }
    
}

void list :: display()
{
    temp1=first;
   
    if(first==NULL)
        cout<<"List is empty";

    else
    {
        while(temp1!=NULL)
        {
            cout<<temp->rollno<<" ";
            temp1=temp1->next;
        }
    }
}

int main()
{
   list obj; int ch; char m; int abc,search, n;
   do
    {
        
        cout<<"1. Insert at beginning.\n";
        cout<<"2. Insert in center.\n";
        cout<<"3. Insert at end.\n";
        cout<<"4. Delete from beginning.\n";
        cout<<"5. Delete from center.\n";
        cout<<"6. Delete from end.\n";
        cout<<"7. Search.\n";
        cout<<"8. Reverse.\n";
        cout<<"9. Count the no of items in the list.\n";
        cout<<"10. Displaying the linked list.\n";
        cout<<"Enter choice : ";
        cin>>ch;

        switch(ch) {
            case 1 : cout<<"enter roll number:";
			         cin>>n;
					 obj.create(n);
					 cout<<"Input : ";
			           
                       obj.insertstart();
                       break;

            case 2 : cout<<"enter roll number:";
			         cin>>n;
					 obj.create(n);
					 cout<<"Input  position  of adding : ";
                     cin>>abc;
                     cout<<"Input List Item : ";
                     obj.insertcenter(abc);
                     break;

            case 3 : cout<<"enter roll number:";
			         cin>>n;
					 obj.create(n);
					 cout<<"Input List Item : ";
                     obj.insertend();
                     break;

            case 4 : obj.deletestart();
                       cout<<"List after deleting is : ";
                       obj.display();
                       break;

            case 5 : cout<<"Enter list item no.  to delete : ";
                       cin>>abc;
                       obj.deletecenter(abc);
                       cout<<"List after deletion : ";
                       obj.display();
                       break;

            case 6 : obj.deleteend();
                       cout<<"List after deletion : ";
                       obj.deleteend();
                       break;

            case 7 : cout<<"Enter the itemto search : ";
                       cin>>search;
                       obj.search(search);
                       break;

            case 8 : obj.reverse();
                     cout<<"Reversed list : ";
                     obj.display();
                       break;

            case 9 : obj.count();
                       break;

            case 10 : cout<<"Linked List : ";
                        obj.display();
                        break;

            default   : cout<<"Invalid input";
        }
    cout<<"\nDo you want to continue: ";
    cin>>m;
   }
   while(m=='y');

   return 0;
}
