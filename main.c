#include <stdio.h>
#include <string.h>
#include "dico.h"

int main(int argc, char **argv)
{
    TArbre dico;
    char buffer[100];
    dico = (TArbre)malloc(sizeof(struct noeud));
    dico = arbreConsVide();
    //int x = 0, y = 0, z = 0;
    char rep;
    /*  strcpy(buffer, "gallon");
        dicoInsererMot(buffer, &dico);
        strcpy(buffer, "all");
        dicoInsererMot(buffer, &dico);
        strcpy(buffer, "maison");
        dicoInsererMot(buffer, &dico);
        strcpy(buffer, "maison");
        dicoInsererMot(buffer, &dico);*/

    /* while (rep != 'N')
    { int j = piocherMot(&buffer);
        if (j==1)
        {
            dicoInsererMot(buffer, &dico);
            dicoAfficher(dico);

            int x = dicoNbOcc(buffer, dico);
            int y = dicoNbMotsDifferents(dico);
            int z = dicoNbMotsTotal(dico);
            printf("%d\n x=", x);
            printf("%d\n y=", y);
            printf("%d\n z=", z);
        }
            printf('voulez vous inserer un autre mot ?\n');
            scanf("%c", &rep);  
    }*/

    while (rep != 'n')
    {
        if (piocherMot(&buffer))
        {
            dicoInsererMot(buffer, &dico);
            dicoAfficher(dico);
            int z = dicoNbMotsDifferents(dico);
            printf("nbr mot differents =%d", z - 1);
            printf("\n");
            int y = dicoNbMotsTotal(dico);
            printf("nbr mot totale =%d ", y);
        }
        printf("\n voulez-vous inserer un autre mot?\n");
        do
        {
            scanf("%c", &rep);
        } while (rep != 'n' && rep != 'o');
    }
}

/*int main(int argc, char **argv)
{
TArbre dico; 
char buffer[100];
dico = arbreConsVide();
strcpy(buffer, "gallon");
dicoInsererMot(buffer, &dico);
dicoAfficher(dico); 
printf("\n");
strcpy(buffer, "munier");
dicoInsererMot(buffer, &dico);
dicoAfficher(dico); 
printf("\n");
strcpy(buffer, "abenia");
dicoInsererMot(buffer, &dico);
dicoAfficher(dico); printf("\n");
strcpy(buffer, "munier");

dicoInsererMot(buffer, &dico);
dicoAfficher(dico); 
printf("\n");
strcpy(buffer, "mumu");
dicoInsererMot(buffer, &dico);
dicoAfficher(dico); 
printf("\n");
strcpy(buffer, "alpha");
dicoInsererMot(buffer, &dico);
strcpy(buffer, "alphabeta");
dicoInsererMot(buffer, &dico);
strcpy(buffer, "al");
dicoInsererMot(buffer, &dico);
dicoAfficher(dico); printf("\n");
printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa",dico)); printf("\n"); }*/