### Principe de CGI avec les Méthodes GET et POST

**CGI (Common Gateway Interface)** permet à un serveur web de communiquer avec des programmes externes, comme des scripts en C++. Ces programmes traitent les données envoyées par les utilisateurs via des formulaires web. On peut utiliser deux méthodes principales pour envoyer ces données : GET et POST.

#### Méthode GET
- **Comment ça marche :** Les données du formulaire sont ajoutées directement à l'URL, par exemple : `?login=username&mdp=password`.
  
- **Avantages :**
  - Facile à mettre en place et à tester.
  - Les URL peuvent être sauvegardées ou partagées.

- **Inconvénients :**
  - Les données sont visibles dans l'URL, ce qui peut poser des problèmes de sécurité.
  - Limite sur la quantité de données envoyées.

- **Utilisation dans ce projet :** Lorsque la méthode GET est utilisée, les données du formulaire sont envoyées dans l'URL. Le script CGI extrait ces données de l'URL pour vérifier les informations de connexion.

#### Méthode POST
- **Comment ça marche :** Les données du formulaire sont envoyées dans le corps de la requête HTTP, pas dans l'URL.

- **Avantages :**
  - Les données sensibles, comme les mots de passe, ne sont pas visibles dans l'URL.
  - Pas de limite sur la quantité de données envoyées.

- **Inconvénients :**
  - Les données ne peuvent pas être sauvegardées ou partagées aussi facilement.
  - Un peu plus complexe à mettre en place.

- **Utilisation dans ce projet :** Avec la méthode POST, les données sont lues à partir du corps de la requête. Le script CGI les extrait et vérifie les informations de connexion.

### Exemple d'Utilisation
- **GET :** Si les informations de connexion sont incorrectes, la page se recharge avec les champs pré-remplis pour faciliter une nouvelle tentative.

- **POST :** Les informations sont envoyées de manière plus sécurisée, et le script CGI les traite en arrière-plan.

En résumé, CGI traite les données des formulaires envoyées par les utilisateurs, que ce soit par GET ou POST, pour vérifier les informations et renvoyer une réponse adaptée.