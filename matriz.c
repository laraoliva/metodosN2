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
      printf("\n\n\t\tMATRIZ  DOS COEFICIENTES\n\n");
     for(i=0;i<=n-1;i++)
     {
        for(j=0;j<=n-1;j++)         
        {
               printf("\t%0.2f",m[i][j]);
               
        }
        printf("\n");
     }
     
    
     printf("\n\n");
   
//################ Gravar um vetor l com indices de linha e colocar o maior valor de cada linha em um vetor v ############

     for(i=0;i<=n-1;i++)
     {
         l[i]=i;
         smax=0;

         for(j=0;j<=n-1;j++)   //loop para gravar o valor max de cada linha
         {
             if( fabs(m[i][j])> fabs(smax))
                smax=m[i][j];       
         }
         
         v[i]=smax;   //grava no vetor os valores max

     }

     printf("\n\n\t\t O VETOR COM OS MAIORES VALORES DA MATRIZ\n\n");
     for(i=0;i<=n-1;i++)
     {
         printf("\n\t%0.2f\n",v[i]);
       
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
