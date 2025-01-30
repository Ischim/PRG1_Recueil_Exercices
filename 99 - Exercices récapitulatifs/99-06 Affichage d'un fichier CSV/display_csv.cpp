//
// Created by ischi on 30.01.2025.
//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "display_csv.h"


using namespace std;

void display_csv(const std::string& file_name, char separator, int width) {
    ifstream input_file (file_name);

    if(!input_file) throw File_not_found();

    string line;
    while(getline(input_file,line)) {
        stringstream s(line);
        string element;
        while (getline(s,element, separator)) {
            cout << setw(width) << right << element;
            //  right car si on est dans un autre programme,
            //  on a une modification pour mettre à gauche,
            //  il faut alors s'assurer pour cette étape l'alignement soit à droite
            //  alternative, faire un back-up du flux en amont dans la fonction, et paramétrer le flux
            //  puis le restorer avant de quitter la fonction
        }
        cout << endl;
    }
    input_file.close();
}
