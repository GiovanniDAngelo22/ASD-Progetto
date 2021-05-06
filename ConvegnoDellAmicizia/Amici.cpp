#include "Functions.cpp"


int main()
{
    Graph g; //Creo il grafo
    string temp;
    int n_nodi,num_archi,x,y,i,risultato;
    std::ifstream input("input.txt", ios::in); //Apro il file di input
    ofstream output;
    output.open("output.txt"); //Apro il file di output
    if (input.fail())
    {
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }
    getline(input,temp,' '); //Prendo il numero dei nodi
    n_nodi = stoi(temp);
    cout << "Numero nodi: " << n_nodi << endl;
    for (i=1;i<n_nodi+1;i++)
        {
            g.addNode(new Node(i)); //Aggiungo i nodi al grafo
        }
    getline(input,temp); //Prendo il numero degli archi
    num_archi = stoi(temp);
    cout << "Numero archi: " << num_archi << endl;
    for (i=0;i<num_archi;i++)  
    {
        getline(input,temp,' '); 
        x=stoi(temp);
        getline(input,temp); 
        y=stoi(temp);
        g.getNode(x-1)->addEdge(g.getNode(y-1));  //Essendo un grafo non orientato, aggiungo sia l'arco X-Y che Y-X.
        g.getNode(y-1)->addEdge(g.getNode(x-1));
    }

    cout <<"Lista di Adiacenza: " << endl;
    g.printAdj();

    risultato = Convegno(g); 
    
    output << risultato << endl;
    output.close();
    input.close();

    return 0;
}