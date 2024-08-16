#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Fonction utilitaire pour extraire la valeur d'un paramètre spécifique
std::string getQueryParam(const std::string& query, const std::string& param) {
    size_t start = query.find(param + "=");
    if (start == std::string::npos) return "";

    start += param.length() + 1;
    size_t end = query.find('&', start);
    if (end == std::string::npos) end = query.length();

    std::string value = query.substr(start, end - start);
    // Remplacement des caractères encodés (%20 pour espace, etc.)
    std::string result;
    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == '+') {
            result += ' ';
        } else if (value[i] == '%') {
            int hex;
            sscanf(value.substr(i + 1, 2).c_str(), "%x", &hex);
            result += static_cast<char>(hex);
            i += 2;
        } else {
            result += value[i];
        }
    }
    return result;
}

// Fonction pour vérifier les informations d'identification
bool checkCredentials(const std::string& login, const std::string& mdp) {
    const std::string filename = "users.txt";
    std::ifstream file(filename);
    if (!file) return false;

    std::string line;
    while (std::getline(file, line)) {
        std::string storedLogin, storedMdp;
        std::istringstream iss(line);
        std::getline(iss, storedLogin, ':');
        std::getline(iss, storedMdp);

        if (login == storedLogin && mdp == storedMdp) {
            return true;
        }
    }
    return false;
}

int main() {
    // En-tête HTTP pour le contenu HTML
    std::cout << "Content-Type: text/html\n\n";

    // Récupération de la query string depuis l'environnement
    std::string query = getenv("QUERY_STRING");

    // Extraction des valeurs login et mot de passe
    std::string login = getQueryParam(query, "login");
    std::string mdp = getQueryParam(query, "mdp");

    // Vérification des informations d'identification
    if (checkCredentials(login, mdp)) {
        // Affichage d'une page de bienvenue
        std::cout << "<!DOCTYPE html>\n";
        std::cout << "<html lang=\"en\">\n";
        std::cout << "<head>\n";
        std::cout << "    <meta charset=\"UTF-8\">\n";
        std::cout << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        std::cout << "    <title>Bienvenue</title>\n";
        std::cout << "</head>\n";
        std::cout << "<body>\n";
        std::cout << "    <h1>Bienvenue, " << login << "!</h1>\n";
        std::cout << "</body>\n";
        std::cout << "</html>\n";
    } else {
        // Retourne la page de connexion avec un message d'erreur et les valeurs remplies
        std::cout << "<!DOCTYPE html>\n";
        std::cout << "<html lang=\"en\">\n";
        std::cout << "<head>\n";
        std::cout << "    <meta charset=\"UTF-8\">\n";
        std::cout << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        std::cout << "    <title>Connexion</title>\n";
        std::cout << "</head>\n";
        std::cout << "<body>\n";
        std::cout << "    <form action=\"traitement.cgi\" method=\"get\">\n";
        std::cout << "        <h1>Connexion</h1>\n";
        std::cout << "        <label for=\"login\">Login:</label>\n";
        std::cout << "        <input type=\"text\" id=\"login\" name=\"login\" required value=\"" << login << "\"><br><br>\n";
        std::cout << "        <label for=\"mdp\">Mot de passe:</label>\n";
        std::cout << "        <input type=\"password\" id=\"mdp\" name=\"mdp\" required value=\"" << mdp << "\"><br><br>\n";
        std::cout << "        <button type=\"submit\">Se connecter</button>\n";
        std::cout << "        <p style=\"color:red;\">Le login ou le mot de passe est incorrect.</p>\n";
        std::cout << "    </form>\n";
        std::cout << "</body>\n";
        std::cout << "</html>\n";
    }

    return 0;
}
