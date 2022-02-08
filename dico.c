#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));           // initialiser le générateur de nombres aléatoires
    return (rand() % nombreMax); //renvoie d'un nombre au hasard entre 0 et nombreMax
}

int piocherMot(char *motPioche)
{
    FILE *dico = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;

    dico = fopen("dico.txt", "r"); //lecture seule

    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }

    //nombre de mots dans le fichier
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while (caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard

    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    //lire la ligne du mot choisi
    fgets(motPioche, 100, dico);

    //vire le \n à la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1;
}

/*void dicoAfficher(TArbre a)
{
    if (arbreEstVide(a) == 0)
        printf("arbre vide");

    else
    {
        // printf("%c", (a->lettre));
        printf("123");
        //dicoAfficher((a->fg));
    }
    //dicoAfficher((a->fd));
}*/
void afficherElements(char mot[], TArbre a)
{
    char end = '\0';

    if (a != NULL)
    {
        if (arbreRacineLettre(a) != end)
        {
            if (a->fg != NULL)
            {
                afficherElements(mot, a->fd);
            }
            if (a->fg != NULL)
            {
                strcat(mot, (char[2]){arbreRacineLettre(a), end});
                afficherElements(mot, arbreFilsGauche(a));
            }
            mot[strlen(mot) - 1] = end;
        }
        else
        {
            printf("\"%s\"\n", mot);
            if (a->fd != NULL)
                afficherElements(mot, arbreFilsDroit(a));
        }
    }
}

void dicoAfficher(TArbre a)
{
    printf("\nListe des mots:\n");
    char mots[255] = "";
    afficherElements(mots, a);
}

/*void dicoInsererMot(char mot[], TArbre *a)
{
    int i = 0;
    TArbre r, p;
    r = (TArbre)malloc(sizeof(struct noeud));
    p = (TArbre)malloc(sizeof(struct noeud));

    if (arbreEstVide(*a) == 0)
    {

        (*a) = arbreCons(mot[0], 0, NULL, NULL);
        p = *a;
        printf("%c", (p)->lettre);

        while (i <= strlen(mot))
        {
            if (i == strlen(mot))
            {
                (*a) = arbreCons('\0', 1, NULL, NULL);
            }
            else
            {
                r = arbreCons(mot[i], 0, NULL, NULL);
                (*a)->fg = r;
            }
            i++;
        }
        // p=p->fg;
        printf("%c", (p)->fg->lettre);
    }

    else
    {
        while (((*a)->lettre) != mot[0] && ((*a)->fd) != NULL)
        {
            (*a) = arbreFilsDroit(*a);
        }

        if ((*a)->fd == NULL)
        {
            (*a) = arbreCons(mot[0], 0, NULL, NULL);
            while (i <= strlen(mot))
            {
                if (i == strlen(mot))
                {
                    (*a) = arbreCons('\0', 1, NULL, NULL);
                    *a = arbreFilsGauche(*a);
                }
                else
                {
                    (*a) = arbreCons(mot[i], 0, NULL, NULL);
                    *a = arbreFilsGauche(*a);
                }
                i++;
            }
        }
        else
        {
            i = 1;
            while (((*a)->lettre) == mot[i] && ((*a)->fg) != NULL)
            {

                if (i == strlen(mot) && ((*a)->fg) != '\0')
                {
                    r = arbreFilsGauche(*a);
                    (*a)->fg = arbreCons('\0', 0, NULL, r);
                }
                else
                {
                    (*a) = arbreFilsGauche(*a);
                    i++;
                }
            }
            if ((*a)->lettre != mot[i])
            {
                (*a) = arbreCons(mot[i], 0, NULL, NULL);
                while (i <= strlen(mot))
                {
                    if (i == strlen(mot))
                    {
                        (*a) = arbreCons('\0', 1, NULL, NULL);
                        *a = arbreFilsGauche(*a);
                    }
                    else
                    {
                        (*a) = arbreCons(mot[i], 0, NULL, NULL);
                        *a = arbreFilsGauche(*a);
                    }
                    i++;
                }
            }
            else
            {
                ((*a)->nb)++;
            }
        }
    }
}*/

int dicoNbOcc(char mot[], TArbre a)
{
    int nb, i = 0;

    if (arbreEstVide(a) == 0)
    {
        return 0;
    }
    while (i <= strlen(mot))
    {
        if ((a->lettre == mot[i]))
        {
            a = a->fg;
            i++;
        }
        else
        {
            return 0;
        }

        if (i == strlen(mot))
        {
            nb = a->nb;
        }
        else
        {
            if ((a->lettre) == '\0')
            {
                a = a->fd; //chercher
            }
        }
    }
}

int dicoNbMotsDifferents(TArbre a)
{
    char end = '\0';
    if (!arbreEstVide(a))
    {
        if (arbreRacineLettre(a) == end)
        {
            return 1 + dicoNbMotsDifferents(arbreFilsGauche(a)) + dicoNbMotsDifferents(arbreFilsDroit(a));
        }

        return dicoNbMotsDifferents(arbreFilsGauche(a)) + dicoNbMotsDifferents(arbreFilsDroit(a));
    }
    else
    {
        return 0;
    }
}

int dicoNbMotsTotal(TArbre a)
{
    int nb = 0;
    if (arbreEstVide(a) == 0)
    {
        return 0;
    }
    else
    {
        if (a->lettre == '\0')
        {
            nb = nb + a->nb;
        }
    }
    return nb + dicoNbMotsTotal(a->fg) + dicoNbMotsTotal(a->fd);
}

void dicoInsererMot(char mot[], TArbre *pa)
{
    char end = '\0';
    if (*pa != NULL)
    {
        if (mot[0] != end)
        {
            if ((*pa)->lettre == mot[0])
            {
                mot++;
                dicoInsererMot(mot, &((*pa)->fg));
            }
            else
            {
                if ((*pa)->fd != NULL)
                {
                    dicoInsererMot(mot, &((*pa)->fd));
                }
                else
                {
                    (*pa)->fd = arbreCons(mot[0], 0, NULL, NULL);
                    dicoInsererMot(mot, &(*pa));
                }
            }
        }
        else if ((*pa)->lettre != end && mot[0] == end)
        {
            TArbre a = arbreCons(end, 1, NULL, *pa);
            *pa = a;
        }
        else if ((*pa)->lettre == end && mot[0] == end)
        {
            (*pa)->nb = (*pa)->nb + 1;
        }
    }
    else
    {
        if (mot[0] != end)
        {
            *pa = arbreCons(mot[0], 0, NULL, NULL);
            mot++;
            dicoInsererMot(mot, &((*pa)->fg));
        }
        else
        {
            *pa = arbreCons(end, 1, NULL, NULL);
        }
    }
}