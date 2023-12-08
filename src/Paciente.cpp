#include <iostream>

#include "Paciente.h"


Paciente::Paciente(std::string nome ,std::string email, std::string cpf, std::string datanascimento,std::string alergias , std::string deficiencias)
 :Nome(nome),Email(email),CPF(cpf),DataNascimento(datanascimento), Alergias(alergias),Deficiencias(deficiencias)
{}


Paciente::Paciente(nlohmann::json& obj){ 
  Nome = obj["Nome"];
  DataNascimento = obj["Data Nascimento"];
  Email = obj["Email"];
  CPF = obj["CPF"];
  Alergias = obj["Alergias"];
  Deficiencias = obj["Deficiencias"];
}

nlohmann::json Paciente::serializar(){
  nlohmann::json obj;

  obj["Nome"] = Nome;
  obj["Data Nascimento"] = DataNascimento;
  obj["Email"] = Email;
  obj["CPF"] =  CPF;
  obj["Alergias"] = Alergias;
  obj["Deficiencias"] = Deficiencias;

  return obj;
}


void Paciente::Exibir(){
  std::cout<<"Nome do paciente: "<< Nome <<std::endl;
  std::cout<<"Data de nascimento do paciente : "<< DataNascimento<<std::endl;
  std::cout<<"Email de contato: "<< Email<<std::endl;
  std::cout<<"CPF do paciente: "<< CPF <<std::endl;
  std::cout<<"As alergias do paciente: "<<Alergias<<std::endl;
  std::cout<<"As deficiencias do paciente: "<<Deficiencias <<std::endl;
}