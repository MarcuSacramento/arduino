/*
  SHIELD TECLADO LCD 16x02
  O shield deve ser conectado simplesmente plugando ao Arduino,
  pois dessa forma será realizada as seguintes conexões:
  - Botões do shield no pino analógico A0;
  - Pino RS do LCD no pino digital D8;
  - Pino Enable (E) do LCD no pino digital D9;
  - Pino de dados B4 do LCD no pino digital D4;
  - Pino de dados B5 do LCD no pino digital D5;
  - Pino de dados B6 do LCD no pino digital D6;
  - Pino de dados B7 do LCD no pino digital D7;
  - Para controlar o contraste do LCD ajuste o 
    potenciômentro de 10K contido no shield.
*/  

/////////////////////////////////
//INICIALIZAÇÃO DAS BIBLIOTECAS//
/////////////////////////////////     
#include <LiquidCrystal.h>    //Biblioteca para Display LCD


/////////////////////////////////
// INICIALIZAÇÃO DAS VARIÁVEIS //
/////////////////////////////////     

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //Inicializando a biblioteca
                                      //com os números dos pinos
                                      //de interface, criando um
                                      //objeto chamado lcd e
                                      //atribuindo aos pinos 
                                      //digitais do Arduino.

/* Como cada botão do Shield está ligado a resistores divisores de tensão,
   então cada botão transmite uma tensão quando pressionado, dessa forma
   será criado uma variável para armazenar esse valor de tensão para cada
   botão: SELECT (seleção), LEFT (esquerda), RIGTH (direita), UP (para cima)
   e DOWN (para baixo).
  */ 
  int botaoSelect;
  int botaoLeft;
  int botaoRigth;
  int botaoUp;
  int botaoDown;
  
  byte pinoBotao = A0;   //inicializando uma variável denominada
                         //pinoBotao no pino analógio A0 do Arduino 
                         //para ler os valores dos botões do shield.

  int valorBotao;        //inicializando uma variável denominada
                         //valorBotao para armazenar os valores  
                         //lidos dos botões do shield.
  
  
///////////
// SETUP //
///////////
void setup() 
{
  Serial.begin(9600);  //setando a comunicação via porta serial à
                       //uma velocidade de 9600bps(baud).  
                            
  lcd.begin(16, 2);    //Definindo o LCD com 16 colunas e 2 linhas
  
  lcd.clear();         //função para apagar a tela LCD
  
  lcd.setCursor(0, 0); //Definindo o cursor na posição inicial do LCD
   
  valorBotao = analogRead(pinoBotao);  //Lê o pino A0 (pinoBotao)
                                       //e armazena o valor lido
                                       //pelo botão na variável
                                       //valorBotao.
  
  botaoSelect = valorBotao;            //armazena o mesmo valor
                                       //da variável valorBotao
                                       //na variável botaoSelect.
  
  /* Pressione o botão SELECT no shield para descobrir o valor da
     tensão para esse botão, pois esse valor será utilizado para
     definir o botão SELECT ao longo do programa.
  */  
  while(valorBotao == botaoSelect)
  {
    lcd.setCursor(0, 0); //Definindo o cursor na posição inicial do LCD
    lcd.print("Pressione  Botao");    //imprime mensagem na tela do LCD
    lcd.setCursor(0, 1); //Definindo o cursor na segunda linha do LCD
    lcd.print("     SELECT     ");    //imprime mensagem na tela do LCD
    botaoSelect = analogRead(pinoBotao); //Lê o pino A0 (pinoBotao)
                                         //e armazena o valor lido
                                         //pelo botão na variável
                                         //botaoSelect.
  }

  lcd.setCursor(0, 0);   //Definindo o cursor na posição inicial do LCD
  lcd.print("O valor do Botao");     //imprime mensagem na tela do LCD
  lcd.setCursor(0, 1);   //Definindo o cursor na segunda linha do LCD
  lcd.print("SELECT   =  ");         //imprime mensagem na tela do LCD
  lcd.print(botaoSelect);//imprime o valor do botao na tela do LCD
  delay(3000);           //aguarda um tempo.
  
  /* Pressione o botão LEFT no shield para descobrir o valor da
     tensão para esse botão, pois esse valor será utilizado para
     definir o botão LEFT (ESQUERDO) ao longo do programa.
  */  
  valorBotao = analogRead(pinoBotao);
  botaoLeft = valorBotao;
  while(valorBotao == botaoLeft)
  {
    lcd.setCursor(0, 0);
    lcd.print("Pressione  Botao");
    lcd.setCursor(0, 1);
    lcd.print("     ESQUERDO     ");
    botaoLeft = analogRead(pinoBotao);
  }
  
  lcd.setCursor(0, 0);
  lcd.print("O valor do Botao");
  lcd.setCursor(0, 1);
  lcd.print("ESQUERDO  = ");
  lcd.print(botaoLeft);
  delay(3000);
  
  /* Pressione o botão RIGTH no shield para descobrir o valor da
     tensão para esse botão, pois esse valor será utilizado para
     definir o botão RIGHT (DIREITO) ao longo do programa.
  */  
  valorBotao = analogRead(pinoBotao);
  botaoRigth = valorBotao;
  while(valorBotao == botaoRigth)
  {
    lcd.setCursor(0, 0);
    lcd.print("Pressione  Botao");
    lcd.setCursor(0, 1);
    lcd.print("    DIREITO     ");
    botaoRigth = analogRead(pinoBotao);
  }
  
  lcd.setCursor(0, 0);
  lcd.print("O valor do Botao");
  lcd.setCursor(0, 1);
  lcd.print("DIREITO  =  ");
  lcd.print(botaoRigth);
  delay(3000);
  
  /* Pressione o botão UP no shield para descobrir o valor da
     tensão para esse botão, pois esse valor será utilizado para
     definir o botão UP (PARA CIMA) ao longo do programa.
  */  
  valorBotao = analogRead(pinoBotao);
  botaoUp = valorBotao;
  while(valorBotao == botaoUp)
  {
    lcd.setCursor(0, 0);
    lcd.print("Pressione  Botao");
    lcd.setCursor(0, 1);
    lcd.print("   PARA  CIMA   ");
    botaoUp = analogRead(pinoBotao);
  }
  
  lcd.setCursor(0, 0);
  lcd.print("O valor do Botao");
  lcd.setCursor(0, 1);
  lcd.print("PARA CIMA = ");
  lcd.print(botaoUp);
  delay(3000);
  
  /* Pressione o botão DOWN no shield para descobrir o valor da
     tensão para esse botão, pois esse valor será utilizado para
     definir o botão DOWN (PARA BAIXO) ao longo do programa.
  */  
  valorBotao = analogRead(pinoBotao);
  botaoDown = valorBotao;
  while(valorBotao == botaoDown)
  {
    lcd.setCursor(0, 0);
    lcd.print("Pressione  Botao");
    lcd.setCursor(0, 1);
    lcd.print("   PARA BAIXO   ");
    botaoDown = analogRead(pinoBotao);
  }
  
  lcd.setCursor(0, 0);
  lcd.print("O valor do Botao");
  lcd.setCursor(0, 1);
  lcd.print("PARA BAIXO =");
  lcd.print(botaoDown);
  delay(3000);
  
  lcd.clear();         //função para apagar a tela LCD
  lcd.setCursor(0, 0); //Definindo o cursor na posição inicial do LCD
  lcd.print("Aperte um BOTAO:");    //imprime mensagem na tela do LCD
}


///////////
// LOOP  //
///////////
void loop() 
{

  valorBotao = analogRead(pinoBotao); //Lê o pino A0 (pinoBotao)
                                       //e armazena o valor lido
                                       //pelo botão na variável
                                       //valorBotao.
  /*Após configurar cada botão do Shield teremos os seguintes valores
    que poderão alterar dependendo da marca e modelo do Shield.
      Botão ESQUERDO (LEFT) = 411;
      Botão PARA CIMA (UP) = 100;
      Botão PARA BAIXO (DOWN) = 258;
      Botão DIREITO (RIGHT) = 0;
      Botão SELECT = 641.
  /*
  /* Se o valor pressionado no shiel foi igual ao botão RIGHT
     imprimir na tela do LCD "Voce selecionou botao DIREITO"  
  */
  if(valorBotao <= botaoRigth)
  {
    lcd.setCursor(0, 0);
    lcd.print("Voce  selecionou");
    lcd.setCursor(0, 1);
    lcd.print(" botao  DIREITO ");
    delay(3000);
    lcd.clear();         //função para apagar a tela LCD
    lcd.setCursor(0, 0);
    lcd.print("Aperte um BOTAO:");
  }
  else
    /* Se o valor pressionado no shiel foi igual ao botão UP
       imprimir na tela do LCD "Voce selecionou botao PARA CIMA"  
    */
    if(valorBotao <= botaoUp)
    {
      lcd.setCursor(0, 0);
      lcd.print("Voce  selecionou");
      lcd.setCursor(0, 1);
      lcd.print("botao  PARA CIMA");
      delay(3000);
      lcd.clear();         //função para apagar a tela LCD
      lcd.setCursor(0, 0);
      lcd.print("Aperte um BOTAO:");
    }
    else
      /* Se o valor pressionado no shiel foi igual ao botão DOWN
         imprimir na tela do LCD "Voce selecionou botao PARA BAIXO"  
      */
      if(valorBotao <= botaoDown)
      {
        lcd.setCursor(0, 0);
        lcd.print("Voce  selecionou");
        lcd.setCursor(0, 1);
        lcd.print("botao PARA BAIXO");
        delay(3000);
        lcd.clear();         //função para apagar a tela LCD
        lcd.setCursor(0, 0);
        lcd.print("Aperte um BOTAO:");
      }
      else
        /* Se o valor pressionado no shiel foi igual ao botão LEFT
           imprimir na tela do LCD "Voce selecionou botao ESQUERDO"  
        */
        if(valorBotao <= botaoLeft)
        {
          lcd.setCursor(0, 0);
          lcd.print("Voce  selecionou");
          lcd.setCursor(0, 1);
          lcd.print(" botao ESQUERDO ");
          delay(3000);
          lcd.clear();         //função para apagar a tela LCD
          lcd.setCursor(0, 0);
          lcd.print("Aperte um BOTAO:");
        }
        else
        /* Se o valor pressionado no shiel foi igual ao botão SELECT
           imprimir na tela do LCD "Voce selecionou botao SELECT"  
        */
          if(valorBotao <= botaoSelect)
          {
            lcd.setCursor(0, 0);
            lcd.print("Voce  selecionou");
            lcd.setCursor(0, 1);
            lcd.print(" botao  SELECT ");
            delay(3000);
            lcd.clear();         //função para apagar a tela LCD
            lcd.setCursor(0, 0);
            lcd.print("Aperte um BOTAO:");
          }
}
