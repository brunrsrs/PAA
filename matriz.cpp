#include <iostream>
#include <vector>

void Inserir(std::vector<std::vector<int>> &mat, int valor1, int valor2) {
    if (mat[valor1][valor2] == -1) {
        std::cout<<"\n\tUm dos nós é inexistente\n";
        return;
    }

    if (mat[valor1][valor2] == 1) {
        std::cout<<"\n\tO valor já está conectado\n";
        return;
    }
    mat[valor1][valor2] = 1;
    mat[valor2][valor1] = 1;
    std::cout<<"\n\tInserido!\n";
}


void Mostrar(std::vector<std::vector<int>> mat, int tamanho) {
    for(int i=0; i<tamanho; i++) {
            if (mat[i][0] != -1)
                std::cout<<i+1;
        for(int j=0; j<tamanho; j++) {
            if (mat[i][j] == 1)
                std::cout<<" -> "<<j+1;
        }
        if (mat[i][0] != -1)
            std::cout<<"\n";
    }
}

void RemoverAresta(std::vector<std::vector<int>>&mat,int valor1, int valor2) {
    if (mat[valor1][valor2] == 0) {
        std::cout<<"\n\tA aresta nao existe";
        return;
    }
    
    if (mat[valor1][valor2] == -1) {
        std::cout<<"\n\tUm dos nós é inexistente";
        return;
    }

    mat[valor1][valor2] = 0;
    mat[valor2][valor1] = 0;
    std::cout<<"\n\tRemovido!\n";
}

void RemoverNo(std::vector<std::vector<int>>&mat,int v, int tamanho) {
    int i, j;

    if (mat[v][v] == -1) {
        std::cout<<"\n\tNó inexistente";
        return;
    }
    
    for (i = 0; i<tamanho; i++) {
        mat[v][i] = -1;
        mat[i][v] = -1;
    }
    std::cout<<"\n\tNó removido!\n";
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
        std::cout<<"\n[1] - Adicionar ligação\n[2] - Mostrar\n[3] - Remover Aresta\n[4] - Remover Nó\n\n[0] - Sair\ncomando: ";
        std::cin>>cmd;

        switch(cmd) {

            case 1:

            do {
            std::cout<<"\nLigar quais numeros?\n(exemplo: 1 2)\ncomando: ";
            std::cin>>valor1; 
            std::cin>>valor2;
            } while (valor1 == valor2 || valor1>tamanho || valor2>tamanho || valor1<1 || valor2<1);
            valor1--;
            valor2--;

            Inserir(matriz, valor1, valor2);
            break;
            
            case 2:
            Mostrar(matriz, tamanho);
            break;

            case 3:
                std::cout<<"\nRemover quais ligações?\n(exemplo: 1 2)\ncomando: ";
                std::cin>>valor1;
                std::cin>>valor2;

                valor1--;
                valor2--;

                RemoverAresta(matriz, valor1, valor2);
            break;

            case 4:
                std::cout<<"\nRemover qual nó?\ncomando: ";
                std::cin>>valor1;

                valor1--;
                valor2--;

                RemoverNo(matriz, valor1, tamanho);
            case 0:
            break;

            default:
            std::cout<<"Inválido";
        }

    } while (cmd != 0);

return 0;
}