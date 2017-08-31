//PROGRAMA PARA RESOLVER UM SISTEMA LINEAR USANDO O MÉTODO DE GAUSS JORDAN

#include<stdio.h>

int main()
{
//#############################Declaraçao de varáveis...inicializaçao da matriz###########################################

     int i,j,k,n=4;
     float m[4][5]={{1,1,0,3,4},{2,1,-1,1,1},{3,-1,-1,2,-3},{-1,2,3,-1,4}};
     float s;
     float x[n];
 
//############################################## Imprimir matriz ########################################################
     printf("\n\n\t\tMATRIZ ESTENDIDA\n\n");
     for(i=0;i<=3;i++)
     {
        for(j=0;j<=4;j++)         
        {
               printf("\t%0.2f",m[i][j]);
               
        }
        printf("\n");
     }
     
    
     printf("\n\n");
   
//########### começar zerando 1 elemento da 2 linha,depois o 2 e Repetir para a segunda coluna, a partir do item 3.########

    for(j=0;j<=3;j++)   //começar pela 1 coluna e assim vai...
    {
        for(i=0;i<=3;i++)          
        { 
            if(i>j)
            {  
                 s=-m[i][j]/m[j][j];
                 for(k=0;k<=n;k++)
                 {
                       m[i][k]=s*m[j][k]+m[i][k];
                 }     
            }

        }
        

    } 

}
