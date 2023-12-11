#include "json.hpp"
#include "remedio.h"
#include <vector>

struct Prontuario{
  std::string MotivoConsulta, Sinais,Diagnostico, Observacao, DiaDaConsulta; 
  std::vector<Remedio> Prescricao;
  long int Codigo;

  Prontuario() = default;

  Prontuario(std::string motivoconsulta, std::string sinais,std::string diagnostico, std::string observacao);
  Prontuario(nlohmann::json obj);

  nlohmann::json serializar();

  void addRemdios(std::string iremedio,std::string idose);
  void Exibir();
};