#include "jogo_da_vida.hpp"
#include <assert.h>

void Inicializar(int l, int c, Torus &t) {
  assert(l >= 0 && l <= 100);
  assert(c >= 0 && c <= 100);
  t.numero_de_linhas = l;
  t.numero_de_colunas = c;
  for (int i = 0; i < t.numero_de_linhas; ++i) {
    for (int j = 0; j < t.numero_de_colunas; ++j) {
      t.viva[i][j] = false;
    }
  }
}

int contaVizinhosVivos(const Torus &t, const int &m, const int &n) {
  int vivos = 0;
  // Exceções: (i) entrada negativa; (ii) entrada maior que o total
  // Mitigações: (i) adicione o total; (ii) tome o resto
  for (int i = m - 1; i <= m + 1; ++i) {
    int row = i;
    if (i < 0) {
      row = row + t.numero_de_linhas;
    } else if (i >= t.numero_de_linhas) {
      row = row % t.numero_de_linhas;
    }
    for (int j = n - 1; j <= n + 1; ++j) {
      if (i == m && j == n) {
        continue;
      }
      int col = j;
      if (j < 0) {
        col = col + t.numero_de_colunas;
      } else if (j >= t.numero_de_colunas) {
        col = col % t.numero_de_colunas;
      }
      if (t.viva[row][col]) {
        ++vivos;
      }
    }
  }
  return vivos;
}
void alteraCelulas(Torus &t, int &m, int &n, int &r, int &c,
                   int **vizinhosVivos) {
  // Ver na wikipédia para mais clareza sobre as condições de alteração
  if (t.viva[m][n] && (vizinhosVivos[m][n] < 2 || vizinhosVivos[m][n] > 3)) {
    t.viva[m][n] = false;
  } else if (!t.viva[m][n] && vizinhosVivos[m][n] == 3) {
    t.viva[m][n] = true;
  }
}
void ExecutarUmaIteracao(Torus &t) {
  // Use ponteiros pra poder chamar a função de alterar células
  // (Seria 1000x vezes mais fácil usar a biblioteca vector)
  int rows = t.numero_de_linhas;
  int cols = t.numero_de_colunas;
  int **vizinhosVivos = new int *[rows];
  for (int i = 0; i < rows; ++i) {
    vizinhosVivos[i] = new int[cols];
  }
  // É importante fazer 2 loops
  // um para contagem de vizinhos e outro para alterar, de fato, o toro
  //
  // Caso seja feito apenas 1 loop, contando e alterando, haverá disparidade
  // entre o número de células vizinhas vivas
  //
  // Exemplo: se a 1ª célula está viva e deve morrer, quando for contar a 2ª
  // célula, a 1ª já vai estar morta (sendo que na contagem devia estar viva)
  for (int m = 0; m < rows; ++m) {
    for (int n = 0; n < cols; ++n) {
      vizinhosVivos[m][n] = contaVizinhosVivos(t, m, n);
    }
  }
  for (int m = 0; m < rows; ++m) {
    for (int n = 0; n < cols; ++n) {
      alteraCelulas(t, m, n, rows, cols, vizinhosVivos);
    }
  }
  for (int i = 0; i < rows; ++i) {
    delete[] vizinhosVivos[i];
  }
  delete[] vizinhosVivos;
}
