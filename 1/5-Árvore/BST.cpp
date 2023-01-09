#include "BST.hpp"
Aluno* criaAluno(Aluno aluno) {
    Aluno* aux = new Aluno;
    aux->set_matricula(aluno.get_matricula());
    aux->set_nome(aluno.get_nome());

    return aux;
}
void BST::inserir_aluno(Aluno aluno) {
    if (this->raiz != nullptr) {
        inserir_aluno_ajudante(raiz, aluno);
    } else {
        this->raiz = criaAluno(aluno);
    }
}
void BST::inserir_aluno_ajudante(Aluno* raiz, Aluno aluno) {
    if (aluno.matricula < raiz->matricula) {
        if (raiz->left == nullptr) {
            raiz->left = criaAluno(aluno);
        } else {
            inserir_aluno_ajudante(raiz->left, aluno);
        }
    } else if (aluno.matricula > raiz->matricula) {
        if (raiz->right == nullptr) {
            raiz->right = criaAluno(aluno);
        } else {
            inserir_aluno_ajudante(raiz->right, aluno);
        }
    }
}
Aluno* BST::procurar_aluno_ajudante(Aluno* r, int matricula) {
    if (r->matricula == matricula) {
        return r;
    } else if (r->matricula > matricula) {
        if (r->left == nullptr) {
            return nullptr;
        } else {
            return procurar_aluno_ajudante(r->left, matricula);
        }
    } else if (r->right == nullptr) {
        return nullptr;
    } else {
        return procurar_aluno_ajudante(r->right, matricula);
    }
}
Aluno* BST::procurar_aluno(int matricula) {
    if (this->raiz != nullptr) {
        return procurar_aluno_ajudante(this->raiz, matricula);
    } else {
        return nullptr;
    }
}
void BST::imprimir_arvore_ajudante(Aluno* r) {
    if (r == nullptr) return;
    imprimir_arvore_ajudante(r->left);
    r->imprimir_dados();
    imprimir_arvore_ajudante(r->right);
}
void BST::imprimir_arvore() {
    if (this->raiz != nullptr) {
        imprimir_arvore_ajudante(raiz);
    }
}
