//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef struct {
    int parent;
    int rank;
} node;

typedef struct {
    int u;
    int v;
    int w;
} edge;

//node *tree;
//size_t tree_size;

/*
void make_set(std::vector <node> tree, size_t i){
    tree[i].rank = 0;
    tree[i].parent = i + 1;
}
*/

int find_set(node tree[], int x){
    if (tree[x-1].parent != x)
        tree[x-1].parent = find_set(tree, tree[x-1].parent);
    return tree[x-1].parent;
}

void link(node tree[], int x, int y){
    //printf("link: %i %i\n", x, y); //debug
    if (tree[x-1].rank > tree[y-1].rank){
        tree[y-1].parent = x;
    }
    else{
        //printf("hear\n"); //debug
        tree[x-1].parent = y;
        if(tree[x-1].rank == tree[y-1].rank){
            //printf("rank==\n"); //debug
            tree[y-1].rank++;
        }   
    }
}

void union_find(node tree[], int x, int y){
    link(tree, find_set(tree, x), find_set(tree, y));
}

int main() {
    int E, u, w, v; //V = number of vertices, E = number of eges
    unsigned long tree_size;
    node *tree;
    unsigned long long result = 0;
    //bool empty = true;

    std::ios::sync_with_stdio(false);
    /*
    if(scanf("%lu", &tree_size) == -1)
        return -1;
    */
    std::cin >> tree_size;

    //std::vector<node> &tree;
    
    tree = (node*)malloc(sizeof(node)*tree_size);
    if(tree == NULL){
        return -1;
    }
    

    /*
    if(scanf("%i", &E) == -1)
        return -1;
    */
    std::cin >> E;

    std::vector<edge> edges(E);  //vector with e number of vectors representing a heavy edge (u, v, w) 
    

    /*
    Reads e number of heavy eges (u, v, w) being u and v two vertices conected with a w weight
    */
    for(short i = 0; i < E; i++){ // for each i less than E add the vector to the vector c
        /*
        if(scanf("%i %i %i", &u, &v, &w) != 3){
            printf("something wrong with scanf\n");//debug
            return -1;
        }
        */
        std::cin >> u >> v >> w;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        /*
        if(empty == true && edges[i][1] != 0)
            empty = false;
        */    
    }




    /*makeset*/
    for(size_t i = 0; i < tree_size; i++){
        tree[i].rank = 0;
        tree[i].parent = i + 1;
        //make_set(tree, i);
    }
    
    std::stable_sort(edges.begin(), edges.end(),
          [](const edge &a, const edge &b) {
        return a.w > b.w;
    
    });

    //printf("\n +++ \n"); //debug

    
    for (auto i : edges){
        printf("%i %i %i\n", i.u, i.v, i.w); //debug
        printf("p: %i %i\n", tree[i.u-1].parent, tree[i.v-1].parent); //debug
        if(find_set(tree, i.u) != find_set(tree, i.v)){ 
            printf("yes\n"); //debug
            union_find(tree, i.u, i.v);
            result += i.w;
        }
        else{
            printf("no\n");
        }
        printf("-----\n"); //debug
    }

    


    
    std::cout << result << "\n";

    free(tree);
    return 0;
}

 