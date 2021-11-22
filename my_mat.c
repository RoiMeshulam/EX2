#include <stdio.h>
#include <math.h>

//foo A
int fooA(int mat[10][10]){
    int i,j;
    for(i=0; i<10;i++){
        for(j=0;j<10;j++){
            printf("Enter value for mat[%d][%d]:",i,j);
            scanf("%d", &mat[i][j]);
            if (mat[i][j]==0 && i!=j){
                mat[i][j]=INFINITY;
            }
        }
    }
    return 1;
}
//foo B
int fooB (int mat[10][10],int helpingMat[10],int i, int j){
    helpingMat[i] = 1;
    helpingMat[j] = 1;
    if(mat[i][j] > 0){
        return 1;
    }
    else{
        int k;
        for(k=0;k<10;k++){
            if(mat[i][k]==0){
                continue;
            }
            else{
                if(helpingMat[k] == 1){
                    continue;
                }
                if(fooB(mat,helpingMat,k,j) != 0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

//int mat_builder (int mat0[10][10],int mat1[10][10],int k ){
//    int checker1,checker2,x,y;
//    for (int i = 0; i <10 ; i++) {
//        for (int j = 0; j <10 ; j++) {
//            if (i==j){
//                mat1[i][j]=0;
//            }
//            else if(i==k){
//                mat1[k][j]=mat0[k][j];
//            }
//            else if(j==k){
//                mat1[i][k]=mat0[i][k];
//            }
//            else{// check what happend when two pairs dont have path
//               checker1=INFINITY;
//               x=mat0[i][k];
//               y=mat0[k][j];
//               checker2=INFINITY;
//                if (x!=INFINITY && y!=INFINITY){
//                    checker2=x+y;
//                }
//                if (mat0[i][j]!=INFINITY){
//                    checker1=mat0[i][j];
//                }
//                if (checker1==INFINITY && checker2==INFINITY){
//                    mat1[i][j]=INFINITY;
//                    continue;
//                }
//                if (checker1!=INFINITY && checker2==INFINITY){
//                    mat1[i][j]=checker1;
//                    continue;
//                }
//                if (checker1==INFINITY && checker2!=INFINITY){
//                    mat1[i][j]=checker2;
//                    continue;
//                }
//                if (checker1<checker2){
//                    mat1[i][j]=checker1;
//                }
//                else{
//                    mat1[i][j]=checker2;
//                }
//            }
//        }
//    }
//    return 1;
//}
//
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




////foo C
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




//foo C
//int fooC(int mat[4][4],int i,int j){
//    int* checker2;
//    int k;
//    int checker= mat[i][j];
//    int mat1[4][4],mat2[4][4],mat3[4][4],mat4[4][4];
//    mat_builder(mat,mat1,0);
//    mat_builder(mat1,mat2,1);
//    mat_builder(mat2,mat3,2);
//    mat_builder(mat3,mat4,3);
//    int* pointers[]={mat1,mat2,mat3,mat4};
//    for (k=0;k<4;k++){
//        checker2= pointers[k]+(4*i)+ j;
//        if (*checker2<checker){
//            checker=*checker2;
//        }
//    }
//    if (checker!=0 && checker!=INFINITY){
//        return checker;
//    }
//    else{
//        return -1;
//    }
//}

//void printMatrice(int mat[4][4]) {
//    int x = 0;
//    int y = 0;
//
//    for(x = 0 ; x < 4 ; x++) {
//        printf(" (");
//        for(y = 0 ; y < 4 ; y++){
//            printf("%d     ", mat[x][y]);
//        }
//        printf(")\n");
//    }
//}


//int main(){
//    int mat[4][4]= {0,3,INFINITY,7,8,0,2,INFINITY,5,INFINITY,0,1,2,INFINITY,INFINITY,0};
//    printf("CHECK7 %d\n", fooC(mat,0,1));
//    //3
//    printf("CHECK8 %d\n", fooC(mat,0,2));
//    //5
//    printf("CHECK9 %d\n", fooC(mat,0,3));
//    //6
//    printf("CHECK7 %d\n", fooC(mat,1,0));
//    //5
//    printf("CHECK8 %d\n", fooC(mat,1,2));
//    //2
//    printf("CHECK9 %d\n", fooC(mat,1,3));
//    //3
//    printf("CHECK7 %d\n", fooC(mat,2,0));
//    //3
//    printf("CHECK8 %d\n", fooC(mat,2,1));
//    //6
//    printf("CHECK9 %d\n", fooC(mat,2,3));
//    //1
//    printf("CHECK7 %d\n", fooC(mat,3,0));
//    //2
//    printf("CHECK8 %d\n", fooC(mat,3,1));
//    //5
//    printf("CHECK9 %d\n", fooC(mat,3,2));
//    //7
//    printf("CHECK7 %d\n", fooC(mat,0,3));
//    //6
//    printf("CHECK8 %d\n", fooC(mat,1,0));
//    //5
//    printf("CHECK9 %d\n", fooC(mat,3,3));
//    //-1
//    printf("CHECK7 %d\n", fooC(mat,0,3));
//    //6
//    printf("CHECK8 %d\n", fooC(mat,1,0));
//    //5
//    printf("CHECK9 %d\n", fooC(mat,3,3));
//    //-1
//    printf("CHECK7 %d\n", fooC(mat,0,3));
//    //6
//    printf("CHECK8 %d\n", fooC(mat,1,0));
//    //5
//    printf("CHECK9 %d\n", fooC(mat,3,3));
//    //-1
//    printf("CHECK7 %d\n", fooC(mat,0,0));
//    //-1
//    printf("CHECK8 %d\n", fooC(mat,1,1));
//    //-1
//    printf("CHECK9 %d\n", fooC(mat,2,2));
//    //-1
//



//    int mat1[4][4],mat2[4][4],mat3[4][4],mat4[4][4];
//    mat_builder(mat,mat1,0);
//    mat_builder(mat1,mat2,1);
//    mat_builder(mat2,mat3,2);
//    mat_builder(mat3,mat4,3);
//    printMatrice(mat1);
//    printf("\n");
//    printMatrice(mat2);
//    printf("\n");
//    printMatrice(mat3);
//    printf("\n");
//    printMatrice(mat4);











//    int t;
//    int helpingMat[10]={0,0,0,0,0,0,0,0,0,0};
//    int mat1[10][10] = {0,12,4,0,0,0,0,0,0,0
//            ,12,0,0,5,4,0,0,0,0,0
//            ,4,0,0,1,0,4,0,0,0,0
//            ,0,5,1,0,0,0,0,0,0,0
//            ,0,3,0,0,0,0,0,0,0,0
//            ,0,0,4,0,0,0,2,0,0,0
//            ,0,0,0,0,0,2,0,0,0,0
//            ,0,0,0,0,0,0,0,0,1,4
//            ,0,0,0,0,0,0,0,1,0,1
//            ,0,0,0,0,0,0,0,4,1,0};
//    int mat2[10][10] = {0,1,0,0,0,0,0,0,1,0
//            ,1,0,0,0,0,0,0,1,0,1
//            ,0,0,0,1,1,0,0,0,0,0
//            ,0,0,1,0,0,0,0,0,0,0
//            ,0,0,1,0,0,0,1,0,0,0
//            ,0,0,0,0,0,0,0,0,1,0
//            ,0,0,0,0,1,0,0,0,0,0
//            ,0,1,0,0,0,0,0,0,0,0
//            ,1,0,0,0,0,1,0,0,0,0
//            ,0,1,0,0,0,0,0,0,0,0};
//    printf("CHECK1 %d",fooB(mat1,helpingMat,8,7));for(t=0;t<10;t++){helpingMat[t]=0;}
//    //True
//    printf("CHECK2 %d",fooB(mat1,helpingMat,0,9));for(t=0;t<10;t++){helpingMat[t]=0;}
//    //True
//    printf("CHECK3 %d",fooB(mat1,helpingMat,1,6));for(t=0;t<10;t++){helpingMat[t]=0;}
//    //False
//    printf("CHECK4 %d",fooB(mat1,helpingMat,9,3));for(t=0;t<10;t++){helpingMat[t]=0;}
//    //False
//    printf("CHECK5 %d",fooB(mat1,helpingMat,0,0));for(t=0;t<10;t++){helpingMat[t]=0;}
//    //False
//    printf("CHECK6 %d",fooB(mat1,helpingMat,6,3));for(t=0;t<10;t++){helpingMat[t]=0;}
//    //True



//

//    return 0;
//}
