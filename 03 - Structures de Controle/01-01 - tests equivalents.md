# Tests équivalents ? 

Les deux extraits de code suivants sont-ils équivalents ? Justifiez votre réponse.

~~~cpp 
if (prixActuel > 100) {
   nouveauPrix = prixActuel - 20;
} else {
   nouveauPrix = prixActuel - 10;
}
~~~

~~~cpp 
if (prixActuel < 100) {
   nouveauPrix = prixActuel - 10;
} else {
   nouveauPrix = prixActuel - 20;
}
~~~

<details>
<summary> Ma réponse (Ischim):</summary>
~~~cpp
/* Dans le premier, si prix actuel vaut cent, il y a une réduction de 10
 * Alors que dans le 2ème, se serait une réduction de 20.
 * 
 * Donc elle ne sont pas équivalent, cependant si dans la deuxième on mettait <= 100 elle serait équivalente
 */
~~~
</details>

<details>
<summary>Solution</summary>
Non, si prixActuel == 100, la valeur de nouveauPrix diffère. 
</details>