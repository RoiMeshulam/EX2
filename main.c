#include "stdio.h"
#include "my_mat.h"

int main() {
    int i,j,k,m;
    int checker;
    int mat[10][10];
    while(1){
        char ch;
        scanf("%c",&ch);
        switch (ch) {
            case 'A':
                checker=fooA(mat);
                if (checker==1){
                }
                continue;

            case 'B':
                scanf(" %d",&i);
                scanf(" %d",&j);
                checker= fooB(mat,i,j);
                if (checker==1){
                    printf("True\n");
                }
                else{
                    printf("False\n");
                }
                continue;


            case 'C':
                scanf(" %d",&k);
                scanf(" %d",&m);
                checker=fooC(mat,k,m);
                if (checker==-1){
                    printf("-1 \n");
                }
                else{
                    printf("%d \n",checker);
                }
                continue;


            case 'D':
                return 0;
        }
    }
    return 0;
}
