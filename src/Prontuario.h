#include "json.hpp"
#include <vector>

struct Prontuario{
  std::string MotivoConsulta, Sinais,Diagnostico, Observacao, DiaDaConsulta; 
  std::vector<std::string> Remedios, Doses;//* decidindo o q fazer
  long int Codigo;

  Prontuario() = default;

  Prontuario(std::string motivoconsulta, std::string sinais,std::string diagnostico, std::string observacao);
  Prontuario(nlohmann::json obj);

  nlohmann::json serializar();

  void Exibir();
  void addRemdios();

};