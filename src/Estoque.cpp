#include <iostream>
#include <string>

#include "Estoque.h"

Estoque::Estoque(std::string nome)
:Nome(nome)
{}

Estoque::Estoque(nlohmann::json& obj){
  for(auto& RemediosJson : obj["Remedios"]){
    Remedios.emplace_back(RemediosJson);
  }
}

nlohmann::json Estoque::serializar(){
  nlohmann::json obj;
  obj["Remedios"] = nlohmann::json::array();
  for(size_t i = 0 ; i < Remedios.size(); i++){
    obj["Remedios"].push_back(Remedios[i].serializar());
  }
  return obj;
}
void Estoque::registro(std::string Rnome, std::string Rdose,int Rquantidade){
  Remedios.emplace_back(Rnome,Rdose,Rquantidade);
}

void Estoque::encontrar(std::string Liniciais){
  std::cout<<">Remedios no estoque com as mesmas iniciais: \n";
  
  bool acho = false;
  for (int i = 0; i < Remedios.size(); i++)
  {
    std::string rnome = Remedios[i].Nome;
    if(Liniciais[0] == rnome[0] and Liniciais[1] == rnome[1] and Liniciais[2] == rnome[2]){
      Remedios[i].Exibir();
      std::cout<<"-----------------------------";
      acho == true;
      break;
    }//if comparacao 
  }
  if(! acho){
    std::cout<<"Nenhum remedio encontrado"<<std::endl;
  }
}


void Estoque::listar(){
  std::cout<<"-----------------------------\n";
  for(size_t i = 0; i < Remedios.size();i++){
    Remedios[i].Exibir();
    std::cout<< "-----------------------------";
  }
}

bool Estoque::adicionarqtd(std::string inptnome,std::string inptdose){
  int posicao = -1;

  
  for(int i = 0 ; i< Remedios.size(); i++){
    if(Remedios[i].Nome == inptnome and Remedios[i].Doses == inptdose){
      posicao = i;
 
      break;
    }
  }
  if(posicao == -1){
    std::cout<<"Remedio não foi encontrado!"<<std::endl;
    return false;    
  }

  Remedios[posicao].Exibir();

  std::cout<<"Digite a quantidade de caixas novas: "<<std::endl;
  int add;
  std::cin>>add;

  Remedios[posicao].quantidade += add;

  std::cout<<"Quantidade nova de caixas: "<< Remedios[posicao].quantidade <<"\n";
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

  std::cout<<"Digite a quantidade de caixas que foram entregues: "<<std::endl;
  int remov;
  std::cin>>remov;

  Remedios[posicao].quantidade -= remov;

  std::cout<<"Quantidade nova de caixas: "<< Remedios[posicao].quantidade<<"\n";
  return true;

}
