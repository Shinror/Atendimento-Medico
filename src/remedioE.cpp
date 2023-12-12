#include <iostream>

#include "remedioE.h"

RemedioE::RemedioE(std::string nome,std::string dose,int quantidade)
  : Nome(nome),Doses(dose), quantidade(quantidade)
{}

RemedioE::RemedioE(nlohmann::json obj){
  Nome = obj["Nome do Remedio"];
  Doses = obj["Dose do Remedio"];
  quantidade = obj["Quantidade de Caixas"];
}

nlohmann::json RemedioE::serializar(){
  nlohmann::json obj;

  obj["Nome do Remedio"] = Nome;
  obj["Dose do Remedio"] = Doses;
  obj["Quantidade de caixas"] = quantidade;

  return obj;
}

void RemedioE::Exibir(){
  std::cout<< "Nome do Remedio : "<< Nome<< "\nDosagem: "<<Doses<<"\n Quantidade de caixas:"<<quantidade<<std::endl; 
}