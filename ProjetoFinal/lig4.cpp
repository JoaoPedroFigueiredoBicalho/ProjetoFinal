#include "lig4.hpp"

void Lig4::lerjogada(int jogadaColuna, char jogada)
{
    if (jogadaColuna < 0 || jogadaColuna >= tamanho) {
        std::cout << "Coluna inválida!" << std::endl;
        return;
    }

    for (int linha = 0; linha <= tamanho; linha++) {
        if (tabuleiro[linha][jogadaColuna] == ' ') {
            tabuleiro[linha][jogadaColuna] = jogada;
        }
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
//AQUI E´GALO hoje tem galo hahahahahah
=======
}
//.
>>>>>>> cd4a6d678edbc9e42b800ec0cbea8bd30b5d1130
=======
>>>>>>> acbf1a6f5a4fa59e4cece045e8598e886f369698
