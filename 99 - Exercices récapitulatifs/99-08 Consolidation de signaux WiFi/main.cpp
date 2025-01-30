#include <iostream>
#include <vector>

struct Routeur {
    int intensiteSignal; // Intensité du signal du routeur
};

#include "reponse.cpp"      // votre réponse

int main() {
    Reseau reseau = {
        {{90}, {80}, {70}, {60}},
        {{80}, {70}, {60}, {50}},
        {{70}, {60}, {50}, {40}},
        {{60}, {50}, {40}, {30}},
        {{50}, {40}, {30}, {20}}
    };

    Reseau nouveauReseau = consoliderSignal(reseau);

    // Imprimer le nouveau réseau
    for (size_t i = 0; i < nouveauReseau.size(); i++) {
        for (size_t j = 0; j < nouveauReseau[i].size(); j++) {
            std::cout << nouveauReseau[i][j].intensiteSignal << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}