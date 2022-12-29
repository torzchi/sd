#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


/*
Se citesc datele din fisierul text list-counties-RO.txt (fiecare linie din fisier contine denumirea: string, populatia: nr. real si suprafata judetului: nr. real).
Sa se afiseze lista județelor cu o populatia mai mare decat 500.000 locuitori utilizând o lista liniara simplu inlantuita.
*/


ifstream fin("judete.txt");

struct node {
    char nume[32];
    float p;
    float s;
    struct node *next;
};

void adaug(struct node **head, char n[32], float pop, float sup)
{


    struct node *new_node = new node;
    new_node->p = pop;
    strcpy(new_node->nume,n);
     new_node->s = sup;
    new_node->next = NULL;



    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    struct node *curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
}

void printList(node* head) {
  node* current = head;
  while (current) {
        if(current->s>500.000){
    cout << current->nume<< " "<<current->s;
     cout << std::endl;}
    current = current->next;


  }
}



int main()
{
      node* root=NULL;
    float s,p;
    char nume[32];

    while(!fin.eof()){
        fin>>nume;
        fin>>s;
        fin>>p;
        //cout<<p<<" ";
        adaug(&root,nume,p,s);

    }

    printList(root);
    return 0;
}
