
int umidade;

void setup()
{
  Serial.begin(9600);
  delay(1000);//Aguarda 1 seg antes de acessar as informações do sensor
}

void loop()
{
  
  
   umidade = analogRead(A0);
  umidade = map(umidade, 1023, 0, 0, 116);
  Serial.print("Umidade = ");
  Serial.println(umidade);

  //Não diminuir o valor abaixo. O ideal é a leitura a cada 2 segundos
  delay(2000);  
}
