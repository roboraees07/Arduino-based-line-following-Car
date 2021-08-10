//Motor shields connections with arduino Nano or Uno
int In1 = 7;
int In2 = 8;
int In3 = 4;
int In4 = 3;
int ENA = 5;
int ENB = 6;
int SPEED = 250;

/// Sensors Pins
const int Ir1 = A0;
const int Ir2 = A1;

// Defining values of IR sensors

int Ir1Val = analogRead(Ir1);
int Ir2Val = analogRead(Ir2);


void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
   if (analogRead(Ir1)<200){
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      analogWrite(ENA, SPEED);
     
    }
    
    else  {
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      analogWrite(ENA, SPEED);
      digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
      analogWrite(ENB, SPEED);
    }
      

    if(analogRead(Ir2)<200){
       digitalWrite(In3, HIGH);
      digitalWrite(In4, LOW);
      analogWrite(ENB, SPEED);
    }

    else  {
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      analogWrite(ENA, SPEED);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
      analogWrite(ENB, SPEED);
      
    }
   Serial.print(analogRead(Ir1));
   Serial.print("Hurray ");
   Serial.println(analogRead(Ir2));
  
}
