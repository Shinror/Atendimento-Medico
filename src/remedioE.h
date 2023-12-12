#include "json.hpp"

struct RemedioE{
  std::string Nome, Doses;

  RemedioE(std::string nome,std::string dose);
  RemedioE(nlohmann::json obj);

  nlohmann::json serializar();

  void Exibir();
};