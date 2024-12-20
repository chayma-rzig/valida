#ifndef FCITOYEN_H
#define FCITOYEN_H
#include <stdio.h>
#include <string.h>
#include<gtk/gtk.h>

typedef struct {
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
} Citoyen;

typedef struct {
    char id_citoyen[50];
    char id_parking[50];
    int nb_jours;
    float tarif_par_jour;
    float services;
    float reduction;
} Facture;

int ajouter(char citoyen [], Citoyen c);
int modifier(char *filename, char * id, Citoyen nouv);
int supprimer(char *filename, char * id);
void afficher(GtkWidget *treeview1, char*l,char * idd);
float calculer_facture(char *filename, char * idd);

#endif


