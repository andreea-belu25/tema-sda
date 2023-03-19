#include "header.h"

//initializare lista dublu inlantuita cu santinela + '#'
 TL2 InitL2()
 {
    TL2 s = (TL2)malloc(sizeof(TCelula2));
    if(s == NULL) 
        return NULL;
    s->info = 0;
    s->pre = NULL;
    s->urm = NULL;
    TL2 aux = (TL2)malloc(sizeof(TCelula2));
    if(aux == NULL)
        return NULL;
    aux->info = '#';
    aux->pre = s;
    aux->urm = NULL;

    s-> urm = aux;
    return s;
 }

 //distrugere lista dublu inlantuita cu santinela
 void DistrugeL(TL2 *s)
 {
    TL2 p = 0, aux = 0;
    for(p = (*s)->urm; p != (*s);)
    {
        aux = p;
        p = p->urm;
        free(aux);
    }
    if(s != NULL)
        free(s);
 }

 // Aloca un element de tip Celula si returneaza pointerul aferent
TL2 AlocCelula(char elem) {
    TL2 aux = (TL2)malloc(sizeof(TCelula2));   // alocare */
    if(aux == NULL) 
         return NULL; // returnez NULL
    aux->info = elem;
    aux->pre = NULL;
    aux->urm = NULL;
    return aux;  //returnez adresa 
}


//distrugere lista simplu inlantuita
void DistrugeL1(TLista *aL)
{
    TLista p, aux;
    p = *aL;
    while(p)
    {
        aux = p;
        p = p->urm;
        free(aux);
    }
    *aL = NULL;
}