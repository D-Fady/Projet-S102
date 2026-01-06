#include <vector>

#include "Avatar.h"
#include "Dictionnaire.h"
#include "Ennemie.h"
#include "Image.h"
#include "Moteur.h"
#include "Niveau.h"
#include "Objet.h"
#include "Personnage.h"
#include "Tuile.h"

using namespace std;

int main(int, char **) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // Charger les images
  Image fond(moteur, "assets/fond.png");
  Image personnage(moteur, "assets/personnages.png"); // Spritesheet personnages
  Image objets(moteur, "assets/objets.png");     // Part 3 Q1: Tileset objets
  Image bravo(moteur, "assets/bravo.png");       // Image de victoire
  Image gameover(moteur, "assets/gameover.png"); // Image de defaite

  // Part 3 Q6: Charger le dictionnaire
  Dictionnaire dictionnaire("assets/dictionnaire.txt");

  // Part 3 Q14: Charger le niveau
  Niveau niveau("assets/niveau.txt", objets, dictionnaire);

  // Question 11-12: Creer les personnages avec skin_x et skin_y
  // Chevalier (hero): skin a la colonne 6, ligne 0 de la spritesheet
  Avatar hero(personnage, 2, 2, BAS, 6, 0);

  // Question 22: Ennemis avec directions initiales
  // Ennemi1: patrouille haut/bas, commence vers le bas
  Ennemie ennemi1(personnage, 5, 3, BAS, 9, 0);
  // Ennemi2: patrouille droite/gauche, commence vers la droite
  Ennemie ennemi2(personnage, 7, 5, DROITE, 0, 4);

  bool quitter = false;
  bool victoire = false;
  bool defaite = false;

  // Boucle de jeu
  while (!quitter) {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN) {
      switch (evenement) {
      case QUITTER_APPUYE:
        quitter = true;
        break;

      // Question 19: Connecter les fleches aux methodes de deplacement
      case DROITE_APPUYE:
        if (!victoire && !defaite) {
          hero.allerDroite(niveau); // Part 3 Q16: avec collision niveau
          // Part 3 Q22: Tester bonus apres deplacement
          niveau.testerBonusEtPrendre(hero.getX() / TAILLE_CASE,
                                      hero.getY() / TAILLE_CASE);
        }
        break;

      case GAUCHE_APPUYE:
        if (!victoire && !defaite) {
          hero.allerGauche(niveau);
          niveau.testerBonusEtPrendre(hero.getX() / TAILLE_CASE,
                                      hero.getY() / TAILLE_CASE);
        }
        break;

      case HAUT_APPUYE:
        if (!victoire && !defaite) {
          hero.allerHaut(niveau);
          niveau.testerBonusEtPrendre(hero.getX() / TAILLE_CASE,
                                      hero.getY() / TAILLE_CASE);
        }
        break;

      case BAS_APPUYE:
        if (!victoire && !defaite) {
          hero.allerBas(niveau);
          niveau.testerBonusEtPrendre(hero.getX() / TAILLE_CASE,
                                      hero.getY() / TAILLE_CASE);
        }
        break;

      default:
        break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise a jour de l'etat du jeu

    // Question 24: Faire avancer les ennemis avec timing
    if (moteur.animationsAmettreAjour() && !victoire && !defaite) {
      ennemi1.avancer(niveau);
      ennemi2.avancer(niveau);
    }

    // Question 25: Tester collision avec les ennemis
    if (!victoire && !defaite) {
      if (hero.touche(ennemi1) || hero.touche(ennemi2)) {
        defaite = true;
      }
    }

    // Part 3 Q25: Tester victoire (tous les bonus collectes)
    if (!victoire && !defaite) {
      if (niveau.gagne()) {
        victoire = true;
      }
    }

    // III. Generation de l'image a afficher
    moteur.initialiserRendu();

    // Afficher le fond
    fond.dessiner(0, 0);

    // Part 3 Q14: Afficher le niveau avant les personnages
    niveau.dessiner();

    // Afficher les personnages
    hero.display(1, 1);
    ennemi1.display(1, 1);
    ennemi2.display(1, 1);

    // Afficher ecran de fin si necessaire
    if (victoire) {
      bravo.dessiner(0, 0);
    } else if (defaite) {
      gameover.dessiner(0, 0);
    }

    moteur.finaliserRendu();

    // Part 3 Q26 (optionnel): Attendre un peu puis quitter si fin de partie
    if (victoire || defaite) {
      moteur.attendre(2.0); // Pause de 2 secondes
      quitter = true;
    }
  }

  return 0;
}
