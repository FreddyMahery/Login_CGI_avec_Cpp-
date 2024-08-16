### Description Simplifiée du Code

Ce programme en C++ utilise CGI (Common Gateway Interface) pour traiter un formulaire de connexion web. Voici une explication claire de chaque partie :

1. **Extraction des Paramètres de Requête** :
   - La fonction `getQueryParam` extrait la valeur d'un paramètre (comme `login` ou `mdp`) à partir d'une chaîne de requête (une partie de l'URL après le `?`).
   - Elle gère les caractères encodés dans l'URL, tels que `%20` pour les espaces.

2. **Vérification des Informations d'Identification** :
   - La fonction `checkCredentials` ouvre un fichier `users.txt` et lit les informations ligne par ligne.
   - Chaque ligne contient un login et un mot de passe séparés par un deux-points. La fonction compare les valeurs fournies avec celles du fichier pour vérifier leur validité.

3. **Traitement des Données du Formulaire** :
   - La fonction `main` lit les données du formulaire depuis l'entrée standard. En CGI, ces données peuvent être passées via la méthode POST (les données sont dans le corps de la requête).
   - Les valeurs de `login` et `mdp` sont extraites et décodées.

4. **Affichage des Pages Web** :
   - Si les informations sont correctes, le programme affiche une page de bienvenue personnalisée avec le nom d'utilisateur.
   - Si les informations sont incorrectes, il renvoie la page de connexion avec un message d'erreur en rouge. Les champs du formulaire conservent les valeurs saisies pour que l'utilisateur puisse essayer à nouveau.

### Fonctionnement Détail :

- **En-tête HTTP** : Le programme commence par envoyer l'en-tête HTTP indiquant que le contenu est du HTML.

- **Lecture des Données** : Les données du formulaire sont lues à partir de l'entrée standard (méthode POST).

- **Extraction des Valeurs** : Les valeurs du login et du mot de passe sont extraites de la chaîne de requête et décodées si nécessaire.

- **Vérification** : Les informations sont comparées avec celles stockées dans le fichier pour déterminer leur validité.

- **Affichage** :
  - **Page de bienvenue** : Affichée si les informations sont correctes.
  - **Page de connexion** : Affichée avec un message d'erreur si les informations sont incorrectes, tout en conservant les valeurs saisies dans les champs du formulaire.