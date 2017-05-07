   /*
   Pinagem do RTC DS 3231
   
   pino GND => Pino A2
   pino VCC => Pino A3
   pino SDA => Pino A4
   pino SCL => Pino A5
   pino SQW => Desconectado
   pino 32K => Desconectado
   */
  
   #include <DS3231.h>
   #include <Wire.h>
   
   int Rele1 = 6;
   int Rele2 = 7;
   
   DS3231 Clock;
   bool Century=false;
   bool h12;
   bool PM;
   byte ADay, AHour, AMinute, ASecond, ABits;
   bool ADy, A12h, Apm;

   byte year, month, date, DoW, hour, minute, second;

   void setup() {
     
   pinMode(Rele1, OUTPUT);
   pinMode(Rele2, OUTPUT);
   digitalWrite(Rele1, HIGH);
   digitalWrite(Rele2, HIGH);  
     
   Wire.begin();
   Serial.begin(9600);
   pinMode(A2, OUTPUT);
   pinMode(A3, OUTPUT);
   digitalWrite(A3, HIGH);
   digitalWrite(A2, LOW);
                
   /* As linhas abaixo servem para acertar o modulo DS3231
   Para acertar, retire as barras e carregue o programa
   depois recoloque as barras novamente. */
        
   //  Clock.setSecond(00);  // Insira os Segundos 
   //  Clock.setMinute(55); // Insira os Minutos 
   //  Clock.setHour(3);     // Insira a Hora 
   //  Clock.setDoW(7);      // Insira o Dia da da semana dom=1
   //  Clock.setDate(15);  // Insira o Dia do Mês
   //  Clock.setMonth(4); // Insira o Mês
   //  Clock.setYear(16);    // Insira somente os dois ultimos digitos do Ano
        
   }
   
   void Relogio() {
   int second,minute,hour,date,month,year,temperature; 
   second=Clock.getSecond();
   minute=Clock.getMinute();
   hour=Clock.getHour(h12, PM);
   date=Clock.getDate();
   month=Clock.getMonth(Century);
   year=Clock.getYear(); 
  
  temperature=Clock.getTemperature();
  
  if(date<10)
  { Serial.print("0"); }
  Serial.print(date,DEC);
  Serial.print(" de ");
  if(month==1)
  { Serial.print("Janeiro"); }
  if(month==2)
  { Serial.print("Fevereiro"); }
  if(month==3)
  { Serial.print("Marco"); }
  if(month==4)
  { Serial.print("Abril"); }
  if(month==5)
  { Serial.print("Maio"); }
  if(month==6)
  { Serial.print("Junho"); }
  if(month==7)
  { Serial.print("Julho"); }
  if(month==8)
  { Serial.print("Agosto"); }
  if(month==9)
  { Serial.print("Setembro"); }
  if(month==10)
  { Serial.print("Outubro"); }
  if(month==11)
  { Serial.print("Novembro"); }
  if(month==12)
  { Serial.print("Dezembro"); }
  Serial.print(" de ");
  Serial.print("20");
  Serial.print(year,DEC);
    
  Serial.print(' ');
  Serial.print('\n');
  if(hour<10)
  { Serial.print("0"); }
  Serial.print(hour,DEC);
  Serial.print(':');
  if(minute<10)
  { Serial.print("0"); }
  Serial.print(minute,DEC);
  Serial.print(':');
  if(second<10)
  { Serial.print("0"); }
  Serial.print(second,DEC);
  Serial.print('\n');
  
  if(Clock.getDoW()==1)
  { Serial.print("Dom"); }
  if(Clock.getDoW()==2)
  { Serial.print("Seg"); }
  if(Clock.getDoW()==3)
  { Serial.print("Ter"); }
  if(Clock.getDoW()==4)
  { Serial.print("Qua"); }
  if(Clock.getDoW()==5)
  { Serial.print("Qui"); }
  if(Clock.getDoW()==6)
  { Serial.print("Sex"); }
  if(Clock.getDoW()==7)
  { Serial.print("Sab"); }
  
  Serial.print('\n');
  Serial.print("Temperatura= ");
  Serial.print(temperature);
  Serial.print('\n');
  Serial.print('\n');
  }
  
  void Rele_1() {
  
   minute=Clock.getMinute();
   hour=Clock.getHour(h12, PM);
   second=Clock.getSecond();
   
   // 1
   
   if((Clock.getDoW()==1) && (hour == 23) && (minute == 15))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==1) && (hour == 23) && (minute == 30))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==2) && (hour == 02) && (minute == 00))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==2) && (hour == 02) && (minute == 20))
   digitalWrite(Rele1, HIGH);
   
   // 2
   
   if((Clock.getDoW()==2) && (hour == 22) && (minute == 18))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==2) && (hour == 22) && (minute == 35))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==3) && (hour == 01) && (minute == 05))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==3) && (hour == 01) && (minute == 15))
   digitalWrite(Rele1, HIGH);
   
   // 3
   
   if((Clock.getDoW()==3) && (hour == 22) && (minute == 48))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==3) && (hour == 23) && (minute == 18))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==4) && (hour == 01) && (minute == 15))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==4) && (hour == 01) && (minute == 35))
   digitalWrite(Rele1, HIGH);
   
   // 4
   
   if((Clock.getDoW()==4) && (hour == 23) && (minute == 01))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==4) && (hour == 23) && (minute == 21))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==5) && (hour == 01) && (minute == 40))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==5) && (hour == 02) && (minute == 05))
   digitalWrite(Rele1, HIGH);
   
   // 5
   
   if((Clock.getDoW()==5) && (hour == 22) && (minute == 35))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==5) && (hour == 22) && (minute == 47))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==6) && (hour == 00) && (minute == 35))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==6) && (hour == 00) && (minute == 55))
   digitalWrite(Rele1, HIGH);
   
   // 6
   
   if((Clock.getDoW()==6) && (hour == 23) && (minute == 12))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==6) && (hour == 23) && (minute == 30))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==6) && (hour == 01) && (minute == 18))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==6) && (hour == 01) && (minute == 35))
   digitalWrite(Rele1, HIGH);
   
   // 7
   
   if((Clock.getDoW()==6) && (hour == 22) && (minute == 45))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==6) && (hour == 23) && (minute == 05))
   digitalWrite(Rele1, HIGH);
   
   if((Clock.getDoW()==1) && (hour == 01) && (minute == 20))
   digitalWrite(Rele1, LOW);
   if((Clock.getDoW()==1) && (hour == 01) && (minute == 38))
   digitalWrite(Rele1, HIGH);
   
   //
   
   }
   
    
   void Rele_2() {
   minute=Clock.getMinute();
   hour=Clock.getHour(h12, PM);
   
   // 1
   
   if((Clock.getDoW()==1) && (hour == 23) && (minute == 17))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==1) && (hour == 23) && (minute == 25))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==2) && (hour == 02) && (minute == 02))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==2) && (hour == 02) && (minute == 18))
   digitalWrite(Rele2, HIGH);
   
   // 2
   
   if((Clock.getDoW()==2) && (hour == 22) && (minute == 20))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==2) && (hour == 22) && (minute == 33))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==3) && (hour == 01) && (minute == 07))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==3) && (hour == 01) && (minute == 13))
   digitalWrite(Rele2, HIGH);
   
   // 3
   
   if((Clock.getDoW()==3) && (hour == 22) && (minute == 50))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==3) && (hour == 23) && (minute == 16))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==4) && (hour == 01) && (minute == 17))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==4) && (hour == 01) && (minute == 33))
   digitalWrite(Rele2, HIGH);
   
   // 4
   
   if((Clock.getDoW()==4) && (hour == 23) && (minute == 03))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==4) && (hour == 23) && (minute == 19))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==5) && (hour == 01) && (minute == 41))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==5) && (hour == 02) && (minute == 02))
   digitalWrite(Rele2, HIGH);
   
   // 5
   
   if((Clock.getDoW()==5) && (hour == 22) && (minute == 37))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==5) && (hour == 22) && (minute == 45))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==6) && (hour == 00) && (minute == 37))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==6) && (hour == 00) && (minute == 50))
   digitalWrite(Rele2, HIGH);
   
   // 6
   
   if((Clock.getDoW()==6) && (hour == 23) && (minute == 15))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==6) && (hour == 23) && (minute == 25))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==6) && (hour == 01) && (minute == 20))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==6) && (hour == 01) && (minute == 33))
   digitalWrite(Rele2, HIGH);
   
   // 7
   
   if((Clock.getDoW()==6) && (hour == 22) && (minute == 48))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==6) && (hour == 23) && (minute == 00))
   digitalWrite(Rele2, HIGH);
   
   if((Clock.getDoW()==1) && (hour == 01) && (minute == 22))
   digitalWrite(Rele2, LOW);
   if((Clock.getDoW()==1) && (hour == 01) && (minute == 35))
   digitalWrite(Rele2, HIGH);
   
   //
   
   }
   
      
  void loop() {
  
  Relogio();
  Rele_1();
  Rele_2();
 
  delay(1000);
  }

