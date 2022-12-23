#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>


int main() {
    int V, E, u, w, v; //V = number of vertices, E = number of eges
    unsigned long long result;
    bool empty = true;
    if(scanf("%i", &V) == -1)
        return -1;
    if(scanf("%i", &E) == -1)
        return -1;

    std::vector<std::vector<int> > c(E, std::vector<int>(3)); //vector with e number of vectors representing a heavy edge (u, w, v) 

    /*
    Reads e number of heavy eges (u, w, v) being u and v two vertices conected with a w weight
    */
    for(short i = 0; i < E; i++){ // for each i less than E add the vector to the vector c
        if(scanf("%i %i %i", &u, &w, &v) != 3){
            printf("something wronf with scanf\n");//debug
            return -1;
        }

        printf("u: %i\n", u);//debug
        c[i].push_back(u);

        printf("w: %i\n", w);//debug
        c[i].push_back(w);

        printf("v: %i\n", v);//debug
        c[i].push_back(v);

        if(empty == true && c[i][1] != 0)
            empty = false;
    }

    if(!empty){
        result = 1; //function to develop
    }else
        result = 0;

    std::cout << result << "\n";
    return 0;
}