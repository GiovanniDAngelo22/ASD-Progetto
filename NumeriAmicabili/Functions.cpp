#include "Header.h"



Numero::Numero(int num){

	numero = num;
	sommaD = CalcoloDivisori(num);
	flag = true;  // Il numero è istanziato nella Hashtable
};

Numero::Numero()
{
	numero = -1; //Valori fittizzi usati per gli elementi eliminati
	sommaD = -1;
	flag=false; //il numero non è istanziato, la locazione e' libera
};



int Numero::getNumero()
{
	return numero;
}

int Numero::getSomma()
{
	return sommaD;
}

bool Numero::getFlag()
{
	return flag;
}

void Numero::setFlag(bool f)
{
	flag = f;
}

void Numero::setNum (int n)
{
	numero = n;
}

void  Numero::setSomma(int s)
{
	sommaD = s;
}

/////////////////////////////////////////////

int HashTable::hashFunction1(int key)
{
	return (key % dim);
}

int HashTable::hashFunction2(int key)
{
	return (1+ key%dim-1);
}

int HashTable::hashFunction (int key, int i) 
{
	return ((hashFunction1(key)+ i*hashFunction2(key))%dim);
}

HashTable::HashTable(int m)
 {
 	dim=m;T = vector<Numero>(dim);
}



vector<Numero> HashTable::coppieAmicabili()
{
	int index,i;
	vector<Numero> risultato;
	for (i=0; i<dim;i++) //Controllo tutta l'hash Table
	{
		if (T[i].getNumero() > 0) //Salto gli elementi vuoti
		{
			index = hashSearch(T[i].getSomma());
			if (index != -1 && index != i) //Se la search ha dato risultato e la somma dei divisori è diversa dal numero stesso
			{
				if(T[index].getSomma() == T[i].getNumero() ) //Se la somma del numero precedentemente trovato è uguale al numero di indice i
				{
					risultato.push_back(T[i]); //Salva la coppia nel vettore risultato
				}
			}
		}

	}
	return risultato;
}

void HashTable::hashInsert(int key)
{
	int index = hashSearch(key); //Prima di inserire controllo se l'elemento è inserito
	if (index != -1)
	{
		return; //In caso di duplicati, non inserisco

	}
	int i = 0;
	int j;
	Numero n(key);
		while (i <= dim) 
		{
			j = hashFunction(key,i);
			if (T[j].getNumero() < 1) //Se la cella è vuota (o è stata cancellata)
				{
					T[j] = n; //Salva il numero nella Hashtable
					i=dim+1; //Esco dal while
				}
			else 
				i=i+1;
		}
}

void HashTable::hashDelete(int key)
{
	int index = hashSearch(key); //Cerco l'indice nella mia Hashtable
	if (index != -1) //Se la search ha dato risultato
	{
		T[index].setSomma(-1); //Setto valori fittizzi in modo da non considerarli in eventuali ricerche/stampe
		T[index].setNum(-1);
		T[index].setFlag(true); 
		cout << "elemento eliminato!" << endl;
	}
	else
	{
		cout << "l'elemento non e' stato trovato" << endl;
	}
}

int HashTable::hashSearch(int key)
{
	int i = 0;
	int j= hashFunction1(key); 
	while (T[j].getFlag() == true || i <= dim) 
	{
		j= hashFunction(key,i);
		if (T[j].getNumero() == key && T[j].getFlag() != false ) //Se il numero c'è e non è stato rimosso
			return j; //ritorno l'indice di posizione
		i=i+1;
	}
	return -1; //l'elemento cercato non c'è
}

void HashTable::printTable()
{
	int i =0;

	for (i =0; i<T.size();i++)
	{
		if (T[i].getFlag() == true && T[i].getNumero() > 0) //Stampa solo elementi presenti e non cancellati
		{	
			cout << T[i].getNumero() << "--> Somma = " << T[i].getSomma();
			cout << endl;
		}
	}
}

/////////////////////////////////////////////

int CalcoloDivisori(int num)
{
   int resto,somma=1; 
    for (int i=2;i<=num/2;i++) //Per tutti i numeri da 2 a num/2 (la somma è inizializzata ad 1, non è necessario sommare 1)
    {
        resto=num%i; //calcolo il resto
            if(resto==0)   //se il resto e' 0 allora
                {somma=somma+i;}  //"i" è un divisore e va aggiunto
    }
    return somma;
}
