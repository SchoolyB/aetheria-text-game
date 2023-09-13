#ifndef COMMON_H
#define COMMON_H

struct Common_Enemy
{
  char name[20];
  int health;
};

struct Mini_Boss
{
  char name[20];
  char description[100];
  int health;
};

struct Boss
{
  char name[20];
  char title[20]; // will be something like "The Great" or "The Terrible"
  char description[100];
  int health;
};

#endif