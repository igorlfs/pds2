#pragma once

#include <cassert>
#include <set>
#include <vector>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    Tipo valor(int i) const;

  private:
    int inicio_;                  // Primeiro índice válido do arranjo.
    int fim_;                     // Último índice válido do arranjo.
    std::vector<Tipo> elementos_; // Elementos do arranjo.
    std::set<int> inicializados_; // Salve as posições inicializadas
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.
// boooo implementou no header!

template <class Tipo>
Arranjo<Tipo>::Arranjo(int inicio, int fim) : inicio_(inicio), fim_(fim) {
    // PRECONDIÇÃO: fim >= inicio.
    assert(fim >= inicio);
    elementos_.resize(fim - inicio + 1);
}

template <class Tipo> void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    assert(i >= inicio_ && i <= fim_);
    inicializados_.insert(i);
    int j = i - inicio_;
    elementos_[j] = valor;
}

template <class Tipo> Tipo Arranjo<Tipo>::valor(int i) const {
    // PRECONDIÇÕES:
    // (1) i está dentro do intervalo de índices do vetor.
    assert(i >= inicio_ && i <= fim_);
    // (2) i foi inicializando anteriormente.
    assert(this->inicializados_.find(i) != this->inicializados_.end());
    int j = i - inicio_;
    return elementos_[j];
}
