#include "header.h"

//inserare in stiva
int Push(TStiva* vf, char* x)
{
    TStiva aux = (TStiva)malloc(sizeof(TCelulaStiva));
    if(!aux)
        return 0;
    strcpy(aux->info, x);
    aux->urm = *vf;
    *vf = aux;
    return 1;
}

//extragere din stiva
int Pop(TStiva* vf, char *ax)
{
    TStiva aux;
    if(*vf == NULL)
        return 0;
    strcpy(ax, (*vf)->info); // e deja char pointer, daca dereferentiezi e doar primu character din sir
    aux = *vf;
    *vf = aux->urm;
    free(aux);
    return 1;
}

//distrugere stiva
void DistrugeS(TStiva *vf)
{
    TStiva aux;
    while(*vf)
    {
        aux = *vf;
        *vf = (*vf)->urm;
        free(aux);
    }
}
