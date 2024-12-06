#include <iostream>

template <typename T>
class DizionarioEsteso {
private:
   static const int TABLE_SIZE = 10; // Dimensione della tabella hash ipotizzata 10
   struct Entry {
       std::string key;
       T value;
       bool isOccupied = false; // Indica se lo slot è occupato
   };
   Entry table[TABLE_SIZE]; // Tabella hash
	//funzione di hash
   	int hashFunction(const std::string& key) const {
	    int hash = 0;
	    for (char ch : key) {
	        hash += static_cast<int>(ch);
	    }
	    return hash % TABLE_SIZE;
	}
//esercizio 2 punto 1
	//funzione di hash per Linear Probing e Double Hashing.
	//funzione per trovare il primo slot disponibile
	int findSlot(int index) {
        int i = 0;
        int indiceIniziale = index;
        int doubleHash = index % 100; // Calcolo dell'incremento per il double hashing
        
        return index;
    }

public:
//esercizio 1
//Inserisci: Aggiunge una coppia <chiave, valore> al dizionario. (é giá implementata nel codice base)
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
        std::cerr << "Collision detected for key: " << key << " at index " << index << ". Resolving...\n";
//esercizio 2 punto 2
        index = findSlot(index); // Trova una nuova posizione disponibile
    	}
//fine esercizio 2 punto 2
        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }
    
//Cancella: Rimuove una coppia dato il valore della chiave.
   void cancella(const std::string key) {
        int index = hashFunction(key);
//esercizio 2 punto 3
		if (table[index].isOccupied && table[index].key != key) {
		        std::cerr << "Collision detected, resolving...\n";
		        index = findSlot(index);  // Troviamo la posizione corretta della chiave
		    }
//fine esercizio 2 punto 3
        // Se la posizione è occupata e la chiave corrisponde, rimuoviamo la voce
        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
            std::cout << "Deleted entry with key: " << key << "\n";
        } 
		else {
            std::cout << "Key not found for deletion: " << key << "\n";
        }
    }

//esercizio 2 punto 3
void modifica(const std::string key, const T newValue) {
    int index = hashFunction(key);
	    if (table[index].isOccupied && table[index].key != key) {
	        std::cerr << "Collision detected, resolving...\n";
	        index = findSlot(index);  // Troviamo la posizione corretta della chiave
	    }
    if (table[index].isOccupied && table[index].key == key) {
        table[index].value = newValue;
        std::cout << "Updated value for key: " << key << "\n";
    } else {
        std::cout << "Key not found for modification: " << key << "\n";
    }
}
//fine esercizio 2 punto 3

//Recupera: Restituisce il valore associato a una chiave specifica. (é giá implementata nel codice base)
    T recupera(const std::string key) const {
        int index = hashFunction(key);
//esercizio 2 punto 3
		if (table[index].isOccupied && table[index].key != key) {
		        std::cerr << "Collision detected, resolving...\n";
		        index = findSlot(index);  // Troviamo la posizione corretta della chiave
		    }
//fine esercizio 2 punto 3
        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }
        return "Key not found!";
    }
    
//Appartiene: Verifica se una chiave è presente nel dizionario.
   	bool appartiene(const std::string key) const {
        int index = hashFunction(key);
//esercizio 2 punto 3
		if (table[index].isOccupied && table[index].key != key) {
		        std::cerr << "Collision detected, resolving...\n";
		        index = findSlot(index);  // Troviamo la posizione corretta della chiave
		    }
//fine esercizio 2 punto 3
        return table[index].isOccupied && table[index].key == key;
    }
    
//Stampa: Stampa il contenuto del dizionario in un formato leggibile. (é giá implementata nel codice base)
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};


