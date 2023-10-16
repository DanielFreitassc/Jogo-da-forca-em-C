#include <stdio.h>
#include <string.h> 
#include "palavras.h" 
 
int main(void) {   
  
    printf("=-=-=-=-=-=-=-=\n");                        
    printf("|| BEM VINDO||");                                    
    printf("\n=-=-=-=-=-=-=-=\n");                     
    printf("=-=-=-=-=-=-=-=\n");                     
    printf("||   MENU    ||");                      
    printf("\n=-=-=-=-=-=-=-=\n");                   
    printf("=-=-=-=-=-=-=-=\n");                 
    printf("||1- JOGAR   ||\n");                  
    printf("||2- SAIR    ||");                  
    printf("\n=-=-=-=-=-=-=-=\n");            
  
    int escolha = 0;          
    scanf("%i", &escolha);    
      
    if (escolha == 1) {                                              
        const char *palavras = sortear_palavra(); 
        char tentativas[6];         
        int tentativas_feitas = 0;   
        int max_tentativas = 6; 
      
        int tamanho = strlen(palavras);  
        char palavra_descoberta[tamanho + 1];   
        for (int i = 0; i < tamanho; i++) {    
            palavra_descoberta[i] = '_';      
        }  
        palavra_descoberta[tamanho] = '\0';

        while (1) {
            printf("\nPalavra: %s\n", palavra_descoberta);                            
            printf("Tentativas restantes: %d\n", max_tentativas - tentativas_feitas);
            printf("Letras tentadas: %s\n", tentativas);                            
            char chute;                   
            printf("Digite uma letra: ");
            scanf(" %c", &chute);        
  
            int acertou = 0;                          
            for (int i = 0; i < tamanho; i++) {      
                if (palavras[i] == chute) {         
                    palavra_descoberta[i] = chute; 
                    acertou = 1;                  
                }
            }
          
            if (!acertou) {                              
                tentativas[tentativas_feitas] = chute;  
                tentativas_feitas++;                   

                printf("  _______\n");                                                                                                 
                printf(" |/      |\n");
                printf(" |      %s\n", (tentativas_feitas >= 1) ? "O" : "");
                printf(" |     %s%s%s\n", (tentativas_feitas >= 3) ? "/" : "", (tentativas_feitas >= 2) ? "|" : "", (tentativas_feitas >= 4) ? "\\" : "");
                printf(" |     %s %s\n", (tentativas_feitas >= 5) ? "/" : "", (tentativas_feitas >= 6) ? "\\" : "");
                printf(" |\n");
                printf("_|___\n\n");
            }

            int palavra_completa = 1;                 
            for (int i = 0; i < tamanho; i++) {       
                if (palavra_descoberta[i] == '_') {  
                    palavra_completa = 0;           
                    break;                        
                }
            }
          
            if (palavra_completa) {                                            
                printf("\nPARABÉNS! Você acertou a palavra: %s\n", palavras); 
                break;                                                       
            }
            if (tentativas_feitas >= max_tentativas){                  
                printf("\nVocê perdeu! A palavra era: %s\n", palavras); 
                break;                                                 
            }
        }
    }

   else {             
        printf("saiu"); 
    }

    return 0; 
}
