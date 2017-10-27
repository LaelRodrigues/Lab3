#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstdlib>
using std::exit;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "produto.h"
#include "fruta.h"
#include "bebida.h"
#include "roupa.h"


void verificaArquivo(ifstream& arquivo);

void LerDados(ifstream& arquivo, vector<shared_ptr<Produto>>& lista, int tam);

#endif