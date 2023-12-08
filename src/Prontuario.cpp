#include <iostream>
#include <string>

#include "Prontuario.h"


Prontuario::Prontuario(std::string motivoconsulta, std::string sinais,std::string diagnostico, std::string observacao, std::string diadaconsulta,int cod)
  : MotivoConsulta(motivoconsulta), Sinais(sinais), Diagnostico(diagnostico),Observacao(observacao),DiaDaConsulta(diadaconsulta),Codigo(cod)
{}

Prontuario::Prontuario(nlohmann::json obj){//deserializar

  std::string code = std::to_string(Codigo);

  MotivoConsulta = obj[code]["Motivo da Consulta"];
  Sinais = obj[code]["Sinais"];
  Diagnostico = obj[code]["Diagnostic"];
  Observacao =obj[code]["Observação"];
  DiaDaConsulta = obj[code]["Dia da consulta"];
}
