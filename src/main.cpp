#include <iostream>
#include <vector>
#include <fstream>


#include "json.hpp"
#include "Paciente.h"

int main(int argc, char** argv){
  std::vector<Paciente> Pacientes;

  std::cout<<"Bem-Vindo ao sistema de atendimento médico"<<"\n=> ";

  while(true){
    std::cout<<">Digite um comando, caso nao os conheca digite'ajuda':"<<"\n=> ";
    
    std::string comando;
    std::getline(std::cin,comando);

    if(comando == "adicionar"){
      std::cout<<">> O que deseja adicionar\npaciente ou prontuario \n=> ";
      std::getline(std::cin,comando);
      
      if(comando == "paciente"){
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
      if(comando == "prontuario"){
        std::cout<<"Digite o CPF do Paciente\n=> ";
        
        std::string inpt;
        std::getline(std::cin,inpt);
        
        int info;
        bool find = false;
        for(int i =0 ; i < Pacientes.size();i++){
          
          if(inpt == Pacientes[i].CPF){
            info = i ;
            find =true;
          }
        }
        if(! find){
          std::cout<<"Paciente não foi encontrados"<<std::endl;
        }
        else
        {
          std::string mutivo, sinal, diag, obs;

          std::cout<<"Escreva o motivo da consulta\n=> ";
          std::getline(std::cin,mutivo);

          std::cout<<"Escreva o(s) sinais apresentados\n=> ";
          std::getline(std::cin,sinal);

          std::cout<<"Escreva o diagnostico apresentado\n=> ";
          std::getline(std::cin,diag);

          std::cout<<"Escreva a(s) observaçõe(s)\n=> ";
          std::getline(std::cin,obs);

          Pacientes[info].Prontuarios.emplace_back(mutivo, sinal, diag, obs);

            std::cout<<">>> Area da prescrição"<<std::endl;
          while(true){
            std::cout<< "Deseja adicionar um remedio [s,n]";
            char afirma;
            std::cin>>afirma;

            if(afirma == 'n' or afirma == 'N'){
              break;
            }
            else{
              std::cout<<"Escreva o nome do remedio \n=>";
              
              std::string rnome;
              std::getline(std::cin,rnome);

              std::cout<<"Escreva a dosagem do remedio\n=>";

              std::string rdosagem;
              std::getline(std::cin,rdosagem);
              
              int tam = Pacientes[info].Prontuarios.size() - 1;
              Pacientes[info].Prontuarios[tam].addRemdios(rnome,rdosagem); 
            }
          }
        }
      }
    }
    if(comando == "listar"){
      std::cout<< "> O que deseja listar:"<<"\npacientes ou prontuarios\n=> ";
      std::getline(std::cin,comando);
      
      if(comando == "pacientes"){
        std::cout<<">>Lista de pacientes: "<<std::endl;
        for(int i = 0 ; i<Pacientes.size();i++){
          Pacientes[i].Exibir();
          std::cout<< "--------------------"<<std::endl;
        }
      }
      if(comando == "prontuarios"){
        std::cout<< "Digite o CPF do paciente\n=> ";
        
        std::string cnpjoto;
        std::getline(std::cin,cnpjoto);

        bool acho = false; 
        int aaa;
        for(int i = 0; i < Pacientes.size(); i++){
          if(cnpjoto == Pacientes[i].CPF){
            acho == true;
            aaa = i;
            break;
          }
        }
        if(! acho){
          std::cout<<"Nenhum Paciente com esse CPF encontrado"<<std::endl;
        }
        Pacientes[aaa].MostrarProntuarios;
      }
    }
    if(comando == "salvar"){
      nlohmann::json obj =  nlohmann::json::array();
      
      for(size_t i =0 ; i < Pacientes.size(); i++){
        obj["Pacientes"].push_back(Pacientes[i].serializar());
      }

      std::ofstream dumper;

      dumper.open("../src/data.json");
      if(! dumper){
        std::cout<<"Não foi possivel salvar o arquivo !";
        return 1;
      }

      dumper << obj.dump();
      dumper.close();
      std::cout<<"Arquivos salvos com sucesso!"<<std::endl;
    }
    if(comando == "carregar"){
      std::ifstream file("../src/data.json");

      if(! file){
        std::cout<<"Arquivo não encontrado"<<std::endl;
        return 1;
      }
      std::string temp;
      
      std::getline(file,temp);
      
      nlohmann::json obj = nlohmann::json::parse(temp);

      for(auto& PacientesJson : obj["Pacientes"]){
        Pacientes.emplace_back(PacientesJson);
      }
      std::cout<<"Informacoes carregadas com sucesso!"<<std::endl;
    }
    if(comando == "ajuda"){
      std::cout<<"> Os comando possiveis são :"<<"\n adicionar, listar, salvar, carregar, sair"<<std::endl; 
    }
    if(comando == "sair"){
      break;
    }//*caba com o  codigo
    



  }





  return 0;
}