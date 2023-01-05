#include <iostream>
using namespace std;

struct nod{

    int data;
    nod* next;
};

void adauga(nod *&head, int date)
{
    struct nod* nou= new nod;

    nou->data=date;
    nou->next=NULL;


    if(head==NULL) {
        head = nou;
        return;
    }

        nod *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }

        curr->next=nou;
}


void printL(nod *head)
{
    nod *curr=head;
    while(curr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void cycle(nod *head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    nod *slow=head;
    nod *fast=head->next;

    while(fast && fast->next)
    {
        if(slow==fast)
        {
            cout<<"ciclu"<<endl;

            return;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"fara ciclu"<<endl;
}



void removeLoop(struct nod* loop_node, struct nod* head) {
    struct nod *ptr1 = loop_node;
    struct nod *ptr2 = loop_node;

    //nr de noduri in ciclu
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }


    ptr1 = head;
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;

    //primul ptr e capul , al doilea il ducem in caputul ciclului
   //avasam pointerii si o sa ajunga in primul element al ciclului
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    //parcurgem pana la sfarsit si setam pointerul ultimului noi la null
    ptr2->next = NULL;
}
void cycleRemove(nod *head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    nod *slow=head;
    nod *fast=head->next;

    while(fast && fast->next)
    {
        if(slow==fast)
        {
            removeLoop(slow,head);
            return;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
}


int main()
{
    nod *root=NULL;
    for(int i=0;i<1000;i++)
    {
        adauga(root,i);
    }
    nod *f=root;
    for(int i=0;i<4;i++)
    {
        f=f->next;

    }
    f->next=root;
    cout<<"creeare ciclu"<<endl;
    cycle(root);

    cycleRemove(root);
    cout<<"eliminare ciclu"<<endl;
    cycle(root);

   // printL(root);

}
