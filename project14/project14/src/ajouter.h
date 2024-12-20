#ifndef AJOUT_H
#define AJOUT_H
typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    char adresse[100];
    char matricule[20];
    char type_de_voiture[30];
    char mot_de_passe[50];
    char date_de_naissance[20]; // Vérifiez que ce nom est correct
    int genre; // 0 pour homme, 1 pour femme
} Citoyen;
// Déclaration de la fonction d'ajout
int ajouter(const char *filename, Citoyen c);


#endif // AJOUT_H

