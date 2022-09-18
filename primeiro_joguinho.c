#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // 1- mostre ao usuario mensagem de boas vindas
  // 2- gere um numero aleatorio
  // 3- pegue um chute do usuario e compare com o numero gerado
  // 4- se o usuario acertou, dê uma mensagem de vitoria
  // 5- se o usuario errou, retire uma tentativa e continue ate as tentativas
  //    acabarem ou o usuario acertar
  // 6- mostre uma mensagem de fracasso ou sucesso

  int timeSinceEpoch = time(0);

  srand(timeSinceEpoch);
  int numeroAleatorio = rand() % 100;
  int numeroTentativas;
  int dificuldade;
  int acertou = 0;

  // printf("%d", numeroAleatorio);

  printf("Bem vindo ao jogo de adivinhação!\n\nComo jogar:\n- O jogo vai gerar "
         "um número de 0 a 100\n  e você deverá acertar usando seus "
         "chutes\n  dentro da quantidade de tentativas fornecida.\n- Não são "
         "permitidos números negativos, ou com vírgula.\n- Divirta-se!");

  printf(
      "\n\nSelecione a dificuldade\n- Fácil ( 1 )\n- Normal ( 2 )\n- Dificil ( "
      "3 )\n-> ");

  scanf("%d", &dificuldade);

  switch (dificuldade) {
  case 1:
    numeroTentativas = 20;
    break;
  case 3:
    numeroTentativas = 6;
    break;
  default:
    numeroTentativas = 12;
    break;
  }

  for (int i = 1; i <= numeroTentativas; i++) {
    // printf("\n%d de %d\n", i, numeroTentativas);
    int chute;
    printf("\nTentativa %d de %d\n", i, numeroTentativas);

    printf("\nDigite seu chute: ");
    scanf("%d", &chute);

    // printf("Seu chute foi: %d\n", chute);
    if (chute < 0) {
      printf("\nErro -> Não são permitidos números negativos.\n");
      i--;
      continue;
    }

    if (chute == numeroAleatorio) {
      acertou = 1;
      break;
    } else if (chute > numeroAleatorio) {
      printf("\nSeu chute foi maior que o número gerado!");
    } else {
      printf("\nSeu chute foi menor que o número gerado!");
    }
  }

  if (acertou) {
    printf("\n\n----------------------\n\nParabéns, você ganhou!\n\n");
  } else {
    printf("\n\n----------------------\n\nQue pena, você perdeu!\n\n");
  }

  return 0;
}