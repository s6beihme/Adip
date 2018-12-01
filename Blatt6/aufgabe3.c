/* Nochmal Studentendatenbank */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
  int matid;
  char prename[30];
  char surname[30];
} student;

typedef struct studentArray {
  student **students;
  int allocated; // allocated memory
  int size; // number of elements
} studentArray;

void allocStudentArray(studentArray *arr, int n) {
  if ((arr->students = (student **) malloc(n*sizeof(student *))) == NULL) {
    printf("allocStudentArray: Memory allocation failed.\n");
    return;
  }
  for (int i=0; i<n; i++) {
    arr->students[i] = NULL;
  }
  arr->allocated = n;
  arr->size = 0;
}

void freeStudentArray(studentArray *arr) {
  for (int i=0; i<arr->allocated; i++) {
    arr->students[i] = NULL;
    free(arr->students[i]);
  }
  free(arr->students);
}

void printStudent(student *st) {
  printf("Matrikelnummer: %d, ", st->matid);
  printf("Vorname: %s, ", st->prename);
  printf("Nachname: %s\n", st->surname);
}

void printStudents(studentArray *arr) {
  for (int i=0; i<arr->size; i++) {
    printStudent(arr->students[i]);
  }
}

void addStudent(studentArray *arr, int matid, const char *prename, const char *surname) {
  if (arr->size == arr->allocated) {
    printf("addStudent: Could not add student: Not enough memory allocated.\n");
    return;
  }
  student *st = (student *) malloc(sizeof(student));
  st->matid = matid;
  strcpy(st->prename, prename);
  strcpy(st->surname, surname);
  arr->students[arr->size] = st;
  arr->size++;
}

void removeStudent(studentArray *arr, int matid) {
  for (int i=0; i<arr->size; i++) {
    if (arr->students[i]->matid == matid) {
      free(arr->students[i]);
      for (int j=i; j<arr->size-1; j++) {
        arr->students[j] = arr->students[j+1];
      }
      arr->size--;
      break;
    }
  }
}

int main() {
  // Test student
  student *test = (student *) malloc(sizeof(student));
  test->matid=12345;
  strcpy(test->prename, "Vorname");
  strcpy(test->surname, "Nachname");
  printStudent(test);
  free(test);

  const int n = 20;
  studentArray arr;
  allocStudentArray(&arr, n);

  addStudent(&arr, 12345, "Prename1", "Surname1");
  addStudent(&arr, 12346, "Prename2", "Surname2");
  addStudent(&arr, 12347, "Prename3", "Surname3");

  removeStudent(&arr, 12346);

  printStudents(&arr);

  freeStudentArray(&arr);
}
