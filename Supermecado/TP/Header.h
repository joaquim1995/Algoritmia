#include <stdio.h>
#include <stdlib.h>

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
int i;
int l;
int contador = 0;

typedef struct
{
	unsigned long codigoArtigo;
	char descricao[MAXNOME];
	float preco;
	unsigned int quantidadeStock;
	unsigned int quantidadeVendida;//quantidade numa compra

} Artigo;    


typedef struct
{
	char nome[MAXNOME];
	char cartaoCidadao[MAXCC];
	unsigned int telefone;
	unsigned long nif;
	char morada[MAXMORADA];
	char email[MAXNOME];

} Cliente; 

		   //Lista
typedef struct Artigos
{
	Artigo artigo;
	struct Artigos *proximo;

} tCelulaArtigos, *ListaArtigos;


typedef struct
{
	ListaArtigos conjuntoArtigo;

} Compra;

//Lista
typedef struct Compras
{
	Compra compra;
	struct Compras *proximo;

} tCelulaCompras, *ListaCompras;


typedef struct
{
	double totalValorGasto;
	ListaCompras compras;
	unsigned int pontos;
	Cliente cliente;
	unsigned int numeroEmissao;

} Cartao;

//Lista
typedef struct Cartoes
{
	Cartao cartao;
	struct Cartoes *proximo;

} tCelulaCartao, *ListaCartao;


typedef struct
{
	ListaCartao tabelaCartao[HASHSIZE];
	ListaArtigos tabelaArtigos[HASHSIZE];
	char localidade[MAXLOCALIZACAO];
}tCelulaSuperdume, *SuperDume;

SuperDume superMercadoLocal[CONJUNTOSUPERDUME];
char localSuperDume[MAXLOCALIZACAO];
int	indiceLocalSuperDume = 0;


#pragma region Metodos

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Menus

void DefinePt();

//Bem-vindo
void Apresentacao();

void EscolherSuperDume();

//Menu Principal
void Principal();

void SecundarioClientes();

void SecundarioArtigos();

void MenuCompra();

//antes de escolher um artigo
void SubMenuNumeroEmissão();

//antes de escolher um artigo ;

//depois de escolher um artigo
void SubMenuCompraQuantidade();

//escolher quantidade
void SubMenuCompraEscolherQuantidade();


void NaoExiste();

void Repetir();

void EsperarErro();

int SimNao();

int QuerContinuar(Artigo a);


#pragma endregion  

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Inicializa

int EncontraSuperDume(char*);

void InicializaTodosSuperDume();

void InicializaSuperDume();

void InicializaSuperDumeTodasListaArtigos();

void InicializaSuperDumeListaArtigos(unsigned int numeroArtigo);

void InicializaSuperDumeTodasListaCartao();

void InicializaSuperDumeListaCartao(unsigned int numeroCartao);

#pragma endregion

//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
#pragma region Hash

//retorna a posição para um array
int HashArtigo(int codigo);

//retorna a posição para um array
int HashCartao(int codigoEmissao);

#pragma endregion


//Falta coisas
//retorna objectos
#pragma region Procura

//Falta enviar a lista toda, tou a enviar apenas o que está depois
//envia a lista onde o cartao está inserido
ListaCartao ProcuraCartaoRetornaLista(unsigned int numeroEmissao);

//Falta enviar a lista toda, tou a enviar apenas o que está depois
//envia a lista onde o cartao está inserido
ListaArtigos ProcuraArtigoRetornaLista(unsigned int numeroArtigo);

//Feito
Cartao ProcuraCartaoRetornaCartao(unsigned int numeroEmissao);

//Feito
Artigo ProcuraArtigoRetornaArtigo(unsigned int codigoArtigo);

//Feito
//Contra : como tenho a hash a ordenar por numero e nao por nome de artigo, vou ter que verificar todas as listas
Artigo ProcuraArtigoRetornaArtigo(char nomeArtigo[]);

#pragma endregion


//Falta coisas e tem erros
//retorna o objecto criado
#pragma region Criar

//se o string copy no final tá a funcionar bem
//Feito verificar 
Cliente CriaCliente();

//Feito
Artigo CriaArtigo();

//Vericar com a prof
Compra CriaCompra();

#pragma endregion


//Alguns falta rever, há perguntas para a professora   , falta inserir compra ?
//insere na tabela de hash [posicao], não retorna nada
#pragma region Insere

//Feito
void InsereInicioArtigo(Artigo artigo);

//Feito
void InsereInicioCartao(Cartao cartao);

// ta bem ? é assim que funciona no a inserção no fim?
void InsereFimCartao(Cartao a);

// ta bem ? é assim que funciona no a inserção no fim?
void InsereFimArtigo(Artigo a);


//ta bem ?  inserção dependendo do numeroEmissao
//Falta rever
void InsereCartao(Cartao a);

//ta bem ?   inserção dependendo do codigoArtigo 
//Falta rever
int InsereArtigo(Artigo a);

//ta bem ?    dependendo nº cartao 	-Penso que está mal perguntar a prof
//Falta rever
void InsereCompra(unsigned int numeroEmissao, Compra c);

#pragma endregion


//Feito	-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//retorna numeros que queremos saber
#pragma region Saber

//Feito
int QuantoStock(unsigned int codigoArtigo);

//Feito
int QuantosPontos(unsigned int numeroEmissao);


//Feito
void QuantoGastei(unsigned int numeroEmissao);


#pragma endregion


//Falta verificar com a professora
//altera na hash [posição] e retorna a alteração
#pragma region Altera

//Falta verificar com a professora
void AlteraStock(unsigned int codigoArtigo, unsigned int quantidadeVendida, Artigo a);

//Falta verificar com a professora
void ReporStock();

#pragma endregion


//Falta saber se está correcto
//altera na hash [posição]
#pragma region Actualiza

//Feito
void ActualizarStockSemParametros();

//Feito
void ActualizarStock(unsigned int codigoArtigo, unsigned int quantidadeVendida);

#pragma endregion   


//Falta retornar o apagado, rever com a profressora muitos erros
//Elimina na hash [posição]	 
#pragma region Elimina

//Feito - Elimina o primeiro artigo de uma lista
void EliminaInicioArtigo(unsigned int codigoArtigo);

//Feito - Elimina o primeiro cartao de uma lista
void EliminaInicioCartao(unsigned int numeroEmissao);

//Falta verificar com a professora penso que tem erro
void EliminaUltimoCartao(unsigned int numeroEmissao);

//Falta verificar com a professora penso que tem erro
void EliminaUltimoArtigo(unsigned int codigoArtigo);



//Falta verificar com a professora
//Este metodo está a ser usado na compra logo recebe uma Lista
ListaArtigos EliminaArtigoNumaLista(ListaArtigos aux, char nomeArtigo[]);

//Feito---------------------------------------------------------------------------
void EliminaTodosCartao();

//Feito---------------------------------------------------------------------------
void EliminaTodosArtigo();


#pragma endregion


//Falta guardar na Hash
#pragma region Calcular


//Falta guardar na Hash
// tá bem?	
void CalcularPontos(unsigned int numeroEmissao);


//Falta guardar na Hash
// tá bem?	 
void CalcularTotalGasto(unsigned int numeroEmissao);

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


void ImprimeListaCartao(unsigned int numeroEmissao);


void ImprimeCarrinhoCompra(ListaArtigos a);

void ImprimeTodosSuperDumes();

#pragma endregion

//Não sei se vai funcionar
#pragma region Ficheiros

// Funcionara ?
void EscreveFicheiro(char nomeFich[]);

// Falta verificar com a professora
void EscreveFicheiroCartoes(char nomeFich[]);

void LeFicheiroArtigos(char nomeFich[]);

// Funcionara ?
void LeFicheiroCartoes(char nomeFich[]);

void DadosPredefinidos();


void GuardaDados();

#pragma endregion 

#pragma endregion