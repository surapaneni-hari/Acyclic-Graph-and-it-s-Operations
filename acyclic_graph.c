#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct Node{
    int ver;
    int weight;
    struct Node* next;
};

struct Adjlist{
    struct Node* head;
};

struct graph{
    int V;
    struct Adjlist* arr;
};

struct graph* create(int V){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->V=V;
    g->arr=(struct Adjlist*)malloc(V * sizeof(struct Adjlist));
    for(int i=0;i<V;++i){
        g->arr[i].head=NULL;
    }
    return g;

}

struct Node* newadj(int ver,int weight){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->ver=ver;
    newnode->weight=weight;
    newnode->next=NULL;
    return newnode;
}

void addEdge(struct graph* g,int source, int dest, int weight){
    struct Node* newnode=newadj(dest,weight);
    newnode->next=g->arr[source].head;
    g->arr[source].head=newnode;
}


void sortfunc(int v, bool visit[], int* stack, int* sI, struct graph* g);
void sort(struct graph* g){
    bool* visit=(bool*)calloc(g->V,sizeof(bool));
    int* stack=(int*)malloc(g->V*sizeof(int));
    int sI=g->V-1;

    for(int i=0;i<g->V;i++){
        if(!visit[i]){
            sortfunc(i,visit,stack,&sI,g);
        }
    }

    printf("DFS Topological Sort: ");
    for(int i=0;i<g->V;i++){
        printf("%d",stack[i]);
    }
    printf("\n");

    free(visit);
    free(stack);

}
void sortfunc(int v,bool visit[],int* stack,int* sI, struct graph* g){
    visit[v]=true;
    struct Node* temp=g->arr[v].head;
    while(temp){
        if(!visit[temp->ver]){
            sortfunc(temp->ver,visit,stack,sI,g);
        }
        temp=temp->next;
    }
    stack[(*sI)--]=v;
}

void shortestpath(struct graph* g,int start){
    int* dist=(int*)malloc(g->V * sizeof(int));
    for(int i=0;i<g->V;i++){
        dist[i]=INT_MAX;
    }
    dist[start]=0;

    int* stack=(int*)malloc(g->V * sizeof(int));
    bool* visit=(bool*)calloc(g->V,sizeof(bool));
    int sI=g->V-1;

    for(int i=0;i<g->V;i++){
        if(!visit[i]){
            sortfunc(i,visit,stack,&sI,g);
        }
    }

    for (int i = 0; i < g->V; i++) {
        int u = stack[i];
        if (dist[u] != INT_MAX) {
            struct Node* temp = g->arr[u].head;
            while (temp) {
                if (dist[temp->ver] > dist[u] + temp->weight) {
                    dist[temp->ver] = dist[u] + temp->weight;
                }
                temp = temp->next;
            }
        }
    }

    printf("Shortest Path from %d:\n", start);
    for (int i = 0; i < g->V; i++) {
        printf("To %d: %d\n", i, dist[i] == INT_MAX ? -1 : dist[i]);
    }

    free(stack);
    free(visit);
    free(dist);
}

void longestpath(struct graph* g, int start) {
    int* dist = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++)
        dist[i] = INT_MIN;

    dist[start] = 0;

    int* stack = (int*)malloc(g->V * sizeof(int));
    bool* visit = (bool*)calloc(g->V, sizeof(bool));
    int sI = g->V - 1;

    for (int i = 0; i < g->V; i++) {
        if (!visit[i]) {
            sortfunc(i, visit, stack, &sI, g);
        }
    }

    for (int i = 0; i < g->V; i++) {
        int u = stack[i];
        if (dist[u] != INT_MIN) {
            struct Node* temp = g->arr[u].head;
            while (temp) {
                if (dist[temp->ver] < dist[u] + temp->weight) {
                    dist[temp->ver] = dist[u] + temp->weight;
                }
                temp = temp->next;
            }
        }
    }

    printf("Longest Path from %d:\n", start);
    for (int i = 0; i < g->V; i++) {
        printf("To %d: %d\n", i, dist[i] == INT_MIN ? -1 : dist[i]);
    }

    free(stack);
    free(visit);
    free(dist);
}

int main() {
    int V = 6;
    struct graph* g = create(V);

    addEdge(g, 0, 1, 5);
    addEdge(g, 0, 2, 3);
    addEdge(g, 1, 3, 6);
    addEdge(g, 1, 2, 2);
    addEdge(g, 2, 4, 4);
    addEdge(g, 2, 5, 2);
    addEdge(g, 2, 3, 7);
    addEdge(g, 3, 5, 1);
    addEdge(g, 4, 5, -1);

    sort(g);
    shortestpath(g, 1);
    longestpath(g, 1);

    return 0;

}

