#include <iostream>
#include <string>

#include "Estoque.h"

Estoque::Estoque(std::string nome)
:Nome(nome)
{}

Estoque::Estoque(nlohmann::json& obj){
  Nome = obj["Nome do Estoque"];
  for(auto& RemediosJson : obj["Remedios"]){
    Remedios.emplace_back(RemediosJson);
  }
  for(auto quantidadejson : obj["quantidade no estoque"]){//!ver com o professor
    quantidade.push_back(quantidadejson);
  }
}

nlohmann::json Estoque::serializar(){
  nlohmann::json obj;

  obj["Nome do estoque"] = Nome;
  obj["Remedios"] = nlohmann::json::array();
  obj["quantidade no estoque"] = nlohmann::json::array();
  for(size_t i = 0 ; i < Remedios.size(); i++){
    obj["Remedios"].push_back(Remedios[i].serializar());
    obj["quantidade no estoque"].push_back(quantidade);
  }
}
void Estoque::registro(std::string Rnome, std::string Rdose,int Rquantidade){
  Remedios.emplace_back(Rnome,Rdose);
  quantidade.push_back(Rquantidade);
}

void Estoque::encontrar(std::string Liniciais){
  std::cout<<">Remedios no estoque com as mesmas iniciais: \n";
  
  bool acho = false;
  for (int i = 0; i < Remedios.size(); i++)
  {
    std::string rnome = Remedios[i].Nome;
    if(Liniciais[0] == rnome[0] and Liniciais[1] == rnome[1] and Liniciais[2] == rnome[2]){
      Remedios[i].Exibir();
      std::cout<<"\nQuantidade de caixas em estoque : "<<quantidade[i]<<"-----------------------------";

      acho == true;
    }//if comparacao 
  }
  if(! acho){
    std::cout<<"Nenhum remedio encontrado"<<std::endl;
  }
}


void Estoque::listar(){
  std::cout<<"-----------------------------";
  for(size_t i = 0; i < Remedios.size();i++){
    Remedios[i].Exibir();
    std::cout<< "\nQuantidade caixas em estoque: "<< quantidade[i]<<"-----------------------------";
  }
}

bool Estoque::adicionarqtd(std::string inptnome,std::string inptdose){
  int posicao;
  bool find = false;
  for(int i = 0 ; i< Remedios.size(); i++){
    if(Remedios[i].Nome == inptnome and Remedios[i].Doses == inptdose){
      posicao = i;
      find = true;
      break;
    }
  }
  if(!find){
    std::cout<<"Remedio não foi encontrado!"<<std::endl;
    return false;    
  }

  Remedios[posicao].Exibir();
  std::cout<<"Quantidade de caixas no estoque: "<< quantidade[posicao] <<std::endl;

  std::cout<<"Digite a quantidade de caixas novas: "<<std::endl;
  int add;
  std::cin>>add;

  quantidade[posicao] += add;

  std::cout<<"Quantidade nova de caixas: "<< quantidade[posicao]<<"\n";
  return true;

}
bool Estoque::usar(std::string inptnome,std::string inptdose){
  int posicao;
  bool find = false;
  for(int i = 0 ; i< Remedios.size(); i++){
    if(Remedios[i].Nome == inptnome and Remedios[i].Doses == inptdose){
      posicao = i;
      find = true;
      break;
    }
  }
  if(!find){
    std::cout<<"Remedio não foi encontrado!"<<std::endl;
    return false;    
  }

  Remedios[posicao].Exibir();
  std::cout<<"Quantidade de caixas no estoque: "<< quantidade[posicao] <<std::endl;

  std::cout<<"Digite a quantidade de caixas que foram entregues: "<<std::endl;
  int remov;
  std::cin>>remov;

  quantidade[posicao] -= remov;

  std::cout<<"Quantidade nova de caixas: "<< quantidade[posicao]<<"\n";
  return true;

}
