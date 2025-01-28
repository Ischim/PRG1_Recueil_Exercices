# switch -> if ... else

Soit le programme suivant

~~~cpp
#include <iostream>
using namespace std;

int main() {
   int n; cin >> n;
   
   switch (n) {
      case 0:  cout << "A";
      case 1:
      case 2:  cout << "B";
               break;
      case 3:
      case 4:
      case 5:  cout << "C";
      default: cout << "D";
   }
}
~~~

Que va-t-il afficher lorsque l'utilisateur entre comme valeur 

~~~
0
~~~

<details>
<summary> Ma réponse (Ischim):</summary>

~~~
AB, car on rentre dans le cas 0, on éxécute le cas 0, puis tous le code qui suit jusqu'on trouve un "break;" Qui est à la fin du cas n° 2.
~~~

</details>

<details>
<summary>Solution</summary>

~~~
AB
~~~
</details>

~~~
1
~~~

<details>
<summary> Ma réponse (Ischim):</summary>

~~~
B, car comme précédament on execute le cas n°1 (ici sans code), comme ici pas de break;, on passe au cas n°2 et on sort car il y a un break.
~~~

</details>

<details>
<summary>Solution</summary>

~~~
B
~~~
</details>

~~~
2
~~~

<details>
<summary> Ma réponse (Ischim):</summary>

~~~
B, car comme on rentre dans le cas n°2 et comme il y a un break, on sort du switch.
~~~

</details>

<details>
<summary>Solution</summary>

~~~
B
~~~
</details>

~~~
4
~~~

<details>
<summary> Ma réponse (Ischim):</summary>

~~~
CD, car on execute le code des cas 4-5 et default, car pas de break;
~~~

</details>

<details>
<summary>Solution</summary>

~~~
CD
~~~
</details>

~~~
6
~~~

<details>
<summary> Ma réponse (Ischim):</summary>

~~~
D, car 6 ne correspond à aucun cas spécifié. donc on rentre dans le cas par defaut
~~~

</details>

<details>
<summary>Solution</summary>

~~~
D
~~~
</details>

~~~
-1
~~~

<details>
<summary> Ma réponse (Ischim):</summary>

~~~
D, car -1 ne correspond à aucun cas spécifieé. donc on rentre dans le cas par defaut
~~~

</details>


<details>
<summary>Solution</summary>

~~~
D
~~~
</details>
