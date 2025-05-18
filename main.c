//Kauê Silva Matheus - RM561675
//Caique Baptistella de Vicente Albertino - RM564747
//Arthur da Silva Alencar - RM563684
//João Pedro de Moura Albino - RM565323

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int opcao;
    
    printf("\n===== MENU DE EXERCICIOS =====\n");
    printf("\n1 - Sequencia de Fibonacci;\n2 - Fatoriais;\n3 - Verificar Palindromo;\n4 - Verificar Substring.\n");
    printf("\nDigite um numero de 1 a 4: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao) {
        case 1: {
            printf("\nVoce escolheu a Sequencia de Fibonacci\n");
           
            int numero, i;
            printf("\nEscolha um valor de 1 a 50: ");
            scanf("%d", &numero);
            getchar();
           
            if (numero < 1 || numero > 50) {
                printf("Numero invalido, escolha um valor entre 1 e 50.\n");
                return 1;
            }
            
            unsigned long long fib[numero];
            fib[0] = 0;
            if (numero > 1) {
                fib[1] = 1;
            }

            for (i = 2; i < numero; i++) {
                fib[i] = fib[i-1] + fib[i-2];
            }

            printf("Os %d primeiros termos da sequencia de Fibonacci: \n", numero);
            for (i = 0; i < numero; i++) {
                printf("%llu ", fib[i]);
            }
            printf("\n");
            break;
        }
        case 2: {
            printf("\nVoce escolheu a opcao de Fatoriais\n");
            int numero;
            printf("\nEscolha um numero de 1 a 20: ");
            scanf("%d", &numero);
            getchar();
        
            if (numero < 1 || numero > 20) {
                printf("Numero invalido! Digite um valor entre 1 e 20.\n");
                return 1;
            }
            
            unsigned long long fatoriais[numero];
            fatoriais[0] = 1;
            
            for (int i = 2; i <= numero; i++) {
                fatoriais[i-1] = fatoriais[i-2] * i;
            }
        
            printf("\nFatoriais calculados:\n");
            for (int i = 0; i < numero; i++) {
                printf("%d! = %llu\n", i+1, fatoriais[i]);
            }
            break;
        }
        case 3: {
            printf("Voce escolheu a opcao de verificar Palindromo\n");
            char palavra[101];
            int i, j, tamanho;
            int eh_palindromo = 1;

            printf("Digite uma palavra (sem espaços, ate 100 letras): ");
            scanf("%100s", palavra); 
            getchar();
        
            tamanho = strlen(palavra);
            
            for (i = 0, j = tamanho - 1; i < j; i++, j--) {
                if (tolower(palavra[i]) != tolower(palavra[j])) {
                    eh_palindromo = 0;
                    break;
                }
            }
        
            if (eh_palindromo) {
                printf("\"%s\" e um palindromo!\n", palavra);
            } else {
                printf("\"%s\" nao e um palindromo.\n", palavra);
            }
            break;
        }
        case 4: {
            char stringPrincipal[100], substring[100];
            int i, j, encontrou;
        
            printf("Digite a string principal (max 99 caracteres): ");
            scanf(" %99[^\n]", stringPrincipal);
            getchar();
        
            printf("Digite a substring a ser buscada (max 99 caracteres): ");
            scanf("%99[^\n]", substring);
            getchar();
        
            int lenPrincipal = strlen(stringPrincipal);
            int lenSub = strlen(substring);
        
            encontrou = 0;
        
            for (i = 0; i <= lenPrincipal - lenSub; i++) {
                for (j = 0; j < lenSub; j++) {
                    if (tolower(stringPrincipal[i + j]) != tolower(substring[j])) {
                        break;
                    }
                }
                if (j == lenSub) {
                    encontrou = 1;
                    break;
                }
            }
        
            if (encontrou) {
                printf("\nA substring \"%s\" ESTA contida na string principal.\n", substring);
            } else {
                printf("\nA substring \"%s\" NAO esta contida na string principal.\n", substring);
            }
            break;
        }
        default: {
            printf("Opcao invalida! Digite um numero entre 1 e 4.\n");
        }
    }

    return 0;
}