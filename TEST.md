# 🐣 S1 | Prog: Workshop

## ⭐⭐ Image Bruitée

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/logo.png) | ![Image modifiée](images/resultat/noise.png) |

📁 [Code source](src/noise/main.cpp)

### Description
Dans cet exercice, un effet aléatoire de couleur (bruit) a été appliqué à l'image. Chaque pixel de l'image a été modifié en assignant une couleur aléatoire. Pour ce faire, les composantes R (rouge), G (vert) et B (bleu) de chaque pixel ont été remplacées par des valeurs aléatoires comprises entre 0 et 1.

### Spécificités
- Utilisation d'une fonction de génération de nombres aléatoires

<br>

## ⭐⭐ Rotation de 90°

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/logo.png) | ![Image modifiée](images/resultat/rotate_90.png) |

📁 [Code source](src/rotate_90/main.cpp)

### Description
Dans cet exercice, une rotation de l'image originale à 90 degrés dans le sens horaire a été effectuée. L'algorithme utilise une approche de manipulation des pixels pour réaliser cette rotation.

### Spécificités
- Parcourir chaque pixel de l'image d'origine et le placer dans une nouvelle image avec des coordonnées modifiées pour effectuer la rotation.
- L'implémentation de la rotation se fait en échangeant les coordonnées x et y des pixels entre l'image d'origine et la nouvelle image résultante.
- Une seconde méthode, actuellement commentée dans le code, utilise une autre approche par inversion des colonnes après avoir effectué la rotation en utilisant la fonction : `std::swap`

### Pièges potentiels à éviter
- Oublier le `-1`. Il permet de tourner l'image dans le sens anti-horaire comme souhaité.
```cpp
    voidImage.pixel(voidImage.width() - 1 - y, x) = image.pixel(x, y);
```

<br>

## ⭐⭐ RGB Split

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/logo.png) | ![Image modifiée](images/resultat/rgb_split.png) |

📁 [Code source](src/rgb_split/main.cpp)

### Description
Dans cet exercice, un effet de séparation des canaux RGB (RGB split) a été appliqué à l'image. L'algorithme modifie les canaux Rouge (R), Vert (G), et Bleu (B) de l'image pour créer une version où chaque canal est décalé par rapport aux autres.

### Spécificités
- Trois boucles distinctes sont utilisées pour traiter séparément les composantes Rouge, Vert et Bleu de chaque pixel de l'image.
- Pour chaque composante de couleur, une boucle spécifique effectue un décalage des pixels à gauche ou à droite en fonction du canal (R, G ou B) tout en conservant les autres canaux.

### Pièges potentiels à éviter
- Ne pas oublier de décaler les valeurs de pixels

<br>

## ⭐⭐ Luminosité

| Après Assombrissement | Avant | Après Eclaircissement |
| --- | :-: |  --: |
| ![Image modifiée sombre](images/resultat/sombre.png) | ![Image d'origine](images/photo.jpg) | ![Image modifiée claire](images/resultat/clair.png) |

📁 [Code source](src/luminosite/main.cpp)

### Description
Dans cet exercice, un effet d'assombrissement ou d'éclaircissement de l'image a été appliqué en utilisant une variable `number`. Cette variable est utilisée pour modifier la puissance des canaux Rouge (R), Vert (G) et Bleu (B) de chaque pixel de l'image.

### Spécificités
- Une boucle parcourt chaque pixel de l'image et ajuste la valeur de chaque composante de couleur en fonction de la valeur de `number`.
- La fonction `pow` est utilisée pour augmenter ou diminuer la valeur des canaux RVB en fonction de la valeur de `number`, ce qui permet de contrôler l'intensité lumineuse des pixels.

### Pièges potentiels à éviter
- Multiplier les valeurs sans les fonctions puissances. Cela nous donnerait un resultat trop saturé.

<br>

## ⭐⭐ Disque

| Image |
| --- |
| ![Image d'origine](images/resultat/disque.png) |

📁 [Code source](src/disque/main.cpp)

### Description
Dans cet exercice, la formation d'un disque a été appliqué à une image de 500x500. L'algorithme remplit les pixels de l'image pour former un disque centré sur l'image.

### Spécificités
- Les pixels situés à l'intérieur du cercle défini par l'équation sont colorés en blanc en vérifiant si sa position correspond à celle à l'intérieur du disque à l'aide d'une équation de cercle.


<br>

## ⭐ Cercle

| Image |
| --- |
| ![Image d'origine](images/resultat/cercle.png) |

📁 [Code source](src/cercle/main.cpp)

### Description
Dans cet exercice, la formation d'un cercle a été appliqué à une image de 500x500. L'algorithme dessine un cercle avec un rayon et une épaisseur de contours variable.

### Spécificités
- Les pixels situés à l'intérieur du cercle sont laissés vides, tandis que ceux se trouvant dans l'épaisseur des contours sont colorés en blanc en déterminant s'ils se trouvent à l'intérieur du cercle ou dans l'épaisseur de ses contours à l'aide d'une équation de cercle modifiée.


<br>

## ⭐⭐⭐ Rosace

| Image |
| --- |
| ![Image d'origine](images/resultat/rosace.png) |

📁 [Code source](src/rosace/main.cpp)


### Description
Dans cet exercice, la formation d'une rosace a été appliqué à une image de 500x500. L'algorithme dessine une rosace en superposant plusieurs cercles avec des épaisseurs de contour variables.

### Spécificités
- Chaque cercle est défini avec un rayon, une épaisseur de contour et une position de centre différents.
- Le centre défini des cercles est calculé en fonction du cercle trigonométrique par des coordonnées polaires.
### Pièges potentiels à éviter
- Ne pas oublier d'ajouter un nouveau centre pour chaque cercle en fonction du centre de base.

<br>

## ⭐⭐ Mosaïque

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/logo.png) | <img src="images/resultat/mosaique.png" alt="Image modifiée" width="300"/> |

📁 [Code source](src/mosaique/main.cpp)

### Description
Dans cet exercice, un effet de mosaïque a été appliqué à l'image en utilisant une version agrandie de l'image originale. L'algorithme divise l'image en une grille de carrés identiques et place des copies de l'image originale dans chaque carré.

### Spécificités
- Une fonction `newImacPoster` est utilisée pour placer une copie de l'image originale à une position spécifique dans la nouvelle image.
- Sur une grille de carrés est utilisé la fonction `newImacPoster` pour répliquer l'image dans chaque carré de la grille, formant ainsi l'effet de mosaïque.
- Le ratio du nombre de carré est modulable grâce à une variable `ratio` présente au début du `main`.

### Pièges potentiels à éviter
- Ne pas oublier de créer une nouvelle image pour y implanter nos autres images

<br>

## ⭐⭐⭐ Fractale de Mandelbrot

| Image |
| --- |
|![Image](images/resultat/fractale.png) |

📁 [Code source](src/fractale/main.cpp)

### Description
Dans cet exercice, un algorithme génère une image représentant la fractale de Mandelbrot. La fractale de Mandelbrot est un ensemble de points complexes dans le plan complexe qui produit une forme fractale lorsqu'elle est visualisée.

### Spécificités
- Deux boucles imbriquées parcourent chaque pixel de l'image et effectuent des itérations selon la formule mathématique de la fractale de Mandelbrot.
- Pour chaque pixel de l'image, l'algorithme effectue un certain nombre d'itérations pour déterminer s'il appartient à l'ensemble de Mandelbrot en fonction de sa convergence ou de sa divergence.
- La couleur du pixel est définie en fonction du nombre d'itérations nécessaires avant que la séquence ne diverge.

### Pièges potentiels à éviter
- L'utilisation d'un booléen pour la boucle while. L'algorithme ne parviendrerai pas à sortir de la boucle.

<br>

## ⭐⭐⭐(⭐) Vortex

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/logo.png) | ![Image modifiée](images/resultat/vortex.png) |

📁 [Code source](src/vortex/main.cpp)

### Description
Dans cet exercice, un effet de vortex a été appliqué à l'image. L'algorithme effectue une transformation de chaque pixel en utilisant une rotation autour d'un centre donné.

### Spécificités
- Une fonction `rotated` est utilisée pour effectuer la rotation des pixels autour d'un centre de rotation.
- La transformation de rotation est appliqué en fonction de la distance par rapport au centre de l'image.

### Pièges potentiels à éviter
- Sortir de l'image en remplaçant les pixels
- Attriuber les nouvelles coordonnées `newPoint.x, newPoint.y` de la nouvelle image `voidImage`. -> Notre transformation serait décalé par rapport au centre `x,y` de notre image d'origine.
```cpp
            if (newPoint.x < image.width() && newPoint.x >= 0 && newPoint.y < image.height() && newPoint.y >= 0)
                voidImage.pixel(x, y) = image.pixel(newPoint.x, newPoint.y);
```

<br>

## ⭐⭐⭐(⭐) Normalisation de l'histogramme

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/photo.jpg) | ![Image modifiée](images/resultat/normalisation.png) |

📁 [Code source](src/normalisation/main.cpp)

### Description
Dans cet exercice, un effet de normalisation de l'histogramme a été appliqué à l'image. L'algorithme détermine le pixel le plus sombre pour le transformer en noir pur `0` et le pixel le plus clair pour le transformer en blanc pur `1`, normalisant ainsi la plage de valeurs des pixels.

### Spécificités
- En utilisant les valeurs identifiées pour le pixel le plus sombre `darkPixel` et le plus clair `whitePixel`, l'algorithme normalise les valeurs RGB de chaque pixel en calculant la moyenne des composantes RGB en fonction du pixel le plus sombre et clair.

### Pièges potentiels à éviter
- Lors du calcul de normalisation, il ne faut pas oublier de multiplie par **l'inverse** de la valeur de notre pixel le plus clair pour ne pas se retrouver avec un histogramme trop sombre.
```cpp
    image.pixel(x, y).r = (image.pixel(x, y).r - darkPixel) * 1 / whitePixel;
    image.pixel(x, y).g = (image.pixel(x, y).g - darkPixel) * 1 / whitePixel;
    image.pixel(x, y).b = (image.pixel(x, y).b - darkPixel) * 1 / whitePixel;
``` 

<br>

## ⭐⭐⭐(⭐) Tramage

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/photo.jpg) | ![Image modifiée](images/resultat/bayer.png) |

📁 [Code source](src/bayer/main.cpp)


### Description
Dans cet exercice, un effet de tramage a été appliqué à l'image. L'algorithme transforme l'image en une version trame à l'aide d'une matrice de Bayer prédéfinie pour effectuer un tramage ordonné.

### Spécificités
- Une fonction `bwImage` est utilisée pour convertir l'image en noir et blanc en remplaçant chaque composante RGB par la moyenne des valeurs R, G et B de chaque pixel pour obtenir des nuances de gris.
- Le tramage est réalisé en itérant sur chaque pixel de l'image et en ajoutant une valeur prédéfinie de la matrice de Bayer à chaque pixel en noir et blanc.
- Selon la valeur résultante après l'ajout, les pixels sont convertis soit en noir (0), soit en blanc (1).

<br>

## ⭐⭐⭐⭐ Convolutions

| Avant | Après |
| ----------- | ----------- |
| ![Image d'origine](images/photo.jpg) | ![Image modifiée](images/resultat/blur.png) |

📁 [Code source](src/blur/main.cpp)


### Description
Dans cet exercice, un effet de convolution a été appliqué à l'image. L'algorithme utilise une matrice de convolution (également appelée noyau ou kernel) pour appliquer des transformations telles que flou, netteté, détection de contours, etc.

### Spécificités
- Une fonction `getBlur` est utilisée pour appliquer la convolution à chaque pixel de l'image en utilisant un kernel prédéfini.
- Pour effecturer un flou simple, le kernel utilisé est une matrice 3x3 de valeurs prédéfinies. Chaque valeur du kernel multiplie les valeurs des pixels voisins, puis les valeurs résultantes sont utilisées pour former les pixels de la nouvelle image grâce à la moyenne des pixels environnants et du noyau.
- Selon le kernel et les valeurs des pixels environnants, différents effets peuvent être obtenus. Il est modulable avec les kernels proposés en commentaire.
- En fonction du kernel, une division peut être appliqué. Un booléen `divide{true}` est alors mis en place pour être activé comme bon nous semble lorsque cela est nécessaire.

### Pièges potentiels à éviter
- Ne pas incrémenter la variable `number` comme ceci :
Pour éviter que celle-ci ne s'ajoute pas lorsque des pixels dépassent l'image. Le kernel ne fonctionnerait donc pas sur les bords de l'image et serait faussé.
```cpp
        if (x + i >= 0 && x + i < image.width() && y + j >= 0 && y + j < image.height())
        {
            result += image.pixel(x + i, y + j) * kernel[number];
            total += kernel[number];
            number++;
        }
```
- Ne pas ajouter de nouvelle image sinon chaque pixel modifié sera pris en compte par son pixel voisin. Les pixels qui se transforment se base donc sur des pixels déjà transformés. L'effet ne marcherai donc pas.
- Oublier de changer la valeur du booléen `divide` lorsqu'elle doit être pris en compte ou non.