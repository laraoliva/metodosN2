//PROGRAMA PARA RESOLVER UM SISTEMA LINEAR USANDO O MÉTODO DE PIVOTEAMENTO

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
//######### Descobrir a maior razao para usar a linha como pivô e anular os outros coeficientes da mesma coluna ###########

    for(k=0;k<=n-1;k++)
    {  
         
         rmax=0;
         for(i=k;i<=n-1;i++)
         {
              r=m[l[i]][k]/v[l[i]];

              if(fabs(r)> fabs(rmax))
              {
                  rmax=r;
                  j=i;
              }
         }

         aux=l[j];    //trocar os indices do vetor l
         l[j]=l[k];  
         l[k]=aux;
  
          
 
         for(i=k+1;i<=n-1;i++) 
         {
             mult=m[l[i]][k]/m[l[k]][k];
             for(a=k;a<=n-1;a++)
             {
                  m[l[i]][a] = m[l[i]][a]-mult*m[l[k]][a];    //zerar os elementos por coluna
             }                
             b[l[i]] = b[l[i]]-mult*b[l[k]];                 //modifica o vetor resposta
         }        


    }
             
     
//############################################ Matriz triangular###############################################

     
     printf("\n\n\t\tMATRIZ TRIANGULAR\n\n"); //imprimir de acordo com o vetor l, pelo qual mudou-se as linhas
     for(i=0;i<=n-1;i++)
     {
        for(j=0;j<=n-1;j++)         
        {
               printf("\t%0.2f",m[l[i]][j]);
               
        }
        printf("\n");
     }
//############################## Resolver o sistema usando os indices do vetor l.###############################

   
    x[l[n-1]]=b[l[n-1]]/m[l[n-1]][l[n-1]];

    for(i=n-1;i>=0;i--)
    {    s=b[l[i]];

         for(j=i+1;j<=n-1;j++)
         {
            s=s-m[l[i]][j]*x[j];
         }
         x[i]=s/m[l[i]][i];
    }
//###############################################resultados######################################################
    
    printf("\n\n\t\tRESULTADOS\n\n");
    for(i=0;i<=n-1;i++)
    {
         printf("\n\tx%d=%0.2f\n",i+1,x[i]);
 
    }
 
    return(0);
}
