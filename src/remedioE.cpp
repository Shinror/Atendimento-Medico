#include <iostream>

#include "remedioE.h"

Remedio::Remedio(std::string nome,std::string dose)
  : Nome(nome),Doses(dose)
{}

Remedio::Remedio(nlohmann::json obj){
  Nome = obj["Nome do Remedio"];
  Doses = obj["Dose do Remedio"];
}

nlohmann::json Remedio::serializar(){
  nlohmann::json obj;

  obj["Nome do Remedio"] = Nome;
  obj["Dose do Remedio"] = Doses;

  return obj;
}

void Remedio::Exibir(){
  std::cout<< "Nome do Remedio : "<< Nome<< "\nDosagem: "<<Doses; 
}