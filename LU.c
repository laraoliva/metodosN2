//PROGRAMA PARA RESOLVER UM SISTEMA LINEAR USANDO LU

#include<stdio.h>
#include<stdlib.h>
#define dim 4



//############################funçao imprime############################

void imprime(double m[][dim+1])
{
   int i,j;
   
    printf("\n\n\t\tMATRIZ ESTENDIDA\n\n");

      for(i=0;i<dim;i++)
     {
        for(j=0;j<dim+1;j++)         
        {
               printf("\t%0.2f",m[i][j]);
               
        }
        printf("\n");
     }
     
    
     printf("\n\n");

}
//#################################funaço matrix triangular...####################
void triangular(double m[][dim+1])
{
   int i,j;

   printf("\n\n\t\tMATRIZ TRIANGULAR\n\n");

   for(i=0;i<dim;i++)
   {
        for(j=0;j<dim;j++)         
        {
               printf("\t%0.2f",m[i][j]);
               
        }
        printf("\n");
     }
     
    
     printf("\n\n");

}
//##################################### funçao zerar###############################
void zerar(double  m[][dim+1])
{
    int i,j,k;
    double s;   

    for(j=0;j<dim;j++)   //começar pela 1 coluna e assim vai...
     {
        for(i=0;i<dim;i++)          
        { 
            if(i>j)
            {  
                 s=-m[i][j]/m[j][j];
                 for(k=0;k<=dim;k++)
                 {
                       m[i][k]=s*m[j][k]+m[i][k];
                 }     
            }

        }
        

    }

}

//#############################funçao para resolver o sistema...#############################

void resultados(double m[][dim+1])
{
   double x[dim],s;
   int i,j;

    x[dim-1]=m[dim-1][dim]/m[dim-1][dim-1];

    for(i=dim-2;i>=0;i--)
    {    s=0;
         for(j=i+1;j<=dim-1;j++)
         {
            s=s+m[i][j]*x[j];
         }
         x[i]=(m[i][dim]-s)/m[i][i];
    }

    printf("\n\n\t\tRESULTADOS\n\n");
    for(i=0;i<dim;i++)
    {
         printf("\n\tx%d=%0.2f\n",i+1,x[i]);
 
    }
} 

int main(void)
{
//#############################inicializaçao da matriz###########################################

     double m[4][5]={{1,1,0,3,4},{2,1,-1,1,1},{3,-1,-1,2,-3},{-1,2,3,-1,4}};
     
     
     imprime(m);
    
     zerar(m);

     triangular(m);

     resultados(m);
     
}
