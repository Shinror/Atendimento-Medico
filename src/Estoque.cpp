#include <iostream>
#include <string.h>

#include "Estoque.h"

Estoque::Estoque(std::string Nome, std::string dosagem, int qtd){
  Remedios.emplace_back(Nome,dosagem);
  quantidade.push_back(qtd);
}

Estoque::Estoque(nlohmann::json& obj){
  for(auto& RemediosJson : obj["Remedios"]){
    Remedios.emplace_back(RemediosJson);
  }
  for(auto quantidadejson : obj["quantidade no estoque"]){
    quantidade.push_back(quantidadejson);
  }
}

nlohmann::json Estoque::serializar(){
  nlohmann::json obj;

  obj["Remedios"] = nlohmann::json::array();
  obj["quantidade no estoque"] = nlohmann::json::array();
  for(size_t i = 0 ; i < Remedios.size(); i++){
    obj["Remedios"].push_back(Remedios[i].serializar());
    obj["quantidade no estoque"].push_back(quantidade);
  }
}

void Estoque::listar(){
  std::cout<<"-----------------------------";
  for(size_t i = 0; i < Remedios.size();i++){
    Remedios[i].Exibir();
    std::cout<< "\nQuantidade caixas em estoque: "<< quantidade[i]<<"-----------------------------";
  }
}