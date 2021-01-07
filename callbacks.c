#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "verification.h"
#include "equipement.h"
#include "support.h"
#include "ouvrier.h"
#include "absent.h"
#include "troupeau.h"


void
on_retour_mod_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*modifier;

modifier=lookup_widget(button,"modifier");

gtk_widget_destroy(modifier);
Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_button3_mod_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *aa,*bb,*cc,*vv,*in,*window3;
equipement E;
char id[30];
cc=lookup_widget(button,"combobox2");
vv=lookup_widget(button,"combobox3");
aa=lookup_widget(button,"entry12_id");
bb=lookup_widget(button,"entry13_prix");
in = lookup_widget(button,"input");
strcpy(E.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cc)));
strcpy(E.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(vv)));
strcpy(E.id,gtk_entry_get_text(GTK_ENTRY(aa)));
strcpy(E.prix,gtk_entry_get_text(GTK_ENTRY(bb)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(in)));
modifierr(E,id);
 window3 = create_window3 ();
  gtk_widget_show (window3);
}


void
on_button4_recherche_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *output; 
char id[30];

 int x; 
equipement E;
 input1=lookup_widget(button,"entry12_id"); 
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
 output=lookup_widget(button,"label13");
 x= rechercher(id);
 if(x==1)
 { gtk_label_set_text(GTK_LABEL(output),"equipement existe"); 
}
 else
 { 
gtk_label_set_text(GTK_LABEL(output),"equipement inexistant"); 
}
}


void
on_afficherM_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *Maintenance;
GtkWidget *treeview1;

modifier=lookup_widget(button,"modifier");

gtk_widget_destroy(modifier);
Maintenance=lookup_widget(button,"Maintenance ");
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);

treeview1=lookup_widget(Maintenance,"treeview1");


afficher(treeview1);
}


void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *Maintenance;



Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
ajouter=lookup_widget(button,"ajouter");
  ajouter = create_ajouter ();
  gtk_widget_show (ajouter);




ajouter=lookup_widget(Maintenance,"ajouter");
}



void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *Maintenance;



Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
modifier=lookup_widget(button,"modifier");
  modifier = create_modifier ();
  gtk_widget_show (modifier);




modifier=lookup_widget(Maintenance,"modifier");

}


void
on_button4_eliminer_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *Maintenance;



Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
supprimer=lookup_widget(button,"supprimer");
  supprimer = create_supprimer ();
  gtk_widget_show (supprimer);




supprimer=lookup_widget(Maintenance,"supprimer");
}


void
on_affichercapteur_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
int  jr,mo,an, nb1=0,nb2=0,nb3=0,nb4=0,nb5=0,nb6=0,nb7=0,nb8=0,nb9=0,id ;
float Te;
char nb[10];
char n1[10],n2[10],n3[10],n4[10],n5[10],n6[10],n7[10],n8[10],n9[10];
GtkWidget *treeview2;
GtkWidget *tnb1;
GtkWidget *Maintenance;
GtkWidget *windowcapteur;
FILE *T,*FL ;
T = fopen ("temperature.txt", "r");
FL= fopen ("temp.txt", "a+");
if((FL!=NULL)&&(T!=NULL))
{
while (fscanf(T,"%d %d %d %d %f \n",&id,&jr,&mo,&an,&Te)!=EOF )
{
if (15<Te && Te<40)
{


if (id==1)
 nb1++ ;
if (id==2)
nb2++ ;
if (id==3)
nb3++ ;
if (id==4)
nb4++ ;
if (id==5)
nb5++ ;
if (id==6)
nb6++ ;
if (id==7)
nb7++ ;
if (id==8)
nb8++ ;
if (id==9)
nb9++;
}}
fprintf(FL,"%d %d %d %d %d %d %d %d %d \n",nb1,nb2,nb3,nb4,nb5,nb6,nb7,nb8,nb9);
//while(fscanf(FL,"%s %s %s %s %s %s %s %s %s\n",n1,n2,n3,n4,n5,n6,n7,n8,n9)!=EOF)
//{


  
  fclose(T);

fclose(FL);
}
Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
Maintenance=lookup_widget(button,"Maintenance");
 windowcapteur = create_windowcapteur ();
  gtk_widget_show (windowcapteur);

treeview2=lookup_widget(windowcapteur,"treeview2");
afficherrr(treeview2);


// itoa(nb,nb1,10);
tnb1 = lookup_widget(button, "label24");
gtk_label_set_text(GTK_LABEL(tnb1),n1);
}


void
on_button3_ajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

FILE *f=NULL;
equipement E;
char id[10];

GtkWidget *windowajoute;
GtkWidget *input1, *input2, *input3, *input4 ,*output1,*output2,*output3,*output4;





windowajoute=lookup_widget(button,"windowajoute");


input1=lookup_widget(button,"comboboxentry1");
input2=lookup_widget(button,"combobox1");
input3=lookup_widget(button,"entry10_id");
input4=lookup_widget(button,"entry9_prix");

strcpy(E.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(E.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(E.id,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E.prix,gtk_entry_get_text(GTK_ENTRY(input4)));




output1=lookup_widget(button,"comboboxentry1");
output2=lookup_widget(button,"combobox1");
output3=lookup_widget(button,"label10_id");
output4=lookup_widget(button,"entry9_prix");
ajouter(E);


 windowajoute = create_windowajoute ();
  gtk_widget_show (windowajoute);

}


void
on_button4_afficher_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *Maintenance;
GtkWidget *treeview1;

ajouter=lookup_widget(button,"ajouter");

gtk_widget_destroy(ajouter);
Maintenance=lookup_widget(button,"Maintenance ");
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);

treeview1=lookup_widget(Maintenance,"treeview1");


afficher(treeview1);

}


void
on_retour_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*ajouter;

ajouter=lookup_widget(button,"ajouter");

gtk_widget_destroy(ajouter);
Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_button5_supp_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *window1;
GtkWidget *input;
char id[30];



supprimer=lookup_widget(button,"supprimer");
window1=lookup_widget(button,"window1");

input=lookup_widget(button,"entry15_id");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));



supprimerr(id);
window1 = create_window1 ();
  gtk_widget_show (window1);
}


void
on_retour_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*supprimer;

supprimer=lookup_widget(button,"supprimer");

gtk_widget_destroy(supprimer);
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_afficherS_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *Maintenance;
GtkWidget *treeview1;

supprimer=lookup_widget(button,"supprimer");

gtk_widget_destroy(supprimer);
Maintenance=lookup_widget(button,"Maintenance ");
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);

treeview1=lookup_widget(Maintenance,"treeview1");


afficher(treeview1);

}


void
on_retour_MT_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*supprimer;

window1=lookup_widget(button,"window1");

gtk_widget_destroy(window1);
}


void
on_retour_MA_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajoute,*ajouter;

windowajoute=lookup_widget(button,"windowajoute");

gtk_widget_destroy(windowajoute);
}


void
on_retour_MM_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window3,*modifier;

window3=lookup_widget(button,"window3");

gtk_widget_destroy(window3);
}


void
on_retour_capteur_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance;
GtkWidget *windowcapteur;
windowcapteur=lookup_widget(button,"windowcapteur");

gtk_widget_destroy(windowcapteur);
}


void
on_button3_c_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
admin c;
GtkWidget *nom,*prenom,*password,*numero,*pays,*cin;
GtkWidget *window4 ,*window2;

window4 = create_window4();


nom=lookup_widget(button,"entry9_c");
prenom=lookup_widget(button,"entry10_c");
password=lookup_widget(button,"entry8_c");
numero=lookup_widget(button,"entry12_c");
pays=lookup_widget(button,"entry11_c");
cin=lookup_widget(button,"entry7_c");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(c.numero,gtk_entry_get_text(GTK_ENTRY(numero)));
strcpy(c.pays,gtk_entry_get_text(GTK_ENTRY(pays)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
ajouter_c(c);


window2 = create_window2();
window4=lookup_widget(button,"window4");

gtk_widget_show (window2);
gtk_widget_hide (window4);
}


void
on_button2_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2,*input1,*input2, *output;
  GtkWidget *window5;
FILE *f;
f=fopen("users.txt","r");
char nom[20];
char password[20];
admin c;
window2 = create_window2();
input1=lookup_widget(button,"entry13_c");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1))); 
input2=lookup_widget(button,"entry14_c");
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2))); 
output=lookup_widget(button,"label57_c");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s \n",c.nom,c.prenom,c.password)!=EOF)
{
if ((strcmp(nom,c.nom)==0)&&(strcmp(password,c.password)==0))
{

window2=lookup_widget(button,"window2");
gtk_widget_destroy(window2);
window5=lookup_widget(button,"window5");
window5 = create_window5 ();
  gtk_widget_show (window5);
window5=lookup_widget(window2,"window5");

}
else
gtk_label_set_text(GTK_LABEL(output),"Not Found!");
}
}
}



void
on_button2_creation_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
  GtkWidget *window4;


window2=lookup_widget(button,"window2");

window4=lookup_widget(button,"window4");
window4 = create_window4 ();
  gtk_widget_show (window4);
window4=lookup_widget(window2,"window4");
}


void
on_g_capteurs_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_g_calendrier_clicked                (GtkWidget      *button,
                                        gpointer         user_data)
{

}


void
on_g_ouvrier_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *GestionOuvrier,*window5;

window5=lookup_widget(button,"window5");

gtk_widget_destroy(window5);
GestionOuvrier =create_GestionOuvrier ();
  gtk_widget_show (GestionOuvrier );
}


void
on_g_equipement_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*window5;

window5=lookup_widget(button,"window5");

gtk_widget_destroy(window5);
Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_button27_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*No,*Pr,*Am,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*labelnom,*labelprenom,*labelsexe,*labelcin,*labelnt,*labelmail;
ouvrier o ; 


int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
int b=1;
No = lookup_widget (objet,"entry1");
Pr = lookup_widget (objet,"entry2");
ci = lookup_widget (objet,"entry3");
Am = lookup_widget (objet,"entry5");
Nt = lookup_widget (objet,"entry4");
jour = lookup_widget (objet,"spinbutton4");
mois = lookup_widget (objet,"spinbutton5");
annee = lookup_widget (objet,"spinbutton6");
se = lookup_widget (objet,"combobox5");




strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(Am)));
strcpy(o.num_tl,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }
/*labelnom=lookup_widget(objet,"label277");
labelprenom=lookup_widget(objet,"label278");
labelsexe=lookup_widget(objet,"label279");
labelcin=lookup_widget(objet,"label280");
labelnt=lookup_widget(objet,"label281");
labelmail=lookup_widget(objet,"label282");




// controle saisie
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if(strcmp(o.num_tl,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir votre numéro de téléphone !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}



if(strcmp(o.Mail,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"saisir Mail !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"");
}
if(b==1){*/
Ajouter_no( o);


//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview3");
affi_no(p,"ouvrier.txt");

}

int x;
int t[2]={0,0};
void
on_button28_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Mode jour ");
 else  
strcpy(ch2," Mode nuit ");
 if (t[0]==1)
 strcat(ch3," Groupe B "); 
if(t[1]==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(button, "label113");

gtk_label_set_text(GTK_LABEL(output),ch3);


}

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   {t[0]=1;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 
  {t[1]=1;}  
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
}


/*void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}*/


void
on_button29_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *dd;

char id[20];

dd = lookup_widget (objet,"entry6");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
supp_no(id);

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview3");
affi_no(p,"ouvrier.txt");
}


void
on_button30_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *dd,*Nom,*Prenom,*CIN,*sexe,*jour,*mois,*num_tl,*annee,*Mail;

char id[20];



dd = lookup_widget (button,"entry7");
Nom = lookup_widget(button, "entry8");
Prenom = lookup_widget(button, "entry9");
sexe = lookup_widget(button, "label110");
CIN = lookup_widget (button,"entry10");
num_tl = lookup_widget(button, "entry11");
jour = lookup_widget(button, "spinbutton7");
mois = lookup_widget(button, "spinbutton8");
annee = lookup_widget(button, "spinbutton9");
Mail = lookup_widget(button, "entry12");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

ouvrier o = rechercher_ouvrier(id);




gtk_entry_set_text(GTK_LABEL(Nom),o.NOM);
gtk_entry_set_text(GTK_LABEL(Prenom),o.Prenom);
gtk_label_set_text(GTK_LABEL(sexe),o.sexe);
gtk_entry_set_text(GTK_LABEL(CIN),o.CIN);
gtk_entry_set_text(GTK_LABEL(num_tl),o.num_tl);
gtk_entry_set_text(GTK_LABEL(Mail),o.Mail);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),o.dt_ns.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),o.dt_ns.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),o.dt_ns.annee);*/
}




void
on_button31_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*nt,*am,*se,*jour,*mois,*annee,*dd;
ouvrier o;
char id[20];


dd = lookup_widget (objet_graphique,"entry7");
no = lookup_widget (objet_graphique,"entry8");
pr = lookup_widget (objet_graphique,"entry9");
se = lookup_widget (objet_graphique,"combobox6");
ci = lookup_widget (objet_graphique,"entry10");
nt = lookup_widget (objet_graphique,"entry11");
jour = lookup_widget (objet_graphique,"spinbutton7");
mois = lookup_widget (objet_graphique,"spinbutton8");
annee = lookup_widget (objet_graphique,"spinbutton9");
am = lookup_widget (objet_graphique,"entry12");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.num_tl,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(am)));
modi_no(id,o);

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview3");
affi_no(p,"ouvrier.txt");
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button32_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview3");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *Mail;
        gchar *num_tl;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *sexe;


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,3,&sexe,4,&CIN,5,&num_tl,6,&jour,7,&mois,8,&annee,9,&Mail,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry7")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry8")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry9")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry10")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry11")),num_tl);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry12")),Mail);

		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook1")));//redirection vers la page precedente




         
}
//mise a jour treeview

affi_no(p,"ouvrier.txt");
}



void
on_button33_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview3");;
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_no( id);// supprimer la ligne du fichier
}

}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button34_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affi,*fenetre_affi1 ;
GtkWidget *da;
GtkWidget *treeView4;
char s[20];
int annee;
da = lookup_widget (objet,"entry13");
strcpy(s,gtk_entry_get_text(GTK_ENTRY(da)));
annee=atoi(s);
taux_dab(annee);
treeView4=lookup_widget(objet,"treeview4");
affi_abs(treeView4,"Absent.txt");
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;}
}


void
on_button36_aj_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_troupeau;
GtkWidget *Ajout;


Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
gtk_widget_destroy(Gestion_troupeau);
Ajout=lookup_widget(objet,"Ajout");
Ajout = create_Ajout ();
  gtk_widget_show (Ajout);
Ajout=lookup_widget(Gestion_troupeau,"Ajout");
}


void
on_button38_mod_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_troupeau;
GtkWidget *recherche_et_modifi;


Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
gtk_widget_destroy(Gestion_troupeau);
recherche_et_modifi=lookup_widget(objet,"recherche_et_modifi");
recherche_et_modifi = create_recherche_et_modifi ();
  gtk_widget_show (recherche_et_modifi);
recherche_et_modifi=lookup_widget(Gestion_troupeau,"recherche_et_modifi");
}


void
on_button37_supp_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_troupeau;
GtkWidget *Suppression;


Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
gtk_widget_destroy(Gestion_troupeau);
Suppression=lookup_widget(objet,"Suppression");
Suppression = create_Suppression ();
  gtk_widget_show (Suppression);
Suppression=lookup_widget(Gestion_troupeau,"Suppression");
}


void
on_button39_nbre_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_troupeau;
GtkWidget *nombre_troupeau;


Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
gtk_widget_destroy(Gestion_troupeau);
nombre_troupeau=lookup_widget(objet,"nombre_troupeau");
nombre_troupeau = create_nombre_troupeau ();
  gtk_widget_show (nombre_troupeau);
nombre_troupeau=lookup_widget(Gestion_troupeau,"nombre_troupeau");
}


void
on_button36_jj_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
troupeau t;
char id[20];
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *input1;  
  GtkWidget *input2; 
  GtkWidget *input3;  
  GtkWidget *input4;  
  GtkWidget *input5;  
  GtkWidget *input6;  
  GtkWidget *input7;  
  GtkWidget *radiobutton1;
  GtkWidget *radiobutton2;
  GtkWidget *window6;
  
int a1=0;
int a2=0;
  output1=lookup_widget(objet_graphique,"label126");
  output2=lookup_widget(objet_graphique,"label127");
  radiobutton1=lookup_widget(objet_graphique,"radiobutton3_s"); 
  radiobutton2=lookup_widget(objet_graphique,"radiobutton4_s"); 
  input1=lookup_widget(objet_graphique,"comboboxentry2_ty"); 
  input2=lookup_widget(objet_graphique,"entry14_poids"); 
  input3=lookup_widget(objet_graphique,"spinbutton10_jour"); 
  input4=lookup_widget(objet_graphique,"spinbutton11_mois"); 
  input5=lookup_widget(objet_graphique,"spinbutton12_annee"); 
  input6=lookup_widget(objet_graphique,"entry15_id");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
  {strcpy(t.sexe,"Masculin");;}
  else{
 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
  {strcpy(t.sexe,"Féminin");}}
  strcpy(t.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
  strcpy(t.poids,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(t.jour,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(t.mois,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(t.annee,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(input6)));
  /*if(validerchaine(t.poids)==1)
{
gtk_label_set_text(GTK_LABEL(output1),"correct");
a1=1;
}
else
gtk_label_set_text(GTK_LABEL(output1),"donnée invalide");
if(exist(id)==1)
{
gtk_label_set_text(GTK_LABEL(output2),"id existant");
a2=1;
}
else
{
gtk_label_set_text(GTK_LABEL(output2),"correct");
strcpy(t.id,id);
}

if( a1==1 && a2==1 )*/
  ajouter_troupeau(t);
  window6 = create_window6 ();
  gtk_widget_show (window6); 
}


void
on_button37_afficher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *Gestion_troupeau;
GtkWidget *treeview5;
Ajout=lookup_widget(objet,"Ajout");
gtk_widget_destroy(Ajout);
Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
  Gestion_troupeau = create_Gestion_troupeau ();
  gtk_widget_show (Gestion_troupeau);
treeview5=lookup_widget(Gestion_troupeau,"treeview5");
	afficher_troupeau(treeview5);
}


void
on_button38_ret_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajout;
GtkWidget *Gestion_troupeau;


Ajout=lookup_widget(objet,"Ajout");
gtk_widget_destroy(Ajout);
Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
Gestion_troupeau = create_Gestion_troupeau ();
  gtk_widget_show (Gestion_troupeau);
Gestion_troupeau=lookup_widget(Ajout,"Gestion_troupeau");
}


void
on_button36_suppp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Suppression,*window7;
GtkWidget *entry14;

char id1[20];

Suppression=lookup_widget(objet,"Suppression");

entry14=lookup_widget(objet,"entry14");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry14)));

supprimer_troupeau(id1);
window7 = create_window7 ();
  gtk_widget_show (window7);
}


void
on_button37_rt_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Suppression;
GtkWidget *Gestion_troupeau;


Suppression=lookup_widget(objet,"Suppression");
gtk_widget_destroy(Suppression);
Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
Gestion_troupeau = create_Gestion_troupeau ();
  gtk_widget_show (Gestion_troupeau);
Gestion_troupeau=lookup_widget(Suppression,"Gestion_troupeau");
}


void
on_button36_rech_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id2[20];
troupeau t;
GtkWidget *recherche_et_modifi;
GtkWidget *input1;
GtkWidget *output0, *output1,*output2,*output3,*output4,*output5,*output6,*output7;

input1=lookup_widget(objet,"entry15_rech");
strcpy(id2,gtk_entry_get_text(GTK_ENTRY(input1)));

output0=lookup_widget(objet,"label149");
output1=lookup_widget(objet,"label148");
output2=lookup_widget(objet,"label143");
output3=lookup_widget(objet,"label144");
output4=lookup_widget(objet,"label145");
output5=lookup_widget(objet,"label146");
output6=lookup_widget(objet,"label147");
output7=lookup_widget(objet,"label150");
FILE*f1;

f1=fopen("/home/yahia/Téléchargements/troupeau/projet/troupeau.txt","r");

if (f1!=NULL)
{
while(fscanf(f1,"%s %s %s %s %s %s %s\n",t.sexe,t.poids,t.type,t.jour,t.mois,t.annee,t.id)!=EOF)
{
if(strcmp(t.id,id2)==0)
{

gtk_label_set_text(GTK_LABEL(output0),t.sexe);
gtk_label_set_text(GTK_LABEL(output1),t.poids);
gtk_label_set_text(GTK_LABEL(output2),t.type);
gtk_label_set_text(GTK_LABEL(output3),t.jour);
gtk_label_set_text(GTK_LABEL(output4),t.mois);
gtk_label_set_text(GTK_LABEL(output5),t.annee);
gtk_label_set_text(GTK_LABEL(output6),t.id);


gtk_label_set_text(GTK_LABEL(output7),"");
}



else
gtk_label_set_text(GTK_LABEL(output7),"troupeau introuvable");
}
}




  fclose(f1);
}


void
on_button37_aff_rech_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *recherche_et_modifi;
GtkWidget *Gestion_troupeau;
GtkWidget *treeview;
recherche_et_modifi=lookup_widget(objet,"recherche_et_modifi");
gtk_widget_destroy(recherche_et_modifi);
Gestion_troupeau=lookup_widget(objet,"Gestion_troupeau");
  Gestion_troupeau = create_Gestion_troupeau ();
  gtk_widget_show (Gestion_troupeau);
treeview=lookup_widget(Gestion_troupeau,"treeview5");
	afficher_troupeau(treeview);
}

void
on_button39_mod_rech_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char sexe [20];char type [20];char poids [20];char jour [20];char mois[20];char annee[20];char id [20];
troupeau t;
GtkWidget *input1;  
  GtkWidget *input2; 
  GtkWidget *input3;  
  GtkWidget *input4;  
  GtkWidget *input5;  
  GtkWidget *input6;  
  GtkWidget *input7;  
  GtkWidget *input8; 
  GtkWidget *input9;
  GtkWidget *radiobutton3;
  GtkWidget *radiobutton4;
  GtkWidget *window8;
  radiobutton3=lookup_widget(objet_graphique,"radiobutton3_se"); 
  radiobutton4=lookup_widget(objet_graphique,"radiobutton4"); 
  input1=lookup_widget(objet_graphique,"entry16_poo"); 
  input2=lookup_widget(objet_graphique,"comboboxentry2_tt"); 
  input3=lookup_widget(objet_graphique,"spinbutton10_jj");
  input4=lookup_widget(objet_graphique,"spinbutton11_mm"); 
  input5=lookup_widget(objet_graphique,"spinbutton12_ann"); 
  input6=lookup_widget(objet_graphique,"entry17_iid"); 
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton3))==TRUE)
  {strcpy(t.sexe,"Masculin");}
  else {
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton4))==TRUE)
  {strcpy(t.sexe,"Feminin");}
}
strcpy(t.poids,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(t.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
  strcpy(t.jour,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(t.mois,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(t.annee,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(input6)));
  modifier_troupeau(t.sexe,t.type,t.poids,t.jour,t.mois,t.annee,t.id);
window8 = create_window8 ();
  gtk_widget_show (window8);
}


void
on_button38_ret_mod_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_troupeau;
GtkWidget *recherche_et_modifi;


recherche_et_modifi=lookup_widget(objet,"recherche_et_modifi");
gtk_widget_destroy(recherche_et_modifi);
Gestion_troupeau=lookup_widget(objet,"recherche_et_modifi");
Gestion_troupeau = create_Gestion_troupeau ();
  gtk_widget_show (Gestion_troupeau);

Gestion_troupeau=lookup_widget(Gestion_troupeau,"recherche_et_modifi");
}


void
on_button36_afficher_nbre_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE*f=NULL;
int n=0;
char v[20];
char type[20];
troupeau t;
GtkWidget *output1;
GtkWidget *input1;
input1=lookup_widget(objet,"comboboxentry2"); 
output1=lookup_widget(objet,"label153");
  strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
f=fopen("troupeau.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",t.sexe,t.poids,t.type,t.jour,t.mois,t.annee,t.id)!=EOF){
if(strcmp(t.type,type)==0)
n++;
sprintf(v,"%d",n);
gtk_label_set_text(GTK_LABEL(output1),v);
}
}


void
on_button26_gest_tro_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window5;
GtkWidget *Gestion_troupeau;

window5=lookup_widget(objet,"window5");

gtk_widget_destroy(window5);
Gestion_troupeau = create_Gestion_troupeau ();
  gtk_widget_show (Gestion_troupeau);
}


void
on_button36_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dd,*Nom,*Prenom,*CIN,*sexe,*jour,*mois,*num_tl,*annee,*Mail;

char id[20];



dd = lookup_widget (button,"entry7");
Nom = lookup_widget(button, "entry8");
Prenom = lookup_widget(button, "entry9");
sexe = lookup_widget(button, "label110");
CIN = lookup_widget (button,"entry10");
num_tl = lookup_widget(button, "entry11");
jour = lookup_widget(button, "spinbutton7");
mois = lookup_widget(button, "spinbutton8");
annee = lookup_widget(button, "spinbutton9");
Mail = lookup_widget(button, "entry12");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

ouvrier o = rechercher_ouvrier(id);




gtk_entry_set_text(GTK_LABEL(Nom),o.NOM);
gtk_entry_set_text(GTK_LABEL(Prenom),o.Prenom);
gtk_label_set_text(GTK_LABEL(sexe),o.sexe);
gtk_entry_set_text(GTK_LABEL(CIN),o.CIN);
gtk_entry_set_text(GTK_LABEL(num_tl),o.num_tl);
gtk_entry_set_text(GTK_LABEL(Mail),o.Mail);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),o.dt_ns.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),o.dt_ns.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),o.dt_ns.annee);
}

