#include <iostream>

using namespace std;
/*
 Sa se creeze o lista liniara simplu inlantuita (fiecare element al listei continand un nr. intreg).
Sa se adauge 10 elemente in lista (adaugand elemente la sfarsitului listei).
Sa se afiseze elementele listei astfel create.
Sa se stearga pe rand cele 10 elemente din lista (stergand de fiecare data ultimul nod).
Sa se afiseze elementele listei astfel obtinute.
 */
struct node {
    int data;
    struct node *next;
};

void adaug(struct node **head, int data)
{
    struct node *new_node = new node;
    new_node->data = data;
    new_node->next = NULL;
    //daca e goala lista primul element e capul
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    struct node *curr = *head;
    //daca nu e primul traversam lista pana la sfarsit si il punem in capat
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}
void afis(node *head){
    struct node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

void stergere(struct node **head) {
    if (*head == NULL) {
        return;
    }

    // daca are doar un element
    if ((*head)->next == NULL) {
        *head = NULL;
        return;
    }

    // traversare pana la pen-ultimul
    struct node *aux = *head;
    while (aux->next->next != NULL) {
        aux = aux->next;
    }
    aux->next = NULL;
}

int main()
{
    struct node *head = NULL;

   for(int i=1;i<11;i++)
   {
       adaug(&head, i);
       afis(head);
       cout<<endl;
   }
    for(int i=1;i<11;i++)
    {
        stergere(&head);
        afis(head);
        cout<<endl;
    }

    return 0;
}
