/* *******************************************************
 **| Programa   : Rede de Petri com Processos Paralelos|**
 **| Autores    : Isabella Galvão e Kewin Lima         |**
 **| Orientador : Ruben Carlo                          |**
 *********************************************************
 **/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NENTRADA 5
#define QINFO 3

typedef struct_token token;
struct struct_token
{
    token *proximo;
};

typedef struct_pilha pilha;

struct struct_pilha
{
    token *topo;
};

pilha cria_pilha(void)
{
    pilha nova_pilha;
    nova_pilha.topo = NULL;
    return nova_pilha;
}

void adiciona_elemento(pilha *p)
{
    if(p.topo == NULL)
    {
        token t;
        t.proximo = NULL;
        p.topo = t;
    }
    else 
    {
        token t;
        t.proximo = p.topo;
        p.topo = t;
    }
}

void remove_elemento(pilha *p)
{
    if(p.topo != NULL)
    {
       p.topo = p.topo.proximo;
    }
}

int pilha_esta_vazia(pilha *p)
{
    if(p.topo == NULL)
        return 1;
    else
        return 0;
}

//Protótipos
int *cria_lugares(int numero_de_lugares);
    
int main(void)
{
    //q[0] = qunatidade de lugar, 
    //q[1] = quantidade de trans,
    //q[2] = quantidade de lugartoke,
    //q[3] = qarcotrans,
    //q[4] = qarcolugar,

    int n,q[NENTRADA],n1; 
    FILE *a = fopen("entrada.txt","r"); // Abrindo o arquivo de entrada

    for(n=0;n<NENTRADA;n++) //Laço para o vetor q
    {
        fscanf(a,"%d", &q[n]);
    }
    int *lugar = cria_lugares(q[0]); //cria n-lugares
    int arcotrans[q[3]][3];  
    int arcolugar[q[4]][3];

    for(n=0;n<( q[2] );n++)
    {
         fscanf(a,"%d", &n1);
         fscanf(a,"%d", &lugar[n1]);
         printf(" %d %d\n", n1, lugar[n1]);
    }
    for(n=0; n<q[3]; n++)
    {
        for(n1=0; n1 < QINFO; n1++)
        {
                fscanf(a, "%d", &arcotrans[n][n1]);
        }
    }    
    // arct[n][0] = lugar de origem
    // arct[n][1] = quantidade de tokens consumidos
    // arct[n][2] = transição de destino
    
    for(n=0; n<q[4]; n++)
    {
        for(n1=0; n1<QINFO; n1++)
        {
               fscanf(a,"%d", &arcolugar[n][n1]);
        }
    }

    // arlg[n][0] = transição de origem
    // arlg[n][1] = quantidade de tokens consumidos
    // arlg[n][2] = lugar de destino
    
    free(lugar); // limpando a alocação dinamica
    fclose(a);// fechando o arquivo de entrada
    return 0;
}

int *cria_lugares(int numero_de_lugares)
{
    return malloc(numero_de_lugares * (sizeof(int))); //Alocação dinâmica
}
