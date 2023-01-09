#include <math.h>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
    std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
    // Neste exemplo usaremos expressoes regulares para verificar se uma linha
    // eh valida ou nao.
    //
    // Esta expressao regular eh formada por cinco partes. Cada uma dessas
    // partes eh um dos tres tipos de padrao regular abaixo:
    //
    // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
    // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
    // \\d+ eh qualquer sequencia de um ou mais digitos
    std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

    // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
    // a expressao regular que acabamos de criar:
    return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
    //
    // Em geral eh mais facil ler dados de uma string se a string eh
    // transformada em um objeto do tipo stringstream:
    std::stringstream ss(str);
    //
    // Iremos ler os dados da string nestas tres variaveis abaixo:
    std::string nomePais;
    unsigned populacao, percUrbana;
    //
    // Como sabemos que a linha contem string int int, podemos fazer a leitura
    // facilmente usando o operador de streaming:
    ss >> nomePais >> populacao >> percUrbana;
    //
    // Note que precisamos arredondar o valor que serah impresso. O
    // arredondamento serah feito via a funcao floor. Ou seja, decimais serao
    // sempre arredondados para baixo:
    unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
    //
    // Uma vez encontrados os valores que precisam ser impressos, seguimos o
    // modelo do enunciado do exercicio:
    std::cout << popRural << " pessoas vivem no campo no " << nomePais
              << std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
    for (char const &c : str) {
        if (!std::isdigit(c) && !std::isspace(c)) {
            return false;
        }
    }
    return true;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
    std::stringstream ss(str);
    std::vector<unsigned> v;
    int n;
    while (ss >> n) {
        v.push_back(n);
    }
    int s = 0;
    for (unsigned i = 0; i < v.size(); ++i) {
        s += v[i];
    }
    std::cout << s << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
    // Primeiro verifique se algum caractere é especial
    for (char const &c : str) {
        if (!std::isalnum(c) && !std::isspace(c)) {
            return false;
        }
    }
    // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
    // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
    // \\d+ eh qualquer sequencia de um ou mais digitos
    std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
    // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
    // a expressao regular que acabamos de criar:
    return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
    std::stringstream ss(str);

    std::string nomeTimes[2];
    unsigned gols[2];

    ss >> nomeTimes[0] >> gols[0] >> nomeTimes[1] >> gols[1];
    if (gols[0] > gols[1]) {
        std::cout << "Vencedor: " << nomeTimes[0] << std::endl;
    } else if (gols[0] < gols[1]) {
        std::cout << "Vencedor: " << nomeTimes[1] << std::endl;
    } else {
        std::cout << "Empate" << std::endl;
    }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
    std::stringstream ss(str);

    std::vector<std::string> v;
    std::string auxiliar;

    while (ss >> auxiliar) {
        v.push_back(auxiliar);
    }
    std::cout << v.size() << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
    for (char const &c : str) {
        if (!std::isalpha(c) && !std::isspace(c)) {
            return false;
        }
    }
    return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
    std::stringstream ss(str);

    std::vector<std::string> v;
    std::string auxiliar;

    while (ss >> auxiliar) {
        v.push_back(auxiliar);
    }
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
    // Note que você pode usar uma expressao regular como:
    // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
    std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";

    std::regex regularExpr(dateFormat);

    return std::regex_match(str, regularExpr);
}

enum meses { Jan = 1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez };
void EscritorDeDatas::processaLinha(const std::string &str) {
    std::stringstream ss(str);

    unsigned dia, mes, ano;
    char barra;

    ss >> dia >> barra >> mes >> barra >> ano;
    std::string mesString;

    switch (mes) {
    case Jan:
        mesString = "Jan";
        break;
    case Fev:
        mesString = "Fev";
        break;
    case Mar:
        mesString = "Mar";
        break;
    case Abr:
        mesString = "Abr";
        break;
    case Mai:
        mesString = "Mai";
        break;
    case Jun:
        mesString = "Jun";
        break;
    case Jul:
        mesString = "Jul";
        break;
    case Ago:
        mesString = "Ago";
        break;
    case Set:
        mesString = "Set";
        break;
    case Out:
        mesString = "Out";
        break;
    case Nov:
        mesString = "Nov";
        break;
    case Dez:
        mesString = "Dez";
        break;
    }
    std::cout << mesString << std::endl;
}
