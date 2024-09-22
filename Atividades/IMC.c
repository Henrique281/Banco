#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE_NAME 20
#define SIZE_LIST 5
#define SIZE_LISTNAMES 14
#define MIN_AGE 15
#define MAX_AGE 60
#define MIN_HEIGHT 1.50
#define MAX_HEIGHT 1.90
#define MIN_WEIGHT 30.0
#define MAX_WEIGHT 120.0

struct Volunteer{
  char name[SIZE_NAME];
  unsigned short age;
  float height;
  float weight;
};

char* randName(){
  char *listNames[] = {"Harry Mason", "Cheryl Mason", "Dahlia Gillespie", "Lisa Garland", "Cybil Bennett", "Alessa Gillespie", "Michael Kaufmann",
                      "James Sunderland", "Mary Shepherd-Sunderland", "Angela Orosco", "Eddie Dombrowski", "Laura", "Maria", "Ernest Baldwin"};
  return listNames[rand() % SIZE_LISTNAMES];
}

int randStatus(int min, int max){
  int value;
  do {
    value = rand();
  } while (!(value > min && value < max));

  return value;
}

float randStatusFloat(float min, float max){
  float value;
  const char progress[4] = {'|', '/', '-', '\\'};
  int i = 0;

  do {
    value = (((float)rand()/(float)(RAND_MAX)) * 100.0);
    printf("\r%c", progress[i % 4]); // indicador de progresso
    fflush(stdout); // limpa o buffer de saida
    sleep(10000); // necessario para indicador de progresso funciona, talvez o compilador reclame...
    i++;
  } while (!(value > min && value < max));

  return value;
}


struct Volunteer* randVolunteers(){
  struct Volunteer *volunteers = malloc(sizeof(struct Volunteer)*SIZE_LIST);

  for (int i = 0;  i < SIZE_LIST; i++) {
    strcpy(volunteers[i].name, randName());
    volunteers[i].age= randStatus(MIN_AGE, MAX_AGE);
    volunteers[i].height= randStatusFloat(MIN_HEIGHT, MAX_HEIGHT);
    volunteers[i].weight = randStatusFloat(MIN_WEIGHT, MAX_WEIGHT);
  }

  return volunteers;
}

void imcIndividualAverage(struct Volunteer *volunteers){
  for (int i = 0; i < SIZE_LIST; i++) {
    printf("Nome: %s\nIdade: %i\nAltura: %.2fcm\nPeso: %.2lfkg\nIMC: %.1f\n\n",
            volunteers[i].name, volunteers[i].age, volunteers[i].height,
            volunteers[i].weight, volunteers[i].weight / (volunteers[i].height * volunteers[i].height));
  }
}
void generalAverageImc(struct Volunteer *volunteers){
  float imcMedia = 0.0;
  for (int i = 0; i < SIZE_LIST; i++) {
    imcMedia += volunteers[i].weight / (volunteers[i].height * volunteers[i].height);
  }
  printf("Media IMC dos voluntarios : %.1f\n", imcMedia/SIZE_LIST);
}

int main(void) {
  srand(time(NULL));
  printf("procurando no banco de dados, aguarde...\n");
  struct Volunteer *volunteers=randVolunteers();
  imcIndividualAverage(volunteers);
  generalAverageImc(volunteers);

  free(volunteers);
  return 0;
}