// A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method //

#include<iostream>
#include<string.h>
using namespace std;

struct node 
{
    int flag;
    char name[20];
    node *down;
    node *next;
};
class GLL
{
    node *head = NULL,*temp = NULL,*ptr,*t1,*t2,*t3;
    public:
    node *Create();
    void insert_book();
    void insert_chapter();
    void insert_section();
    void insert_subsection();
    void Display();
}ob;

node *GLL::Create()
{
    ptr = new node ;
    ptr -> flag = 0;
    cout << "Enter the name: ";
    cin >> ptr ->name ;
    ptr -> down = NULL;
    ptr -> next = NULL;
    return ptr;
}
void GLL::insert_book()
{
    if (head ==NULL)
    {
        t1 = Create();
        head = t1;
    }
    else
    {
        cout<<"Book is already Existing.";
    }
}
void GLL :: insert_chapter()
{
    int n;
    if (head == NULL)
    {
        cout<<"Book is not existing.";

    }
    else 
    {
        cout <<"How many chapters do you want to add : ";
        cin >>n;
        
        for (int i =0;i<n;i++)
        {
            t1 = Create();
            if ( head -> flag == 0)
            {
                head -> down = t1;
                head -> flag = 1;
            }
            else
            {
                temp = head;
                temp = temp -> down;
                while (temp -> next != NULL)
                {
                    temp = temp -> next;
                } 
                temp -> next  = t1;

            }
        }


    }
}
void GLL :: insert_section()
{
    char ch[20];
    int n;
    if (head == NULL)
    {
        cout<<"Book is not Existing";
    }
    else 
    {
        cout << "Enter the Chapter in which you want to add section : ";
        cin >> ch;
        temp = head;
        if (temp -> flag == 0)
        {
            cout <<"No chapters are existing.";
        }
        else 
        {
            temp = temp -> down;
            while (temp != NULL)
            {
               if (strcmp(ch,temp -> name)==0) 
               {
                   cout <<"How many Section do you want to add : ";
                   cin >> n;
                   for (int i=0;i<n;i++)
                   {
                        t1 = Create();
                        if (temp -> flag == 0)
                        {
                            temp -> down = t1;
                            temp -> flag = 1;
                        }
                        else
                        {
                            t2 = temp;
                            t2 = temp -> down;
                            while (t2 -> next != NULL)
                            {
                                t2 = t2 -> next;
                            }
                            t2 -> next = t1;
                        }
                   }
               }  
               temp = temp ->next;
            }   	
        }
    }
}

void GLL :: insert_subsection()
{
    char ch[20] , chs[20];
    int n,m;
    if (head == NULL)
    {
        cout<<"Book is not Existing";
    }
    else 
    {
        cout << "Enter the Chapter in which you want to add section : ";
        cin >> ch;
        temp = head;
        if (temp -> flag == 0)
        {
            cout <<"No chapters are existing.";
        }
        else 
        {
            temp = temp -> down;
            while (temp != NULL)
            {
               if (strcmp(ch,temp -> name)==0) 
               {
                    cout << "Enter the Section in which you want to add Subsection : ";
                    cin >> chs;
                    temp = temp -> down;
                        while (temp != NULL)
                        {
                        if (strcmp(chs,temp -> name)==0) 
                        {
                            cout <<"How many Section do you want to add : ";
                            cin >> m;
                            for (int i=0;i<m;i++)
                            {
                                    t3 = Create();
                                    if (temp -> flag == 0)
                                    {
                                        temp -> down = t3;
                                        temp -> flag = 1;
                                    }
                                    else
                                    {
                                        t2 = temp;
                                        t2 = temp -> down;
                                        while (t2 -> next != NULL)
                                        {
                                            t2 = t2 -> next;
                                        }
                                        t2 -> next = t3;
                                    }
                            }
                        }  
                        temp = temp ->next;
                        }   	
                    }
            }
               
            
        }
    }
}

void GLL :: Display()
{

    if (head == NULL)
    {
        cout<<"Book is not Existing.";
    }
    else 
    {
        temp = head;
        cout<<"\nName of Book is : "<<temp -> name;
        temp = temp -> down;
        while (temp != NULL)
        {
            cout<<"\n\tName of Chapters : "<<temp -> name;
            t1 = temp;
            if (t1 -> flag == 1)
            {
                t1 = t1 -> down;
                while (t1 != NULL)
                {
                   cout <<"\n\t\tName of Sections : "<<t1 -> name ;
                   t3 = t1;
                   if (t3 -> flag == 1)
                   {
                       t3 = t3 -> down;
                       while(t3 != NULL)
                       {
                          cout<<"\n\t\t\tName of Subsections : "<<t3 ->name;
                          t3 = t3 -> next;
                       }
                   }
                   t1 = t1 -> next;
                }

            }

            temp = temp -> next;
        }

    }
}


int main ()
{
    int ch;

    while (1)
    {
        cout<<"\nEnter your Choice :";
        cout<<"\nPress 1 to insert Book";
        cout<<"\nPress 2 to insert Chapter.";
        cout<<"\nPress 3 to insert Section.";
        cout<<"\nPress 4 to insert Sub-Section.";
        cout<<"\nPress 5 to Display."<<endl;
        cin>>ch;
        switch (ch) 
        {
            case 1:
                ob.insert_book();
                break;
            case 2:
                ob.insert_chapter();
                break;
            case 3:
                ob.insert_section();
                break;
           case 4:
                ob.insert_subsection();
                break;
            case 5:
                ob.Display();
                break;
            
        }
    }
    return 0;
}

