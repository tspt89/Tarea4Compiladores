#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct variable
{
	char* nombre;
	int tipo;
	union{
		int i;
		float f;
		bool b;
	};
	struct variable * next;
};

void printTableS(struct variable * table);
void printTable();
void checkIdRepeated(char * id);

struct variable *root = NULL;
struct variable *tmpList = NULL;

struct variable * insertId(char * nombre){
	checkIdRepeated(nombre);
	if(tmpList == NULL){
		//printf("TEMPORAL ES NULL\n");
		struct variable* tmp = calloc(1,sizeof(struct variable));
		//tmpList = (struct variable *) calloc(1,sizeof(struct variable));
		tmp->nombre = (char *) malloc(128 * sizeof(struct variable));
		strcpy(tmp->nombre,nombre);
		tmp->next = NULL;
		tmpList = tmp;
		//printf("PASA %s\n", tmp->nombre);
	} else {
		//printf("PASA ELSE\n");
		struct variable * newNode = (struct variable *) calloc(1,sizeof(struct variable));
		struct variable * tmp = tmpList;
		newNode->next = NULL;
		newNode->nombre = (char *) malloc(128 * sizeof(struct variable));
		strcpy(newNode->nombre,nombre);
		
		while (tmp->next != NULL)  
        	tmp = tmp->next;
		tmp->next = newNode;
	}

	//printTableS(tmpList);	
}

void setTipoTmpList(int tipo){

	struct variable* tmp = tmpList;
	while(tmp != NULL){
		//printf("TIPO de variable: {%d}\n",tipo );
		tmp->tipo = tipo;

		if(tipo == 0) tmp->i = 0;
		if(tipo == 1) tmp->i = 0.0f;
		if(tipo == 2) tmp->i = false;
		tmp = tmp->next;
	}
	
	if(root == NULL){
		//printf("ROOT IS NULL\n");
		root = tmpList;
		tmpList = NULL;
	} else {
		tmp = root;
		while(tmp->next != NULL){
			//printf("ROOT: %s\n",tmp->nombre);
			tmp = tmp->next;
			//printf("ROOT: %s\n",tmp->nombre);
		}	
		//printf("ROOT: %s\n",tmp->nombre);
		tmp->next = tmpList;
		tmp = tmp->next;
		//printf("ROOT: %s\n",tmp->nombre);
		tmpList = NULL;
	}
	

}

void checkId(char * id){
	struct variable * tmp = root;
	printf("ID A BUSCAR: %s\n", id);

	while((tmp->next != NULL) && (strcmp(id,tmp->nombre))){
		tmp = tmp->next;
	}

	if(strcmp(id,tmp->nombre) != 0){
		printf("ID: %s not found\n",id);
		printf("Tabla de simbolos: \n");
		printTable();
		exit(1);
	}
}

void checkIdRepeated(char * id){
	struct variable * tmp = root;
	printf("ID A BUSCAR: %s\n", id);

	if(tmp != NULL){
		while((tmp->next != NULL)){
			printf("COMPARE ROOT: %s %d\n",id, (strcmp(id,tmp->nombre)));

			if(strcmp(id,tmp->nombre) == 0){
			printf("ID: %s repeated\n",id);
			printf("Tabla de simbolos: \n");
			printTable();
			exit(1);
		}

			tmp = tmp->next;
		}

		
	} else {
		if(tmpList != NULL){
			tmp = tmpList;
			while((tmp->next != NULL)){
				printf("COMPARE TMP: %s %d\n", id,(strcmp(id,tmp->nombre)));

				if(strcmp(id,tmp->nombre) == 0){
					printf("ID: %s repeated\n",id);
					printf("Tabla de simbolos: \n");
					printTable();
					exit(1);
				}

				tmp = tmp->next;


			}

			
		}
	}
	
	


}


void printTableS(struct variable * table){
	struct variable * t = table;
	if(t == NULL){
		//printf("TABLE IS EMPTY !\n");
	} else {
		struct variable *tmp = tmpList;
		printf("%-10s %-10s %10s\n","Nombre","Tipo","Valor");
		while(tmp != NULL){
			printf("%-10s %-10d\n",tmp->nombre,tmp->tipo);
			tmp = tmp->next;
		}
	}
}

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
		//printf("%10s %10s %10s\n","Nombre","Tipo","Valor");
		while(tmp != NULL){
			if(tmp->tipo == 0){ strcpy(tipo, "int");  sprintf(valor,"%d",tmp->i); }
			if(tmp->tipo == 1){ strcpy(tipo, "real"); sprintf(valor,"%f",tmp->f); }
			if(tmp->tipo == 2){ strcpy(tipo, "bool"); strcpy(valor,(tmp->b) ? "true":"false");}
			printf("%10s %10s %10s\n",tmp->nombre,tipo,valor);
			tmp = tmp->next;
		}
	}

	printf("\033[1;0m");
}