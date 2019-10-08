#include <iostream>
#include <string.h>
#include <vector>
#include <ctime> 
#include <stdlib.h>
#include <stdio.h> //libreria che serve per le funzioni toupper() e tolower()//
#include <cstdlib> //libreria per controllare il tipo di sistema operativo del computer sulla quale viene fatto esguire il programma//
#include <array>
#include <bits/stdc++.h> //libreria per la funzione compareinterval//
using namespace std;

bool compareinterval(vector <string>i1, vector<string>i2) {
  return (i1[0]<i2[0]);
}
 
int main(){
 
    int azione;
    vector < vector<string> > agenda;
    vector < vector<string> > Preferiti;
    vector < vector<string> > vettori = {{"Torre Antonella","3316578442"},{"Fantini Marco", "3319736229"}, {"Parrucchiera Carmela", "3286230102"}, {"Meccanico Giovanni", "3332127150"}, {"Vecchi Carlo", "3398740165"}, {"Magnani Davide", "3493356504"}};
    int l = agenda.size();
    // abbiamo creato un vettore contenente i contatti da aggiungere alla rubrica quando viene visualizzata per la prima volta. I contatti che vengono inseriti sono 4 e vengono scelti in modo casuale dal vettore 'vettori'//
    srand(time(NULL));
    int rn = rand()%6;
    int lista[4];
    lista[0] = rn;
    lista[3] = 8;
    int w = 1;
    while(lista[3] == 8){
        rn = rand()%6;
        if(rn != lista[0] && rn!=lista[1] && rn!=lista[2] && rn!=lista[3] && 0 <=rn && rn<= 5){
            lista[w] = rn;
            w++;
        };
    };
     
    for (int t=0; t<4; t++) {
        agenda.push_back(vettori[lista[t]]);
    };
     
     
    while (azione!=8) {
     
        cout << "\nBenvenuto\a nella tua rubrica! Ecco le operazioni possibili:\n";
        cout << "1. Crea nuovo Contatto" << endl;
        cout << "2. Modifica Contatto" << endl;
        cout << "3. Elimina Contatto" << endl;
        cout << "4. Cerca contatto per nome o cognome" << endl;
        cout << "5. Visualizza intera rubrica" << endl;
        cout << "6. Elimina intera rubrica" << endl;
        cout << "7. Visualizza Preferiti" << endl;
        cout << "8. ESCI\n" << endl;
        cout << "Inserisci il numero corrispondente all'azione che vuoi eseguire\n\n";
        cin >> azione;
     
        vector < vector<string> > vettori = {{"Torre Antonella","3316578442"},{"Fantini Marco", "3319736229"}, {"Parrucchiera Carmela", "3286230102"}, {"Meccanico Giovanni", "3332127150"}, {"Vecchi Carlo", "3398740165"}, {"Magnani Davide", "3493356504"}};
        string nome;
        string cognome;
        string numero;

        switch (azione){
         
            case 1: {
             // per creare un nuovo contatto chiediamo all'utente di inserire il nuovo nome, cognome e numero, che vengono salvati nel vettore 'Nuovo_Contatto', che viene poi aggiunto alla rubrica. //
                cout << "Nome: ";
                cin >> nome;
                nome[0] = toupper(nome[0]);
                for (int y=1; y<nome.size(); y++) {
                  nome[y]=tolower(nome[y]);
                }
                cout << "Cognome(se non vuoi aggiungere questa voce scrivi 'No'): ";
                cin >> cognome;
                if (cognome == "no" || cognome == "No" || cognome == "NO") {
                  cognome = ""; 
                } else {
                  cognome[0] = toupper(cognome[0]);
                  for (int y=1; y<cognome.size(); y++) {
                    cognome[y]=tolower(cognome[y]);
                  }
                }
                cout << "Numero: ";
                cin >> numero;
                while (numero.size() != 10) {
                    cout << "Numero non esistente, riprova: ";
                    cin >> numero;
                }
                string nomeint = cognome + " " + nome; // creiamo una stringa che contenga sia il nome che il cognome del nuovo contatto//
                vector <string> Nuovo_Contatto = {nomeint, numero};
                agenda.push_back (Nuovo_Contatto);
                cout << "Contatto creato con successo!\n\n";
                char prefe;
                cout << "Se vuoi aggiungere il contatto ai Preferiti scrivi 'P', altrimenti 'S'\n";
                cin >> prefe;
                if (prefe == 'p' || prefe == 'P') {
                    Preferiti.push_back (Nuovo_Contatto);
                    cout << "Contatto aggiunto ai Preferiti!\n";
                } else {
                    break;
                }
            } break;
                 
            case 2: {
             // questa è l'opzione per modificare un contatto già esistente: come prima cosa visualizziamo la rubrica, poi chiediamo all'utente di scrivere il noumero del contatto da modificare e chiediamo il nuovo nome, cognome o numero//
                sort(agenda.begin(),agenda.end(),compareinterval);
                int l = agenda.size();
                cout << "CONTATTI IN AGENDA\n";
                cout << "***********************************\n";
                for (int i=0; i<l; i++){
                    for (int e=0; e==0 || e==1; e++){
                        if (e==0) {
                            cout << i+1 << ". " << agenda[i][e] << " ";
                        } else {
                            cout << agenda[i][e] << endl;
                        }
                    }
                }
                cout << "***********************************\n\n";
                cout << "Scrivi il numero del contatto che vuoi modificare;\n";
                int num_modifica;
                cin >> num_modifica;
                cout << "Scrivi 'N' se vuoi modificare il nome e il cognome o 'C' il numero:";
                char modifica;
                cin >> modifica;
                 
                switch(toupper(modifica)) {
                    case 'N': {
                     // l'utente ha deciso di modificare il nome o il cognome del contatto, quindi creiamo due nuove stringhe(nomen, cognomen), che conterranno i nuovi dati, che vanno a costituire un'altra stringa; questo lo facciamo perchè già precedentemente abbiamo considerato nome e cognome come una stringa unica.//
                        cout << "Nuovo nome:  ";
                        string nomen;
                        cin >> nomen;
                        nomen[0] = toupper(nomen[0]);
                        string cognomen;
                        cout << "Nuovo Cognome:  ";
                        cin >> cognomen;
                        cognomen[0] = toupper(cognomen[0]);
                        string nomeint = cognomen + " " + nomen;
                        agenda[num_modifica-1][0] = nomeint;
                        cout << "Contatto modificato: ";
                        cout << agenda[num_modifica-1][0] << "  ";
                        cout << agenda[num_modifica-1][1] << endl;
                    } break;
                    case 'C': {
                     // il nuovo numero inserito dall'utente lo trattiamo come stringa e l'unico controllo che facciamo è che sia di 10 cifre per controllare se è valido; dopo di che lo aggiungiamo alla rubrica//
                        string numeron;
                        cout << "Nuovo numero: ";
                        cin >> numeron;
                        while (numeron.size() != 10) {
                            cout << "Numero non esistente, riprova: ";
                            cin >> numero;
                            }
                        agenda[num_modifica-1][1] = numeron;
                        cout << "Contatto modificato: ";
                        cout << agenda[num_modifica-1][0] << "  ";
                        cout << agenda[num_modifica-1][1] << endl;
                    }
                }
            } break;
             
            case 3: {
             // nel caso dell'eliminazione di un contatto chiediamo all'utente di inserire il numero del contatto che desidera cancellare e successivamnte lo eliminiamo dalla rubrica con la funzione erase//
                sort(agenda.begin(),agenda.end(),compareinterval);
                int l = agenda.size();
                cout << "CONTATTI IN AGENDA\n";
                cout << "***********************************\n";
                for (int i=0; i<l; i++){
                    for (int e=0; e==0 || e==1; e++){
                        if (e==0) {
                            cout << i+1 << ". " << agenda[i][e] << " ";
                        } else {
                            cout << agenda[i][e] << endl;
                        }
                    }
                }
                cout << "***********************************\n";
                cout << "Scrivi il numero del contatto che vuoi eliminare:\n";
                int elimina_contatto;
                cin >> elimina_contatto;
                 
                for(int i = 0; i< agenda.size(); i++){
                    if ( elimina_contatto == i+1){
                        agenda.erase(agenda.begin()+i);
                        cout << "Contatto eliminato!\n";
                        break;
                    } else {
                      cout << "Numero contatto non esistente\n";
                      break;
                    } 
                }
            } break;
                 
            case 4: { 
              // nel caso 'cerca per nome o per cognome' salviamo la stringa inserita dall'utente in nuove variabili, che controlliamo siano uguali a quelle già salvate nella rubrica. Avendo considerato nome e cognome come una stringa unica separata dallo spazio, abbiamo dovuto dividere la stringa contenente il nome e cognome in due sottostringhe, che compariamo con i valori inseriti dall'utente nel momento della ricerca//
                vector < vector<string> > contatti_trovati;
                char comando;
                int contatore = 0;
                cout << "Scrivi 'N' se vuoi cercare un contatto per nome o 'C' per cognome:\n";
                cin >> comando;
                if (toupper(comando) == 78){
                    string nome;
                    cout << "Inserire nome:\n";
                    cin >> nome;
                    nome[0] = toupper(nome[0]);
                    for(int i = 0; i<agenda.size(); i++){
                        int pos = agenda[i][0].find(" ");
                        if(agenda[i][0].substr(pos+1) == nome){
                            contatti_trovati.push_back(agenda[i]);
                            contatore++;
                        }
                    }
                }else if (toupper(comando) == 67){
                    string cognome ;
                    cout << "Inserire cognome:\n";
                    cin >> cognome;
                    cognome[0] = toupper(cognome[0]);
                    for(int i = 0; i<agenda.size(); i++){
                        if(agenda[i][0].substr(0,cognome.length()) == cognome){
                            contatti_trovati.push_back(agenda[i]);
                            contatore++;
                        }
                    }
                }

                if(contatore != 0){
                    cout << "\nCONTATTI TROVATI\n";
                    cout << "***********************************\n";
                    for (int i=0; i<contatti_trovati.size(); i++){
                        for (int e=0; e==0 || e==1; e++){
                            if (e==0) {
                                cout << i+1 << ". " << contatti_trovati[i][e] << " ";
                            } else {
                                cout << contatti_trovati[i][e] << endl;
                            }
                        }
                    }
                    cout << "***********************************\n";
                }else{
                    cout << "Nessun contatto trovato\n";
                }

            } break;
             
            case 5:{ // caso in cui viene visualizzata l'intera rubrica: stampiamo ogni elemento presente all'interno del vettore agenda//
                sort(agenda.begin(),agenda.end(),compareinterval);
                int l = agenda.size();
                cout << "CONTATTI IN AGENDA\n";
                cout << "***********************************\n";
                for (int i=0; i<l; i++){
                    for (int e=0; e==0 || e==1; e++){
                        if (e==0) {
                            cout << i+1 << ". " << agenda[i][e] << " ";
                        } else {
                            cout << agenda[i][e] << endl;
                        }
                    }
                }
                cout << "***********************************\n";
            } break;
             
            case 6: { // caso in cui l'agenda viene eliminata e quindi viene pulito il terminale//
                if (getenv("windir") == NULL){
                    system("clear");
                } else {
                    system("cls");
                };
                cout << "La tua rubrica è stata eliminata\n\n";
            } break;
             
            case 7:{ // caso in cui vengono visualizzati tutti i preferiti, un vettore contenente i vari contatti che sono stati aggiunti//
                int z = Preferiti.size();
                if (Preferiti.empty() == true) {
                cout << "Non ci sono Preferiti\n\n";
                }
                sort(Preferiti.begin(),Preferiti.end(),compareinterval);
                for (int i=0; i<z; i++){
                    for (int e=0; e==0 || e==1; e++){
                        cout << Preferiti[i][e] << endl;
                    }
                }
            } break;
             
            case 8 : {
                cout << "Hai chiuso la rubrica"<< endl;
            } break;
             
            default:{
                cout << "\nOperazione non esistente, inserisci il numero corrispondente all'azione che vuoi eseguire o 8 per uscire\n";
            } break;
        }
    }
    return 0;
}
