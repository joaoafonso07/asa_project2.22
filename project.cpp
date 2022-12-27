#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

typedef struct {
    int parent;
    int rank;
} node;

static node *tree;
size_t tree_size;


void make_set(size_t i){
    tree[i].rank = 0;
    tree[i].parent = i + 1;
}

int find_set(int x){
    if (tree[x-1].parent != x);
        tree[x-1].parent = find_set(tree[x-1].parent);
    return tree[x-1].parent;
}

void union(int x, int y){
    link(find_set[x], find_set(y));
}

void link(int x, int y){
    if (tree[x-1].rank > tree[y-1].rank){
        tree[y-1].parent = x;
    }
    else{
        tree[x-1].parent = y;
        if(tree[x-1].rank == tree[y-1].rank)
            tree[y-1].rank++;
    }
}


int main() {
    int E, u, w, v; //V = number of vertices, E = number of eges
    unsigned long long result;
    bool empty = true;

    if(scanf("%lu", &tree_size) == -1)
        return -1;

    tree = (node*)malloc(sizeof(node)*tree_size);
    if(tree == NULL){
        return -1;
    }

    if(scanf("%i", &E) == -1)
        return -1;

    std::vector<std::vector<int>> edges;  //vector with e number of vectors representing a heavy edge (u, v, w) 

    /*
    Reads e number of heavy eges (u, v, w) being u and v two vertices conected with a w weight
    */
    for(short i = 0; i < E; i++){ // for each i less than E add the vector to the vector c
        if(scanf("%i %i %i", &u, &v, &w) != 3){
            printf("something wronf with scanf\n");//debug
            return -1;
        }
        edges.push_back({u, v, w});
        
        if(empty == true && edges[i][1] != 0)
            empty = false;
    }




    /*makeset*/
    for(size_t i = 0; i < tree_size; i++){
        make_set(i);
    }
    
    std::sort(edges.begin(), edges.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[2] > b[2];
    });

    printf("\n +++ \n");

    
    for (auto i : edges){
        printf("%i %i %i\n", i[0], i[1], i[2]);

    }


    if(!empty){
        result = 1; //function to develop
    }else
        result = 0;

    std::cout << result << "\n";
    return 0;
}

 