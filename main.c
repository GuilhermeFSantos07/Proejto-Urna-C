#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*--------------------------------registro de candidatos--------------------------------*/
//candidato a presid�ncia
struct registro_prsdnt{ //struct de dados para presid�ncia
	char nome[50]; //nome do candidato
	char partido[50]; //nome do partido
	char vice[50]; //nome do vice candidato
	int numeroV; //n�mero do candidato
	int votosP;//n�mero de votos
}candidatoP[3]; //vetores para armazenar os candidatos a presid�ncia

void cadastro_prsdnt(char P){ //void para solicitar e armazenar os dados em vetores
	int p; //vari�vel para o comando for
	for(p=0;p<3;p++){ //estrutura para os vetores
		printf("\nDigite o nome do candidato: "); //solicita o nome do candidato
		fgets(candidatoP[p].nome, 50, stdin); //guarda o nome do candidato
		candidatoP[p].nome[strlen(candidatoP[p].nome) - 1] = '\0';
		printf("Digite o nome do partido: "); //solicita o nome do partido
		fgets(candidatoP[p].partido, 50, stdin); //guarda o nome do partido
		candidatoP[p].partido[strlen(candidatoP[p].partido) - 1] = '\0';
		printf("Digite o nome do vice-presidente: "); //solicita o nome do vice candidato
		fgets(candidatoP[p].vice, 50, stdin); //guarda o nome do vice candidato
		candidatoP[p].vice[strlen(candidatoP[p].vice) - 1] = '\0';
		printf("Digite o numero do candidato: "); //solicita o n�mero para votar no candidato
		scanf("%d", &candidatoP[p].numeroV); //guarda o n�mero para votar no candidato
		getchar(); //previni o \n ser ativado 2 vezes
	}
}

//candidato a governo
struct registro_gvrn{ //struct de dados para governo
	char nome[50]; //nome do candidato
	char partido[50]; //nome do partido
	char vice[50]; //nome do vice candidato
	int numeroV; //n�mero do candidato
	int votosG; //n�mero de votos
}candidatoG[3]; //vetores para armazenar os candidatos a governo

void cadastro_gvrn(char G){ //void para solicitar e armazenar os dados em vetores
	int g; //vari�vel para o comando for
	for(g=0;g<3;g++){ //estrutura para os vetores
		printf("\nDigite o nome do candidato: "); //solicita o nome do candidato
		scanf("%s", candidatoG[g].nome); //guarda o nome do candidato
		printf("Digite o nome do partido: "); //solicita o nome do partido
		scanf("%s", candidatoG[g].partido); //guarda o nome do partido
		printf("Digite o nome do vice-governador: "); //solicita o nome do vice candidato
		scanf("%s", candidatoG[g].vice); //guarda o nome do vice candidato
		printf("Digite o n�mero do candidato: "); //solicita o n�mero para votar no candidato
		scanf("%d", &candidatoG[g].numeroV); //guarda o n�mero para votar no candidato
		getchar(); //previni o \n ser ativado 2 vezes
	}
}

//candidato ao senado
struct registro_sndr{ //struct de dados para senado
	char nome[50]; //nome do candidato
	char partido[50]; //nome do partido
	int numeroV; //n�mero do candidato
	int votosS; //n�mero de votos
}candidatoS[3]; //vetores para armazenar os candidatos ao senado

void cadastro_sndr(char S){ //void para solicitar e armazenar os dados em vetores
	int s; //vari�vel para o comando for
	for(s=0;s<3;s++){ //estrutura para os vetores
		printf("\nDigite o nome do candidato: "); //solicita o nome do candidato
		scanf("%s", candidatoS[s].nome); //guarda o nome do candidato
		printf("Digite o nome do partido: "); //solicita o nome do partido
		scanf("%s", candidatoS[s].partido); //guarda o nome do partido
		printf("Digite o numero do candidato: "); //solicita o n�mero para votar no candidato
		scanf("%d", &candidatoS[s].numeroV); //guarda o n�mero para votar no candidato
		getchar(); //previni o \n ser ativado 2 vezes
	}
}

/*--------------------------------registro de eleitores--------------------------------*/
struct registro_eleitor{ //struct para eleitores
	char nome[50]; //nome do candidato
	int voto1, voto2, voto3, Ntitulo; //vari�veis dos 3 votos e n�mero do t�tulo
}eleitor[2][2]; //matriz para armazenar os eleitores

void cadastrar_eleitor(char E){ //void para solicitar e armazenar os eleitores
	int l, c; //vari�veis para o comando for
	for(l=0;l<2;l++){ //estrtura para as linhas da matriz
		for(c=0;c<2;c++){ //estrutura para as colunas da matriz
			printf("\nDigite o nome do eleitor: "); //solicita o nome do eleitor
			scanf("%s", eleitor[l][c].nome); //aramazena o nome do eleitor
			printf("Digite o numero do titulo: "); //solicita o n�mero do t�tulo
			scanf("%d", &eleitor[l][c].Ntitulo); //armazena o n�mero do t�tulo
			getchar(); //previni o \n ser ativado 2 vezes
		}
	}
}


/*---------------------------------------elei��o---------------------------------------*/
void eleicao(char V){ //void para o processo de elei��o
  int l, c, i, titulo, op3; //vari�veis para os comandos for, receber o n�mero do t�tulo e para comando switch
  for(i=0;i<2;i++){ //estrutura para os vetores
    candidatoP[i].votosP=0; //zera o n�mero de votos do candidato
    candidatoG[i].votosG=0; //zera o n�mero de votos do candidato
    candidatoS[i].votosS=0; //zera o n�mero de votos do candidato
  }
  while(1){ //loop infinito com comando para encerrar
    printf("\nDigite o numero do titulo: "); //solicita o n�mero do t�tulo
    scanf("%d", &titulo); //armazena o n�mero do t�tulo
    getchar(); //previni o \n ser ativado 2 vezes
    if(titulo==36237727){ //se digitado, o n�mero 36237727 encerra o loop
      break; //encerrando o loop
    }
    for(l=0;l<2;l++){ //estrutura para as linhas da matriz
      for(c=0;c<2;c++){ //estrtura para as colunas da matriz
        if(titulo==eleitor[l][c].Ntitulo){ //consulta se o n�mero do t�tulo est� cadastrado
          printf("\nEleitor encontrado: "); //imprime caso sim. caso n�o volta para a solicita��o na linha 105
          printf("%s", eleitor[l][c].nome); //exibe o nome do eleitor encontrado
          printf("\nDigite o numero do candidato a presidencia: "); //solicita o n�mero do candidato a presid�ncia
          scanf("%d", &eleitor[l][c].voto1); //armazena o voto
          getchar(); //previni o \n ser ativado 2 vezes
          for(i=0;i<3;i++){ //estrutura para consultar o candidato � presid�ncia
            if(eleitor[l][c].voto1==candidatoP[i].numeroV){ //consulta o candidato. 
              //caso n�o encontre, entende-se como voto nulo e vai pra pr�xima sequ�ncia
              printf("\nNome do candidato: %s", candidatoP[i].nome); //caso encontre exibe o nome do candidato
              printf("\nNome do vice: %s", candidatoP[i].vice); //exibe o nome do vice
              printf("\nNome do partido: %s", candidatoP[i].partido); //exibe o nome do partido
              printf("\n");
              printf("\n1-Confirmar"); //op��o 1: confirma voto
              printf("\n2-Cancelar"); //op��o 2: cancela o voto
              printf("\nDigite a opcao: "); //solicita a op��o
              scanf("%d", &op3); //armazena a op��o
              getchar(); //previni o \n ser ativado 2 vezes
              switch(op3){ //escolhas
                case 1: //confirma
                  candidatoP[i].votosP++; //adiciona um voto pro candidato
                  printf("\nVoto confirmado"); //imprime a confirma��o
                  printf("\n");
                break; 
                case 2: //cancela e segue para a pr�xima sequ�ncia
                  eleitor[l][c].voto1=0; //deixa o voto vazio
                  printf("\nVoto cancelado"); //imprime a confirma��o
                  printf("\n");
                break;
              }
            }
          }
          printf("\nDigite o numero do candidato a governador: "); //solicita o n�mero do candidato a governador
          scanf("%d", &eleitor[l][c].voto2); //armazena o voto
          getchar(); //previni o \n ser ativado 2 vezes
          for(i=0;i<3;i++){ //estrutura para consultar o candidato
            if(eleitor[l][c].voto2==candidatoG[i].numeroV){ //consuta o candidato
              //caso n�o encontre, entende-se como voto nulo e vai pra pr�xima sequ�ncia
              printf("\nNome do candidato: %s", candidatoG[i].nome); //caso encontre exibe o nome do candidato
              printf("\nNome do vice: %s", candidatoG[i].vice); //exibe o nome do vice
              printf("\nNome do partido: %s", candidatoG[i].partido); //exibe o nome do partido
              printf("\n1-Confirmar"); //op��o 1: confirma voto
              printf("\n2-Cancelar"); //op��o 2: cancela o voto
              printf("\nDigite a opcao: "); //solicita a op��o
              scanf("%d", &op3); //armazena a op��o
              getchar(); //previni o \n ser ativado 2 vezes
              switch(op3){ //escolhas
                case 1: //confirma
                  candidatoG[i].votosG++; //adiciona um voto pro candidato
                  printf("\nVoto confirmado"); //imprime a confirma��o
                break;
                case 2: //cancela e segue para a pr�xima sequ�ncia
                  eleitor[l][c].voto2=0; //deixa o voto vazia
                  printf("\nVoto cancelado"); //imprime a confirma��o
                break;
              }
            }
          }
          printf("\nDigite o numero do candidato a senador: "); //solicita o n�mero do candidato a senador
          scanf("%d", &eleitor[l][c].voto3); //armazena o voto
          getchar(); //previni o \n ser ativado 2 vezes
          for(i=0;i<3;i++){ //estrutura para consultar o candidato
            if(eleitor[l][c].voto3==candidatoS[i].numeroV){ //consulta o candidato
              //caso n�o encontre, entende-se como voto nulo e vai pra pr�xima sequ�ncia
              printf("\nNome do candidato: %s", candidatoS[i].nome); //caso encontre exibe o nome do candidato
              printf("\nNome do partido: %s", candidatoS[i].partido); //exibe o nome do vice
              printf("\n1-Confirmar"); //op��o 1: confirma voto
              printf("\n2-Cancelar"); //op��o 2: cancela voto
              printf("\nDigite a opcao: "); //solicita a op��o
              scanf("%d", &op3); //armazena a op��o
              getchar(); //previni o \n ser ativado 2 vezes
              switch(op3){ //escolhas
                case 1: //confirma
                  candidatoS[i].votosS++; //adiciona um voto pro candidato
                  printf("\nVoto confirmado"); //imprime a confirma��o
                break;
                case 2: //cancela e volta pro come�o do loop
                  eleitor[l][c].voto3=0; //deixa o voto vazio
                  printf("\nVoto cancelado"); //imprime a confirma��o
                break;
              }
            }
          }
        }
      }
    }
  }
}


/*---------------------------------------resultado---------------------------------------*/
void resultados(char R){ //void para exibir os resultados
	int eleitoP, eleitoG, eleitoS, i; //vari�veis para armazenar o eleito e vari�vel para o comando for
	eleitoP=0; //igualando a zero
	eleitoG=0; //igualando a zero
	eleitoS=0; //igualando a zero

    for(i=0;i<3;i++){ //estrutura para os vetores
    	printf("\nNome do candidato: %s", candidatoP[i].nome); //exibe o nome do candidato a presid�ncia
    	printf("\nPartido: %s", candidatoP[i].partido); //exibe o nome do partido
    	printf("\nNome do Vice: %s", candidatoP[i].vice); //exibe o nome do vice
    	printf("\nN�mero para votar: %d", candidatoP[i].numeroV); //exibe o n�mero para voto
    	printf("\nN�mero de votos: %d", candidatoP[i].votosP); //exibe a quantidade de votos
    	if(candidatoP[i].votosP>eleitoP){ //consulta se o n�mero de votos � maior
			eleitoP=candidatoP[i].votosP; //se sim ele armazena na vari�vel para futuras consultas
    	}
    	if(eleitoP>1){ //estrutura para previnir que imprima no primeiro loop
			printf("\nCandidato eleito"); //caso seja o maior ele imprime o eleito
		}
	}
	for(i=0;i<3;i++){ //estrutura para os vetores
		printf("\nNome do candidato: %s", candidatoG[i].nome); //exibe o nome do candidato a governador 
		printf("\nPartido: %s", candidatoG[i].partido);  //exibe o nome do partido
		printf("\nNome do Vice: %s", candidatoG[i].vice); //exibe o nome do vice
		printf("\nN�mero para votar: %d", candidatoG[i].numeroV); //exibe o n�mero para voto
		printf("\nN�mero de votos: %d", candidatoG[i].votosG); //exibe a quantidade de votos
		if(candidatoG[i].votosG>eleitoG){ //consulta se o n�mero de votos � maior
			eleitoG=candidatoG[i].votosG; //se sim ele armazena na vari�vel para futuras consultas
		}
		if(eleitoG>1){ //estrutura para previnir que imprima no primeiro loop
			printf("\nCandidato eleito"); //caso seja o maior ele imprime o eleito
		}
	}
	for(i=0;i<3;i++){ //estrutura para os vetores
		printf("\nNome do candidato: %s", candidatoS[i].nome); //exibe o nome do candidato a senador
		printf("\nPartido: %s", candidatoS[i].partido); //exibe o nome do partido
		printf("\nNumero para votar: %d", candidatoS[i].numeroV); //exibe o n�mero para voto
		printf("\nN�mero de votos: %d", candidatoS[i].votosS); //exibe a quantidade de votos
		if(candidatoS[i].votosS>eleitoS){ //consulta se o n�mero de votos � maior
			eleitoS=candidatoS[i].votosS; //se sim ele armazena na vari�vel para futuras consultas
		}
		if(eleitoS>1){ //estrutura para previnir que imprima no primeiro loop
			printf("\nCandidato eleito"); //caso seja o maior ele imprime o eleito
		}
	}
}

/*-----------------------------------------menus-----------------------------------------*/
void menus(char M){ //void que cont�m os menus principais
	int op, op2; //vari�vel para os comados switch

	while(1){ //loop infinito com vari�vel de controle
		printf("\n1-Cadastrar candidato"); //op��o 1
		printf("\n2-Cadastrar eleitor"); //op��o 2
		printf("\n3-Eleicao"); //op��o 3
		printf("\n4-Resultado"); //op��o 4
		printf("\n5-Encerrar"); //op��o 5
		printf("\nDigite a opcao: "); //solicita uma op��o
		scanf("%d", &op); //armazena a op��o
		getchar(); //previni o \n ser ativado 2 vezes
		switch(op){ //escolhas do primeiro menu
			case 1: //op��o 1 cadastro de candidato
				printf("\n1-Cadastrar presidente"); //op��o 1 cadastrar  presid�nte
				printf("\n2-Cadastrar governador"); //op��o 2 cadastrar governador
				printf("\n3-Cadastar senador");//op��o 3 cadastar senador
				printf("\n4-Voltar pro menu anterior");
				printf("\nDigite a opcao: "); //solicita uma op��o
				scanf("%d", &op2); //armazena a op��o
				getchar();
				switch(op2){ //escolhas do segundo menu
					case 1: //op��o 1 cadastro de presid�nte
						cadastro_prsdnt('P'); //chama a fun��o void de presid�nte
					break;
					case 2: //op��o 2 cadastro de governador
						cadastro_gvrn('G'); //chama a fun��o void de governador
					break;
					case 3: //op��o 3 cadastro de senador
						cadastro_sndr('S'); //chama a fun��o void de senador
					break;
					case 4: //op��o 4: volta pro menu inicial
					break;
				}
			break;
			case 2: //op��o 2 cadastro de eleitor
				cadastrar_eleitor('E'); //chama a fun��o void de cadastro de eleitor
			break;
			case 3: //op��o 3 elei��o
				eleicao('V'); //chama a fun��o void de elei��o
			break;
			case 4: //op��o 4 resultados
				resultados('R'); //chama a fun��o void de resultados
			break;
		}
		if(op==5){ //op��o 5 finaliza o loop
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	int l, c; //vari�veis para o comando for

	menus('M'); //chama a fun��o de menus
  
	//ap�s encerrar o loop de menus
	//eleitores e seus votos
	for(l=0;l<2;l++){ //estrutura para as linhas da matriz
		for(c=0;c<2;c++){ //estrtura para as colunas da matriz
			printf("\nNome do eleitor: %s", eleitor[l][c].nome); //exibe o nome do elitor
			printf("\nNumero do titulo: %d", eleitor[l][c].Ntitulo); //exibe o n�mero do t�tulo
			printf("\nVoto para presidente: %d", eleitor[l][c].voto1); //exibe o voto para presid�ncia
			printf("\nVoto para governador: %d", eleitor[l][c].voto2); //exibe o voto para governador
			printf("\nVoto para senador: %d", eleitor[l][c].voto3); //exibe para o senado
		}
	}

	printf("\nPrograma encerrado"); //confirma que o programa foi encerrado

	return 0;
}
// :)
