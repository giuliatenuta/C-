#include <iostream>
#include <string>
using namespace std;
 
void VisualizzaOpzioni(){
 cout << "Ecco le operazioni possibili:" << endl;
 cout << "1. Visualizza tutti i contatti" << endl;
 cout << "2. Aggiungi contatto" << endl;
 cout << "3. Elimina contatto" << endl;
 cout << "4. Esci\n" << endl;
 cout << "Scrivi il numero corrispondente all'azione da eseguire: " << endl;
}

int main() {
  cout << "Benvenuto nella tua rubrica!" << endl;
  int azione;
  string numero;
  string nome;
  string cognome;
  string nomeint;
  string rubrica[30][2];
  int l= 30;
  for (int i=0; i< l; i++) {
    for (int e=0; e<2; e++) {
      rubrica[i][e] = "";
    }
  }
  rubrica[0][0] = "Meccanico Massimo";
  rubrica[0][1] = "3312565895";
  rubrica[1][0] = "Asternisi Lorenzo";
  rubrica[1][1] = "3289856566";

  

  while (azione!=4) {
    VisualizzaOpzioni();
    cin >> azione;
    int ci;
 
   switch(azione){
     case 1:
     cout << "***************************************" << endl;
     for (int i=0; i<l; i++) {
     	if (rubrica[i][1] != "") {
     			cout << i+1 << ". " << rubrica[i][0] << endl;
      			cout << "   " << rubrica[i][1] << endl;
		 } 
     }
     cout << "***************************************" << endl;
     break;
 
     case 2:
     cout << "Inserisci il nome del nuovo contatto: " << endl;
     cin >> nome;
     nome[0] = toupper(nome[0]);
     cout << "\nCognome: " << endl;
     cin >> cognome;
     cognome[0] = toupper(cognome[0]);
     cout << "Numero: ";
     cin >> numero;

     while (numero.size() != 10) {
      cout << "Numero non esistente, riprova: ";
      cin >> numero;
     }
     cout << "Nuovo contatto creato!\n\n" ;
     nomeint = cognome + " " + nome;
     for (int i=0; i<l; i++) {
        if (rubrica[i][1] == "") {
          rubrica[i][0] = nomeint;
          rubrica[i][1] = numero;
          break;
        } 
      }
      break;
 
     case 3:
     cout << "Contatto da eliminare: ";
     int elimina;
     cin >> elimina;
     rubrica[elimina-1][0] = "";
     rubrica[elimina-1][1] = "";
     cout << "Contatto eliminato con successo!\n\n";
     break;
 
     default:
     	cout << "\nOperazione non esistente, inserisci il numero corrispondente all'azione che vuoi eseguire\n";
     break;
   }
  };
 
  
 return 0;
 }
