//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef struct {
    unsigned long parent;
    unsigned long rank;
} node;

typedef struct {
    unsigned long u;
    unsigned long v;
    unsigned long w;
} edge;

void make_set(node tree[], size_t tree_size){
    for(size_t i = 0; i < tree_size; i++){
        tree[i].rank = 0;
        tree[i].parent = i + 1;
    }
}

unsigned long find_set(node tree[], unsigned long x){
    if (tree[x-1].parent != x)
        tree[x-1].parent = find_set(tree, tree[x-1].parent);
    return tree[x-1].parent;
}

void link(node tree[], unsigned long x, unsigned long y){
    if (tree[x-1].rank > tree[y-1].rank){
        tree[y-1].parent = x;
    }
    else{
        tree[x-1].parent = y;
        if(tree[x-1].rank == tree[y-1].rank){
            tree[y-1].rank++;
        }   
    }
}

void union_find(node tree[], unsigned long x, unsigned long y){
    link(tree, find_set(tree, x), find_set(tree, y));
}

unsigned long Kruskal(node tree[], std::vector<edge> edges){
    unsigned long result = 0;



    for (auto i : edges){
        if(find_set(tree, i.u) != find_set(tree, i.v)){ 
            union_find(tree, i.u, i.v);
            result += i.w;
        }
    }
    return result;
}    


int main() {
    unsigned long E, u, v, w; //E = number of eges, u = vertice, v = vertice, w = weight
    unsigned long tree_size;
    node *tree;
    //unsigned long long result = 0;

    std::ios::sync_with_stdio(false);
    
    std::cin >> tree_size;
    
    tree = (node*)malloc(sizeof(node)*tree_size);
    if(tree == NULL){
        return -1;
    }
    
    std::cin >> E;

    std::vector<edge> edges(E);  //vector with E number of heavy edges (u, v, w) 
    

    /*
    Reads e number of heavy eges (u, v, w) being u and v two vertices conected with a w weight
    */
    for(unsigned long long i = 0; i < E; i++){ // for each i less than E change the struct edge conteined in the vector edges
      
        std::cin >> u >> v >> w;

        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
     
    }



    make_set(tree, tree_size);
    
    std::stable_sort(edges.begin(), edges.end(),
          [](const edge &a, const edge &b) {
        return a.w > b.w;
    
    });

    
    std::cout << Kruskal(tree, edges) << "\n";

    free(tree);
    return 0;
}

 