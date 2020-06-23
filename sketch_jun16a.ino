int led[] = {2,3,4,5};
int swtch[] = {6,7,8,9};
int hz[] = {262,330,392,523};
int randNum[4];
int x = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A5));
  for(int i=0;i<4;i++){
    pinMode(led[i],OUTPUT);
    pinMode(swtch[i],INPUT);
  }
  Serial.println("----------------------------");
  for(int i=0;i<4;i++){
    randNum[i] = random(0,4);
    digitalWrite(led[randNum[i]],1);
    Serial.println(randNum[i]);
    tone(10,hz[randNum[i]],250);
    delay(500);
    digitalWrite(led[randNum[i]],0);
  }
  Serial.println("----------------------------");
}

void loop() {
  for(int i=0;i<4;i++){
    if(digitalRead(swtch[i]) == 1){
      Serial.print(i);
      Serial.println("를 눌렀습니다.");
      if(swtch[i] == randNum[x] + 6){
        x++;
        digitalWrite(led[i],1);
        tone(10,hz[i],250);
        delay(250);
        digitalWrite(led[i],0);
      }
      else {
        x=0;
        tone(10,648,500);
        delay(1000);
      }
    }
    else noTone(10);
  }
  if(x==4){
    for(int i=0;i<4;i++) {
      tone(10,hz[i],250);
      delay(250);
    }
    x=0;
  }
}
