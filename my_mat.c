#include <stdio.h>
#include <math.h>

int mat_builder (int mat0[10][10],int mat1[10][10],int k ){
    int checker1,checker2,x,y;
    for (int i = 0; i <10 ; i++) {
        for (int j = 0; j <10 ; j++) {
            if (i==j){
                mat1[i][j]=0;
            }
            else if(i==k){
                mat1[k][j]=mat0[k][j];
            }
            else if(j==k){
                mat1[i][k]=mat0[i][k];
            }
            else{
                checker1=INFINITY;
                x=mat0[i][k];
                y=mat0[k][j];
                checker2=INFINITY;
                if (x!=2147483647 && y!=2147483647){
                    checker2=x+y;
                }
                if (mat0[i][j]!=2147483647){
                    checker1=mat0[i][j];
                }
                if (checker1==2147483647 && checker2==2147483647){
                    mat1[i][j]=INFINITY;
                    continue;
                }
                if (checker1!=2147483647 && checker2==2147483647){
                    mat1[i][j]=checker1;
                    continue;
                }
                if (checker1==2147483647 && checker2!=2147483647){
                    mat1[i][j]=checker2;
                    continue;
                }
                if (checker1<checker2){
                    mat1[i][j]=checker1;
                }
                else{
                    mat1[i][j]=checker2;
                }
            }
        }
    }
    return 1;
}


void printMatrice(int mat[10][10]) {
    int x = 0;
    int y = 0;

    for(x = 0 ; x < 10 ; x++) {
        printf(" (");
        for(y = 0 ; y < 10 ; y++){
            printf("%d     ", mat[x][y]);
        }
        printf(")\n");
    }
}

//foo A
int fooA(int mat[10][10]){
    int i,j;
    for(i=0; i<10;i++){
        for(j=0;j<10;j++){
            printf("Enter value for mat[%d][%d]:",i,j);
            scanf("%d", &mat[i][j]);
            if (mat[i][j]==0 && i!=j){
                mat[i][j]=2147483647;
            }
        }
    }
    printMatrice(mat);
    return 1;
}

int fooC(int mat[10][10],int i,int j){
    int* checker2;
    int k;
    int checker= mat[i][j];
    int mat1[10][10],mat2[10][10],mat3[10][10],mat4[10][10],mat5[10][10],mat6[10][10],mat7[10][10],mat8[10][10],mat9[10][10],mat10[10][10];
    mat_builder(mat,mat1,0);
    mat_builder(mat1,mat2,1);
    mat_builder(mat2,mat3,2);
    mat_builder(mat3,mat4,3);
    mat_builder(mat4,mat5,4);
    mat_builder(mat5,mat6,5);
    mat_builder(mat6,mat7,6);
    mat_builder(mat7,mat8,7);
    mat_builder(mat8,mat9,8);
    mat_builder(mat9,mat10,9);
    int* pointers[]={mat1,mat2,mat3,mat4,mat5,mat6,mat7,mat8,mat9,mat10};
    for (k=0;k<10;k++){
        checker2= pointers[k]+(10*i)+ j;
        if (*checker2<checker){
            checker=*checker2;
        }
    }
    if (checker!=0 && checker!=2147483647){
        return checker;
    }
    else{
        return -1;
    }
}


//foo B
int fooB (int mat[10][10],int i, int j){
    int checker;
    checker= fooC(mat,i,j);
    if (checker!=-1){
        return 1;
    } else{
        return 0;
    }
}
