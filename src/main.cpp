#include "ficha.hpp"
#include <iostream>
#include <string> //Biblioteca para strings
#include <vector> //Biblioteca para vetores
#include <array>
#include <cstdlib> 
#include <fstream>




using namespace std;
ficha personagem;
bool fichacriada = false;

bool criarapagarficha (bool statusFicha) {
 int confimarExclusao;
  if (statusFicha = false) {
    //criacaodeFicha();
    return true;
  } else {
    cout << "Esta acao ira apagar sua ficha atual, se quiser mesmo fazer isso digite 1, se nao digite 2";
    cin >> confimarExclusao;
    if (confimarExclusao = 1) {
      return criarapagarficha(false);
    } else {
      return true;
    }
  }
}

void criacaodeFicha () {
  fichacriada = true;
  cout << "Bem vindo a criação de ficha do seu personagem" << endl;
  cout << "Qual o nome do seu personagem?" << endl;
  cin >> personagem.nome;
  cout << "Qual a raca do seu personagem?" << endl;
  cin >> personagem.raca;
  cout << "Qual o seu arquetipo?" << endl;
  cin >> personagem.arquetipo;
  cout << "Qual o seu estilo de Auria?" << endl;
  cin >> personagem.estiloAuria;
  personagem.nivel = 1;

  cout << "Agora, coloque os atributos na sequencia - FOR | DES | CON | INT | CAR | AUR" << endl;
  cin >> personagem.FOR; cin >> personagem.DES; cin >> personagem.CON; cin >> personagem.INT;
  cin >> personagem.CAR; cin >> personagem.AUR;

  cout << "Quantos pontos de vida você tem?" << endl;
  cin >> personagem.PV;
  personagem.PVATUAL = personagem.PV;
  personagem.CalcAP();
  personagem.CalcCA();
  personagem.CalcIniciativa();

  for (int i = 0; i < 3; i++) {
    cout << "Quais as suas pericias?" << endl;
    cin >> personagem.pericias[i];
  }
  personagem.InserirItens();
  personagem.tecnicasdespertar = {""};
}

void displayFicha() {
  #ifdef _WIN32
  system("cls"); // Para Windows
  #else
  system("clear"); // Para Linux/macOS
  #endif
  cout << "Nome:  " << personagem.nome << endl;
  cout << "Raca:  " << personagem.nomearRaca() << endl;
  cout << "Arquetipo: " << personagem.nomearArquetipo() << endl;
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
  for (int i = 0; i < 3; i++) {
    cout << "Pericia" << i+1 <<": " << personagem.NomePericia(personagem.pericias[i]) << " + " << personagem.ModPericia(personagem.pericias[i]) << endl;
  }
  cout << endl;
  cout << "Tecnicas: " << endl;
  personagem.TecnicasArquetipos(personagem.arquetipo);
  for (int i = 0; i < personagem.QuantidadeTecnicas; i++) {
    cout << personagem.tecnicasNomes[i] << endl;
  }
  cout << endl;
  cout << "Inventario: " << endl;
  for (int i = 0; i < personagem.QuantidadeItens; i++) {
    cout << personagem.inventario[i] << endl;
  }

  //cout << "Tecnicas Desp: " << endl << pers onagem.tecnicasdespertar[0] << endl << personagem.tecnicasdespertar[1] << endl;
  //cout << "Inventario: " << endl << personagem.inventario[0] << endl << personagem.inventario[1] << endl << personagem.inventario[2];
}

int main() {
  int RespostaUser;
  ofstream outFile;

  criacaodeFicha();
  displayFicha();
  cout << endl;
  cout << "Oque quer fazer agora?" << endl;
  cin >> RespostaUser; 

  while (RespostaUser != 0)
  { 
   switch (RespostaUser)
  {
  case 1: // Atualizar Status
  personagem.attStatus();
  displayFicha();
    break;
  case 2: // Incluir itens 
  personagem.SubirNivel();
  displayFicha();
    break;
  case 3: // Excluir itens
  personagem.ExcluirItens();
  displayFicha();
    break;
  case 4: // Subir nivel
  personagem.SubirNivel();
  displayFicha();
    break;
  case 5: // Adcionar Tecnicar Despertadas
  
    break;
  case 6: // Cura
  
    break;
  case 7:
    beak: // Dano
  default:
    break;
  }
  cout << "Oque quer fazer agora?" << endl;
  cin >> RespostaUser; 
  }
  

  };