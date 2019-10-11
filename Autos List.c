#include <stdio.h>
#include <stdlib.h>
#define TAM 150

typedef struct{
char marca[30];
char tipo[30];
int anho;
int costo;
char color[30];
int nserie;
}TipoDato;

typedef struct
{
TipoDato pila[TAM];
int tope;
int tam;
}Pila;

typedef struct
{
TipoDato cola[TAM];
int inicio, final;
int tam;
}Cola;

void inicializaPila(Pila * p, int tam);
void inicializaCola(Cola * c, int tam);

int main(int argc, char *argv[]) {
	int accion,tam;
	int pnueva=0;
	int colanueva=0;
	char sino;
	Pila p;
	Cola c;
	TipoDato d;
	do{
		system("cls");
		printf(" QUE ES LO QUE DESEAS REALIZAR? \n\n   1.- CREAR NUEVA PILA\n   2.- INGRESAR AUTOMOVIL EN LA PILA\n   3.- EXTRAER AUTOMOVIL DE LA PILA \n   ------------ \n   4.- CREAR NUEVA COLA\n   5.- INGRESAR AUTOMOVIL A LA COLA\n   6.- EXTRAER AUTOMOVIL DE LA COLA\n   ------------ \n   7.- SALIR\n");
		scanf("%d",&accion);
		switch(accion)
	{
		case 1:
        	if(!pnueva)
			{
				printf("CUAL SERA EL TAMAÑO DE LA PILA. \n");
				scanf("%d",&tam);
            	inicializaPila(&p,tam);
            	pnueva++;
            	verificar(accion,1);
			}else{
				printf("YA EXISTE UNA PILA ACTUALMENTE.\n\n");
				printf("QUIERES ELIMINAR ESTA PILA?, SE PERDERA LA COLA ACTUAL. s/n\n");
				scanf("%s",&sino);
				if(sino=='s')
				{
					printf("CUAL SERA EL TAMAÑO DE LA PILA. \n");
					scanf("%d",&tam);
					inicializaPila(&p,tam);
	          		verificar(accion,1);
				}
			}
            break;
            case 4:
        	if(!colanueva)
			{
				printf("CUAL SERA EL TAMÑO DE LA COLA. \n");
				scanf("%d",&tam);
				inicializaCola(&c,tam);
				colanueva=1;
				verificar(accion,4);
			}else{
				printf("YA EXISTE UNA COLA ACTUALMENTE. \n\n");
				printf("QUIERES ELIMINAR ESTA COLA?, SE PERDERA LA COLA ACTUAL. s/n \n");
				scanf("%s",&sino);
				if(sino =='s')
				{
					inicializaPila(&p,tam);
	          		verificar(accion,4);
				}
			}
            break;
	}
	if(pnueva)
	{
			switch(accion)
    {

        case 2:
         	captura(&d);
			accion = push(&p,&d);
			verificar(accion,2);
            break;
        case 3:
			accion = pop(&p,&d);
			verificar(accion,3);
			if(accion)
			{
			printf("SE A PODIDO EXTRAER EL AUTOMOVIL:\n\n");
			imprimir(d);
			}
            break;
        case 7:
			printf("PRECIONE CUALQUIER TECLA PARA SALIR. \n");
            break;
		case 1:
		case 4:
		case 5:
		case 6:
			break;
        default:
            printf("¡¡ERROR!! EL NUMERO ES INVALIDO. \n");
		}
    }else{
    	if(accion == 2 || accion == 3)
    		printf("FALTA INICIAR LA PILA.\n\n");
    }
    if(colanueva)
    {
    	switch(accion)
    {
    	case 5:
        	captura(&d);
			accion = enqueue(&c,&d);
			verificar(accion,5);
            break;
        case 6:
			accion = dequeue(&c,&d);
			verificar(accion,6);
			if(accion)
			{
				printf("SE A PODIDO EXTRAER EL AUTOMOVIL:\n\n");
				imprimir(d);
			}
            break;
        case 1:
		case 4:
		case 2:
		case 3:
			break;
		case 7:
		printf("PRECIONE CUALQUIER TECLA PARA SALIR. \n");
        break;
		}
	}else{
		 if(accion == 5 || accion == 6)
    	 	printf("FALTA INICIAR LA COLA.\n\n");
    }
	delay();
	}while(accion!=7);
	return 0;
}
void delay()
{
	long double i,j,s;
	for(i=0;i<100000;i++)
	{
		for(j=0;j<10000;j++)
		{
			s=1;
		}
	}
}
void imprimir(TipoDato d)
{
	printf("  MARCA DEL AUTOMOVIL.%s\n",d.marca);
	printf("  TIPO DE AUTOMOVIL. %s\n",d.tipo);
	printf("  ANNO DEL AUTOMOVIL. %d\n",d.anho);
	printf("  COSTO DEL AUTOMOVIL. %d\n",d.costo);
	printf("  COLOR DEL AUTOMOVIL. %s\n",d.color);
	printf("  NUMERO DE SERIE DEL AUTOMOVIL. %d\n\n",d.nserie);
}

void verificar(int accion,int pico)
{
	if(accion==1)
	{
	printf("SU CAMBIO HA SIDO REALIZADO DE FORMA SATISFACTOREA. \n\n");
	}else{
		if(pico==2)
		printf("NO SE PUEDE REALIZAR ESTO, PILA LLENA.\n\n");
		if(pico==3)
		printf("LO SENTIMOS, NO SE PUEDE REALIZAR ESTO: PILA VACIA. \n\n");
		if(pico==5)
		printf("NO SE PUEDE REALIZAR ESTO, PILA LLENA. \n\n");
		if(pico==6)
		printf("LO SENTIMOS, NO SE PUEDE REALIZAR ESTO: PILA VACIA. \n\n");
	}
}

void captura(TipoDato*d)
{
	printf("MARCA DE EL AUTOMOVIL. \n");
	scanf("%s",d->marca);
	fflush(stdin);
	printf("CLASE DEL AUTOMOVIL. \n");
	scanf("%s",d->tipo);
	fflush(stdin);
	printf("ANNO DEL AUTOMOVIL. \n");
	scanf("%d",&d->anho);
	printf("COSTO DEL AUTOMOVIL. \n");
	scanf("%d",&d->costo);
	printf("COLOR DEL AUTOMOVIL. \n");
	scanf("%s",d->color);
	fflush(stdin);
	printf("NUMERO DEL AUTOMOVIL \n");
	scanf("%d",&d->nserie);
}

void inicializaPila(Pila * p, int tam)
{
p->tam = tam <= TAM? tam : TAM;
p->tope = 0;
}

int pilaVacia(Pila p)
{
int reg = 1;
if(p.tope > 0)
reg = 0;
return(reg);
}

int pilaLlena(Pila p)
{
int reg = 1;
if(p.tope < p.tam)
reg = 0;
return(reg);
}

int push(Pila * p, TipoDato d)
{
  int reg = 0;
	if( ! pilaLlena(*p) )
	{
	p->pila[p->tope] = d;
	p->tope++;
	reg = 1;
	}
  return(reg);
}

int pop(Pila * p, TipoDato *d)
{
int reg = 0;
	if( ! pilaVacia(*p))
	{
	p->tope--;
	*d = p->pila[p->tope];
	reg = 1;
	}
return(reg);
}

void inicializaCola(Cola * c, int tam)
{
c->tam = tam <= TAM? tam+1 : TAM;
c->inicio = c->final = 0;
}

int colaVacia(Cola c)
{
int reg;
reg = c.inicio == c.final ? 1 : 0;
return(reg);
}

int colaLlena(Cola c)
{
int reg;
reg = (c.final+1) % c.tam == c.inicio? 1:0;
return(reg);
}

int enqueue(Cola * c, TipoDato d)
{
int reg = 0;
if( ! colaLlena(*c) )
{
c->cola[c->final] = d;
c->final = (c->final + 1) % c->tam;
reg = 1;
}
return(reg);
}

int dequeue(Cola * c, TipoDato *d)
{
int reg = 0;
if( ! colaVacia(*c))
{
*d = c->cola[c->inicio];
c->inicio = (c->inicio + 1) % c->tam;
reg = 1;
}
return(reg);
}
