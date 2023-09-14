#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    char slovo[5]={'s','d','p','g','h'};
    FILE *F1;
    F1 = fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\F1.txt","wt"); 
    for( i=0; i<5; i++ ) { 
        fprintf(F1,"%c\n",slovo[i]);
        fprintf( F1, "%d\n", i ); 
    } 
    fclose(F1);
    int k=0;
    FILE *finput;
    int s;
    finput=fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\F1.txt","r+");  
    
    while ((fscanf(finput, "%d",&s)!=EOF))
    {    if(!finput) break; 
        k++;
    }
    int *c = (int*) malloc(k*sizeof(int));
    rewind(finput);
    FILE *F2;
    F2 = fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\F2.txt","wt"); 
    //записываем в F2 5 строчек
    for(i=1;i<6;i++)
    {
        fscanf(finput, "%d",&c[i]);
        fprintf( F2, "%d\n" ,c[i]);
    }
    fclose(finput);
    
    free(c);
    fclose(F2);
    printf("DONE!");
    return 0;
}