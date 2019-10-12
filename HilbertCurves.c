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

void Inverte (char *vetor,int i,int l)
{
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

void Simetriza (char *vetor,int i,int l)
{
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

int main ()
{
	int n;
	scanf("%d",&n);
	int i=n/2;
	int j=1;
	while (i>1)					/*aqui a var i serve para testar se n é potência de 2 e j descobre o numero do exponte desa potência*/
	{
		i=i/2;
		j++;
	}
	if ( i != 1 )
	{
		printf("Erro: Não é uma potência de 2");
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
		int l;
		while (i<n2)
		{
			l=i;					/*essa variável guarda o começo do resto do vetor que será criado no laço*/
			if (e==1)
			{
				Inverte(va,i,l);		/*cria o vetor invertido uma vez*/
				e=0;
			}
			else
			{
				Simetriza(va,i,l);		/*cria o vetor simétrico na outra*/
				SubstituiExtremos(va,i,j);	/*subtitui os 8 extremos*/
				e=1;
			}
			i=i*2;
		}
		ImprimeVetor(va,i);
		printf("\n");
	}
	return 0;
}
