#include "ficha.hpp"
#include <iostream>

using namespace std;

string ficha::nomearRaca() const {
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

