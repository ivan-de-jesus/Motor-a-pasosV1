int pasos;
char dato[30];
byte posicion=0;  //Variable para cambiar la posición de los caracteres del array 

void setup() {
Serial.begin(115200);// 
pinMode(23, OUTPUT); // Es el Giro, en Bajo “0” lógico Sentido Horario y “1” Anti Horario.
pinMode(22, OUTPUT); // Velocidad de Operación, Controlada por Pulsos.
//digitalWrite(8, LOW); // Sentido Horario
//digitalWrite(9, LOW);
}
void loop() {
if (Serial.available()){
  memset(dato, 0,sizeof(dato));//memset borra el contenido del array  "cadena" desde la posición 0 hasta el final sizeof
  while(Serial.available()>0) //Mientras haya datos en el buffer ejecuta la función
    {
      delay(5); //Poner un pequeño delay para mejorar la recepción de datos
      dato[posicion]=Serial.read();//Lee un carácter del string "cadena" de la "posicion", luego lee el siguiente carácter con "posicion++"
      posicion++;
    }
    pasos = atoi(dato);//Convertimos la cadena de caracteres en enteros
    
//Configuramos el sentido horario   
if(dato[0] == '+'){
      digitalWrite(8, HIGH);
    }else if(dato[0] == '-'){
      digitalWrite(8, LOW);
  }

for(int i = 1; i<= pasos; i++ ){
  digitalWrite(9, HIGH);
  delayMicroseconds(1000);
  digitalWrite(9, LOW);
  delayMicroseconds(1000);
  }
 Serial.print("No. Pasos: ");
 Serial.println(pasos);
 posicion=0;//Ponemos la posicion a 0
 }
}
