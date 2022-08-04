#include<stdio.h>
/*
		*FAETERJ-Rio*
		TRABALHO DA AV2
		POR MYLENA GUSMÃO E
		NATALIE MARQUES
		
i. Inserção de um número no vetor;
ii. Remoção de determinado valor;
iii. Alteração de um valor por outro;
iv. Busca de determinado elemento no vetor,
retornando a sua posição, se encontrado no
vetor, ou o valor -1, caso contrário;
v. Exibição de todos os elementos do vetor;
vi. E, por último, a opção de sair do programa.
*/

//mostrando que existe funções
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

//função principal MAIN
void main(){    
//declaração de variáveis
	int v[CAP]={0}, quant=0;
	int numeroI, numeroR, numeroB, numeroA, numeroA2;
	char codigo;
	
//estrutura de repetição 'Do...while' para o MENU
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
		
	//switch case para cada escolha do usuário	
		switch (codigo){
				case '1':
					//pedindo para o usuário informar o número que ele deseja
						printf("Digite um numero: ");
						scanf("%d", &numeroI);
						//estrutura de condição para se os casos dentro do inserir forem falsos o usuário não pode fazer a ação
						if(inserirNumero(v, &quant, numeroI)==FALSE)
						{
							printf("\nIMPOSSIVEL SEGUIR COM A OPERACAO!\n");
						}
						
					break;	
		
					
				case '2':
					//pedindo para o usuário informar o número que ele deseja remover
					printf("Selecione o numero que deseja remover: ");
					scanf("%d", &numeroR);
					//chamando a função remover e se retornar FALSE é pq o número inserido é inválido
					if(removerNumero(v, &quant, numeroR)==FALSE)
					{
						printf("\nIMPOSSIVEL SEGUIR COM A OPERACAO!\n");
					}
				break;
				
				case '3':
					//pedindo para o usuário informar o número que ele deseja alterar
					printf("Digite o numero que deseja alterar: ");
					scanf("%d", &numeroA);
					//pedindo para o usuário informar o número que ele vai substituir o q ele removeu
					printf("Digite o numero que o substituira: ");
					scanf("%d", &numeroA2);
					//chamando a função alterar e se retornar FALSE é pq um dos números ou os números inseridos são inválidos
					if(alterarNumero(v, &quant, numeroA, numeroA2)==FALSE)
					{
						printf("\nIMPOSSIVEL SEGUIR COM A OPERACAO!\n");
					}
					
				break;
				
				case '4':
					//pedindo para o usuário informar o número que ele deseja buscar
					printf("Digite o numero que deseja buscar: ");
					scanf("%d", &numeroB);
					//chamando e printando a função buscar
					printf("\nA posicao do numero e: %d\n", buscarNumero(v, quant, numeroB));
				break;
				
				case '5':
					//chamando a função exibir
				  	exibirVetor(v, quant);
				break;
					
			}
			system("pause");
			system("cls");
		}while(codigo!='S');
		 
		
			
}

//função para verificar se o vetor está cheio ou vazio
int vetorVazio(int quant){
	  if(CAP == quant)
	  {
	  	//se o vetor tiver 'cheio' retornar FALSE
         return FALSE;
      }else 
	  	  {
	  	  	//se o vetor tiver 'vazio' retornar TRUE, isso quer dizer que ainda há espaço em que o usuário possa inserir
        	return TRUE; 
    	  }
}

//função para inserir um número ordenado crescentemente e sem repetição
int inserirNumero(int vetor[], int *quant, int n){
//declaração de variáveis
	int num, i;
	
	//verificando se o vetor se encontra vazio 
	if(vetorVazio(*quant)==FALSE)
	{
		return FALSE;
	}
	
		
	//verificando se já existe números iguais no vetor
	if(buscarNumero( vetor, *quant, n)!=(-1))
	{
		return FALSE;
	}
	
	//verificando se é o primeiro número do vetor a ser inserido,se for então atribuir sem fazer alterações
	if((*quant)==0 )
	{
		vetor[0]=n;
		(*quant)++;
		return TRUE;
		
	}else{
		//verificando se o último número que foi digitado, é maior que o elemento anterior a ele no vetor, se sim então atribuir sem fazer alterações
		if(n>vetor[*quant-1])
		{
			vetor[*quant]=n;
			(*quant)++;
			return TRUE;
		}else{
			//se caso todos os verificando de cima forem falsos, os elementos do vetor serão trocados e reorganizados em ordem
			for(i=0; i<*quant; i++)
			{
				//estrutura de repetição para ordenar crescentemente o vetor
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

	//atribuindo a variável n, já organizada, ao vetor	
	vetor[*quant]=n;
	
	//adicionando 1 unidade no vetor
	(*quant)++;
	
	//concluindo com perfeição e retornando TRUE
	return TRUE;
}

//função para a remoção de um determindado número
int removerNumero(int vetor[], int *quant, int n){
//declaração de variáveis
	int posicao, i;
	
	//atribuição da variável 'posição' para o retorno da função
	posicao=buscarNumero( vetor, *quant, n);
	
	//estrutura de condição caso a posicao for -1 retornar FALSE imediatamente
	 if(posicao==-1)
	 {
	 	return FALSE;
	 }
	 
	//varrendo o vetor da posição que foi encontrada até o quant 
	for(i=posicao; i<*quant-1; i++)
		{
			vetor[i]=vetor[i+1];
		}
		
	//removendo 1 unidade da quantidade que tinha no vetor
	(*quant)--;
	
	//concluindo com perfeição e retornando TRUE
	return TRUE;
	
}

//função para a alteração de um determindado número por outro
int alterarNumero(int vetor[], int *quant, int num1, int num2){
	//declaração de variáveis
	int numero, numero1;
	
	//atribuindo o número a uma variável caso o número digitado exista no vetor
	if(buscarNumero( vetor, *quant, num1)!=(-1))
	{
		numero=num1;
	}else{
		//caso não exista retornar falso e assim não podendo seguir com a operação
		return FALSE;
	}
	
	//atribuindo o número a uma variável caso o número digitado não exista no vetor
	if(buscarNumero(vetor, *quant, num2)==(-1))
	{
		numero1=num2;
	}else{
		//caso exista retornar falso e assim não podendo seguir com a operação
		return FALSE;
	}
	
	//chamando a funcao remover para tirar o número já existente do vetor
	removerNumero(vetor, quant, numero);
	//chamando a funcao inserir para inserir o novo número que o usuário digitou 
	inserirNumero(vetor, quant, numero1);
	
	//concluindo com perfeição e retornando TRUE
	return TRUE;
}


//função para buscar determinado número no vetor
int buscarNumero(int vetor[], int quant, int num){
//declaração de variáveis
	int i;
	
	//varrendo o vetor para comparar entre o número que o usuário quer buscar e o número que já existe ou não no vetor
		for(i=0;i<quant; i++)
		{
			//se numero for igual ao elemento do vetor então tem que retornar a posicao q o elemento se encontra
			if(num==vetor[i])
			{
				return i;
				
			}
			//se numero for menor que o elemento do vetor então não existe o valor no vetor
			if(num<vetor[i])
			{
				return -1;
			}
			
		}
		
		//se não for encontrado retornar o valor -1
		return -1;
}

//função para exibir
void exibirVetor(int vetor[], int quant){
//declaração de variáveis
	int i;
	
	//varrendo o vetor e printando o mesmo
		for(i=0; i<quant; i++)
		{
			printf("%d ", vetor[i]);
		}
		printf("\n\n");
}
