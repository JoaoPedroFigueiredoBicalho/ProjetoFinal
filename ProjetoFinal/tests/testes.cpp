#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lig4.cpp"

TEST_CASE("Teste de verificação da função lerjogada") {
    Lig4 jogo;

    //Verificando se o usuário inseriu um número negativo
    CHECK(jogo.lerjogada(-2) == false);

    //Verificando se o usuário inseriu algum número maior que o tabuleiro
    
}


