#include <stdio.h>
#include <stdlib.h>
#include "fcitoyen.h"
#include <string.h>
#include <gtk/gtk.h>

int ajouter(char citoyen [], Citoyen c) {
    FILE *f = fopen(citoyen, "a");
    if (f != NULL) {
        fprintf(f, "%s %s %s %s %s %s %s %s %s %s\n",
                c.id, c.nom, c.prenom, c.date_de_naissance, c.adresse,
                c.email, c.mot_de_passe, c.sexe, c.matricule, c.type_de_voiture);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(char *filename, char * id, Citoyen nouv)
{
Citoyen c;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("temp.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s\n",
                      c.id, c.nom, c.prenom, c.date_de_naissance, c.adresse,
                      c.email, c.mot_de_passe, c.sexe, c.matricule, c.type_de_voiture) != EOF)
        {
            if(strcmp(c.id,id)!=0)
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s\n",
                        c.id, c.nom, c.prenom, c.date_de_naissance,
                        c.adresse, c.email, c.mot_de_passe, c.sexe,
                        c.matricule, c.type_de_voiture);
            } else {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s\n",
                        nouv.id, nouv.nom, nouv.prenom, nouv.date_de_naissance, nouv.adresse,
                        nouv.email, nouv.mot_de_passe, nouv.sexe, nouv.matricule, nouv.type_de_voiture);
        }           }
        
        fclose(f);
        fclose(f2);

        remove(filename);
        rename("temp.txt", filename);
}
    return 1;
}


int supprimer(char *filename, char * id)
{
Citoyen c;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("temp.txt", "w+");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s\n",
                      c.id, c.nom, c.prenom, c.date_de_naissance, c.adresse,
                      c.email, c.mot_de_passe, c.sexe, c.matricule, c.type_de_voiture) != EOF)        

{
if (strcmp(c.id,id)!=0) 
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s\n",
                        c.id, c.nom, c.prenom, c.date_de_naissance, c.adresse,
                        c.email, c.mot_de_passe, c.sexe, c.matricule, c.type_de_voiture);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("temp.txt", filename);
        return 1;
    }
}

void afficher( GtkWidget *treeview1, char*l, char * idd) {




GtkListStore *adstore;/*creation du modele de type liste*/
adstore=NULL;
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/

FILE *f;
adstore=gtk_tree_view_get_model(treeview1);



    char id[20];
    char nom[50];
    char prenom[50];
    char sexe[50];
    char date_de_naissance[20];
    char adresse[100];
    char email[50];
    char mot_de_passe[50];
    char matricule[20];
    char type_de_voiture[50];
    int k=0;

     
     

	/* Creation de la 1ere colonne */
	if(adstore==NULL)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("date_de_naissance",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("adresse",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("email",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);

	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mot_de_passe",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);

	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("matricule",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);

	/* Ajouter la 10emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 10eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type_de_voiture",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	}
   /* Creation du modele */
        adstore = gtk_list_store_new(10,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING);
   /* Insertion des elements */
        f=fopen(l,"r");
while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s\n",
                      id, nom, prenom, date_de_naissance, adresse,
                      email, mot_de_passe, sexe, matricule, type_de_voiture) != EOF)
        {if (strcmp(id, idd) == 0){ GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,nom,
                            2,prenom,
                            3,sexe,
                            4,date_de_naissance,
			    5,adresse,
			    6,email,
		 	    7,mot_de_passe,
			    8,matricule,
			    9,type_de_voiture,
                            -1);}}
        fclose(f);


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
g_object_unref(adstore);
}






float calculer_facture(char *filename, char * idd) {
    Facture c;
    float tot;
    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        while (fscanf(f, "%s %s %d %f %f %f\n",
                      c.id_citoyen, c.id_parking, &c.nb_jours, &c.tarif_par_jour, &c.services,
                      &c.reduction) != EOF) {
            if (strcmp(c.id_citoyen,idd)==0) {
		tot=(((c.nb_jours * c.tarif_par_jour) - c.reduction) + c.services);
                break;
            }
        }
        fclose(f);
    }
    return tot;
}


