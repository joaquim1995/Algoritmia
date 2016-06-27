/*
o progama nas pergunta recebe apenas x valores, podem ser introduzidos mais mas ele só vai ler aqueles que foi configurado
O programa está limitado a 100 pessoas e 100 refeições
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>



int Contador=0;
int ContadorRefeicoes = 0;

//para refeiçoes
struct
{
	int numero;// numero de aluno
	int diaRefeicao;
	int mesRefeicao;
	int anoRefeicao;
	short int tipoRefeicaoJantar;//1 - Sim, 2 - Não
	short int tipoRefeicaoAlmoco;//1 - Sim, 2 - Não
	short consumida;///1 - Sim, 2 - Não
}refeicoes[100];

#pragma region Metodos

//Bemvindo
void Apresentacao()
{
	int espera;
	char username[21];
	DWORD username_len = 21;

	GetUserName(username, &username_len);

	username[20] = '\0';
	printf_s("Bem vindo, ");
	puts(username);
	printf_s("\n Espero que goste do trabalho . . .");
	espera = clock();//conta o tempo
	while (clock() - espera <= 3500);//enquanto não se passaram  5 segundos
	system("cls");

}

//Menu Principal
void Principal()
{	
	printf("\tData : %s Hora : %s", __DATE__, __TIME__);
	printf_s("\n\n");
	printf_s("[1] - Inserir alunos\n");
	printf_s("[2] - Procurar alunos por nome\n");
	printf_s("[3] - Procurar alunos por número\n");
	printf_s("[4] - Listar alunos\n");
	printf_s("[5] - Alterar alunos\n");
	printf_s("[6] - Remover alunos\n");
	printf_s("[7] - Refeições\n");
	printf_s("[8] - Carregar cartão\n");
	printf_s("[0] - Sair\n");
	
}

//Texto do confirma
void Confirma()
{
	printf_s("\nDeseja realizar a acção ?\n");
	printf_s("\n[1] - Sim\n");
	printf_s("[2] - Não\n");

}

//Perguntas ao inserir o aluno
void PerguntasAluno(int numero[], char nomeCompleto[][201], int ano[], int mes[], int dia[], char rua[][101], int porta[], int codigoP[], int codigoU[], int telefone[], char curso[][100], float plafond[])
{
	int erro = 0;
	int l;
	int quantosJaExistem = 0;
	int quantosExistem;
	int w;
	int temporaria;
	char temporariaChar[201];
	int temp=0;
	char temporaria_Char[201];
	int tempAno = 0;
	int tempMes = 0;
	int tempDia = 0;


	// Verifica quantos alunos já existem
	for (w = 0; w < 100; w++)
	{
		if (numero[w] > 0)
		{
			quantosJaExistem++;
		}
	}

	quantosExistem = quantosJaExistem + Contador;

	if (quantosExistem == 100) 
		printf_s("A base de dados está cheia. Impossivel adicionar alunos");

	else
	{
		do
		{
			erro = 0;

			printf_s("Insire o teu número : ");
			scanf_s("%d", &temp);
			fflush(stdin);

			if (temp <= 0 || temp > 99999)
			{
				printf("Erro numero inválido\n");
				erro = 1;
				continue;
			}

			//verifica se esse número já existe
			for (l = 0; l < 100; l++)
			{
				if ((temp == numero[l] && quantosExistem != l))
				{
					printf("Erro numero já atribuído\n");
					erro = 1;
					break;
				}				
			}
			if (erro == 0)
			{
				numero[quantosExistem] = temp;
			}

		} while (erro != 0);

		do
		{
			erro = 0;

			printf_s("\nInsire o teu nome completo : ");
			gets_s(temporaria_Char, 201);

			_strupr_s(temporaria_Char);

			for (l = 0; l < strlen(temporaria_Char); l++)
			{
				if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && (temporaria_Char[l] != ' '))
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
				strcpy_s(nomeCompleto[quantosExistem], temporaria_Char);
			}

			fflush(stdin);

		} while (erro != 0);

		do
		{
			erro = 0;

			printf_s("\nInsire a tua data de nascimento \'ano-mes-dia \' : ");
			scanf_s("%d-%d-%d", &tempAno, &tempMes, &tempDia);
			fflush(stdin);

			if (tempAno < 0)
			{
				printf("Erro ano impossivel\n");
				erro = 1;
				continue;
			}
			else if (tempAno < 1930 || tempAno > 1998)
			{
				printf("Idade para frequentar a escola incorrecta. Volte a inserir a idade!");
				erro = 1;
				continue;
			}

			else if (tempMes > 12 || tempMes < 1)
			{
				printf("Erro mês impossivel\n");
				erro = 1;
				continue;
			}

			else if (tempDia > 31 || tempDia < 1 || ((tempAno % 4 == 0) && tempMes == 2 && tempDia > 28))
			{
				printf("Erro dia impossivel\n");
				erro = 1;
				continue;
			}

			else if (tempMes == 4 && tempDia == 31 || tempMes == 9 && tempDia == 31 || tempMes == 31)
			{
				printf("Erro dia impossivel\n");
				erro = 1;
				continue;
			}

			if (erro==0)
			{
				ano[quantosExistem] = tempAno;
				mes[quantosExistem] = tempMes;
				dia[quantosExistem] = tempDia;
			}

		} while (erro != 0);

		do
		{
			erro = 0;
			strcpy_s(temporaria_Char, "");

			printf_s("\nInsire o nome da rua onde moras : ");
			gets_s(temporaria_Char, 101);
			_strupr_s(temporaria_Char);
			fflush(stdin);

			for (l = 0; l <= strlen(temporaria_Char); l++)
			{
				if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && temporaria_Char[l] != ' ' && temporaria_Char[l] != -121 && temporaria_Char[l] != '\0')
				{
					printf_s("\nIntroduza caracter\'s validos\n");
					erro = 1;
					break;
				}
			}

			if (erro ==0)
			{
				strcpy_s(rua[quantosExistem], temporaria_Char);
			}

		} while (erro != 0);

		do
		{
			erro = 0;
			temp = -1;

			printf_s("\nInsire o nº da porta : ");
			scanf_s("%d", &temp);
			fflush(stdin);

			if (temp < 0)
			{
				printf("Erro porta impossivel\n Se não tem porta digite '0'\n");
				erro = 1;
				continue;
			}

			if (erro == 0)
			{
				porta[quantosExistem] = temp;
			}

		} while (erro != 0);

		do
		{
			erro = 0;
			tempAno = 0;
			tempMes = 0;

			printf_s("\nInsire o teu código postal : ");
			scanf_s("%04d-%03d", &tempAno, &tempMes);
			fflush(stdin);


			if (tempAno > 9700 || tempAno < 1000)
			{
				printf("Código postal não conhecido\n");
				erro = 1;
				continue;
			}

			else if (tempMes > 999 || tempMes < 0)
			{
				printf("Código postal não conhecido\n");
				erro = 1;
				continue;
			}

			if (erro == 0)
			{
				codigoU[quantosExistem] = tempMes;
				codigoP[quantosExistem] = tempAno;
			}
			

		} while (erro != 0);

		do
		{
			erro = 0;
			temp=0;

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
				telefone[quantosExistem] = temp;
			}
			

		} while (erro != 0);

		do
		{
			erro = 0;
			strcpy_s(temporaria_Char, "");

			printf_s("\nInsire o nome do curso : ");
			gets_s(temporaria_Char, 100);
			_strupr_s(temporaria_Char);
			fflush(stdin);

			for (l = 0; l <= strlen(temporaria_Char); l++)
			{
				if (((temporaria_Char[l] < 'A') || (temporaria_Char[l] > 'Z')) && temporaria_Char[l] != ' ' && temporaria_Char[l] != -121 && temporaria_Char[l] != '\0' && temporaria_Char[l] !=45)
				{
					printf_s("\nIntroduza caracter\'s validos\n");
					erro = 1;
					break;
				}
			}

			if (erro == 0)
			{
				strcpy_s(curso[quantosExistem], temporaria_Char);
			}
			

		} while (erro != 0);

		do
		{
			erro = 0;


			plafond[quantosExistem] = 0;

			if (plafond[quantosExistem] < 0)
			{
				printf("Erro plafond impossivel\n");
				erro = 1;
				continue;
			}

		} while (erro != 0);

		//ordena os alunos por número
		for (l = 0; l < 100; l++)
		{
			for (w = 0; w < 100 - 1; w++)
			{
				if (numero[w] > numero[w + 1] && numero[w + 1] > 0)
				{
					temporaria = numero[w];
					numero[w] = numero[w + 1];
					numero[w + 1] = temporaria;

					strcpy_s(temporariaChar, strlen(nomeCompleto[w]) + 1, nomeCompleto[w]);
					strcpy_s(nomeCompleto[w], strlen(nomeCompleto[w]) + 1, nomeCompleto[w + 1]);
					strcpy_s(nomeCompleto[w + 1], strlen(nomeCompleto[w]) + 1, temporariaChar);

					temporaria = ano[w];
					ano[w] = ano[w + 1];
					ano[w + 1] = temporaria;

					temporaria = mes[w];
					mes[w] = mes[w + 1];
					mes[w + 1] = temporaria;

					temporaria = dia[w];
					dia[w] = dia[w + 1];
					dia[w + 1] = temporaria;

					strcpy_s(temporariaChar, strlen(nomeCompleto[w]) + 1, rua[w]);
					strcpy_s(rua[w], strlen(rua[w]) + 1, rua[w + 1]);
					strcpy_s(rua[w + 1], strlen(rua[w]) + 1, temporariaChar);

					temporaria = porta[w];
					porta[w] = porta[w + 1];
					porta[w + 1] = temporaria;

					strcpy_s(temporariaChar, strlen(curso[w]) + 1, curso[w]);
					strcpy_s(curso[w], strlen(curso[w]) + 1, curso[w + 1]);
					strcpy_s(curso[w + 1], strlen(curso[w]) + 1, temporariaChar);
				}
			}
		}
	}
}//SubMenu Inserir aluno

//texto inserir aluno
void InserirAluno()
{
	printf_s("\n[1] - Inserir outro aluno\n");	
	printf_s("[0] - Voltar\n");
}

//Menu procurar aluno por nome
void ProcurarAlunoNome()
{
	printf_s("Nome do aluno que quer procurar : \n");
}

//SubMenu procurar aluno por nome
void InserirNome()
{
	printf_s("\n[1] - Inserir outro nome\n");
	printf_s("[0] - Voltar\n");
}

//Menu procurar aluno por numero
void ProcurarAlunoNumero()
{
	printf_s("Número do aluno que quer procurar : \n");
}

//SubMenu procurar aluno por numero
void InserirNumero()
{
	printf_s("\n[1] - Inserir outro número\n");
	printf_s("[0] - Voltar\n");
}

//Alunos existentes
void AlunosExistentes()
{
	printf_s("Alunos que estão registados no sistema : \n");
}

//SubMenu alunos existentes
void InserirActualizacao()
{
	printf_s("\n[1] - Actualização\n");
	printf_s("[0] - Voltar\n");
}

//Remover alunos
void AlunosRemover()
{
	printf_s("Número do aluno que quer remover : \n");
}

//SubMenu remover alunos
void InserirRemover()
{
	printf_s("\nQue irá fazer ?\n");
	printf_s("\n[1] - Remover outro aluno\n");
	printf_s("[0] - Voltar\n");
}

//Alterar alunos
void AlteraAluno(int numero[], char nomeCompleto[][201], int ano[], int mes[], int dia[], char rua[][101], int porta[], int codigoP[], int codigoU[], int telefone[], char curso[][100], float plafond[])
{
	int numeroAluno;
	int i;
	int opcao;
	int contador = -1;
	int existe = 0;
	int temp;
	int tempData[3];
	int erro = 1;
	int temporaria;
	char valorDuzentos[200];
	char valor[100];
	int l;
	int tempo;

	do
	{
		system("cls");

		numeroAluno = 0;

		printf_s("Insira o Nº do aluno : ");
		scanf_s("%d", &numeroAluno);
		fflush(stdin);

		if (numeroAluno < 1 || numeroAluno> 99999)
			continue;
		
	} while (numeroAluno < 1 || numeroAluno> 99999);


		for (i = 0; i < 100; i++)
		{
			if (numeroAluno == numero[i])
			{						
				contador = i;
				break;
			}
		}

		if (contador > -1)
		{
			do
			{
				opcao = -1;

				for (i = 0; i < 100; i++)
				{
					if (numeroAluno == numero[i])
					{
						system("cls");
						printf_s("[1] - \t\t  Numero : %d\n", numero[i]);
						printf_s("[2] -      Nome Completo : %s\n", nomeCompleto[i]);
						printf_s("[3] - Data de Nascimento : %d-%d-%d\n", ano[i], mes[i], dia[i]);
						printf_s("[4] - \t  \t     Rua : %s\n", rua[i]);
						if (porta[i] == 0) printf_s("[5] - \t\t   Porta : Nenhuma\n");
						else printf_s("[5] - \t\t   Porta : %d\n", porta[i]);
						printf_s("[6] -      Código postal : %d-%d\n", codigoP[i], codigoU[i]);
						printf_s("[7] - \t\tTelefone : %d\n", telefone[i]);
						printf_s("[8] - \t\t   Curso : %s\n", curso[i]);
						printf_s("[0] - \t\t    Sair \n");
						contador = i;
						break;
					}
				}


				printf_s("\nOpção : ");
				scanf_s("%d", &opcao);
				fflush(stdin);
				printf_s("\n");

				switch (opcao)
				{
				case 1:
					do
					{
						erro = 0;
						existe = 0;
						temporaria = 0;

						printf("\n\nNumero atual : %d \n", numero[contador]);
						printf("Insira o Numero : ");
						scanf_s("%d", &temporaria);
						fflush(stdin);

						if (temporaria < 1 || temporaria > 99999)
						{
							printf("Erro numero inválido\n\n");
							break;
						}

						if (erro != 1)
						{
							// Verifica se esse numero já existe
							for (i = 0; i < 100; i++)
							{
								if (temporaria == numero[i] && i != contador)
								{
									existe++;
									printf_s("\nEsse numero pertence a outro aluno !");
									break;
								}
							}

							if (existe == 0)
							{
								numero[contador] = temporaria;
								printf_s("\n[Status] - Alterado\n\n");
								tempo = clock();//conta o tempo
								while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
							}
						}

					} while (existe != 0 && erro != 1);

					break;

				case 2:
					do
					{		
						erro = 0;
						strcpy_s(valorDuzentos, "");
						printf("Nome Completo atual : %s \n", nomeCompleto[contador]);
						printf("Insira o Nome Completo : ");
						gets_s(valorDuzentos);
						_strupr_s(valorDuzentos);
						fflush(stdin);

						for (l = 0; l <= strlen(valorDuzentos); l++)
						{
							if (((valorDuzentos[l] < 'A') || (valorDuzentos[l] > 'Z')) && valor[l] != ' ' && valorDuzentos[l] != -121 && valorDuzentos[l] != '\0')
							{
								printf_s("\nIntroduza caracter\'s validos\n");
								erro = 1;
								break;
							}
						}

						if (erro == 0)
						{
							strcpy_s(nomeCompleto[contador], valorDuzentos);
							printf_s("\n[Status] - Alterado\n\n");
							tempo = clock();//conta o tempo
							while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						}

					} while (erro!=0);

					break;

				case 3:
					do
					{
						erro = 0;
						tempData[0] = -1;
						tempData[1] = -1;
						tempData[2] = -1;

						printf("Data de Nascimento atual : %d-%d-%d\n", ano[contador], mes[contador], dia[contador]);
						printf("Insira a Data de Nascimento : ");
						scanf_s("%d-%d-%d", &tempData[0], &tempData[1], &tempData[2]);
						fflush(stdin);

						if (tempData[0]  < 1920 || tempData[0] > 1998)
						{
							printf("Erro ano impossivel\n\n");
							erro = 1;
							continue;
						}

						else if (tempData[1]  > 12 || tempData[1]  < 1)
						{
							printf("Erro mês impossivel\n\n");
							erro = 1;
							continue;
						}

						else if (tempData[2] > 31 || tempData[2] < 1 || ((tempData[0] % 2 == 0) && tempData[1] == 2 && tempData[2] == 2 && tempData[2] > 28))
						{
							printf("Erro dia impossivel\n\n");
							erro = 1;
							continue;
						}

						else if (tempData[1] == 4 && tempData[2] == 31 || tempData[1] == 9 && tempData[2] == 31 || tempData[1] == 31)
						{
							printf("Erro dia impossivel\n\n");
							erro = 1;
							continue;
						}

						else
						{
							ano[contador] = tempData[0];
							mes[contador] = tempData[1];
							dia[contador] = tempData[2];
							printf_s("\n[Status] - Alterado\n\n");
							tempo = clock();//conta o tempo
							while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	

						}
					} while (erro != 0);

					break;

				case 4:
					do
					{
						erro = 0;
						strcpy_s(valor,"0");

						printf("Rua atual : %s\n", rua[contador]);
						printf("Insira o Rua : ");
						gets_s(valor);
						_strupr_s(valor);
						fflush(stdin);



						for (l = 0; l <= strlen(valor); l++)
						{
							if (((valor[l] < 'A') || (valor[l] > 'Z')) && valor[l] != ' ' && valor[l] != -121 && valor[l] != '\0')
							{
								printf_s("\nIntroduza caracter\'s validos\n");
								erro = 1;
								break;
							}
						}

						if (erro == 0)
						{
							strcpy_s(rua[contador], valor);
							printf_s("\n[Status] - Alterado\n\n");
							tempo = clock();//conta o tempo
							while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						}

					} while (erro != 0);

					break;

				case 5:
					do
					{
						erro = 0;
						temporaria = -1;

						if (porta[i] == 0) printf_s("Porta atual : Nenhuma");
						else printf_s("Porta atual : %d\n", porta[contador]);
						printf("Insira o porta : ");
						scanf_s("%d", &temporaria);
						fflush(stdin);

						if (temporaria < 0 || temporaria > 99999)
						{
							printf("Erro porta impossivel\n Se não tem porta digite '0'\n\n");
							erro = 1;
							continue;
						}

						else
						{
							porta[contador] = temporaria;
							printf_s("\n[Status] - Alterado\n\n");
							tempo = clock();//conta o tempo
							while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						}

					} while (erro != 0);

					break;

				case 6:
					do
					{
						erro = 0;
						temp = 0;
						temporaria = 0;

						printf("Codigo Postal atual : %d-%d\n", codigoP[contador], codigoU[contador]);
						printf("Insira o Codigo Postal : ");
						scanf_s("%d-%d", &temp, &temporaria);
						fflush(stdin);

						if (temp > 9700 || temp < 1000)
						{
							printf("\n\nCódigo postal não conhecido\n");
							erro = 1;
							continue;
						}

						else if (temporaria > 999 || temporaria < 0)
						{
							printf("\n\nCódigo postal não conhecido\n");
							erro = 1;
							continue;
						}

						else
						{
							codigoP[contador] = temp;
							codigoU[contador] = temporaria;
							printf_s("\n[Status] - Alterado\n\n");
							tempo = clock();//conta o tempo
							while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						}

					} while (erro != 0);

					break;

				case 7:
					do
					{
						existe = 0;
						temp = telefone[contador];
						temporaria = 0;

						printf("Telefone atual : %d \n", telefone[contador]);
						printf("Insira o Telefone : ");
						scanf_s("%d", &temporaria);
						fflush(stdin);

						if (temporaria >= 297000000 || temporaria < 210000000)
						{
							printf("Erro numero de telefone inválido. Não confundir telemóvel com telefone\n\n");
							erro = 1;
						}

						if (erro != 1)
						{
							// Verifica se esse numero já existe
							for (i = 0; i < 100; i++)
							{
								if (temporaria == telefone[i])
								{
									existe++;
									printf_s("\nEsse telefone pertence a outro aluno !");
									telefone[contador] = temp;
									break;
								}
							}

							if (existe == 0)
							{	
								telefone[contador] = temporaria;							
								printf_s("\n[Status] - Alterado\n\n");
								tempo = clock();//conta o tempo
								while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
							}	
						}


					} while (existe != 0 && erro != 1);

					break;

				case 8:
					do
					{				
						erro = 0;
						strcpy_s(valor,"0");	

						printf("Curso atual : %s \n", curso[contador]);
						printf("Insira o Curso : ");
						gets_s(valor);
						_strupr_s(valor);
						fflush(stdin);

						for (l = 0; l <= strlen(valor); l++)
						{
							if (((valor[l] < 'A') || (valor[l] > 'Z')) && valor[l] != ' ' && valor[l] != -121 && valor[l] != '-' && valor[l] != '\0')
							{
								printf_s("\nIntroduza caracter\'s validos\n");
								erro = 1;
								break;
							}
						}

						if (erro == 0)
						{
							strcpy_s(curso[contador], valor);
							printf_s("\n[Status] - Alterado\n\n");
							tempo = clock();//conta o tempo
							while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						}


					} while (erro != 0);
					break;

				case 0:
					system("cls");
					break;

				default:
					printf("\nInsira uma opcao valida !\n");
					tempo = clock();//conta o tempo
					while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
					break;
				}

			} while ((opcao < 1 && opcao > 8 && existe != 0 )|| opcao != 0);

		}
		else
		{
			printf_s("\n\n Número não conhecido !");
			tempo = clock();//conta o tempo
			while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
		}
	
}

//SubMenu alterar alunos
void InserirAlterar()
{
	printf_s("\nQue irá fazer agora ? \n");
	printf_s("\n[1] - Alterar outro aluno\n");
	printf_s("[0] - Voltar\n");
}

//Carregar cartão
void CarregarCartao()
{
	printf_s("Número do aluno que quer carregar ou verificar o saldo : \n");
}

//SubMenu carregar cartão
void InserirCartao()
{
	printf_s("\nQue irá fazer ?\n");
	printf_s("\n[1] - Cartão de outro aluno\n");
	printf_s("[0] - Voltar\n");
}

//SubMenu carregar cartão
void CartaoAccao()
{
	printf_s("Que ação irá fazer : ");
	printf_s("\n[1] - Verificar o plafond\n");
	printf_s("[2] - Carregar cartão\n");
	printf_s("[0] - Voltar\n");
}

//SubMenu carregar cartão
void CartaoAccaoMais()
{
	printf_s("Que irá fazer : \n");
	printf_s("[2] - Carregar cartão\n");
	printf_s("[0] - Sair\n");
}

//SubMenu Refeições
void Refeicoes()
{
	printf_s("[1] - Encomendar refeições\n");
	printf_s("[2] - Consumir refeições\n");
	printf_s("[3] - Listar refeições\n");
	printf_s("[4] - Listar refeições num determinado dia\n");
	printf_s("[0] - Voltar\n");

}

//Organiza por numero
void Organiza(int numero[], char nomeCompleto[][201], int ano[], int mes[], int dia[], char rua[][101], int porta[], int codigoP[], int codigoU[], int telefone[], char curso[][100], float plafond[])
{
	int w, l, temporaria;
	char temporariaChar[201];
	//ordena os alunos por número
	for (l = 0; l < 100; l++)
	{
		for (w = 0; w < 100 - 1; w++)
		{
			if (numero[w] > numero[w + 1] && numero[w + 1] > 0)
			{
				temporaria = numero[w];
				numero[w] = numero[w + 1];
				numero[w + 1] = temporaria;

				strcpy_s(temporariaChar, strlen(nomeCompleto[w]) + 1, nomeCompleto[w]);
				strcpy_s(nomeCompleto[w], strlen(nomeCompleto[w]) + 1, nomeCompleto[w + 1]);
				strcpy_s(nomeCompleto[w + 1], strlen(nomeCompleto[w]) + 1, temporariaChar);

				temporaria = ano[w];
				ano[w] = ano[w + 1];
				ano[w + 1] = temporaria;

				temporaria = mes[w];
				mes[w] = mes[w + 1];
				mes[w + 1] = temporaria;

				temporaria = dia[w];
				dia[w] = dia[w + 1];
				dia[w + 1] = temporaria;

				strcpy_s(temporariaChar, strlen(nomeCompleto[w]) + 1, rua[w]);
				strcpy_s(rua[w], strlen(rua[w]) + 1, rua[w + 1]);
				strcpy_s(rua[w + 1], strlen(rua[w]) + 1, temporariaChar);

				temporaria = porta[w];
				porta[w] = porta[w + 1];
				porta[w + 1] = temporaria;

				strcpy_s(temporariaChar, strlen(curso[w]) + 1, curso[w]);
				strcpy_s(curso[w], strlen(curso[w]) + 1, curso[w + 1]);
				strcpy_s(curso[w + 1], strlen(curso[w]) + 1, temporariaChar);
			}
		}
	}
}

//regras para comprar a senha
int RegrasParaEncomendar(char timeChar[], int hora, int dia, char mes[], int ano, int mesInt, int erro, char dateChar[])
{
	int w = 0;
	erro = 0;

	//recebe a hora
	timeChar = __TIME__;

	// menos 48 pois a tabela ascii tem por exemplo o 0 na posição 48 ...
	hora = ((int)timeChar[0] - 48) * 10 + ((int)timeChar[1] - 48);

	//recebe o data
	dateChar = __DATE__;
	dia = ((int)dateChar[4] - 48) * 10 + ((int)dateChar[5] - 48);

	//recebe mes
	mes[0] = dateChar[0];
	mes[1] = dateChar[1];
	mes[2] = dateChar[2];
	mes[3] = '\0';

	if (mes = "Jan")
		mesInt = 1;
	else if (mes = "Fev")
		mesInt = 2;
	else if (mes = "Mar")
		mesInt = 3;
	else if (mes = "Abr")
		mesInt = 4;
	else if (mes = "Mai")
		mesInt = 5;
	else if (mes = "Jun")
		mesInt = 6;
	else if (mes = "Jul")
		mesInt = 7;
	else if (mes = "Ago")
		mesInt = 8;
	else if (mes = "Set")
		mesInt = 9;
	else if (mes = "Out")
		mesInt = 10;
	else if (mes = "Nov")
		mesInt = 11;
	else if (mes = "Dez")
		mesInt = 12;

	// recebe ano
	ano = (((int)dateChar[7]) - 48) * 1000 + (((int)dateChar[8]) - 48) * 100 + (((int)dateChar[9]) - 48) * 10 + (((int)dateChar[10]) - 48);
	

	if (ContadorRefeicoes == 99)
	{
		printf_s("\nA base de dados está cheia. Impossivel adicionar refeições");
		return erro = 1;
	}

	else
	{
		if (refeicoes[ContadorRefeicoes].diaRefeicao < dia && refeicoes[ContadorRefeicoes].mesRefeicao == mesInt && refeicoes[ContadorRefeicoes].anoRefeicao == ano)
		{
			printf_s("\nNão pode enconmentar refeições de dias que já passaram");
			return erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].mesRefeicao < mesInt && refeicoes[ContadorRefeicoes].anoRefeicao == ano)
		{
			printf_s("\nNão pode encomendar refeições de dias que já passaram");
			return erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].anoRefeicao < ano)
		{
			printf_s("\nNão pode encomendar refeições de dias que já passaram");
			return erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].mesRefeicao> 12 || refeicoes[ContadorRefeicoes].mesRefeicao < 1)
		{
			printf("\nErro mês impossivel");
			return erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].diaRefeicao > 31 || refeicoes[ContadorRefeicoes].diaRefeicao < 1 || ((refeicoes[ContadorRefeicoes].anoRefeicao % 4 == 0) && refeicoes[ContadorRefeicoes].mesRefeicao == 2 && refeicoes[ContadorRefeicoes].diaRefeicao > 28))
		{
			printf("\nErro dia impossivel");
			return erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].mesRefeicao == 4 && refeicoes[ContadorRefeicoes].diaRefeicao == 31 || refeicoes[ContadorRefeicoes].mesRefeicao == 9 && refeicoes[ContadorRefeicoes].diaRefeicao == 31 || refeicoes[ContadorRefeicoes].mesRefeicao == 11 && refeicoes[ContadorRefeicoes].diaRefeicao == 31)
		{
			printf("\nErro dia impossivel");
			return erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].anoRefeicao > ano && refeicoes[ContadorRefeicoes].mesRefeicao >= 7)
		{
			printf("\nErro não podes encomendar refeições para o proximo ano lectivo");
			return erro = 1;
		}

		else if (hora > 14 && dia == refeicoes[ContadorRefeicoes].diaRefeicao && refeicoes[ContadorRefeicoes].tipoRefeicaoAlmoco == 1)
		{
			printf("\nErro não podes encomendar refeições que ja passe a hora");
			return erro = 1;
		}

		else if (hora > 22 && dia == refeicoes[ContadorRefeicoes].diaRefeicao && refeicoes[ContadorRefeicoes].tipoRefeicaoJantar == 1)
		{
			printf("\nErro não podes encomendar refeições que ja passe a hora");
			return erro = 1;
		}

		
	}
	return erro = 0;
}

//regras para consumir a senha
int RegrasParaConsumir(char timeChar[], int hora, int dia, char mes[], int ano, int mesInt, int erro, char dateChar[],int anoI, int mesI,int diaI)
{
	int w = 0;
	erro = 0;

	//recebe a hora
	timeChar = __TIME__;

	// menos 48 pois a tabela ascii tem por exemplo o 0 na posição 48 ...
	hora = ((int)timeChar[0] - 48) * 10 + ((int)timeChar[1] - 48);

	//recebe o data
	dateChar = __DATE__;
	dia = ((int)dateChar[4] - 48) * 10 + ((int)dateChar[5] - 48);

	//recebe mes
	mes[0] = dateChar[0];
	mes[1] = dateChar[1];
	mes[2] = dateChar[2];
	mes[3] = '\0';

	if (mes = "Jan")
		mesInt = 1;
	else if (mes = "Fev")
		mesInt = 2;
	else if (mes = "Mar")
		mesInt = 3;
	else if (mes = "Abr")
		mesInt = 4;
	else if (mes = "Mai")
		mesInt = 5;
	else if (mes = "Jun")
		mesInt = 6;
	else if (mes = "Jul")
		mesInt = 7;
	else if (mes = "Ago")
		mesInt = 8;
	else if (mes = "Set")
		mesInt = 9;
	else if (mes = "Out")
		mesInt = 10;
	else if (mes = "Nov")
		mesInt = 11;
	else if (mes = "Dez")
		mesInt = 12;

	// recebe ano
	ano = (((int)dateChar[7]) - 48) * 1000 + (((int)dateChar[8]) - 48) * 100 + (((int)dateChar[9]) - 48) * 10 + (((int)dateChar[10]) - 48);
	
	
		if (diaI < dia && mesI == mesInt && anoI == ano)
		{
			printf_s("\nNão pode enconmentar refeições de dias que já passaram");
			return erro = 1;
		}

		else if (mesI < mesInt && anoI == ano)
		{
			printf_s("\nNão pode encomendar refeições de dias que já passaram");
			return erro = 1;
		}

		else if (anoI < ano)
		{
			printf_s("\nNão pode encomendar refeições de dias que já passaram");
			return erro = 1;
		}

		else if (mesI > 12 || mesI < 1)
		{
			printf("\nErro mês impossivel");
			return erro = 1;
		}

		else if (diaI > 31 || diaI < 1 || ((anoI % 4 == 0) && mesI == 2 && diaI > 28))
		{
			printf("\nErro dia impossivel");
			return erro = 1;
		}

		else if (mesI == 4 && diaI == 31 || mesI == 9 && dia == 31 || mesI == 11 && diaI == 31)
		{
			printf("\nErro dia impossivel");
			return erro = 1;
		}
	
	return erro = 0;
}

//Encomenda refeições
void EncomendaRefeicoes(int numero[], float plafond[], char timeChar[12], int hora, int dia, char mes[3], int ano, int mesInt, char nomeCompleto[][201], char dateChar[])
{
	int numeroAluno;
	int m;
	int contador=0;
	int opcao;
	int erro = 1;
	int tempo;
	int existe = 0;
	


	//recebe o numero
	do
	{
		system("cls");
		printf_s("Introduza o numero do aluno que deseja encomendar refeições : ");
		scanf_s("%d", &numeroAluno);
		fflush(stdin);


		if (numeroAluno < 1 || numeroAluno > 99999)
			continue;


		for (m = 0; m < 100; m++)
		{
			//tem um numero = ao introduzido
			if (numeroAluno == numero[m])
			{
				refeicoes[ContadorRefeicoes].numero = numero[m];
				erro = 0;
				break;
			}
		}

		//numero nao conhecido
		if (erro != 0)
		{
			
			printf_s("\n\nEsse número nao é conhecido pelo sistema\n\n");
		}
		tempo = clock();//conta o tempo
		while (clock() - tempo <= 1500);//enquanto não se passaram  5 segundos	
	} while (erro != 0);
	
	//comprar a refeição
	do
	{
		system("cls");
		erro = 0;

		printf_s("O\\A aluno\\a : %s \n", nomeCompleto[m]);
		printf_s("O\\A aluno\\a número : %5d Tem um plafound de %.2f \n\n", refeicoes[ContadorRefeicoes].numero, plafond[m]);
		
		printf_s("Introduza o dia em que quer encomendar a refeição \'ano-mes-dia\' : ");
		scanf_s("%d-%d-%d", &refeicoes[ContadorRefeicoes].anoRefeicao, &refeicoes[ContadorRefeicoes].mesRefeicao, &refeicoes[ContadorRefeicoes].diaRefeicao);
		fflush(stdin);

		if (refeicoes[ContadorRefeicoes].anoRefeicao <= 0)
		{
			printf_s("Ano inválido");
			erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].mesRefeicao <= 0)
		{
			printf_s("Mês inválido");
			erro = 1;
		}

		else if (refeicoes[ContadorRefeicoes].diaRefeicao <= 0)
		{
			printf_s("Dia inválido");
			erro = 1;
		}
		
		if (erro == 0)
		{
			//tempo introduzido
			erro = RegrasParaEncomendar(timeChar, hora, dia, mes, ano, mesInt, erro, dateChar);
			tempo = clock();//conta o tempo
			while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
		}
		
		if (erro == 1)
		{
			printf_s("\nData incorrecta\n\n");
			continue;
		}

		else
		{
			//tem dinheiro                                                                                               ou nao tem almoço  ou  nao tem jantar
			if (refeicoes[ContadorRefeicoes].numero == numero[m] && plafond[m] >= 3 && refeicoes[ContadorRefeicoes].tipoRefeicaoJantar != 1 || refeicoes[ContadorRefeicoes].tipoRefeicaoAlmoco != 1)
			{
				printf_s("[1] - Almoço\n");
				printf_s("[2] - Jantar\n\n");
				scanf_s("%d", &opcao);
				fflush(stdin);

				//almoço             e nao tem almoço
				if (opcao == 1 && refeicoes[ContadorRefeicoes].tipoRefeicaoAlmoco != 1)
				{
					for (m = 0; m < 100; m++)
					{
						if (refeicoes[m].tipoRefeicaoAlmoco == 1 && refeicoes[m].numero == refeicoes[ContadorRefeicoes].numero && refeicoes[m].diaRefeicao == refeicoes[ContadorRefeicoes].diaRefeicao && refeicoes[m].mesRefeicao == refeicoes[ContadorRefeicoes].mesRefeicao && refeicoes[m].anoRefeicao == refeicoes[ContadorRefeicoes].anoRefeicao )
						{
							existe = 1;
							break;
						}
					}

					if (existe == 0)
					{
						plafond[ContadorRefeicoes] = plafond[ContadorRefeicoes] - 3;
						erro = 0;
						refeicoes[ContadorRefeicoes].tipoRefeicaoAlmoco = 1;						
					}

					else
					{
						if (refeicoes[ContadorRefeicoes].consumida == 1)
						{
							printf_s("Desculpe já consumiu essa refeição !");
						}
						else
						{
							printf_s("Desculpe já encomendou essa refeição !");
						}
					}
				}

				//jantar             e nao tem jantar
				else if (opcao == 2 && refeicoes[ContadorRefeicoes].tipoRefeicaoJantar != 1)
				{
					for (m = 0; m < 100; m++)
					{
						if (refeicoes[m].tipoRefeicaoJantar == 1 && refeicoes[m].numero == refeicoes[ContadorRefeicoes].numero && refeicoes[m].diaRefeicao == refeicoes[ContadorRefeicoes].diaRefeicao && refeicoes[m].mesRefeicao == refeicoes[ContadorRefeicoes].mesRefeicao && refeicoes[m].anoRefeicao == refeicoes[ContadorRefeicoes].anoRefeicao)
						{
							existe = 1;
							break;
						}
					}

					if (existe == 0)
					{
						plafond[ContadorRefeicoes] = plafond[ContadorRefeicoes] - 3;
						erro = 0;
						refeicoes[ContadorRefeicoes].tipoRefeicaoJantar = 1;
					}

					else
					{
						if (refeicoes[ContadorRefeicoes].consumida == 1)
						{
							printf_s("Desculpe já consumiu essa refeição !");
						}
						else
						{
							printf_s("Desculpe já encomendou essa refeição !");								
						}						
					}
				}

				//nao conhecida
				else if (opcao != 2 || opcao != 1)
				{
					printf_s("\nOpção não conhecida");
					erro = 1;
				}

				//ja tem a refeiçao para aquele dia e para o jantar ou almoço
				else
				{
					printf_s("\nNão foi descontado o valor dessa refeição pois já tinha essa refeição reservada.");
					erro = 1;
				}
			}

			//nao tem dinheiro
			else
			{
				printf_s("Não é possivel encomendar nenhuma refeição pois não tem dinheiro\n");
				printf_s("Para encomendar uma refeição tem que carregar o cartão com : %.2f", 3 - plafond[m]);
				erro = 1;
			}
				
		}		
		tempo = clock();//conta o tempo
		while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
	} while (erro != 0);
	
	ContadorRefeicoes++;
}

//SubMenu encomendar refeiçao
void EncomendarAccao()
{
	printf_s("\n\nQue ação irá realizar : ");
	printf_s("\n[1] - Voltar a encomendar refeição\n");
	printf_s("[0] - Voltar\n");
}

//Consume refeições
void ConsomeRefeicoes(char timeChar[], int hora, int dia, char mes[], int ano, int mesInt, char dateChar[])
{
	int existe = 0;
	int i;
	int numeroAluno;
	int diaI, mesI, anoI; // introduzido pelo utilizador
	int erro=0;
	int tempo;
	int opcao;
	
	do
	{
		system("cls");
		printf_s("Introduza o numero do aluno que deseja verificar refeições : ");
		scanf_s("%d", &numeroAluno);
		fflush(stdin);

		for (i = 0; i < 100; i++)
		{
			if (numeroAluno == refeicoes[i].numero)
			{
				existe = 1;
				break;
			}
		}
		
		if (numeroAluno < 1 || numeroAluno > 99999)
		{
			printf_s("\n Esse numero não é conhecido!\n");
			erro = 1;
		}

		else if (existe == 0)
		{
			printf_s("\n\nEsse aluno não tem nenhuma refeição ");
			erro = 1;
		}
		
		if (erro == 0)
		{
			printf_s("\n\nIntroduza a data da refeição : ");
			scanf_s("%d-%d-%d", &anoI, &mesI, &diaI);
			fflush(stdin);

			if (anoI <= 0)
			{
				printf_s("\n\nAno inválido");
				erro = 1;
			}

			else if (mesI <= 0)
			{
				printf_s("\n\nMês inválido");
				erro = 1;
			}

			else if (diaI <= 0)
			{
				printf_s("\n\nDia inválido");
				erro = 1;
			}

			if (erro == 0)
			{
				//tempo introduzido
				erro = RegrasParaConsumir(timeChar, hora, dia, mes, ano, mesInt, erro, dateChar, anoI, mesI, diaI);
			}

			if (erro == 1)
			{
				tempo = clock();//conta o tempo
				while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos
				continue;
			}

			else
			{
				printf_s("\n\n[1] - Almoço\n[2] - Jantar \n");
				scanf_s("%d", &opcao);
				fflush(stdin);

				if (opcao==1)
				{
					if (refeicoes[i].tipoRefeicaoAlmoco == 1)
					{
						printf_s("\n\nRefeição consumida");
						refeicoes[i].consumida = 1;
						tempo = clock();//conta o tempo
						while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						continue;
					}
					else
					{
						printf_s("\n\nNão pode consumir esta refeição porque nao a pagou");
						tempo = clock();//conta o tempo
						while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						continue;
					}
				}

				else if (opcao == 2)
				{
					if (refeicoes[i].tipoRefeicaoJantar == 1)
					{
						printf_s("\n\nRefeição consumida");
						refeicoes[i].consumida = 1;
						tempo = clock();//conta o tempo
						while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						continue;
					}
					else
					{
						printf_s("\n\nNão pode consumir esta refeição porque nao a pagou");
						tempo = clock();//conta o tempo
						while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
						continue;
					}
				}

				else
				{
					erro = 1;
					printf_s("Opção não conhecida");
				}

			}
		}


		tempo = clock();//conta o tempo
		while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
	} while (erro != 0);
	
}

//SubMenu consumir refeiçao
void ConsumirAccao()
{
	printf_s("\n\nQue ação irá realizar : ");
	printf_s("\n[1] - Voltar a consumir uma refeição\n");
	printf_s("[0] - Voltar\n");
}

//Consume refeições
void ListaRefeicoes(int numero[], char nomeCompleto [][201])
{
	int existe = 0;
	int i,w=0,k;
	int numeroAluno;	
	int erro = 0;
	int tempo;
	int opcao;
	int posicaoRefeicoes[100];

	do
	{
		existe = 0;
		i=0, w = 0;
		erro = 0;

		system("cls");
		printf_s("Introduza o numero do aluno que deseja verificar o registo de refeições : ");
		scanf_s("%d", &numeroAluno);
		fflush(stdin);
		if (numeroAluno < 1 || numeroAluno > 99999 && numeroAluno != 0)
		{
			erro = 1;
			continue;
		}
		if (numeroAluno == 0)
			continue;

		if (numeroAluno > 99999)
		{
			erro = 1;
			printf_s("Desculpe esse é um número que passa dos limites da base de dados");
			tempo = clock();//conta o tempo
			while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
			continue;
		}

		for (i = 0; i < 100; i++)
		{
			if (numeroAluno == refeicoes[i].numero)
			{
				posicaoRefeicoes[w] = i;
				w++;
			}
		}
		
		
		if (w == 0 && numeroAluno != 0)
		{
			printf_s("\n\nEsse aluno não tem nenhuma refeição ");
			erro = 1;
			tempo = clock();//conta o tempo
			while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
			continue;
		}

	} while (erro != 0);
		
	do
	{
		erro = 0;

		printf_s("Quer que se mostre a lista detalhada, com nome, número, data, consumida ou não e tipo de refeição?");
		printf_s("\n[1] - Sim\n");
		printf_s("\n[0] - Não\n");
		scanf_s("%d", &opcao);
		fflush(stdin);
		system("cls");

		if (opcao == 0)
		{
			if (numeroAluno == 0)
			{
				for (i = 0; i < 100; i++)
				{
					if (refeicoes[i].numero > 0)
					{
						w++;
					}

					if (refeicoes[i].consumida > 0)
					{
						existe++;
					}
				}
				printf_s("\n\nNúmero total de registos : %d\nNúmero total de consumidas : %d", w, existe);
			}

			else
			{
				for (i = 0; i < 100; i++)
				{
					if (refeicoes[i].numero == numeroAluno && refeicoes[i].consumida > 0)
					{
						existe++;
					}
				}
				printf_s("\n\n O aluno %d tem encomendadas %d refeições, e tem %d consumidas", numeroAluno, w, existe);
			}

		}

		else if (opcao == 1)
		{
			if (numeroAluno == 0)
			{
				for (i = 0; i < 100; i++)
				{
					for ( k = 0; k < 100; k++)
					{
						if (refeicoes[i].numero == numero[k])
						{
							break;
						}
					}

					if (refeicoes[i].numero > 0)
					{
						printf_s("\nNúmero : %d\nJantar : %d    Almoco : %d\n Data :%d-%d-%d\nConsumida : %d\nNome : %s\n", refeicoes[i].numero, refeicoes[i].tipoRefeicaoJantar, refeicoes[i].tipoRefeicaoAlmoco, refeicoes[i].anoRefeicao, refeicoes[i].mesRefeicao, refeicoes[i].diaRefeicao, refeicoes[i].consumida, nomeCompleto[k]);
						w++;
					}

					if (refeicoes[i].consumida > 0)
					{
						existe++;
					}
				}
				printf_s("\n\nNúmero total de registos : %d\nNúmero total de consumidas : %d", w, existe);
			}

			else
			{
				for (i = 0; i < 100; i++)
				{
					if (refeicoes[i].numero == numeroAluno && refeicoes[i].consumida > 0)
					{
						existe++;
						printf_s("\nNúmero : %d\nJantar : %d    Almoco : %d\n Data :%d-%d-%d\nConsumida : %d\nNome : %s\n ", refeicoes[i].numero, refeicoes[i].tipoRefeicaoJantar, refeicoes[i].tipoRefeicaoAlmoco, refeicoes[i].anoRefeicao, refeicoes[i].mesRefeicao, refeicoes[i].diaRefeicao, refeicoes[i].consumida, nomeCompleto[k]);
					}
					
				}
				printf_s("\n\n O aluno %d tem encomendadas %d refeições, e tem %d consumidas", numeroAluno, w, existe);
			}

		}

		else
		{
			erro = 1;
			printf_s("\n Valor não conhecido");
		}

		tempo = clock();//conta o tempo
		while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	

	} while (erro != 0);
}

//SubMenu listar refeiçao
void ListarAccao()
{
	printf_s("\n\nQue ação irá realizar : ");
	printf_s("\n[1] - Voltar a pesquisar por outro número\n");
	printf_s("[0] - Voltar\n");
}

//Lista data refeições
void ListaDataRefeicoes()
{
	int ano = 0, mes = 0, dia = 0;
	int existe = 0;
	int i = 0, w = 0, k = 0;
	int numeroAluno = 0;
	int erro = 0;
	int tempo = 0;
	int opcao = 0;

	do
	{
		existe = 0;
		i = 0, w = 0;
		erro = 0;

		system("cls");
		printf_s("Introduza uma data para verificar o registo de refeições : ");
		scanf_s("%d-%d-%d", &ano, &mes, &dia);
		fflush(stdin);


		if (ano <= 0)
		{
			printf_s("\n\nAno inválido");
			erro = 1;
		}

		else if (mes <= 0)
		{
			printf_s("\n\nMês inválido");
			erro = 1;
		}

		else if (dia <= 0)
		{
			printf_s("\n\nDia inválido");
			erro = 1;
		}


		if (erro == 0)
		{
			for (i = 0; i < 100; i++)
			{
				if (dia == refeicoes[i].diaRefeicao && mes == refeicoes[i].mesRefeicao && ano == refeicoes[i].anoRefeicao && refeicoes[i].consumida == 0)
				{
					existe = 1;
					printf_s("\n\nData : %d-%d-%d\tNúmero : %d\nJantar : %d    Almoco : %d\n\n", refeicoes[i].diaRefeicao, refeicoes[i].mesRefeicao, refeicoes[i].anoRefeicao, refeicoes[i].numero, refeicoes[i].tipoRefeicaoJantar, refeicoes[i].tipoRefeicaoAlmoco);
				}
			}
			if (existe == 0)
			{
				printf_s("Esta data não tem nada marcado!");

			}
		}
		

		tempo = clock();//conta o tempo
		while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
		continue;
		

	} while (erro != 0);
				
}

//SubMenu listar refeiçao por data
void ListarDataAccao()
{
	printf_s("\n\nQue ação irá realizar : ");
	printf_s("\n[1] - Voltar a pesquisar por outra data\n");
	printf_s("[0] - Voltar\n");
}

#pragma endregion

void main()
{

#pragma region Variaveis

	//Vars

	FILE *baseDados;	

	//variaveis para as horas
	char timeChar[12] = __TIME__;
	int time=0;
	int date = 0;
	int hora=0, diaA=0, mesS=0, anoO=0;
	char mesChar[4];
	char dateChar[13];

	//datas
	char *mesDiaAno;
	char dadosData[19];
	dadosData[18] = '\0';
	char temp[12];
	temp[11] = '\0';

	//uso geral
	int tempo;
	int escolha = 1;
	int subEscolha = 1;
	int cont = 0;
	int i = 0; // ciclos for
	int w=0; // ciclos for
	int l = 0; // ciclos for
	int k = 0; // ciclos for
	int temporaria = 0; // ciclos for
	char temporariaChar[201] = ""; // ciclos for
	int opcaoDados;
	int confirma;
	int erro;

	// Inserir Aluno

	int numero[100];
	char nomeCompleto[100][201];
	int ano[100], mes[100], dia[100];
	char rua[100][101];
	int porta[100];
	int codigoP[100], codigoU[100];
	int telefone[100];
	char curso[100][100];
	float plafond[100];	
	
    
	int repetirAluno;
	int contador = 0;

	// Listar aluno
	int verificaAluno;

	// Procurar Aluno por nome
	char nome[51];
	char recebeNome[51];
	int resultados = 0;

	// Procurar Aluno por nome
	int numeroProcurado;

	// Remover aluno
	int numeroRemover;
	int tmp = 200;

	// Carregar cartão
	int numeroCarregar;
	float carregar;

#pragma endregion

	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	fflush(stdin);//limpar a memória temporária	

	Apresentacao();

	#pragma region Perguntar se quer dados
	do
	{
		printf_s("Para facilitar a verificação ao utilizador que o programa\nrealmente funciona perguntamos a voçê utilizador se deseja\nter dados para poder fazer a consulta sem ter que introduzir\nexaustivamente dados. \n\nDeseja ter alguns dados na aplicação ? ");
		printf_s("\n[1] - Sim");
		printf_s("\n[2] - Não\n");
		scanf_s("%d", &opcaoDados);
		fflush(stdin);

		if (opcaoDados == 1)
		{
#pragma region Dados Predefinidos

			//dados predefinidos
			numero[0] = 1;
			nomeCompleto[0][0] = 'A';
			nomeCompleto[0][1] = 'N';
			nomeCompleto[0][2] = 'A';
			nomeCompleto[0][3] = ' ';
			nomeCompleto[0][4] = 'C';
			nomeCompleto[0][5] = 'O';
			nomeCompleto[0][6] = '\0';
			ano[0] = 2000;
			mes[0] = 10;
			dia[0] = 2;
			rua[0][0] = 'A';
			rua[0][1] = '\0';
			porta[0] = 10;
			codigoP[0] = 4123;
			codigoU[0] = 231;
			telefone[0] = 213123423;
			curso[0][0] = 'L';
			curso[0][1] = 'E';
			curso[0][2] = 'S';
			curso[0][3] = 'I';
			curso[0][4] = '\0';
			plafond[0] = 10.0;

			numero[1] = 2;
			nomeCompleto[1][0] = 'Q';
			nomeCompleto[1][1] = 'U';
			nomeCompleto[1][2] = 'I';
			nomeCompleto[1][3] = 'M';
			nomeCompleto[1][4] = ' ';
			nomeCompleto[1][5] = 'C';
			nomeCompleto[1][6] = '\0';
			ano[1] = 1995;
			mes[1] = 10;
			dia[1] = 2;
			rua[1][0] = 'B';
			rua[1][1] = '\0';
			porta[1] = 20;
			codigoP[1] = 4123;
			codigoU[1] = 231;
			telefone[1] = 213123423;
			curso[1][0] = 'L';
			curso[1][1] = 'E';
			curso[1][2] = 'S';
			curso[1][3] = 'I';
			curso[1][4] = '\0';
			plafond[1] = 10.0;

			numero[2] = 3;
			nomeCompleto[2][0] = 'F';
			nomeCompleto[2][1] = 'E';
			nomeCompleto[2][2] = 'R';
			nomeCompleto[2][3] = 'N';
			nomeCompleto[2][4] = 'A';
			nomeCompleto[2][5] = 'O';
			nomeCompleto[2][6] = '\0';
			ano[2] = 2000;
			mes[2] = 10;
			dia[2] = 2;
			rua[2][0] = 'A';
			rua[2][1] = '\0';
			porta[2] = 10;
			codigoP[2] = 4123;
			codigoU[2] = 231;
			telefone[2] = 213123423;
			curso[2][0] = 'L';
			curso[2][1] = 'E';
			curso[2][2] = 'S';
			curso[2][3] = 'I';
			curso[2][4] = '\0';
			plafond[2] = 10.0;

			numero[3] = 4;
			nomeCompleto[3][0] = 'A';
			nomeCompleto[3][1] = 'N';
			nomeCompleto[3][2] = 'A';
			nomeCompleto[3][3] = ' ';
			nomeCompleto[3][4] = 'C';
			nomeCompleto[3][5] = 'O';
			nomeCompleto[3][6] = '\0';
			ano[3] = 2000;
			mes[3] = 10;
			dia[3] = 2;
			rua[3][0] = 'A';
			rua[3][1] = '\0';
			porta[3] = 10;
			codigoP[3] = 4123;
			codigoU[3] = 231;
			telefone[3] = 213123423;
			curso[3][0] = 'L';
			curso[3][1] = 'E';
			curso[3][2] = 'S';
			curso[3][3] = 'I';
			curso[3][4] = '\0';
			plafond[3] = 10.0;

			numero[4] = 5;
			nomeCompleto[4][0] = 'A';
			nomeCompleto[4][1] = 'N';
			nomeCompleto[4][2] = 'A';
			nomeCompleto[4][3] = ' ';
			nomeCompleto[4][4] = 'C';
			nomeCompleto[4][5] = 'O';
			nomeCompleto[4][6] = '\0';
			ano[4] = 2000;
			mes[4] = 10;
			dia[4] = 2;
			rua[4][0] = 'A';
			rua[4][1] = '\0';
			porta[4] = 10;
			codigoP[4] = 4123;
			codigoU[4] = 231;
			telefone[4] = 213123423;
			curso[4][0] = 'L';
			curso[4][1] = 'E';
			curso[4][2] = 'S';
			curso[4][3] = 'I';
			curso[4][4] = '\0';
			plafond[4] = 10.0;

			numero[5] = 6;
			nomeCompleto[5][0] = 'A';
			nomeCompleto[5][1] = 'N';
			nomeCompleto[5][2] = 'A';
			nomeCompleto[5][3] = ' ';
			nomeCompleto[5][4] = 'C';
			nomeCompleto[5][5] = 'O';
			nomeCompleto[5][6] = '\0';
			ano[5] = 2000;
			mes[5] = 10;
			dia[5] = 2;
			rua[5][0] = 'A';
			rua[5][1] = '\0';
			porta[5] = 10;
			codigoP[5] = 4123;
			codigoU[5] = 231;
			telefone[5] = 213123423;
			curso[5][0] = 'L';
			curso[5][1] = 'E';
			curso[5][2] = 'S';
			curso[5][3] = 'I';
			curso[5][4] = '\0';
			plafond[5] = 10.0;

			numero[6] = 7;
			nomeCompleto[6][0] = 'A';
			nomeCompleto[6][1] = 'N';
			nomeCompleto[6][2] = 'A';
			nomeCompleto[6][3] = ' ';
			nomeCompleto[6][4] = 'C';
			nomeCompleto[6][5] = 'O';
			nomeCompleto[6][6] = '\0';
			ano[6] = 2000;
			mes[6] = 10;
			dia[6] = 2;
			rua[6][0] = 'A';
			rua[6][1] = '\0';
			porta[6] = 10;
			codigoP[6] = 4123;
			codigoU[6] = 231;
			telefone[6] = 213123423;
			curso[6][0] = 'L';
			curso[6][1] = 'E';
			curso[6][2] = 'S';
			curso[6][3] = 'I';
			curso[6][4] = '\0';
			plafond[6] = 10.0;

			numero[7] = 8;
			nomeCompleto[7][0] = 'A';
			nomeCompleto[7][1] = 'N';
			nomeCompleto[7][2] = 'A';
			nomeCompleto[7][3] = ' ';
			nomeCompleto[7][4] = 'C';
			nomeCompleto[7][5] = 'O';
			nomeCompleto[7][6] = '\0';
			ano[7] = 2000;
			mes[7] = 10;
			dia[7] = 2;
			rua[7][0] = 'A';
			rua[7][1] = '\0';
			porta[7] = 10;
			codigoP[7] = 4123;
			codigoU[7] = 231;
			telefone[7] = 213123423;
			curso[7][0] = 'L';
			curso[7][1] = 'E';
			curso[7][2] = 'S';
			curso[7][3] = 'I';
			curso[7][4] = '\0';
			plafond[7] = 10.0;

			numero[8] = 9;
			nomeCompleto[8][0] = 'A';
			nomeCompleto[8][1] = 'N';
			nomeCompleto[8][2] = 'A';
			nomeCompleto[8][3] = ' ';
			nomeCompleto[8][4] = 'C';
			nomeCompleto[8][5] = 'O';
			nomeCompleto[8][6] = '\0';
			ano[8] = 2000;
			mes[8] = 10;
			dia[8] = 2;
			rua[8][0] = 'A';
			rua[8][1] = '\0';
			porta[8] = 10;
			codigoP[8] = 4123;
			codigoU[8] = 231;
			telefone[8] = 213123423;
			curso[8][0] = 'L';
			curso[8][1] = 'E';
			curso[8][2] = 'S';
			curso[8][3] = 'I';
			curso[8][4] = '\0';
			plafond[8] = 10.0;

			numero[9] = 10;
			nomeCompleto[9][0] = 'A';
			nomeCompleto[9][1] = 'N';
			nomeCompleto[9][2] = 'A';
			nomeCompleto[9][3] = ' ';
			nomeCompleto[9][4] = 'C';
			nomeCompleto[9][5] = 'O';
			nomeCompleto[9][6] = '\0';
			ano[9] = 2000;
			mes[9] = 10;
			dia[9] = 2;
			rua[9][0] = 'A';
			rua[9][1] = '\0';
			porta[9] = 10;
			codigoP[9] = 4123;
			codigoU[9] = 231;
			telefone[9] = 213123423;
			curso[9][0] = 'L';
			curso[9][1] = 'E';
			curso[9][2] = 'S';
			curso[9][3] = 'I';
			curso[9][4] = '\0';
			plafond[9] = 10.0;

			numero[99] = 100;
			nomeCompleto[99][0] = 'C';
			nomeCompleto[99][1] = 'E';
			nomeCompleto[99][2] = 'P';
			nomeCompleto[99][3] = 'A';
			nomeCompleto[99][4] = ' ';
			nomeCompleto[99][5] = 'A';
			nomeCompleto[99][6] = '\0';
			ano[99] = 1995;
			mes[99] = 10;
			dia[99] = 2;
			rua[99][0] = 'A';
			rua[99][1] = '\0';
			porta[99] = 10;
			codigoP[99] = 4123;
			codigoU[99] = 231;
			telefone[99] = 213123423;
			curso[99][0] = 'L';
			curso[99][1] = 'E';
			curso[99][2] = 'S';
			curso[99][3] = 'I';
			curso[99][4] = '\0';
			plafond[99] = 10.0;


			
#pragma endregion
			break;
		}

		else if (opcaoDados == 2) break;

		system("cls");
	} while (opcaoDados != 1 || opcaoDados != 2 );

#pragma endregion
	
	//Menu
	do
	{		
		escolha = -1;
		mesDiaAno = __DATE__; // dar o tempo ao apontador 

		system("cls");

		Principal();
		scanf_s("%d", &escolha);
		fflush(stdin);//limpar a memória temporária
				
		switch (escolha)
		{
					//Atribuir aluno - Done!
			#pragma region Caso_1
					case 1:

						do
						{
							system("cls");

							erro = 0;
							repetirAluno = -1;

							//perguntas
							PerguntasAluno(numero, nomeCompleto, ano, mes, dia, rua, porta, codigoP, codigoU, telefone, curso, plafond);
							Contador++;
			    
							do
							{
								InserirAluno();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);
				

						} while (repetirAluno == 1);

						system("cls");
						break;

			#pragma endregion 

					//Pesquisa por nome - Done! Verificado!
			#pragma region Caso_2
					case 2:
						
						do
						{
							system("cls");
							resultados = 0;
							strcpy_s(nome, "");

							//perguntas
							ProcurarAlunoNome();
							gets_s(nome, 51);
							_strupr_s(nome);
							fflush(stdin);

							for (i = 0; i < 100; i++)
							{
								for (k = 0; k < 51; k++)
								{
									if ((nomeCompleto[i][k]) != ' ')
									{
										recebeNome[k] = nomeCompleto[i][k];
									}
						
									else if ((nomeCompleto[i][k]) == ' ')
									{
										recebeNome[k] = '\0';
										break;
									}						
								}

								for (int j = 0; j < 51; j++)
								{
									if (nome[j] == recebeNome[j] && nome[j] == '\0')
									{
										printf_s("\nNumero : %05d\t Nome : %s\n", numero[i], nomeCompleto[i]);
										resultados++;
									}

									else if (nome[j] != recebeNome[j])
									{
										break;
									}

									else 
									{
										continue;
									}
								}					
							}
				
							if (resultados == 0)
							{
								printf_s("\nNão existem alunos com esse nome.\n");
							}

							printf_s("\n\n\nResultados aparecidos : %d\n", resultados);

							do
							{
								repetirAluno = -1;
								InserirNome();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);


						} while (repetirAluno == 1);

						system("cls");
						break;
			#pragma endregion 

					//Pesquisa por numero - Done! Verificado!
			#pragma region Caso_3
					case 3:
						do
						{							
							system("cls");
							resultados = 0;
							numeroProcurado = -1;

							//perguntas
							ProcurarAlunoNumero();
							scanf_s("%d", &numeroProcurado);
							fflush(stdin);

							if (numeroProcurado < 1 || numeroProcurado > 99999)
								continue;

							for (i = 0; i < 100; i++)
							{
								if (numeroProcurado==numero[i])
								{
									printf_s("\nNome : ");
									puts(nomeCompleto[i]);
									printf_s("Numero : %05d\tData de Nascimento : %04d-%02d-%02d\nMorada : Rua %s, porta nº %d\nCurso : %s\n\n", numero[i], ano[i], mes[i], dia[i], rua[i], porta[i], curso[i]);
									resultados++;
								}

								else continue;
				
							}

							if (resultados == 0)
							{
								printf_s("\nNão existem alunos com esse número.\n");
							}

							printf_s("\n\n\nResultados aparecidos : %d\n", resultados);

							do
							{
								InserirNumero();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);


						} while (numeroProcurado < 1 || numeroProcurado > 99999);

						system("cls");
						break;

			#pragma endregion 

					//Mostrar alunos - Done! Verificado!
			#pragma region Caso_4
					case 4:
						do
						{
							system("cls");

							resultados = 0;
							verificaAluno = 0;

							//organiza
							Organiza(numero, nomeCompleto, ano, mes, dia, rua, porta, codigoP, codigoU, telefone, curso, plafond);

							//perguntas
							AlunosExistentes();
							
							//numero de alunos que o sistema suporta : 100
							for (i = 0; i < 100; i++)
							{
								//numero predefinido quando não existe qualquer valor  é negativo
								if (numero[i] < 0 && verificaAluno == 0)
								{
									for (k = i; k < 100; k++)
									{
										//verifica se existe mais algum numero
										verificaAluno++;
									}
								}

								//se existir mais algum aluno entao quando o numero for positivo
								else if ((verificaAluno > 0 && numero[i] > 0) || numero[i] > 0)
								{
									printf_s("\nNumero : %05d\t Nome : %s\n", numero[i], nomeCompleto[i]);
									resultados++;
								}					
							}

							printf_s("\n\n\nResultados aparecidos : %d\n", resultados);

							do
							{
								InserirActualizacao();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);


						} while (repetirAluno == 1);

			
						system("cls");
						break;

			#pragma endregion 

					//Alterar aluno - Done! Verificado!
			#pragma region Caso_5
					case 5:
						do
						{
							system("cls");

							AlteraAluno(numero, nomeCompleto, ano, mes, dia, rua, porta, codigoP, codigoU, telefone, curso, plafond);
							
							do
							{
								InserirAlterar();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);


						} while (repetirAluno == 1);
						break;

			#pragma endregion 

					//Remover aluno - Done! Verificado!
			#pragma region Caso_6
					case 6:

						do
						{
							do
							{
								system("cls");
								resultados = 0;

								//perguntas
								AlunosRemover();
								scanf_s("%d", &numeroRemover);
								fflush(stdin);

								if (numeroRemover < 1 || numeroRemover > 99999)
									continue;
								//numero de alunos que o sistema suporta : 100
								for (i = 0; i < 100; i++)
								{
									//se numero na posição x = ao que qero remover
									if (numero[i] == numeroRemover)
									{
										printf_s("\nAluno com os seguintes dados : \n");
										printf_s("Nome : ");
										puts(nomeCompleto[i]);
										printf_s("Numero : %05d\tData de Nascimento : %04d-%02d-%02d\nMorada : Rua %s, porta nº %d\nCurso : %s\n\n", numero[i], ano[i], mes[i], dia[i], rua[i], porta[i], curso[i]);
										resultados++;
										break;
									}

									else if (i == 99 && resultados == 0)
									{
										printf_s("\nEsse número não pertence a nenhum aluno ! \n");
										tempo = clock();//conta o tempo
										while (clock() - tempo <= 2000);//enquanto não se passaram  5 segundos	
									}
								}

							} while (resultados != 1);

							if (resultados != 0)
							{
								do
								{								
									resultados = 0;
									confirma = 0;

									Confirma();
									scanf_s("%d", &confirma);
									fflush(stdin);

									//se não confirmar
									if (confirma == 2) 
										break;

									//se confirmar
									else if (confirma == 1)
									{

										//numero de alunos que o sistema suporta : 100
										for (i = 0; i < 100; i++)
										{
											//se numero na posição x = ao que qero remover
											if (numero[i] == numeroRemover)
											{
												//valor na posição x no array vai receber um valor da pocição x + 1 eliminando assim os valores 
												for (k = i; k < 100; k++)
												{
													//só entra uma vez
													if (k == i)
													{
														resultados++;
														system("cls");
														printf_s("\nAluno com os seguintes dados : \n");
														printf_s("Nome : ");
														puts(nomeCompleto[i]);
														printf_s("Numero : %05d\tData de Nascimento : %04d-%02d-%02d\nMorada : Rua %s, porta nº %d\nCurso : %s\n\n", numero[i], ano[i], mes[i], dia[i], rua[i], porta[i], curso[i]);
													}
													//Se a posição for menor que a ultima posição possivel
													if (k < 99)
													{
														// quer dizer que a proxima posição do array não tem nada, ou nenhum valor
														if (numero[k + 1] < 0)
														{
															
															numero[k] = -1;
															strcpy_s(nomeCompleto[k], strlen(nomeCompleto[k]) + 1, "");
															ano[k] = -1;
															mes[k] = -1;
															dia[k] = -1;
															strcpy_s(rua[k], strlen(nomeCompleto[k]) + 1, "");
															porta[k] = -1;
															strcpy_s(curso[k], strlen(nomeCompleto[k]) + 1, "");

															printf_s("\n\nStatus [ removido ] \n");
															printf_s("\n\n\nResultados aparecidos : %d\n", resultados);

															tempo = clock();//conta o tempo
															while (clock() - tempo <= 4000);//enquanto não se passaram  5 segundos	

															break;//sai do ciclo porque não pode haver dois numeros iguais e porque o proximo valor é nulo
														}

														else//copia os dados da posição x + 1 para a posição x
														{
															numero[k] = numero[k + 1];
															strcpy_s(nomeCompleto[k], nomeCompleto[k + 1]);
															ano[k] = ano[k + 1];
															mes[k] = mes[k + 1];
															dia[k] = dia[k + 1];
															strcpy_s(rua[k], strlen(nomeCompleto[k]) + 1, rua[k + 1]);
															porta[k] = porta[k + 1];
															strcpy_s(curso[k], strlen(nomeCompleto[k]) + 1, curso[k + 1]);
														}
													}

													else if (k == 99)
													{
														
														numero[k] = -1;
														strcpy_s(nomeCompleto[k], strlen(nomeCompleto[k]) + 1, "");
														ano[k] = -1;
														mes[k] = -1;
														dia[k] = -1;
														strcpy_s(rua[k], strlen(nomeCompleto[k]) + 1, "");
														porta[k] = -1;
														strcpy_s(curso[k], strlen(nomeCompleto[k]) + 1, "");

														tempo = clock();//conta o tempo
														while (clock() - tempo <= 4000);//enquanto não se passaram  5 segundos	

														printf_s("\n\nStatus [ removido ] \n");
														printf_s("\n\n\nResultados aparecidos : %d\n", resultados);

														break;
													}
												}
											}
										}
										
										break;
									}

								} while (confirma != 2 || confirma != 1);

							}

							do
							{
								system("cls");
								InserirRemover();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);


						} while (repetirAluno == 1);

						system("cls");
						break;

			#pragma endregion 

					//Refeições - Done ! Verificado!
			#pragma region Caso_7
					case 7:
						do
						{
							system("cls");
							subEscolha = -1;
							Refeicoes();
							scanf_s("%d", &subEscolha);
							fflush(stdin);//limpar a memória temporária

							switch (subEscolha)
							{
								case 1://Encomendar refeições - Done!								
								do
								{
									EncomendaRefeicoes(numero, plafond, timeChar, hora, diaA, mesChar, anoO, mesS, nomeCompleto,dateChar);
									Contador++;
								
									EncomendarAccao();
									scanf_s("%d", &repetirAluno);
									fflush(stdin);

									if (repetirAluno == 1)
										continue;

									else if (repetirAluno == 0)
										break;

								} while (repetirAluno != 0);


								break;
								
							case 2://Consumir refeições - Done!
								do
								{
									ConsomeRefeicoes(timeChar, hora, diaA, mesChar, anoO, mesS, dateChar);

									ConsumirAccao();
									scanf_s("%d", &repetirAluno);
									fflush(stdin);

									if (repetirAluno == 1)
										continue;

									else if (repetirAluno == 0)
										break;

								} while (repetirAluno != 0);

								break;

							case 3:
								do
								{
									ListaRefeicoes(numero, nomeCompleto);

									ListarAccao();
									scanf_s("%d", &repetirAluno);
									fflush(stdin);

									if (repetirAluno == 1)
										continue;

									else if (repetirAluno == 0)
										break;

								} while (repetirAluno != 0);


								break;

							case 4:
								do
								{
									ListaDataRefeicoes();

									ListarDataAccao();
									scanf_s("%d", &repetirAluno);
									fflush(stdin);

									if (repetirAluno == 1)
										continue;

									else if (repetirAluno == 0)
										break;

								} while (repetirAluno != 0);

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

						} while (subEscolha !=0);

						break;

			#pragma endregion 

					//Carregar o cartão - Done! Verificado!
			#pragma region Caso_8
					case 8:
						do
						{
							do
							{
								system("cls");
								resultados = 0;
								numeroCarregar = 0;

								CarregarCartao();
								scanf_s("%d", &numeroCarregar);
								fflush(stdin);

								//numero de alunos que o sistema suporta : 100
								for (i = 0; i < 100; i++)
								{
									//se numero na posição x = ao que qero remover
									if (numero[i] == numeroCarregar)
									{

										printf_s("\nAluno com os seguintes dados : \n");
										printf_s("Nome : ");
										puts(nomeCompleto[i]);
										printf_s("Numero : %05d\tData de Nascimento : %04d-%02d-%02d\nMorada : Rua %s, porta nº %d\nCurso : %s\n\n", numero[i], ano[i], mes[i], dia[i], rua[i], porta[i], curso[i]);
										resultados++;
										break;
									}

									else if (i == 99 && resultados == 0)
									{
										printf_s("\nEsse número não pertence a nenhum aluno ! \n");
										tempo = clock();//conta o tempo
										while (clock() - tempo <= 3000);//enquanto não se passaram 3segundos	
									}
								}

								if (resultados != 0)
								{
									do
									{
										confirma = -1;

										Confirma();
										scanf_s("%d", &confirma);
										fflush(stdin);

										if (confirma == 2)
											break;

									} while (confirma != 1);


									//se não confirmar
									if (confirma == 2)
										break;									

									//se confirmar
									else if (confirma == 1)
									{
										do
										{
											system("cls");

											opcaoDados = -1;

											CartaoAccao();
											scanf_s("%d", &opcaoDados); //reutilizar a opção do predifinir dados, pois ela nao vai ser mais usada
											fflush(stdin);

											// Sair
											if (opcaoDados == 0)
												break;

											// Ver o plafond
											if (opcaoDados == 1)
											{
												do
												{
													opcaoDados = -1;
													system("cls");

													printf_s("Voçê tem %.2f euros \n\n\n", plafond[i]);

													CartaoAccaoMais();
													scanf_s("%d", &opcaoDados);
													fflush(stdin);

													if (opcaoDados == 0)
														break;

												} while (opcaoDados != 2);
												
											}

											// Carregar o dinheiro
										    if (opcaoDados == 2)
											{
												do
												{
													carregar = 0;
													system("cls");

													printf_s("Voçê tem : %2.2f euros \n\n\n", plafond[i]);
													printf_s("Deseja carregar o cartão com quanto ? \n");
													scanf_s("%f", &carregar);
													fflush(stdin);

													if (carregar < 0.01)
													{
														carregar = 0;
														printf_s("\nVoçê tem que carregar com mais do que um cêntimo \n");

													}

													plafond[i] += carregar;

													printf_s("\nVoçê ficou com : %0.2f euros \n", plafond[i]);

													tempo = clock();//conta o tempo
													while (clock() - tempo <= 3000);//enquanto não se passaram 3segundos	

												} while (carregar < 0.01);
												
											}

										} while (opcaoDados != 1 || opcaoDados != 2 || opcaoDados != 0);
									}
								}
							} while (numeroCarregar < 1 || numeroCarregar > 99999);


							//se quer repetir o procedimento
							do
							{
								repetirAluno = -1;
								system("cls");

								InserirCartao();
								scanf_s("%d", &repetirAluno);
								fflush(stdin);

								if (numeroCarregar < 1 || numeroCarregar > 99999)
									continue;

								if (repetirAluno == 1)
									break;

								else if (repetirAluno == 0)
									break;

							} while (repetirAluno != 0 || repetirAluno != 1);

						} while (repetirAluno == 1);


						system("cls");
						break;

#pragma endregion

					//Sair - Done!
			#pragma region Caso_0

					case 0:
						system("cls");
						break;
			#pragma endregion


			#pragma region Default

		default:
			printf_s("Opção não conhecida\n");
			printf_s("\nEspere . . .");

			//enquanto não se passaram  2 segundos	
			tempo = clock();
			while (clock() - tempo <= 2000);					

			system("cls");
			break;
#pragma endregion
		}				

	} while (escolha !=0);

#pragma region Base de dados

	//tenta ler se existe
	fopen_s(&baseDados, "Alunos.txt", "r");
	mesDiaAno = __DATE__;
#pragma region Cria base dados

	//se nao existir cria
	if (baseDados == NULL)
	{
		printf_s("\n Vai ser criada a base de dados \n");

		//cria um ficheiro com a base de dados dos alunos			
		fopen_s(&baseDados, "Alunos.txt", "w");

		if (baseDados == NULL)
		{
			printf_s("\n Error ! No permission \n");
		}

		else
		{
			printf_s("\n A gerar ficheiro dos alunos . . .  \n\n Aguarde ");

			//porque sao 100 alunos
			for (i = 0; i < 100; i++)
			{
				//escrever a data
				if (i == 0) fprintf(baseDados, "Data : %s\n", mesDiaAno);

				if (numero[i]<0)
				{
					continue;
				}

				else
				{
					// escreve o nome dos alunos e numero , que estão nesta utilização do programa
					fprintf(baseDados, "\nNumero : %0.5d", numero[i]);
					fprintf(baseDados, "\t  Nome : %s", nomeCompleto[i]);
				}
			}

			printf("\n\n A base de dados foi criada !");
		}
		fclose(baseDados);
	}
#pragma endregion

#pragma region Vai verificar a data

	//ainda em modo de leitura ver se a data é igual á do sistema
	else
	{
		// começa do incio do fichero
		fseek(baseDados, 0, SEEK_SET);

		//Recebe a data do ficheiro 
		fread(dadosData, 18, sizeof(char), baseDados);

		//armazena a data numa variavel
		for (i = 7; i < 18; i++)
		{
			temp[i - 7] = dadosData[i];

		}

		//recebe a data do sistema
		for (i = 0; i < 11; i++)
		{
			dadosData[i] = mesDiaAno[i];
		}

		dadosData[11] = '\0';

		//fecha o ficheiro em modo de leitura
		fclose(baseDados);


#pragma region Se tiver a mesma data escreve de novo

		//actualiza
		if (strcmp(temp, dadosData) == 0)
		{
			//cria um ficheiro com a base de dados dos alunos
			fopen_s(&baseDados, "Alunos.txt", "w");

			if (baseDados == NULL)
			{
				printf_s("\n Error ! No permission \n");
			}

			else
			{
				printf_s("\n A gerar ficheiro dos alunos . . .  \n\n Aguarde ");

				//porque sao 100 alunos
				for (i = 0; i < 100; i++)
				{
					//escrever a data
					if (i == 0) fprintf(baseDados, "Data : %s\n", mesDiaAno);

					if (numero[i]<0)
					{
						continue;
					}

					else
					{
						// escreve o nome dos alunos e numero , que estão nesta utilização do programa
						fprintf(baseDados, "\nNumero : %0.5d", numero[i]);
						fprintf(baseDados, "\t  Nome : %s", nomeCompleto[i]);
					}
				}

				printf("A base de dados foi actualizada !");
			}

			fclose(baseDados);
		}

#pragma endregion

#pragma region Se tiver uma data diferente acrescenta á que existe

		//acrescenta
		else
		{
			//adiciona a um ficheiro com a base de dados dos alunos
			fopen_s(&baseDados, "Alunos.txt", "a");

			if (baseDados == NULL)
			{
				printf_s("\n Error ! No permission \n");
			}

			else
			{
				printf_s("\n A gerar ficheiro dos alunos . . .  \n\n Aguarde ");

				//dar uns espaços
				fprintf(baseDados, "\n\n\n");

				fclose(baseDados);

				//adiciona a um ficheiro com a base de dados dos alunos
				fopen_s(&baseDados, "Alunos.txt", "r+");

				if (baseDados == NULL)
				{
					printf_s("\n Error ! No permission \n");
				}

				else
				{
					//porque sao 100 alunos
					for (i = 0; i < 100; i++)
					{
						//escrever a data
						if (i == 0) fprintf(baseDados, "Data : %s\n", mesDiaAno);

						if (numero[i]<0)
						{
							continue;
						}

						else
						{
							// escreve o nome dos alunos e numero , que estão nesta utilização do programa
							fprintf(baseDados, "\nNumero : %0.5d", numero[i]);
							fprintf(baseDados, "\t  Nome : %s", nomeCompleto[i]);
						}						
					}

					fclose(baseDados);

					printf("Foi adicionada á base de dados existente !");
				}
			}
#pragma endregion

		}
#pragma endregion

		tempo = clock();//conta o tempo
		while (clock() - tempo <= 5000);//enquanto não se passaram  5 segundos	
	}
#pragma endregion

		exit(0);

}
