#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#define MAX_ANIMALES 100

typedef struct {
    char id[20];
    float peso;
    int lote;
} Animal;

extern Animal animales[MAX_ANIMALES];
extern int cantidadAnimales;




#endif // ANIMAL_H_INCLUDED
