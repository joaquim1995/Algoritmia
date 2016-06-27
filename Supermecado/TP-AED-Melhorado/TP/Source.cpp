// ***********************************************************************
// Assembly         : 
// Author           : Utilizador
// Created          : 05-22-2015
// Language : C
// For : AED  
// Last Modified By : Utilizador
// Last Modified On : 05-27-2015
// ***********************************************************************
// <copyright file="Source.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************


#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

#pragma region Metodos


//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Menu's'

/// <summary>
/// Defines the pt.
/// </summary>
void DefinePt()
{
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	fflush(stdin);//limpar a memória temporária	
}

//Bem-vindo
/// <summary>
/// Apresentacaoes this instance.
/// </summary>
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

/// <summary>
/// Escolhers the super dume.
/// </summary>
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
/// <summary>
/// Principals this instance.
/// </summary>
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

/// <summary>
/// Secundarioes the clientes.
/// </summary>
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
	printf_s("[6] - Consultar Valor Total de Compras de um Cartão\n");
	printf_s("[7] - Consultar Pontos de um Cartão\n");
	printf_s("[8] - Consultar os Clientes\n");
	printf_s("[0] - Voltar\n");

}

/// <summary>
/// Menus the altera.
/// </summary>
/// <param name="a">a.</param>
void MenuAltera(Artigo a)
{
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");
	printf_s("Está a trabalhar no SuperDume : %s", localSuperDume);
	printf_s("\n\n\n");
	printf_s("[1] - Descriçao - %s\n", a.descricao);
	printf_s("[2] - Código - %d\n",a.codigoArtigo);
	printf_s("[3] - Preço - %.2f\n",a.preco);
	printf_s("[4] - Stock - %d\n", a.quantidadeStock);
	printf_s("[0] - Voltar\n");

}

/// <summary>
/// Secundarioes the artigos.
/// </summary>
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

/// <summary>
/// Menus the compra.
/// </summary>
void MenuCompra()
{
	printf_s("\n[1] - Escolher Artigo \n");
	printf_s("[2] - Mostrar o Carrinho de compras \n");
	printf_s("[3] - Eliminar um Artigo da Compra \n");
	printf_s("[0] - Voltar\n");
}

/// <summary>
/// Menus the super dume.
/// </summary>
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
/// <summary>
/// Subs the menu numero emissão.
/// </summary>
void SubMenuNumeroEmissão()
{
	printf_s("\nIntroduza o numero de Emissão do Cartão : ");
}

//antes de escolher um artigo
/// <summary>
/// Subs the menu compra artigo.
/// </summary>
void SubMenuCompraArtigo()
{
	printf_s("\nIntroduza o nome do Artigo :");
}

//depois de escolher um artigo
/// <summary>
/// Subs the menu compra quantidade.
/// </summary>
void SubMenuCompraQuantidade()
{
	printf_s("\n[1] - Escolher Quantidade \n");
	printf_s("[0] - Cancelar\n");
}

//escolher quantidade
/// <summary>
/// Subs the menu compra escolher quantidade.
/// </summary>
void SubMenuCompraEscolherQuantidade()
{
	printf_s("\nIntroduza a quantidade desejada : \n");
}

/// <summary>
/// Naoes the existe.
/// </summary>
void NaoExiste()
{
	printf("O artigo não foi apagado pois é inesxistente");
}

/// <summary>
/// Repetirs this instance.
/// </summary>
void Repetir()
{
	
	printf_s("\n\n\nDeseja repetir o processo ? \n\n");
	printf_s("\n[1] - Repetir o processo \n");
	printf_s("[0] - Voltar\n");
}

/// <summary>
/// Esperars the erro.
/// </summary>
void EsperarErro()
{
	int tempo;
	printf_s("Opção não conhecida\n");
	printf_s("\nEspere . . .");

	tempo = clock();//conta o tempo
	while (clock() - tempo <= 2000);//enquanto não se passaram 3segundos						

	system("cls");
}

/// <summary>
/// Esperars this instance.
/// </summary>
void Esperar()
{
	int tempo;

	tempo = clock();//conta o tempo
	while (clock() - tempo <= 1200);//enquanto não se passaram 3segundos
}

/// <summary>
/// Esperars the pouco.
/// </summary>
void EsperarPouco()
{
	int tempo;

	tempo = clock();//conta o tempo
	while (clock() - tempo <= 250);//enquanto não se passaram 3segundos
}

/// <summary>
/// Esperars the enter.
/// </summary>
void EsperarEnter()
{
	fflush(stdin);
	printf("Prime o enter ");
	getc(stdin);
}

/// <summary>
/// Sims the nao.
/// </summary>
/// <returns>int.</returns>
int SimNao()
{
	int simNao;
	printf_s("\n[1] - Sim \n");
	printf_s("[0] - Não\n");
	do
	{
		simNao = 0;

		scanf_s("%1d", &simNao);

		if (simNao == 1)
			break;

	} while (simNao != 0);
	return simNao;
}

/// <summary>
/// Quers the continuar.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
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

/// <summary>
/// Quers the cartao.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
int QuerCartao(Compra a)
{
	system("cls");
	int aux;
	printf("Quer registar em cartão ?\n\n");
	aux = SimNao();
	return aux;
}

/// <summary>
/// Quers the continuar.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
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

/// <summary>
/// Encontras the super dume.
/// </summary>
/// <param name="localizacao">The localizacao.</param>
/// <returns>int.</returns>
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

/// <summary>
/// Inicializas the todos super dume.
/// </summary>
void InicializaTodosSuperDume()
{
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		superMercadoLocal[i] = NULL;
		//strcpy_s(superMercadoLocal[i]->localidade, sizeof(char),"\0");
	}
}

/// <summary>
/// Inicializas the super dume.
/// </summary>
void InicializaSuperDume()
{

	if (indiceLocalSuperDume >= 0)
	{
			free(superMercadoLocal[indiceLocalSuperDume]);
			superMercadoLocal[indiceLocalSuperDume] = (SuperDume)calloc(1, sizeof(tCelulaSuperdume));
			strcpy_s(superMercadoLocal[indiceLocalSuperDume]->localidade, sizeof(char), "");
			printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");
}			 

/// <summary>
/// Inicializas the super dume todas lista artigos.
/// </summary>
void InicializaSuperDumeTodasListaArtigos()
{
	if (indiceLocalSuperDume >= 0)
	{
		for (l = 0; l < HASHSIZE; l++)
		{
			free(superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[l]);
			superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[l] = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
		}
		printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");

	
}
						
/// <summary>
/// Inicializas the super dume lista artigos.
/// </summary>
/// <param name="numeroArtigo">The numero artigo.</param>
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
		
/// <summary>
/// Inicializas the super dume todas lista cartao.
/// </summary>
void InicializaSuperDumeTodasListaCartao()
{

	if (indiceLocalSuperDume >= 0)
	{
		for (l = 0; l < HASHSIZE; l++)
		{
			free(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[l]);
			superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[l]=(ListaCartao)calloc(1, sizeof(tCelulaCartao));
			superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[l] = NULL;

		}
		printf_s("Foi Inicializado\n");
	}
	else
		printf_s("Não foi Inicializado, pois não foi encontrado");


}	   

/// <summary>
/// Inicializas the super dume lista cartao.
/// </summary>
/// <param name="numeroCartao">The numero cartao.</param>
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


/// <summary>
/// Alocas the todos super dume.
/// </summary>
void AlocaTodosSuperDume()
{
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
	{
		superMercadoLocal[i] = (SuperDume)calloc(1,sizeof(tCelulaSuperdume));	  
		superMercadoLocal[indiceLocalSuperDume] = NULL;
	}
}

/// <summary>
/// Alocas the super dume.
/// </summary>
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

/// <summary>
/// Alocas the super dume todas lista artigos.
/// </summary>
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
  	 
/// <summary>
/// Alocas the super dume lista artigos.
/// </summary>
/// <param name="numeroArtigo">The numero artigo.</param>
void AlocaSuperDumeListaArtigos(unsigned int numeroArtigo)
{
	if (indiceLocalSuperDume >= 0)
	{
		int indice = HashArtigo(numeroArtigo);
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos)); 
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = NULL;
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

/// <summary>
/// Alocas the super dume todas lista cartao.
/// </summary>
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

/// <summary>
/// Alocas the super dume lista cartao.
/// </summary>
/// <param name="numeroCartao">The numero cartao.</param>
void AlocaSuperDumeListaCartao(unsigned int numeroCartao)
{

	if (indiceLocalSuperDume >= 0)
	{
		int indice = HashArtigo(numeroCartao);
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = NULL;
		printf_s("Foi Alocado");
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

/// <summary>
/// Alocas the super dume compras.
/// </summary>
/// <param name="numeroCartao">The numero cartao.</param>
void AlocaSuperDumeCompras(unsigned int numeroCartao)
{			  
	if (indiceLocalSuperDume >= 0)
	{
		Cartao aux = ProcuraCartaoRetornaCartao(numeroCartao);
		ListaCartao temp;
		ListaCartao anterior= NULL;
		int indice;

		//o cartao existe
		if (aux.numeroEmissao != NULL)
		{	
			indice = HashArtigo(aux.numeroEmissao);
			temp = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];

			if (temp->cartao.compras == NULL)
			{	 

				while (temp->cartao.numeroEmissao != (aux.numeroEmissao)   )
				{
					anterior = temp;
					temp = temp->proximo;	   
				}

				if (anterior == NULL)
				{
					temp->cartao.compras = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

					temp->cartao.compras = NULL;
					superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = temp;
				}

				else
				{
					temp->cartao.compras = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
					temp->cartao.compras = NULL;
					anterior->proximo = temp;
					superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = anterior;
				}
			}					 		
		}	   		
	}
	else
		printf_s("Não foi Alocado, pois não foi encontrado");
}

#pragma endregion


//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Hash

//retorna a posição para um array
/// <summary>
/// Hashes the artigo.
/// </summary>
/// <param name="codigo">The codigo.</param>
/// <returns>int.</returns>
int HashArtigo(int codigo)
{
	int sum = codigo;

	sum %= (HASHSIZE - 1);

	return sum;
}

//retorna a posição para um array
/// <summary>
/// Hashes the cartao.
/// </summary>
/// <param name="codigoEmissao">The codigo emissao.</param>
/// <returns>int.</returns>
int HashCartao(int codigoEmissao)
{
	int sum = codigoEmissao;

	sum %= (HASHSIZE - 1);

	return sum;
}

#pragma endregion


//retorna objectos
#pragma region Procura


//envia a lista onde o cartao está inserido
/// <summary>
/// Procuras the cartao retorna lista.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
/// <returns>ListaCartao.</returns>
ListaCartao ProcuraCartaoRetornaLista(unsigned int numeroEmissao)
{														 
	int indice = HashCartao(numeroEmissao), encontrado = 0;
	ListaCartao aux = NULL ;  
	ListaCartao anterior = NULL;
	
	if (indiceLocalSuperDume >= 0)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];

		while (aux != NULL && encontrado == 0)
		{
			if (aux->cartao.numeroEmissao == numeroEmissao)
			{
				encontrado = 1;
			}
			else
			{
				aux = aux->proximo;
			}
		}	 		
	}	  	
	
	return aux;
}


//envia a lista onde o cartao está inserido
/// <summary>
/// Procuras the artigo retorna lista.
/// </summary>
/// <param name="numeroArtigo">The numero artigo.</param>
/// <returns>ListaArtigos.</returns>
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
/// <summary>
/// Procuras the cartao retorna cartao.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
/// <returns>Cartao.</returns>
Cartao ProcuraCartaoRetornaCartao(unsigned int numeroEmissao)
{
	Cartao temp;

	ListaCartao aux = ProcuraCartaoRetornaLista(numeroEmissao);


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
/// <summary>
/// Procuras the artigo retorna artigo.
/// </summary>
/// <param name="codigoArtigo">The codigo artigo.</param>
/// <returns>Artigo.</returns>
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
/// <summary>
/// Procuras the artigo retorna artigo.
/// </summary>
/// <param name="nomeArtigo">The nome artigo.</param>
/// <returns>Artigo.</returns>
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
	temp.codigoArtigo = NULL;
	printf("O artigo não foi encontrado");
	return temp;
}


/// <summary>
/// Procuras the artigo retorna artigo da compra.
/// </summary>
/// <param name="nomeArtigo">The nome artigo.</param>
/// <param name="lista">The lista.</param>
/// <returns>Artigo.</returns>
Artigo ProcuraArtigoRetornaArtigoDaCompra(char nomeArtigo[], ListaArtigos lista)
{
	ListaArtigos aux = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));

	
		aux = lista;

		while (aux != NULL)
		{
			if (strcmp(nomeArtigo, aux->artigo.descricao) == 0 && aux->artigo.quantidadeStock > 0)
				return aux->artigo;

			aux = aux->proximo;
		}

	Artigo temp;
	temp.codigoArtigo = NULL;
	printf("O artigo não foi encontrado");
	return temp;
}


/// <summary>
/// Procuras the super dume retorna.
/// </summary>
/// <param name="localizacao">The localizacao.</param>
/// <returns>int.</returns>
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


//retorna o objecto criado
#pragma region Criar

//Feito verificar 
/// <summary>
/// Crias the cliente.
/// </summary>
/// <returns>Cliente.</returns>
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
		fflush(stdin);
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
		strcpy_s(temporaria_Char, sizeof(CHAR) , "");
		printf_s("\nInsire o teu nome completo : ");
		fflush(stdin);
		fgets(temporaria_Char, sizeof(char) * MAXNOME, stdin);
		fflush(stdin);

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
		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "" || temporaria_Char[0] == '\n')
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
		fflush(stdin);
		fgets(temporaria_Char, sizeof(char) *MAXMORADA,stdin);
		fflush(stdin);
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
		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "" || temporaria_Char[0] == '\n')
			erro = 1;

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
		fflush(stdin);
		scanf_s("%d", &temp);
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
		fflush(stdin);
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
		fflush(stdin);
		fgets(temporaria_Char, sizeof(char) *MAXCC,stdin);
		fflush(stdin);
		_strupr_s(temporaria_Char);

		for (i = 0; i < LETRASCC; i++)
		{
			if ((temporaria_Char[i] < '0') || (temporaria_Char[i] > '9'))
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

		if (temporaria_Char[0] == '\0' || temporaria_Char[0] == ' ' || temporaria_Char == "" || temporaria_Char[0] == '\n')
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
/// <summary>
/// Crias the cartao.
/// </summary>
/// <returns>Cartao.</returns>
Cartao CriaCartao()
{
	Cartao c;

	c.cliente = CriaCliente();
	c.numeroEmissao = CalculaContador(); 
	c.pontos = 0;
	c.quantasCompras = 0;
	//c.totalValorGasto = 0.0;


	return c;
}

//Feito
/// <summary>
/// Crias the artigo.
/// </summary>
/// <returns>Artigo.</returns>
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
		fflush(stdin);
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
		fflush(stdin);
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
		fflush(stdin);
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
		fflush(stdin);
		fgets(temporaria_Char, sizeof(char) *MAXNOME ,stdin);
		fflush(stdin);

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

/// <summary>
/// Inseres the lista.
/// </summary>
/// <param name="lista">The lista.</param>
/// <param name="temp">The temporary.</param>
/// <returns>ListaArtigos.</returns>
ListaArtigos InsereLista(ListaArtigos lista, Artigo temp)
{
	ListaArtigos res = NULL;
	int tempUm, tempDois;

	if (lista == NULL)
	{
		lista = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));

		lista->artigo = temp;
		lista->proximo = NULL;
		res = lista;
	}
	else
	{
		ListaArtigos nova = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));
		nova->artigo = temp;
		nova->proximo = lista;
		res = nova;
	}
	tempUm = temp.codigoArtigo;
	tempDois = temp.quantidadeVendida;
	ActualizarStock(tempUm, tempDois);
	return res;
}

//Funciona
/// <summary>
/// Crias the compra.
/// </summary>
/// <returns>Compra.</returns>
Compra CriaCompra()
{
	int repetir;
	unsigned int escolha;
	unsigned int escolhaQuantidade;
	unsigned int escolhaQuantidadeD;
	char nomeArtigo[MAXNOME];
	unsigned int quantidadeArtigo;
	ListaArtigos anterioe = NULL;
	ListaArtigos aux = NULL;// (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
	Artigo temp;


	escolha = 99;

	do
	{
		system("cls");
		MenuCompra();
		scanf_s("%d", &escolha);

		switch (escolha)
		{
			//compra artigo	 funciona
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
					fflush(stdin);
					fgets(nomeArtigo, sizeof(char) * MAXNOME, stdin);
					fflush(stdin);
					_strupr_s(nomeArtigo);
					

					//ve se o artigo existe
					temp = ProcuraArtigoRetornaArtigo(nomeArtigo);

					//se existir
					if (temp.codigoArtigo != NULL)
					{
						//escolher a quantidade ou cancelar a compra do artigo
						do
						{	
							//Menu
							quantidadeArtigo = 0;
							SubMenuCompraQuantidade();
							do
							{
								escolhaQuantidadeD = 3;
								fflush(stdin);
								scanf_s("%d", &escolhaQuantidadeD);
								fflush(stdin);

								if (escolhaQuantidadeD == 1)
									break;

							} while (escolhaQuantidadeD != 0);

							if (temp.quantidadeVendida == temp.quantidadeStock)
								printf("\nO artigo esgotou\n");

							//se escolher introduzir a quantidade
							else if (escolhaQuantidadeD == 1 )
							{
								if (temp.quantidadeVendida != 0)
									printf("\nAinda há em stock : %d  . . .\n", (temp.quantidadeStock - temp.quantidadeVendida));
								
								//introduzimos a quantidade
								SubMenuCompraEscolherQuantidade();
								
								do
								{
									quantidadeArtigo = -1;
									fflush(stdin);
									scanf_s("%d", &quantidadeArtigo);
									fflush(stdin);

								} while (quantidadeArtigo < 0 || temp.quantidadeStock < temp.quantidadeVendida + quantidadeArtigo);
								temp.quantidadeVendida += quantidadeArtigo;

								break;
							}

						} while (escolhaQuantidadeD != 0);


						aux = InsereLista(aux, temp);  
						
					}
				}

				

				Repetir();
				do
				{
					fflush(stdin);
					scanf_s("%d", &repetir);
					fflush(stdin);

					if (repetir == 1)
						break;

				} while (repetir != 0);

			} while (repetir != 0);
			break;

			//imprime bem
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
					fflush(stdin);

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
				fflush(stdin);
				fgets(nomeArtigo, sizeof(char) *MAXNOME, stdin);
				fflush(stdin);
				_strupr_s(nomeArtigo);

				temp = ProcuraArtigoRetornaArtigoDaCompra(nomeArtigo,aux);

				//se existir
				if (temp.codigoArtigo != NULL)
				{

					ReporStockNaCompra(temp.codigoArtigo,temp.quantidadeVendida);
					aux = EliminaArtigoNumaLista(aux,nomeArtigo);
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

		case 0:
			break;

		default:
			EsperarErro();
			break;
		}

	} while (escolha != 0);



	Compra compra;
	compra.conjuntoArtigo = aux;
	return compra;
}

/// <summary>
/// Crias the super dume.
/// </summary>
/// <returns>SuperDume.</returns>
SuperDume CriaSuperDume()
{
	int erro;
	char temporaria_Char[MAXLOCALIZACAO];
	SuperDume novo = (SuperDume)calloc(1, sizeof(tCelulaSuperdume));

	do
	{
		erro = 0;	  
		printf_s("\nInsire a localização do SuperDume : ");
		fflush(stdin);
		fgets(temporaria_Char, sizeof(char) *MAXLOCALIZACAO,stdin);
		fflush(stdin);
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


/// <summary>
/// Inseres the cartao.
/// </summary>
/// <param name="a">a.</param>
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
		temp->cartao.quantasCompras = 0;
		temp->proximo = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];
		superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = temp;
	}
}		


/// <summary>
/// Inseres the artigo.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
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


/// <summary>
/// Inseres the compra.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
/// <param name="c">The c.</param>
void InsereCompra(unsigned int numeroEmissao, Compra c)
{
	if (QuerCartao(c) != 1)
	{
		printf("\n\nNão foi inserido em nenhum cartão\n");
	}
	else
	{
         		system("cls");

		if (c.conjuntoArtigo == NULL)
			printf("\n\nA compra nao tinha nada\n");

		else
		{
			int indice = HashArtigo(numeroEmissao);
			ListaCartao aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];
			ListaCartao anterior = NULL;

			//ja estou dentro do cartão correcto
			while (aux->cartao.numeroEmissao != numeroEmissao)
			{
				anterior = aux;
				aux = aux->proximo;
			}


			if (aux->cartao.compras == NULL)
				AlocaSuperDumeCompras(numeroEmissao);

			ListaCompras atual = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

			atual->compra = c;
			atual->compra.quantosArtigos = QuantosArtigosTemUmaCompra(c);
			atual->proximo = aux->cartao.compras;
			aux->cartao.compras = atual;
			aux->cartao.quantasCompras = QuantasComprasTemUmCartao(aux->cartao);

			if (anterior == NULL)
			{
				superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = aux;
			}

			else
			{
				anterior->proximo = aux;
				superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = anterior;
			}
					 
		}
	}

}


/// <summary>
/// Inseres the super dume.
/// </summary>
/// <param name="s">The s.</param>
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
/// <summary>
/// Quantoes the stock.
/// </summary>
/// <param name="codigoArtigo">The codigo artigo.</param>
/// <returns>int.</returns>
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
/// <summary>
/// Quantoses the pontos.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
void QuantosPontos(unsigned int numeroEmissao)
{
	system("cls");
	double num = 0.0;
	int pontos=0;
	int indice = HashCartao(numeroEmissao), encontrado = 0;
	ListaCartao aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCartao temp = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCompras atual = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
	ListaCompras anterior = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

	if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] == NULL);

	else
	{


		_memccpy(aux, superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], 1, sizeof(tCelulaCartao));
		_memccpy(temp, aux, 1, sizeof(tCelulaCartao));

		if (indiceLocalSuperDume >= 0)
		{
			//entra dentro do cartao
			while (aux != NULL && encontrado == 0)
			{
				if (aux->cartao.numeroEmissao == numeroEmissao)
					encontrado = 1;

				else
					aux = aux->proximo;

			}
		}

		if (aux->cartao.quantasCompras > 0)
		{



			anterior = aux->cartao.compras;

			if (encontrado == 0);

			else
			{

				if (anterior != NULL && anterior->compra.conjuntoArtigo)
				{
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
					_memccpy(atual, anterior, 1, sizeof(tCelulaCompras));

					// percorre todas as compras
					while (anterior != NULL)
					{
						// percorre artigos de uma compra
						while (anterior->compra.conjuntoArtigo != NULL)
						{
							num += (anterior->compra.conjuntoArtigo->artigo.quantidadeVendida * anterior->compra.conjuntoArtigo->artigo.preco);
							anterior->compra.conjuntoArtigo = anterior->compra.conjuntoArtigo->proximo;
						}

						anterior = anterior->proximo;
					}

					anterior = atual;
					_memccpy(temp->cartao.compras, anterior, 1, sizeof(tCelulaCompras));
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
				}
			}
		}

	}

	pontos = (int)(num / PONTOS);

	if (num == 0.0)
		printf("\nNão tem pontos \n\n\n");

	else
		printf("Tem : %.2lf  pontos\n\n\n", pontos);

	EsperarEnter();	
	
}

/// <summary>
/// Retornas the pontos.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
/// <returns>int.</returns>
int RetornaPontos(unsigned int numeroEmissao)
{
	double num = 0.0;
	int pontos = 0;
	int indice = HashCartao(numeroEmissao), encontrado = 0;
	ListaCartao aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCartao temp = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCompras atual = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
	ListaCompras anterior = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

	if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] == NULL);

	else
	{
		memcpy_s(aux, sizeof(tCelulaCartao), superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], sizeof(tCelulaCartao));
		//_memccpy(aux, superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], 1, sizeof(tCelulaCartao));
		_memccpy(temp, aux,1, sizeof(tCelulaCartao));

		if (indiceLocalSuperDume >= 0)
		{
			//entra dentro do cartao
			while (aux != NULL && encontrado == 0)
			{
				if (aux->cartao.numeroEmissao == numeroEmissao)
					encontrado = 1;

				else
					aux = aux->proximo;

			}
		}

		if (aux->cartao.quantasCompras > 0)
		{


			anterior = aux->cartao.compras;

			if (encontrado == 0);

			else
			{

				if (anterior != NULL && anterior->compra.conjuntoArtigo)
				{
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
					_memccpy(atual, anterior, 1, sizeof(tCelulaCompras));

					// percorre todas as compras
					while (anterior != NULL)
					{
						// percorre artigos de uma compra
						while (anterior->compra.conjuntoArtigo != NULL)
						{
							num += (anterior->compra.conjuntoArtigo->artigo.quantidadeVendida * anterior->compra.conjuntoArtigo->artigo.preco);
							anterior->compra.conjuntoArtigo = anterior->compra.conjuntoArtigo->proximo;
						}

						anterior = anterior->proximo;
					}

					anterior = atual;
					_memccpy(temp->cartao.compras, anterior, 1, sizeof(tCelulaCompras));
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
				}
			}

			pontos = (int)(num / PONTOS);
		}
		return pontos;

	}
}


/// <summary>
/// Quantoses the super dumes ha.
/// </summary>
/// <returns>int.</returns>
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
/// <summary>
/// Quantoes the gastei.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
void QuantoGastei(unsigned int numeroEmissao)
{
	system("cls");
	double num = 0.0;
	int indice = HashCartao(numeroEmissao), encontrado = 0;
	ListaCartao aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCartao temp = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCompras atual = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
	ListaCompras anterior = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

	if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] == NULL);


	else
	{	  
		memcpy_s(aux, sizeof(tCelulaCartao), superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], sizeof(tCelulaCartao));
		//_memccpy(aux, superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], 1, sizeof(tCelulaCartao));
		_memccpy(temp, aux, 1, sizeof(tCelulaCartao));

		if (indiceLocalSuperDume >= 0)
		{
			//entra dentro do cartao
			while (aux != NULL && encontrado == 0)
			{
				if (aux->cartao.numeroEmissao == numeroEmissao)
					encontrado = 1;

				else
					aux = aux->proximo;

			}
		}

		if (aux->cartao.quantasCompras > 0)
		{

			anterior = aux->cartao.compras;

			if (encontrado == 0);

			else
			{

				if (anterior != NULL && anterior->compra.conjuntoArtigo)
				{
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
					_memccpy(atual, anterior, 1, sizeof(tCelulaCompras));

					// percorre todas as compras
					while (anterior != NULL)
					{
						// percorre artigos de uma compra
						while (anterior->compra.conjuntoArtigo != NULL)
						{
							num += (anterior->compra.conjuntoArtigo->artigo.quantidadeVendida * anterior->compra.conjuntoArtigo->artigo.preco);
							anterior->compra.conjuntoArtigo = anterior->compra.conjuntoArtigo->proximo;
						}

						anterior = anterior->proximo;
					}

					anterior = atual;
					_memccpy(temp->cartao.compras, anterior, 1, sizeof(tCelulaCompras));
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
				}
			}
		}
	}

	if (num == 0.0)
		printf("\nNão gastou nada\n\n\n");

	else
		printf("Já gastou : %.2lf\n\n\n", num);

	EsperarEnter();
}


/// <summary>
/// Quantoses the artigos tem uma compra.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
int QuantosArtigosTemUmaCompra(Compra a)
{
	ListaArtigos aux = a.conjuntoArtigo;
	l = 0;
	while (aux!= NULL)
	{
		l++;
		aux = aux->proximo;
	}				   
	return l;
}


/// <summary>
/// Quantases the compras tem um cartao.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
int QuantasComprasTemUmCartao(Cartao a)
{
	ListaCompras aux = a.compras;
	l = 0;
	while (aux != NULL)
	{
		l++;
		aux = aux->proximo;
	}
	return l;
}

#pragma endregion


#pragma region Actualiza

//Feito
/// <summary>
/// Actualizars the stock sem parametros.
/// </summary>
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
/// <summary>
/// Actualizars the stock.
/// </summary>
/// <param name="codigoArtigo">The codigo artigo.</param>
/// <param name="quantidadeVendida">The quantidade vendida.</param>
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

/// <summary>
/// Eliminas the artigo numa lista.
/// </summary>
/// <param name="aux">The aux.</param>
/// <param name="nomeArtigo">The nome artigo.</param>
/// <returns>ListaArtigos.</returns>
ListaArtigos EliminaArtigoNumaLista(ListaArtigos aux, char nomeArtigo[])
{
	int encontrou = 0;
	ListaArtigos anterior = NULL;
	ListaArtigos temp = aux;

	if (temp != NULL)
	{
		//Será que está bem?
		while (temp != NULL)
		{
			if (strcmp(temp->artigo.descricao, nomeArtigo) == 0)
			{
				encontrou = 1;
				printf("Elimidado");
				break;
			}
			else
			{
				anterior = temp;
				temp = temp->proximo;
			}
		}

		if (encontrou == 1)
		{
			if (anterior != NULL)
			{
				anterior->proximo = temp->proximo;
				return anterior;
			}
			else
			{	 //apaga o cartao que queremos
				return temp->proximo;
			}
		}
	}

	NaoExiste();
	return aux;

}

/// <summary>
/// Eliminas the cartao.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
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


/// <summary>
/// Eliminas the artigo.
/// </summary>
/// <param name="codigoArtigo">The codigo artigo.</param>
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


/// <summary>
/// Eliminas the super dume.
/// </summary>
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
/// <summary>
/// Eliminas the todos cartao.
/// </summary>
void EliminaTodosCartao()
{
	InicializaSuperDumeTodasListaCartao();
}

//Feito---------------------------------------------------------------------------
/// <summary>
/// Eliminas the todos artigo.
/// </summary>
void EliminaTodosArtigo()
{
	InicializaSuperDumeTodasListaArtigos();
}


#pragma endregion


//altera na hash [posição] e retorna a alteração
#pragma region Altera

/// <summary>
/// Alteras the stock.
/// </summary>
/// <param name="codigoArtigo">The codigo artigo.</param>
/// <param name="quantidadeVendida">The quantidade vendida.</param>
/// <param name="a">a.</param>
void AlteraStock(unsigned int codigoArtigo, unsigned quantidadeVendida, Artigo a)
{
	int indice = HashArtigo(codigoArtigo);
	ListaArtigos atual = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
	ListaArtigos anterior = NULL;

	printf("Tinha em stock : %d\n", a.quantidadeStock);

	//Diminui o stock
	a.quantidadeStock -= quantidadeVendida;

	//mostra alteraçoes

	printf("Agora Tem em stock : %d\n", a.quantidadeStock);
	atual->artigo.quantidadeVendida = 0;


	atual = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];


	while (atual->artigo.codigoArtigo != a.codigoArtigo)
	{
		anterior = atual;
		atual = atual->proximo;
	}

	atual->artigo = a;

	if (anterior ==NULL)
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = atual;

	else
	{
		anterior->proximo = atual;
		superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = anterior;
	}																	   
}

/// <summary>
/// Repors the stock.
/// </summary>
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

/// <summary>
/// Repors the stock na compra.
/// </summary>
/// <param name="codigoArtigo">The codigo artigo.</param>
/// <param name="quantidadeComprada">The quantidade comprada.</param>
void ReporStockNaCompra(unsigned int codigoArtigo, unsigned int quantidadeComprada)
{
	ListaArtigos atual = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
	int indice;

	indice = HashArtigo(codigoArtigo);
	Artigo a = ProcuraArtigoRetornaArtigo(codigoArtigo);

	//não existe um artigo com esse código
	if (a.codigoArtigo == NULL);

	//existe
	else
	{	
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
/// <summary>
/// Alteras the artigo.
/// </summary>
/// <param name="a">a.</param>
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


#pragma region Calcular
 
/// <summary>
/// Calculars the total gasto.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
/// <returns>double.</returns>
double CalcularTotalGasto(unsigned int numeroEmissao)
{

	double num = 0.0;
	int indice = HashCartao(numeroEmissao), encontrado = 0;
	ListaCartao aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCartao temp = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCompras atual = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
	ListaCompras anterior = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

	if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] == NULL);

	else
	{
		memcpy_s(aux, sizeof(tCelulaCartao), superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice],sizeof(tCelulaCartao));
		//_memccpy(aux, superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], 1, sizeof(tCelulaCartao));
		_memccpy(temp, aux, 1, sizeof(tCelulaCartao));

		if (indiceLocalSuperDume >= 0)
		{
			//entra dentro do cartao
			while (aux != NULL && encontrado == 0)
			{
				if (aux->cartao.numeroEmissao == numeroEmissao)
					encontrado = 1;

				else
					aux = aux->proximo;

			}
		}

		if (aux->cartao.quantasCompras > 0)
		{
			anterior = aux->cartao.compras;

			if (encontrado == 0);

			else
			{

				if (anterior != NULL && anterior->compra.conjuntoArtigo)
				{
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
					_memccpy(atual, anterior, 1, sizeof(tCelulaCompras));

					// percorre todas as compras
					while (anterior != NULL)
					{
						// percorre artigos de uma compra
						while (anterior->compra.conjuntoArtigo != NULL)
						{
							num += (anterior->compra.conjuntoArtigo->artigo.quantidadeVendida * anterior->compra.conjuntoArtigo->artigo.preco);
							anterior->compra.conjuntoArtigo = anterior->compra.conjuntoArtigo->proximo;
						}

						anterior = anterior->proximo;
					}

					anterior = atual;
					_memccpy(temp->cartao.compras, anterior, 1, sizeof(tCelulaCompras));
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
				}
			}
		}
	}


	return num;
}

//Feito   
/// <summary>
/// Calculas the contador.
/// </summary>
/// <returns>int.</returns>
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


//Feito 
#pragma region Imprime

// Done
/// <summary>
/// Imprimes the lista todos artigos.
/// </summary>
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


/// <summary>
/// Imprimes the lista todos artigos para compra.
/// </summary>
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
				printf("Preço  : %.2f\n", aux->artigo.preco);
				printf("Stock  : %d\n", aux->artigo.quantidadeStock);
				printf("\n");
			}
			aux = aux->proximo;
		}
	}
	EsperarEnter();
}

// Done
/// <summary>
/// Imprimes the lista todos clientes.
/// </summary>
void ImprimeListaTodosClientes()
{
	l = 0;
	ListaCartao aux;
	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];
		while (aux != NULL )
		{
			printf("%dº Cliente\n", l + 1);
			printf("Nº Emissão     : %d\n", aux->cartao.numeroEmissao);
			printf("Nome           : %s", aux->cartao.cliente.nome);
			printf("Cartão Cidadão : %s\n", aux->cartao.cliente.cartaoCidadao);
			printf("Email          : %s", aux->cartao.cliente.email);
			printf("Morada         : %s", aux->cartao.cliente.morada);
			printf("NIF            : %lu\n", aux->cartao.cliente.nif);
			printf("Telefone       : %d\n", aux->cartao.cliente.telefone);
			printf("\n");
			l++;
			aux = aux->proximo;
		}
	}
	EsperarEnter();
}


/// <summary>
/// Imprimes the lista todos cartao.
/// </summary>
void ImprimeListaTodosCartao()
{
	l = 0;
	ListaCartao aux;
	for (i = 0; i < HASHSIZE; i++)
	{
		aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];
		//percorre todos os cartões
		while (aux != NULL)
		{
			printf("\n\nNº Emissão  : %d\n", aux->cartao.numeroEmissao);
			printf("Nome do Cliente : %s", aux->cartao.cliente.nome);
			printf("Valor Gasto     : %.2lf\n", CalcularTotalGasto(aux->cartao.numeroEmissao));
			printf("Pontos          : %d\n\n", RetornaPontos(aux->cartao.numeroEmissao));
			l = 1;
			aux = aux->proximo;
		}
	}
	if (l != 1)
		printf("\n\nNão existe qualquer cartão\n\n");
	EsperarEnter();
}

			
/// <summary>
/// Imprimes the lista cartao.
/// </summary>
/// <param name="numeroEmissao">The numero emissao.</param>
void ImprimeListaCartao(unsigned int numeroEmissao)
{
	int indice = HashCartao(numeroEmissao), encontrado = 0;
	ListaCartao aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCartao temp = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
	ListaCompras atual = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
	ListaCompras anterior = (ListaCompras)calloc(1, sizeof(tCelulaCompras));


	if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] == NULL);

	else
	{
		memcpy_s(aux, sizeof(tCelulaCartao), superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], sizeof(tCelulaCartao));

		//_memccpy(aux, superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], 1, sizeof(tCelulaCartao));
		_memccpy(temp, aux, 1, sizeof(tCelulaCartao));

		if (indiceLocalSuperDume >= 0)
		{
			//entra dentro do cartao
			while (aux != NULL && encontrado == 0)
			{
				if (aux->cartao.numeroEmissao == numeroEmissao)
					encontrado = 1;

				else
					aux = aux->proximo;

			}
		}


		i = 1;
		l = 0;

		if (aux->cartao.compras > 0)
		{


			anterior = aux->cartao.compras;



			if (encontrado == 0);

			else
			{

				if (anterior != NULL && anterior->compra.conjuntoArtigo)
				{
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
					_memccpy(atual, anterior, 1, sizeof(tCelulaCompras));

					while (anterior != NULL)
					{
						l = 1;
						printf("\nCompra %d\n", i);
						printf("______________________________________\n");

						//percorre todos os artigos
						while (anterior->compra.conjuntoArtigo != NULL)
						{


							printf("%d -         Descrição : %s", l, anterior->compra.conjuntoArtigo->artigo.descricao);
							printf("	        Preço : %.2f\n", anterior->compra.conjuntoArtigo->artigo.preco);
							printf("        Código artigo : %d\n", anterior->compra.conjuntoArtigo->artigo.codigoArtigo);
							printf("  Quantidade Comprada : %d\n", anterior->compra.conjuntoArtigo->artigo.quantidadeVendida);
							printf("Quantidade de Artigos : %d\n\n", anterior->compra.quantosArtigos);

							anterior->compra.conjuntoArtigo = anterior->compra.conjuntoArtigo->proximo;
							l++;
						}

						anterior = anterior->proximo;
						i++;
					}

					anterior = atual;
					_memccpy(temp->cartao.compras, anterior, 1, sizeof(tCelulaCompras));
					_memccpy(superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice], temp, 1, sizeof(tCelulaCartao));
				}

				if (l == 0)
					printf("\nNão há nada para mostrar\n");
			}
		}
	}
	
	
	EsperarEnter();

}



/// <summary>
/// Imprimes the carrinho compra.
/// </summary>
/// <param name="a">a.</param>
void ImprimeCarrinhoCompra(ListaArtigos a)
{
	ListaArtigos aux = NULL;
	aux = a;
	double soma = 07;

	if (aux == NULL)
		printf("Não adicionou nada\n");

	else
	{
		while (aux != NULL)
		{
			
			printf("Artigo     : %s", aux->artigo.descricao);
			printf("Preço      : %.2f\n", aux->artigo.preco);
			soma += (aux->artigo.preco * aux->artigo.quantidadeVendida);
			printf("Quantidade : %d\n", aux->artigo.quantidadeVendida);
			printf("\n\n");
			aux = aux->proximo;
		}
		printf("Total : %lf\n", soma);
	}
	EsperarEnter();

}


/// <summary>
/// Imprimes the todos super dumes.
/// </summary>
void ImprimeTodosSuperDumes()
{
	for (i = 0; i < CONJUNTOSUPERDUME; i++)
		printf("%d - %s", i + 1, superMercadoLocal[i]->localidade);
}

#pragma endregion
		

#pragma region Ficheiros

/// <summary>
/// Novas the lista.
/// </summary>
/// <param name="lista">The lista.</param>
/// <param name="temp">The temporary.</param>
/// <returns>ListaArtigos.</returns>
ListaArtigos NovaLista(ListaArtigos lista, Artigo temp)
{
	ListaArtigos res = NULL;

	if (lista == NULL)
	{
		lista = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));

		lista->artigo = temp;
		lista->proximo = NULL;
		res = lista;
	}
	else
	{
		ListaArtigos nova = (ListaArtigos)calloc(1,sizeof(tCelulaArtigos));
		nova->artigo = temp;
		nova->proximo = lista;
		res = nova;
	}

	return res;
}


/// <summary>
/// Novas the lista cartao.
/// </summary>
/// <param name="lista">The lista.</param>
/// <param name="temp">The temporary.</param>
/// <returns>ListaCartao.</returns>
ListaCartao NovaListaCartao(ListaCartao lista, Cartao temp)
{
	ListaCartao res = NULL;

	if (lista == NULL)
	{
		lista = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
		lista->cartao.compras = (ListaCompras)calloc(1, sizeof(tCelulaCompras)); 
		lista->cartao = temp;
		lista->proximo = NULL;
		res = lista;
	}
	else
	{
		ListaCartao nova = (ListaCartao)calloc(1, sizeof(tCelulaCartao));
		nova->cartao = temp;
		nova->proximo = lista;
		res = nova;
	}

	return res;
}


/// <summary>
/// Novas the lista compra.
/// </summary>
/// <param name="lista">The lista.</param>
/// <param name="temp">The temporary.</param>
/// <returns>ListaCompras.</returns>
ListaCompras NovaListaCompra(ListaCompras lista, Compra temp)
{
	ListaCompras res = NULL;

	if (lista == NULL)
	{
		lista = (ListaCompras)calloc(1, sizeof(tCelulaCompras));

		lista->compra = temp;
		lista->proximo = NULL;
		res = lista;
	}
	else
	{
		ListaCompras nova = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
		nova->compra = temp;
		nova->proximo = lista;
		res = nova;
	}

	return res;
}	   
																		

/// <summary>
/// Escreves the ficheiro artigos.
/// </summary>
/// <param name="nomeFich">The nome fich.</param>
void EscreveFicheiroArtigos(char nomeFich[])
{
	FILE* f;
	l = 0;
	f = fopen(nomeFich, "w");

	if (f == NULL)
	{
		perror(nomeFich);
		EsperarPouco();
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
				while (aux != NULL)
				{				
					fwrite(&aux->artigo, sizeof(Artigo), 1, f);
					aux = aux->proximo;
				}
			}
		}
		fclose(f);
	}

	EsperarPouco();
}


/// <summary>
/// Escreves the ficheiro cartoes.
/// </summary>
/// <param name="nomeFich">The nome fich.</param>
void EscreveFicheiroCartoes(char nomeFich[])
{
	l = 0;
	FILE* f;
	f = fopen(nomeFich, "w");
	if (f == NULL)
	{
		perror(nomeFich);
		EsperarPouco();
	}
	else
	{	
		ListaCartao aux;
		for (i = 0; i < HASHSIZE; i++)
		{
			aux = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[i];

			if (aux == NULL);

			else
			{
		
				while (aux != NULL)
				{		 										
					fwrite(&aux->cartao, sizeof(Cartao), 1, f);	

					for (l = 0; l < aux->cartao.quantasCompras; l++)
					{
						fwrite(&aux->cartao.compras->compra, sizeof(Compra), 1, f);

						for (i = 0; i < aux->cartao.compras->compra.quantosArtigos; i++)
						{
							fwrite(&aux->cartao.compras->compra.conjuntoArtigo->artigo, sizeof(Artigo), 1, f);
							aux->cartao.compras->compra.conjuntoArtigo = aux->cartao.compras->compra.conjuntoArtigo->proximo;
						}
						aux->cartao.compras = aux->cartao.compras->proximo;
					}  
					aux = aux->proximo;
				}
			}
		}
		fclose(f);
	}
	EsperarPouco();
	
}


/// <summary>
/// Les the ficheiro artigos.
/// </summary>
/// <param name="nomeFich">The nome fich.</param>
void LeFicheiroArtigos(char nomeFich[])
{
	FILE* f;
	ListaArtigos res = NULL;
	int indice;
	Artigo artigo;
	f = fopen("artigos.txt", "r");

	if (f == NULL)
	{
		perror(nomeFich);
		EsperarPouco();
	}

	else
	{
		ListaArtigos aux = NULL;

		while (!feof(f))
		{	
			aux = res;
			fread(&artigo, sizeof(Artigo), 1, f);

			if (feof(f))
				break;

			//criamos o artigo
			if (artigo.codigoArtigo > NULL)
				res = NovaLista(aux, artigo);
		}  		
		fclose(f);

		while (res != NULL)
		{
			aux = NULL;
			indice = HashArtigo(res->artigo.codigoArtigo);
			
			if (superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] != NULL)
			{
				aux = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
				aux->artigo = res->artigo;
				aux->proximo = superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice];
				superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = aux;
			}
			else
				superMercadoLocal[indiceLocalSuperDume]->tabelaArtigos[indice] = NovaLista(aux, res->artigo);
			
			res = res->proximo;
		}																										 			
	}
}
 

/// <summary>
/// Les the ficheiro cartoes.
/// </summary>
/// <param name="nomeFich">The nome fich.</param>
void LeFicheiroCartoes(char nomeFich[])
{
	FILE* f;
	int cont = 0;
	l = 0;
	int indiceAnterior, indice = -1;
	ListaCartao res = NULL;

	ListaCartao aux = NULL;
	ListaCartao cartao= (ListaCartao)calloc(1,sizeof(tCelulaCartao));	
	cartao->cartao.compras = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
	cartao->cartao.compras->compra.conjuntoArtigo = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));

	f = fopen("cartoes.txt", "r");
	if (f == NULL)
	{
		system("cls");
		printf("\n\n");
		perror(nomeFich);
		printf("\n\n");
		EsperarEnter();
	}

	else
	{			
		while (!feof(f))
		{
			aux = res;

			fread(&cartao->cartao, sizeof(Cartao), 1, f);

			if (feof(f) || (cartao->cartao.numeroEmissao == 4278124286 && cartao->cartao.quantasCompras == 4278124286))
				break;
			
						
			if (cartao->cartao.quantasCompras > NULL)
			{				
				cartao->cartao.compras = (ListaCompras)calloc(1, sizeof(tCelulaCompras));
				for (l = 0; l < cartao->cartao.quantasCompras; l++)
				{
					fread(&(cartao->cartao.compras->compra), sizeof(Compra), 1, f);

					if (cartao->cartao.compras->compra.quantosArtigos > NULL)
					{

						cartao->cartao.compras->compra.conjuntoArtigo = (ListaArtigos)calloc(1, sizeof(tCelulaArtigos));
						for (i = 0; i < cartao->cartao.compras->compra.quantosArtigos; i++)
						{
							fread(&cartao->cartao.compras->compra.conjuntoArtigo->artigo, sizeof(Artigo), 1, f);	  							
						}	 
					}
					
				}					
			}
			

			//criamos o cartao->cartao
			if (cartao->cartao.numeroEmissao > NULL)
				res = NovaListaCartao(aux, cartao->cartao);
												   
		}

		fclose(f);

		while (res != NULL)
		{
			indice = HashArtigo(res->cartao.numeroEmissao);
			aux = NULL;

			if (superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] != NULL)
			{
				aux = (ListaCartao)calloc(1, sizeof(tCelulaCartao));	 //tinha tCelulaCompras
				aux->cartao = res->cartao;
				aux->proximo = superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice];
				superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = aux;
			}

			else
			{
				superMercadoLocal[indiceLocalSuperDume]->tabelaCartao[indice] = NovaListaCartao(aux, res->cartao);
			}

			res = res->proximo;
		}
	}

	

	
}


/// <summary>
/// Les the dados.
/// </summary>
void LeDados()
{
	fflush(stdin);
	LeFicheiroArtigos("artigos.txt");

	fflush(stdin);
	LeFicheiroCartoes("cartoes.txt");
}

/// <summary>
/// Guardas the dados.
/// </summary>
void GuardaDados()
{
	fflush(stdin);
	EscreveFicheiroArtigos("artigos.txt");

	fflush(stdin);
	EscreveFicheiroCartoes("cartoes.txt");
}

#pragma endregion 

#pragma endregion

/// <summary>
/// Mains the specified argc.
/// </summary>
/// <param name="argc">The argc.</param>
/// <param name="argv">The argv.</param>
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
	char *mesDiaAno;
	unsigned int tempo;
	unsigned int codigoArtigo = 0;
	int numeroEmissao = 0;

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
			LeDados();
			jaAbriu = 1;

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
				case 1:// Criar cartao								
					do
					{
						system("cls");
						repetir = -1;

						InsereCartao(CriaCartao());

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					break;

				case 2://  Eliminar cartao
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;


						ImprimeListaTodosCartao();
						printf("\nIntroduza '0' para cancelar.\n");
						printf("Introduza o numero de emissão : ");
						fflush(stdin);
						scanf_s("%d", &numeroEmissao);
						fflush(stdin);


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

				case 3:	  // fazer uma compra
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;
						ImprimeListaTodosCartao();	
						printf("\n\n");
						SubMenuNumeroEmissão();
						do
						{
							fflush(stdin);
							scanf_s("%d", &numeroEmissao);
							fflush(stdin);

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

				case 4:	//	   mostrar a compra
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							fflush(stdin);
							scanf_s("%d", &numeroEmissao);
							fflush(stdin);

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
							 
				case 6:	 // mostra o total gasto
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							fflush(stdin);
							scanf_s("%d", &numeroEmissao);
							fflush(stdin);

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

				case 7:	  // Saber os pontos
					do
					{
						system("cls");
						repetir = -1;
						numeroEmissao = 0;

						SubMenuNumeroEmissão();
						do
						{
							fflush(stdin);
							scanf_s("%d", &numeroEmissao);
							fflush(stdin);

						} while (numeroEmissao <= 0);


						printf("\n\nTem %d pontos\n", RetornaPontos(numeroEmissao));

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					system("cls");
					break;

				case 8:	  // ImprimeListaTodosClientes
					do
					{
						system("cls");
						repetir = -1;

						ImprimeListaTodosClientes();

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);

					system("cls");
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

			//Gerir Artigos	
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
						fflush(stdin);
						scanf_s("%d", &escolha);
						fflush(stdin);

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
						codigoArtigo = 0;
						printf_s("\nIntroduza o codigo do Artigo :");
						fflush(stdin);
						scanf_s("%d", &codigoArtigo);
						fflush(stdin);

						ProcuraArtigoRetornaArtigo(codigoArtigo);

						Repetir();
						scanf_s("%d", &repetir);
						fflush(stdin);

						if (repetir == 1)
							continue;

						else if (repetir == 0)
							break;

					} while (repetir != 0);
					break;

				case 8:	   //Funciona
					do
					{
						system("cls");
						repetir = -1;

						printf_s("\nIntroduza o codigo do Artigo :");
						fflush(stdin);
						scanf_s("%d", &codigoArtigo);
						fflush(stdin);

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
			if (jaAbriu == 0)
			{
				system("cls");
				InicializaSuperDume();
				InicializaSuperDumeTodasListaArtigos();
				InicializaSuperDumeTodasListaCartao();
				LeDados();

			}
			
			break;

#pragma endregion 

			//Guardar Ficheiro
#pragma region Caso_4
		case 4:

			system("cls");
			GuardaDados();
			break;

#pragma endregion 		

			//Escolher SuperDume 
#pragma region Caso_5
		case 5:
			system("cls");
			EscolherSuperDume();
			break;

#pragma endregion 		

			//Gerir SuperDume 
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

			// Sair
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
	printf("  ,", "|        ,\"        ,\"  |					  \n");
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
	printf(" |  |  C:\/>_           |  |  |   ,/|==== ooo |      ;				\n");
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
	printf("  /  oooooooooooooooo  .o.  oooo //,   \,\''-----------		\n");
	EsperarPouco();
	printf(" / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,\\n");
	EsperarPouco();
	printf("/_==__==========__==_ooo__ooo=_/'   /___________,\"				 \n");
	EsperarPouco();
	printf("`-----------------------------'                               \n");
	EsperarPouco();
#pragma endregion 

	exit(EXIT_SUCCESS);
}

