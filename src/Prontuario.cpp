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
  
  
  
  for (auto reme : obj["Remedio"])
  {
    Remedios.push_back(reme);
  }
  for (auto dose : obj["Doses"])
  {
    Doses.push_back(dose);
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

    obj["Remedios"] = nlohmann::json::array();
    for(size_t i = 0;i<Remedios.size();i++){
      obj["Remedios"].push_back(Remedios[i]);
    }

    obj["Doses"] = nlohmann::json::array();
    for(size_t i = 0;i<Doses.size();i++){
      obj["Doses"].push_back(Doses[i]);
    }


    return obj;
}


void Prontuario::addRemdios(std::string iremedio,std::string idose){
  Remedios.push_back(iremedio);
  Doses.push_back(idose);
}

