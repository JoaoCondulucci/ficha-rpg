#include "ficha.hpp"
#include <iostream>

using namespace std;
int main() {
  ficha personagem;
  personagem.nome = "Kloister";
  personagem.raca = 1;
  personagem.arquetipo = 4;
  personagem.estiloAuria = 3;
  personagem.nivel = 1;

  personagem.FOR = 0;
  personagem.DES = 0;
  personagem.CON = 0;
  personagem.INT = 0;
  personagem.CAR = 0;
  personagem.AUR = 0;

  personagem.PV = 89;
  personagem.PVATUAL = personagem.PV;
  personagem.AP = 123;
  personagem.CA = 239;

  personagem.Iniciativa = 2930;

  personagem.pericias = {103, 104, 108} ;
/*   int Perícia1;
  int Perícia2;
  int Perícia3;
  int Perícia4;
  int Perícia5; */

  personagem.inventario = {"Batata assada", "Bazooka", "Mel"};
  personagem.tecnicas = {1, 42, 13};
  personagem.tecnicasdespertar = {"Socos flamejantes", "Ira do dragao"};

  //-----------------------------------------------------
  cout << "Nome:  " << personagem.nome << endl;
  cout << "Raca:  " << personagem.nomearRaca() << endl;
  cout << "Arquétipo: " << personagem.nomearArquetipo() << endl;
  cout << "Auria: " << personagem.nomearAuria() << endl;
  cout << "Nivel: " << personagem.nivel << endl;

  cout << endl;

  cout << "-------------------------- STATUS -------------------------" << endl;
  cout << 
  "FOR: " << personagem.FOR << "(" << personagem.statusMods(personagem.FOR) << ") || " << 
  "DES: " << personagem.DES << "(" << personagem.statusMods(personagem.DES) << ") || " << 
  "CON: " << personagem.CON << "(" << personagem.statusMods(personagem.CON) << ") || " << 
  "INT: " << personagem.INT << "(" << personagem.statusMods(personagem.INT) << ") || " << 
  "CAR: " << personagem.CAR << "(" << personagem.statusMods(personagem.CAR) << ") || " << 
  "AUR: " << personagem.AUR << "(" << personagem.statusMods(personagem.AUR) << ")" << endl;
  cout << endl;
  cout << "PV MAX: " << personagem.PV << endl;
  cout << "PV ATUAL: " << personagem.PVATUAL << endl;
  cout << "AP: " << personagem.AP << endl;
  cout << "CA: " << personagem.CA << endl;
  cout << "Iniciativa: " << personagem.Iniciativa << endl;

  cout << endl;

  cout << "-------------------------- ATAQUES -------------------------" << endl;
  cout << "Pericia 1: " << personagem.pericias[0] << endl;
  cout << "Pericia 2: " << personagem.pericias[1] << endl;
  cout << "Pericia 3: " << personagem.pericias[2] << endl;
  cout << endl;
  cout << "Tecnicas: " << endl << personagem.tecnicas[0] << endl << personagem.tecnicas[1] << endl << personagem.tecnicas[2];
  cout << "Tecnicas Desp: " << endl << personagem.tecnicasdespertar[0] << endl << personagem.tecnicasdespertar[1] << endl;
  cout << "Inventario: " << endl << personagem.inventario[0] << endl << personagem.inventario[1] << endl << personagem.inventario[2];
};