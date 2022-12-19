int buzzerPin = 7;
int tempo = 200;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int duration[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
int ledPins[] = {8, 9, 10, 11, 12, 13};
int ledCount = 6;

void playTheTone(char note, int duration) {
  char notesName[] = { 'c', 'd', 'e', 'f', 'g' };
  int tones[] = { 261, 293, 329, 349, 392 };

  for (int i = 0; i <= sizeof(tones); i++) {
    if (note == notesName[i]) {
      tone(buzzerPin, tones[i], duration);
    }
  }
}

void offLEDS() {
  for (int i = 0; i < sizeof(ledPins); i++){
    digitalWrite(ledPins[i], LOW);
  }
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < sizeof(ledPins); i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int j = 0;
  for (int i = 0; i <= sizeof(notes)-1; i++) {
    if (notes[i] == ' ') {
      delay(duration[i] * tempo);
    } else {
      playTheTone(notes[i], duration[i] * tempo);
      offLEDS();
      digitalWrite(ledPins[j], HIGH);
      j++;
      j = j % ledCount;
    }
    delay((tempo*2)*duration[i]);
  }
}
