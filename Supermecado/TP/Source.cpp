/*
* Made By : Joaquim Cardoso
* Day :
* For : AED
* Language : C
* Descricion : TP
* Number : 10201
* Contact : joaquimcardoso12@hotmail.com
*/
#define NDEBUG 
#define D_SCL_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define  _AFX_SECURE_NO_WARNINGS
#define _ATL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Header.h"
#include <iostream>

/*
Falta criar um CalculaCodigo de artigo tal e qual ao Calcula o codigo de emissao
Pk vai ser o computador a atribuir o numero, ele apenas vai ter que verificar a tabela dos artigos toda a  1a vez
porque vou criar uma variavel global para saber sempre o ultimo numero atribuido no stock e para verificar muito rapidamente se existe
faço if(ULTIMO < ITEM && ITEM > 0)
existe quase de certeza
mas se for carregado por ficheiro pode não ter entao  tenho que verificar a procura naqueça lista

falta colocar em todos os malloc uma verificação if((bla variavel = (bla)calloc(tCelulabla))==NULL)não há memoria
falta criar um metodo que vá alterar os dados de u artigo . AlteraArtigo
*/

//______________________________________________________________________
//Duvidas
/*
  		  Podemos fazer o free de :

		  superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice]

		  antes de apagar e depois de apagar atribuimos o valor de atua a :
		  superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice]

*/



#pragma region Metodos

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Menu's'

void DefinePt()
{
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	fflush(stdin);//limpar a memória temporária	
}

//Bem-vindo
void Apresentacao()
{
	system("cls");
	DefinePt();
	int espera;
	char username[21];
	DWORD username_len = 21;

	GetUserName(username, &username_len);

	username[20] = '\0';
	printf_s("Bem vindo, ");
	puts(username);
	printf_s("\n Espero que goste do trabalho . . .");
	espera = clock();//conta o tempo
	while (clock() - espera <= 3500);//enquanto não se passaram  3,5 segundos
	system("cls");

}

void EscolherSuperDume()
{
	char temp[MAXLOCALIZACAO]="";
	do
	{
		system("cls");
		ImprimeTodosSuperDumes();

		printf_s("\n\nIntroduza a localização do SuperDume : ");
		fgets(temp, sizeof(char) *MAXLOCALIZACAO, stdin);
		_strupr_s(temp);

	} while (EncontraSuperDume(temp) == -1);
	strcpy_s(localSuperDume, sizeof(char)*MAXLOCALIZACAO, temp);
}

//Menu Principal
void Principal()
{
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");										
	printf_s("Está a trabalhar no SuperDume : %s", localSuperDume);
	printf_s("\n\n\n");
	printf_s("[1] - Gerir Clientes\n");
	printf_s("[2] - Gerir Artigos \n");
	printf_s("[3] - Carregar de um ficheiro\n");
	printf_s("[4] - Guardar em ficheiro \n");
	printf_s("[5] - Escolher o SuperDume\n");
	printf_s("[6] - Gerir o SuperDume\n");
	printf_s("[0] - Sair\n");

}

void SecundarioClientes()
{
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");
	printf_s("Está a trabalhar no SuperDume : %s", localSuperDume);
	printf_s("\n\n\n");
	printf_s("[1] - Atribuir um Cartão\n");
	printf_s("[2] - Eliminar um Cartão\n");
	printf_s("[3] - Registar Compra\n");
	printf_s("[4] - Consultar Compras de um Cartão\n");
	printf_s("[5] - Consultar Compras de Todos os Cartões\n");
	printf_s("[6] - Consultar Valor Total de Compras de um Cartão\n");
	printf_s("[7] - Consultar Pontos de um Cartão\n");
	printf_s("[0] - Voltar\n");

}

void MenuAltera(Artigo a)
{
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");
	printf_s("Está a trabalhar no SuperDume : %s", localSuperDume);
	printf_s("\n\n\n");
	printf_s("[1] - Descriçao - %s\n", a.descricao);
	printf_s("[2] - Código - %d\n",a.codigoArtigo);
	printf_s("[3] - Preço - %2.f\n",a.preco);
	printf_s("[4] - Stock - %d\n", a.quantidadeStock);
	printf_s("[0] - Voltar\n");

}

void SecundarioArtigos()
{
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");
	printf_s("Está a trabalhar no SuperDume : %s", localSuperDume);
	printf_s("\n\n\n");
	printf_s("[1] - Adicionar Artigos\n");
	printf_s("[2] - Actualizar Stock (Artigo)\n");
	printf_s("[3] - Repor Stock\n");
	printf_s("[4] - Eliminar Artigo\n");
	printf_s("[5] - Eliminar Todos os Artigos\n");
	printf_s("[6] - Consultar Todos os Artigos\n");
	printf_s("[7] - Verificar se um Artigo existe\n");
	printf_s("[8] - Alterar dados um Artigo existe\n");
	printf_s("[0] - Voltar\n");

}

void MenuCompra()
{
	printf_s("\n[1] - Escolher Artigo \n");
	printf_s("[2] - Mostrar o Carrinho de compras \n");
	printf_s("[3] - Eliminar um Artigo da Compra \n");
	printf_s("[0] - Voltar\n");
}

void MenuSuperDume()
{
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");
	printf_s("Está a trabalhar no SuperDume : %s", localSuperDume);
	printf_s("\n\n\n");
	printf_s("[1] - Inserir SuperDume \n");	    
	printf_s("[2] - Eliminar SuperDUme\n");
	printf_s("[0] - Voltar\n");
}

//antes de escolher um artigo
void SubMenuNumeroEmissão()
{
	printf_s("\nIntroduza o numero de Emissão do Cartão : ");
}

//antes de escolher um artigo
void SubMenuCompraArtigo()
{
	printf_s("\nIntroduza o nome do Artigo :");
}

//depois de escolher um artigo
void SubMenuCompraQuantidade()
{
	printf_s("\n[1] - Escolher Quantidade \n");
	printf_s("[0] - Cancelar\n");
}

//escolher quantidade
void SubMenuCompraEscolherQuantidade()
{
	printf_s("\nIntroduza a quantidade desejada : \n");
}


void NaoExiste()
{
	printf("O artigo não foi apagado pois é inesxistente");
}

void Repetir()
{
	
	printf_s("\n\n\nDeseja repetir o processo ? \n\n");
	printf_s("\n[1] - Repetir o processo \n");
	printf_s("[0] - Voltar\n");
}

void EsperarErro()
{
	int tempo;
	printf_s("Opção não conhecida\n");
	printf_s("\nEspere . . .");

	tempo = clock();//conta o tempo
	while (clock() - tempo <= 2000);//enquanto não se passaram 3segundos						

	system("cls");
}

void Esperar()
{
	int tempo;

	tempo = clock();//conta o tempo
	while (clock() - tempo <= 1200);//enquanto não se passaram 3segundos
}

void EsperarPouco()
{
	int tempo;

	tempo = clock();//conta o tempo
	while (clock() - tempo <= 250);//enquanto não se passaram 3segundos
}

void EsperarEnter()
{
	fflush(stdin);
	printf("Prime o enter ");
	getc(stdin);
}

int SimNao()
{
	int simNao;
	printf_s("\n[1] - Sim \n");
	printf_s("[0] - Não\n");
	do
	{
		scanf_s("%1d", &simNao);

		if (simNao == 1)
			break;

	} while (simNao != 0);
	return simNao;
}

int QuerContinuar(Artigo a)
{
	system("cls");
	int aux;
	printf("Realmente quer introduzir este artigo em stock ?\n\n");
	printf("Nome   : %s\n", a.descricao);
	printf("Código : %d\n", a.codigoArtigo);
	printf("Preço  : %.2f €\n", a.preco);
	printf("Stock  : %d\n\n", a.quantidadeStock);
	aux = SimNao();
	return aux;
}

int QuerCartao(Compra a)
{
	system("cls");
	int aux;
	printf("Quer registar em cartão ?\n\n");
	aux = SimNao();
	return aux;
}

int QuerContinuar(Cartao a)
{

	system("cls");
	int aux;
	printf("Realmente quer introduzir este cartao no regiosto ?\n\n");
	printf("Nome   : %s\n", a.cliente.nome);
	printf("Número Emissão : %d\n", a.numeroEmissao);
	aux = SimNao();
	return aux;
}
#pragma endregion  

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Inicializa

int EncontraSuperDume(char localizacao[])
{
	int	indexSuperDume = -1;
	
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
		if (strcmp(superMercadoLocal[i]->localidade, localizacao) == 0)
			indexSuperDume = i;

	if (indexSuperDume >= 0)
	{
		indiceLocalSuperDume = indexSuperDume;
		printf("SuperDumer Encontrado");
		Esperar();
	}

	else
	{
		printf("SuperDume Desconhecido");
		Esperar();
	}
	return	indexSuperDume;
}

void InicializaTodosSuperDume()
{
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		superMercadoLocal[i] = NULL;
		//strcpy_s(superMercadoLocal[i]->localidade, sizeof(char),"\0");
	}
}

void InicializaSuperDume()
{

	if (indiceLocalSuperDume >= 0)
	{		  	
			superMercadoLocal[indiceLocalSuperDume] = NULL;
			strcpy_s(superMercadoLocal[i]->localidade, sizeof(char), "\0");
			printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");
}			 

void InicializaSuperDumeTodasListaArtigos()
{
	if (indiceLocalSuperDume >= 0)
	{
		for (l = 0; l < HASHSIZE; l++)
		{
			superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[l] = NULL;
		}
		printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");

	
}
						
void InicializaSuperDumeListaArtigos(unsigned int numeroArtigo)
{
	if (indiceLocalSuperDume >= 0)
	{
		int indice = HashArtigo(numeroArtigo);
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = NULL;
		printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");
}
		
void InicializaSuperDumeTodasListaCartao()
{

	if (indiceLocalSuperDume >= 0)
	{
		for (l = 0; l < HASHSIZE; l++)
		{
			superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[l] = NULL;
		}
		printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");


}	   

void InicializaSuperDumeListaCartao(unsigned int numeroCartao)
{

	if (indiceLocalSuperDume >= 0)
	{
		int indice = HashArtigo(numeroCartao);
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = NULL;
		printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");
}

#pragma endregion 

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Aloca memória


void AlocaTodosSuperDume()
{
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		superMercadoLocal[i] = (SuperDume)calloc(1,sizeof(tCelulaSuperdume));
		//strcpy_s(superMercadoLocal[i]->localidade, sizeof(char),"\0");
	}
}

void AlocaSuperDume()
{

	if (indiceLocalSuperDume >= 0)
	{
		superMercadoLocal[indiceLocalSuperDume] = (SuperDume)calloc(1, sizeof(tCelulaSuperdume));
		superMercadoLocal[indiceLocalSuperDume] = NULL;
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

void AlocaSuperDumeTodasListaArtigos()
{
	if (indiceLocalSuperDume >= 0)
	{
		for (l = 0; l < HASHSIZE; l++)
		{
			superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[l] = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
			superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[l] = NULL;
		}
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}
  	 
void AlocaSuperDumeListaArtigos(unsigned int numeroArtigo)
{
	if (indiceLocalSuperDume >= 0)
	{
		int indice = HashArtigo(numeroArtigo);
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos)); 
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

void AlocaSuperDumeTodasListaCartao()
{

	if (indiceLocalSuperDume >= 0)
	{
		for (l = 0; l < HASHSIZE; l++)
		{
			superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[l] = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
			superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[l] = NULL;
		}
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

void AlocaSuperDumeListaCartao(unsigned int numeroCartao)
{

	if (indiceLocalSuperDume >= 0)
	{
		int indice = HashArtigo(numeroCartao);
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

#pragma endregion

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Hash

//retorna a posição para um array
int HashArtigo(int codigo)
{
	int sum = codigo;

	sum %= (HASHSIZE - 1);

	return sum;
}

//retorna a posição para um array
int HashCartao(int codigoEmissao)
{
	int sum = codigoEmissao;

	sum %= (HASHSIZE - 1);

	return sum;
}

#pragma endregion


//Falta coisas
//retorna objectos
#pragma region Procura

//Falta enviar a lista toda, tou a enviar apenas o que está depois
//envia a lista onde o cartao está inserido
ListaCartao ProcuraCartaoRetornaLista(unsigned int numeroEmissao)
{
	ListaCartao aux = (ListaCartao)calloc(1,sizeof(tCelulaCartao));

	int indice = HashCartao(numeroEmissao);
	
	if (indiceLocalSuperDume >= 0)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];

		while (aux != NULL)
		{
			if (aux->cartao.numeroEmissao == numeroEmissao)
				return aux;

			aux = aux->proximo;
		}
	}	  	
	
	return NULL;
}

//Falta enviar a lista toda, tou a enviar apenas o que está depois
//envia a lista onde o cartao está inserido
ListaArtigos ProcuraArtigoRetornaLista(unsigned int numeroArtigo)
{
	ListaArtigos aux = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));

	int indice = HashCartao(numeroArtigo);

	if (indiceLocalSuperDume >= 0)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];

		while (aux != NULL)
		{
			if (aux->artigo.codigoArtigo == numeroArtigo)
				return aux;

			aux = aux->proximo;
		}
	}

	return NULL;
}

//Feito
Cartao ProcuraCartaoRetornaCartao(unsigned int numeroEmissao)
{
	ListaCartao aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	Cartao temp;


	aux = ProcuraCartaoRetornaLista(numeroEmissao);


	if (aux == NULL) {
		printf("\nNão existe nenhum cartao com esse número\n\n");
		temp.numeroEmissao = NULL;
	}

	else
	{
		printf("\nExiste um cartao com esse código\n");
		temp = aux->cartao;
		printf("\nNumero Emissão  : %d", temp.numeroEmissao);
		printf("\nNome do Cliente : %s", temp.cliente.nome);
		Esperar();

	}

	return temp;
}

//Feito
Artigo ProcuraArtigoRetornaArtigo(unsigned int codigoArtigo)
{
	ListaArtigos aux = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));
	Artigo temp;				
	

	aux = ProcuraArtigoRetornaLista(codigoArtigo);


	if (aux == NULL) {
		printf("\nNão existe nenhum artigo com esse código\n\n");
		temp.codigoArtigo = NULL;
	}

	else
	{
		printf("\nExiste um artigo com esse código");
		temp = aux->artigo;
		printf("\nNome : %s",temp.descricao);
		Esperar();

	}

	return temp;
}

//Feito
//Contra : como tenho a hash a ordenar por numero e nao por nome de artigo, vou ter que verificar todas as listas
Artigo ProcuraArtigoRetornaArtigo(char nomeArtigo[])
{
	ListaArtigos aux = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));

	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[i];

		while (aux != NULL)
		{
			if (strcmp(nomeArtigo, aux->artigo.descricao) == 0 && aux->artigo.quantidadeStock > 0)
				return aux->artigo;

			aux = aux->proximo;
		}
	}
	Artigo temp;
	temp.codigoArtigo = -NULL;
	printf("O artigo não foi encontrado");
	return temp;
}

int ProcuraSuperDumeRetorna(char localizacao[])
{
	int erro = 0;
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		if (superMercadoLocal[i] != NULL)
		{
			if (strcmp(superMercadoLocal[i]->localidade, localizacao) == 0)
				return 1;
		}				 		
	}
	return 0;
}

#pragma endregion


//Falta coisas e tem erros
//retorna o objecto criado
#pragma region Criar

//se o string copy no final tá a funcionar bem
//Feito verificar 
Cliente CriaCliente()
{
	unsigned int erro = 0;
	unsigned int temp = 0;
	char temporaria_Char[MAXNOME];
	char nome[MAXNOME];
	char cartaoCidadao[MAXCC];
	unsigned int telefone;
	unsigned long nif;
	char morada[MAXMORADA];
	char email[MAXNOME];


	do
	{
		erro = 0;

		printf_s("Insire o teu nif : ");
		scanf_s("%d", &temp);
		fflush(stdin);

		if (temp <= 0 || temp > 999999999)
		{
			printf("Erro nif inválido\n");
			erro = 1;
			continue;
		}

		if (erro == 0)
		{
			nif = temp;
		}

	} while (erro != 0);

	do
	{
		erro = 0;

		printf_s("\nInsire o teu nome completo : ");
		fgets(temporaria_Char, sizeof(char) * MAXNOME, stdin);

		_strupr_s(temporaria_Char);

		for (l = 0; l < strlen(temporaria_Char); l++)
		{
			if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && (temporaria_Char[l] != ' ') && (temporaria_Char[l] != '\n'))
			{
				printf_s("\nIntroduza caracter\'s validos\n");
				erro = 1;
				break;
			}
		}
		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "")
			erro = 1;

		if (erro == 0)
		{
			strcpy_s(nome, sizeof(CHAR) * MAXNOME, temporaria_Char);
		}

		fflush(stdin);

	} while (erro != 0);

	do
	{
		erro = 0;
		strcpy_s(temporaria_Char, "");

		printf_s("\nInsire o nome da rua onde moras : ");
		fgets(temporaria_Char, sizeof(char) *MAXMORADA,stdin);
		_strupr_s(temporaria_Char);
		fflush(stdin);

		for (l = 0; l <= strlen(temporaria_Char); l++)
		{
			if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && temporaria_Char[l] != ' ' && temporaria_Char[l] != -121 && temporaria_Char[l] != '\0' && (temporaria_Char[l] != '\n'))
			{
				printf_s("\nIntroduza caracter\'s validos\n");
				erro = 1;
				break;
			}
		}

		if (erro == 0)
		{
			strcpy_s(morada, sizeof(char) * MAXMORADA, temporaria_Char);
		}

	} while (erro != 0);

	do
	{
		erro = 0;
		temp = 0;

		printf_s("\nInsire o nº de telefone : ");
		scanf_s("%09d", &temp);
		fflush(stdin);

		if (temp >= 297000000 || temp < 210000000)
		{
			printf("Erro numero de telefone inválido. Não confundir telemóvel com telefone\n");
			erro = 1;
			continue;
		}

		if (erro == 0)
		{
			telefone = temp;
		}


	} while (erro != 0);

	do
	{
		erro = 0;
		strcpy_s(temporaria_Char, "");

		printf_s("\nInsire o teu email: ");
		fgets(temporaria_Char, sizeof(char) * MAXNOME , stdin);
		fflush(stdin);

		
		if (erro == 0)
		{
			strcpy_s(email, sizeof(char) * MAXNOME, temporaria_Char);
		}


	} while (erro != 0);

	do
	{
		erro = 0;

		printf_s("\nInsire o teu numero de cartao de cidadão : ");
		fgets(temporaria_Char, sizeof(char) *MAXCC,stdin);
		fflush(stdin);
		_strupr_s(temporaria_Char);

		for (i = 0; i < LETRASCC; i++)
		{
			if ((temporaria_Char[i] < '0') || (temporaria_Char[i] > '9') && (temporaria_Char[i] != '\n'))
			{
				printf_s("\nIntroduza caracter\'s validos\n");
				erro = 1;
				break;
			}
		}

		if (erro == 0)
		{
			for (l = LETRASCC; l < MAXCC; l++)
			{
				if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && (temporaria_Char[l] != ' ') && (temporaria_Char[l] != '\0'))
				{
					printf_s("\nIntroduza caracter\'s validos\n");
					erro = 1;
					break;
				}
			}
		}

		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "")
			erro = 1;

		if (erro == 0)
		{
			strcpy_s(cartaoCidadao, sizeof(CHAR) * MAXCC, temporaria_Char);
		}

		fflush(stdin);

	} while (erro != 0);

	Cliente c;

	strcpy_s(c.cartaoCidadao, sizeof(char) * MAXCC, cartaoCidadao);
	strcpy_s(c.email, sizeof(char) * MAXNOME, email);
	strcpy_s(c.morada, sizeof(char) * MAXMORADA, morada);
	strcpy_s(c.nome, sizeof(char) * MAXNOME, nome);
	c.nif = nif;
	c.telefone = telefone;

	return c;
}
 
//Feito
Cartao CriaCartao()
{
	Cartao c;

	c.cliente = CriaCliente();
	/*c = NULL;*/
	c.numeroEmissao = CalculaContador(); 
	c.pontos = 0;
	c.totalValorGasto = 0.0;


	return c;
}

//Feito
Artigo CriaArtigo()
{
	unsigned int codigoArtigo;
	char descricao[MAXNOME];
	float preco;
	unsigned int stock;
	unsigned int erro = 0;
	unsigned int temp = 0;
	float tempFloat = 0.0;
	char temporaria_Char[MAXNOME];
	Artigo a;

	do
	{
		system("cls");
		erro = 0;

		printf_s("Insire o código do artigo : ");
		scanf_s("%d", &temp);
		fflush(stdin);
		a = ProcuraArtigoRetornaArtigo(temp);

		if (temp <= 0 || temp > MAXSTOCK)
		{
			printf("Erro código de artigo inválido\n");
			erro = 1;
			continue;
		}

		if (a.codigoArtigo != NULL)
		{
			erro = 1;
			continue;
		}

		if (erro == 0)
		{
			codigoArtigo = temp;
		}

	} while (erro != 0);

	temp = 0;

	do
	{
		erro = 0;

		printf_s("Insire o stock do artigo : ");
		scanf_s("%d", &temp);
		fflush(stdin);

		if (temp <= 0 || temp > MAXSTOCK)
		{
			printf("Erro stock de artigo inválido\n");
			erro = 1;
			continue;
		}

		if (erro == 0)
		{
			stock = temp;
		}

	} while (erro != 0);

	temp = 0;

	do
	{
		erro = 0;

		printf_s("Insire o preço do artigo : ");
		scanf_s("%f", &tempFloat);
		fflush(stdin);

		if (tempFloat <= 0.0 || tempFloat > MAXSTOCK)
		{
			printf("Erro preço de artigo inválido\n");
			erro = 1;
			continue;
		}

		if (erro == 0)
		{
			preco = tempFloat;
		}

	} while (erro != 0);

	do
	{
		erro = 0;

		printf_s("\nInsire a descrição do produto : ");
		fgets(temporaria_Char, sizeof(char) *MAXNOME ,stdin);

		_strupr_s(temporaria_Char);

		for (l = 0; l < strlen(temporaria_Char); l++)
		{
			if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && (temporaria_Char[l] != ' ') && (temporaria_Char[l] != '\n'))
			{
				printf_s("\nIntroduza caracter\'s validos\n");
				erro = 1;
				break;
			}
		}
		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "")
			erro = 1;

		if (erro == 0)
		{
			strcpy_s(descricao, sizeof(CHAR) * MAXNOME, temporaria_Char);
		}

		fflush(stdin);

	} while (erro != 0);

	

	a.codigoArtigo = codigoArtigo;
	strcpy_s(a.descricao, sizeof(char)* MAXNOME, descricao);
	a.preco = preco;
	a.quantidadeStock = stock;
	a.quantidadeVendida = 0;


	return a;
}

//está mal
Compra CriaCompra()
{
	unsigned int tempUm;
	unsigned int temDois;
	int repetir;
	unsigned int escolha;
	unsigned int escolhaQuantidade;
	char nomeArtigo[MAXNOME];
	unsigned int quantidadeArtigo;
	ListaArtigos anterioe = NULL;
	ListaArtigos aux = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));
	Artigo temp;


	escolha = 99;

	do
	{
		system("cls");
		MenuCompra();
		scanf_s("%1d", &escolha);

		switch (escolha)
		{
			//compra artigo	 - verificar
		case 1:
			do
			{
				repetir = -1;
				system("cls");

				//mostra todos os artigos
				ImprimeListaTodosArtigos();

				if (l == 0);

				else
				{  
					SubMenuCompraArtigo();
					fgets(nomeArtigo, sizeof(char) * MAXNOME, stdin);
					_strupr_s(nomeArtigo);
					

					//ve se o artigo existe
					temp = ProcuraArtigoRetornaArtigo(nomeArtigo);

					//se existir
					if (temp.codigoArtigo != NULL)
					{
						//escolhe ver se quer escolher a quantidade ou cancelar a compra do artigo
						do
						{	
							//Menu
							quantidadeArtigo = 0;
							SubMenuCompraQuantidade();
							do
							{
								fflush(stdin);
								scanf_s("%d", &escolhaQuantidade);

								if (escolhaQuantidade == 1)
									break;

							} while (escolhaQuantidade != 0);

							if (temp.quantidadeVendida == temp.quantidadeStock)
								printf("\nO artigo esgotou\n");

							//se escolher introduzir a quantidade
							else if (escolhaQuantidade == 1 )
							{
								//introduzimos a quantidade
								SubMenuCompraEscolherQuantidade();
								if (temp.quantidadeVendida != 0)
									printf("\nAinda há em stock : %d  . . .", (temp.quantidadeStock - temp.quantidadeVendida));
								
								do
								{
									fflush(stdin);
									scanf_s("%d", &quantidadeArtigo);

								} while (quantidadeArtigo < 0 || temp.quantidadeStock < quantidadeArtigo);
								temp.quantidadeVendida += quantidadeArtigo;

								break;
							}

						} while (escolhaQuantidade != 0);


						//verificar isto com a professora a ver se está bem						
						aux->artigo = temp;
						anterioe = aux;
						aux = aux->proximo;
					}
				}

				Repetir();
				do
				{
					fflush(stdin);
					scanf_s("%d", &repetir);

					if (repetir == 1)
						break;

				} while (repetir != 0);

			} while (repetir != 0);
			break;

			//imprime carrinho acho que tá bem
		case 2:
			do
			{
				system("cls");
				repetir = -1;

				ImprimeCarrinhoCompra(aux);
				Repetir();
				do
				{
					fflush(stdin);
					scanf_s("%d", &repetir);

					if (repetir == 1)
						break;

				} while (repetir != 0);

			} while (repetir != 0);

			break;

			//elimina um artigo do carrinho
		case 3:
			do
			{
				system("cls");
				repetir = -1;
				strcpy_s(nomeArtigo, "");

				SubMenuCompraArtigo();
				fgets(nomeArtigo, sizeof(char) *MAXNOME, stdin);
				//aux = EliminaArtigoNumaLista(aux, nomeArtigo);

				Repetir();
				do
				{
					fflush(stdin);
					scanf_s("%d", &repetir);

					if (repetir == 1)
						break;

				} while (repetir != 0);

			} while (repetir != 0);
			break;

		case 0:
			break;

		default:
			EsperarErro();
			break;
		}

	} while (escolha != 0);

	ListaArtigos amn = anterioe;

	//verificar
	while (amn != NULL)
	{
		tempUm = amn->artigo.codigoArtigo;
		temDois = amn->artigo.quantidadeVendida;
		ActualizarStock(tempUm, temDois);
		amn = amn->proximo;
	}

	Compra compra;
	compra.conjuntoArtigo = aux;
	return compra;
}

SuperDume CriaSuperDume()
{
	int erro;
	char temporaria_Char[MAXLOCALIZACAO];
	SuperDume novo = (SuperDume)calloc(1, sizeof(tCelulaSuperdume));

	do
	{
		erro = 0;	  
		printf_s("\nInsire a localização do SuperDume : ");
		fgets(temporaria_Char, sizeof(char) *MAXLOCALIZACAO,stdin);
		_strupr_s(temporaria_Char);

		for (l = 0; l < strlen(temporaria_Char); l++)
		{
			if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && (temporaria_Char[l] != ' ') && (temporaria_Char[l]!= '\n'))
			{
				printf_s("\nIntroduza caracter\'s validos\n");
				erro = 1;
				break;
			}
		}

		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "")
		{
			erro = 1;
			continue;
		}

		if (ProcuraSuperDumeRetorna(temporaria_Char) == 1)
		{
			erro = 1;
			continue;
		}

		if (erro == 0)
		{
			strcpy_s(novo->localidade, sizeof(char) * MAXLOCALIZACAO, temporaria_Char);
		}

		fflush(stdin);

	} while (erro != 0);
		
	return novo;
}

#pragma endregion


//nao retorna nada												
#pragma region Insere


void InsereCartao(Cartao a)
{
	//tá bem este texto ????
	if (QuerContinuar(a) != 1)
		printf("\n\nCancelou a inserção do cartão");

	else
	{
		system("cls");
		int indice = HashCartao(a.numeroEmissao);

		ListaCartao temp = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
		temp->cartao = a;
		temp->cartao.compras = NULL;
		temp->proximo = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = temp;
	}
}		


int InsereArtigo(Artigo a)
{
	if (QuerContinuar(a) != 1)
	{
		printf("\n\nCancelou a inserção do artigo");
		return 0;
	}

	else
	{
		system("cls");
		int indice = HashArtigo(a.codigoArtigo);

		ListaArtigos temp = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));

		temp->artigo = a;
		temp->proximo = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = temp;
	}	
	return 1;
}


void InsereCompra(unsigned int numeroEmissao, Compra c)
{
	if (QuerCartao(c) != 1)
	{
		printf("\n\nNão foi inserido em nenhum cartão\n");
	}
	else
	{
		system("cls");

		int indice = HashArtigo(numeroEmissao);
		ListaCartao atual = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];
		ListaCartao anterior = NULL;						  

		//ja estou dentro do cartão correcto
		while ( atual->cartao.numeroEmissao != numeroEmissao)
		{
			anterior = atual;
			atual = atual->proximo;
		}

		//Logica está certa mas estara mesmo certo?
		atual->cartao.compras->compra = c;
		atual->cartao.compras->proximo = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice]->cartao.compras;

		anterior->proximo = atual;
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = anterior;

	}
}


void InsereSuperDume(SuperDume s)
{
	int colocado = 0;
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		if (superMercadoLocal[i] == NULL)
		{			
			superMercadoLocal[i] = s;
			printf("\nFoi colocado");
			colocado = 1;
			strcpy_s(localSuperDume, sizeof(char) * MAXLOCALIZACAO, s->localidade);
		}
	}

	if (colocado == 0)
		printf("Ups contacte o administrador para poder utilizar mais lojas");
}


#pragma endregion


//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//retorna numeros que queremos saber
#pragma region Saber

//Feito
int QuantoStock(unsigned int codigoArtigo)
{
	unsigned int indice = 0;
	Artigo a;

	a = ProcuraArtigoRetornaArtigo(codigoArtigo);

	if (a.codigoArtigo == NULL);

	else
		indice = a.quantidadeStock;

	
	return indice;
}

//Feito
int QuantosPontos(unsigned int numeroEmissao)
{
	Cartao temp;
	int aux = 0;

	temp = ProcuraCartaoRetornaCartao(numeroEmissao);

	if (temp.numeroEmissao == NULL);

	else
		aux = temp.pontos;	
	

	return aux;
}

int QuantosSuperDumesHa()
{
	int cont = 0;
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		if (superMercadoLocal[i] != NULL)
			cont++;

	}
	return cont;

}


//Feito
void QuantoGastei(unsigned int numeroEmissao)
{
	Cartao temp;
	double aux = 0.0;
	temp = ProcuraCartaoRetornaCartao(numeroEmissao);

	if (temp.numeroEmissao != NULL)
	{
		CalcularTotalGasto(numeroEmissao);
		aux = temp.totalValorGasto;	
	}

	

	printf("Já gastou : %.2lf", aux);
}


#pragma endregion


#pragma region Actualiza

//Feito
void ActualizarStockSemParametros()
{
	unsigned int codigoArtigo, quantidadeVendida;


	printf_s("\nIntroduza o codigo do Artigo :");
	scanf_s("%d", &codigoArtigo);

	Artigo aux = ProcuraArtigoRetornaArtigo(codigoArtigo);

	//não existe um artigo com esse código
	if (aux.codigoArtigo == NULL);

	//existe
	else
	{
		printf_s("\nIntroduza a quantidade do Artigo vendida :");

		do
		{
			scanf_s("%d", &quantidadeVendida);

		} while (quantidadeVendida < 0 || quantidadeVendida > aux.quantidadeStock);

		AlteraStock(codigoArtigo, quantidadeVendida, aux);
	}
}

//Feito
void ActualizarStock(unsigned int codigoArtigo, unsigned int quantidadeVendida)
{
	Artigo aux = ProcuraArtigoRetornaArtigo(codigoArtigo);

	//não existe um artigo com esse código
	if (aux.codigoArtigo == NULL);

	else
		AlteraStock(codigoArtigo, quantidadeVendida, aux);

}

#pragma endregion   


//Elimina na hash [posição]	 
#pragma region Elimina

void EliminaCartao(unsigned numeroEmissao)
{

	if (numeroEmissao > 0)
	{
		Cartao a = ProcuraCartaoRetornaCartao(numeroEmissao);

		if (a.numeroEmissao == NULL)
			NaoExiste();

		else
		{
			int indice = HashCartao(numeroEmissao);
			ListaCartao atual = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];
			ListaCartao anterior = NULL;
			ListaCartao final = NULL;

			while (atual != NULL && atual->cartao.numeroEmissao != numeroEmissao)
			{
				anterior = atual;
				atual = atual->proximo;
			}


			// se for o primeiro da lista
			if (anterior == NULL)
			{

				final = atual->proximo;
				superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = final;
			}

			else
			{
				anterior->proximo = atual->proximo;
				superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = anterior;
			}
		}
	}
}


void EliminaArtigo(unsigned int codigoArtigo)
{
	if (codigoArtigo > 0)
	{
		int indice = HashArtigo(codigoArtigo);
		ListaArtigos atual = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];
		ListaArtigos anterior = NULL; // (ListaArtigos)calloc(1, (sizeof(tCelulaArtigos)));
		ListaArtigos final = NULL;

		Artigo a = ProcuraArtigoRetornaArtigo(codigoArtigo);

		if (a.codigoArtigo == NULL)
			NaoExiste();

		else
		{
			while (atual != NULL && atual->artigo.codigoArtigo != codigoArtigo)
			{
				anterior = atual;
				atual = atual->proximo;
			}


			// se for o primeiro da lista
			if (anterior == NULL)
			{

				final = atual->proximo;
				superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = final;
			}

			else
			{
				anterior->proximo = atual->proximo;
				superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = anterior;
			}  
		}
	}
}


void EliminaSuperDume()
{
	system("cls");
	int eliminou = 0;
	char local[MAXLOCALIZACAO];

	printf_s("Introduza a localização do SuperDume : ");
	fgets(local, sizeof(char) * MAXLOCALIZACAO, stdin);
	_strupr_s(local);

	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		if (strcmp(local, superMercadoLocal[i]->localidade) == 0)
		{
			if (strcmp(localSuperDume, superMercadoLocal[i]->localidade) == 0)
			{
				printf_s("\n\nCuidado foi eliminado o SuperDume onde trabalhava\n\n");
				strcpy_s(localSuperDume, sizeof(char), "");
			}
			eliminou = 1;
			superMercadoLocal[i] = NULL;
		}
	}

	if (eliminou == 0)
		printf_s("Não foi encontrado");

	else
	{
		printf_s("Foi eliminado");
		if (QuantosSuperDumesHa() == 0)
		{
			printf_s("\n\nDesculpe para poder trabalhar tem que ter no minimo um Super Dume\n");
			EsperarEnter();
			InsereSuperDume(CriaSuperDume());
		}
	}
}

//Feito---------------------------------------------------------------------------
void EliminaTodosCartao()
{
	InicializaSuperDumeTodasListaCartao();
}

//Feito---------------------------------------------------------------------------
void EliminaTodosArtigo()
{
	InicializaSuperDumeTodasListaArtigos();
}


#pragma endregion

//Falta verificar com a professora
//altera na hash [posição] e retorna a alteração
#pragma region Altera

void AlteraStock(unsigned int codigoArtigo, unsigned quantidadeVendida, Artigo a)
{
	int indice = HashArtigo(codigoArtigo);
	ListaArtigos atual = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));

	printf("Tinha em stock : %d\n", a.quantidadeStock);

	//Diminui o stock
	a.quantidadeStock -= quantidadeVendida;

	//mostra alteraçoes

	printf("Agora Tem em stock : %d\n", a.quantidadeStock);
	atual->artigo.quantidadeVendida = 0;


	atual = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];


	while (atual->artigo.codigoArtigo != a.codigoArtigo)
		atual = atual->proximo;

	atual->artigo = a;

	//coloca na hash
	superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = atual;

}

void ReporStock()
{
	unsigned int codigoArtigo, quantidadeComprada;
	ListaArtigos atual = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
	int indice;

	printf_s("\nIntroduza o codigo do Artigo :");
	scanf_s("%d", &codigoArtigo);

	indice = HashArtigo(codigoArtigo);
	Artigo a = ProcuraArtigoRetornaArtigo(codigoArtigo);

	//não existe um artigo com esse código
	if (a.codigoArtigo == NULL);

	//existe
	else
	{
		printf_s("\nIntroduza a quantidade do Artigo vendida :");

		do
		{
			scanf_s("%d", &quantidadeComprada);

		} while (quantidadeComprada < 0);

		printf_s("Tinha em stock : %d\n", a.quantidadeStock);

		//Diminui o stock
		a.quantidadeStock += quantidadeComprada;

		//mostra alteraçoes

		printf("Agora Tem em stock : %d\n", a.quantidadeStock);
		atual->artigo.quantidadeVendida = 0;


		atual = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];


		while (atual->artigo.codigoArtigo != a.codigoArtigo)
			atual = atual->proximo;

		atual->artigo = a;

		//coloca na hash
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = atual;

	}
}

//Feito
void AlteraArtigo(Artigo a)
{
	if (a.codigoArtigo == NULL);

	else
	{
		unsigned int escolha;
		unsigned int codigoArtigo;
		char descricao[MAXNOME];
		float preco;
		unsigned int stock;
		unsigned int erro = 0;
		unsigned int temp = 0;
		float tempFloat = 0.0;
		char temporaria_Char[MAXNOME];

		do
		{
			system("cls");
			escolha = 99;
			MenuAltera(a);
			scanf_s("%d", &escolha);
			fflush(stdin);

			switch (escolha)
			{
			case 2:
				do
				{
					temp = 0;
					printf_s("Insire o novo código do artigo : ");
					scanf_s("%d", &temp);
					fflush(stdin);

				} while (temp != ProcuraArtigoRetornaArtigo(temp).codigoArtigo);

				XORSWAP(a.codigoArtigo, temp);

				if (InsereArtigo(a) == 0);
				else
					EliminaArtigo(a.codigoArtigo);
				
				break;

			case 4:

				do
				{
					temp = 0;
					printf_s("Insire o stock do artigo : ");
					scanf_s("%d", &temp);
					fflush(stdin);

				} while (temp <= 0);

				a.quantidadeStock = temp;
				EliminaArtigo(a.codigoArtigo);
				InsereArtigo(a);

				break;

			case 3:
				do
				{
					tempFloat = 0.0;
					printf_s("Insire o preço do artigo : ");
					scanf_s("%f", &tempFloat);
					fflush(stdin);

				} while (tempFloat <= 0.0);

				a.preco = tempFloat;
				EliminaArtigo(a.codigoArtigo);
				InsereArtigo(a);

				break;

			case 1:
				do
				{
					printf_s("\nInsire a descrição do produto : ");
					fgets(temporaria_Char, sizeof(char) *MAXNOME, stdin);
					_strupr_s(temporaria_Char);

				} while (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "");
				strcpy_s(a.descricao, sizeof(char) * MAXNOME, temporaria_Char);
			
				if (InsereArtigo(a) == 0);

				else
					EliminaArtigo(a.codigoArtigo);

				break;


			default:
				break;
			}
			
			

		} while (escolha != 0);
	}
}




#pragma endregion


//Falta guardar na Hash
#pragma region Calcular


//Falta guardar na Hash
// tá bem?	
void CalcularPontos(unsigned int numeroEmissao)
{
	ListaCartao cartoes = (ListaCartao)calloc(1,sizeof(tCelulaCartao));

#pragma region Encontra Cartao
	int indice = HashCartao(numeroEmissao);
	cartoes = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];

	while (cartoes != NULL)
	{
		if (cartoes->cartao.numeroEmissao == numeroEmissao)
			break;

		cartoes = cartoes->proximo;
	}
#pragma endregion

	float total = 0;

	// percorre todas as compras
	while (cartoes->cartao.compras != NULL)
	{
		// percorre artigos de uma compra
		while (cartoes->cartao.compras->compra.conjuntoArtigo != NULL)
		{
			total += cartoes->cartao.compras->compra.conjuntoArtigo->artigo.preco;
			cartoes->cartao.compras->compra.conjuntoArtigo = cartoes->cartao.compras->compra.conjuntoArtigo->proximo;
		}

		cartoes->cartao.compras = cartoes->cartao.compras->proximo;
	}

	//dar os pontos a um cartao
	cartoes->cartao.pontos = (int)(total / PONTOS);


}


//Falta guardar na Hash
// tá bem?	 
void CalcularTotalGasto(unsigned int numeroEmissao)
{
	ListaCartao cartoes;
	double total = 0;

#pragma region Encontra Cartao

	cartoes = ProcuraCartaoRetornaLista(numeroEmissao);

#pragma endregion

	if (cartoes == NULL);

	else
	{
		// percorre todas as compras
		while (cartoes->cartao.compras != NULL)
		{
			// percorre artigos de uma compra
			while (cartoes->cartao.compras->compra.conjuntoArtigo != NULL)
			{
				total += cartoes->cartao.compras->compra.conjuntoArtigo->artigo.preco;
				cartoes->cartao.compras->compra.conjuntoArtigo = cartoes->cartao.compras->compra.conjuntoArtigo->proximo;
			}

			cartoes->cartao.compras = cartoes->cartao.compras->proximo;
		}

		//dar os pontos a um cartao
		cartoes->cartao.totalValorGasto = total;

		//Falta guardar na Hash

	}
}

//Feito   
int CalculaContador()
{
	unsigned int cont = 0;
	int contadorListasLigadas;
	int comparadorListasLigadas;
	ListaCartao aux;

	if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[1] == NULL);

	else
	{
		for (i = 0; i < HASHSIZE; i++)
		{
			aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];

			contadorListasLigadas = 0;

			//percorre todos os cartões
			while (aux != NULL)
			{
				contadorListasLigadas++;
				if (cont < aux->cartao.numeroEmissao)
					cont = aux->cartao.numeroEmissao;

				aux = aux->proximo;
			}
			comparadorListasLigadas = contadorListasLigadas;

			if (i != 0 && comparadorListasLigadas > contadorListasLigadas)
				break;
		}

	}

	//retorna o proximo numero de emissao 
	return ++cont;
	
}

#pragma endregion

//Feito : Em prencipio funciona
#pragma region Imprime

// Done
void ImprimeListaTodosArtigos()
{
	system("cls");
	l = 0;
	ListaArtigos aux;

	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[i]; 

		if (superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[i] != NULL)
		{																 			
			while (aux != NULL)
			{
				printf_s("%dº Artigo\n", l + 1);
				printf_s("Nome   : %s ", aux->artigo.descricao);
				printf_s("Código : %d\n", aux->artigo.codigoArtigo);
				printf_s("Preço  : %.2f\n", aux->artigo.preco);
				printf_s("Stock  : %d\n", aux->artigo.quantidadeStock);
				printf_s("\n");
				aux = aux->proximo;
				l++;
			}
		}	 		
	}
	if (l == 0)
		printf("\nNão há nada para mostrar\n");

	EsperarEnter();
}

void ImprimeListaTodosArtigosParaCompra()
{
	ListaArtigos aux;

	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[i];
		while (aux != NULL)
		{
			if (aux->artigo.quantidadeStock > 0)
			{
				printf("%dº Artigo\n", i + 1);
				printf("Nome   : %s\n", aux->artigo.descricao);
				printf("Código : %d\n", aux->artigo.codigoArtigo);
				printf("Preço  : %f\n", aux->artigo.preco);
				printf("Stock  : %d\n", aux->artigo.quantidadeStock);
				printf("\n");
			}
			aux = aux->proximo;
		}
	}
	EsperarEnter();
}

// Done
void ImprimeListaTodosClientes()
{
	ListaCartao aux;
	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];
		while (aux != NULL)
		{
			printf("%dº Cliente\n", i + 1);
			printf("Nome           : %s\n", aux->cartao.cliente.nome);
			printf("Cartão Cidadão : %s\n", aux->cartao.cliente.cartaoCidadao);
			printf("Email          : %s\n", aux->cartao.cliente.email);
			printf("Morada         : %s\n", aux->cartao.cliente.morada);
			printf("NIF            : %l\n", aux->cartao.cliente.nif);
			printf("Telefone       : %d\n", aux->cartao.cliente.telefone);
			printf("\n");
			aux = aux->proximo;
		}
	}
	EsperarEnter();
}

//Done todas as compras e artigos
void ImprimeListaTodosCartoes()
{
	ListaCartao aux;
	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];
		//percorre todos os cartões
		while (aux != NULL)
		{
			i = 1;
			printf("\n\nNº Emissão      : %d\n", aux->cartao.numeroEmissao);
			printf("Nome do Cliente : %s\n", aux->cartao.cliente.nome);
			printf("Valor Gasto     : %.2lf\n", aux->cartao.totalValorGasto);
			printf("Pontos          : %lf\n", aux->cartao.pontos);

			
			aux = aux->proximo;
		}
	}
	EsperarEnter();
}

void ImprimeListaTodosCartao()
{
	l = 0;
	ListaCartao aux;
	for (i = 0; i < HASHSIZE; i++)
	{
		//mudar isto para a posiçao do indice em hasCartao
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];
		//percorre todos os cartões
		while (aux != NULL)
		{
			printf("\n\nNº Emissão  : %d\n", aux->cartao.numeroEmissao);
			printf("Nome do Cliente : %s", aux->cartao.cliente.nome);
			printf("Valor Gasto     : %.2lf\n", aux->cartao.totalValorGasto);			
			printf("Pontos          : %d\n\n", aux->cartao.pontos);
			l = 1;
			aux = aux->proximo;
		}
	}
	if (l != 1)
		printf("\n\nNão existe qualquer cartão\n\n");
	EsperarEnter();
}


void ImprimeListaCartao(unsigned int numeroEmissao)
{
	ListaCartao aux = ProcuraCartaoRetornaLista(numeroEmissao);
	i = 1;
	l = 0;
	if (aux != NULL)
	{
		while (aux->cartao.compras != NULL)
		{
			l = 1;
			printf("Compra %d", i);
			printf("_________________________________________________________________________________________");

			//percorre todos os artigos
			while (aux->cartao.compras->compra.conjuntoArtigo != NULL)
			{
				printf("%d - Descrição : %lf", l, aux->cartao.compras->compra.conjuntoArtigo->artigo.descricao);
				printf("Preço          : %2.lf\n", aux->cartao.compras->compra.conjuntoArtigo->artigo.preco);
				printf("Código artigo  : %d\n", aux->cartao.compras->compra.conjuntoArtigo->artigo.codigoArtigo);
				printf("Stock          : %d\n", aux->cartao.compras->compra.conjuntoArtigo->artigo.quantidadeStock);

				aux->cartao.compras->compra.conjuntoArtigo = aux->cartao.compras->compra.conjuntoArtigo->proximo;
				l++;
			}

			aux->cartao.compras = aux->cartao.compras->proximo;
			i++;
		}

		aux = aux->proximo;
	}

	if (l== 0)		 
		printf("\nNão há nada para mostrar\n");

	EsperarEnter();

}


void ImprimeCarrinhoCompra(ListaArtigos a)
{
	ListaArtigos aux = NULL;
	aux = a;
	double soma = 0;

	if (aux == NULL)
		printf("Não adicionou nada");

	else
	{
		while (aux != NULL)
		{
			printf("Artigo     : %s", aux->artigo.descricao);
			printf("Preço      : %.2f\n", aux->artigo.preco);
			soma += aux->artigo.preco;
			printf("Quantidade : %d\n", aux->artigo.quantidadeVendida);
			aux = aux->proximo;
		}
		printf("Total : %.2lf\n", soma);
	}
	EsperarEnter();

}

void ImprimeTodosSuperDumes()
{
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
		printf("%d - %s", i + 1, superMercadoLocal[i]->localidade);
}

#pragma endregion

//Não sei se vai funcionar
#pragma region Ficheiros

// Funcionara ?
void EscreveFicheiro(char nomeFich[])
{
	FILE* f;
	f = fopen(nomeFich, "wb");
	if (f == NULL)
	{
		perror(nomeFich);
		exit(EXIT_FAILURE);
	}
	   	
	else
	{	   		
		ListaArtigos aux;
		for (i = 0; i < HASHSIZE; i++)
		{
			aux = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[i];
			if (aux == NULL);
			else
			{
				fwrite(&aux, CONJUNTOSUPERDUME, 1, f);
				aux = aux->proximo;

			}
			
		}
		fclose(f);

	}
}

// Falta verificar com a professora
void EscreveFicheiroCartoes(char nomeFich[])
{
	FILE* f;

	if (fopen_s(&f, nomeFich, "wb") == NULL)
		perror(nomeFich);

	ListaCartao aux;
	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];

		if (aux == NULL)
			continue;

		else
		{
			while (aux != NULL)
			{
				fwrite(&(aux), sizeof(ListaCartao), 1, f);
				aux = aux->proximo;
			}
		}
	}
	fclose(f); 
}

void LeFicheiroArtigos(char nomeFich[])
{
	FILE* f;
	f = fopen("artigos.txt", "wb");
	if (f == NULL)
	{
		perror(nomeFich);
		exit(EXIT_FAILURE);
	}

	else
	{
		ListaArtigos aux;

		for (i = 0; i < HASHSIZE; i++)
		{
			aux = NULL;
			while (feof(f))
			{
				fread(&(aux), sizeof(ListaArtigos), 1, f);
				aux = aux->proximo;
			}

			if (aux == NULL)
				continue;

			else
			{
				superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[i] = aux;
			}  
		}
		fclose(f);
	}
}

	/*if (fopen_s(&f, nomeFich, "rb") == NULL)
		printf("Erro");*/
    /*
		   lCiclista loadingCic (lCiclista l1) {

		   lCiclista aux;
		   FILE *f;

		   if ((f = fopen ("ciclistas.txt","r")) != NULL) {

		   aux = (lCiclista) malloc(sizeof(Ciclista));

		   fread (aux,sizeof(Ciclista),1,f);

		   while ( !feof(f) ) {

		   aux->seg = l1;
		   l1 = aux;
		   aux = (lCiclista) malloc(sizeof(Ciclista));
		   fread (aux,sizeof(Ciclista),1,f);
		   }

		   fclose (f);
		   return l1;

		   } else {
		   return l1;

		   }






		   List lerclientes()
		   {
		   List l=NULL,auxlist, aux;
		   FILE *f;
		   f=fopen("clientes.dat","rb");
		   if(f==NULL)
		   return NULL;
		   else{
		   while (!feof(f)){
		   if(aux=((cliente*)malloc(sizeof(cliente)) == NULL){
		   printf("erro a alocar memoria \n");
		   return NULL;
		   }
		   if(l==NULL){
		   fread(&aux,sizeof(cliente), 1, f);
		   aux->next=NULL;
		   l=aux;
		   auxlist=l;}
		   else{
		   printf("Cl");
		   fread(&aux,sizeof(cliente), 1, f);
		   aux->next=NULL;
		   auxlist->next=aux;
		   auxlist=aux;
		   }
		   }
		   }
		   fclose(f);
		   printf("LE CLIENTES");
		   system("PAUSE");
		   return(l);
		   }



		   }
		   */
	

// Funcionara ?	Parece que sim, tá melhor este que o de ler artigos
void LeFicheiroCartoes(char nomeFich[])
{
	FILE* f;

	if (fopen_s(&f, nomeFich, "rb") == NULL)
		printf("Erro");

	else
	{
		ListaCartao aux;
		for (i = 0; i < HASHSIZE; i++)
		{
			aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];
			while (aux != NULL)
			{
				fread(&(aux), sizeof(ListaCartao), 1, f);
				aux = aux->proximo;
			}
			superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[HashCartao(aux->cartao.numeroEmissao)] = aux;
		}
		fclose(f);
	}
}


void DadosPredefinidos()
{
	char caminho[MAXNOME];

	//dados predefinidos

	printf_s("Nome do ficheiro dos Artigos :  ");
	//fgets(caminho, sizeof(char) * MAXNOME, stdin);
	fflush(stdin);
	LeFicheiroArtigos("artigos.txt");

	strcpy_s(caminho, "");

	printf_s("Nome do ficheiro dos Cartoes :  ");
	//fgets(caminho, sizeof(char) * MAXNOME , stdin);
	fflush(stdin);
	LeFicheiroCartoes("cartoes.txt");
}

void GuardaDados()
{
	char caminho[MAXNOME];

	//dados predefinidos
	//printf_s("Nome do ficheiro dos Artigos :  ");
	//fgets(caminho, sizeof(char) *MAXNOME, stdin);
	fflush(stdin);
	EscreveFicheiro("artigos.txt");

	/*strcpy_s(caminho, "");

	printf_s("Nome do ficheiro dos Cartoes :  ");
	fgets(caminho, sizeof(char) *MAXNOME, stdin);
	fflush(stdin);
	EscreveFicheiroCartoes(caminho);*/
}

#pragma endregion 

#pragma endregion

void main(int argc, char** argv)
{

#pragma region Variaveis

	//variaveis para escolhas
	unsigned int escolha;
	unsigned int opcaoDados;
	unsigned int repetir;
	unsigned int erro;
	unsigned int subEscolha;

	//variaveis para as horas
	char timeChar[12] = __TIME__;
	unsigned int time = 0;
	unsigned int date = 0;
	unsigned int hora = 0, diaA = 0, mesS = 0, anoO = 0;
	char *mesDiaAno;
	unsigned int tempo;
	char dadosData[19];
	dadosData[18] = '\0';
	char temp[12];
	temp[11] = '\0';


	unsigned int codigoArtigo;
	int numeroEmissao;

#pragma endregion


#pragma region Atribuir Valores

	escolha = -1;
	mesDiaAno = __DATE__; // dar o tempo ao apontador 
	system("cls");
	



#pragma endregion


#pragma region Apresentacao

	Apresentacao();

#pragma endregion


#pragma region Perguntar se quer dados
	do
	{
		printf_s("Para facilitar a verificação ao utilizador que o programa\nrealmente funciona perguntamos a voçê utilizador se deseja\ncarregar dados de um txt. \n\nDeseja ter alguns dados na aplicação ? ");
		printf_s("\n[1] - Sim");
		printf_s("\n[2] - Não\n");
		scanf_s("%d", &opcaoDados);
		fflush(stdin);

		if (opcaoDados == 1)
		{
#pragma region Dados Predefinidos
			AlocaSuperDume();
			system("cls");
			printf("Então terá de dar o nome do seu SuperDume\n");
			printf("_____________________________________________\n\n");
			InsereSuperDume(CriaSuperDume());
			AlocaSuperDumeTodasListaCartao();
			AlocaSuperDumeTodasListaArtigos();
			DadosPredefinidos();

#pragma endregion

		}

		else if (opcaoDados == 2)
		{
			
			system("cls");
			printf("Então terá de criar o seu primeiro SuperDume\n");
			printf("_____________________________________________\n\n");
			InsereSuperDume(CriaSuperDume());
		}

		system("cls");
	} while (opcaoDados != 2 && opcaoDados != 1);

#pragma endregion


#pragma region Menu

	do
	{
		system("cls");

		Principal();
		scanf_s("%d", &escolha);
		fflush(stdin);//limpar a memória temporária

		switch (escolha)
		{
			//Gerir Clientes
#pragma region Caso_1
		case 1:

			do
			{
				system("cls");
				subEscolha = -1;
				SecundarioClientes();
				scanf_s("%d", &subEscolha);
				fflush(stdin);//limpar a memória temporária

				switch (subEscolha)
				{
				case 1:// Funciona								
					do
					{
						system("cls");
						repetir = -1;	

						InsereCartao( CriaCartao());

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 2://  Funciona
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						
						ImprimeListaTodosCartao();
						printf("\nIntroduza '0' para cancelar.\n");
						printf("Introduza o numero de emissão : ");
						scanf_s("%d", &numeroEmissao);

						if (numeroEmissao == 0);

						else
							EliminaCartao(numeroEmissao);
					

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 3:
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							scanf_s("%d", &numeroEmissao);

						} while (numeroEmissao <= 0);

						if (ProcuraCartaoRetornaCartao(numeroEmissao).numeroEmissao == NULL);
						
						else
							InsereCompra(numeroEmissao, CriaCompra());


						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 4:	//	   testar depois de fazer uma compra
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							scanf_s("%d", &numeroEmissao);

						} while (numeroEmissao <= 0);


						ImprimeListaCartao(numeroEmissao);


						system("cls");
						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 5://
					do
					{
						system("cls");
						repetir = -1;

						ImprimeListaTodosCartoes();

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 6:
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							scanf_s("%d", &numeroEmissao);

						} while (numeroEmissao <= 0);


						QuantoGastei(numeroEmissao);

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 7:	  // testar depois de fazer uma compra
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							scanf_s("%d", &numeroEmissao);

						} while (numeroEmissao <= 0);


						printf("\n\nTem %d pontos\n",QuantosPontos(numeroEmissao));

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 0:
					system("cls");
					break;

				default:
					printf_s("Opção não conhecida\n");
					printf_s("\nEspere . . .");

					tempo = clock();//conta o tempo
					while (clock() - tempo <= 2000);//enquanto não se passaram 3segundos						

					system("cls");
					break;
				}

			} while (subEscolha != 0);

			system("cls");
			break;

#pragma endregion 

			//Gerir Artigos	  Funciona
#pragma region Caso_2

		case 2:
			do
			{
				system("cls");
				subEscolha = -1;
				SecundarioArtigos();
				scanf_s("%d", &subEscolha);
				fflush(stdin);//limpar a memória temporária

				switch (subEscolha)
				{
				case 1://	Funciona							
					do
					{
						system("cls");
						repetir = -1;

						InsereArtigo(CriaArtigo());

						printf("\n\n");
						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 2://	Funciona
					do
					{
						system("cls");
						repetir = -1;

						ActualizarStockSemParametros();

						printf("\n\n");
						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 3://	Funciona
					do
					{
						system("cls");
						repetir = -1;

						ReporStock();	  

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 4://   Funciona
					do
					{
						system("cls");
						erro = 0;
						escolha = 0;
						repetir = -1;
								   

						ImprimeListaTodosArtigos();
						printf("\nIntroduza '0' para cancelar.\n");
						printf("Introduza o código do produto : ");
						scanf_s("%d", &escolha);
						
						if (escolha == 0);		 							

						else 
							EliminaArtigo(escolha);

						printf("\n\n");
						Repetir();

						do
						{
							fflush(stdin);
							scanf_s("%d", &repetir);

							if (repetir == 1)
								break;

						} while (repetir != 0);

					} while (repetir != 0);

					break;

				case 5://Funciona
					do
					{
						system("cls");
						repetir = -1;

						EliminaTodosArtigo();

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 6:	//Funciona
					do
					{
						system("cls");
						repetir = -1;

						ImprimeListaTodosArtigos();

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 7:
					do
					{
						system("cls");
						repetir = -1;

						printf_s("\nIntroduza o codigo do Artigo :");
						scanf_s("%d", &codigoArtigo);

						ProcuraArtigoRetornaArtigo(codigoArtigo);

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

				case 8:	   //Funciona
					do
					{
						system("cls");
						repetir = -1;

						printf_s("\nIntroduza o codigo do Artigo :");
						scanf_s("%d", &codigoArtigo);

						AlteraArtigo(ProcuraArtigoRetornaArtigo(codigoArtigo));

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 0:
					system("cls");
					break;

				default:
					EsperarErro();
					break;
				}

			} while (subEscolha != 0);

			system("cls");
			break;

#pragma endregion 

			//Carregar Ficheiro
#pragma region Caso_3
		case 3:

			system("cls");
			DadosPredefinidos();
			break;

#pragma endregion 

			//Guardar Ficheiro
#pragma region Caso_4
		case 4:

			system("cls");
			GuardaDados();
			break;

#pragma endregion 		

			//Escolher SuperDume Funciona
#pragma region Caso_5
		case 5:
			system("cls");
			EscolherSuperDume();
			break;

#pragma endregion 		

			//Gerir SuperDume Funciona
#pragma region Caso_6
		case 6:
			do
			{
				system("cls");
				subEscolha = -1;
				MenuSuperDume();
				scanf_s("%d", &subEscolha);
				fflush(stdin);//limpar a memória temporária

				switch (subEscolha)
				{
				case 1://	Done							
					do
					{
						repetir = -1;

						InsereSuperDume(CriaSuperDume());

						printf("\n\n");
						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 2://	Done
					do
					{
						repetir = -1;


						EliminaSuperDume();

						printf("\n\n");
						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;	
				
				case 0:
						system("cls");
						break;

				default:
						EsperarErro();
						break;
				}

			} while (subEscolha != 0);


			break;

#pragma endregion 		

		    // Sair Funciona
#pragma region Caso_0

		case 0:
			break;

#pragma endregion


#pragma region Default

		default:
			EsperarErro();
			break;

#pragma endregion
		}

	} while (escolha != 0);


#pragma endregion 


#pragma region Bonitos 
	EsperarPouco();
	system("cls");

	printf(", ----------------, , -------- - , \n");
	EsperarPouco();
	printf("    ,-----------------------,          ,\"        ,\"|						\n");
	EsperarPouco();
	printf("  ,"                      ,"|        ,\"        ,\"  |					  \n");
	EsperarPouco();
	printf(" +-----------------------+  |      ,\"        ,\"    |					 \n");
	EsperarPouco();
	printf(" |  .-----------------.  |  |     +---------+      |					\n");
	EsperarPouco();
	printf(" |  |                 |  |  |     | -==----'|      |					\n");
	EsperarPouco();
	printf(" |  |  I LOVE DOS!    |  |  |     |         |      |				   \n");
	EsperarPouco();
	printf(" |  |  Good command   |  |  |/----|`---=    |      |				 \n");
	EsperarPouco();
	printf(" |  |  C:\>_           |  |  |   ,/|==== ooo |      ;				\n"); 
	EsperarPouco();
	printf(" |  |                 |  |  |  // |(((( [33]|    ,\"				\n");																																		
	EsperarPouco();
	printf(" |  `-----------------'  |,\" .;'| |((((     |  ,\"				 \n");
	EsperarPouco();
	printf(" +-----------------------+  ;;  | |         |,\"				\n");	
	EsperarPouco();
	printf("    /_)______________(_/  //'   | +---------+					 \n");		
	EsperarPouco();
    printf("___________________________/___  `,								 \n");	
	EsperarPouco();
    printf("  /  oooooooooooooooo  .o.  oooo /,   \,\"-----------		\n");		
	EsperarPouco();
	printf(" / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,\"			  \n");	
	EsperarPouco();
    printf("/_==__==========__==_ooo__ooo=_/'   /___________,\"				 \n");	
	EsperarPouco();
	printf("`-----------------------------'                               \n");		
	EsperarPouco();
#pragma endregion 
	getc(stdin);
	exit(EXIT_SUCCESS);
}

