# metodosN2

Programa para resolver um sistema linear usando o metodo de gauss-jordan.

Primeiro inicializei a matriz estendida 4x5,os coeficientes junto com os resultados.Declarei um vetor para receber os resultados.

Segundo imprimi a matriz estendendida.

Terceiro passo comecei da primeira coluna, zerando o segundo elemento, depois o terceiro.Fiz isso de coluna em coluna, transformando a matriz dos coeficientes em triangular superior. Da seguinte forma: de coluna em coluna, testei se o indice i era maior que o indice j (para comecar da segunda linha e do segundo elemento da matriz), se fosse verdade, atribui a uma variavel s a razao do elemento da linha que se encontrava com o elemento correspondente da primeira linha da matriz.Dentro do terceiro "for", sustitui a linha que se encontrava pela multiplicacao dessa razao s com o proprio valor do elemento mais a soma deste. Feito isso, zerei os elementos certos.

Quarto passo, imprimi a matriz dos coeficientes triangular.

Quinto passo,foi achar os valores das variaveis, preenchendo o vetor x. Fiz isso de baixo para cima, achando primeiro o valor de x4. Para achar os outros valores, comecei um "for" da terceira linha e dentro coloquei outro "for" para as colunas, começando da quarta coluna, sustitui o valor de x4, e fui acumulando em uma variavel s a soma da multiplicaçao da variavel com o coeficiente correspondente, percorri todas as colunas, no final gravei o valor da variavel achada no vetor antes de mudar de linha e fazer todo o processo novamente.

Sexto passo foi imprimir os resultados.









