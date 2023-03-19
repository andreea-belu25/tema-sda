#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula2
{
    char info;
    struct celula2 *pre, *urm;
}TCelula2, *TL2;

//implementare stiva
typedef struct celst
{
    char *info; //aici o sa iti trebuiasca pointer in loc de char, dar cand ajungi la undo o sa vezi
    struct celst *urm;
}TCelulaStiva, *TStiva;

//definire lista simplu inlantuita pentru coada
typedef struct celula
{
    struct celula *urm;
    char *info; //fa-le si tu char pointer sa nu mai fi restrictionata la cate charactere pui in el, ca oricum aloci dinamic
}TCelula, *TLista;

//implementare coada
typedef struct coada
{
    TLista inc, sf;
}TCelulaCoada, *TCoada;

TL2 InitL2();
void DistrugeL(TL2 *s);
TL2 AlocCelula(char elem);
void DistrugeL1(TLista *aL);
TStiva InitS(void);
int Push(TStiva* vf, char* x);
int Pop(TStiva* vf, char *ax);
void DistrugeS(TStiva *vf);
TCoada* InitQ(void);
int InsQ(TCoada *c, char *x);
int ExtQ(TCoada *c, char *x);
void DistrQ(TCoada **c);
