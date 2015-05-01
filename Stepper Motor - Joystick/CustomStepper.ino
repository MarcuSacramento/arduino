// Constantes de controle do Joystick

const int SW_pin =2; // Pino para indicar se o Joystick foi pressionado
const int X_pin =0; // Pino para o eixo X
const int Y_pin =1; // Pino para o eixo Y

//Biblioteca do Arduino e Cia(http://www.arduinoecia.com.br/)
#include <CustomStepper.h> //Define os parametros de ligacao do motor de passo  

    CustomStepper stepper(8,
        9,
        10,
        11, (byte[]) {
            8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001
        },
        4075.7728395,
        12,
        CW);
        
        boolean rotate1 = false;  
        
boolean rotacao =false;
float leituraX;
int velocidade;
void setup() {
    //Define a velocidade do motor  
    stepper.setRPM(0);
    //Define o numero de passos por rotacao  
    stepper.setSPR(4075.7728395);
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
}
void loop() {
    if (digitalRead(SW_pin) == 1) {
        //Direção no sentido horário(ClockWork)
        stepper.setDirection(CW);
    } else {
        //Direção no sentido anti-horário(Contra-ClockWork)
        stepper.setDirection(CCW);
    }
    //Existem valores Máximo para a velocidade do motor
    //Converte a leitura do Joystick que vai de 0 a 1016
    //em um valor próximo do máximo e mínimo do motor
    leituraX =sqrt(analogRead(X_pin));
    velocidade=(int) leituraX;
    if (velocidade > 20) {
        int aux = velocidade - 20;
        velocidade = velocidade - aux;
    }
    stepper.setRPM(velocidade);
    if (stepper.isDone() && rotacao == false) {
        //Define o numero de rotacoes  
        //Trabalhando com Giro
        stepper.rotate(1);
        //Trabalhando com ângulo
        //stepper.rotateDegrees(90);
        rotacao = true;
    }
    if (stepper.isDone() && rotacao == true) {
        //stepper.rotate(1); 
        stepper.rotateDegrees(90);
        rotacao = false;
    }
    //Comando obrigatorio para funcionamento da biblioteca  
    stepper.run();
}
