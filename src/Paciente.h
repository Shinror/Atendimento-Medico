#include"json.hpp"


struct Paciente{
  std::string Nome, Email, CPF, DataNascimento, Alergias,Deficiencias;

  Paciente() = default;

  Paciente(std::string nome ,std::string email, std::string cpf, std::string datanascimento,std::string alergias , std::string deficiencias);
  Paciente(nlohmann::json& obj);

  nlohmann::json serializar();

  void Exibir();
};