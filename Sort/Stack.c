#include "Stack.h"




void StackInit(Stack* ps) {
	assert(ps);

	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

void StackDestroy(Stack* ps) {
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}


void StackPush(Stack* ps, STDatatype x) {
	assert(ps);
	
	if (ps->top == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDatatype* newarr = (STDatatype*)realloc(ps->arr, newcapacity * sizeof(STDatatype));
		if (newarr == NULL) {
			perror("realloc fail");
			exit(-1);
		}
		ps->arr = newarr;
		ps->capacity = newcapacity;
	}
	
	ps->arr[ps->top++] = x;
	
}


void StackPop(Stack* ps) {
	assert(ps && ps->top != 0);

	--ps->top;
}


STDatatype StackTop(Stack* ps) {
	assert(ps);
	assert(ps->top != 0);

	return ps->arr[ps->top - 1];
}

int StackSize(Stack* ps) {
	assert(ps);

	return ps->top;
}

void StackPrint(Stack* ps) {
	assert(ps);

	int i = ps->top-1;
	while (i >= 0) {
		printf("%d ", ps->arr[i]);
		i--;
	}
}