#include <gtk/gtk.h>
int m,k;

typedef struct
{
    int jour;
    int mois;
    int annee;

}Date;

typedef struct 
{ 
char id[200] ; 
char NOM[200];
char Prenom[200];
char CIN[200];
char Mail[200];
char num_tl[200];
char sexe[200];
Date dt_ns;

}ouvrier;

void Ajouter_no(ouvrier o);
void supp_no(char id[]);
void modi_no(char id[],ouvrier o);
ouvrier rechercher_ouvrier(char id[]);
void affi_no(GtkWidget* treeview1,char*l);

 





