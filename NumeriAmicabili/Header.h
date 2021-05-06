#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
using namespace std;

//Scheletro classi
class Numero {
private:
    int numero; 
    int sommaD; //Somma dei divisori del numero
    bool flag; //Flag identifica se il numero è stato istanziato o meno nella Hash table. 
    //Un oggetto eliminato ha comunque flag positiva in modo da poter proseguire nella ricerca dopo un eventuale cancellazione.
public:
    Numero(int num); 
    Numero();
    ~Numero(){};
    int getNumero();
    int getSomma();
    bool getFlag();
    void setFlag(bool f);
    void setNum (int n);
    void setSomma(int s);
};

/////////////////////////////////////

class HashTable{
	private:
		int dim;
		vector<Numero> T;
		int hashFunction1(int key); //Prima funzione di hash
		int hashFunction2(int key); //Seconda funzione di hash (Per iterare)
		int hashFunction (int key, int i); //Funzione di hash utilizzata effettivamente
	public:
		HashTable(int m);
		~HashTable(){};
		void hashInsert(int key); 
		void hashDelete(int key);
		int hashSearch(int key); 
		void printTable(); 
		vector<Numero> coppieAmicabili(); //Trovo i numeri amicabili all'interno della Hashtable
};

int CalcoloDivisori(int num); //Dato un numero, ne calcola la somma dei divisori

#endif
