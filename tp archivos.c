#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define espacio_char 20 

// Trabajo Práctico Taller de Programación
// Integrantes : Ortego Ignacio, Ponce Lautaro


/* Consigna:
nuevoContacto: solicita los datos de un nuevo contacto y lo agrega en la agenda;

muestraContactos: lista todos los contactos;

buscaContactosNombre: recibe una cadena de caracteres y devuelve los contactos
cuyo nombre contenga la cadena recibida (no muestra);

buscarContactosTelefono: se comporta de manera an´aloga a buscaContactosNombre 
pero trabaja con el tel´efono en vez del nombre (no muestra);

eliminarContactoNombre: recibe el nombre del contacto que se desea borrar; si
el contacto no existe lo informa con un mensaje apropiado y, en caso de que exista
solicita la confirmaci´on del usuario y procede a borrar el contacto;

eliminarTodosContactos: solicita la confirmaci´on del usuario para borrar todos
los contactos;

menu: permite acceder a las distintas funcionalidades del programa.
*/

// Estructuras:

typedef struct _Contacto{
char *nombre, *direccion, *telefono, *mail, *aliasTelegram, *usuarioInstagram;
} Contacto;

typedef struct _Snodo{
    Contacto* dato;
    struct _Snodo *sig, *ant;
} Snodo;

typedef struct{
    Snodo *primero, *ultimo;
} Slist;


// Funciones:

void imprimirCartel(int a) // Función auxiliar para mostrar carteles estéticos
{   
    if(a == 1)
    {
        printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c  0. Mostrar menu en pantalla                        %c\n", 186, 186); 
        printf("%c  1. Generar nuevo contacto                          %c\n", 186, 186);
        printf("%c  2. Mostrar todos los contactos                     %c\n", 186, 186);
        printf("%c  3. Buscar un contacto por nombre                   %c\n", 186, 186);
        printf("%c  4. Buscar un contacto por numero de telefono       %c\n", 186, 186);
        printf("%c  5. Eliminar un contacto por nombre                 %c\n", 186, 186);
        printf("%c  6. Eliminar todos los contactos                    %c\n", 186, 186);
        printf("%c  7. Cerrar agenda                                   %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    }
    if(a == 2)
    {   
        printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c  Quiere ver la informacion detallada del contacto?  %c\n", 186, 186); 
        printf("%c  1. SI                                              %c\n", 186, 186);
        printf("%c  0. NO                                              %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("Respuesta:");
    }
    if(a == 3){
        printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c  Desea eliminar este contacto?                      %c\n",186,186);
        printf("%c  1. SI                                              %c\n",186,186);
        printf("%c  0. NO                                              %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("Respuesta:");
    }

    if(a == 4){
        printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c  Desea eliminar todos los contactos?                %c\n",186,186);
        printf("%c  1. SI                                              %c\n",186,186);
        printf("%c  0. NO                                              %c\n",186,186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("Respuesta:");

    }
    if(a == 5){
        printf("\n");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf("%c  Desea cerrar la agenda?                            %c\n", 186, 186);
        printf("%c  1. SI                                              %c\n", 186, 186);
        printf("%c  0. NO                                              %c\n", 186, 186);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("Respuesta:");
    }
}                                                            

Contacto* ingresoDatos() // Funcion auxiliar para ingresar los datos de un nuevo contacto
{
    // Pedir memoria para cada miembro de la estructura Contacto:
    Contacto *aux = malloc(sizeof(Contacto));
    aux->nombre = malloc(sizeof(char)*espacio_char);
    aux->direccion = malloc(sizeof(char)*espacio_char);
    aux->telefono = malloc(sizeof(char)*espacio_char);
    aux->mail = malloc(sizeof(char)*espacio_char);
    aux->aliasTelegram = malloc(sizeof(char)*espacio_char);
    aux->usuarioInstagram = malloc(sizeof(char)*espacio_char);
    
    // Ingreso de datos:
    //Recuerden que el %s lee hasta un separador (tabulador, espacio en blanco o salto de línea).
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", aux->nombre);
    printf("Ingrese la direccion del contacto:");
    scanf("%s", aux->direccion);
    printf("Ingrese el telefono del contacto:");
    scanf("%s", aux->telefono);
    printf("Ingrese el mail del contacto:");
    scanf("%s", aux->mail);
    printf("Ingrese el alias de Telegram del contacto:");
    scanf("%s", aux->aliasTelegram);
    printf("Ingrese el usuario de instagram del contacto:");
    scanf("%s", aux->usuarioInstagram);

    return aux;
}

Contacto* ingresoDatosLista(Snodo *tempNodo) // Funcion auxiliar para ingresar los datos de un nuevo contacto
{
    // Pedir memoria para cada miembro de la estructura Contacto:
    Contacto *aux = malloc(sizeof(Contacto));
    aux->nombre = malloc(sizeof(char)*espacio_char);
    aux->direccion = malloc(sizeof(char)*espacio_char);
    aux->telefono = malloc(sizeof(char)*espacio_char);
    aux->mail = malloc(sizeof(char)*espacio_char);
    aux->aliasTelegram = malloc(sizeof(char)*espacio_char);
    aux->usuarioInstagram = malloc(sizeof(char)*espacio_char);
    
    // Copia de datos:
    strcpy(tempNodo->dato->nombre, aux->nombre);
    strcpy(tempNodo->dato->direccion, aux->direccion);
    strcpy(tempNodo->dato->telefono, aux->telefono);
    strcpy(tempNodo->dato->mail, aux->mail);
    strcpy(tempNodo->dato->aliasTelegram, aux->aliasTelegram);
    strcpy(tempNodo->dato->usuarioInstagram, aux->usuarioInstagram);

    return aux;
}

Slist* nuevoContacto(Contacto *aux, Slist* lista) 
{
    // Pido memoria para el nuevo nodo
    Snodo* nuevoNodo = malloc(sizeof(Snodo));
    //Esto copia el puntero. No se hace una copia real de los datos.
    nuevoNodo->dato = aux;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = lista->ultimo;

    // Agrega el nodo al final de la lista
    if(lista->ultimo != NULL) lista->ultimo->sig = nuevoNodo; // Si la lista no esta vacia
    if(lista->primero == NULL) lista->primero = nuevoNodo; // Si la lista esta vacia
    lista->ultimo = nuevoNodo;

    return lista;
}

//Se podría haber reusado la función visitante de SList.
void muestraContactos(Slist* lista)
{
    int i = 1;
    Snodo *tempNodo = lista->primero;

    if(lista->primero == NULL) printf("No hay contactos ingresados."); // Si la lista esta vacia
    else
    {
        for(;tempNodo != NULL; tempNodo = tempNodo->sig) // Recorrer la lista
        {
        	//Esto tendría que estar en una función.
            printf("\n\n%c Contacto %d:\n", 254, i);
            printf("  Nombre: %s\n", tempNodo->dato->nombre);
            printf("  Direccion: %s\n", tempNodo->dato->direccion);
            printf("  Telefono: %s\n", tempNodo->dato->telefono);
            printf("  Mail: %s\n",tempNodo->dato->mail);
            printf("  Alias de Telegram: %s\n", tempNodo->dato->aliasTelegram);
            printf("  Usuario de Instagram: %s\n", tempNodo->dato->usuarioInstagram);
            i++;
        }

    }
}

Snodo* buscaContactosNombre(Slist* lista, char* nombre) // Devuelve el primer contacto encontrado por nombre
{
    Snodo* tempNodo = lista->primero;

    if(lista->primero != NULL) 
    {
        for(;tempNodo != NULL; tempNodo=tempNodo->sig) // Recorrer la lista
        {
            if(strstr(tempNodo->dato->nombre,nombre) != NULL) return tempNodo; // Comparar datos
        }
    }
    return tempNodo = NULL; //Si no hay coincidencias o la lista esta vacia
}

Snodo* buscarContactosTelefono(Slist* lista, char* telefono) // Devuelve el primer contacto encontrado por telefono
{
    Snodo* tempNodo = lista->primero;

    if(lista->primero != NULL)
    {
        for(;tempNodo != NULL; tempNodo=tempNodo->sig) //Recorrer la lista
        {
            if(strstr(tempNodo->dato->telefono,telefono) != NULL) return tempNodo;   // Comparar datos
        } 
    }
    return tempNodo = NULL; //Si no hay coincidencias o la lista esta vacia
}

void informacionDetallada(Contacto* tempCont) // Funcion extra que muestra informacion del contacto encontrado (opcional por el usuario)
{
    int opcion = 0;
    
    imprimirCartel(2);
    scanf("%i",&opcion); // Le pregunta al usuario si quiere mostrar los datos del contacto
    
    if(opcion == 1)
    {
        printf("\n%c Datos del contacto:\n", 254);
        printf("  Nombre: %s\n", tempCont->nombre);
        printf("  Direccion: %s\n", tempCont->direccion);
        printf("  Telefono: %s\n", tempCont->telefono);
        printf("  Mail: %s\n", tempCont->mail);
        printf("  AliasTelegram: %s\n", tempCont->aliasTelegram);
        printf("  UsuarioInstagram: %s\n", tempCont->usuarioInstagram);
    }
}

void liberarMemoria(Snodo* freeNodo) // Funcion auxiliar para ahorrar líneas al liberar memoria
{
    free(freeNodo->dato->nombre);
    free(freeNodo->dato->direccion);
    free(freeNodo->dato->telefono);
    free(freeNodo->dato->mail);
    free(freeNodo->dato->aliasTelegram);
    free(freeNodo->dato->usuarioInstagram);
    free(freeNodo->dato);
    free(freeNodo);
}

void eliminarContactoNombre(Slist* lista, char* nombre) 
{    
    int confirmacion = 0, ban = 0;
    int resultado = 0;
    Snodo* tempNodo = lista->primero;
    Snodo* freeNodo = tempNodo;

    if(lista->primero != NULL) 
    {
    	//Si es el único no entra acá.
        for(;tempNodo->sig != NULL; tempNodo = tempNodo->sig) // Recorrer la lista
        {
            if(strcmp(tempNodo->dato->nombre,nombre) == 0)
            {
                imprimirCartel(3);
                scanf("%d", &confirmacion);
                resultado = 1;
            }

            if(confirmacion == 1)
            {
                freeNodo = tempNodo;
            
                if(tempNodo->ant == NULL && tempNodo->sig == NULL) // Unico en la lista 
                {
                    lista->primero = NULL;
                    lista->ultimo = NULL;
                    ban = 1;
                }
                else if(ban == 0 && tempNodo->ant == NULL && tempNodo->sig != NULL) // Primero de la lista 
                {
                    tempNodo->sig->ant = NULL;
                    lista->primero = tempNodo->sig;
                    ban = 1;
                }
                else if(ban == 0 && tempNodo->sig == NULL)  // Ultimo en la lista. 
                {
                    tempNodo->ant->sig = NULL;
                    lista->ultimo = tempNodo->ant;
                    ban = 1;
                }
                else if(ban == 0)   // En el medio de la lista. 
                {
                    tempNodo->sig->ant = tempNodo->ant;
                    tempNodo->ant->sig = tempNodo->sig;
                    ban = 1;
                }
                liberarMemoria(freeNodo);
            }
            confirmacion = 0;
            ban = 0;
        }
        
        if(ban == 0 && strcmp(tempNodo->dato->nombre,nombre) == 0)
        {
            imprimirCartel(3);
            scanf("%d", &confirmacion);
            resultado = 1;
        }

        // Nodo afuera del for, puede ser el único o el último

        if(confirmacion == 1)
        {
            freeNodo = tempNodo;
            
            if(tempNodo->ant == NULL && tempNodo->sig == NULL) // Unico en la lista 
            {
                lista->primero = NULL;
                lista->ultimo = NULL;
                ban = 1;
            }
            else if(ban == 0 && tempNodo->sig == NULL)  // Ultimo en la lista
            {
                tempNodo->ant->sig = NULL;
                lista->ultimo = tempNodo->ant;
                ban = 1;
            }
            liberarMemoria(freeNodo);
        }
        
        if (resultado == 0) printf("\nEl contacto ingresado no existe");
    }
}

Slist* eliminarTodosContactos(Slist* lista, int finalizar) 
{
    int confirmacion;
    Snodo* tempNodo = lista->primero;
    Snodo* freeNodo = NULL;

    if(lista->primero == NULL && finalizar == 0) printf("No hay contactos ingresados");
    else if(lista->primero != NULL)
    {   
        if(finalizar == 0)  // Si el programa no esta finalizando, se pide confirmacion del usuario
        {
            imprimirCartel(4);
            scanf("%d", & confirmacion);
        } 
        else confirmacion = 1;

        if(confirmacion == 1) // Borra el primero de la lista con el primer modulo hasta que queda uno y lo borra con el segundo modulo
        {
            for(;tempNodo->sig != NULL; tempNodo = tempNodo->sig) // Recorrer la lista
            {
                freeNodo = tempNodo;

                if(tempNodo->ant == NULL && tempNodo->sig != NULL) // Primero de la lista
                {
                    lista->primero = tempNodo->sig;
                    tempNodo->sig->ant = NULL;
                }

                liberarMemoria(freeNodo);
            }
            freeNodo = tempNodo;

            if(tempNodo->ant == NULL && tempNodo->sig == NULL) // Unico en la lista
            {
                lista->primero = NULL;
                lista->ultimo = NULL;
            }
                
            liberarMemoria(freeNodo);
        }
    }
    return lista;
}

void guardarContactos(Slist* lista, FILE* fp)
{
    Snodo *tempNodo = lista->primero;

    if(lista->primero != NULL) // Si la lista esta vacia
    {
        for(;tempNodo != NULL; tempNodo = tempNodo->sig) // Recorrer la lista
        {
            fprintf(fp, "\n\n%c Contacto %d:\n", 254);
            fprintf(fp, "  Nombre: %s\n", tempNodo->dato->nombre);
            fprintf(fp, "  Direccion: %s\n", tempNodo->dato->direccion);
            fprintf(fp, "  Telefono: %s\n", tempNodo->dato->telefono);
            fprintf(fp, "  Mail: %s\n",tempNodo->dato->mail);
            fprintf(fp, "  Alias de Telegram: %s\n", tempNodo->dato->aliasTelegram);
            fprintf(fp, "  Usuario de Instagram: %s\n", tempNodo->dato->usuarioInstagram);
        }

    }
}
// Menú y main:

int menu(int input, Slist* lista)
{
	// Cada vez que se llama a menu se pide memoria para las variables nombre y telefono. 
    int restart, finalizar = 0;
    Contacto *aux;
    char* telefono = malloc(sizeof(char)*espacio_char);
    char* nombre = malloc(sizeof(char)*espacio_char);

    FILE *fp;
    fp = fopen("contactos.txt", "a+");

    switch (input)
    {
    case 0: // Mostrar menu en pantalla
        imprimirCartel(1);
        break;
    case 1: // Generar nuevo contacto
        aux = ingresoDatos();
        lista = nuevoContacto(aux,lista);
        printf("\nHecho");
        break;
    case 2: // Mostrar todos los contactos
        muestraContactos(lista);
        printf("\nHecho");
        break;
    case 3: // Buscar un contacto por nombre
        printf("Ingrese un nombre de contacto a buscar:");
        scanf("%s",nombre);
        
        if(buscaContactosNombre(lista,nombre) == NULL) printf("No hubo coincidencias\n");
        else
        {
            printf("Contacto encontrado: %s\n", (buscaContactosNombre(lista,nombre))->dato->nombre);
            informacionDetallada(buscaContactosNombre(lista,nombre)->dato);
        }

        printf("\nHecho");
        break;
    case 4: // Buscar un contacto por numero de telefono
        printf("Ingrese un telefono de contacto a buscar:");
        scanf("%s",telefono);

        if(buscarContactosTelefono(lista,telefono) == NULL) printf("No hubo coincidencias\n");
        else 
        {
            printf("Contacto encontrado: %s\n", (buscarContactosTelefono(lista,telefono))->dato->nombre);
            informacionDetallada(buscarContactosTelefono(lista,telefono)->dato);
        }

        printf("\nHecho");
        break;
    case 5: // Eliminar un contacto por nombre
        printf("Ingrese el nombre del contacto que desea eliminar: ");
        scanf("%s",nombre);
        eliminarContactoNombre(lista,nombre);
        printf("\nHecho");
        break;
    case 6: // Eliminar todos los contactos
        eliminarTodosContactos(lista,finalizar);
        printf("\nHecho");
        break;
    case 7: // Cerrar agenda
        imprimirCartel(5);          // Confirmación para cerrar el programa
        scanf("%i",&finalizar);

        guardarContactos(lista,fp);
        fclose(fp);

        if(finalizar == 1)
        {
            eliminarTodosContactos(lista,finalizar);
            free(lista);
            free(nombre);
            free(telefono);
            printf("Ha cerrado la agenda");
            restart = 2;                      // Esta asignación de valor es para que el pr                                              ograma termine inmediatamente luego de ejecutar las líneas anteriores y cortar el loop del main
        }

        break;
    default: // Si no corresponde a las opciones anteriores
        printf("El valor ingresado no corresponde a ninguna funcion, intenta nuevamente\n");
        restart = 1;    // Se lo devuelve al main para saber que el input ingresado no es correcto
        break;
    }

    return restart;
}

int main()

{	
    int input = 0, ban = 0, seguir = 1, respuesta_menu = 0;

    // Declaración de la lista
    Slist *lista = malloc(sizeof(Slist));
    lista->primero = NULL;
    lista->ultimo = NULL;

    // TXT
    
    printf("\nBienvenido a la agenda! \nA continuacion se muestran las funciones disponibles:\n");
    
    while(seguir == 1)      // Loop que muestra el menú al realizarse una función. Cuando seguir deja de ser 1, el programa finaliza.
    {
        menu(input,lista);      // input = 0 por lo que muestra el menú
        while(ban == 0)         // Loop para evitar que el numero ingresado no corresponda a ninguna función
        {
            printf("Ingrese la funcion que desea realizar: ");
            scanf("%i", &input);
            if((respuesta_menu = menu(input,lista)) != 1) ban = 1;   // Si el valor devuelto por la función es distinto de uno, el input ingresado es correcto
            if (respuesta_menu == 2) seguir = 0;                     // Si el valor devuelto por la función es 2, el programa termina inmediatamente
        }
        ban = 0;
        input = 0;
    }

    return 0;
}