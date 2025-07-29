
#ifndef FICHA_HPP
#define FICHA_HPP
// Guards para que o arquivo não seja incluido duas vezes, evita erros de compilação

#include <string> //Biblioteca para strings
#include <vector> //Biblioteca para vetores
#include <array>
#include <iostream>

struct ficha
{ 
  std::string nome;
  int raca;
  int arquetipo;
  int estiloAuria;
  int nivel;
  
  //Atributos
  int FOR;
  int DES;
  int CON;
  int INT;
  int CAR;
  int AUR;

  int PV;
  int PVATUAL;
  int AP;
  int CA;

  int Iniciativa;

  int pericias[3];
  std::vector<std::string> ListaPericias;

  
/*   int Perícia1;
  int Perícia2;
  int Perícia3;
  int Perícia4;
  int Perícia5; */

  std::vector<std::string> inventario;
  int QuantidadeItens;
  std::vector<int> tecnicas;
  std::vector<std::string> tecnicasNomes;
  std::vector<std::string> tecnicasdespertar;


  std::string nomearRaca() const {
  switch (raca)
  {
  case 1:
    return "Humano";
    break;
  case 2:
    return "Quimera";
    break;
  case 3:
    return "Demonio";
    break;
  case 4:
    return "Hibrido";
    break;
  case 5:
    return "Herdeiro";
    break;
  case 6:
    return "Anjo";
    break;
  default:
    return "Não existe esta raca";
  }
  }

  std::string nomearArquetipo() const {
  switch (arquetipo)
  {
  case 1:
    return "Arsenalista";
    break;
  case 2:
    return "Refinador";
    break;
  case 3:
    return "Canalizador Externo";
    break;
  case 4:
    return "Canalizador Interno";
    break;
  default:
    return "Arquetipo inexistente";
  }
  }

  std::string nomearAuria() const {
  switch (estiloAuria)
  {
  case 1:
    return "Explosivo";
    break;
  case 2:
    return "Refinado";
    break;
  case 3:
    return "Defensivo";
    break;
  case 4:
    return "Instintivo";
    break;
  case 5:
    return "Oculto";
    break;
  case 6:
    return "Disforme";
    break;
  default:
    return "Estilo de auria inexistente";
  }
  }

  void SubirNivel() {
    nivel+= 1;

  }

  int statusMods(int Modificador) const {
    return (Modificador / 2 - 5);
  }

  void CalcVidaDano(int DANO) {
      PVATUAL = PVATUAL - DANO ;
  }

  void CalcVidaCura(int CURA) {
      PVATUAL = PVATUAL + CURA;
  }

  void CalcAP( ) {
      AP = 0;
      AP = 10 + (statusMods(AUR) * 2);
  }

  void CalcCA( ) {
      CA = 0;
      CA = 10 + statusMods(DES) /*+ Armadura*/;
  }  

  void CalcIniciativa( ) {
      Iniciativa = 0;
      Iniciativa = statusMods(DES);
  }

  std::string NomePericia(int NumPericia) {
      ListaPericias = {"Atletismo","Brutalidade","Luta Desarmada","Acrobacia","Furtividade","Pontaria","Reflexos","Resistencia Fisica","Sobrevivencia","Fortitude","Conhecimento","Investigacao","Tecnologia","Ciencia","Persuasao","Intimidacao","Atuacao","Lideranca","Canalizacao","Projecao","Refinamento","Manipulacao","Deteccao Aurica"};
      return ListaPericias[NumPericia];
}; 
  int ModPericia (int NumPericia) const {
    if (NumPericia >= 0 && NumPericia < 3) {
      return statusMods(FOR);
    } else if (NumPericia < 6) {
      return statusMods(DES) + 2;
    } else if (NumPericia < 9) {
      return statusMods(CON) + 2;
    } else if (NumPericia < 13) {
      return statusMods(INT) + 2;
    } else if (NumPericia < 16) {
      return statusMods(CAR) + 2;
    } else if (NumPericia < 20) {
      return statusMods(AUR) + 2;
    } else {
      return 333333;
    }; 
  }

  void TecnicasArquetipos() {
    switch (arquetipo)
    {
    case 1:
      if (nivel == 1) {
        tecnicasNomes = {"Mestre de armas"};
      } else if (nivel == 3) {
        tecnicasNomes = {"Mestre de armas", "Combo rapido"};
      } else if (nivel == 5) {
        tecnicasNomes = {"Mestre de armas", "Combo rapido", "Troca tatica"};
      } else if (nivel == 7) {
        tecnicasNomes = {"Mestre de armas", "Combo rapido", "Troca tatica", "Estilo adaptavel"};
      } else if (nivel == 10) {
        tecnicasNomes = {"Mestre de armas", "Combo rapido", "Troca tatica", "Estilo adaptavel", ""};
      }
      break;
    case 2:
      if (nivel == 1) {
        tecnicasNomes = {"Molde inicial"};
      } else if (nivel == 3) {
        tecnicasNomes = {"Molde inicial", "Armadura condensada"};
      } else if (nivel == 5) {
        tecnicasNomes = {"Molde inicial", "Armadura condensada", "Construcao persistente"};
      } else if (nivel == 7) {
        tecnicasNomes = {"Molde inicial", "Armadura condensada", "Construcao persistente", "Barreira reflexiva"};
      } else if (nivel == 10) {
        tecnicasNomes = {"Molde inicial", "Armadura condensada", "Construcao persistente", "Barreira reflexiva", "Criacao suprema"};
      }      
      break;
    case 3:
      if (nivel == 1) {
        tecnicasNomes = {"Descarga mistica"};
      } else if (nivel == 3) {
        tecnicasNomes = {"Descarga mistica", "Amplificar tecnica"};
      } else if (nivel == 5) {
        tecnicasNomes = {"Descarga mistica", "Amplificar tecnica", " Estouro de zona"};
      } else if (nivel == 7) {
        tecnicasNomes = {"Descarga mistica", "Amplificar tecnica", " Estouro de zona", "Auria expandida"};
      } else if (nivel == 10) {
        tecnicasNomes = {"Descarga mistica", "Amplificar tecnica", "Estouro de zona", "Auria expandida", "Tempestade final"};
      }
      break;
    case 4:
      if (nivel == 1) {
        tecnicasNomes = {"Corpo Reforçado"};
      } else if (nivel == 3) {
        tecnicasNomes = {"Corpo Reforçado", "Impacto potente"};
      } else if (nivel == 5) {
        tecnicasNomes = {"Corpo Reforçado", "Impacto potente", "Canalizar Dor"};
      } else if (nivel == 7) {
        tecnicasNomes = {"Corpo Reforçado", "Impacto potente", "Canalizar Dor", "Auria ativa"};
      } else if (nivel == 10) {
        tecnicasNomes = {"Corpo Reforçado", "Impacto potente", "Canalizar Dor", "Auria Ativa", "Explosão Interna"};
      }
      break;

    
    default:
      tecnicasNomes = {"Não encontrado"};
      break;
    }
  }
};






#endif //Completa o ifndef :)
