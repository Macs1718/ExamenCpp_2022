# Examen C++ 2022

## Exercice 1 : Quaternions

Les quaternions sont des une "généralisation" des nombres complexes où le produit n'est plus une loi commutative.
L'ensemble des quaternions est engendré à partir des réels à partir de trois éléments *i*, *j* et *k* tels que

    i² = j² = k² = ijk = -1

ce qui permet de déduire les relations suivantes (utiles pour programmer les quaternions) :

    i² = -1     ij = k     ik = -j
    ji = -k     j² = -1    jk =  i
    ki =  j     kj = -i    k² = -1

et un quaternion s'écrit sous la forme :

    q = a + b.i + c.j + d.k avec a,b,c,d ∈ R⁴

On a donc pour la multiplication :

    q₁q₂ = (a₁ + b₁.i + c₁.j + d₁.k).(a₂ + b₂.i + c₂.j + d₂.k)
         = (a₁a₂-b₁b₂-c₁c₂-d₁d₂)   + (a₁b₂+b₁a₂+c₁d₂-d₁c₂).i +
           (a₁c₂+c₁a₂+d₁b₂-b₁d₂).j + (a₁d₂+d₁a₂+b₁c₂-c₁b₂).k 

On appelle partie réelle de *q* le scalaire *a*, et la partie "imaginaire pur" le nombre *b.i + c.j + d.k*.

On appelle conjugué de *q* le nombre *q** *= a - b.i - c.j - d.k*

On a la relation *(q₁q₂)** = *q₂** *q₁**

Le nombre réel ∥q∥ défini par

    ∥q∥² = a² + b² + c² + d²

est appelé **norme** de *q*.  

On peut montrer que pour tout quaternion non nul, il existe un inverse pour la multiplication qui est égal à :

    q⁻¹= (1/∥q∥²) q*

Ecrire et testez une classe quaternion dont les quatre réels peuvent être représentés par des entiers ou des réels simple ou double précision avec laquelle on peut :

    - Additionner ou soustraire deux quaternions
    - Multiplier deux quaternions 
    - Calcul le conjugué d'un quaternion
    - Inverser un quaternion

Exercice 2 : Embryon de calcul formel

On veut créer un embryon d'un logiciel faisant du calcul formel.

L'idée est de créer des "foncteurs", c'est à dire des classes représentant des opérations ou des fonctions mathématiques (addition, multiplication, constante, cosinus, etc. ), de pouvoir les évaluer pour un *x* donné, mais aussi de les dérivées et de pouvoir afficher sur console la fonction.

Pour cet exercice, nous allons créer quatre foncteurs :

- Le foncteur Variable qui représente le paramètre *x*
- Le foncteur Constante qui représente une constante réelle 
- Le foncteur Addition qui représente l'addition de deux foncteurs. On redéfinira l'opérateur + pour alléger l'écriture de cette addition : f1 + f2 sera donc équilvalent à écrire

        std::make_shared<Addition>(f1, f2)

    où f1 et f2 seront des pointeurs partagés sur deux foncteurs déjà définis.
- Le foncteur Multiplication qui représente la multiplication de deux foncteurs. Là encore, on redéfinira de même que pour l'addition l'opérateur * pour alléger l'écriture de cette multiplication

Le fichier **formelle.cpp** est un exemple d'utilisation de cette bibliothèque.

Quelle relation objet relie les quatre foncteurs ainsi définis ?

Expliquer quel est l'intérêt de manipuler ces foncteurs via un pointeur (ici partagé, mais ce n'est pas obligatoire) plutôt que de les manipuler directement ?

Complèter le code afin de faire marcher le programme principal que vous trouverez dans **formelle.cpp**

Nota Bene : Pour faciliter la lecture des fonctions et de leurs dérivées, il est conseillé 
d'afficher des parenthèses pour bien définir les priorités entre la multiplication et l'addition. Par exemple, si on définit f comme : 3*x + 2, on affichera f à l'écran comme :

    ((3*x)+2)
