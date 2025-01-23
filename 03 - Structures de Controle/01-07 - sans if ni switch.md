# Sans if ni switch

Réécrivez les extraits de code suivants en n'utilisant ni `if` ni `switch` mais exclusivement des opérateurs de comparaisons et des opérateurs logiques.

~~~cpp
if (i < 1) {
   b = true;
} else {
   b = i > 2;
}
~~~

<details>
<summary> Ma réponse (Ischim):</summary>
~~~cpp
b = (i < 1) or (1 > 2);
~~~
</details>

<details>
<summary>Solution</summary>

~~~cpp
b = (i < 1) or (i > 2);
~~~
</details>

~~~cpp
if (j == 0) {
   b = true;
} else {
   if (i / j < k) {
      b = false;
   } else {
      b = true;
   }
}
~~~

<details>
<summary> Ma réponse (Ischim):</summary>
~~~cpp
b = (j == 0) or !(i/j < k);
b = (j == 0) or  (i/j >= k);
~~~
</details>

<details>
<summary>Solution</summary>

~~~cpp
b = (j == 0) or !(i / j < k);
b = (j == 0) or (i / j >= k);
~~~

</details>

~~~cpp
if (j == 0) {
   b = false;
} else {
   if (i / j < k) {
      b = true;
   } else {
      b = false;
   }
}
~~~

### Table de Vérité
| j == 0 | i/j  < k | b     |
| ------ | -------- | ----- |
| True   | X        | False |
| False  | True     | True  |
| False  | False    | False |

<details>
<summary> Ma réponse (Ischim):</summary>
~~~cpp
b = !(j == 0) and (i/j < k);
~~~
</details>

<details>
<summary>Solution</summary>

~~~cpp
b = (j != 0) and (i / j < k);
~~~

</details>
