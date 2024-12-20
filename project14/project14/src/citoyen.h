// citoyen.h
#ifndef CITOYEN_H
#define CITOYEN_H

// Définir la structure Citoyen
typedef struct {
    int id;
    char nom[100];
    char prenom[100];
    char email[100];
    char adresse[100];
    char matricule[100];
    char type_de_voiture[100];
    char mot_de_passe[100];
    char datedenaissance[20];  // Format de date à ajuster selon vos besoins
} Citoyen;

#endif // CITOYEN_H

