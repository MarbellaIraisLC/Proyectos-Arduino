const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
const int triggerEmisor = 3;
const int echoReceptor = 2;
const int triggerEmisor1= 5;
const int echoReceptor1 = 4;
const int valorUmbral = 20; //valor de la distancia en cm para detenerse
long tiempoEntrada;
float distanciaEntrada;
long tiempoEntrada1;
float distanciaEntrada1;

int pinR = 2, pinL = 3, followerR, followerL; // PINS DE LOS SENSORES SEGUIDORES DE LÍNEA



const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;    
int rojo = 0;  
int verde = 0;  
int azul = 0;  

void setup()
{
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
pinMode(triggerEmisor,OUTPUT);
pinMode(echoReceptor,INPUT);
pinMode(triggerEmisor1,OUTPUT);
pinMode(echoReceptor1,INPUT);

  pinMode (pinR, INPUT);
  pinMode (pinL, INPUT);

  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);  
Serial.begin(9600);
}

void loop()
{


  color(); 
  Serial.print("   ");  
  Serial.print(rojo, DEC);  
  Serial.print("   ");  
  Serial.print(verde, DEC);  
  Serial.print("   ");  
  Serial.print(azul, DEC);  


  
followerR = digitalRead (pinR);

followerL = digitalRead (pinL);


sensorUltrasonidos();

// Si el valor de la distancia es menor que 5 cm se para y sigue recto en caso contrario
if(distanciaEntrada>valorUmbral&&distanciaEntrada1<valorUmbral&&(followerR == 0)&(followerL == 0))
{
robotAvance();
}
if ((followerR == 0)& (followerL == 1)) //RIGHT - DERECHA
{

}

if ((followerR == 1)& (followerL == 0)) //LEFT - IZQUIERDA
{
    
}
if(distanciaEntrada>valorUmbral&&distanciaEntrada1<valorUmbral&&(followerR == 1)& (followerL == 1))
{
robotParar ();
}
}


 
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}




void sensorUltrasonidos()
{
digitalWrite(triggerEmisor,LOW); digitalWrite(triggerEmisor1,LOW);
delayMicroseconds(10);
digitalWrite(triggerEmisor, HIGH); digitalWrite(triggerEmisor1, HIGH);
delayMicroseconds(10);
tiempoEntrada=pulseIn(echoReceptor, HIGH); tiempoEntrada1=pulseIn(echoReceptor1, HIGH);
distanciaEntrada= int(0.017*tiempoEntrada); distanciaEntrada1= int(0.017*tiempoEntrada1);// Fórmula para calcular la distancia en cm
Serial.println("El valor de la distancia es ");
Serial.println(distanciaEntrada);
Serial.println("El valor de la distancia es ");
Serial.println(distanciaEntrada1);
delay(200);
}

void robotAvance()
{
digitalWrite (IN1, HIGH);
digitalWrite (IN2, HIGH);
digitalWrite (IN3, HIGH);
digitalWrite (IN4, HIGH);
}
void robotParar()
{
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
}
void robotIzquierda()
{
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
}
void robotDerecha()
{
digitalWrite (IN1, LOW);
digitalWrite (IN2, LOW);
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
}
