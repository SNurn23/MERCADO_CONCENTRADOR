 //Estructuras usadas en el trabajo
struct medidores{
	int lecturamedidor;
	int nropuesto;
}m;

 struct puestos{
	char sector[60];
	char tipo[60];
	int dimension;
	int dispon;
	long int precio;
	int id;
	int medidor;
}p;

struct fecha{
	int dia;
	int mes;
	int ano;
}f;

struct cliente{
	char nombre[40];
	long int dni;
	int idcliente;
	int contpuestos;
}c;

 struct contratos{
 struct cliente client;
	char responsablefirma [40];
	char responsableregistro [40];
	int id;
	long int precio;
	struct fecha fechainicio;
	struct fecha fechafin;
	int idpuesto;
	int medidorpuest;
}w;



