//PROGRAMA PARA RESOLVER UM SISTEMA LINEAR USANDO LU

#include<stdio.h>
#include<stdlib.h>
#define dim 4


//##################################### ler matriz a partir de um arquivo ########################
double **lermatriz()
{
   double **m,a;
   int i,j;
   char nome[100];

   FILE *leitura;
   
   printf("\n\n\t\tDIGITE O NOME DO ARQUIVO QUE SERA USADO PARA LER OS VALORES DA MATRIZ:\n\n");
   scanf("%s",nome);

   leitura= fopen(nome,"r"); 
   

    m=malloc(dim*sizeof(double *));
    

    for (i=0;i<dim;i++)
    {   
        
          m[i]=malloc((dim+1)*sizeof(double));
    }

    i=j=0;

    while (fscanf(leitura,"%lf",&a) !=EOF) 
    {
       
       if(j==dim+1)
       { 
          
          j=0;
          i++;
         
       }
       m[i][j]=a;
       j++;

    }
    return m;
}

//############################funçao imprime############################

void imprimeEX(double **m)
{
   int i,j;
   

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
//#################################funçao matrix triangular...####################
void imprime(double **m)
{
   int i,j;


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
void zerar(double  **m)
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

void resultados(double **m)
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

    printf("\n\n\t\tRESULTADOS PELA ELIMINAÇAO DE GAUSS\n\n");
    for(i=0;i<dim;i++)
    {
         printf("\n\tx%d=%0.2f\n",i+1,x[i]);
 
    }
} 

//################################## calcular L e U #############################################

double **calcmatrizU(double **m,double **U,double **L,int k)
{
    int j,s;
    double soma;

    for(j=k;j<=dim-1;j++)
    {
          soma=0;

          for(s=0;s<=k;s++)
          {
               soma=soma+L[k][s]*U[s][j];
          }

          U[k][j] = m[k][j] -soma;
    }
    return U;
}


double **calcmatrizL(double **m,double **U,double **L,int k)
{
    int i,s;
    double soma;

    for(i=k+1;i<dim;i++)
    {
       soma=0;
       for(s=0;s<=k;s++)
       {
             soma=soma+L[i][s]*U[s][k];
       }
       L[i][k] = (m[i][k] - soma)/U[k][k];
    } 
    return L; 
}

//###################### funçao para resolver Lz=b (triangular inferior)########################

double *triangIN(double *b,double **L)
{
   int i,j;
   double *z,soma;
   
   z=malloc(dim*sizeof(double *));

   z[0]=b[0];
   
   for(i=1;i<dim;i++)
   {
       soma=0;
       for(j=0;j<=i;j++)
      {
         soma = soma + L[i][j]*z[j];
      }
      z[i] = b[i]-soma;
   }
   return z;
}

//###################### funçao para resolver Ux=z (triangular superior)#######################

double *triangSUP(double **U, double *z)
{
   int i,j;
   double *x,soma;

   x=malloc(dim*sizeof(double *));

   x[dim-1] = z[dim-1]/U[dim-1][dim-1];
   
   for(i=dim-2;i>=0;i--)
   {
      soma=0;

      for(j=i+1;j<dim;j++)
      {
          soma = soma + U[i][j]*x[j];
      }
     x[i] = (z[i]-soma)/U[i][i];
   }
   return x;
}



int main(void)
{
//#############################inicializaçao da matriz###########################################

    double **m,**L,**U,*x,*z,*b;
    int i,k;
   
    m=malloc(dim*sizeof(double *));
    L=malloc(dim*sizeof(double *));
    U=malloc(dim*sizeof(double *));
    x=malloc(dim*sizeof(double *));
    z=malloc(dim*sizeof(double *));
    b=malloc(dim*sizeof(double *));

    for (i=0;i<dim;i++)
    {    
          m[i]=malloc((dim+1)*sizeof(double));
          L[i]=malloc((dim)*sizeof(double));
          U[i]=malloc((dim)*sizeof(double));
          
    }

    m=lermatriz();

    for(i=0;i<dim;i++)
    {
                             //vetor b de resposta para usar na funçao
       b[i]=m[i][dim];
       printf("%lf\n",b[i]);

    }
  
    printf("\n\n\t\tMATRIZ ESTENDIDA\n\n");
    imprimeEX(m);

    for (k=0;k<dim;k++)
    {    
        L[k][k]=1;

        U=calcmatrizU(m,U,L,k);   
       
        L=calcmatrizL(m,U,L,k);       
    }

    zerar(m);

    printf("\n\n\t\tMATRIZ TRIANGULAR\n\n");
    imprime(m);

    resultados(m);
    
    printf("\n\n\t\tMATRIZ U: \n\n");
    imprime(U);
    printf("\n\n\t\tMATRIZ L: \n\n");
    imprime(L); 

    z=triangIN(b,L);
    x=triangSUP(U,z);
    
    printf("\n\n\t\tRESULTADOS PELO METODO LU:\n\n");
    for(i=0;i<dim;i++)
    {
         printf("\n\tx%d=%0.2f\n",i+1,x[i]);
 
    }

}
