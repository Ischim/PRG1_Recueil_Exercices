# Frais de livraison

Une société suisse tarife ses frais de livraison comme suit :

- 5.00 CHF si livraison en Suisse, à l'exception des cantons des Grisons et du Tessin où les frais de livraison se monte à 7.00 CHF
- 7.00 CHF si livraison au Liechtenstein. 
- 10.00 CHF partout ailleurs dans le monde

Complétez le programme qui suit pour qu'il détermine et affiche le tarif de livraison. Il ne peut poser que des questions auxquelles l'utilisateur répond que par "O" (oui) ou "N" (non)

~~~cpp
#include <iostream>

using namespace std;

int main() {
   cout << "Livraison en Suisse ? (O/N) ";
   char reponse1; cin >> reponse1;
   
   // votre code vient ici
  
}
~~~

<details>
<summary>Ma réponse (Ischim):</summary>

~~~cpp
#include <iostream>
#include <cstlib>

using namespace std;

int main() {
   cout << "Livraison en Suisse ? (O/N) ";
   char reponse1; cin >> reponse1;
   
   // votre code vient ici
   const double frais_suisse           5.0;
   const double frais_suisse_exeption  7.0;
   const double frais_liechtenstein    7.0;
   const double frais_monde           10.0;

   double frais_client                 0.0;

    if (reponse1 == 'O' or reponse1 == 'o') {
      cout << "Livraison dans le Tessin "
           << "ou aux Grisson ? (O/N)";
      char reponse2; cin >> reponse2;

      frais_client = (reponse2 == 'O' or reponse2 == 'o') ?
                     frais_suisse_exeption :
                     frais_suisse;
   
   } else {
      cout << "Livraison au Liechtenstein ? (O/N)"
      char reponse2; cin >> reponse2;

   frais_client = (reponse2 == 'O' or reponse2 == 'o') ? 
                  frais_liechenstein : 
                  frais_monde;
   }

   cout << "Pour votre envoi, il y a " << frais_client 
        << " CHF de frais d'envoie." << endl;
}
~~~

</details>


<details>
<summary>Solution</summary>

~~~cpp
#include <iostream>

using namespace std;

int main() {

   const double frais_suisse_sauf_exception =  5.00;
   const double frais_tessin_grison         =  7.00;
   const double frais_liechtenstein         =  7.00;
   const double frais_international         = 10.00;

   double frais; // frais calculés

   cout << "Livraison en Suisse ? (O/N) ";
   char reponse1; cin >> reponse1;

   if (reponse1 == 'O') {
      cout << "Livraison au GR ou TI ? (O/N) ";
      char reponse2; cin >> reponse2;
      frais = (reponse2 == 'O') ?
              frais_tessin_grison :
              frais_suisse_sauf_exception;
   } else {
      cout << "Livraison au Liechtenstein ? (O/N) ";
      char reponse2; cin >> reponse2;
      frais = (reponse2 == 'O') ?
              frais_liechtenstein :
              frais_international;
   }

   cout << "Frais : " << frais << " CHF" << endl;
}
~~~
</details>
