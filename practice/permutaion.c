#include<stdio.h>
int taken[20];
int position[20];

void generate_p(int idx, int n) {
    int i;
    if(idx == n){
        for(i = 0; i < n; i++){
            printf("%d ", position[i]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++){
        if(taken[i] == 0){
            taken[i] = 1;
            position[idx] = i;

            generate_p(idx+1, n);

            taken[i] = 0;
        }
    }

}
int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 0; i <= n; i++) {
        taken[i] = 0;
        position[i] = 0;
    }
    generate_p(0, n);
    return 0;
}
