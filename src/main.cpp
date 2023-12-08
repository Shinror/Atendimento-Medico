#include <iostream>
#include <vector>
#include <fstream>


#include "json.hpp"
#include "Paciente.h"

int main(int argc, char** argv){
  std::vector<Paciente> Pacientes;

  std::cout<<"Bem-Vindo ao sistema de atendimento médico"<<std::endl;

  while(true){
    std::cout<<">Digite um comando, caso nao os conheca digite'ajuda':"<<std::endl;
    
    std::string comando;
    std::getline(std::cin,comando);

    if(comando == "novo"){
      std::string inome,iemail,icpf,idatanascimeno,ialergias,ideficiencias;

      
      std::cout<<"nome : "<<std::endl;
      std::getline(std::cin,inome);

      std::cout<<"email : "<<std::endl;
      std::getline(std::cin,iemail);
      
      std::cout<<"cpf : "<<std::endl;
      std::getline(std::cin,icpf);
      
      std::cout<<"born : "<<std::endl;
      std::getline(std::cin,idatanascimeno);
      
      std::cout<<"alergias : "<<std::endl;
      std::getline(std::cin,ialergias);
      
      std::cout<<"deficiencias : "<<std::endl;
      std::getline(std::cin,ideficiencias);




      Pacientes.emplace_back(inome,iemail,icpf,idatanascimeno,ialergias,ideficiencias);
    }
    if(comando == "listar"){
      std::cout<<">Lista de pacientes: "<<std::endl;
      
      for(int i = 0 ; i<Pacientes.size();i++){
        Pacientes[i].Exibir();
        std::cout<< "--------------------"<<std::endl;
      }
    }
    if(comando == "sair"){
      break;//essa é a mudanca
      }//*caba com o  codigo




  }





  return 0;
}