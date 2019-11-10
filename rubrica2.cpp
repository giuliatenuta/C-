#include <iostream>
#include <string>
using namespace std;
 
void VisualizzaOpzioni(){
 cout << "Benvenuto nella tua rubrica!" << endl;
 cout << "Ecco le operazioni possibili:" << endl;
 cout << "1. Visualizza tutti i contatti" << endl;
 cout << "2. Aggiungi contatto" << endl;
 cout << "3. Elimina contatto" << endl;
 cout << "4. Esci" << endl;
 cout << "Scrivi il numero corrispondente all'azione da eseguire: " << endl;
}


int main() {
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
  int ci=0;
  

  while (azione!=4) {
    VisualizzaOpzioni();
    cin >> azione;
 
   switch(azione){
     case 1:
     for (int i=0; i<l; i++) {
      if (rubrica[i][1] != "") {
        ci ++;
      }
     }
     cout << "***************************************" << endl;
     for (int i=0; i<ci; i++) {
      cout << i+1 << ". " << rubrica[i][0] << endl;
      cout << "   " << rubrica[i][1] << endl;
     }
     cout << "***************************************" << endl;
     ci=0;
     break;
 
     case 2:
     cout << "Inserisci il nome del nuovo contatto: " << endl;
     cin >> nome;
     cout << "\nCognome: " << endl;
     cin >> cognome;
     cout << "Numero: ";
     cin >> numero;

     while (numero.size() != 10) {
      cout << "Numero non esistente, riprova: ";
      cin >> numero;
     }
     nomeint = cognome + " " + nome;
     for (int i=0; i<l; i++) {
        if (rubrica[i][1] == "") {
          rubrica[i][0] = nomeint;
          rubrica[i][1] = numero;
          ci=0;
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
     cout << "Contatto eliminato con successo!";
     ci=0;
     break;
 
     default:
     	cout << "\nOperazione non esistente, inserisci il numero corrispondente all'azione che vuoi eseguire\n";
     break;
   }
  };
 
  
 return 0;
 }
