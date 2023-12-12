#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#include "Prontuario.h"


Prontuario::Prontuario(std::string motivoconsulta, std::string sinais,std::string diagnostico, std::string observacao)
  : MotivoConsulta(motivoconsulta), Sinais(sinais), Diagnostico(diagnostico),Observacao(observacao)
{
  std::srand(std::time(NULL));
  Codigo = std::rand() % 10000+1;

  time_t momento = time(nullptr);
  struct tm* timeInfo = localtime(&momento);
  
  int dia = timeInfo->tm_mday;
  int mes = timeInfo->tm_mon +1;
  int ano = timeInfo->tm_year +1900;


  DiaDaConsulta = std::to_string(dia) + " / " +  std::to_string(mes) + " / "+ std::to_string(ano);



}

Prontuario::Prontuario(nlohmann::json obj){//deserializar
  MotivoConsulta = obj["Motivo da Consulta"];
  Sinais = obj["Sinais"];
  Diagnostico = obj["Diagnostico"];
  Observacao =obj["Observação"];
  DiaDaConsulta = obj["Dia da consulta"];
  Codigo = obj["Codigo do Prontuario"];
  
  for(auto& prec : obj["Prescricao"]){
    Prescricao.emplace_back(prec);
  }
  

}

nlohmann::json Prontuario::serializar(){
  nlohmann::json obj;
  obj["Motivo da Consulta"] =MotivoConsulta;
  obj["Sinais"] = Sinais;
  obj["Diagnostico"] = Diagnostico;
  obj["Observação"] = Observacao;
  obj["Dia da consulta"] = DiaDaConsulta;
  obj["Codigo do Prontuario"] = Codigo;

  obj["Precricao"] = nlohmann::json::array();
  for(size_t i = 0 ; i < Prescricao.size(); i++){
    obj["Prescricao"].push_back(Prescricao[i].serializar());
  }
  
  return obj;
}

void Prontuario::Exibir(){
  std::cout<< "Motivo da consulta :"<< MotivoConsulta<<std::endl;
  std::cout<<"Sinais Apresentados: "<< Sinais<<std::endl;
  std::cout<< "Diagnostico: "<< Diagnostico<<std::endl;
  std::cout<< "Observaçao : "<< Observacao<<std::endl;
  std::cout<< "Dia da consulta: "<< DiaDaConsulta<<std::endl;
  std::cout<< "\nCodigo do Prontuario:"<< Codigo<<std::endl;
  std::cout<<"Prescrição :"<<std::endl;
  for(size_t i =0 ; i < Prescricao.size(); i++){
    Prescricao[i].Exibir();
    std::cout<< std::endl;
  }

}
void Prontuario::addRemdios(std::string iremedio,std::string idose){
  Prescricao.emplace_back(iremedio,idose);
}

