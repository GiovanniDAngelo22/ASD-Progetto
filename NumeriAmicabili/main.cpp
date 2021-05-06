#include "Functions.cpp"
#define M 10007

int main()
{
	int i, scelta,n,numero,temp;
	vector<Numero> risultato;
 
	HashTable ht(M);
	cout << "Seleziona la modalità:" << endl;
	cout << "1) Visualizza i numeri amicabili da 1 ad n" << endl;
	cout << "2) Inserisci n numeri da tastiera"<<endl;
	cin >> scelta;
	switch(scelta) {

   case 1  :
      	
      	cout << "Inserire fino a che numero calcolare i numeri amicabili (Max 10000)"<< endl;
		cin >> n;
		cout << "Calcolo amicabili da 1 a " << n<< "..." << endl;
		for (i=0;i<=n;i++)
		{
			ht.hashInsert(i);
		}
			cout << "coppie :" << endl;
			risultato=ht.coppieAmicabili();
		for (i=0;i<risultato.size();i++)
		{
			cout << risultato[i].getNumero() << "--> " << risultato[i].getSomma()<<endl;
		}
		cout << "Programma terminato" << endl;
      break;
	
   case 2  :
      	cout << "Quanti numeri vuoi inserire?" << endl;
		cin >> n;
		cout << "Inserire " << n << " numeri" << endl;
		for (i=0;i<n;i++)
		{
			cin >> temp;
			ht.hashInsert(temp);
		}
			while (1)
		{
			cout << "Cosa vuoi fare?" << endl;
			cout << "1)Vedi coppie amicabili" << endl;
			cout << "2)Rimuovi numeri dalla tabella" << endl;
			cout << "3)Inserisci numero nella tabella" << endl;
			cout << "4)Visualizza la tabella" << endl;
			cout << "5)Esci" << endl;
			cin >> scelta;
			switch(scelta) {

			   case 1 :
			      			risultato=ht.coppieAmicabili();
					for (i=0;i<risultato.size();i++)
					{
						cout << risultato[i].getNumero() << "--> " << risultato[i].getSomma()<<endl;
					}
			      break; 

			   case 2 :
			      cout << "Che numero vuoi eliminare?" <<endl;
			      cin >> numero;
			      ht.hashDelete(numero);
			      break; 
			   case 3 :
				  cout <<  "Inserisci nuovo numero" << endl;
				  cin >> numero;
				  ht.hashInsert(numero);
				  break;
			   case 4 :
			   		cout << "Stampo la tabella:"<< endl;
			   		ht.printTable();
			   	break;
			   	case 5: 
			   	return 0;
			   default : 
			    cout << "Scelta non valida"<< endl;
			}
		}
      break; 
  
   default : 
   cout << "Scelta non valida, programma in chiusura" << endl;
   return 0;
	}
}

