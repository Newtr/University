#include <stdio.h>
#include <conio.h>
main(){
    int matr1[5]= {1,2,1,1,3};
    FILE *fout1;
    fout1 = fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\FileA.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fout1,"%d",matr1[i]);
        fprintf(fout1,"\n");
    }
    fclose(fout1);
    int matr2[5],schet=0;
    FILE *fout2;
    fout2 = fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\FileB.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        schet=i;
        while (schet!=5)
        {
            if (matr1[i]==matr1[++schet])
            {
                matr1[i]=0;
            }
            
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        fprintf(fout2,"%d",matr2[i]=matr1[i]);
        fprintf(fout2,"\n");
    }
    
    fclose(fout2);
    printf("END");
}