const int trig=9;
const int echo =8;
int sure;
int mesafe;
const int in3=6;
const int in4=7;
const int e2=5;
void setup() {

  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(e2,OUTPUT);
}

void loop() {
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  
  sure=pulseIn(echo,HIGH);
  mesafe=(sure/2)/28.5;
  Serial.print(mesafe);
  Serial.println(" cm");
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  fonksiyon(mesafe);
}

void fonksiyon(int mesafe)
{
  if(mesafe>200)
  {
    analogWrite(e2,255);
  }
  else if (mesafe<200 && mesafe >150 )
  {
    analogWrite(e2,200);
  }
  else if (mesafe<150 && mesafe >100)
  {
    analogWrite(e2,155);
  }
  else if (mesafe<100 && mesafe > 50)
    {
      analogWrite(e2,100);
    }
  else if (mesafe <50 && mesafe >30)
  {
      analogWrite(e2,55);
  }
  else
  {
      analogWrite(e2,0);
  }
}
