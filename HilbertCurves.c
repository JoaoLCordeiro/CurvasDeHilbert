#include <stdio.h>
#include <stdlib.h>

void InicializaVA (char *vetor,int e)
{
	vetor[0]='0';
	if ( (e % 2) == 0 )
	{
		vetor[1]='E';
		vetor[2]='E';
	}
	else
	{
		vetor[1]='D';
		vetor[2]='D';
	}
	vetor[3]='0';
}

void Inverte (char *vetor,int i)
{
	int l=i;
	for ( l=l ; l<(2*i) ; l++)
	{
		if (vetor[l-i]=='E')
		{
			vetor[l]='D';
		}
		else
		{
			if (vetor[l-i]=='D')
			{
				vetor[l]='E';
			}
			else
			{
				vetor[l]='0';
			}
		}
	}
}

void Simetriza (char *vetor,int i)
{
	int l=i;
	int k=1;
	for ( l=l ; l<(2*i) ; l++)
	{
		if (vetor[i-k]=='E')
		{
			vetor[l]='E';
		}
		else
		{
			if (vetor[i-k]=='D')
			{
				vetor[l]='D';
			}
			else
			{
				vetor[l]='0';
			}
		}
		k++;
	}
}

void ImprimeVetor(char *vetor,int tam)
{
	int i;
	for ( i=0 ; i<tam ; i++)
	{
		printf("%c",vetor[i]);
	}
}

void SubstituiExtremos(char *vetor, int i,int j1)
{
	i=i*2;					/*tamanho atual do vetor*/
	int n=i;				/*tamanho da matriz do vetor atual*/
	int j2=0;				/*exponencial do vetor atual*/
	while (i>1)				/*este while acha o exponencial do vetor atual, mas o que a gente quer é o exponencial do indice da matriz atual*/
	{
		j2++;
		i=i/2;
	}
	j2=j2/2;				/*então dividimos o exponencial por 2, já que o indice da matriz é elevado ao quadrado para achar o tamanho*/
	vetor[0]='0';
	if ((j1 % 2)==0)				/*quer dizer que estamos construindo um vetor de 4,16,...*/
	{	
		if ((j2 % 2)==0)			/*quer dizer que estamos na PARTE que faz um vetor de 4,16,...*/
		{
			vetor[(n/4)-1]='D';
			vetor[n/4]='0';
			vetor[n/2-1]='E';
			vetor[n/2]='E';
			vetor[3*n/4-1]='0';
			vetor[3*n/4]='D';
		}
		else					/*quer dizer que estamos na PARTE que faz um vetor de 8,32,...*/
		{
			vetor[(n/4)-1]='0';
                	vetor[n/4]='E';
               		vetor[n/2-1]='0';
                	vetor[n/2]='0';
                	vetor[3*n/4-1]='E';
                	vetor[3*n/4]='0';
		}
	}
	else						/*quer dizer que estamos construindo um vetor de 8,32,...*/
	{
		if ((j2 % 2)==0)			/*quer dizer que estamos na PARTE que faz um vetor de 4,16,...*/
		{
			vetor[(n/4)-1]='E';
                        vetor[n/4]='0';
                        vetor[n/2-1]='D';
                        vetor[n/2]='D';
                        vetor[3*n/4-1]='0';
                        vetor[3*n/4]='E';
		}
		else					/*quer dizer que estamos na PARTE que faz um vetor de 8,32,...*/
		{
			vetor[(n/4)-1]='0';
                        vetor[n/4]='D';
                        vetor[n/2-1]='0';
                        vetor[n/2]='0';
                        vetor[3*n/4-1]='D';
                        vetor[3*n/4]='0';
		}
	}
	vetor[n-1]='0';
}

void VAtoDRUL (char *vetor,char **matriz,int n,int j)
{
	if ((j % 2) == 1)						/*if que inicializa a matriz em razão da ordem da matriz requerida*/
	{
		matriz[n-1][0]='U';
	}
	else
	{
		matriz[n-1][0]='R';
	}
	int l=n-1;
	int c=0;
	int i;
	for ( i=1 ; i<(n*n) ; i++ )
	{
		if (matriz[l][c]=='U')					/*os ifs grandes testam qual o elemento do local atual da matriz*/
		{
			l=l-1;						/*dentro de cada if grande, ele desloca o local atual*/
			if (vetor[i]=='0')				/*os ifs menores testam o elemento no vetor angular e dão o elemento atual da matriz DRUL*/
			{
				matriz[l][c]='U';
			}
			else
			{
			if (vetor[i]=='D')
			{
				matriz[l][c]='R';
			}
			else /* if (vetor[i]=='E') */
			{
				matriz[l][c]='L';
			}
			}				
		}
		else
		{
		if (matriz[l][c]=='D')
		{
			l=l+1;
			if (vetor[i]=='0')
                        {
				matriz[l][c]='D';
                        }
                        else
                        {
                        if (vetor[i]=='D')
                        {
				matriz[l][c]='L';
                        }
                        else /* if (vetor[i]=='E') */
                        {
				matriz[l][c]='R';
			}
			}
		}
		else				
		{
		if (matriz[l][c]=='R')
		{
			c=c+1;
			if (vetor[i]=='0')
                        {
				matriz[l][c]='R';
                        }
                        else
                        {
                        if (vetor[i]=='D')
                        {
				matriz[l][c]='D';
                        }
                        else /* if (vetor[i]=='E') */
                        {
				matriz[l][c]='U';
                        }
                        }				
		}
		else	/*if (matriz[l][c]=='L')*/
		{
			c=c-1;
			if (vetor[i]=='0')
                        {
				matriz[l][c]='L';
                        }
                        else
                        {
                        if (vetor[i]=='D')
                        {
				matriz[l][c]='U';
                        }
                        else /* if (vetor[i]=='E') */
                        {
				matriz[l][c]='D';
                        }
                        }				
		}
		}
		}
	}
}

void ImprimirMatrizINT (int **matriz,int n)
{
	int i;
	int j;
	for ( i=0 ; i<n ; i++)
	{
		for ( j=0 ; j<n ; j++ )
		{
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}

void ImprimirMatrizCHAR (char **matriz,int n)		
{
	int i;
	int j;
	for ( i=0 ; i<n ; i++)
	{
		for ( j=0 ; j<n ; j++ )
		{
			printf("%c ",matriz[i][j]);
		}
		printf("\n");
	}
}

void DRULtoINT (char **DRUL,int **INT,int n)
{
	int l=n-1;
	int c=0;
	int i;
	for ( i=0 ; i<n*n ; i++ )				/*passa por todos os elementos da matriz*/
	{
		INT[l][c]=i;					/*poe o inteiro i no local atual*/
		if (DRUL[l][c]=='U')				/*esses ifs e elses deslocam o local atual da matriz*/
		{
			l=l-1;
		}
		else
		{
		if (DRUL[l][c]=='D')
		{
			l=l+1;
		}
		else
		{
		if (DRUL[l][c]=='R')
		{
			c=c+1;
		}
		else	/* if (DRUL[l][c]=='L') */
		{
			c=c-1;
		}
		}
		}
	}
}

int main ()
{
	int n;
	scanf("%d",&n);					/*lê a ordem da matriz que precisa ser gerada*/
	float i=n/2;
	int j=1;
	while (i>1)					/*aqui a var i serve para testar se n é potência de 2 e j descobre o numero do exponte desa potência*/
	{
		i=i/2;
		j++;
	}
	if ( i != 1 )
	{
		printf("Erro: Não é uma potência de 2\n");
		return 1;
	}
	else							/*aqui começa a 'execução de verdade'*/
	{
		int n2=n*n;					/*coloco n² em uma variável pra não ter que fazer novamente a conta*/
		char* va;
		va = malloc (n2*sizeof(char));			/*alocando espaço para o 'vetor angular'*/
		InicializaVA(va,j);				/*cria o vetor da 2x2 ou seu inverso*/
		i=4;
		int e=1;					/*uma espécie de boolean disfarçado*/
		while (i<n2)
		{
			if (e==1)
			{
				Inverte(va,i);			/*cria o vetor invertido uma vez*/
				e=0;
			}
			else
			{
				Simetriza(va,i);		/*cria o vetor simétrico na outra*/
				SubstituiExtremos(va,i,j);	/*subtitui os 8 extremos*/
				e=1;
			}
			i=i*2;
		}
		/*ImprimeVetor(va,i);*/					/*tire o comentário para imprimir o vetor angular*/
		/*printf("\n");*/
		char **matrizDRUL = malloc (n*sizeof(char*));		/*aloca o vetor de ponteiros da DRUL*/
		int i2;
                for ( i2=0 ; i2<n ; i2++ )				/*aloca a matriz DRUL*/
                {
                	matrizDRUL[i2] = malloc (n*sizeof(char));
		}
		VAtoDRUL(va,matrizDRUL,n,j);				/*gera a matriz DRUL*/
		/*ImprimirMatrizCHAR(matrizDRUL,n);*/			/*tire o comentário para imprimir a matriz DRUL */
		free(va);						/*libera o espaço usado pelo vetor angular*/
		int **matrizINT = malloc (n*sizeof(int*));		/*aloca o vetor de ponteiros da INT*/
		for (i2=0 ; i2<n ; i2++ )				/*aloca a matriz INT*/
		{
			matrizINT[i2] = malloc (n*sizeof(int));
		}
		DRULtoINT(matrizDRUL,matrizINT,n);			/*passa a matriz do padrão DRUL pro INT*/
		ImprimirMatrizINT(matrizINT,n);				/*imprime a matriz INT*/
		free(matrizDRUL);					/*libera o espaço usado pela matriz DRUL*/
		free(matrizINT);					/*libera o espaço usado pela matriz INT*/
	}
	return 0;
}
