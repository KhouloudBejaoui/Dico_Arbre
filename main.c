#include <stdio.h>
#include <string.h>
#include "dico.h"

int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    dico = (TArbre)malloc(sizeof(struct noeud));
    dico = arbreConsVide();
    char rep;
    char choix[50];

    while (rep != 'n')
    {
        if (piocherMot(&buffer))
        {
            dicoInsererMot(buffer, &dico);
            printf("\n");printf("\n");
            printf("   +------------------------------------------------------------+\n");
            printf("   |\t\t\t Arbre Dico\t\t\t\t|\n");
            printf("   +------------------------------------------------------------+\n");
            dicoAfficher(dico);
            int z = dicoNbMotsDifferents(dico);
            printf("\n");
            printf(" \t\t-Nombre mot differents =%d", z);
            printf("\n");
            int y = dicoNbMotsTotal(dico);
            printf("\t\t-Nombre mot totale =%d ", y);
            printf("\n");
            printf("\n \t **** Choisir un mot pour savoir son occurrence ****\n");
            do
            {
                scanf("%s", &choix);
            } while (choix == "");

            int x = dicoNbOcc(choix, dico);
            printf("\t\t-L'occurrence du mot %s =%d ", choix, x);
        }
        printf("\n");
        printf("\n \t **** Voulez-vous inserer un autre mot ? ****\n");
        do
        {
            scanf("%c", &rep);
        } while (rep != 'n' && rep != 'o');
    }
}

