#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size)
{
  int max = arr[0];
  
  for(int i = 1; i < size; i++)
    {
      if (arr[i] > max)
      {
        max = arr[i];
      }
    }
  return max;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size)
{
  int temp;
  int i = 0;
  int j = size - 1;
  
  while(1)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;

      i++;
      j--;

      if(i >= j)
      {
        break;
      }
    }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize)
{
  int *numPares = (int *) malloc(size * sizeof(int));
if(numPares == NULL)
{
  exit(EXIT_FAILURE);
}
  
  int talla = 0;

  for(int i = 0; i < size; i++)
    {
      if((arr[i] % 2) == 0)
      {
        numPares[talla] = arr[i];
        talla++;
      }
    }
  (*newSize) = talla;
  
  return numPares;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[])
{
  int i = 0;
  int j = 0;
  int pos = 0;

  while(1)
    {
      if(arr1[i] < arr2[j])
      {
        result[pos] = arr1[i];
        i++;
        pos++;
      } else if (arr1[i] > arr2[j])
      {
        result[pos] = arr2[j];
        j++;
        pos++;
      } else
      {
        result[pos] = arr1[i];
        result[pos + 1] = arr2[j];
        i++;
        j++;
        pos += 2;
      }

      if(i >= size1)
      {
        while(j < size2)
          {
            result[pos] = arr2[j];
            j++;
            pos++;
          }
        break;
      } else if(j >= size2)
      {
        while(i < size1)
          {
            result[pos] = arr1[i];
            i++;
            pos++;
          }
        break;
      }
    }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/

/* Creo la función esAscendente que permite recorrer el arreglo para verificar si esta ordenado de forma ascendente, retornando false si es que se encuentra un dato que no este ordenado, y retornando true si es que todos los datos estan ordenados
*/
bool esAscendente(int arr[], int size)
{
  for(int i = 0; i < size - 1; i++)
    {
      if (arr[i] > arr[i+1])
      {
        return false;
      }
    }
  return true;
}

/* La función esDescendente funciona de la misma forma que esAscendente pero verificando si es que el arreglo esta ordenado de forma descendente recorriendolo con un ciclo for
*/

bool esDescendente(int arr[], int size)
{
  for(int i = 0; i < size - 1; i++)
    {
      if (arr[i] < arr[i+1])
      {
        return false;
      }
    }
  return true;
}

int checkSorted(int arr[], int size)
{
  if(esAscendente(arr, size))
  {
    return 1;
  } else if (esDescendente(arr, size))
  {
    return -1;
  } else
  {
    return 0;
  }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion)
{
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size)
{
  Nodo *cabeza = NULL;
  Nodo *actual = NULL;
  Nodo *temp = NULL;

  for(int i = 0; i < size; i++)
    {
      temp = (Nodo *) malloc(sizeof(Nodo));
      if (temp == NULL)
      {
        exit(EXIT_FAILURE);
      }

      temp->numero = arr[i];
      temp->siguiente = NULL;

      if(cabeza == NULL)
      {
        cabeza = temp;
      } 
      else
      {
        actual->siguiente = temp;
      }

      actual = temp;
    }
  return cabeza; 
}
