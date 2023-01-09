#pragma once
#include <map>
#include <vector>

#include "Cotacao.hpp"
using std::map;
using std::vector;

struct HistoricoBovespa {
    // Variáveis
    map<string, vector<Cotacao>> Colecao;

    // Construtores
    HistoricoBovespa() = default;

    // Operadores
    void inserir_cotacao(string sigla, string data, double valor);
    double calcular_valor_medio_acao(string sigla);
    Cotacao* recuperar_cotacao_maxima_acao(string sigla);
    Cotacao* recuperar_cotacao_minima_acao(string sigla);
    void imprimir_estatisticas_completas();
};
