//TABLA HASH CON LISTAS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<fstream>
#define tam 7

using namespace std;

struct nodo{//estructura nodo
	int datos;
	nodo* siguiente;
};

nodo* cadena[tam];//creamos la tabla hash

void inicio(){//inicializamos la tabla
	int i;
	for(i=0;i<tam;i++)
	cadena[i] = NULL;
}

void insertar(int valor){//insertar nuevo dato
	nodo* nuevonodo = (nodo *)malloc(sizeof(nodo));//creamos un nuevo nodo
	nuevonodo->datos = valor;
	nuevonodo->siguiente = NULL;
	
	int clave = valor % tam;//calculamos la clave
	
	if(cadena[clave] == NULL){//comprobamos si la cadena[clave] este vacia
		cadena[clave] = nuevonodo;
	}else{//si ocurre una colision
		nodo* temp = cadena[clave];
		while(temp->siguiente){
			temp = temp->siguiente;
		}
		temp->siguiente = nuevonodo;//se agrega el nodo al final de la cadena[clave]
	}
}

void ingresarDatos(){
	int valor;
	cout<<"\tIngrese un numero: ";
	cin>>valor;
	insertar(valor);
	cout<<endl;
	cout<<"\tDato ingresado "<<endl;
	cout<<endl;
	system("pause");
}

void impresion(){
	int i;
	for(i=0;i<tam;i++){
		nodo* temp = cadena[i];
		cout<<"cadena-> "<<"["<<i<<"]";
		while(temp){
			cout<<" -> "<<temp->datos;
			temp = temp->siguiente;
		}
		cout<<" NULL "<<endl;
	}
}

void ejecutarDot(){
	int respuesta = system("dot.exe -Tpng tablaHash.dot -o GraficaHash.png");
	if(respuesta == 0){
		system("D:\\elrober\\escritorio\\GraficaHash.png");
		cout<<"se a generado la grafica con exito"<<endl;
	}else{
		cout<<"Se a producido un error catastrofico.... borrar la carpeta 'system32' "<<endl;
	}

}

void escribirDot(){
	ofstream archivo;
	archivo.open("tablaHash.dot",ios::out);//abriendo archivo o creandolo
	archivo<<"digraph{"<<endl;
	archivo<<endl;
	int i;
	for(i=0;i<tam;i++){
		nodo* temp = cadena[i];
		archivo<<"cadena"<<i;
		while(temp!=NULL){
			archivo<<" -> "<<temp->datos;
			temp = temp->siguiente;
		}
		archivo<<endl;
	}
	archivo<<"}";
	archivo.close();
	ejecutarDot();
}


int main(){

	int opcion;
	bool bandera= false;
	
	do{
		system("cls");
		cout<<"\t\t MENU TABLA HASH"<<endl;
		cout<<"\t1.- Ingresar Datos"<<endl;
		cout<<"\t2.- Mostrar Datos"<<endl;
		cout<<"\t3.- Salir"<<endl;
		cin>>opcion;
		
		switch(opcion){
			
			case 1:
				ingresarDatos();
				break;
			case 2:
				impresion();
				escribirDot();
				break;
			case 3:
				bandera = true;
				break;
			default:
				cout<<"opcion no valido"<<endl;
				break;
		}
	}while(bandera !=true);
return 0;
}




