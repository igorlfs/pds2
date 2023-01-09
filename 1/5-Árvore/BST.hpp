#pragma once

#include "Aluno.hpp"
struct BST {
    Aluno* raiz = nullptr;

    void inserir_aluno_ajudante(Aluno* raiz, Aluno aluno);
    void inserir_aluno(Aluno aluno);

    Aluno* procurar_aluno_ajudante(Aluno* r, int matricula);
    Aluno* procurar_aluno(int matricula);

    void imprimir_arvore_ajudante(Aluno* r);
    void imprimir_arvore();
};
