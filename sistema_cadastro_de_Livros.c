#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

typedef struct obra OBRA;
struct obra{
	int numero;
};

typedef struct caixa CAIXA;
struct caixa{
	int numero;
};

typedef struct cadastro ACERVO;
struct cadastro{
	char titulo[50];
	int edicao;
	char autor[50];
	char editora[30];
	int ano;
	int isbn;
	int exemplares;
	CAIXA guardar;
	OBRA categoria;
};

void alunoRA();
void cadastrarObras();
void listarTodoAcervo();
void listarLivros();
void listarRevistas();
void listarCaixas();

main(){
	setlocale(LC_ALL,"");
	int opcao;
	
 do{
		alunoRA();
		printf("\n1 - Registrar no Acervo");
		printf("\n2 - Listar todo o Acervo");
		printf("\n3 - Listar livros");
		printf("\n4 - Listar revistas");
		printf("\n5 - Listar obras por caixa");
		printf("\n0 - Sair\n");
		printf("\nEscolha Opção: ");
		scanf("%d", &opcao);
	
		switch(opcao)
		{
			case 1:
				printf(">>> CADASTRO NO ACERVO <<<\n");
				cadastrarObras();
				system("pause");
			break;
			
			case 2:
				printf(">>> LISTAR TODO O ACERVO <<<\n");
				listarTodoAcervo();	
				system("pause");
			break;
		
			case 3:
				printf(">>> LISTAR LIVROS <<<\n");
				printf("DIGITE 1 PARA EXIBIR TODOS OS LIVROS.\n");
				listarLivros();
				system("pause");
			break;
		
			case 4:
				printf(">>> LISTAR REVISTAS <<<\n");
				printf("\nDIGITE 2 PARA EXIBIR TODAS AS REVISTAS.\n");
				listarRevistas();
				system("pause");
			break;
		
			case 5:
				printf("Informe a caixa desejada:[1] CAIXA 1 | [2] CAIXA 2 | [3] CAIXA 3\n");
				listarCaixas();
				system("pause");
			break;
		
			case 0:
				printf("\nSaindo do sistema!!!\n");
				getch();
			break;
		
			default:
				printf("OPÇÃO INVÁLIDA!!!!\n");
				getch();
			break;	
		}	
	}while(opcao != 0);
	
	return(0);
}

void alunoRA()
{
	system("cls");
	int s;
	for(s=0; s<80; s++) printf("-");
	printf("\n ---- GIL CÉSAR MARTINS DOS SANTOS JÚNIOR ----");
	printf("\n ---- RA: 20047657-5 ---- ");
	printf("\n **** Engenharia de Software **** \n");
	for(s=0; s<80; s++) printf("-");
}

void cadastrarObras()
{
	FILE* arq;
	ACERVO inc;
	
	arq = fopen("arquivo.txt", "ab");
	
	if ( arq == NULL){
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
	else{
		do{
			alunoRA();
			fflush(stdin);
			printf("\nInforme o título da obra: ");
			gets(inc.titulo);
			
			fflush(stdin);
			printf("\nInforme a edição (apenas números)..: ");
			scanf("%d", &inc.edicao);
				
			fflush(stdin);	
			printf("\nAutor............: ");
			gets(inc.autor);
				
			fflush(stdin);	
			printf("\nEditora............: ");
			gets(inc.editora);
				
			fflush(stdin);	
			printf("\nInforme o ano (aaaa)..: ");
			scanf("%d", &inc.ano);
			
			fflush(stdin);	
			printf("\nInforme o isbn (apenas números)..: ");
			scanf("%d", &inc.isbn);
				
			fflush(stdin);	
			printf("\nInforme a quantidade de exemplares..: ");
			scanf("%d", &inc.exemplares);
				
			fflush(stdin);	
			printf("\nCategorias: [1] Livros | [2] Revistas | " );
			scanf("%d", &inc.categoria);
			
			fflush(stdin);	
			printf("\nGuardar em qual caixa?: [1] CAIXA 1 | [2] CAIXA 2 | [3] CAIXA 3 | ");
			scanf("%d", &inc.guardar);
				
			fwrite(&inc, sizeof(ACERVO), 1, arq);
			
			printf("\nDeseja cadastrar nova obra [s]-sim [n]-não :");
		}while((getche() == 's')||(getche() == 'S'));
		fclose(arq);
	}
}

void listarTodoAcervo()	
{
	FILE* arq;
	ACERVO inc;
	
	arq = fopen("arquivo.txt", "rb");
	alunoRA();
	
	if ( arq == NULL){
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
	else{
		while(fread(&inc, sizeof(ACERVO), 1, arq) == 1){
			printf("\n------------------------------------\n");
			printf("TÍTULO: %s\n", inc.titulo);
			printf("EDIÇÃO: %d\n", &inc.edicao);
			printf("AUTOR: %s\n", inc.autor);
			printf("EDITORA: %s\n", inc.editora);
			printf("ANO: %d\n", &inc.ano);
			printf("ISBN: %d\n", &inc.isbn);
			printf("EXEMPLARES: %d\n", inc.exemplares);
			printf("CATEGORIA: %d\n", inc.categoria);
			printf("CAIXA: %d\n", inc.guardar);
			printf("-------------------------------------\n\n");
		}
	}
	fclose(arq);
	getch();
}

void listarLivros()
{
	FILE* arq;
	arq = fopen("arquivo.txt","rb");
	ACERVO inc;
	
	alunoRA();
	
	if(arq == NULL){
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
	else{
		int livro;
		do{
		printf("\nDIGITE [1] PARA EXIBIR TODOS OS LIVROS OU DIGITE [0] PARA SAIR.\n");
		scanf("%d", &livro);
		}while((livro != 0)&&(livro != 1));
		
		
		while( fread(&inc,sizeof(ACERVO), 1, arq )==1){
			if( livro == inc.categoria.numero){
			printf("\n------------------------------------\n");
			printf("TÍTULO: %s\n", inc.titulo);
			printf("EDIÇÃO: %d\n", &inc.edicao);
			printf("AUTOR: %s\n", inc.autor);
			printf("EDITORA: %s\n", inc.editora);
			printf("ANO: %d\n", &inc.ano);
			printf("ISBN: %d\n", &inc.isbn);
			printf("EXEMPLARES: %n\n", inc.exemplares);
			printf("CATEGORIA: %d\n", inc.categoria);
			printf("CAIXA: %d\n", inc.guardar);
			printf("-------------------------------------\n\n");
			}
		}
	}
	fclose(arq);
	getch();
}
void listarRevistas()
{
	FILE* arq;
	arq = fopen("arquivo.txt","rb");
	ACERVO inc;
	
	alunoRA();
	if(arq == NULL){
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
	else{
		int revista;
			do{
				printf("\nDIGITE [2] PARA EXIBIR TODAS AS REVISTAS OU DIGITE [0] PARA SAIR.");
				scanf("%d", &revista);
			}while((revista != 0)&&(revista != 2));
		
		while( fread(&inc,sizeof(ACERVO), 1, arq )==1){
			if( revista == inc.categoria.numero){
			printf("\n------------------------------------\n");
			printf("TÍTULO: %s\n", inc.titulo);
			printf("EDIÇÃO: %d\n", &inc.edicao);
			printf("AUTOR: %s\n", inc.autor);
			printf("EDITORA: %s\n", inc.editora);
			printf("ANO: %d\n", &inc.ano);
			printf("ISBN: %d\n", &inc.isbn);
			printf("EXEMPLARES: %n\n", inc.exemplares);
			printf("CATEGORIA: %d\n", inc.categoria);
			printf("CAIXA: %d\n", inc.guardar);
			printf("-------------------------------------\n\n");
			}
		}
	}
	fclose(arq);
	getch();	
}
void listarCaixas()
{
	FILE* arq;
	arq = fopen("arquivo.txt","rb");
	ACERVO inc;
	
	alunoRA();
	
	if(arq == NULL){
		printf("\nErro ao abrir o arquivo para leitura!\n");
	}
	else{
		int caixa;
		printf("\nQUAL CAIXA DESEJA EXIBIR?: \n[1] CAIXA 1 | [2] CAIXA 2 | [3] CAIXA 3 |\n ");
		scanf("%d", &caixa);
		
		while( fread(&inc,sizeof(ACERVO), 1, arq )==1){
			if (caixa == inc.guardar.numero){
			printf("\n------------------------------------\n");
			printf("TÍTULO: %s\n", inc.titulo);
			printf("EDIÇÃO: %d\n", &inc.edicao);
			printf("AUTOR: %s\n", inc.autor);
			printf("EDITORA: %s\n", inc.editora);
			printf("ANO: %d\n", &inc.ano);
			printf("ISBN: %d\n", &inc.isbn);
			printf("EXEMPLARES: %n\n", inc.exemplares);
			printf("CATEGORIA: %d\n", inc.categoria);
			printf("CAIXA: %d\n", inc.guardar);
			printf("-------------------------------------\n\n");
			}
		}
	}
	fclose(arq);
	getch();
}
	
	


