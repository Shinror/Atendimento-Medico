#include "json.hpp"

struct Remedio{
  std::string Nome, Doses;

  Remedio(std::string nome,std::string dose);
  Remedio(nlohmann::json obj);

  nlohmann::json serializar();

  void Exibir();
};