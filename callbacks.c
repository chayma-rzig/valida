#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fcitoyen.h"

int y;
int y1;
// Fonction appelée lors du clic sur le bouton radio "Homme"
void on_radiobuttonhomme_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;} 

}

// Fonction appelée lors du clic sur le bouton radio "Femme"
void on_radiobuttonfemme_toggled(GtkToggleButton *togglebutton, gpointer user_data) {
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;} 

}

// Fonction appelée lors du clic sur le bouton "Ajouter"

void on_buttonAjouter_clicked(GtkWidget *objet, gpointer user_data) {
GtkWidget *day,*month,*year,*ca,*cb,*ty,*se,*da,*po,*nbr,*valid,*cn,*labelnom,*labelprenom,*labelid,*labelmdp,*labelemail;
valid=lookup_widget(objet,"buttonAjouter");
Citoyen A ;
int i;
int dayy;
int monthh;
int yearr;
char day1[10];
char month1[10];
char year1[10];

int b=1;

ty = lookup_widget (objet,"entrynom");
se = lookup_widget (objet,"entryprenom");
da = lookup_widget (objet,"entryID");
po = lookup_widget (objet,"entrymdp");
nbr = lookup_widget (objet,"entryadresse");
cn = lookup_widget (objet,"entryemail");
ca = lookup_widget (objet,"entrymatricule");
cb = lookup_widget (objet,"entrytype");
day = lookup_widget (objet,"day");
month = lookup_widget (objet,"month");
year = lookup_widget (objet,"year");




strcpy(A.nom,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.prenom,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.id,gtk_entry_get_text(GTK_ENTRY(da)));

dayy=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
monthh=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
yearr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));

strcpy(A.adresse,gtk_entry_get_text(GTK_ENTRY(nbr)));
strcpy(A.email,gtk_entry_get_text(GTK_ENTRY(cn)));
strcpy(A.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(po)));
strcpy(A.matricule,gtk_entry_get_text(GTK_ENTRY(ca)));
strcpy(A.type_de_voiture,gtk_entry_get_text(GTK_ENTRY(cb)));


snprintf(day1, sizeof(day1), "%02d", dayy);
snprintf(month1, sizeof(month1), "%02d", monthh);
snprintf(year1, sizeof(year1), "%02d", yearr);

snprintf(A.date_de_naissance, sizeof(A.date_de_naissance), "%s/%s/%s", day1, month1, year1);


labelnom=lookup_widget(objet,"labelnomm");
labelprenom=lookup_widget(objet,"labelprenomm");
labelid=lookup_widget(objet,"labelidm");
labelmdp=lookup_widget(objet,"labelmdpm");
labelemail=lookup_widget(objet,"labelemailm");

if (y==1) 
strcpy(A.sexe,"Homme");
 if (y==2) 
strcpy(A.sexe,"Femme");


if(strcmp(A.nom,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir nom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(A.prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prenom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}

if(strcmp(A.id,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelid),"saisir id !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelid),"");
}
if(strcmp(A.mot_de_passe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmdp),"saisir mot de passe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmdp),"");
}
if(strcmp(A.email,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelemail),"saisir E-mail !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelemail),"");
}




if(b==1){
ajouter("citoyen.txt",A);
// Vider les champs du formulaire
        gtk_entry_set_text(GTK_ENTRY(ty), "");
        gtk_entry_set_text(GTK_ENTRY(se), "");
        gtk_entry_set_text(GTK_ENTRY(da), "");
        gtk_entry_set_text(GTK_ENTRY(po), "");  
        gtk_entry_set_text(GTK_ENTRY(nbr), "");
        gtk_entry_set_text(GTK_ENTRY(cn), "");
        gtk_entry_set_text(GTK_ENTRY(ca), "");
        gtk_entry_set_text(GTK_ENTRY(cb), "");
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(day), 0);  // Réinitialiser les spin buttons
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(month), 0);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(year), 0);

        // Afficher un message de succès (facultatif)
        GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
                                                  GTK_BUTTONS_CLOSE, "Citoyen ajouté avec succès");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);}
 else {
        // Afficher un message d'erreur (facultatif)
        
    }
}




void
on_radiobuttonfemme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y1=2;} 

}
//modifier

void
on_buttonmodifier_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *day,*month,*year,*ca,*cb,*ty,*se,*da,*po,*nbr,*valid,*cn,*labelnom,*labelprenom,*labelid,*labelmdp,*labelemail;

char idd [20] ;
Citoyen A ;

int dayy;
int monthh;
int yearr;
char day2[10];
char month2[10];
char year2[10];

ty = lookup_widget (objet,"entrynom1");
se = lookup_widget (objet,"entryprenom1");
da = lookup_widget (objet,"entryID1");
po = lookup_widget (objet,"entrymotdepasse1");
nbr = lookup_widget (objet,"entryadresse1");
cn = lookup_widget (objet,"entryemail1");
ca = lookup_widget (objet,"entrymatricule1");
cb = lookup_widget (objet,"entrytypedevoiture1");
day = lookup_widget (objet,"day1");
month = lookup_widget (objet,"month1");
year = lookup_widget (objet,"year1");



strcpy (A.sexe,"");
if (y1==1) 
strcpy(A.sexe,"Homme");
 if (y1==2) 
strcpy(A.sexe,"Femme");


strcpy(idd,gtk_entry_get_text(GTK_ENTRY(da)));
strcpy(A.id,gtk_entry_get_text(GTK_ENTRY(da)));
strcpy(A.nom,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.prenom,gtk_entry_get_text(GTK_ENTRY(se)));

dayy=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
monthh=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
yearr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));

strcpy(A.adresse,gtk_entry_get_text(GTK_ENTRY(nbr)));
strcpy(A.email,gtk_entry_get_text(GTK_ENTRY(cn)));
strcpy(A.mot_de_passe,gtk_entry_get_text(GTK_ENTRY(po)));
strcpy(A.matricule,gtk_entry_get_text(GTK_ENTRY(ca)));
strcpy(A.type_de_voiture,gtk_entry_get_text(GTK_ENTRY(cb)));

snprintf(day2, sizeof(day2), "%02d", dayy);
snprintf(month2, sizeof(month2), "%02d", monthh);
snprintf(year2, sizeof(year2), "%02d", yearr);

snprintf(A.date_de_naissance, sizeof(A.date_de_naissance), "%s/%s/%s", day2, month2, year2);
 // **Clear modification form fields**
    gtk_entry_set_text(GTK_ENTRY(ty), "");
    gtk_entry_set_text(GTK_ENTRY(se), "");
    gtk_entry_set_text(GTK_ENTRY(da), "");
    gtk_entry_set_text(GTK_ENTRY(po), "");  // Clear password field too
    gtk_entry_set_text(GTK_ENTRY(nbr), "");
    gtk_entry_set_text(GTK_ENTRY(cn), "");
    gtk_entry_set_text(GTK_ENTRY(ca), "");
    gtk_entry_set_text(GTK_ENTRY(cb), "");
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(day), 0);  // Reset spin buttons
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(month), 0);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(year), 0);
   
 

modifier("citoyen.txt", idd, A);
// Assuming successful modification:
GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
                                           GTK_BUTTONS_CLOSE, "Citoyen modifié avec succès");
gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);


}
//supression
void
on_buttonsuprimer_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd;

char idd[50];

dd = lookup_widget (objet_graphique,"comboboxentry1");
strcpy(idd,gtk_combo_box_get_active_text(GTK_COMBO_BOX(dd)));
           
  
 supprimer("citoyen.txt",idd);
 // Afficher un message de confirmation
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
                                              GTK_BUTTONS_CLOSE, "Citoyen supprimé avec succès");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);	
}


//affichage
void
on_buttonafficher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p,*dd;
	p=lookup_widget(objet,"treeview1");
	char idd[50];

	dd = lookup_widget (objet,"entryID3");
	strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));	
    gchar *id;
    gchar *nom;
    gchar *prenom;
    gchar *sexe;
    gchar *date_de_naissance;
    gchar *adresse;
    gchar *email;
    gchar *mot_de_passe;
    gchar *matricule;
    gchar *type_de_voiture;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&prenom,3,&sexe,4,&date_de_naissance,5,&adresse,6,&email,7,&mot_de_passe,8,&matricule,9,&type_de_voiture,-1);
  	
               	
}
afficher(p ,"citoyen.txt",idd);
}

//facture
void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *labeltot,*dd;

char idd[50];
char tot_str[50];

labeltot=lookup_widget(objet_graphique,"tot");

dd = lookup_widget (objet_graphique,"entryID4");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));	

    float tot=calculer_facture("facture.txt",idd);

   snprintf(tot_str, sizeof(tot_str), " Votre facture est: %.2f TND", tot);
gtk_label_set_text(GTK_LABEL(labeltot),tot_str);	
}


void
on_radiobuttonhomme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y1=1;} 

}

//actuliser bouton
void
on_actualiser_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *comboboxent;
    Citoyen nouv;
    comboboxent = lookup_widget(button, "comboboxentry1");

    // Open the file for reading
    FILE *f = fopen("citoyen.txt", "r");
    if (f != NULL) {
        // Loop through each entry in the file
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s\n",
                      nouv.id, nouv.nom, nouv.prenom, nouv.date_de_naissance, nouv.adresse,
                      nouv.email, nouv.mot_de_passe, nouv.sexe, nouv.matricule, nouv.type_de_voiture) != EOF) {
            // Check if the ID already exists in the combo box
            gboolean id_exists = FALSE;
            GSList *items = gtk_combo_box_get_model(GTK_COMBO_BOX(comboboxent)); 
            GtkTreeIter iter;
            // Iterate through the model to check if the ID exists
            if (gtk_tree_model_get_iter_first(GTK_TREE_MODEL(items), &iter)) {
                do {
                    gchar *existing_id;
                    gtk_tree_model_get(GTK_TREE_MODEL(items), &iter, 0, &existing_id, -1);
                    if (g_strcmp0(existing_id, nouv.id) == 0) {
                        id_exists = TRUE;
                        g_free(existing_id);  // Free the existing ID string
                        break;
                    }
                    g_free(existing_id);  // Free the existing ID string
                } while (gtk_tree_model_iter_next(GTK_TREE_MODEL(items), &iter));
            }

            // Append the ID only if it does not exist in the ComboBox
            if (!id_exists) {
                gtk_combo_box_append_text(GTK_COMBO_BOX(comboboxent), nouv.id);
            }
        }

        fclose(f);
    }
}

