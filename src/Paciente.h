#include"json.hpp"
#include "Prontuario.h"

#include <vector>

struct Paciente{
  std::string Nome, Email, CPF, DataNascimento, Alergias,Deficiencias;
  std::vector<Prontuario> Prontuarios;

  Paciente() = default;

  Paciente(std::string nome ,std::string email, std::string cpf, std::string datanascimento,std::string alergias , std::string deficiencias);
  Paciente(nlohmann::json& obj);

  nlohmann::json serializar();

  void Exibir();
  void MostrarProntuarios();
};