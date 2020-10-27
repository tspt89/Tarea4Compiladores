#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct variable
{
	char nombre[12];
	int tipo;
	union{
		int i;
		float f;
		bool b;
	};
	struct variable * next;
};

struct variable *root = NULL;

void insert(char * nombre, int t, void* b){
	struct variable * node;
	node = (struct variable *) malloc(sizeof(struct variable*));

	strcpy(node->nombre,nombre);
	node->tipo = t;
	node->next = NULL;

	if(root == NULL){
		root = node;
	} else {
		struct variable *tmp = root;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void insertValue(char * nombre, int i, float f, bool b){
	struct variable *tmp = root;

	while((tmp->next != NULL) && (strcmp(nombre,tmp->nombre))){
		tmp = tmp->next;
	}

	switch(tmp->tipo){
		case 0:	//0 para int
			tmp->i = i;
			break;
		case 1:	//1 para real
			tmp->f = f;
			break;
		case 2:	// 2 para bool
			tmp->b = b;
			break;
	}

}

void printTable(){
	char tipo[20],valor[10];
	if(root == NULL){
		printf("No hay ningun elemento en la tabla\n");
	} else {
		struct variable *tmp = root;
		printf("%10s %10s %10s\n","Nombre","Tipo","Valor");
		while(tmp->next){
			if(tmp->tipo == 0){ strcpy(tipo, "int");  sprintf(valor,"%d",tmp->i); }
			if(tmp->tipo == 1){ strcpy(tipo, "real"); sprintf(valor,"%f",tmp->f); }
			if(tmp->tipo == 2){ strcpy(tipo, "bool"); strcpy(valor,(tmp->b) ? "true":"false");}
			printf("%10s %10s %10s\n",tmp->nombre,tipo,valor);
			tmp = tmp->next;
		}
	}
}