#include "json.hpp"
#include <vector>

struct Prontuario{
  std::string MotivoConsulta, Sinais,Diagnostico, Observacao, DiaDaConsulta; 
  std::vector<std::string> Remedios, Doses;//* decidindo o q fazer
  int Codigo;

  Prontuario() = default;

  Prontuario(std::string motivoconsulta, std::string sinais,std::string diagnostico, std::string observacao, std::string diadaconsulta,int cod);
  Prontuario(nlohmann::json obj);

  nlohmann::json serializar();

  void Exibir();
  void addRemdios(std::vector<std::string> remedios,std::vector<std::string> dosagem);

};