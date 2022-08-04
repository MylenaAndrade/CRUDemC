#include<stdio.h>
/*
		*FAETERJ-Rio*
		TRABALHO DA AV2
		POR MYLENA GUSM�O E
		NATALIE MARQUES
		
i. Inser��o de um n�mero no vetor;
ii. Remo��o de determinado valor;
iii. Altera��o de um valor por outro;
iv. Busca de determinado elemento no vetor,
retornando a sua posi��o, se encontrado no
vetor, ou o valor -1, caso contr�rio;
v. Exibi��o de todos os elementos do vetor;
vi. E, por �ltimo, a op��o de sair do programa.
*/

//mostrando que existe fun��es
int vetorVazio(int quant);
int inserirNumero(int vetor[], int *quant, int n);
int removerNumero(int vetor[], int *quant, int n);
int alterarNumero(int vetor[], int *quant, int num1, int num2);
int buscarNumero(int vetor[], int quant, int n);
void exibirVetor(int vetor[], int quant);

//declarando uma constante de CAP elementos e uma constante para TRUE e FALSE
#define CAP 10
#define TRUE 1
#define FALSE 0

//fun��o principal MAIN
void main(){    
//declara��o de vari�veis
	int v[CAP]={0}, quant=0;
	int numeroI, numeroR, numeroB, numeroA, numeroA2;
	char codigo;
	
//estrutura de repeti��o 'Do...while' para o MENU
	do{
		printf("\t     MENU ");
		printf("\n\t--------------");
		printf("\n Digite [1] para: Inserir  \n Digite [2] para: Remover  \n Digite [3] para: Alterar ");
		printf("\n Digite [4] para: Buscar  \n Digite [5] para: Exibir");
		printf("\n Digite [S] Se deseja encerrar o programa\n\n");
		printf("Insira o codigo: ");
		fflush(stdin);
		scanf("%c", &codigo);
		codigo=toupper(codigo); 
		printf("\n\n");
		
	//switch case para cada escolha do usu�rio	
		switch (codigo){
				case '1':
					//pedindo para o usu�rio informar o n�mero que ele deseja
						printf("Digite um numero: ");
						scanf("%d", &numeroI);
						//estrutura de condi��o para se os casos dentro do inserir forem falsos o usu�rio n�o pode fazer a a��o
						if(inserirNumero(v, &quant, numeroI)==FALSE)
						{
							printf("\nIMPOSSIVEL SEGUIR COM A OPERACAO!\n");
						}
						
					break;	
		
					
				case '2':
					//pedindo para o usu�rio informar o n�mero que ele deseja remover
					printf("Selecione o numero que deseja remover: ");
					scanf("%d", &numeroR);
					//chamando a fun��o remover e se retornar FALSE � pq o n�mero inserido � inv�lido
					if(removerNumero(v, &quant, numeroR)==FALSE)
					{
						printf("\nIMPOSSIVEL SEGUIR COM A OPERACAO!\n");
					}
				break;
				
				case '3':
					//pedindo para o usu�rio informar o n�mero que ele deseja alterar
					printf("Digite o numero que deseja alterar: ");
					scanf("%d", &numeroA);
					//pedindo para o usu�rio informar o n�mero que ele vai substituir o q ele removeu
					printf("Digite o numero que o substituira: ");
					scanf("%d", &numeroA2);
					//chamando a fun��o alterar e se retornar FALSE � pq um dos n�meros ou os n�meros inseridos s�o inv�lidos
					if(alterarNumero(v, &quant, numeroA, numeroA2)==FALSE)
					{
						printf("\nIMPOSSIVEL SEGUIR COM A OPERACAO!\n");
					}
					
				break;
				
				case '4':
					//pedindo para o usu�rio informar o n�mero que ele deseja buscar
					printf("Digite o numero que deseja buscar: ");
					scanf("%d", &numeroB);
					//chamando e printando a fun��o buscar
					printf("\nA posicao do numero e: %d\n", buscarNumero(v, quant, numeroB));
				break;
				
				case '5':
					//chamando a fun��o exibir
				  	exibirVetor(v, quant);
				break;
					
			}
			system("pause");
			system("cls");
		}while(codigo!='S');
		 
		
			
}

//fun��o para verificar se o vetor est� cheio ou vazio
int vetorVazio(int quant){
	  if(CAP == quant)
	  {
	  	//se o vetor tiver 'cheio' retornar FALSE
         return FALSE;
      }else 
	  	  {
	  	  	//se o vetor tiver 'vazio' retornar TRUE, isso quer dizer que ainda h� espa�o em que o usu�rio possa inserir
        	return TRUE; 
    	  }
}

//fun��o para inserir um n�mero ordenado crescentemente e sem repeti��o
int inserirNumero(int vetor[], int *quant, int n){
//declara��o de vari�veis
	int num, i;
	
	//verificando se o vetor se encontra vazio 
	if(vetorVazio(*quant)==FALSE)
	{
		return FALSE;
	}
	
		
	//verificando se j� existe n�meros iguais no vetor
	if(buscarNumero( vetor, *quant, n)!=(-1))
	{
		return FALSE;
	}
	
	//verificando se � o primeiro n�mero do vetor a ser inserido,se for ent�o atribuir sem fazer altera��es
	if((*quant)==0 )
	{
		vetor[0]=n;
		(*quant)++;
		return TRUE;
		
	}else{
		//verificando se o �ltimo n�mero que foi digitado, � maior que o elemento anterior a ele no vetor, se sim ent�o atribuir sem fazer altera��es
		if(n>vetor[*quant-1])
		{
			vetor[*quant]=n;
			(*quant)++;
			return TRUE;
		}else{
			//se caso todos os verificando de cima forem falsos, os elementos do vetor ser�o trocados e reorganizados em ordem
			for(i=0; i<*quant; i++)
			{
				//estrutura de repeti��o para ordenar crescentemente o vetor
				if(n<vetor[i])
				{
					num=vetor[i];
					vetor[i]=n;
					n=num;
				}
			}
		}
	}
	
	printf("\n");

	//atribuindo a vari�vel n, j� organizada, ao vetor	
	vetor[*quant]=n;
	
	//adicionando 1 unidade no vetor
	(*quant)++;
	
	//concluindo com perfei��o e retornando TRUE
	return TRUE;
}

//fun��o para a remo��o de um determindado n�mero
int removerNumero(int vetor[], int *quant, int n){
//declara��o de vari�veis
	int posicao, i;
	
	//atribui��o da vari�vel 'posi��o' para o retorno da fun��o
	posicao=buscarNumero( vetor, *quant, n);
	
	//estrutura de condi��o caso a posicao for -1 retornar FALSE imediatamente
	 if(posicao==-1)
	 {
	 	return FALSE;
	 }
	 
	//varrendo o vetor da posi��o que foi encontrada at� o quant 
	for(i=posicao; i<*quant-1; i++)
		{
			vetor[i]=vetor[i+1];
		}
		
	//removendo 1 unidade da quantidade que tinha no vetor
	(*quant)--;
	
	//concluindo com perfei��o e retornando TRUE
	return TRUE;
	
}

//fun��o para a altera��o de um determindado n�mero por outro
int alterarNumero(int vetor[], int *quant, int num1, int num2){
	//declara��o de vari�veis
	int numero, numero1;
	
	//atribuindo o n�mero a uma vari�vel caso o n�mero digitado exista no vetor
	if(buscarNumero( vetor, *quant, num1)!=(-1))
	{
		numero=num1;
	}else{
		//caso n�o exista retornar falso e assim n�o podendo seguir com a opera��o
		return FALSE;
	}
	
	//atribuindo o n�mero a uma vari�vel caso o n�mero digitado n�o exista no vetor
	if(buscarNumero(vetor, *quant, num2)==(-1))
	{
		numero1=num2;
	}else{
		//caso exista retornar falso e assim n�o podendo seguir com a opera��o
		return FALSE;
	}
	
	//chamando a funcao remover para tirar o n�mero j� existente do vetor
	removerNumero(vetor, quant, numero);
	//chamando a funcao inserir para inserir o novo n�mero que o usu�rio digitou 
	inserirNumero(vetor, quant, numero1);
	
	//concluindo com perfei��o e retornando TRUE
	return TRUE;
}


//fun��o para buscar determinado n�mero no vetor
int buscarNumero(int vetor[], int quant, int num){
//declara��o de vari�veis
	int i;
	
	//varrendo o vetor para comparar entre o n�mero que o usu�rio quer buscar e o n�mero que j� existe ou n�o no vetor
		for(i=0;i<quant; i++)
		{
			//se numero for igual ao elemento do vetor ent�o tem que retornar a posicao q o elemento se encontra
			if(num==vetor[i])
			{
				return i;
				
			}
			//se numero for menor que o elemento do vetor ent�o n�o existe o valor no vetor
			if(num<vetor[i])
			{
				return -1;
			}
			
		}
		
		//se n�o for encontrado retornar o valor -1
		return -1;
}

//fun��o para exibir
void exibirVetor(int vetor[], int quant){
//declara��o de vari�veis
	int i;
	
	//varrendo o vetor e printando o mesmo
		for(i=0; i<quant; i++)
		{
			printf("%d ", vetor[i]);
		}
		printf("\n\n");
}
