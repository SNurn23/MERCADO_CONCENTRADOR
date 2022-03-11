#include<stdio.h>
#include"funciones.c"
#include<stdlib.h>
main ()
{
int volver=1,bucle=1;
while(volver==1){
system("cls");
int opcion, opcion2, opcion3;
printf("\t\t\t-----------------------------------------------------------\n");
printf ("\t\t\t------------BIENVENIDO AL MERCADO CONCENTRADOR-------------\n");
printf("\t\t\t-----------------------------------------------------------\n");
printf("\t\t\t\t");  cantidadpuestxsector();
printf("\n");
printf ("Elija una opcion\n");
printf("\n");
printf ("1) Alquileres\n");
printf ("2) Puestos\n");
printf ("3) Contratos\n");
printf ("4) Medidores\n");
printf ("5) Salir\n");
printf("Opcion:\t");
scanf ("%d",&opcion);
system("cls");
 switch (opcion){
 	
 	case 1:
 		//  llama a la funcion alquileres
 		printf ("Elija una opcion \n");
 		printf ("1)Alquilar un puesto\n");
 		printf ("2) Buscar alquileres ingresando nombre del productor\n");
			printf("3) Buscar alquileres ingresando dos fechas\n");
 		scanf ("%d",&opcion2);
 		system("cls");
 		    switch (opcion2){
 		    
				  case 1:
				
				   	 alquilarpuesto();
 		    		break;
 		    			case 2:
 		    		buscarproductor();
				 				break;
				 				case 3:
				 				alquilerporfechas();
				 				break;
						}
	 break; 			
	case 2:
 		//  llama a la funcion puestos
 		printf ("Elija una opcion\n");
 		printf("\n");
 		printf ("1) Listar los puestos alquilados\n");
 		printf ("2) Listar los puestos segun el sector\n");
 		printf ("3) Listar los productores con mas de un puesto\n");
 		printf ("4) Mostrar puestos\n");
 		printf ("5)Mostrar los sectores con mayor porcentaje \n");
 		printf ("6) Ajustes\n");
 		scanf ("%d",&opcion2);
 		system("cls");
 		switch(opcion2){
 			case 1:
 				 puestosalquilados();
 				 break;
 				case 2:
				     puestoxsector();	
				    break;
 					case 3:
 					productorconmaspuestos();
 						 break;
 						case 4:		
 							 mostrarpuestos();
 						//	 system("pause");
 							 break;
 							 case 5:
 							 	porcentajexsector();
 							 	break;
 							 case 6:
 							 	 printf ("Elija una opcion\n");
 		                         printf("\n");
 							 	 printf("1)Agregar puesto\n");
 							     printf("2)Modificar puesto\n");
 							     printf("3)Eliminar puesto\n");
 							     scanf("%d",&opcion3);
 							     system("cls");
 							     switch(opcion3){
								    case 1:
 										 agregarpuesto();
 										 break;
											 case 2:
									     modificarpuesto();
									     break;
									        case 3:
 											   eliminarpuestos();
 											   break;
							                 }
							                 break;
		 }
		 break;
 	case 3:
 		//   llama a la funcion contratos
 		printf ("Elija una opcion\n");
 		printf("\n");
 		printf ("1)Mostrar los contratos de los alquileres\n");
 		printf ("2)Mostrar contrato especifico\n");
 		printf("3)Mostrar contratos dados de baja\n");
 		printf ("4)Ajustes\n");
 		scanf("%d",&opcion2);
 		system("cls");
 		switch(opcion2){
 			case 1:
 				 mostrarcontratos();
 				 break;
 				 case 2:
 				 	 mostrarcontratoespecifico();
 				 	 break;
 				 	 case 3:
 				 	 	contratoseliminados();
 				 	 	break;
 				 	 	case 4:
 				 	 		printf ("Elija una opcion\n");
 		                    printf("\n");
 				 	 		printf("1)Renovar contrato\n");
 				 	 		printf("2)Eliminar contrato\n");
 				 	 		scanf("%d",&opcion3);
 				 	 		system("cls");
 				 	 		switch(opcion3){
 				 	 			case 1:
 				 	 				renovarcontrato();
 				 	 				break;
 				 	 				case 2:
 				 	 					eliminarcontratos();
 				 	 					break;
										}
		 break;
		 }
		 break;
	case 4:
	 printf("Elija una opcion:\n");
	 printf("\n");	 
	 printf("1) Mostrar medidores\n");
	 scanf("%d",&opcion2);
	 system("cls");
	 switch(opcion2){
	 	case 1:
	 		mostrarmedidores();
	 		break;
	 }
	 break;
	 case 5:
	 	exit(1);
	 	break;
 	}
	system("pause");
}
}

