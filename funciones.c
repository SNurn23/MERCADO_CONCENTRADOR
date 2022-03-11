//Funcion Alquileres
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include "estructuras.c"
//VARIABLES DEL CONTADOR DE SECTORES
int frut=0, var=0, preel=0, cult=0, carni=0, resultado;
int pre=0,car=0,fruti=0,vari=0,culti=0,dpre=0,dcar=0,dfru=0,dvar=0,dcult=0;

void alquilerporfechas(){
	FILE *arch;
	struct fecha buscar;
	int diain,mesin,anioin,diafin,mesfin,aniofin,bandera=0;
	long int inicio,fin,cuentasin,cuentasfin;
	struct contratos contrat;
	arch=fopen("contratos.b","rb");
	if(arch!=NULL){
		printf("Ingrese la fecha de inicio del contrato\n");
       printf("Dia: ");
       scanf("%d",&diain);
       if(diain<=31){
       	diain;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Mes: ");
       scanf("%d",&mesin);
       if(mesin<=12){
       	mesin;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Anio: ");
       scanf("%d",&anioin);
       if(anioin>=2006){
       anioin;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Ingrese la fecha de fin del contrato\n");
       printf("Dia: ");
       scanf("%d",&diafin);
       if(diafin<=31){
       	diafin;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Mes: ");
       scanf("%d",&mesfin);
       if(mesfin<=12){
      	mesfin;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Anio: ");
       scanf("%d",&aniofin);
       inicio=(anioin*10000+mesin*100+diain);
	   fin=(aniofin*10000+mesfin*100+diafin);
	   fread(&contrat,sizeof(contrat),1,arch);
	   while(!feof(arch)){
			cuentasin=(contrat.fechainicio.ano*10000+contrat.fechainicio.mes*100+contrat.fechainicio.dia);
			cuentasfin=(contrat.fechafin.ano*10000+contrat.fechafin.mes*100+contrat.fechafin.dia);
			
			if((cuentasin>=inicio)&&(cuentasfin<=fin)){
				printf("Nombre del cliente: %s\n",contrat.client.nombre);
				printf("DNI del cliente: %ld\n",contrat.client.dni);
				printf("El id del cliente:%d\n",contrat.client.idcliente);
				printf("Cantidad de puestos alquilados: %d\n",contrat.client.contpuestos);
				printf("Responsable de la firma:%s\n",contrat.responsablefirma);
				printf("Responsable del registro:%s\n",contrat.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contrat.fechainicio.dia,contrat.fechainicio.mes,contrat.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contrat.fechafin.dia,contrat.fechafin.mes,contrat.fechafin.ano);
			    printf("el ID del puesto: %d\n",contrat.idpuesto);
				printf("Monto mensual:$%ld\n",contrat.precio);
			    printf("ID del contrato: %d\n\n\n",contrat.id);
				bandera=1;
			}
				fread(&contrat,sizeof(contrat),1,arch);
		}
		
		if(bandera==0){
			printf("********************************************************\n");
			printf("No se encontraron contratos entre las fechas ingresadas\n");
			printf("********************************************************\n");
		}
		fclose(arch);
	}
}

void porcentajexsector()
{
	FILE *arch;
	struct puestos puest;
	int aux=100;
    float p=0,carnic=0,frh=0,vr=0,cul=0;
	char sector1[]="preelaborados";
	char sector2[]="carnicos";
	char sector3[]="frutihorticola";
	char sector4[]="varios";
	char sector5[]="actividades";
	arch=fopen("puestos.b","rb");
	if(arch!=NULL){
		fread (&puest,sizeof(puest),1,arch);
		while (!feof(arch)){
			if(strcmp(puest.sector,sector1)==0){
			 if(puest.dispon==1){
			 	pre++;       
				}
			}
			if(strcmp(puest.sector,sector2)==0){
				if(puest.dispon==1){
					car++;
				}
			}
			if(strcmp(puest.sector,sector3)==0){
				if(puest.dispon==1){
					fruti++;
				}
			}
			if(strcmp(puest.sector,sector4)==0){
				if(puest.dispon==1){
					vari++;
				}
			}
			if(strcmp(puest.sector,sector5)==0){
				if(puest.dispon==1){
					culti++;
				}
			}
			//aca termina contar los que estan disponibles
			if(strcmp(puest.sector,sector1)==0){
			 if(puest.dispon==2){
			 	dpre++;                 
				}
			}
			if(strcmp(puest.sector,sector2)==0){
				if(puest.dispon==2){
					dcar++;
				}
			}
			if(strcmp(puest.sector,sector3)==0){
				if(puest.dispon==2){
					dfru++;
				}
			}
			if(strcmp(puest.sector,sector4)==0){
				if(puest.dispon==2){
					dvar++;
				}
			}
			if(strcmp(puest.sector,sector5)==0){
				if(puest.dispon==2){
					dcult++;
				}
			}
			//aca termina de contar los que no estan disponibles
			fread(&puest,sizeof(puest),1,arch);
		}
	}
	fclose(arch);
	pre=pre+dpre;
	car=car+dcar;
	fruti=fruti+dfru;
	vari=vari+dvar;
	culti=culti+dcult;
	p=(dpre * aux);
	p=(p/pre);   
	carnic=(dcar*aux);
	carnic=(carnic/car);
	frh=(dfru*aux);       
	frh=(frh/fruti);
	if(isnan(frh / 0.0) ){    //el if comprueba que sea un numero y le asigna un 0
	frh=0;
}
	vr=(dvar*aux);
	vr=(vr/vari);
	cul=(dcult*aux);
	cul=(cul/culti);
	fflush(stdin);
		if(isnan(vr / 0.0) ){    //el if comprueba que sea un numero y le asigna un 0
	vr=0;
}
	if(isnan(cul / 0.0) ){    //el if comprueba que sea un numero y le asigna un 0
	cul=0;
}
	if(isnan(carnic / 0.0) ){    //el if comprueba que sea un numero y le asigna un 0
	carnic=0;
}
	if(isnan(p / 0.0) ){    //el if comprueba que sea un numero y le asigna un 0
	p=0;
}
	if((frh==0)&&(p==0)&&(cul==0)&&(carnic==0)&&(vr==0)){
		printf("\nFaltan cargar puestos\n");
	}
	if((frh==p)&&(frh==vr)&&(frh==cul)&&(frh==carnic)&&(p==vr)&&(p==cul)&&(p==carnic)&&(vr==cul)&&(vr==carnic)&&(cul==carnic)){
		printf("\nTodos los sectores tienen el mismo porcentaje\n");
	}
	if((p==carnic)&&(carnic==frh)&&(frh==vr)&&(vr>cul)){
		printf("Preelaborados, carnicos, frutihorticolas y varios tienen el mismo porcentaje\n");
	}else{ 
		if((p==carnic)&&(carnic==frh)&&(frh==cul)&&(cul>vr)){
			printf("Preelaborados, carnicos, frutihorticolas y actividades tienen el mismo porcentaje\n");    // if((carnic==cul)&&(carnic==vr)&&(carnic==frh)&&(carnic>p)){
		}else{ 	
			if((carnic==cul)&&(carnic==vr)&&(carnic==frh)&&(carnic>p)){																								
				printf("Carnicos, actividades, varios y frutihorticolas tienen el mismo porcentaje\n");
			}else{
				if((p==carnic)&&(p==cul)&&(p==vr)&&(p>frh)){
					printf("Preelaborados, carnicos, actividades y varios tienen el mismo porcentaje\n");
				}else{
					if((p==cul)&&(p==vr)&&(p>frh)&&(p>carnic)){                                                       //ACA EMPIEZA
						printf("Preelaborados, actividades y varios tienen el mismo porcentaje\n");	
					}else{
						if((p==frh)&&(p==vr)&&(p>carnic)&&(p>cul)){
							printf("Preelaborados, frutihorticolas y varios tienen el mismo porcentaje\n");
						}else{
							if((p==cul)&&(p=frh)&&(p>carnic)&&(p>vr)){
								printf("Preelaborados, actividades y frutihorticolas tienen el mismo porcentaje\n");
							}else{
								if((p==carnic)&&(p==cul)&&(p>vr)&&(p>frh)){
									printf("Preelaborados, carnicos y actividades tienen el mismo porcentaje\n");
								}else{
									if((p==carnic)&&(p==frh)&&(p>cul)&&(p>vr)){
										printf("Preelaborados, cranicos y frutihorticolas tienen el mismo porcentaje\n");
									}else{
										if((p==carnic)&&(p==vr)&&(p>cul)&&(p>frh)){
											printf("Preelaborados, cranicos y varios tienen el mismo porcentaje\n");
										}else{
											if((carnic==vr)&&(carnic==frh)&&(carnic>p)&&(carnic>cul)){
												printf("Carnicos, varios y frutihorticolas tienen el mismo porcentaje\n");
											}else{
												if((carnic==vr)&&(carnic==cul)&&(carnic>p)&&(carnic>frh)){
															printf ("Carnicos varios y actividades tienen el mismo porcentaje\n");
													}else{
														if((carnic==frh)&&(carnic==cul)&&(carnic>p)&&(carnic>vr)){
															printf("Carnicos, frutihorticolas y actividades tienen el mismo porcentaje\n");
														}else{
															if((vr==frh)&&(vr==cul)&&(vr>p)&&(vr>carnic)){
																printf("Varios, frutihorticolas y actividades tienen el mismo porcentaje\n");	
															}else{
																if((p==vr)&&(p>cul)&&(p>carnic)&&(p>frh)){
																	printf("Preelaborados y varios tienen el mismo porcentaje\n");
																}else{
																	if((p==cul)&&(p>vr)&&(p>carnic)&&(p>frh)){
																		printf("Preelaborados y actividades tienen el mismo porcentaje\n");
																	}else{
																		if((p==carnic)&&(p>cul)&&(p>vr)&&(p>frh)){
																			printf("Preelaborados y carnicos tienen el mismo porcentaje");
																		}else{
																			if((p==frh)&&(p>cul)&&(p>carnic)&&(p>vr)){
																				printf("Preelaborados y frutihorticolas tienen el mismo porcentaje\n");
																			}else{
																				if((vr==cul)&&(vr>p)&&(vr>carnic)&&(vr>frh)){
																					printf("Varios y actividades tienen el mismo porcentaje\n");
																				}else{
																					if((vr==carnic)&&(vr>p)&&(vr>cul)&&(p>frh)){
																						printf("Varios y carnicos tienen el mismo porcentaje\n");
																					}else{
																						if((vr==frh)&&(vr>p)&&(vr>cul)&&(vr>carnic)){
																							printf("Varios y frutihorticolas tienen el mismo porcentaje\n");
																						}else{
																							if((cul==carnic)&&(cul>frh)&&(cul>p)&&(cul>vr)){
																								printf("actividades y carnicos tienen el mismo porcentaje\n");
																							}else{
																								if((cul==frh)&&(cul>p)&&(cul>carnic)&&(cul>vr)){
																									printf("actividades y frutihorticolas tienen el mismo porcentaje\n");
																								}else{
																									if((carnic==frh)&&(carni>p)&&(carnic>vr)&&(carnic>cul)){
																										printf("Carnicos y frutihorticolas tienen el mismo porcentaje\n");
																										}else{
																											if((p>carnic)&&(p>frh)&&(p>vr)&&(p>cul)){
																												printf ("\nPreelaborados es el sector de mayor porcentaje\n");
																											}else{
																												if((carnic>frh)&&(carnic>vr)&&(carnic>cul)){
																													printf ("Carnicos es el sector de mayor porcentaje\n");
																												}else{
																													if((frh>vr)&&(frh>cul)){
																														//f es el de mayor porcentaje
																														printf ("Frutihorticolas es el sector de mayor porcentaje\n");
																													}else{
																														if(vr>cul){
																															//V es el de mayor porcentaje
																															printf("Varios es el sector de mayor porcentaje\n");
																														}else{
																															if(cul>vr){
																																printf("actividades es el sector de mayor porcentaje\n");
																																//cul es el de mayor porcentaje
																														}
																													}
																												}
																											}
																										}
																									}	
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
}

void agregarpuesto(){ // funcion que agrega puestos
 long int cont=0;
 FILE *puntero;
 struct puestos puest;
 int cargar,seguircargando;
 printf ("Desea agregar un puesto?: (1)SI (0)NO\n");
 scanf ("%d",&seguircargando);
	while (seguircargando==1){
	puntero = fopen ("puestos.b","ab");
	if (puntero!=NULL){
		printf ("Ingrese el sector que corresponda \n");
		getchar ();
		gets (puest.sector);
		printf("Ingrese el tipo de puesto \n");
		gets (puest.tipo);
		printf ("Ingrese la dimension del puesto \n");
		scanf ("%d",&puest.dimension);
		printf ("Ingrese el precio del puesto \n");
		scanf ("%ld",&puest.precio);
	puest.dispon=1;
	puest.medidor=0;
	puest.id=cargarid();
	fwrite(&puest,sizeof(puest),1,puntero);
	fclose (puntero);
}else {
	printf ("No funciona");
}
printf ("Desea seguir cargando datos?: (1)SI o (2)NO\n");
scanf ("%d",&seguircargando);
}
}
void mostrarpuestos()
{
	FILE *puntero;
	struct puestos p;
	puntero = fopen ("puestos.b","rb");
if (puntero!=NULL){
	fread (&p,sizeof(p),1,puntero);
	while (!feof(puntero)){
		if(p.id!=0){
		printf ("El sector es %s\n",p.sector);
		printf ("El tipo es %s\n",p.tipo);
		printf ("La dimension es de %dm2\n",p.dimension);
		printf ("El precio del puesto es de $%ld \n",p.precio);
		printf ("La disponibilidad es %d\n",p.dispon);
		printf ("El id del puesto es %d\n",p.id);
		printf("El medidor del puesto esta en: %d \n\n\n",p.medidor);
	}
	fread (&p,sizeof(p),1,puntero);
}
	fclose (puntero);
}else
printf ("No funciona");
}


void puestoxsector(){
	FILE *puntero;
	struct puestos puest;
	char sector[60];
	printf("Ingrese el sector\n");
	getchar();
   	     gets(sector);
   	     	system("cls");
	puntero=fopen("puestos.b","rb");
	if(puntero!=NULL){
		fread(&puest,sizeof(puest),1,puntero);
		while(!feof(puntero)){
			if(strcmp(puest.sector,sector)==0){
			 
				printf("Sector: %s\n",puest.sector);
				printf("Tipo de puesto: %s\n",puest.tipo);
				printf("Dimension: %dm2\n",puest.dimension);
				printf("Disponibilidad: %d\n",puest.dispon);
				printf("Precio: $%ld\n",puest.precio);
				printf("El ID del puesto es: %d\n\n\n",puest.id);
				printf("\n");
			}
			fread(&puest,sizeof(puest),1,puntero);
		}
		fclose(puntero);
	}
}
	void mostrarmedidores(){
	FILE *arch;
	struct medidores medidor;
	arch=fopen("medidores.b","rb");
	if(arch!=NULL){
		fread(&medidor,sizeof(medidor),1,arch);
		while(!feof(arch)){
			printf("El id de puesto es %d\n",medidor.nropuesto);
			printf("La ultima lectura del medidor es de %d\n\n",medidor.lecturamedidor);
			fread (&medidor,sizeof(medidor),1,arch);
		}
		fclose(arch);
	}
	}
	
	
int cargarid()
{
	FILE *puntero;
	struct puestos puest;
	int id=0;
	
	puntero = fopen ("puestos.b","rb");
	if (puntero!=NULL){
			fread (&puest,sizeof(puest),1,puntero);
			while (!feof(puntero)){
 				id = puest.id;
 				fread (&puest,sizeof(puest),1,puntero);
			}
			id++;
			printf ("El id del puesto es:%d\n",id);
			fclose (puntero);
	}
	return (id);
}

int cargaridcliente()
{
	FILE *puntero;
	struct contratos contrat;
	int id=0;
	
	puntero = fopen ("contratos.b","rb");
	if (puntero!=NULL){
			fread (&contrat,sizeof(contrat),1,puntero);
			while (!feof(puntero)){
 				id = contrat.client.idcliente;
 				fread (&contrat,sizeof(contrat),1,puntero);
			}
			id++;
			printf ("El id del cliente es:%d\n",id);
			fclose (puntero);
	}
	return (id);
}
int cargaridcontrato()
{
	FILE *arch;
	int idc=0;
	struct contratos contra;
	arch = fopen ("contratos.b","rb");
	if (arch!=NULL){
			fread(&contra,sizeof(contra),1,arch);
			while (!feof(arch)){
 				idc = contra.id;
 				fread(&contra,sizeof(contra),1,arch);
			}
			idc=idc+1;
			printf ("El id del contrato es:%d\n",idc);
			fclose (arch);
	}
	return (idc);
}
//el id del contrato tira 0
int buscarid(long int dni){//devuelve -1 en el segundo contrato
 	FILE * arch;
 	struct contratos contrat;
 	int idcli;
 	arch=fopen("contratos.b","rb");
 	if(arch!=NULL){
 			fread (&contrat,sizeof(contrat),1,arch);
 		while (!feof(arch)){
 			if(contrat.client.dni==dni){
 				idcli=contrat.client.idcliente;
 				fseek(arch,sizeof(contrat),SEEK_END);
			 }
			 
 			fread (&contrat,sizeof(contrat),1,arch);
		 }
		 	 fclose(arch);		 	 
}

	 return(idcli);
 }
modificarmedidores(int puest, int medidores){
	FILE *punteromedidor;
	puest++;
	struct medidores medid;
		punteromedidor=fopen("medidores.b","a+b");
	 if(punteromedidor!=NULL){
 	medid.lecturamedidor=medidores;
 	medid.nropuesto=puest;
 	fwrite(&medid,sizeof(medid),1,punteromedidor);
 	fclose (punteromedidor);
	}else{
		printf("No se pudo abrir el archivo medidores\n");
	}
}

//funcion que modifica la disponibilidad de los puestos alquilados
void modificar(int puest, int medidores){
	FILE *puntero;
	int i=-1;
	puest--;
	struct puestos ps;
	puntero = fopen ("puestos.b","r+b");
	if (puntero!=NULL){
	fseek (puntero,( puest)*sizeof (ps),SEEK_SET);
	fread (&ps,sizeof(ps),1,puntero);
	ps.dispon=2;
	ps.medidor=medidores;
	fseek (puntero,sizeof(ps)*i,SEEK_CUR);
	fwrite(&ps,sizeof(ps),1,puntero);
	fclose (puntero);
	modificarmedidores(puest , medidores);
}else
printf ("No funciona");
}

int incrementarcont(int idcli){
    //Creacion de variable temporales
    FILE *arch;         											
    struct contratos contrat;
  int cont=1,aux=(-1);
    //apertura de archivo
    arch=fopen("contratos.b","r+b"); 
    if(arch!=NULL){//if de comprobacion de apertura 								
        fread(&contrat,sizeof(contrat),1,arch);
        while(!feof(arch)){//while de recorrido de archivo
            if(contrat.client.idcliente==idcli){
                cont++;// este contador representa la cantidad de puestos que posee un cliente
            }//fin if
            fread(&contrat,sizeof(contrat),1,arch);
        }//fin while
        fclose(arch);
       }
       return(cont);
    }

//FUNCION QUE CREA CONTRATOS
void crearcontrato(int puesto, long int precio){
	FILE *puntero;
	FILE *arch;
	FILE *punteromedidor;
	int opcion,clienteid,medidor,idcontrato,dia,mes,anio,nromedid, nropues;
	int idcli,cont=1;
	long int dni;
	char nombrecontrato[40];
	struct medidores medid;
	struct contratos contrat;
	struct puestos puest;
	punteromedidor=fopen("medidores.b","ab");
	if(punteromedidor!=NULL){
		fread(&medid,sizeof(medid),1,punteromedidor);
		puntero = fopen ("contratos.b","ab");
		if (puntero!=NULL){
			printf ("Ingrese el nombre del cliente\n");
			getchar();
			gets (contrat.client.nombre);
			printf ("Ingrese el dni del cliente\n");
			scanf ("%ld",&contrat.client.dni);
			dni=contrat.client.dni;
			//Hay que ver si el cliente ya existia
			printf("Alquilo un puesto anteriormente? 1)SI 2)NO \n");
			int c;
			scanf("%d",&c);
			if(c==2){
				contrat.client.idcliente=cargaridcliente();
				contrat.client.contpuestos=cont;
				printf("El contador de puestos es: %d\n",contrat.client.contpuestos);
			}else{
			  contrat.client.idcliente=buscarid(dni);
			  clienteid=contrat.client.idcliente;
			  contrat.client.contpuestos=incrementarcont(clienteid);
			  printf("El contador es :%d\n",contrat.client.contpuestos);
	     	}
			printf ("Ingrese el nombre del responsable de firma\n");
			fflush(stdin);
			gets (contrat.responsablefirma);
			printf ("Ingrese el responsable del registro\n");
			gets (contrat.responsableregistro);
	       printf("Ingrese la fecha de inicio del contrato\n");
	       printf("Dia: ");
	       scanf("%d",&dia);
	       if(dia<=31){
	       	contrat.fechainicio.dia=dia;
		   }else{
		   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
		   	exit (1);
		   }
	       printf("Mes: ");
	       scanf("%d",&mes);
	       if(mes<=12){
	       	 contrat.fechainicio.mes=mes;
		   }else{
		     printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
		   	 exit (1);
		   }
       printf("Anio: ");
       scanf("%d",&anio);
       if(anio>=2006){
       	contrat.fechainicio.ano=anio;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Ingrese la fecha de fin del contrato\n");
       printf("Dia: ");
       scanf("%d",&dia);
       if(dia<=31){
       	contrat.fechafin.dia=dia;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Mes: ");
       scanf("%d",&mes);
       if(mes<=12){
       	contrat.fechafin.mes=mes;
	   }else{
	   	printf("La fecha ingresada no es correcta, ingrese nuevamente\n");
	   	exit (1);
	   }
       printf("Anio: ");
       scanf("%d",&contrat.fechafin.ano);
       if(contrat.medidorpuest<0){
     		printf("El medidor se encuentra en 0\n");
							}else{
       printf("El medidor anterior se encuentra en %d\n",contrat.medidorpuest);
       }
       printf("Ingrese el medidor mayor al anterior \n");
       scanf ("%d",&medidor);
       if(medidor>contrat.medidorpuest){
       	contrat.medidorpuest=medidor;
			}else{
			printf("Ingrese un medidor mayor al anterior\n");
			exit(1);
			}
       nromedid=contrat.medidorpuest;
       nropues=contrat.idpuesto;
       contrat.idpuesto=puesto;
       contrat.precio=precio;
       contrat.id=cargaridcontrato();
     //  medidor=contrat.medidorpuest;
 fwrite(&contrat,sizeof(contrat),1,puntero);
 idcontrato=contrat.id;
 modificar(puesto , medidor);
 punteromedidor=fopen("medidores.b","a+b");
 // hACER UN TXT POR CONTRATO. INGRESAR POR TECLADO EL NOMBRE QUE SE LE VA A DAR AL TXT POR EJ NUM DE PUESTO Y FECHAS Y GUARDARLA EN UNA VARIABLE
 printf("Ingrese el nombre del contrato\n");
 fflush(stdin);
 gets(nombrecontrato);
 strcat(nombrecontrato,".txt");
 arch=fopen(nombrecontrato,"at");
 if(arch!=NULL){
 	fputs(" \t \t \t ************CONTRATO DE ALQUILER DEL MERCADO CONCENTRADOR*************\n",arch);
 	 fprintf(arch,"\n");
			 fprintf(arch,"N° DE CONTRATO: %d\n",contrat.id);
			  fprintf(arch,"\n");
			 fprintf(arch,"Consta por el presente documento ");
			 fprintf(arch,"los dias %d del mes %d del año %d ",contrat.fechainicio.dia,contrat.fechainicio.mes,contrat.fechainicio.ano);
			 fprintf(arch,"el contrato de alquiler de un puesto en el mercado concentrador  ");
			 fputs("al Señor/a........",arch);
			 fputs(contrat.client.nombre,arch);
			 fprintf(arch,"......con DNI:%ld con ID:%d  que alquila el Puesto n° %d. \n",contrat.client.dni,contrat.client.idcliente,contrat.idpuesto);
			  fprintf(arch,"\n");
			 fprintf(arch,"El precio del alquiler sera de $%ld mensuales.",contrat.precio);
			  fprintf(arch,"\n");
			   fprintf(arch,"\n");
			 fprintf(arch,"  \t \t INTERVIENEN \n");
			  fprintf(arch,"\n");
			 fputs("El señor/a.....",arch);
			 fputs(contrat.responsablefirma,arch);
			 fputs(".....como responsable por parte del Mercado Concentrador y el Señor/a .......",arch);
			 fputs(contrat.responsableregistro,arch);
			 fputs("......Responsable de la registracion del alquiler.\n",arch);
			  fprintf(arch,"\n");
			 fputs("Se reconocen los reunidos con la capacidad civil necesaria para contratar y obligarse y, en especial, para otorgar ",arch);
			 fputs(" el presente CONTRATO DE ALQUILER DE PUESTO y a tal efecto, actuando ambos en su propio nombre y derecho,",arch);
			 fputs(" siendo responsables de la veracidad de sus manifestaciones, De mutuo acuerdo.",arch);
			  fprintf(arch,"\n");
			   fprintf(arch,"\n");
			 fprintf(arch,"Dicho contrato consta de una fecha de caducidad despues de los dias %d del mes %d del año %d.",contrat.fechafin.dia,contrat.fechafin.mes,contrat.fechafin.ano);
			 fprintf(arch,"\n");
			  fprintf(arch,"\n");
			   fprintf(arch,"\n");
			    fprintf(arch,"\n");
			 fputs("Firma el inquilino .....................",arch);
			 fprintf(arch,"\n");
			 fputs("Firma el responsable por parte del MC .......................",arch);
			 fprintf(arch,"\n");
			 fputs("Firma el responsable de la registracion ......................",arch);
			 fclose(arch);
 }
 fclose (puntero);

 printf ("El contrato se creo con exito!!!!!!!!!!!!!!!\n");
}	else{
	printf ("No se creo el archivo\n");
}
fclose(punteromedidor);
}
}


void alquilarpuesto(){ //funcion que muestra los puestos disponibles segun sector
	FILE *puntero;
	struct puestos p;
	int	idalq;
	long int precio;
	char sector[60];
//	int result;
int band=0;
printf("Ingrese el sector del puesto que desea alquilar\n");
getchar();
gets(sector);
	puntero = fopen ("puestos.b","rb");
if (puntero!=NULL){
	fread (&p,sizeof(p),1,puntero);
	printf ("\t\t\t\t\t***PUESTOS DISPONIBLES***\n\n");
	while (!feof(puntero)){
		if(strcmp(p.sector,sector)==0){
		if(p.dispon==1){
			band=1;
		printf ("El sector es %s\n",p.sector);
		printf ("El tipo es %s\n",p.tipo);
		printf ("La dimension es de %dm2\n",p.dimension);
		printf ("El precio del puesto es de $%ld \n",p.precio);
		printf ("El id del puesto es %d\n",p.id);
		printf("\n");
	}
}
fread (&p,sizeof(p),1,puntero);
}
if(band==0){
printf("No hay puestos disponibles del sector ingresado\n");
}else{

int op;
	printf("Desea alquilar un puesto? (1)SI  (0)NO \n");
	scanf("%d",&op);
	if(op==1){
		printf("Ingrese el ID del puesto a alquilar\n");
		scanf("%d",&idalq);
		fseek(puntero,(idalq)*sizeof(p),SEEK_SET);
	fread(&p,sizeof(p),1,puntero);
	precio=p.precio;
		crearcontrato(idalq ,precio);
	//result=contsector(sector);
/*	printf("\n");
	printf("el result es %d",result);
*/
	}
	fclose (puntero);
}
}
else{
printf ("No funciona");
}
}


void puestosalquilados()
{

 FILE *puntero;
	struct puestos ps;
	puntero = fopen ("puestos.b","rb");
if (puntero!=NULL){
	fread (&ps,sizeof(ps),1,puntero);
	while (!feof(puntero)){
		if(ps.dispon==2){
		printf ("El sector es %s\n",ps.sector);
		printf ("El tipo es %s\n",ps.tipo);
		printf ("La dimension es de %dm2\n",ps.dimension);
		printf ("El precio del puesto es de $%ld\n",ps.precio);
		printf ("El id del puesto es %d\n",ps.id);
		printf("\n");
     }
     fread (&ps,sizeof(ps),1,puntero);
    } 
	fclose(puntero); 
}else{
	printf("No se abrio el archivo correctamente");
}
}

void buscarproductor(){     //funcion que busca a un productor en el registro alquileres por el nombre
	char nombre[40];                 
	long int dni;
	FILE *puntero;
	struct contratos contr;
	int band=0;
	printf ("\nIngrese el nombre del cliente\n");
	getchar();
	gets (nombre);
	printf ("Ingrese el dni del cliente\n");
	scanf ("%ld",&dni);
	puntero=fopen("contratos.b","rb");
	if(puntero!=NULL){
		fread (&contr,sizeof(contr),1,puntero);
		while(!feof(puntero)){
			if(strcmp(nombre,contr.client.nombre)==0){ 
				if(contr.client.dni==dni){
				if(contr.id!=0){
					band=1;
				printf("Nombre del cliente: %s\n",contr.client.nombre);
				printf("DNI del cliente: %ld\n",contr.client.dni);
				printf("El id del cliente:%d\n",contr.client.idcliente);
		//		printf("Cantidad de puestos alquilados: %d\n",contr.client.contpuestos);
				printf("Responsable de la firma:%s\n",contr.responsablefirma);
				printf("Responsable del registro:%s\n",contr.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contr.fechainicio.dia,contr.fechainicio.mes,contr.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contr.fechafin.dia,contr.fechafin.mes,contr.fechafin.ano);
				printf("el ID del puesto: %d\n",contr.idpuesto);
				printf("Monto mensual:$%ld\n",contr.precio);
				printf("El medidor del contrato esta en: %d\n",contr.medidorpuest);
				printf("ID del contrato: %d\n\n\n",contr.id);
	       	}
	       }
			}
			fread (&contr,sizeof(contr),1,puntero);
		}
		if(band==0){
			printf("No se encontro el cliente\n");
		}
		fclose(puntero);
	}else{
		printf("no se abrio el archivo correctamente\n");
	}
	
}


void cantidadpuestxsector(){
	frut=0, var=0, preel=0, cult=0, carni=0;
		FILE *puntero;
		struct puestos puests;
		char sector1[]="frutihorticola";
		char sector2[]="preelaborados";
		char sector3[]="varios";
		char sector4[]="carnicos";
		char sector5[]="cultura";
		puntero=fopen("puestos.b","rb");
		if(puntero!=NULL){
			fread(&puests,sizeof(puests),1,puntero);
			while(!feof(puntero)){
				if(puests.dispon==2){
					if(strcmp(puests.sector,sector1)==0){
						frut++;
					}else{
						if(strcmp(puests.sector,sector2)==0){
						preel++;
					}else{
						if(strcmp(puests.sector,sector3)==0){	
						var++;
					}else{
						if(strcmp(puests.sector,sector4)==0){
						carni++;
					}else{
						if(strcmp(puests.sector,sector5)==0){
						cult++;
					}
				}
			}
		}
	}
}
fread(&puests,sizeof(puests),1,puntero);
}

fclose(puntero);

if( (frut==0) && (preel==0) && (var==0) && (carni==0) && (cult==0)){
	      printf("No hay ningun puesto alquilado\n");
}else{
	if((frut>preel) && (frut>var) && (frut>carni) && (frut>cult)){
	printf("El sector con mayor puestos es: FRUTIHORTICOLA\n");
}else{
	if((preel>frut) && (preel>var) && (preel>carni) && (preel>cult)){
		printf("El sector con mayor puestos es: PRE-ELABORADOS\n");
	}else{
		if((var>frut) && (var>preel) && (var>carni) && (var>cult)){
			 printf("El sector con mayor puestos es: VARIOS\n");
		}else{
			if((carni>frut) && (carni>preel) && (carni>var) && (carni>cult)){
				printf("El sector con mayor puestos es: CARNICOS\n");
			}else{
			  if((cult>frut) && (cult>preel) && (cult>var) && (cult>carni)){
			  	  printf("El sector con mayor puestos es: CULTURA\n");		  
}else{
	if( (frut==preel)&&(frut==var)&&(frut==cult)&&(frut==carni)&&(preel==var)&&(preel==cult)&&(preel==carni)&&(var==cult)&&(var==carni)&&(cult==carni)){
      printf("TODOS LOS SECTORES TIENEN LA MISMA CANTIDAD DE PUESTOS\n");
    }else{
    		if((frut==preel) && (preel==var) && (var==cult) && (frut>carni) ){//con uno que sea mayor a carni
			  		  printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, PRE-ELABORADOS, VARIOS Y CULTURA\n");
				  }else{
				  	if((frut==preel) && (preel==var) && (var==carni) &&  (frut>cult) ){
			  		  printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, PRE-ELABORADOS, VARIOS Y CARNICOS\n");
				  }else{
				  	if((frut==preel) && (preel==carni) && (carni==cult) && (frut>var)){
			  		  printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, PRE-ELABORADOS, CARNICOS Y CULTURA\n");
				  }else{
				  	if((carni==preel) && (preel==var) && (var==cult) && (carni>frut)){
			  		  printf("Los sectores con mayor puestos son: PRE-ELABORADOS, CARNICOS, VARIOS Y CULTURA\n");
				  }else{
				  	if( (frut==carni) && (carni==var) && (var==cult) && (frut>preel)){
			  		  printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, CARNICOS, VARIOS Y CULTURA\n");
				  }else{
				  	if((frut==preel) && (preel==var) && (frut>carni) && (frut>cult)){
			  		printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, PRE-ELABORADOS Y VARIOS\n");
				  }else{
				  	if((frut==preel) && (preel==carni) && (frut>var) && (frut>cult) ){
			  		  printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, PRE-ELABORADOS Y CARNICOS\n");
				  }else{
				  	if((frut==preel) && (preel==cult) && (frut>var) && (frut>carni)){
				  		printf("Los sectores con mayor puestos son: FRUTIHORTICOLA, PRE-ELABORADOS Y CULTURA\n");
					  }else{
					  	if((cult==preel) && (preel==var) && (cult>frut) && (cult>carni)){
				  		printf("Los sectores con mayor puestos son: CULTURA, PRE-ELABORADOS Y VARIOS\n");
					  }else{
					  		if((carni==preel) && (preel==var) && (carni>frut) &&(carni>cult) ){
				  		     printf("Los sectores con mayor puestos son: CARNICOS, PRE-ELABORADOS Y VARIOS\n");
				  		 }else{
				  		 	if((frut==preel) && (frut>var) && (frut>carni) && (frut>cult)){
			  		  printf("Los sectores con mayor puestos es: FRUTIHORTICOLA Y PRE-ELABORADOS\n");
				  }else{
				  	if((frut==var) && (frut>preel) && (frut>carni) && (frut>cult)){
			  		  printf("Los sectores con mayor puestos es: FRUTIHORTICOLA Y VARIOS\n");
				  }else{
				  	if((frut==cult) && (frut>preel) && (frut>var) && (frut>carni)){
			  		  printf("Los sectores con mayor puestos es: FRUTIHORTICOLA Y CULTURA\n");
				  }else{
				  	if( (frut==carni) && (frut>preel) && (frut>var)  && (frut>cult)){
			  		  printf("Los sectores con mayor puestos es: FRUTIHORTICOLA Y CARNICOS\n");
				  }else{
				  	if( (preel==var) && (preel>frut) && (preel>carni) && (preel>cult)){
			  		  printf("Los sectores con mayor puestos es: PREELABORADOS Y VARIOS\n");
				  }else{
				  	if( (preel==carni) && (preel>frut) && (preel>var) && (preel>cult)){
			  		printf("Los sectores con mayor puestos es: PREELABORADOS Y CARNICOS\n");
				  }else{
				  	if((preel==cult) && (preel>frut) && (preel>var) && (preel>carni)){
			  		  printf("Los sectores con mayor puestos es: PREELABORADOS Y CULTURA\n");
				  }else{
				  	if((var==carni) && (var>frut) && (var>preel) && (var>cult)){
				  		printf("Los sectores con mayor puestos es: VARIOS Y CARNICOS\n");
					  }else{
					  	if( (var==cult) && (cult>frut) && (cult>preel)  && (cult>carni)){
				  		printf("Los sectores con mayor puestos es: VARIOS Y CULTURA\n");
					  }else{
					  		if((carni==cult) && (carni>frut) && (carni>preel) && (carni>var)){
				  		     printf("Los sectores con mayor puestos es: CARNICOS Y CULTURAL\n");
				  		 
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}

//funcion que muestra productor con mas de un puesto
void productorconmaspuestos(){
 FILE *puntero;
	struct contratos contrat;
	int aux=0,band=0;
	puntero = fopen ("contratos.b","rb");
if (puntero!=NULL){
	fread (&contrat,sizeof(contrat),1,puntero);
	while (!feof(puntero)){
		if((contrat.client.contpuestos>1) && (contrat.client.idcliente !=aux)){
			aux=contrat.client.idcliente;
			band=1;
		printf("Nombre del cliente: %s\n",contrat.client.nombre);
		printf("DNI: %ld \n", contrat.client.dni);
		printf("ID: %d \n",contrat.client.idcliente);
	//	printf("Cantidad de puestos: %d",contrat.client.contpuestos);
		printf("\n");
     }
     fread (&contrat,sizeof(contrat),1,puntero);
    } 
    if(band==0){
    	printf("No hay productores con mas de un puesto\n");
	}
	fclose(puntero); 
}else{
	printf("No se abrio el archivo correctamente");
}
}

void renovarcontrato (){ //FUNCION QUE RENUEVA CONTRATOS 
FILE *arch;
int aux=(-1);
int op,contrat;
struct contratos contr;
arch=fopen("contratos.b","r+b");
if(arch!=NULL){
	fread(&contr,sizeof(contr),1,arch);
	while(!feof(arch)){
		if(contr.id>0){
				printf("Nombre del cliente: %s\n",contr.client.nombre);
				printf("DNI del cliente: %ld\n",contr.client.dni);
				printf("El id del cliente:%d\n",contr.client.idcliente);
	//			printf("Cantidad de puestos alquilados: %d\n",contr.client.contpuestos);
				printf("Responsable de la firma:%s\n",contr.responsablefirma);
				printf("Responsable del registro:%s\n",contr.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contr.fechainicio.dia,contr.fechainicio.mes,contr.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contr.fechafin.dia,contr.fechafin.mes,contr.fechafin.ano);
				printf("el ID del puesto: %d\n",contr.idpuesto);
				printf("Monto mensual:$%ld\n",contr.precio);
				printf("El medidor del contrato esta en: %d\n",contr.medidorpuest);
				printf("ID del contrato: %d\n\n\n",contr.id);
		}
			fread(&contr,sizeof(contr),1,arch);
	}
	printf("Desea renovar un contrato? 1)SI 2)NO \n");
	scanf("%d",&op);
	if(op==1){
		printf("Ingrese el id del contrato que desea renovar\n");
		scanf("%d",&contrat);
		fseek(arch,sizeof(contr)*contrat,SEEK_SET);
		 fread(&contr,sizeof(contr),1,arch);
	 	fseek(arch,sizeof(contr)*aux,SEEK_CUR);
		printf("Ingrese la nueva fecha de fin del alquiler\n");
       printf("Dia: ");
       scanf("%d",&contr.fechafin.dia);
       printf("Mes: ");
       scanf("%d",&contr.fechafin.mes);
       printf("Anio: ");
       scanf("%d",&contr.fechafin.ano);
       fwrite(&contr,sizeof(contr),1,arch);
       fread(&contr,sizeof(contr),1,arch);
	}
	fclose(arch);
}else
printf("No se abrio el Archivo");
}//crear un contrato nuevo

void modificarpuesto(){ //modifica puesto
FILE *arch;
struct puestos p;
int op,id,aux=(-1),op2;
arch=fopen("puestos.b","r+b");
if (arch!=NULL){
	fread (&p,sizeof(p),1,arch);
	printf("LISTA DE PUESTOS: \n");
	while (!feof(arch)){
		if(p.id>0){
		printf ("El sector es %s\n",p.sector);
		printf ("El tipo es %s\n",p.tipo);
		printf ("La dimension es de %dm2\n",p.dimension);
		printf ("El precio del puesto es de $%ld \n",p.precio);
		printf ("La disponibilidad es %d\n",p.dispon);
		printf ("El id del puesto es %d\n",p.id);
		printf("El medidor del puesto esta en: %d \n\n\n",p.medidor);
	}
	fread (&p,sizeof(p),1,arch);
}
printf("Desea modificar un puesto? 1)SI 2)NO \n");
scanf("%d",&op);
if(op==1){
	printf("Ingrese el id del puesto a modificar:\n");
	scanf("%d",&id);
		fseek(arch,sizeof(p)*id,SEEK_SET);
		 fread(&p,sizeof(p),1,arch);
	 	fseek(arch,sizeof(p)*aux,SEEK_CUR);
	 	printf("Que desea modificar: \n 1)SECTOR \n 2)TIPO DE PUESTO \n 3)DIMENSION \n 4)PRECIO\n 5)MODIF. TODO \n");
	 	printf("Opcion: ");
	 	scanf("%d",&op2);
	 	if(op2==1){
	 	printf ("Ingrese el sector que corresponda \n");
		getchar ();
		gets (p.sector);
	}
	if(op2==2){
		printf("Ingrese el tipo de puesto \n");
		gets (p.tipo);
	}
	if(op2==3){
		printf ("Ingrese la dimension del puesto \n");
		scanf ("%d",&p.dimension);
	}
	if(op2==4){
		printf ("Ingrese el precio del puesto \n");
		scanf ("%ld",&p.precio);
	}
	if(op2==5){
		printf ("Ingrese el sector que corresponda \n");
		getchar ();
		gets (p.sector);
		printf("Ingrese el tipo de puesto \n");
		gets (p.tipo);
		printf ("Ingrese la dimension del puesto \n");
		scanf ("%d",&p.dimension);
		printf ("Ingrese el precio del puesto \n");
		scanf ("%ld",&p.precio);
	}
		fwrite(&p,sizeof(p),1,arch);
		printf("Se modifico correctamente!");
}
}
fclose(arch);
}
void mostrarcontratos(){
	FILE *arch;
	struct contratos contrat;
	arch=fopen("contratos.b","r+b");
	if(arch!=NULL){
		fread(&contrat,sizeof(contrat),1,arch);
		while(!feof(arch)){
			if(contrat.id>0){
		    	printf("Nombre del cliente: %s\n",contrat.client.nombre);
				printf("DNI del cliente: %ld\n",contrat.client.dni);
				printf("El id del cliente:%d\n",contrat.client.idcliente);
		//		printf("Cantidad de puestos alquilados: %d\n",contrat.client.contpuestos);
				printf("Responsable de la firma:%s\n",contrat.responsablefirma);
				printf("Responsable del registro:%s\n",contrat.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contrat.fechainicio.dia,contrat.fechainicio.mes,contrat.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contrat.fechafin.dia,contrat.fechafin.mes,contrat.fechafin.ano);
				printf("el ID del puesto: %d\n",contrat.idpuesto);
				printf("Monto mensual:$%ld\n",contrat.precio);
				printf("ID del contrato: %d\n\n\n",contrat.id);
			}
			fread(&contrat,sizeof(contrat),1,arch);
		}
	}else{
		printf("no se abrio el archivo correctamente");
	}
}

void mostrarcontratoespecifico(){
	FILE *arch;
	struct contratos contrat;
	char nombre[40];
	long int dni;
	arch=fopen("contratos.b","r+b");
	if(arch!=NULL){
		printf("Ingrese el nombre del cliente\n");
		getchar();
		gets(nombre);
		printf("Ingrese el dni del cliente\n");
		scanf("%ld",&dni);
		fread(&contrat,sizeof(contrat),1,arch);
		while(!feof(arch)){
			if(contrat.id>0){
				if(strcmp(contrat.client.nombre,nombre)==0){
					if(contrat.client.dni==dni){
		    	printf("Nombre del cliente: %s\n",contrat.client.nombre);
				printf("DNI del cliente: %ld\n",contrat.client.dni);
				printf("El id del cliente:%d\n",contrat.client.idcliente);
//				printf("Cantidad de puestos alquilados: %d\n",contrat.client.contpuestos);
				printf("Responsable de la firma:%s\n",contrat.responsablefirma);
				printf("Responsable del registro:%s\n",contrat.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contrat.fechainicio.dia,contrat.fechainicio.mes,contrat.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contrat.fechafin.dia,contrat.fechafin.mes,contrat.fechafin.ano);
				printf("el ID del puesto: %d\n",contrat.idpuesto);
				printf("Monto mensual:$%ld\n",contrat.precio);
				printf("ID del contrato: %d\n\n\n",contrat.id);
			}
		}
			}
			fread(&contrat,sizeof(contrat),1,arch);
		}
	}else{
		printf("no se abrio el archivo correctamente");
	}
}

void eliminarpuestos(){
	int op,id,aux=(-1);
	FILE *arch;
	struct puestos p;
	arch=fopen("puestos.b","r+b");
	if(arch!=NULL){
	fread (&p,sizeof(p),1,arch);
	printf("LISTA DE PUESTOS: \n");
	while (!feof(arch)){
		if(p.id>0){
		printf ("El sector es %s\n",p.sector);
		printf ("El tipo es %s\n",p.tipo);
		printf ("La dimension es de %dm2\n",p.dimension);
		printf ("El precio del puesto es de $%ld \n",p.precio);
		printf ("La disponibilidad es %d\n",p.dispon);
		printf ("El id del puesto es %d\n",p.id);
		printf("El medidor del puesto esta en: %d \n\n\n",p.medidor);
	}
	fread (&p,sizeof(p),1,arch);
	}
	printf("Desea eliminar un puesto? 1)SI 2)NO \n");
scanf("%d",&op);
if(op==1){
	printf("Ingrese el id del puesto a eliminar:\n");
	scanf("%d",&id);
	id--;
		fseek(arch,sizeof(p)*id,SEEK_SET);
	 fread(&p,sizeof(p),1,arch);
		fseek(arch,sizeof(p)*aux,SEEK_CUR);
	 p.id=0;
		p.dimension=0;
		p.dispon=0;
		p.medidor=0;
		p.precio=0;
		strcpy(p.sector," ");
		strcpy(p.tipo," ");
		fwrite(&p,sizeof(p),1,arch);
	fclose(arch);
	printf("Se elimino el puesto correctamente!\n");
}
//volver al menu

}
}



void eliminarcontratos(){
	fpos_t pos;
	int op,id,aux=(-1),idpuesto,idcontrato,contaux;
	FILE *arch,*puntero;
	struct contratos contrat;
	struct puestos p;
	arch=fopen("contratos.b","r+b");
	puntero=fopen("puestos.b","r+b");
	if(arch!=NULL){
		fread(&contrat,sizeof(contrat),1,arch);
		while(!feof(arch)){
			if(contrat.id>0){
		    	printf("Nombre del cliente: %s\n",contrat.client.nombre);
				printf("DNI del cliente: %ld\n",contrat.client.dni);
				printf("El id del cliente:%d\n",contrat.client.idcliente);
//				printf("Cantidad de puestos alquilados: %d\n",contrat.client.contpuestos);
				printf("Responsable de la firma:%s\n",contrat.responsablefirma);
				printf("Responsable del registro:%s\n",contrat.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contrat.fechainicio.dia,contrat.fechainicio.mes,contrat.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contrat.fechafin.dia,contrat.fechafin.mes,contrat.fechafin.ano);
				printf("el ID del puesto: %d\n",contrat.idpuesto);
				printf("Monto mensual:$%ld\n",contrat.precio);
				printf("ID del contrato: %d\n\n\n",contrat.id);
			}
			fread(&contrat,sizeof(contrat),1,arch);
		}
		printf("Desea eliminar un contrato? 1)SI 2)NO\n");
		scanf("%d",&op);
		if(op==1){
			printf("Ingrese el id del contrato a Eliminar\n");
			scanf("%d",&idcontrato);
			idcontrato--;
			fseek(arch,sizeof(contrat)*idcontrato,SEEK_SET);
	 	fread(&contrat,sizeof(contrat),1,arch);
			fseek(arch,sizeof(contrat)*aux,SEEK_CUR);
			contaux=contrat.client.contpuestos;
			contaux--;
			contrat.client.contpuestos=contaux;
			contrat.id=0;
			idpuesto=contrat.idpuesto;
			fwrite(&contrat,sizeof(contrat),1,arch);
		}
		fclose(arch);
}
if(puntero!=NULL){
	idpuesto--;
 fseek (puntero,(idpuesto)*sizeof (p),SEEK_SET);
	fread (&p,sizeof(p),1,puntero);
		p.dispon=1;
		fseek (puntero,sizeof(p)*aux,SEEK_CUR);
		fwrite(&p,sizeof(p),1,puntero);
		printf("Se elimino el contrato con exito!\n");
}
}

void contratoseliminados(){
	FILE *arch;
	struct contratos contrat;
	arch=fopen("contratos.b","r+b");
	if(arch!=NULL){
		fread(&contrat,sizeof(contrat),1,arch);
		while(!feof(arch)){
			if(contrat.id==0){
		    	printf("Nombre del cliente: %s\n",contrat.client.nombre);
				printf("DNI del cliente: %ld\n",contrat.client.dni);
				printf("El id del cliente:%d\n",contrat.client.idcliente);
			//	printf("Cantidad de puestos alquilados: %d\n",contrat.client.contpuestos);
				printf("Responsable de la firma:%s\n",contrat.responsablefirma);
				printf("Responsable del registro:%s\n",contrat.responsableregistro);
				printf("Fecha inicio: %d/%d/%d\n",contrat.fechainicio.dia,contrat.fechainicio.mes,contrat.fechainicio.ano);
				printf("Fecha fin: %d/%d/%d\n",contrat.fechafin.dia,contrat.fechafin.mes,contrat.fechafin.ano);
				printf("el ID del puesto: %d\n",contrat.idpuesto);
				printf("Monto mensual:$%ld\n",contrat.precio);
				printf("ID del contrato: %d\n\n\n",contrat.id);
			}
			fread(&contrat,sizeof(contrat),1,arch);
		}
	}else{
		printf("no se abrio el archivo correctamente");
	}
}

