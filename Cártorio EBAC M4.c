#include<stdio.h>//Comunica��o com o usu�rio.
#include <stdlib.h>//Aloca��o de espa�o em mem�ria.
#include <locale.h>//Aloca��o de texto por regi�o.
#include<string.h>//Respons�vel pelas strings.
int registro()//Fun��o para o Registro.
{
	char arquivo[40];//In�cio vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//Fim vari�veis
	
	setlocale(LC_ALL, "Portuguesse");//Indica a linguagem usada.
	
	printf("Voc� escolheu registro de novos alunos\n");//Mensagem de entrada.
	printf("Digite o CPF a ser cadastrado: ");//Pede uma informa��o do usu�rio.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// Copia os valores da string.
	
	FILE *file;//Criando um novo arquivo.
	file=fopen(arquivo, "w");//Cria um novo arquivo.(w � pre-definido).
	fprintf(file, "\nCPF: ");//Inserindo texto para organizar os dados, e facilitar para o usu�rio no momento da consulta!
	fprintf(file,cpf); //Salva a vari�vel no arquivo.
	fclose(file);//Fecha o arquivo.
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.(a � pre-definido).
	fprintf(file, "\n\nNome: ");//Inserindo texto para organizar os dados.
	fclose(file);//Fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: ");//Pede uma informa��o do usu�rio.
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, "\n\nSobrenome: ");//Inserindo texto para organizar os dados.
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//Pede uma informa��o do usu�rio.
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, "\n\nCargo: ");//Inserindo texto para organizar os dados.
	fclose(file);
	
	printf("Digite o Cargo que sera ocupado: ");//Pede uma informa��o do usu�rio.
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo, "a");//Atualiza o arquivo.
	fprintf(file,"\n\n");//Inserindo texto para organizar os dados.
	fclose(file);
	
	return 0;//Adicionado para que ao final dos registros n�o seja necessario clicar "enter" para retornar ao menu, dessa forma fica autom�tico.
	
}
int consulta()//Fun��o para Consulta.
{
	char cpf[40];//Variaveis
	char conteudo[200];//Variaveis
	
	setlocale(LC_ALL, "Portuguese");//Indica a linguagem usada.
	
	printf("Voc� escolheu consultar situa��o de cadastro\n");//Mensagem de entrada.
	printf("Digite o CPF que deseja consultar: ");//Pede uma informa��o do usu�rio.
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r");//l� o arquivo. o r � pre-definido.
	
	if(file == NULL)//Caso o valor na� seja encontrado.
	{
		printf("CPF n�o cadastrado.\n");//Mensagem Resposta.
		system("pause");//Tempo para que o usu�rio possa ler a mensagem resposta.
		return 0;//Interrempor a execu��o. Sem isso, caso o usu�rio clique "enter" duas vezes a mensagem "Essas foram as informa��es encontradas" vai aparecer!
	}
	
	printf("\nEssas foram as informa��es encontradas:\n");//Mensagem resposta. Fora do while, para n�o entrar no loop e repetir a mensagem!
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	fclose(file);//Fechar o arquivo. Se n�o tiver esse comando, caso o usu�rio queira consultar um CPF e em seguida excluir, n�o ira funcionar o delete.
	system("pause");
}

int deletar()//Fun��o para deletar.
{
	char cpf[40];
	
	printf("Voc� escolheu deletar cadastro\n");//Mensagem de entrada.
	printf("Digite o CPF que deseja deletar do sistema: ");//Pede uma informa��o do usu�rio.
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf, "r");
	fclose(file);
	
	if(file==NULL)
	{
		printf("Esse CPF n�o est� cadastrado\n");//Mensagem Resposta.
		system("pause");
	}
	if(file!=NULL)
	{
		remove(cpf);//Remove o CPF escolhido.
		printf("O usu�rio foi deletado.\n");//Mensagem Resposta.
		system("pause");
	}
}

int main()//Fun��o Principal.
{
	int opcao=0;//Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Indica a Linguagem usada
		
		printf("\tBem Vindo ao Cart�rio da EBAC \n\n");//Come�o do menu
		printf("\tA seguir digite o valor correspondente a op��o desejada \n\n");
		printf("\t1-Registro de novos alunos");
		printf("\t2-Consultar situa��o de cadastro");
		printf("\t3-Deletar cadastro \n\n");
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenamento de Informa��es
		
		system("cls");
	
		switch(opcao)//Op��es de sele��o do menu
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
		printf("Desculpe, essa op��o n�o est� disponivel\n");
		system("pause");
		break;	//Fim das op��es de sele��o do menu
		}
	}
}
