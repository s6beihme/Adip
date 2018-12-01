/* Studentendatenbank */
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  char nachname[30];
  float note;
} student;

student *allocStudentArray(int n) {
  student *res;
  if ((res = (student *) malloc(n*sizeof(student))) == NULL) {
    printf("allocStudentArray: Memory allocation failed.\n");
    return NULL;
  }
  return res;
}

void freeStudentArray(student *students) {
  free(students);
}

void readStudents(student *students, int n) {
  for (int i=0; i<n; i++) {
    printf("Gib den Nachnamen ein:\n");
    scanf("%s", students[i].nachname);
    do {
      printf("Gib die Note ein (zwischen 1.0 und 5.0):\n");
      scanf("%f", &(students[i].note));
    } while (students[i].note < 1 || students[i].note > 5);
  }
}

float getMinGrade(student *students, int n) {
  if (n <= 0) {
    printf("getMinGrade: Minimum of an empty array is not defined.");
    return 0;
  }

  float min = students[0].note;
  for (int i=1; i<n; i++) {
    if (students[i].note < min) {
      min = students[i].note;
    }
  }

  return min;
}

float getAverageGrade(student *students, int n) {
  float sum = 0;
  for (int i=0; i<n; i++) {
    sum += students[i].note;
  }

  return sum/n;
}

int main() {
  int n;
  printf("Wie viele Studenten sollen hinzugefuegt werden?\n");
  scanf("%d", &n);
  student *students = allocStudentArray(n);
  readStudents(students, n);

  float minGrade = getMinGrade(students, n);
  printf("Die beste Note %f haben erhalten:\n", minGrade);
  for (int i=0; i<n; i++) {
    if (students[i].note == minGrade) {
      printf("%s\n", students[i].nachname);
    }
  }

  printf("Die Durchschnittsnote betraegt %f.", getAverageGrade(students, n));

  freeStudentArray(students);
}
