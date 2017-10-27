/**
 * @file	arquivo.h
 * @brief	arquivo de cabecalho com funcoes para manipulacao
 *			de arquivos 
 * @author	Lael Rodrigues(laelrodrigues7@gmail.com)
 * @since	25/10/2017
 * @data	26/10/2017
 */


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

/**
 * @brief	Funcao que verifica se o arquivo e valido
 * @param 	arquivo stream de entrada 
 */

void verificaArquivo(ifstream& arquivo);

/**
 * @brief	Funcao que Ler os dados do arquivo de entrada
 * @param 	lista Lista de produtos
 * @param 	arquivo stream de entrada 
 */
void LerDados(ifstream& arquivo, vector<shared_ptr<Produto>>& lista, int tam);

#endif