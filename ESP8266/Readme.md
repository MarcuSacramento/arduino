#ESP8266-01: Conexão Simples

Apenas para documentar o modo de operação do módulo WiFi

O Módulo funciona pelo envio de Comandos via Serial.
Para utilizar o Arduino para comunicação Serial, estabelecer que nenhuma porta envie ou receba comandos.
[Vídeo de Exemplo](https://youtu.be/8DMVtXN5pMY)
![BreadBoard](https://github.com/MarcuSacramento/arduino/blob/master/ESP8266/Conex%C3%A3o%20Simples_bb.png)
![Schematic](https://github.com/MarcuSacramento/arduino/blob/master/ESP8266/Conex%C3%A3o%20Simples_Esquem%C3%A1tico.png)

#### Configuração Básica:

| Comando                      | Ação | Observação |
|------------------------------|------|------------|
| AT+RST                       | Reset do Módulo      |            |
| AT                           | Teste de envio de Comandos     |            |
| AT+GMR                       | Versão do Firmware     |            |
| AT+CWLAP                     | Listagem das Redes WiFi Disponíveis     |            |
| AT+CWJAP="rede-wifi","senha" | Conexão a rede WiFi especificada    |            |
| AT+CWMODE=1                  | Modo de Operação     | Servidor            |
| AT+CIFSR                     | Mostrar IP Atual     |            |
| AT+CIPMUX=1                  | Modo de Múltiplas Conexões     | Habilitado           |
| AT+CIPSERVER=1,80            | Modo Servidor TCP     | Servidor Criado na Porta 80           |
| AT+CIPSEND=0,93              | Envio de Informações ao requisitante     | Após requisitar no browser a informação pode ser enviada via Serial Monitor:Enviar no Canal 0(zero) ```<head><meta http-equiv=""refresh"" content=""3""></head><h1><u>ESP8266 - Web Server</u></h1>```            |
| AT+CIPCLOSE=0                | Encerrar o envio     | Após o Cliente receber os dados é encerrada a conexão liberando o módulo para novas requisições:Encerrar o Canal 0)zero)            |


#### Paleta de Comandos:
http://www.pighixxx.com/test/wp-content/uploads/2014/12/ESP8266Ref.pdf

https://room-15.github.io/blog/2015/03/26/esp8266-at-command-reference/

http://www.pridopia.co.uk/pi-doc/ESP8266ATCommandsSet.pdf

#### Referências:
http://rancidbacon.com/files/kiwicon8/ESP8266_WiFi_Module_Quick_Start_Guide_v_1.0.4.pdf

http://blog.filipeflop.com/wireless/esp8266-arduino-tutorial.html

#### Desafios:
https://olimex.wordpress.com/2015/01/29/esp8266-building-hello-world-blink-led-and-simple-web-server-to-drive-the-relay-and-check-button-status/

https://petestechprojects.wordpress.com/2014/12/10/mini-server-on-arduino-esp8266/

https://petestechprojects.wordpress.com/2014/12/03/auto-esp8266-server-init/
https://petestechprojects.wordpress.com/2014/12/04/arduino-parsing-for-occurrence-of-string-from-serial-port/
https://hackaday.io/project/5150-arduino-ide-for-esp8266-quickstart-guide
