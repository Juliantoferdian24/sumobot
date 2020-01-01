int echoPindepan  = A0;  
int trigPindepan = 9;  
int maximumRange = 65;
int minimumRange = 1 ;
long durationdepan, distancedepan;
int EchoPinkiri = A3;
int TrigPinkiri = 8 ;
long Durationkiri, Distancekiri;
int EchoPinkanan = A4;
int TrigPinkanan = 12;
long Durationkanan, Distancekanan;
int EchoPindepankanan = A5;
int TrigPindepankanan = 4 ;
long Durationdepankanan, Distancedepankanan;
int persenjarak;

//Sensor Cahaya
int LED = 11;
int sensor1 = A1;
int sensor2 = A2;
int lightValue = 50;
int jarak;
int baca;
int persenLDR;
int baca2;
int persenLDR2;

int Left1 = 11;
int Left2 = 10;
int Right1 = 6;
int Right2 = 5;


void setup()
{
  Serial.begin (9600);
  pinMode(trigPindepan, OUTPUT);
  pinMode(echoPindepan, INPUT);
  pinMode(TrigPinkiri, OUTPUT);
  pinMode(EchoPinkiri, INPUT);
  pinMode(TrigPinkanan, OUTPUT);
  pinMode(EchoPinkanan, INPUT);
  pinMode(TrigPindepankanan, OUTPUT);
  pinMode(EchoPindepankanan, INPUT);

  //Sensor Cahaya
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  // sensor (1,2,3,4) kiri ke kanan

  //Set pin
  pinMode(Left1, OUTPUT); 
  pinMode(Right1, OUTPUT);
  pinMode(Left2, OUTPUT); 
  pinMode(Right2, OUTPUT);
  delay(5000);



}
void loop() {

  lightSensor();
//LDR2 kanan ldr kiri
  if ((persenLDR >70 ) && (persenLDR2 < 70) )
  {
    Serial.println("kiri bos");
    digitalWrite(LED, HIGH);
    kiri ();
  }

  if ((persenLDR < 70) && (persenLDR2 > 70))
  {
    Serial.println("kanan bos");
    digitalWrite(LED, HIGH);
    kanan ();
  }
  if ((persenLDR < 70) && (persenLDR2 < 70))
  {
    Serial.println("mundur bos");
    digitalWrite(LED, HIGH);
    mundur ();
    kiri();
    kiri();
  }
  if ((persenLDR > 70) && (persenLDR2 > 70))
  {
    nyusahin ();
    Serial.println("sesuai sistem");
    digitalWrite(LED, LOW);


    if (
      (distancedepan >= maximumRange || distancedepan <= minimumRange) &&
      (Distancekiri <= maximumRange && Distancekiri >= minimumRange) &&
      (Distancekanan >= maximumRange || Distancekanan <= minimumRange) &&
      (Distancedepankanan >= maximumRange || Distancedepankanan <= minimumRange)
    )
    {
      Serial.println("left");
      kiri();

    }
    if (
      (distancedepan <= maximumRange && distancedepan >= minimumRange) &&
      (Distancekiri >= maximumRange || Distancekiri <= minimumRange) &&
      (Distancekanan >= maximumRange || Distancekanan <= minimumRange) &&
      (Distancedepankanan >= maximumRange || Distancedepankanan <= minimumRange)
    )
    {
      Serial.println("frontkiri");
      maju();
    }
    if
    (
      (distancedepan >= maximumRange || distancedepan <= minimumRange) &&
      (Distancekiri >= maximumRange || Distancekiri <= minimumRange) &&
      (Distancekanan <= maximumRange && Distancekanan >= minimumRange) &&
      (Distancedepankanan >= maximumRange || Distancedepankanan <= minimumRange)
    )
    {
      Serial.println("right");
      kanan ();
    }
    if
    (
      (distancedepan >= maximumRange || distancedepan <= minimumRange) &&
      (Distancekiri >= maximumRange || Distancekiri <= minimumRange) &&
      (Distancekanan >= maximumRange || Distancekanan <= minimumRange) &&
      (Distancedepankanan <= maximumRange && Distancedepankanan >= minimumRange)
    )
    {
      Serial.println("frontkanan");
      maju();
    }
    if (
      (distancedepan <= maximumRange || distancedepan >= minimumRange) &&
      (Distancekiri >= maximumRange || Distancekiri <= minimumRange) &&
      (Distancekanan >= maximumRange || Distancekanan <= minimumRange) &&
      (Distancedepankanan <= maximumRange || Distancedepankanan >= minimumRange)
    )
    {
      Serial.println("front");
      maju();
    }
    if (
      (distancedepan >= maximumRange || distancedepan <= minimumRange) &&
      (Distancekiri >= maximumRange || Distancekiri <= minimumRange) &&
      (Distancekanan >= maximumRange || Distancekanan <= minimumRange) &&
      (Distancedepankanan >= maximumRange || Distancedepankanan <= minimumRange)
    )
    {
      Serial.println("muter");
      kanan();
      kanan();
     
      
    }
    /* else{
       int jarak[4];
       jarak[1] = distancedepan;
       jarak[2] = Distancekiri;
       jarak[3] = Distancekanan;
       jarak[4] = Distancebelakang;
       int a=1;
       for(int i=0;i<=4;i++){
         while(jarak[i]<=maximumRange && jarak[i]>=minimumRange){
             if (min(jarak[a],jarak[i])== jarak[i]){
             a=i;}
             Serial.println(jarak[a]);
           }
           }
        if(a==1) maju();
        if(a==2) kiri();
        if(a==3) kanan();
        if(a==4) mundur();
       }*/




  }



}
void maju() {
  analogWrite(Left1,215 );
  analogWrite(Right1, 255);
  analogWrite(Left2, 0);
  analogWrite(Right2, 0);
  Serial.println("maju selesai");
  delay(50);
}

void mundur() {
  analogWrite(Left1,0 );
  analogWrite(Right1, 0);
  analogWrite(Left2, 215);
  analogWrite(Right2, 255);
  Serial.println("mundur selesai");
  delay (50);
}

void kanan() {
  analogWrite(Left1,0 );
  analogWrite(Right1, 0);
  analogWrite(Left2, 0);
  analogWrite(Right2, 255);
  Serial.println("kanan selesai");
  delay (50);
}

void kiri() {
  analogWrite(Left1,0 );
  analogWrite(Right1, 0);
  analogWrite(Left2, 255);
  analogWrite(Right2, 0);
  Serial.println("kanan selesai");
  delay(50);
}


void nyusahin ()
{ digitalWrite(trigPindepan, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPindepan, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPindepan, LOW);
  durationdepan = pulseIn(echoPindepan, HIGH);
  distancedepan = durationdepan / 58.2;
  Serial.println("jarak depan =" + String(distancedepan));

  digitalWrite(TrigPinkiri, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPinkiri, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPinkiri, LOW);
  Durationkiri = pulseIn(EchoPinkiri, HIGH);
  Distancekiri = Durationkiri / 58.2;
  Serial.println("jarak kiri = " + String(Distancekiri));

  digitalWrite(TrigPinkanan, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPinkanan, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPinkanan, LOW);
  Durationkanan = pulseIn(EchoPinkanan, HIGH);
  Distancekanan = Durationkanan / 58.2;
  Serial.println("jarak kanan =" + String(Distancekanan));


  digitalWrite(TrigPindepankanan, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPindepankanan, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPindepankanan, LOW);
  Durationdepankanan = pulseIn(EchoPindepankanan, HIGH);
  Distancedepankanan = Durationdepankanan / 58.2;
  Serial.println("jarak depankanan =" + String(Distancedepankanan));


}
void lightSensor() {


  baca = analogRead(sensor1);
  persenLDR = map(baca, 500, 1023, 0, 100);
  Serial.println("Nilai Intensitas Cahaya1: " + String(baca) + " | Persentase: " + String(persenLDR) + "%");

  baca2 = analogRead(sensor2);
  persenLDR2 = map(baca2, 500, 1023, 0, 100);
  Serial.println("Nilai Intensitas Cahaya2: " + String(baca2) + " | Persentase: " + String(persenLDR2) + "%");


}
