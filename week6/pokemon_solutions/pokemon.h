#ifndef POKEMON_H
#define POKEMON_H

/* 
 * header guard -- this prevents this header file from being included
 * multiple times
 */

/* 
 * Problem 0
 * Write an enumerated type called poketype with these 4 elements:
 *    - FIRE
 *    - WATER
 *    - ELECTRIC
 *    - LEAF
 * Typedef the enumerated type so that we can refer to it simply as 'poketype'
 */
typedef enum poketype poketype;
enum poketype {
  FIRE,
  WATER,
  ELECTRIC,
  LEAF
};


/*
 * Problem 1
 * Write a struct pokemon that has:
 *    - name field of 256 chars
 *    - poketype field called type
 *    - int field called level
 * Typedef the struct so that we can reference it simply as 'pokemon'
 */
typedef struct pokemon pokemon;
struct pokemon {
  char name[256];
  poketype type;
  int level;
};


/* end header guard */

#endif
