//
// Created by ischi on 30.01.2025.
//

#include <vector>

using Reseau = std::vector<std::vector<Routeur>>;

Reseau consoliderSignal(const Reseau& res) {
    Reseau new_res;
    for(size_t l = 0; l < res.size(); l += 2) {
        std::vector<Routeur> new_ligne;

        for(size_t c = 0; c < res[l].size(); c += 2) {
            // cas par défault
            int totalSignal = res[l][c].intensiteSignal;
            int compteur = 1;

            // cas ligne + 1
            if ( l + 1 < res.size()) {
                totalSignal = res[l+1][c].intensiteSignal;
                ++compteur;
            }

            // cas colonne + 1
            if ( c + 1 < res[l].size()) {
                totalSignal = res[l][c+1].intensiteSignal;
                ++compteur;
            }

            // cas colonne + 1 & ligne +1
            if ( c + 1 < res[l].size() and l + 1 < res.size()) {
                totalSignal = res[l+1][c+1].intensiteSignal;
                ++compteur;
            }

            new_ligne.push_back({(totalSignal / compteur)});
        }
        new_res.push_back(new_ligne);
    }
    return new_res;
}