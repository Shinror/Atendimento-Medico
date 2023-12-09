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

  for(auto& ProntuarioJson : obj["Prontuarios"]){
    Prontuarios.emplace_back(ProntuarioJson);//!ver com o professor
  }
}

nlohmann::json Paciente::serializar(){
  nlohmann::json obj;

  obj["Nome"] = Nome;
  obj["Data Nascimento"] = DataNascimento;
  obj["Email"] = Email;
  obj["CPF"] =  CPF;
  obj["Alergias"] = Alergias;
  obj["Deficiencias"] = Deficiencias;
  obj["Prontuarios"] = nlohmann::json::array();
  for(size_t i =0;i< Prontuarios.size();i++){
    obj["Prontuarios"].push_back(Prontuarios[i].serializar());
  }

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

void Paciente::NovoProntuario(){

}
void Paciente::MostrarProntuarios(){
  std::cout<<"> Prontuarios do "<< Nome <<std::endl;
  for(size_t i = 0 ; i < Prontuarios.size(); i++){
    Prontuarios[i].Exibir();
    std::cout<<"--------------------------"<<std::endl;
  }
}