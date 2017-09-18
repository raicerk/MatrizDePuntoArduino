
#include "LedControl.h"     //simpre incluimos la libreria de control 

const byte DIN      = D5;   //Lo conectamos en din
const byte CS       = D6;   //Lo conectamos a Load (cs)
const byte CLK      = D7;   //Lo conectarmos a CLK 
const byte QTD_DISP =  1;   //El nuemro de matriz con controlador M72XX

LedControl ledMatrix = LedControl(DIN, CLK, CS, QTD_DISP);

void setup() {
  
  // El MAX72XX está en modo de ahorro de energía en el arranque, tenemos que hacer que despierte
  ledMatrix.shutdown(0, false);  //modo 'shutdown' no display '0' y FALSE
  
  // Establecer el brillo a un valor medio
  ledMatrix.setIntensity(0, 5);  //intensidad del display '0' y 5 (0~16)
  
  // y borramos la pantalla
  ledMatrix.clearDisplay(0);     //borrar pantalla '0'
}

void loop(){

  char texto[] = "Adiowis"; //Texto a mostrar en la matriz

  //Texto a mostrar en la matriz (Ejemplo de conversion de string a Char, descomentar para probar
  //String enviar = "Holiwis";  
  //enviar.toCharArray(texto,50);

  //Muestra texto de izquiera a derecha
  ledMatrix.clearDisplay(0);
  ledMatrix.printStringScroll(0, 0, texto, 50, '<');
  delay(500);

  //Muestra el texto de derecha a izquierda
  ledMatrix.clearDisplay(0);
  ledMatrix.printStringScroll(0, 0, texto, 50, '>');
  delay(500);

}




