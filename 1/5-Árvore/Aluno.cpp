#include "Aluno.hpp"

#include <iostream>
void Aluno::set_matricula(int _matricula) { this->matricula = _matricula; }
void Aluno::set_nome(string _nome) { this->nome = _nome; }
int Aluno::get_matricula() { return this->matricula; }
string Aluno::get_nome() { return this->nome; }
void Aluno::imprimir_dados() {
    cout << this->matricula << " " << this->nome << endl;
}
