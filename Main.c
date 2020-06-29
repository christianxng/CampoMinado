#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM_PADRAO 9
#define BOMBAS_PADRAO 10

void inicializarMatriz(char matriz[][TAM_PADRAO])
{
    int i, j;

    for (i = 0; i < TAM_PADRAO; i++)
    {
        for (j = 0; j < TAM_PADRAO; j++)
        {
            matriz[i][j] = '#';
        }
    }
}
void inicializarMatrizB(char matriz[][TAM_PADRAO])
{
    int i, j;

    for (i = 0; i < TAM_PADRAO; i++)
    {
        for (j = 0; j < TAM_PADRAO; j++)
        {
            matriz[i][j] = '0';
        }
    }
}


void gerarBombas(char matrizBase[][TAM_PADRAO], int linhas, int colunas, int numeroBombas, int l1, int c1)
{
    int posX, posY, i, bombas_Geradas = 0;

    do
    {
        do
        {
            posX = rand() % linhas;

        } while (posX == l1);
        do
        {
            posY = rand() % colunas;

        } while (posX == c1);
        if(matrizBase[posX][posY] != '*')
        {
            matrizBase[posX][posY] = '*';
            bombas_Geradas++;
        }
    }while(bombas_Geradas<numeroBombas);
}

void imprimirMatriz(char matriz[][TAM_PADRAO], int linha, int coluna, int numero_Bomba)
{
    int i, j;
    printf("-------------------------------------------------------");
    printf("\n------------------Campo Minado PADRÃO------------------");
    printf("\n-------------------------------------------------------\n");
    for (i = 0; i < coluna; i++)
    {
        printf("    %d", i);
    }
    printf("\n\n");
    for (i = 0; i < linha; i++)
    {
        printf("%d", i);
        for (j = 0; j < coluna; j++)
        {
            printf("    %c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n Numero de Bombas marcadas: %d/%d\n", numero_Bomba,BOMBAS_PADRAO);
}


void imprimirMatrizladoAlado(char matriz[][TAM_PADRAO], char matriz2[][TAM_PADRAO], int linha, int coluna, int numero_Bomba)
{
    int i, j;
    printf("-------------------------------------------------------");
    printf("\n------------------Campo Minado PADRÃO------------------");
    printf("\n-------------------------------------------------------\n");
    for (i = 0; i < coluna; i++)
    {
        printf("    %d", i);
    }
      printf("\n\n");
    for (i = 0; i < linha; i++)
    {
        printf("%d", i);
        for (j = 0; j < coluna; j++)
        {
            printf("    %c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n-------------------------------------------------------");
    printf("\n------------------MATRIZ BOMBAS------------------");
    printf("\n-------------------------------------------------------\n");
     for (i = 0; i < coluna; i++)
    {
        printf("    %d", i);
    }
      printf("\n\n");
    for (i = 0; i < linha; i++)
    {
        printf("%d", i);
        for (j = 0; j < coluna; j++)
        {
            printf("    %c", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n Numero de Bombas marcadas: %d/%d\n", numero_Bomba,BOMBAS_PADRAO);
}


void inserirBandeira(char  matriz_jogo[][TAM_PADRAO],char  matriz_base[][TAM_PADRAO], int * numero_Bomba)
{
    int opBandeira = 0, retornoBandeira = 0, l, c;
    printf("Deseja Marcar alguma Bandeira?   1 - Sim \t 2 - Não\n");
    scanf("%d", &opBandeira);
    if (opBandeira == 1)
    {

        do
        {

            printf("Digite a linha e coluna para marcar a Bandeira: \n");
            scanf("%d %d", &l, &c);

            if (matriz_jogo[l][c] != 'B')
            {
                 matriz_jogo[l][c] = 'B';
                (*numero_Bomba)++;
                retornoBandeira = 1;
                //imprimirMatriz(matriz_jogo, TAM_PADRAO, TAM_PADRAO, *numero_Bomba);
                imprimirMatrizladoAlado(matriz_jogo,matriz_base,TAM_PADRAO, TAM_PADRAO, (*numero_Bomba));
                
            }
            else
            {
                printf(" \t !!! Local ja marcado com bandeira -- Selecione novamente:\n");
                retornoBandeira = 0;
            }

        } while (retornoBandeira != 1);
    }
}

int verificaAdPadrao(char matriz_base[][TAM_PADRAO],int l, int c)
{
    int i,j,contador = 0;
    for (i = (l - 1); i < (l + 2); i++)
        {
            for (j = (c - 1); j < (c + 2); j++)
            {
                //printf("\n l:%d c:%d : %c\n", i, j, matriz_base[i][j]);
                if ( i < TAM_PADRAO  && i >= 0 && j < TAM_PADRAO && j >= 0 && matriz_base[i][j] == '*')
                {
                    contador++;
                }               
                
            }
        }

    return contador;
    
}

int verificaoAdjacentes(char matriz_jogo[][TAM_PADRAO], char matriz_base[][TAM_PADRAO], int l, int c)
{
    int contador = 0,situacao = 0, i, j, casasAbertas = 0, pixel;
    char v,p;
    
    if (matriz_base[l][c] == '*')
    {

        matriz_jogo[l][c] = '*';
        situacao = 1;
        return situacao;
    }
    else
    {
        for (i = (l - 1); i < (l + 2); i++)
        {
            for (j = (c - 1); j < (c + 2); j++)
            {
                //printf("\n l:%d c:%d : %c\n", i, j, matriz_base[i][j]);
                if ( i < TAM_PADRAO  && i >= 0 && j < TAM_PADRAO && j >= 0 && matriz_base[i][j] == '*')
                {
                    contador++;
                }
                else if( i < TAM_PADRAO  && i >= 0 && j < TAM_PADRAO && j >= 0)
                {
                    pixel = verificaAdPadrao(matriz_base,i,j);
                    p = pixel + '0';
                    if(p == '0' )
                    {
                        matriz_jogo[i][j]= '-';
                    }
                    else
                    {
                       matriz_jogo[i][j]= p;
                    }                  
                    
                }
                
            }
        }
        v = contador + '0';

        if(v == '0')
        {
            matriz_jogo[l][c] = '-';
        }
        else
        {
            matriz_jogo[l][c] = v;
        }
        
    }
    for (i = 0; i < TAM_PADRAO; i++)
    {        
        for (j = 0; j < TAM_PADRAO; j++)
        {
            if(matriz_jogo[i][j]!='#')
            casasAbertas++;
        }       
    }
    if(casasAbertas - ((TAM_PADRAO*TAM_PADRAO)-BOMBAS_PADRAO)==0)
    {
        return 2;
    }
    else
    {
        return 0;
    }
    
}
void expandir(char matriz_base[][TAM_PADRAO],char matriz_jogo[][TAM_PADRAO], int l, int c){
    int i ,j;
    for(i=(l-1);i<(l+2);i++){
        for(j=(l-1);j<(l+2);j++){
            if(matriz_base[i][j]=='0'){
                if( i < TAM_PADRAO  && i >= 0 && j < TAM_PADRAO && j >= 0 )
                {
                    matriz_jogo[i][j]='-';
                }
                
            }
        }

    }

}
int barreiraDiagonal(char matriz_base[][TAM_PADRAO], int l,int c){
    if((matriz_base[l][c-1] !='0' && matriz_base[l+1][c] !='0' )
     ||(matriz_base[l-1][c] !='0' && matriz_base[l][c] !='0' ) 
     || (matriz_base[l][c+1] !='0' && matriz_base[l-1][c] !='0' ) 
     || (matriz_base[l][c+1] !='0' && matriz_base[l+1][c] !='0' )){
        return 1;
    }
    return 0;
}
void explorar(char matriz_base[][TAM_PADRAO],char matriz_jogo[][TAM_PADRAO], int l, int c){
    int i,j,situacao=0;
    for(i=(l-1);i<(l+2) && (i<TAM_PADRAO && i>=0) ;i++){
        for(j=(l-1);j<(l+2) && (j<TAM_PADRAO && j>=0);j++){
            situacao=barreiraDiagonal(matriz_base,i,j);
            if(matriz_base[i][j]=='0' && situacao==0){
                printf("\n %d %d",i,j);
                //expandir(matriz_base,matriz_jogo,i,j);
                verificaoAdjacentes(matriz_jogo,matriz_base,i,j);
            }
        }
    }
}

void campoMinadoPadrao(char matriz_jogo[][TAM_PADRAO], char matriz_base[][TAM_PADRAO], int *numero_Bomba)
{

    int l, c, situacao = 0, opBandeira = 0;


    inicializarMatriz(matriz_jogo);
    inicializarMatrizB(matriz_base);
    printf("digite a linha e coluna para explorar: \n");
    scanf("%d %d", &l, &c); 
    gerarBombas(matriz_base, TAM_PADRAO, TAM_PADRAO, BOMBAS_PADRAO, l, c);
    verificaoAdjacentes(matriz_jogo, matriz_base, l, c);
    explorar(matriz_base,matriz_jogo,l,c);
    imprimirMatriz(matriz_jogo, TAM_PADRAO, TAM_PADRAO, (*numero_Bomba));
    do
    {

        printf("digite a linha e coluna para explorar: \n");
        scanf("%d %d", &l, &c); 
        explorar(matriz_base,matriz_jogo,l,c);
        printf("\n main: l:%d c:%d\n", l, c);
        situacao = verificaoAdjacentes(matriz_jogo, matriz_base, l, c);
        
        //imprimirMatriz(matriz_jogo, TAM_PADRAO, TAM_PADRAO, (*numero_Bomba));
        imprimirMatrizladoAlado(matriz_jogo,matriz_base,TAM_PADRAO, TAM_PADRAO, (*numero_Bomba));

        if (situacao == 1)
        {
            printf("\n\n\n* * * * * * * * * * * * GAME OVER - BOMBA SELECIONADA * * * * * * * * * * * * \n\n\n\n\n\n");
            break;
        }
        else if(situacao == 2)
        {
            printf("\n\n\n* * * * * * * * * * * * VOCÊ GANHOU * * * * * * * * * * * * \n\n");
            printf("\n* * * * * * * * * * * * PARABÉNS * * * * * * * * * * * * \n\n\n\n\n\n");
            break;
        }
        else
        {
            inserirBandeira(matriz_jogo,matriz_base, numero_Bomba);
                    
        }

    } while (situacao == 0);
}
void menu(char matriz_jogo[][TAM_PADRAO], char matriz_base[][TAM_PADRAO], int *numero_Bomba)
{

    int opcao;

    do
    {
        printf("------------------------------------------------");
        printf("\n------------------Campo Minado------------------");
        printf("\n------------------------------------------------\n\n");
        printf("\n                      MENU\n");
        printf(" 1 -> Novo Jogo\n 2 -> Personalizar tabuleiro\n 3 -> Recordes\n 0 -> Sair\n");
        printf("\nDigite um opção:\n");

        scanf("%d", &opcao);
        switch (opcao)
        {

            case 1:

                campoMinadoPadrao(matriz_jogo, matriz_base, numero_Bomba);

                break;
            case 2:
                printf("\nParte ainda não pronta\n");  
                break;
            case 3: 
                printf("\nParte ainda não pronta\n");  
                break;
            case 0: 
                printf("\n Obrigado! \n");  
                exit(1);         
            default:
                printf("\nOpção Invalida\n");
                break;
            }
    } while (opcao != 0);
}

int main()
{

    srand(1);
    int numero_bomba_marcada = 0;
    char matriz_jogo[TAM_PADRAO][TAM_PADRAO], matriz_base[TAM_PADRAO][TAM_PADRAO];
    menu(matriz_jogo, matriz_base, &numero_bomba_marcada);

    return 0;
}

