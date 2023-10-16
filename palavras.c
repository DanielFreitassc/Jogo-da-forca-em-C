#include <stdlib.h>
#include <time.h> 
const char *palavras[] = {"bolo", "computador",
"teclado", "programador", "paulo", "tela", "vagner",
"criciuma", "satc", "escola", "mouse", "celular"}; 
const int num_palavras = sizeof(palavras) / sizeof(palavras[0]);

const char *sortear_palavra() {    
    srand(time(NULL));
    int indice_palavra_escolhida = rand() % num_palavras; 
    return palavras[indice_palavra_escolhida];
}
