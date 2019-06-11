const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   
boolean si=false;
 long guardar=0.0;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
    
  
}

void loop()
{
    
   
  long t; //tiempo que demora en llegar el eco
  long d; //distancia en centimetros
  

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(86400000);          //Enviamos un pulso cada día
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  if(guardar<=d){
    guardar=d;
    si=true;
  }
  
  
  Serial.print(si);      //Mostramos true si la planta ha crecido
            
}
