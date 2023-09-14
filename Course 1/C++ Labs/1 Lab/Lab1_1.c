#include <stdio.h>
#include <conio.h>
main(){
    int matr1[10]= {1,2,1,1,3,3,3,5,2,2};
    FILE *fout1;
    fout1 = fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\FileDop1.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        fprintf(fout1,"%d",matr1[i]);
        fprintf(fout1,"\n");
    }
    fclose(fout1);
    int matr2[3],schet=0,kolvo=0;
    FILE *fout2;
    fout2 = fopen("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\File2_Lr2_dops\\FileDop2.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        schet=i;
        kolvo=0;
        while (schet!=10)
        {
            if (matr1[i]==matr1[++schet])
            {
                kolvo++;
            }
            
        }
        if (kolvo==2)
        {
            if (i==4)
            {
                matr2[2]=matr1[4];
            }
            matr2[i]=matr1[i];
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        fprintf(fout2,"%d",matr2[i]);
        fprintf(fout2,"\n");
    }
    
    fclose(fout2);
    printf("END");
}