/* MAIN DATO DALLA TRACCIA
#include <string>
#include "Dizionario.cpp"

int main() {

    Dizionario<std::string> dict;

    dict.inserisci("apple", "fruit");
    dict.inserisci("car", "vehicle");
    dict.inserisci("book", "object");

    std::cout << "Value for 'apple': " << dict.recupera("apple") << "\n";
    std::cout << "Value for 'car': " << dict.recupera("car") << "\n";
    std::cout << "Value for 'pen': " << dict.recupera("pen") << "\n";

    dict.stampa();

    return 0;
} */

#include <iostream>
#include <string>
#include "Dizionario.cpp"

int main() {
    
	Dizionario<std::string> dict;

    dict.inserisci("apple", "fruit");
    dict.inserisci("car", "vehicle");
    dict.inserisci("book", "object");

    std::cout << "Value for 'apple': " << dict.recupera("apple") << "\n";
    std::cout << "Value for 'car': " << dict.recupera("car") << "\n";
    std::cout << "Value for 'pen': " << dict.recupera("pen") << "\n"; 

    // aggiungo una chiave ipotetica che potrebbe entrare in collisione con una esistente
    std::cout << "\inserire 'lappe' per provare la collisione:\n"; // Supponiamo che "app" causi una collisione con "apple"
    dict.inserisci("lappe", "fruit_variant"); // Inseriamo una chiave che dovrebbe causare una collisione

    // aggiungo un'altra possibile collisione
    std::cout << "\ninserire 'cra' per provare la collisione:\n"; // Un'altra collisione ipotetica
    dict.inserisci("cra", "vehicle_variant");

    // stampo i dati in tabella
    std::cout << "\nPrinting the dictionary:\n";
    dict.stampa(); // Mostriamo l'intero contenuto della tabella

    // funzione di modifica
    std::cout << "\nModifying 'apple' to 'sweet_fruit':\n";
    dict.modifica("apple", "sweet_fruit");
    std::cout << "Updated value for 'apple': " << dict.recupera("apple") << "\n";

    // funzione cancella
    std::cout << "\n cancella 'car':\n";
    dict.cancella("car");
    std::cout << "valore di 'car' dopo la cancellazione: " << dict.recupera("car") << "\n";

    // funzione appartiene
    std::cout << "\n controllo dell'esistenza delle chiavi':\n";
    std::cout << "esiste 'book'? " << (dict.appartiene("book") ? "si" : "No") << "\n";
    std::cout << "esiste 'car'? " << (dict.appartiene("car") ? "si" : "No") << "\n"; // dopo la cancellazione!!
    std::cout << "esiste 'apple'? " << (dict.appartiene("apple") ? "si" : "No") << "\n";

    return 0;
}
