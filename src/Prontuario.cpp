#include <iostream>
#include <string>
#include <cstdio>
#include <cstime>

#include "Prontuario.h"


Prontuario::Prontuario(std::string motivoconsulta, std::string sinais,std::string diagnostico, std::string observacao, std::string diadaconsulta,int cod)
  : MotivoConsulta(motivoconsulta), Sinais(sinais), Diagnostico(diagnostico),Observacao(observacao),DiaDaConsulta(diadaconsulta),Codigo(cod)
{
  std::srand(std::time(0));

  Codigo = std::rand() % 10000;
}

Prontuario::Prontuario(nlohmann::json obj){//deserializar
  MotivoConsulta = obj["Motivo da Consulta"];
  Sinais = obj["Sinais"];
  Diagnostico = obj["Diagnostico"];
  Observacao =obj["Observação"];
  DiaDaConsulta = obj["Dia da consulta"];
  Codigo = obj["Codigo do Prontuario"];
}

nlohmann::json Prontuario::serializar(){
    nlohmann::json obj;
    obj["Motivo da Consulta"] =MotivoConsulta;
    obj["Sinais"] = Sinais;
    obj["Diagnostico"] = Diagnostico;
    obj["Observação"] = Observacao;
    obj["Dia da consulta"] = DiaDaConsulta;
    obj["Codigo do Prontuario"] = Codigo;

    return obj;
}

void Prontuario::Exibir(){
  std::cout<< "Motivo da consulta :"<<MotivoConsulta<<std::endl;
  std::cout<<"Sinais Apresentados: "<< Sinais<<std::endl;
  std::cout<< "Diagnostico: "<<Diagnostico<<std::endl;
  std::cout<< "Observaçao : "<< Observacao<<std::endl;
  std::cout<< "Dia da consulta: "<<DiaDaConsulta<<std::endl;
  std::cout<< "\nCodigo do Prontuario:"<<Codigo<<std::endl;
}

  void Pronturaio::addRemdios(std::vector<std::string> remedios,std::vector<std::string> dosagem){

  }

