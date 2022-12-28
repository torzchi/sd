#include <iostream>
#include <string.h>

using namespace std;

struct node{
    char nume[32];
    float nota;
    node *next;
};

void adauga(node *&head, char num[32], float grade){
    node* new_node = new node;
    new_node->nota = grade;
    strcpy(new_node->nume, num);
    new_node->next = head;
    head = new_node;
}
//pentru a afisa in ordinea notelor punem studentii in lista deja sortati

void adaugaOrd(node *&head, char num[32], float grade) {
    node* new_node = new node;
    new_node->nota = grade;
    strcpy(new_node->nume, num);
    if (!head || head->nota < grade) {
        new_node->next = head;
        head = new_node;
    } else {
        node* current = head;
        while (current->next && current->next->nota >= grade) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(node* head) {
    node* current = head;
    while (current) {
        cout << current->nota << " "<<current->nume;
        cout << endl;
        current = current->next;
    }

}

int main(){
    node *root=NULL;
    node *root2=NULL;
    adauga(root,"andy", 7.7 );
    adauga(root,"klad", 5.22 );
    adauga(root,"ingrid", 8.12 );
    adauga(root,"topus", 6.20);
    printList(root);
    cout<<endl;
    cout<<"ordonat";
    cout<<endl;
    adaugaOrd(root2,"andy", 7.7 );
    adaugaOrd(root2,"klad", 5.22 );
    adaugaOrd(root2,"ingrid", 8.12 );
    adaugaOrd(root2,"topus", 6.20);


    printList(root2);
}
