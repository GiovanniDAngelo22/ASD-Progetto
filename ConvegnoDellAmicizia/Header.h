#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Scheletro classi
class Node{
    int amici;  // numero degli amici del nodo
    int data; //numero che identifica il nodo
    int posizione; //la sua posizione all'interno del vettore della coda di priorita'
    bool eliminato=false; //identifica se e' stato rimosso dalla coda di priorità
    list<Node *> *adj; //lista dei nodi adiacenti
public:
    Node(int data);
    Node(){};
    ~Node();
    void addEdge(Node *w); //aggiunge un nodo alla lista di adiacenza
    void removeEdge(); // decrementa il valore di "amici"
    list<Node *> * getAdj(); //ritorna la lista di adiacenza del nodo
    int getData(); //ritorna l'identificativo del nodo
    int getAmici(); 
    void setPosizione(int p); 
    void elimina(); // imposta "eliminato" a true 
    bool getEliminazione();  
    int getPosizione();
};

/////////////////////////////////////////////

class Heap
{
    private:
        vector<Node*> vettore; 
        int heapSize; 
        bool isHeap;
        int ParentB(int i);
        int LeftB(int i);
        int RightB(int i);
    public:
        Heap(vector<Node*> &v);
        ~Heap(){};
        void printHeap();
        void setElem (int i, Node * newVal);
        void BuildMinHeap();
        void minHeapify(int i);
        void RestoreHeap(); //Ha la stessa funzione del buildMinHeap ma non modifica l'heapsize
        void Insert();
        Node* getElem (int i);
        int getHeapSize();
        void setHeapSize(int i);
        bool getHeapyness(); //Ci dice se è rispetta la prioprietà di heap o meno
        void heapInsert(Node* newVal);
        void heapSwap (Node * &t1, Node* &t2); //Inverte i puntatori di due Node
};

/////////////////////////////////////////////

class CodaPriorita : public Heap
{
    private:

    public:
        CodaPriorita(vector<Node*> &a);
        ~CodaPriorita(){};
        Node* getHeapMinimum();
        Node* heapExtractMin();
        void heapIncreasePriority(Node *newVal, int i);
        void insertCoda(Node * newVal);

};

/////////////////////////////////////////////

class Graph
{
    vector<Node *> *adj;
public:
    Graph();
    ~Graph();
    void addNode(Node *w);
    Node *getNode(int v);
    void printAdj(); 
    int getV(); //necessario per sapere il numero di Vertici
};

/////////////////////////////////////////////

int Convegno(Graph g); 



#endif
