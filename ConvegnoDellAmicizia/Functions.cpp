#include "Header.h"

Node::Node(int data)
{
	this->data=data;
	amici=0;
    adj=new list<Node *>;
}

Node::~Node()
{
    adj->clear();
    delete adj;
}

void Node::addEdge(Node *w)
{
	adj->push_back(w);amici++;
}

void Node::removeEdge()
{
	amici--;
}

list<Node *> * Node::getAdj()
{	
	return adj;
}

int Node::getData()
{
	return data;
}

int Node::getAmici()
{
	return amici;
}

void Node::setPosizione(int p)
{
	posizione = p;
}

void Node::elimina()
{
	eliminato = true;
}

bool Node::getEliminazione()
{
	return eliminato;
}

int Node::getPosizione()
{
	return posizione;
}


/////////////////////////////////////////////


int Heap::ParentB(int i)
{
	return (i-1)>>1;
}

int Heap::LeftB(int i)
{
	return (i<<1)|0x1;
}

int Heap::RightB(int i)
{
	return (i+1)<<1;
}


Heap::Heap(vector<Node*> &v)
{
	vettore = v;heapSize=0; isHeap=false;
}

void Heap::printHeap()
{
    for(int i=0; i<heapSize;i++)
        {
            {
            cout <<  vettore.at(i)->getData();
            }
        }
        cout << endl;
}

void Heap::setElem (int i, Node * newVal)
{
	vettore[i] = newVal;
}


void Heap::BuildMinHeap()
{
    heapSize = vettore.size();
    for (int j=(vettore.size()/2); j>=0;j--)
    {
        minHeapify(j);
    }
    isHeap = true;
}

void Heap::RestoreHeap() 
{
    for (int j=(vettore.size()/2); j>=0;j--)
    {
        minHeapify(j);
    }
    isHeap = true;
}

void Heap::minHeapify(int i)
{
    int min;
    int l=LeftB(i), r=RightB(i);
    if (l<heapSize && vettore.at(i)->getAmici()>vettore.at(l)->getAmici())
    {
        min=l;
    }
    else
    {
        min=i;
    }
    if (r < heapSize && vettore.at(min)->getAmici()>vettore.at(r)->getAmici())
    {
        min=r;
    }
    if (min!=i)
    {
        heapSwap(vettore.at(i),vettore.at(min));
        vettore.at(min)->setPosizione(min);
        vettore.at(i)->setPosizione(i);
        minHeapify(min);
    }


};



Node* Heap::getElem (int i)
{
	return vettore[i];
}

int Heap::getHeapSize()
{
	return heapSize;
}

void Heap::setHeapSize(int i)
{
	heapSize=i;
}

bool Heap::getHeapyness()
{
	return isHeap;
}

void Heap::heapInsert(Node * newVal)
{
    vettore.push_back(newVal); //inserisco l'elemento
    heapSize++; //incremento l'heapsize
    int i = heapSize-1;
    vettore.at(i)->setPosizione(i);
    isHeap = false; //Non rispetto più la proprietà heap
}
void Heap::heapSwap (Node * &t1, Node* &t2)
{
    Node * temp;
    temp=t1;
    t1=t2;
    t2=temp;
}

/////////////////////////////////////////////

CodaPriorita::CodaPriorita(vector<Node*> &a):Heap(a){};

Node* CodaPriorita::getHeapMinimum()
{
	return getElem(0);
}


void CodaPriorita::heapIncreasePriority(Node *newVal, int i)
	{
	setElem(i, newVal);
	while (i>0 && getElem((i-1)/2)->getAmici() > getElem(i)->getAmici())
		{
			//Inizio Swap
			Node *elem1 = getElem((i-1)/2);
			Node *elem2 = getElem(i);
			setElem((i-1)/2,elem2);
			setElem(i,elem1);
			//Fine Swap
			//Riassegno il valore delle posizioni
			getElem((i-1)/2)->setPosizione((i-1)/2);
            getElem(i)->setPosizione(i);
			i=(i-1)/2;
		}
	}


Node* CodaPriorita::heapExtractMin()
{
    if (getHeapyness() == true)
    {
    if(getHeapSize() < 0)
    {
        cout << "Elementi finiti, impossibile estrarre" << endl;
        exit (-1);
    }
    else
    {
        Node* min=getElem(0);
        min->elimina(); //Il nodo estratto è stato eliminato, non bisogna piu' considerarlo nella coda
        Node* elem2 = getElem(getHeapSize()-1);
        elem2->setPosizione(0);
        setElem(0,elem2);
        setElem(getHeapSize(),min);
        setHeapSize((getHeapSize()-1));
        minHeapify(0);
        return min;
    }
    }
    else
        exit(0);
}

void CodaPriorita::insertCoda(Node * newVal)
{
	heapInsert(newVal);
}

/////////////////////////////////////////////

Graph::Graph()
{
	adj = new vector<Node *>;
}

Graph::~Graph()
{
    adj->clear();
    delete adj;
}

void Graph::addNode(Node *w)
{
	adj->push_back(w);
}

Node* Graph::getNode(int v)
{
	return adj->at(v);
}

void Graph::printAdj(){
    for(auto v:*adj){
        cout<<"Adj("<<v->getData()<<"):";
        for(auto vv:*v->getAdj())
            cout<<" "<<vv->getData();
        cout<<endl;
    }
}

int Graph::getV()
{
	return adj->size();
}

/////////////////////////////////////////////

int Convegno(Graph g)
{
	int risultato,i;
	vector<Node*> a;
    Node* temp_nodo;
    CodaPriorita coda(a); //creo una coda vuota
    for (i=0;i<g.getV();i++)
    {
        coda.heapInsert(g.getNode(i));  //inserisco i vertici del grafo nella coda di priorita
    }
    coda.BuildMinHeap();
    cout << "Nodi nella coda:" << endl;
    coda.printHeap();  
    Node* u; 
    while (coda.getHeapSize() > 0 && coda.getHeapMinimum()->getAmici() <= 2)  //Fintanto che la coda non si svuota o la testa della coda ha più di 2 amici
    {
       temp_nodo = coda.heapExtractMin();  //Estraggo il minimo, ha sicuramente meno di 3 amici
       for (auto x: *temp_nodo->getAdj()) //Scorro la sua lista di adiacenza
       {
       		if (x->getEliminazione()==false) //Se il nodo trovato nella lista di adiacenza non è stato già eliminato
            {
            	x->removeEdge(); //decremento il valore di "amici"
                coda.heapIncreasePriority(x,x->getPosizione()); //
        }
       }
    }
    cout << "Nodi rimanenti: " << endl;
    coda.printHeap();
    risultato = coda.getHeapSize();
    return risultato;
}