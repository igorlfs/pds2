#include "fila_de_prioridade.h"

// Nó (elemento da fila): nome e prioridade são atributos informados no header
// (inclusive, a parte de ser unsigned)
// Do header também temos que a fila é uma lista encadeada, portanto preciso de
// um ponteiro para o próximo elemento
struct No {
  string nome;
  unsigned int prioridade;
  No *prox;
};

// É importate fazer uma função para criar as nodes com alocação dinâmica para
// que as nodes não "sumam" da memória quando os métodos "acabarem".
No *CriaNo(int p, string s) {
  No *aux = new No;
  aux->nome = s;
  aux->prioridade = p;
  aux->prox = nullptr;
  return aux;
}

// Uma fila vazia tem 0 elementos e o seu primeiro elemento é inválido
FilaDePrioridade::FilaDePrioridade() {
  this->tamanho_ = 0;
  this->primeiro_ = nullptr;
}

// Retorna o tamanho da fila
int FilaDePrioridade::tamanho() const { return this->tamanho_; }

// Perceba que existem 2 modos de avaliar se a fila está vazia, ligados à
// inicialização:
//
// Se o ponteiro para a cabeça da lista (this->primeiro_) for nulo, então a
// lista está vazia
//
// Se o tamanho da lista for 0, então a lista está vazia.
//
// A princípio optei pela 1ª estratégia (mais intuitiva para mim), mas acredito
// que quem elaborou o exercício contava com a 2ª abordagem, então fiz a
// modificação. Afinal, sem isso, o atributo tamanho não teria muita utilidade
bool FilaDePrioridade::vazia() const {
  if (this->tamanho() == 0) {
    return true;
  }
  return false;
}

// Esse VPL foi construído de modo que o primeiro elemento da lista PRECISA ser
// o de maior prioridade! Isso é evidente pelo fato que a cada impressão se
// remove o primeiro elemento da fila. Desse modo, preciso quando for inserir,
// não posso simplemesmente inserir na última posição, como em uma lista
// encadeada tradicional.
//
// Preciso inserir na posição certa, seguindo a ordem
// alfabética. Um dos motivos de essa abordagem ser interessante é que em
// momento algum a lista fica desordenada.
void FilaDePrioridade::Inserir(int p, string s) {
  No *novoNo = CriaNo(p, s);
  // Se a lista estiver vazia ou se o novo elemento for maior que a cabeça,
  // então o novo elemento deve ser a nova cabeça.
  if (this->vazia() || this->primeiro_->prioridade < novoNo->prioridade) {
    novoNo->prox = this->primeiro_;
    this->primeiro_ = novoNo;
  } else {
    // Caminhe pela lista até chegar no final ou até encontrar um elemento cujo
    // próximo tem a prioridade menor que a do novo elemento. Desse modo, vou
    // poder inserir o novo elemento após o atual (e antes do sucessor imediato
    // deste), assim mantendo a ordem.
    //
    // Nesse caso, o "próximo" é o maior elemento menor que o novo elemento!
    No *atual = this->primeiro_;
    while (atual->prox != nullptr &&
           atual->prox->prioridade >= novoNo->prioridade) {
      atual = atual->prox;
    }
    novoNo->prox = atual->prox;
    atual->prox = novoNo;
  }
  // Não esqueça de alterar o tamanho.
  ++this->tamanho_;
}

// Retorna o nome associado ao primeiro elemento
string FilaDePrioridade::primeiro() const { return this->primeiro_->nome; }

// Para remover o 1º elemento só prciso que a cabeça aponte para o elemento
// seguinte. Não esqueça de alterar o tamanho.
void FilaDePrioridade::RemoverPrimeiro() {
  this->primeiro_ = this->primeiro_->prox;
  --this->tamanho_;
}
