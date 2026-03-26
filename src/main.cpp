
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
  Image objets(moteur, "assets/objets.png");          // Tileset objets
  Image bravo(moteur, "assets/bravo.png");            // Image de victoire
  Image gameover(moteur, "assets/gameover.png");      // Image de defaite

  Dictionnaire dictionnaire("assets/dictionnaire.txt");

  Niveau niveau("assets/niveau.txt", objets, dictionnaire);

  Avatar hero(personnage, 2, 2, BAS, 6, 0);

  Ennemie ennemi1(personnage, 5, 3, BAS, 9, 0);
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

      case DROITE_APPUYE:
        if (!victoire && !defaite) {
          hero.allerDroite(niveau); // Q16 vec collision niveau
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

    // fait avancer les ennemis avec timing
    if (moteur.animationsAmettreAjour() && !victoire && !defaite) {
      ennemi1.avancer(niveau);
      ennemi2.avancer(niveau);
    }

    // teste collision avec les ennemis
    if (!victoire && !defaite) {
      if (hero.touche(ennemi1) || hero.touche(ennemi2)) {
        defaite = true;
      }
    }

    // teste victoire / tous les bonus collectes
    if (!victoire && !defaite) {
      if (niveau.gagne()) {
        victoire = true;
      }
    }

    // III. Generation de l'image a afficher
    moteur.initialiserRendu();

    // affiche le fond
    fond.dessiner(0, 0);

    // affiche le niveau avant les personnages
    niveau.dessiner();

    // affiche les personnages
    hero.display(1, 1);
    ennemi1.display(1, 1);
    ennemi2.display(1, 1);

    // affiche l'ecrans de fin si necessaire
    if (victoire) {
      bravo.dessiner(0, 0);
    } else if (defaite) {
      gameover.dessiner(0, 0);
    }

    moteur.finaliserRendu();

    // attend un peu avant de quitter si fin de partie
    if (victoire || defaite) {
      moteur.attendre(2.0); // Pause de 2 secondes
      quitter = true;
    }
  }

  return 0;
}
