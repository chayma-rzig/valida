#include <stdio.h>
#include "callback.h"  
// Inclure le fichier des callbacks

// Fonction pour ajouter un citoyen dans le fichier
int ajouter(const char *filename, Citoyen c) {
    // Ouvrir le fichier en mode "ajout" (si le fichier n'existe pas, il sera créé)
    FILE *f = fopen(filename, "a");
    
    if (!f) {
        // Si l'ouverture échoue, retourner 0
        return 0;
    }

    // Écrire les données du citoyen dans le fichier au format CSV
    fprintf(f, "%d;%s;%s;%s;%s;%s;%s;%s\n", 
            c.id, c.nom, c.prenom, c.email, c.adresse,
            c.matricule, c.type_de_voiture, c.mot_de_passe);

    // Fermer le fichier après l'écriture
    fclose(f);

    // Retourner 1 pour indiquer le succès
    return 1;
}

