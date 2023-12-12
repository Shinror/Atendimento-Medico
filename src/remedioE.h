#include "json.hpp"

struct RemedioE{
  std::string Nome, Doses;
  int quantidade;
  
  RemedioE(std::string nome,std::string dose,int quantidade);
  RemedioE(nlohmann::json obj);

  nlohmann::json serializar();

  void Exibir();
};