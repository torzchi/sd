#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N 5

unsigned int hashh(const char *str) {
    unsigned int hash=0;
    int c;
    int p=1;

    while ((c = *str++)) {
        hash +=c * pow(13,p);
        p++;
    }

    return hash % 64;
}

struct Graph {
  int nodes[N][N];
  int node_count;
};
void print_vertices(struct Graph *graph) {
  for (int i = 0; i < graph->node_count; i++) {
    printf("Node %d has vertices: ", i);
    for (int j = 0; j < graph->node_count; j++) {
      if (graph->nodes[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}




int main() {
    FILE *fp;
    int names[N][N]={0};
    char name[32];
    int i=0,j=0;
    fp = fopen("info.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fscanf(fp, "%s", name) != EOF) {
        if (strcmp(name, ".") == 0) {
            i++;
            j = 0;
        } else {
            if(j==0){
            cout<<name<<" "<<hashh(name);
            cout<<endl;}
           names[i][j]=hashh(name);
            j++;
        }

    }

    fclose(fp);


    for (int k = 0; k < N; k++) {
            for(int l=0;l<N;l++)
            {
                if(l==0)
                    printf("%d : ", names[k][l]);

            if(names[k][l]!=0 && l!=0)
            {
             printf("%d ", names[k][l]);
            }
            }
            cout<<endl;
    }
    //apelare print_vertices daca ar merge


    cout<<"maximul=";
    int maxim=0;
    int current=0;
    int m;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        if(names[i][j]!=0)
        {
            current++;
        }
        if(current>maxim)
        {
            maxim=current;
            m=names[i][j];
        }
        current=0;
    }


    cout<<m<<" "<<maxim-1;




}
