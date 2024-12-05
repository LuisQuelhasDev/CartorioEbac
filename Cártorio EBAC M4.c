#include<stdio.h>//Comunicação com o usuário.
#include <stdlib.h>//Alocação de espaço em memória.
#include <locale.h>//Alocação de texto por região.
#include<string.h>//Responsável pelas strings.
int registro()//Função para o Registro.
{
	char arquivo[40];//Início variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//Fim variáveis
	
	setlocale(LC_ALL, "Portuguesse");//Indica a linguagem usada.
	
	printf("Você escolheu registro de novos alunos\n");//Mensagem de entrada.
	printf("Digite o CPF a ser cadastrado: ");//Pede uma informação do usuário.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// Copia os valores da string.
	
	FILE *file;//Criando um novo arquivo.
	file=fopen(arquivo, "w");//Cria um novo arquivo.(w é pre-definido).
	fprintf(file, "\nCPF: ");//Inserindo texto para organizar os dados, e facilitar para o usuário no momento da consulta!
	fprintf(file,cpf); //Salva a variável no arquivo.
	fclose(file);//Fecha o arquivo.
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.(a é pre-definido).
	fprintf(file, "\n\nNome: ");//Inserindo texto para organizar os dados.
	fclose(file);//Fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: ");//Pede uma informação do usuário.
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, "\n\nSobrenome: ");//Inserindo texto para organizar os dados.
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//Pede uma informação do usuário.
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, "\n\nCargo: ");//Inserindo texto para organizar os dados.
	fclose(file);
	
	printf("Digite o Cargo que sera ocupado: ");//Pede uma informação do usuário.
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file,"\n\n");//Inserindo texto para organizar os dados.
	fclose(file);
	
	return 0;//Adicionado para que ao final dos registros não seja necessario clicar "enter" para retornar ao menu, dessa forma fica automático.
	
}
int consulta()//Função para Consulta.
{
	char cpf[40];//Variaveis
	char conteudo[200];//Variaveis
	
	setlocale(LC_ALL, "Portuguese");//Indica a linguagem usada.
	
	printf("Você escolheu consultar situação de cadastro\n");//Mensagem de entrada.
	printf("Digite o CPF que deseja consultar: ");//Pede uma informação do usuário.
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r");//lê o arquivo. o r é pre-definido.
	
	if(file == NULL)//Caso o valor naõ seja encontrado.
	{
		printf("CPF não cadastrado.\n");//Mensagem Resposta.
		system("pause");//Tempo para que o usuário possa ler a mensagem resposta.
		return 0;//Interrempor a execução. Sem isso, caso o usuário clique "enter" duas vezes a mensagem "Essas foram as informações encontradas" vai aparecer!
	}
	
	printf("\nEssas foram as informações encontradas:\n");//Mensagem resposta. Fora do while, para não entrar no loop e repetir a mensagem!
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	fclose(file);//Fechar o arquivo. Se não tiver esse comando, caso o usuário queira consultar um CPF e em seguida excluir, não ira funcionar o delete.
	system("pause");
}

int deletar()//Função para deletar.
{
	char cpf[40];
	
	printf("Você escolheu deletar cadastro\n");//Mensagem de entrada.
	printf("Digite o CPF que deseja deletar do sistema: ");//Pede uma informação do usuário.
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf, "r");
	fclose(file);
	
	if(file==NULL)
	{
		printf("Esse CPF não está cadastrado\n");//Mensagem Resposta.
		system("pause");
	}
	if(file!=NULL)
	{
		remove(cpf);//Remove o CPF escolhido.
		printf("O usuário foi deletado.\n");//Mensagem Resposta.
		system("pause");
	}
}

int main()//Função Principal.
{
	int opcao=0;//Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Indica a Linguagem usada
		
		printf("\tBem Vindo ao Cartório da EBAC \n\n");//Começo do menu
		printf("\tA seguir digite o valor correspondente a opção desejada \n\n");
		printf("\t1-Registro de novos alunos");
		printf("\t2-Consultar situação de cadastro");
		printf("\t3-Deletar cadastro \n\n");
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenamento de Informações
		
		system("cls");
	
		switch(opcao)//Opções de seleção do menu
		{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Desculpe, essa opção não está disponivel\n");
		system("pause");
		break;	//Fim das opções de seleção do menu
		}
	}
}
