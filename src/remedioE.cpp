#include <iostream>

#include "remedioE.h"

RemedioE::RemedioE(std::string nome,std::string dose)
  : Nome(nome),Doses(dose)
{}

RemedioE::RemedioE(nlohmann::json obj){
  Nome = obj["Nome do Remedio"];
  Doses = obj["Dose do Remedio"];
}

nlohmann::json RemedioE::serializar(){
  nlohmann::json obj;

  obj["Nome do Remedio"] = Nome;
  obj["Dose do Remedio"] = Doses;

  return obj;
}

void RemedioE::Exibir(){
  std::cout<< "Nome do Remedio : "<< Nome<< "\nDosagem: "<<Doses; 
}