
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

  std::string inventario[50];
  int QuantidadeItens;
  std::vector<int> tecnicas;
  std::string tecnicasNomes[5];
  int QuantidadeTecnicas;
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

  void CalcVidaDano() {
    int DANO;
      std::cout << "Quanto de dano você recebeu?" << std::endl;
      std::cin >> DANO;
      PVATUAL = PVATUAL - DANO ;
  }

  void CalcVidaCura() {
    int CURA;
      std::cout << "Quanto você curou" << std::endl;
      std::cin >> CURA;
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

  void TecnicasArquetipos(int IndicadorTecnicas) {
    switch (IndicadorTecnicas)
    {
    case 1:
      if (nivel == 1) {
        tecnicasNomes[0] = {"Mestre de armas"};
        QuantidadeTecnicas = 1;
      } else if (nivel == 3) {
        tecnicasNomes[1] = {"Combo rapido"};
        QuantidadeTecnicas = 2;
      } else if (nivel == 5) {
        tecnicasNomes[2] = {"Troca tatica"};
        QuantidadeTecnicas = 3;
      } else if (nivel == 7) {
        tecnicasNomes[3] = {"Estilo adaptavel"};
        QuantidadeTecnicas = 4;
      } else if (nivel == 10) {
        tecnicasNomes[4] = {"a"};
        QuantidadeTecnicas = 5;
      }
      break;
    case 2:
      if (nivel == 1) {
        tecnicasNomes[0] = {"Molde inicial"};
        QuantidadeTecnicas = 1;
      } else if (nivel == 3) {
        tecnicasNomes[1] = {"Armadura condensada"};
        QuantidadeTecnicas = 2;
      } else if (nivel == 5) {
        tecnicasNomes[2] = {"Construcao persistente"};
        QuantidadeTecnicas = 3;
      } else if (nivel == 7) {
        tecnicasNomes[3] = {"Barreira reflexiva"};
        QuantidadeTecnicas = 4;
      } else if (nivel == 10) {
        tecnicasNomes[4] = {"Criacao suprema"};
        QuantidadeTecnicas = 5;
      }      
      break;
    case 3:
      if (nivel == 1) {
        tecnicasNomes[0] = {"Descarga mistica"};
        QuantidadeTecnicas = 1;
      } else if (nivel == 3) {
        tecnicasNomes[1] = {"Amplificar tecnica"};
        QuantidadeTecnicas = 2;
      } else if (nivel == 5) {
        tecnicasNomes[2] = {" Estouro de zona"};
        QuantidadeTecnicas = 3;
      } else if (nivel == 7) {
        tecnicasNomes[3] = {"Auria expandida"};
        QuantidadeTecnicas = 4;
      } else if (nivel == 10) {
        tecnicasNomes[4] = {"Tempestade final"};
        QuantidadeTecnicas = 5;
      }
      break;
    case 4:
      if (nivel == 1) {
        tecnicasNomes[0] = {"Corpo Reforçado"};
        QuantidadeTecnicas = 1;
      } else if (nivel == 3) {
        tecnicasNomes[1] = {"Impacto potente"};
        QuantidadeTecnicas = 2;
      } else if (nivel == 5) {
        tecnicasNomes[2] = {"Canalizar Dor"};
        QuantidadeTecnicas = 3;
      } else if (nivel == 7) {
        tecnicasNomes[3] = {"Auria ativa"};
        QuantidadeTecnicas = 4;
      } else if (nivel == 10) {
        tecnicasNomes[4] = {"Explosão Interna"};
        QuantidadeTecnicas = 5;
      }
      break;

    
    default:
      break;
    }
  }

  void InserirItens() {
    int teste;
    
    while (teste != 0)
    {
      std::cout << "Qual item voce deseja adicionar?" << std::endl;
      std::cin >> inventario[QuantidadeItens];
      std::cout << "Deseja continuar?" << std::endl;
      std::cin >> teste;
      QuantidadeItens++;
    }
  }
  void ExcluirItens() {
    int ItemExcluido;
    int i;
      std::cout << "Qual item voce deseja excluir?" << std::endl;
      std::cin >> ItemExcluido;
      i = ItemExcluido;
      if (i == QuantidadeItens ) {
        inventario[i-1] = " ";
        std::cout << "Item excluido" << std::endl;
        QuantidadeItens--;
      } else if (i < QuantidadeItens) {
      for (i = ItemExcluido; i - 1 < QuantidadeItens; i++) {
        inventario[i-1] = inventario[i];
        i++;
        std::cout << "Item excluido" << std::endl;
        QuantidadeItens--;
      }
    } else {
      std::cout << "ERRO: ITEM NAO ENCONTRADO" << std::endl;
    }
    }

  void attStatus() {
    char resposta;
    std::cout << "Qual status você deseja atualizar?" << std::endl;
    std::cin >> resposta;

    if (resposta == 'F') {
      std::cout << "Muito bem, atualize a forca - Seu valor atual e" << FOR << std::endl;
      std::cin >> FOR;
    } else if (resposta == 'D') {
      std::cout << "Muito bem, atualize a destreza - Seu valor atual e" << DES << std::endl;
      std::cin >> DES; 
    } else if (resposta == 'C') {
      std::cout << "Muito bem, atualize a constituicao - Seu valor atual e" << CON << std::endl;
      std::cin >> CON;
    } else if (resposta == 'I') {
      std::cout << "Muito bem, atualize a inteligencia - Seu valor atual e" << INT << std::endl;
      std::cin >> INT;
    } else if (resposta == 'S') {
      std::cout << "Muito bem, atualize o carisma - Seu valor atual e" << CAR << std::endl;
      std::cin >> CAR;
    } else if (resposta == 'A') {
      std::cout << "Muito bem, atualize a auria - Seu valor atual e" << AUR << std::endl;
      std::cin >> AUR;
    }
    
    
  }
};





#endif //Completa o ifndef :)
