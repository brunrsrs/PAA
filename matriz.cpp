#include <iostream>
#include <vector>

void Inserir(std::vector<std::vector<int>> &mat, int valor1, int valor2) {
    if (mat[valor1][valor2] == 1) {
        std::cout<<"O valor já está conectado\n";
        return;
    }
    mat[valor1][valor2] = 1;
    mat[valor2][valor1] = 1;
}


void Mostrar(std::vector<std::vector<int>> mat, int tamanho) {
    for(int i=0; i<tamanho; i++) {
            std::cout<<i+1;
        for(int j=0; j<tamanho; j++) {
            if (mat[i][j] == 1)
                std::cout<<" -> "<<j+1;
        }
    std::cout<<"\n";
    }
}

int main()  {
    int tamanho;
    int valor1, valor2;
    std::vector<std::vector<int>> matriz;

    do {
    std::cout<<"\nTamanho da matriz: ";
    std::cin>>tamanho;
    } while (tamanho <= 0);

    matriz.resize(tamanho);

    for(auto &linha : matriz)
        linha.resize(tamanho);

    for(int i=0; i<tamanho; i++)
        for(int j=0; j<tamanho; j++)
            matriz[i][j] = 0;


    int cmd=0;

    do {
        std::cout<<"\n[1] - Adicionar ligação\n[2] - Mostrar\n[0] - Sair\ncomando: ";
        std::cin>>cmd;

        switch(cmd) {

            case 1:

            do {
            std::cout<<"\nLigar quais numeros?\n(exemplo: 1 2)\ncomando: ";
            std::cin>>valor1; 
            std::cin>>valor2;
            } while (valor1 == valor2 || valor1>tamanho || valor2 >tamanho);
            valor1--;
            valor2--;

            Inserir(matriz, valor1, valor2);
            std::cout<<"\n\tInserido!\n";
            break;
            
            case 2:
            Mostrar(matriz, tamanho);
            break;


            case 0:
            break;

            default:
            std::cout<<"Inválido";
        }

    } while (cmd != 0);

return 0;
}