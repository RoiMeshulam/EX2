#include "stdio.h"
#include "my_mat.h"

int main() {
    int i,j,k,m;
    int checker;
    int mat[10][10];
    while(1){
        char ch;
        printf("Please enter A,B,C or D\n");
        scanf("%c",&ch);
        switch (ch) {
            case 'A':
                checker=fooA(mat);
                if (checker==1){
                    printf("Matrix was built successfully\n");
                }
                continue;

            case 'B':
                printf("please enter i and j in that order\n");
                scanf("%d",&j);
                scanf("%d",&j);
                checker= fooB(i,j,mat);
                if (checker==1){
                    printf("True");
                }
                else{
                    printf("False");
                }
                continue;


            case 'C':
                printf("please enter k and m in that order\n");
                scanf("%d",&k);
                scanf("%d",&m);
                checker=fooC(mat,k,m);
                if (checker==-1){
                    printf("-1 \n");
                }
                else{
                    printf("%d \n",checker);
                }
                continue;


            case 'D':
                printf("""\n time to go, bye");
                return 0;
        }
    }
}
