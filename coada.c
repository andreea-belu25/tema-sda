#include "header.h"

//initializare coada vida
TCoada* InitQ(void)
{
    TCoada *c;
    c=(TCoada*) calloc(1, sizeof(TCelulaCoada)); // aceeasi chestie
    return c;
}
//test
//inserare in coada
int InsQ(TCoada *c, char *x)
{
    TLista aux; // nu merge aici sa scoti pt ca ea vrea sa returneze 0 daca nu a reusit alocarea si 1 daca a reusit
    //tu nu ai nev de asa ceva poti sa o faci void direct ca pnm, nu faci program pt productie si nu prea ai treaba
    //daca esueaza sau nu, mereu o sa ai suficiente resurse unde sa aloci elementele
    
    aux = (TLista) calloc(1, sizeof(TCelula));
    if(!aux)
        return 0;

    aux->info = calloc(strlen(x) + 1, sizeof(char));//gen ca sa pui numele operatie, aloci dimensiunea ei + 1(caracterul null)
    if (aux->info)
        strcpy(aux->info, x);
    aux->urm = NULL;
    
    if((*c)->inc == NULL) {
        (*c)->inc = aux;
    } else {
            (*c)->sf->urm = aux;
            (*c)->sf = aux;
    }
    return 1;
}

//extragere din coada
int ExtQ(TCoada *c, char *x)
{
    TLista aux;
    if((*c)->inc == NULL)
        return 0;
    aux = (*c)->inc;
    strcpy(x, aux->info);
    (*c)->inc = aux->urm;
    if((*c)->inc == NULL) //am avut o singura valoare in coada
        (*c)->sf = NULL;
    free(aux);
    return 1;
}

//distrugere coada
void DistrQ(TCoada **c) //triplu pointer, functia asta vezi ca trebuie sa o chemi cu DistrQ(&&c)
{
    TLista p = (**c)->inc, aux;
    while(p)
    {
        aux = p;
        p = p->urm;
        free(aux);
    }
    free(*c);
    *c = NULL;
}