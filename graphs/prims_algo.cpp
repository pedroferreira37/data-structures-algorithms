#include <stdlib.h>
#include <iostream>

#define V 8
#define I 32767

using namespace std;

int cost [V][V] =  {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 6},
            {I, I, 9, I, 10, I, I, I},
            {I, I, I, 8, I, 12, I, 11},
            {I, I, I, I, 12, I, 18, 16},
            {I, 5, I, I, I, 18, I, I},
            {I, I, 6, I, 11, 16, I, I}};

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][7];


int main() {
    int i, j, k, u, v, n = 7, min = I;

    for(i = 1; i <= n; i++) {
        for(j = i; j <= n; j++) {
            if(cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for(i = 0; i <= n; i++) {
        if(near[i] != 0) {

        if(cost[i][u] < cost[i][v]) {
            near[i] = u;
        } else {
            near[i] = v;
        }

        }
    }

    for(i = 1; i < n - 1; i++) {
        min = I;
        for(j = 1; j <= n; j++) {
            if(near[j] != 0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        
        for(j  =1; j <= n; j++) {
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }


    for(i = 0; i < n - 1; i++) {
        cout << "(" << t[0][i] <<  "," << t[1][i] << ")" << endl;
    }
}