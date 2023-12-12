#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "json.hpp"
#include "Paciente.h"
#include "Estoque.h"

int main(int argc, char** argv){
  std::vector<Paciente> Pacientes;
  Estoque Armazem("oi");

  std::cout<<"Bem-Vindo ao sistema de atendimento médico"<<std::endl;

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
        
        std::cout<<"Data de nascimento : "<<std::endl;
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
          bool continua = true;
          while(continua){
            std::cout<< "Deseja adicionar um remedio [s,n]\n=>";
            std::string afirma;
            std::getline(std::cin,afirma);

            if(afirma == "n" or afirma == "N"){
            continua = false;
            }
            else if(afirma == "s" or afirma == "S"){
              std::cout<<"Escreva o nome do remedio \n=>";
              
              std::string rnome = " ";
              std::getline(std::cin,rnome);
              if(rnome != " "){
                std::cout<<"Escreva a dosagem do remedio\n=>";

                std::string rdosagem;
                std::getline(std::cin,rdosagem);
                
                
                int tam = Pacientes[info].Prontuarios.size() - 1;
                Pacientes[info].Prontuarios[tam].addRemdios(rnome,rdosagem); 
                


              }//if antbug
            }//if nome remdio
          }//while area remedio
        }//paciente encontrado
      }//comando prontuario
    }//comando adicionar
    
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
        for(int i = 0; i < Pacientes.size(); i++){
          if(cnpjoto == Pacientes[i].CPF){
            Pacientes[i].MostrarProntuarios();
            acho = true;
            break;
          }
        }
        if(! acho){
          std::cout<<"Nenhum Paciente com esse CPF encontrado"<<std::endl;
        }
        
      }
    }


    if(comando == "estoque"){
      std::cout<<"Area de Gerenciamento do Estoque\n";

      if( Armazem.Nome != "oi"){
        Estoque Armazem("oi");
      }
      while (true)
      {
        std::cout<<"> O que deseja fazer:  \nnovo, listar, encontrar, caixas, sair\n=>";

        std::string comandoE;
        std::getline(std::cin, comandoE);

        if(comandoE =="novo"){
          std::cout<<"Escreva o nome do remedio: \n=>";
          
          std::string nominho;
          std::getline(std::cin,nominho);

          std::cout<<"Escreva a dosagem do remedio: \n=>";

          std::string dosinha;
          std::getline(std::cin, dosinha);

          std::cout<<"Escreva a quantidade de caixas: \n=>";

          int qunti = -1;
          std::cin>>qunti;

          if(qunti != -1)
          Armazem.registro(nominho, dosinha, qunti);
        }//if novo estoque
        if(comandoE == "listar")
          Armazem.listar();
        
        if(comandoE == "encontrar"){
          std::cout<<"Digite as três primeiras letra doremedio:\n=>";
          
          std::string Letras;
          std::getline(std::cin,Letras);
          Armazem.encontrar(Letras);
        }
        if(comandoE == "caixas"){

          std::cout<<">>Gerenciamento de caixas de remedio\n O que deseja fazer: adicionar, remover: \n=>";
          std::getline(std::cin, comandoE);

          if(comandoE == "adicionar"){
            std::cout<<"Escreva o nome do remedio: \n=>";
            
            std::string nominho;
            std::getline(std::cin,nominho);
            
            std::cout<<"Escreva a dosagem do remedio: \n=>";

            std::string dosinha;
            std::getline(std::cin, dosinha);

            if(! Armazem.adicionarqtd(nominho,dosinha))
              std::cout<<"Use o comando encontrar para ver se nenhum erro de digitação ocorreu."<<std::endl;
          }//if adicinar
          if(comandoE == "remover"){
            std::cout<<"Escreva o nome do remedio: \n=>";
            
            std::string nominho;
            std::getline(std::cin,nominho);
            
            std::cout<<"Escreva a dosagem do remedio: \n=>";

            std::string dosinha;
            std::getline(std::cin, dosinha);

            if(! Armazem.usar(nominho,dosinha))
              std::cout<<"Use o comando encontrar para ver se nenhum erro de digitação ocorreu."<<std::endl;
          }
        }//if caixas
        if(comandoE =="sair"){
          break;
        }
      }//while
    }//if estoque



    if(comando == "salvar"){
      nlohmann::json obj;
      obj["Pacientes"] =  nlohmann::json::array();
      
      for(size_t i =0 ; i < Pacientes.size(); i++){
        obj["Pacientes"].push_back(Pacientes[i].serializar());
      }

      std::ofstream dumper;

      dumper.open("../data/Paciente.json");
      if(! dumper){
        std::cout<<"Não foi possivel salvar o arquivo !";
        return 1;
      }

      dumper << obj.dump();
      dumper.close();
      std::cout<<"Arquivos dos pacientes salvos com sucesso!!"<<std::endl<<"Salvando estoque, pode levar um tempo...\n";
      
      //arquivo armazem
      nlohmann::json objArmazem;
      objArmazem["Armazem"] = nlohmann::json::array();

      std::ofstream ArquivoArmazem;
      ArquivoArmazem.open("../data/Armazem.json");
      
      if(! ArquivoArmazem){
        std::cout<<"Não foi possivel salvar o arquivo!";
        return 1;
      }
    
      objArmazem["Armazem"] = Armazem.serializar();
      
      ArquivoArmazem << objArmazem.dump();
      ArquivoArmazem.close();

      std::cout<<"Estoque salvo com sucesso!!"<<std::endl;
    }
    
    if(comando == "carregar"){
      std::ifstream file("../data/Paciente.json");

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
      file.close();
      std::cout<<"Informacoes dos pacientes carregadas com sucesso!"<<std::endl<<"Carregando estoque, pode levar um tempo\n";
    
      file.open("../data/Armazem.json");

      if(!file){
        std::cout<<"Arquivo não encontrado"<<std::endl;
        return 1;
      }

      std::getline(file,temp);
      std::cout<<temp;

      nlohmann::json obj2 ;
      obj2["Armazem"]= nlohmann::json::parse(temp);

    
      auto& ArmazemJson = obj2["Armazem"];
      Estoque Armazem(ArmazemJson);//!ver com o professor
     
        
      file.close();
      std::cout<<"Estoque carregado com sucesso!!"<<std::endl;

    }

    if(comando == "limpar"){
      std::system("cls"); 
      std::system("clear");
    }

    if(comando == "ajuda"){
      std::cout<<"> Os comando possiveis são :"<<"\n adicionar, listar, estoque, limpar, salvar, carregar, sair"<<std::endl; 
    }

    if(comando == "sair"){
      break;
    }//*caba com o  codigo
    



  }
  return 0;
}