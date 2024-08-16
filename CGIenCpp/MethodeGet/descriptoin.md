Voici une description simplifiée et claire du code :

### Description du Code

Ce programme en C++ utilise CGI (Common Gateway Interface) pour gérer les connexions des utilisateurs via un formulaire web. Voici comment il fonctionne :

1. **Extraction des Paramètres de la Requête** :
   - La fonction `getQueryParam` prend une chaîne de requête (comme `login=username&mdp=password`) et extrait la valeur d'un paramètre spécifique, par exemple, `login` ou `mdp`.
   - Elle remplace également les caractères encodés dans l'URL (comme `%20` pour un espace) par leurs équivalents normaux.

2. **Vérification des Informations d'Identification** :
   - La fonction `checkCredentials` lit les informations d'identification stockées dans un fichier (`users.txt`), où chaque ligne contient un login et un mot de passe séparés par un deux-points.
   - Elle vérifie si le login et le mot de passe fournis correspondent à ceux stockés.

3. **Traitement des Données de Formulaire** :
   - La fonction `main` récupère les paramètres de la requête (login et mot de passe) depuis l'environnement CGI.
   - Elle utilise `checkCredentials` pour vérifier si les informations d'identification sont correctes.

4. **Affichage des Pages Web** :
   - Si les informations sont correctes, le programme affiche une page de bienvenue personnalisée.
   - Si les informations sont incorrectes, il renvoie la page de connexion avec un message d'erreur. Les valeurs saisies dans les champs du formulaire sont conservées pour faciliter une nouvelle tentative.

### Fonctionnement Détail :

- **En-tête HTTP :** Le programme commence par envoyer l'en-tête HTTP pour indiquer qu'il renvoie du contenu HTML.
  
- **Lecture des Données :** Les données du formulaire sont lues à partir de l'URL (pour la méthode GET).
  
- **Extraction des Valeurs :** Les valeurs du login et du mot de passe sont extraites et décodées si nécessaire.
  
- **Vérification :** Les valeurs sont comparées à celles stockées dans le fichier pour vérifier la validité des informations.

- **Affichage :** Selon le résultat de la vérification, le programme génère une page HTML :
  - **Page de bienvenue** si les informations sont correctes.
  - **Page de connexion** avec un message d'erreur si les informations sont incorrectes, tout en conservant les valeurs saisies pour que l'utilisateur puisse essayer à nouveau.