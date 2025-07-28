
#ifndef FICHA_HPP
#define FICHA_HPP
// Guards para que o arquivo não seja incluido duas vezes, evita erros de compilação

#include <string> //Biblioteca para strings
#include <vector> //Biblioteca para vetores

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
  int AP;
  int CA;

  int Iniciativa;

  std::vector<int> pericias;
/*   int Perícia1;
  int Perícia2;
  int Perícia3;
  int Perícia4;
  int Perícia5; */

  std::vector<std::string> inventario;
  std::vector<int> tecnicas;
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
    return "Não existe esta raca";
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
    return "Não existe esta raca";
  }
  }

  void SubirNivel() {
    nivel+= 1;
  }
};








#endif //Completa o ifndef :)
