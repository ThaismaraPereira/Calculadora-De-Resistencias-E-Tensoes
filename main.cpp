#include <stdio.h>
#include <stdlib.h>

int main()
{
   float R1, R2, R3, E;
   float I1, I2, I3, It, P1, P2, P3, Pt, V1, V2, V3, Vt, Req, R12;
   int associacao, novaop, verificador1, verificador2, verificador3, verificadorE;

  do{
   printf("Informe o valor de R1: \n");
   scanf("%f", &R1);
   printf("Informe o valor de R2: \n");
   scanf("%f", &R2);
   printf("Informe o valor de R3: \n");
   scanf("%f", &R3);

   //  >>>>>>>>>>>> Verifica a veracidade dos valores dos resistores <<<<<<<<<<<<

   while ((R1 <= 0 || R1 >= 100000) || (R2 <= 0 || R2 >= 100000) || (R3 <= 0 || R3 >= 100000)) {

    retorno : /* caso o verificador de inteiro for falso ele retorna aqui*/

    printf("Informe apenas valores inteiros, positivos, nao nulos e inferiores a 100000 \n\n");
    printf("Informe o valor de R1: \n");
    scanf("%f", &R1);
    printf("Informe o valor de R2: \n");
    scanf("%f", &R2);
    printf("Informe o valor de R3: \n");
    scanf("%f", &R3);

   }

   verificador1 = R1;
   verificador2 = R2;
   verificador3 = R3;

   if (verificador1 == R1 && verificador2 == R2 && verificador3 == R3){

   printf("Informe o valor da fonte (E) : \n");
   scanf( "%f", &E);

   } else {

    goto retorno;

   }

   while (E <= 0 || E > 12){

   retorno2: /* caso E não seja inteiro ele volta aqui */

    printf("Informe apenas valores positivos, nao nulos e inferiores ou iguais a 12 \n\n");
    printf("Informe o valor da fonte (E) : \n");
    scanf("%f", &E);

   }

   verificadorE = E;

   if (verificadorE == E){

   retorno3 : /* caso o tipo de associação não for correto, ele volta aqui */

   printf("Informe o tipo de associacao: 1 = Serie, 2 = Paralelo, 3 = Misto \n");
   scanf("%d", &associacao);

   } else {

       goto retorno2;

   }

    switch (associacao)    {

    case 1:

      Req = R1 + R2 + R3;
      It = E / Req;

      // Calcular tensoes

      V1 = R1 * It;
      V2 = R2 * It;
      V3 = R3 * It;

      // Calcular potencias

      P1 = V1 * It;
      P2 = V2 * It;
      P3 = V3 * It;

      // Apresentar dados

      printf("A resistencia equivalente e: %f  ohms  \n", Req/1000);
      printf("A corrente e: %.2f \n", It);
      printf("A tensao V1 e: %.2f \n", V1);
      printf("A tensao V2 e: %.2f \n", V2);
      printf("A tensao V3 e: %.2f \n", V3);
      printf("A potencia P1 e: %.2f \n", P1);
      printf("A potencia P2 e: %.2f \n", P2);
      printf("A potencia P3 e: %.2f \n", P3);

      break;

    case 2:

       R12 = (R1*R2)/(R1+R2);
       Req = (R3*R12)/(R3+R12);
       It = E / Req;
       I1 = E / R1;
       I2 = E / R2;
       I3 = E / R3;
       P1 = E * I1;
       P2 = E * I2;
       P3 = E * I3;

       printf("A resistencia equivalente e: %f  ohms \n", Req);
       printf("A intensidade toltal da corrente e: %.2f \n", It);
       printf("A intensidade da corrente I1 e: %.2f \n", I1);
       printf("A intensidade da corrente I2 e: %.2f \n", I2);
       printf("A intensidade da corrente I3 e: %.2f \n", I3);
       printf("A potencia P1 e: %.2f \n", P1);
       printf("A potencia P2 e: %.2f \n", P2);
       printf("A potencia P3 e: %.2f \n", P3);

    break;

    case 3:

        Req = ((R1 * R2)/(R1+R2)) + R3;
        It = E / Req ;
        V3 = R3 * It;
        I3 = It;
        V1 = E - V3;
        V2 = V1;
        I1 = V1 / R1;
        I2 = V2 / R2;
        P1 = V1 * I1;
        P2 = V2 * I2;
        P3 = V3 * I3;

        printf("A resistencia equivalente e: %f  ohms \n", Req);
        printf("A intensidade total da corrente e: %.2f \n", It);
        printf("A tensao V1 e: %.2f \n", V1);
        printf("A tensao V2 e: %.2f \n", V2);
        printf("A tensao V3 e: %.2f \n", V3);
        printf("A potencia P1 e: %.2f \n", P1);
        printf("A potencia P2 e: %.2f \n", P2);
        printf("A potencia P3 e: %.2f \n", P3);

        break;

    default :

        printf("Opcao invalida \n");
        goto retorno3;

    }



    printf("Deseja fazer uma nova operaçao sim = 1, não = qualquer numero \n");
    scanf("%d", &novaop);

  } while(novaop == 1);



    return 0;
}
