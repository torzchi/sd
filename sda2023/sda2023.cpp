// Se citeste dintr-un fisier traseul unui autobuz (Oras Oras Distanta) si se verifica daca poate face un itinerariu care sa traca prin toate orasele + lungimea acestuia


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define MAX_NAME_LENGTH 100

struct Edge {
    int to;
    int distance;
    struct Edge *next;
};

struct City {
    char name[MAX_NAME_LENGTH];
    struct Edge *head;
};
struct City cities[MAX_CITIES];
int num_cities = 0;
bool visited[MAX_CITIES];
int sum_distances = 0;

void add_edge(int from, int to, int distance) {
    struct Edge *edge = (struct Edge*) malloc(sizeof(struct Edge));
    edge->to = to;
    edge->distance = distance;
    edge->next = cities[from].head;
    cities[from].head = edge;
}
int get_city_index(char *name) {
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, name) == 0) {
            return i;
        }
    }
    strcpy(cities[num_cities].name, name);
    cities[num_cities].head = NULL;
    return num_cities++;
}

void dfs(int city) {
    visited[city] = true;
    struct Edge *edge = cities[city].head;
    while (edge != NULL) {
        if (!visited[edge->to]) {
            sum_distances += edge->distance;
            dfs(edge->to);
        }
        edge = edge->next;
    }
}

bool is_connected() {
    for (int i = 0; i < num_cities; i++) {
        visited[i] = false;
    }
    dfs(0);
    for (int i = 0; i < num_cities; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *file = fopen("city_distances.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char city1[MAX_NAME_LENGTH];
    char city2[MAX_NAME_LENGTH];
    int distance;
    while (fscanf(file, "%s %s %d", city1, city2, &distance) == 3) {
        int city1_index = get_city_index(city1);
        int city2_index = get_city_index(city2);
        add_edge(city1_index, city2_index, distance);
        add_edge(city2_index, city1_index, distance);
    }
    fclose(file);
    if (is_connected()) {
        printf("All cities are connected.\n");
        printf("Sum of distances: %d\n", sum_distances);
    } else {
        printf("Not all cities are connected.\n");
    }
    return 0;
}
