#include <stdio.h>
#include <stdlib.h>

struct _DynArray {
	int cur_size;
	int max_size;
	int* data;
};

typedef struct _DynArray* DynArray;

//1 if successfull, else 0
int init_dyn_array(DynArray* a) {
	*a = malloc(sizeof(struct _DynArray));
	if (*a == NULL) return 0;

	(*a)->data = malloc(sizeof(int));
	if ((*a)->data == NULL) {
		free(*a);
		return 0;
	}

	(*a)->max_size = 1;
	(*a)->cur_size = 0;
	return 1;
}

void free_dyn_array(DynArray *a) {
	free((*a)->data);
	free(*a);
}

void dyn_array_add(DynArray a, int n) {
	if (a->cur_size < a->max_size) {
		a->data[a->cur_size] = n;
		a->cur_size++;
	}
	else {
		int* temp = realloc(a->data, a->max_size * 2 * sizeof(int));
		if (a->data == NULL) {
			printf("dyn_array_add failed to reallocate memory\n");
			free(a->data);
			return;
		}
		a->data = temp;
		a->max_size *= 2;
		a->data[a->cur_size] = n;
		a->cur_size++;
	}
}

void dyn_array_print(DynArray a) {
	if (a == NULL) {
		printf("\nNULL pointer given to dyn_array_print\n");
		return;
	}
	printf("\nDynamic Array of size %i:\n", a->cur_size);
	for (int i = 0; i < a->cur_size; i++) {
		printf("%i, ", a->data[i]);
	}
	printf("\n");
}


//here cur size=max size (except for empty dynamic array)
struct _DynArrayMin {
	int cur_size;
	int* data;
};

typedef struct _DynArrayMin* DynArrayMin;

//1 if successfull, else 0
int init_dyn_array_min(DynArrayMin* a) {
	*a = malloc(sizeof(struct _DynArray));
	if (*a == NULL) return 0;

	(*a)->data = malloc(sizeof(int));
	if ((*a)->data == NULL) {
		free(*a);
		return 0;
	}

	(*a)->cur_size = 0;

	return 1;
}

void free_dyn_array_min(DynArrayMin *a) {
	free((*a)->data);
	free(*a);
}

void dyn_array_min_add(DynArrayMin a, int n) {
	if (a->cur_size == 0) {
		a->data[a->cur_size] = n;
		a->cur_size++;
	}
	else {
		int* temp = realloc(a->data, (a->cur_size + 1) * sizeof(int));
		if (a->data == NULL) {
			printf("dyn_array_add failed to reallocate memory\n");
			free(a->data);
			return;
		}
		a->data = temp;
		a->data[a->cur_size] = n;
		a->cur_size++;
	}

}

void dyn_array_min_print(DynArrayMin a) {
	if (a == NULL) {
		printf("\nNULL pointer given to dyn_array_min_print\n");
		return;
	}
	printf("\nDynamic Array of size %i:\n", a->cur_size);
	for (int i = 0; i < a->cur_size; i++) {
		printf("%i, ", a->data[i]);
	}
	printf("\n");
}

int main() {
	DynArray a = NULL;
	if (init_dyn_array(&a) == 0) {
		printf("init dyn array failed\n");
		return 0;
	}
	dyn_array_add(a,1);
	printf("cur size%i\n", a->cur_size);
	for (int i = 2; i < 10; i++) {
		dyn_array_add(a, i);
	}
	dyn_array_print(a);
	printf("\nmax size%i\n", a->max_size);
	free_dyn_array(&a);

	DynArrayMin b = NULL;
	if (init_dyn_array_min(&b) == 0) {
		printf("init dyn array min failed\n");
		return 0;
	}
	dyn_array_min_add(b, 1);
	printf("cur size%i\n", b->cur_size);
	for (int i = 2; i < 10; i++) {
		dyn_array_min_add(b, i);
	}
	dyn_array_min_print(b);
	printf("\nb cur size: %i", b->cur_size);
	free_dyn_array_min(&b);
}
