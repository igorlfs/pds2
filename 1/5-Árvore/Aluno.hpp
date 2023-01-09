#pragma once
#include <string>
using namespace std;
struct Aluno {
    int matricula;
    string nome;

    Aluno* left = nullptr;
    Aluno* right = nullptr;

    void set_matricula(int _matricula);
    void set_nome(string _nome);
    int get_matricula();
    string get_nome();

    void imprimir_dados();
};
