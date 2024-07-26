#define INFERENCE

#ifdef INFERENCE

#include "aifes_e_f32_fnn.h"

#endif

#define QUEUE_SIZE 200
#define ANALOG_PIN 2

uint32_t arr[QUEUE_SIZE];
float input_data[QUEUE_SIZE]; // AIfES input data
float output_data[1]; // AIfES output data

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  //set the resolution to 12 bits (0-4095)
  analogReadResolution(12);
  analogSetAttenuation(ADC_0db);

  pinMode(23, OUTPUT);

  delay(10000);
}

void loop() {
  uint32_t startTime = micros();

  for (size_t i = 0; i < QUEUE_SIZE; i++) {
    arr[i] = analogRead(ANALOG_PIN);
  }

#ifdef INFERENCE

  for (int i = 0; i < QUEUE_SIZE; i++) {
    input_data[i] = arr[i];
  }

  aifes_e_f32_fnn_inference((float*)input_data,(float*)output_data);

  Serial.printf("%f\n", output_data[0]);

  if (output_data[0] > 0.5) {
    digitalWrite(23, HIGH);
  } else {
    digitalWrite(23, LOW);
  }

#else
  // print out the values you read:
  Serial.print("1,");
  for (size_t i = 0; i < QUEUE_SIZE; i++) {
    Serial.print(arr[i]);
    if (i < QUEUE_SIZE-1) {
      Serial.print(",");
    }
  }
  Serial.print("\n");
#endif
}

