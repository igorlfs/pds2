#pragma once

#include <set>
#include <vector>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES:
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const;

  private:
    int inicio_;                  // Primeiro índice válido do arranjo.
    int fim_;                     // Último índice válido do arranjo.
    std::vector<Tipo> elementos_; // Elementos do arranjo.
    std::set<int> inicializados_; // Salve as posições inicializadas
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

struct ExcecaoIntervaloVazio {
    int inicio;
    int fim;
};

struct ExcecaoIndiceInvalido {
    int inicio;
    int fim;
    int indice;
};

struct ExcecaoIndiceNaoInicializado {
    int indice;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE Arranjo.

template <class Tipo>
Arranjo<Tipo>::Arranjo(int inicio, int fim) : inicio_(inicio), fim_(fim) {
    if (fim < inicio) throw ExcecaoIntervaloVazio{inicio_, fim_};
    elementos_.resize(fim - inicio + 1);
}

template <class Tipo> void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
    if (i < inicio_ || i > fim_) throw ExcecaoIndiceInvalido{inicio_, fim_, i};
    inicializados_.insert(i);
    int j = i - inicio_;
    elementos_[j] = valor;
}

template <class Tipo> Tipo Arranjo<Tipo>::valor(int i) const {
    if (i < inicio_ || i > fim_) throw ExcecaoIndiceInvalido{inicio_, fim_, i};
    if (this->inicializados_.find(i) == this->inicializados_.end())
        throw ExcecaoIndiceNaoInicializado{i};
    int j = i - inicio_;
    return elementos_[j];
}
