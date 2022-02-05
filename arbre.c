#include <stdio.h>
#include "arbre.h"

TArbre arbreConsVide()
{
    TArbre A;
    A = (TArbre)malloc(sizeof(struct noeud));
    A->lettre = NULL;
    A->nb = NULL;
    A->fg = NULL;
    A->fd = NULL;
    return A;
}

int arbreEstVide(TArbre A)
{
    return (A == NULL);
}

TArbre arbreCons(char c, int nb, TArbre fg, TArbre fd)
{
    TArbre A;
    A = (TArbre)malloc(sizeof(struct noeud));
    A->lettre = c;
    A->nb = nb;
    A->fg = fg;
    A->fd = fd;
    return A;
}

char arbreRacineLettre(TArbre A)
{
    return A->lettre;
}

int arbreRacineNbOcc(TArbre A)
{
    return A->nb;
}

TArbre arbreFilsGauche(TArbre A)
{
    return (A->fg);
}

TArbre arbreFilsDroit(TArbre A)
{
    return (A->fd);
}

void arbreSuppr(TArbre A)
{
    if (!arbreEstVide(A))
    {
        arbreSuppr(A->fg);
        arbreSuppr(A->fd);
        free(A);
    }
}

