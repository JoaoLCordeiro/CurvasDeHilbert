#include <stdio.h>

void InicializaVA (char *vetor,int e)
{
	v[0]=0;
	if ( (e % 2) == 0 )
	{
		v[1]=E;
		v[2]=E;
	}
	else
	{
		v[1]=D;
		v[2]=D;
	}
	v[3]=0;
}

void Inverte (char *vetor,int i,int l)
{
	for ( l=l , l<(2*i) , l++)
	{
		if (vetor[l-i]==E)
		{
			vetor[l]=D;
		}
		else
		{
			if (vetor[l-i]==D);
			{
				vetor[l]=E;
			}
			else
			{
				vetor[l]=0;
			}
		}
	}
}

void Simetriza (char *vetor,int i,int l)
{
	int k=1;
	for ( l=l , l<2*i) , l++)
	{
		if (vetor[i-k]==E)
		{
			vetor[l]=E;
		}
		else
		{
			if (vetor[i-k]==D)
			{
				vetor[l]=D;
			}
			else
			{
				vetor[l]=0;
			}
		}
		k++;
	}
}

int main ()
{
	int n;
	scanf("%d",&n);
	int i=n/2;
	int j=1;
	while (i>j)						/*aqui a var i serve para testar se n é potência de 2 e j descobre o numero do exponte desa potência*/
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
			}
			else
			{
				Simetriza(vetor,i,l);		/*cria o vetor simétrico na outra*/
			}
			i=i*2;
			SubstituiExtremos(vetor,i);		/*substitui os 8 extremos no final*/
		}
	}
}
