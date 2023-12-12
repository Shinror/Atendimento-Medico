#include "json.hpp"
#include "remedioE.h"

#include <vector>


struct Estoque{
  std::string Nome;
  std::vector<RemedioE> Remedios;
  std::vector<int>quantidade;

  
  Estoque(std::string nome);
  Estoque(nlohmann::json& obj);
  


  nlohmann::json serializar();

  void registro(std::string Rnome,std::string Rdose,int Rquantidade);
  void encontrar(std::string Liniciais);
  void listar();
  bool adicionarqtd(std::string inptnome,std::string inptdose);
  bool usar(std::string inptnome,std::string inptdose);
    
};