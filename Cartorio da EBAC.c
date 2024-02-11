#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser cadastrado: "); //coletando infos dos usuários
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //primeiro acessa o file, depois recebe o comando, cria o arquivo
	file = fopen(arquivo, "w"); //esse comando file quer dizer: abre um arquivo com o nome da variável e é um arquivo novo (write).
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //def. linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	system("cls"); //responsável por limpar a tela
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("O usuário foi excluído.\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
        	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
        	
	    printf("### Cartório da EBAC ###\n\n"); //início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); //fim do menu
	    
	    scanf("%d", &opcao); //armazenando informações e fica parado no menu esperando a resposta usuário
	    
	    system("cls");
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro(); //chamada de funções
	    	break; //o break é usado no final de cada case para interromper o comando switch
	    	
	    	case 2:
	    	consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
	    	break;
	    	
	    	default:
	    	printf("Essa opção não está disponível.\n\n");
	    	system("pause");
	    	break;
		}
	
	}
}
