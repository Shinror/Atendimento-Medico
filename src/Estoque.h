#include "json.hpp"
#include "remedio.h"

#include <vector>


struct Estoque{
  std::vector<Remedio> Remedios;
  std::vector<int>quantidade;

  Estoque(std::string Nome, std::string dosagem, int qtd);
  Estoque(nlohmann::json& obj);

  nlohmann::json serializar();

  void listar();  
};