//PROGRAMA PARA RESOLVER UM SISTEMA LINEAR USANDO O MÉTODO DE GAUSS JORDAN

#include<stdio.h>

int main()
{
//#############################Declaraçao de varáveis...inicializaçao da matriz###########################################

     int i,j,k,a,aux,n=3;
     int l[n];
     float m[3][3]={{2,2,-1},{3,3,1},{1,-1,5}};
     float smax,mult,rmax,s,r;
     float b[3]={3,7,5},x[n],v[n];
 
//############################################## Imprimir matriz ########################################################
     printf("\n\n\t\tMATRIZ ESTENDIDA\n\n");
     for(i=0;i<=2;i++)
     {
        for(j=0;j<=3;j++)         
        {
               printf("\t%0.2f",m[i][j]);
               
        }
        printf("\n");
     }
     
    
     printf("\n\n");
   
//########### começar zerando 1 elemento da 2 linha,depois o 2 e Repetir para a segunda coluna, a partir do item 3.########

    for(j=0;j<=2;j++)   //começar pela 1 coluna e assim vai...
    {
        for(i=0;i<=2;i++)          
        {   
            if(i=j & m[i][j]==0)

            {     if( m[i][j=1]==0)  //muda a linha com linha
                  {
                     for(j=0;j<=2;j++)
                     {   a=m[i][j];
                         m[i][j]=m[i+1][j]; 
                         m[i+1][j]=a;
                     }                    
                  }
  
                  else    //muda coluna com a proxima coluna
                  {
                       for(i=0;i<=2;i++)
                       {  a=m[i][j];
                          m[i][j]=m[i][j+1]; 
                          m[i][j+1]=a;
                       }
                  }
            }
 

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
//############################################ Matriz triangular###############################################

     printf("\n\n\t\tMATRIZ TRIANGULAR\n\n");
     for(i=0;i<=2;i++)
     {
        for(j=0;j<=2;j++)         
        {
               printf("\t%0.2f",m[i][j]);
               
        }
        printf("\n");
     }
//################################################# substituições ##############################################     
    x[n-1]=m[n-1][n]/m[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {    s=0;
         for(j=i+1;j<=n-1;j++)
         {
            s=s+m[i][j]*x[j];
         }
         x[i]=(m[i][n]-s)/m[i][i];
    }
//###############################################resultados######################################################
    
    printf("\n\n\t\tRESULTADOS\n\n");
    for(i=0;i<=2;i++)
    {
         printf("\n\tx%d=%0.2f\n",i+1,x[i]);
 
    }
 
    return(0);
}
