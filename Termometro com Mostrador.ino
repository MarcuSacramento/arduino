int LM35 = 0;//Porta de Leitura do Sensor de Temperatura
int LED = 13;//Porta de Escrita para o LED quando o mesmo Atingir 40 Graus
int valorLido = 0;
float temperatura = 0;
float temperaturaLida;

void setup() {
   /***Definição das Portas ***/
    pinMode(LED, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    digitalWrite(9, LOW);
  /***Habilitando a leitura da Porta Serial***/
    Serial.begin(9600);

}


void loop() {

    temperaturaLida = vertificaTemperatura();

    Serial.println(temperaturaLida);
    if (temperaturaLida > 40) {
        digitalWrite(LED, HIGH);
    }
    if (temperaturaLida <= 39) {
        digitalWrite(LED, LOW);
    }


   /***Verificando a Temperatura Lida para jogar no Indicador de LCD***/
    if ((temperaturaLida >= 20.00) && (temperaturaLida < 30.00)) {
        numeroDois();
    }
    if (temperaturaLida >= 30.00 && temperaturaLida < 40.00) {
        numeroTres();
    }
    if (temperaturaLida >= 40.00 && temperaturaLida < 50.00) {
        numeroQuatro();
    }
    if (temperaturaLida >= 50.00 && temperaturaLida < 60.00) {
        numeroCinco();
    }
    if (temperaturaLida >= 60.00 && temperaturaLida < 70.00) {
        numeroSeis();
    }



}


/***Função para checar a Temperatura***/
float vertificaTemperatura() {
   /***Realiza Leitura da Porta analógica***/
    valorLido = analogRead(LM35);
   /***Ajusta o valor do Sensor***/
    temperatura = (valorLido * 0.00488);
    temperatura = temperatura * 100;

   /***Aguardando para próxima leitura***/
    delay(500);

    return temperatura;
}

/***Função para escrever o número no mostrador***/
void numeroUm() {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);


}

/***Função para escrever o número no mostrador***/
void numeroDois() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);


}
/***Função para escrever o número no mostrador***/
void numeroTres() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);


}
/***Função para escrever o número no mostrador***/
void numeroQuatro() {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);


}
/***Função para escrever o número no mostrador***/
void numeroCinco() {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);


}
/***Função para escrever o número no mostrador***/
void numeroSeis() {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);


}
/***Função para escrever o número no mostrador***/
void numeroSete() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);


}

/***Função para escrever o número no mostrador***/
void numeroOito() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);


}

/***Função para escrever o número no mostrador***/
void numeroNove() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);


}
/***Função para escrever o número no mostrador***/
void numeroZero() {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
}
