// ***********************************************************************
// Assembly         : 
// Author           : Utilizador
// Created          : 05-22-2015
//
// Last Modified By : Utilizador
// Last Modified On : 05-25-2015
// ***********************************************************************
// <copyright file="Header.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
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


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>	
#include <string.h>
#include <windows.h>

#define SECURE_ERASE 35
#define MAXLOCALIZACAO 30
#define CONJUNTOSUPERDUME 1
#define MAXSTOCK 999999999
#define PONTOS 50
#define GASTO 50
#define LETRASCC 8
#define MAXCC 13
#define MAXMORADA 101
#define MAXNOME 51
#define HASHSIZE 101
#define XORSWAP(a, b)	((a)^=(b),(b)^=(a),(a)^=(b))

/// <summary>
/// The i
/// </summary>
int i;
/// <summary>
/// The l
/// </summary>
int l;
/// <summary>
/// The contador
/// </summary>
int contador = 0;

int jaAbriu = 0;

/// <summary>
/// Struct __unnamed_struct_0001_1
/// </summary>
typedef struct
{
	/// <summary>
	/// The codigo artigo
	/// </summary>
	unsigned int codigoArtigo;
	/// <summary>
	/// The descricao
	/// </summary>
	char descricao[MAXNOME];
	/// <summary>
	/// The preco
	/// </summary>
	float preco;
	/// <summary>
	/// The quantidade stock
	/// </summary>
	unsigned int quantidadeStock;
	/// <summary>
	/// The quantidade vendida
	/// </summary>
	unsigned int quantidadeVendida;//quantidade numa compra

} Artigo;    


/// <summary>
/// Struct __unnamed_struct_0001_2
/// </summary>
typedef struct
{
	/// <summary>
	/// The nome
	/// </summary>
	char nome[MAXNOME];
	/// <summary>
	/// The cartao cidadao
	/// </summary>
	char cartaoCidadao[MAXCC];
	/// <summary>
	/// The telefone
	/// </summary>
	unsigned int telefone;
	/// <summary>
	/// The nif
	/// </summary>
	unsigned long nif;
	/// <summary>
	/// The morada
	/// </summary>
	char morada[MAXMORADA];
	/// <summary>
	/// The email
	/// </summary>
	char email[MAXNOME];

} Cliente; 

		   //Lista
/// <summary>
/// Struct Artigos
/// </summary>
typedef struct Artigos
{
	/// <summary>
	/// The artigo
	/// </summary>
	Artigo artigo;
	/// <summary>
	/// The proximo
	/// </summary>
	struct Artigos *proximo;

} tCelulaArtigos, *ListaArtigos;


/// <summary>
/// Struct __unnamed_struct_0001_3
/// </summary>
typedef struct
{
	/// <summary>
	/// The conjunto artigo
	/// </summary>
	ListaArtigos conjuntoArtigo;
	/// <summary>
	/// The quantos artigos
	/// </summary>
	unsigned int quantosArtigos;

} Compra;

//Lista
/// <summary>
/// Struct Compras
/// </summary>
typedef struct Compras
{
	/// <summary>
	/// The compra
	/// </summary>
	Compra compra;
	/// <summary>
	/// The proximo
	/// </summary>
	struct Compras *proximo;

} tCelulaCompras, *ListaCompras;


/// <summary>
/// Struct __unnamed_struct_0001_4
/// </summary>
typedef struct
{
	/// <summary>
	/// The compras
	/// </summary>
	ListaCompras compras;
	/// <summary>
	/// The pontos
	/// </summary>
	unsigned int pontos;
	/// <summary>
	/// The cliente
	/// </summary>
	Cliente cliente;
	/// <summary>
	/// The numero emissao
	/// </summary>
	unsigned int numeroEmissao;
	/// <summary>
	/// The quantas compras
	/// </summary>
	unsigned int quantasCompras;

} Cartao;

//Lista
/// <summary>
/// Struct Cartoes
/// </summary>
typedef struct Cartoes
{
	/// <summary>
	/// The cartao
	/// </summary>
	Cartao cartao;
	/// <summary>
	/// The proximo
	/// </summary>
	struct Cartoes *proximo;

} tCelulaCartao, *ListaCartao;


/// <summary>
/// Struct __unnamed_struct_0001_5
/// </summary>
typedef struct
{
	/// <summary>
	/// The tabela cartao
	/// </summary>
	ListaCartao tabelaCartao[HASHSIZE];
	/// <summary>
	/// The tabela artigos
	/// </summary>
	ListaArtigos tabelaArtigos[HASHSIZE];
	/// <summary>
	/// The localidade
	/// </summary>
	char localidade[MAXLOCALIZACAO];
}tCelulaSuperdume, *SuperDume;

/// <summary>
/// The super mercado local
/// </summary>
SuperDume superMercadoLocal[CONJUNTOSUPERDUME];
/// <summary>
/// The local super dume
/// </summary>
char localSuperDume[MAXLOCALIZACAO];
/// <summary>
/// The indice local super dume
/// </summary>
int	indiceLocalSuperDume = 0;


#pragma region Metodos
//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Menu's'

void DefinePt();

int QuantosArtigosTemUmaCompra(Compra);

int QuantasComprasTemUmCartao(Cartao);

//Bem-vindo
void Apresentacao();

void EscolherSuperDume();

//Menu Principal
void Principal();

void SecundarioClientes();
void MenuAltera(Artigo );
void SecundarioArtigos();

void MenuCompra();

void MenuSuperDume();

//antes de escolher um artigo
void SubMenuNumeroEmissão();

//antes de escolher um artigo
void SubMenuCompraArtigo();

//depois de escolher um artigo
void SubMenuCompraQuantidade();

//escolher quantidade
void SubMenuCompraEscolherQuantidade();

void NaoExiste();

void Repetir();
void EsperarErro();

void Esperar();

void EsperarPouco();

void EsperarEnter();
int SimNao();

int QuerContinuar(Artigo );

int QuerCartao(Compra );

int QuerContinuar(Cartao );
#pragma endregion  

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Inicializa

int EncontraSuperDume(char []);

void InicializaTodosSuperDume();

void InicializaSuperDume();

void InicializaSuperDumeTodasListaArtigos();

void InicializaSuperDumeListaArtigos(unsigned int );

void InicializaSuperDumeTodasListaCartao();

void InicializaSuperDumeListaCartao(unsigned int );

#pragma endregion 

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Aloca memória


void AlocaTodosSuperDume();

void AlocaSuperDume();

void AlocaSuperDumeTodasListaArtigos();

void AlocaSuperDumeListaArtigos(unsigned int );

void AlocaSuperDumeTodasListaCartao();

void AlocaSuperDumeListaCartao(unsigned int );

void AlocaSuperDumeCompras(unsigned int );

#pragma endregion

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Hash

//retorna a posição para um array
int HashArtigo(int );

//retorna a posição para um array
int HashCartao(int );

#pragma endregion


//retorna objectos
#pragma region Procura

//Falta enviar a lista toda, tou a enviar apenas o que está depois
//envia a lista onde o cartao está inserido
ListaCartao ProcuraCartaoRetornaLista(unsigned int );

//Falta enviar a lista toda, tou a enviar apenas o que está depois
//envia a lista onde o cartao está inserido
ListaArtigos ProcuraArtigoRetornaLista(unsigned int );

//Feito
Cartao ProcuraCartaoRetornaCartao(unsigned int );
//Feito
Artigo ProcuraArtigoRetornaArtigo(unsigned int );

//Feito
//Contra : como tenho a hash a ordenar por numero e nao por nome de artigo, vou ter que verificar todas as listas
Artigo ProcuraArtigoRetornaArtigo(char []);

int ProcuraSuperDumeRetorna(char []);
#pragma endregion


//retorna o objecto criado
#pragma region Criar

//se o string copy no final tá a funcionar bem
//Feito verificar 
Cliente CriaCliente();

//Feito
Cartao CriaCartao();

//Feito
Artigo CriaArtigo();

ListaArtigos InsereCompraDaniela(ListaArtigos , Artigo );

//está mal
Compra CriaCompra();

SuperDume CriaSuperDume();

#pragma endregion


//nao retorna nada												
#pragma region Insere


void InsereCartao(Cartao );

int InsereArtigo(Artigo );

void InsereCompra(unsigned int , Compra );


void InsereSuperDume(SuperDume );


#pragma endregion


//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//retorna numeros que queremos saber
#pragma region Saber

//Feito
int QuantoStock(unsigned int );

int RetornaPontos(unsigned int );

//Feito
void QuantosPontos(unsigned int );

int QuantosSuperDumesHa();


//Feito
void QuantoGastei(unsigned int );

#pragma endregion


#pragma region Actualiza

//Feito
void ActualizarStockSemParametros();

//Feito
void ActualizarStock(unsigned int , unsigned int );

#pragma endregion   


//Elimina na hash [posição]	 
#pragma region Elimina

ListaArtigos EliminaArtigoNumaLista(ListaArtigos , char []);

void EliminaCartao(unsigned );


void EliminaArtigo(unsigned int );


void EliminaSuperDume();

//Feito---------------------------------------------------------------------------
void EliminaTodosCartao();

//Feito---------------------------------------------------------------------------
void EliminaTodosArtigo();


#pragma endregion

//altera na hash [posição] e retorna a alteração
#pragma region Altera

void AlteraStock(unsigned int , unsigned , Artigo);

void ReporStock();
//Feito
void AlteraArtigo(Artigo );



#pragma endregion


//Falta guardar na Hash
#pragma region Calcular

double CalcularTotalGasto(unsigned int );

Artigo ProcuraArtigoRetornaArtigoDaCompra(char [], ListaArtigos );

void ReporStockNaCompra(unsigned int , unsigned int );

//Feito   
int CalculaContador();

#pragma endregion

//Feito : Em prencipio funciona
#pragma region Imprime

// Done
void ImprimeListaTodosArtigos();

void ImprimeListaTodosArtigosParaCompra();

// Done
void ImprimeListaTodosClientes();
//Done todas as compras e artigos
void ImprimeListaTodosCartoes();

void ImprimeListaTodosCartao();

void ImprimeListaCartao(unsigned int );


void ImprimeCarrinhoCompra(ListaArtigos );

void ImprimeTodosSuperDumes();
#pragma endregion

//Não sei se vai funcionar
#pragma region Ficheiros

// Falta verificar com a professora
void EscreveFicheiroArtigos(char []);
// Falta verificar com a professora
void EscreveFicheiroCartoes(char []);


void LeFicheiroArtigos(char []);

// Funcionara ?	Parece que sim, tá melhor este que o de ler artigos
void LeFicheiroCartoes(char []);


void LeDados();

void GuardaDados();

#pragma endregion 

#pragma endregion