#ifndef DEF_ARBRE
#define DEF_ARBRE

struct noeud
{
    int nb;
    char lettre;
    struct noeud *fg;
    struct noeud *fd;
};

typedef struct noeud *TArbre;

TArbre arbreConsVide(void);
int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre a);

#endif