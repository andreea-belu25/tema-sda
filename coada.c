#include "header.h"

//initializare coada vida
TCoada* InitQ(void)
{
    TCoada *c;
    c=(TCoada*)malloc(sizeof(TCelulaCoada));
    if(!c)
        return NULL;
    (*c)->inc = NULL; 
    (*c)->sf = NULL;
    return c;
}
//test
//inserare in coada
int InsQ(TCoada *c, int x)
{
    TLista aux;
    aux = (TLista)malloc(sizeof(TCelula));
    if(!aux)
        return 0;
    aux->info = c;
    aux->urm = NULL;
    if(c->inc == NULL) {
        c->inc = aux;
    } else {
            c->sf->urm = aux;
            c->sf = aux;
    }
    return 1;
}

//extragere din coada
int ExtQ(TCoada *c, char *x)
{
    TLista aux;
    if(c->inc == NULL)
        return 0;
    aux = (*c)->inc;
    strcpy(*x, aux->info);
    (*c)->inc = aux->urm;
    if(c->inc == NULL) //am avut o singura valoare in coada
        c->sf = NULL;
    free(aux);
    return 1;
}

//distrugere coada
void DistrQ(TCoada **c)
{
    TLista p = (*c)->inc, aux;
    while(p)
    {
        aux = p;
        p = p->urm;
        free(aux);
    }
    free(*c);
    *c = NULL;
}