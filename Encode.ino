int a = 8;
int b = 9;


int Ra, Rb; //Recebe a e b
volatile int countA = 0;
int countB = 0;

void setup() {
  Serial.begin(9600);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
   Ra = digitalRead(a);
   Rb = digitalRead(b);
   
}

void loop() {
 // Interessante que cada passo do encolde ele soma dois no contador, isso por que almentou a resolução do mesmo.
  if(Ra == Rb){                   // Analiza o estado atual do encode                     
    if( Rb != digitalRead(b)){    // Espera alguma alteração podendo ser para DIREIRA 
      Ra = digitalRead(a);
      Rb = digitalRead(b);
    
      countA++; 
      Serial.print("A = ");
      Serial.println(countA);  
    }
    if( Ra != digitalRead(a)){   // OU ESQUERDA 
      Ra = digitalRead(a);
      Rb = digitalRead(b);
    
      countA--; 
      Serial.print("A = ");
      Serial.println(countA);  
    }
  }

  else {                          // caso o estado inicial seja diferente o mecanismo anterior se inverte.
    if( Rb != digitalRead(b)){
      Ra = digitalRead(a);
      Rb = digitalRead(b);
      countA--;
      Serial.print("A = ");
      Serial.println(countA);  
    }
    if( Ra != digitalRead(a)){
      Ra = digitalRead(a);
      Rb = digitalRead(b);
    
      countA++; 
      Serial.print("A = ");
      Serial.println(countA);  
    }
  } 
}
