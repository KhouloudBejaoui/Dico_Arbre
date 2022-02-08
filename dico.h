#ifndef DEF_DICO
#define DEF_DICO
#include "arbre.h"


int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

/* Primitives de gestion d’un dictionnaire */
void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
void afficherElements(char mot[], TArbre a);
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a); 
int dicoNbMotsTotal(TArbre a);

#endif