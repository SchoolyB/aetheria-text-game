#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Prototypes/Creation.h"
#include "../../Countries/Description.c"
#include "../../Utils/Global_Project_Variables.h"
#include "../../Utils/Macros/Macros.h"

// Global variables to be used in other files. See "Hero.h"
char hero_first_name[10];
char hero_dynasty_name[10];
char hero_gender[10];
char hero_homeland[10];
char hero_profession[15];
char hero_class[10];

//===========================================================================================================//
int getFirstName()
{
  char firstNameInput[10];
  char firstNameConfirmation[10];
  printf("Enter your first name: ");
  fgets(firstNameInput, sizeof(firstNameInput), stdin);

  // Remove the trailing newline character from the input
  // !This step is important and must be had for every function that uses fgets to store data
  // size_t len = strlen(firstNameInput);
  // if (len > 0 && firstNameInput[len - 1] == '\n')
  // {
  //   firstNameInput[len - 1] = '\0';
  // }
  REMOVE_NEWLINE_CHARACTER(firstNameInput);
  // this copies the input from the user into the hero_first_name variable
  strcpy(hero_first_name, firstNameInput);
  printf("Your first name is: %s\n", hero_first_name);

  printf("Is this correct? (y/n): ");

  fgets(firstNameConfirmation, sizeof(firstNameConfirmation), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(firstNameConfirmation);
  if (IS_YES(firstNameConfirmation))
  {
    printf("You have chosen %s as your first name\n", hero_first_name);
    dynastyNameCheck();
  }
  else if (IS_NO(firstNameConfirmation))
  {
    getFirstName();
  }
  else
  {
    MAKE_VALID_DECISION;
    getFirstName();
  }
}
//===========================================================================================================//
int dynastyNameCheck()
{
  char dynastyNameDecision[10];
  char confirmDynastyDecision[10];
  printf("Do you have a dynasty name? (y/n): ");
  fgets(dynastyNameDecision, sizeof(dynastyNameDecision), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(dynastyNameDecision);
  // Compare dynastyNameDecision with strings using strcmp
  if (IS_YES(dynastyNameDecision))
  {
    getDynastyName();
  }
  else if (IS_NO(dynastyNameDecision))
  {
    sleep(1);
    printf("You have chosen not to have a dynasty name\n");
    sleep(1);
    printf("Are you sure you do not come from a great dynasty? (y/n): ");
    fgets(confirmDynastyDecision, sizeof(confirmDynastyDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmDynastyDecision);
    if (IS_YES(confirmDynastyDecision))
    {
      printf("You have chosen not to have a dynasty name\n");
      heroGenderCheck();
    }
    else if (IS_NO(confirmDynastyDecision))
    {
      getDynastyName();
    }
    else
    {
      MAKE_VALID_DECISION;
      dynastyNameCheck();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    dynastyNameCheck();
  }
  return 1;
}
//===========================================================================================================//
// This function is what gets the dynasty name if the player has chooses to have one
int getDynastyName()
{
  char dynastyNameInput[20];
  printf("Enter your dynasty name: ");
  fgets(dynastyNameInput, sizeof(dynastyNameInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(dynastyNameInput);
  // this copies the input from the user into the hero_dynasty_name variable
  strcpy(hero_dynasty_name, dynastyNameInput);
  printf("Your dynasty name is: %s\n", hero_dynasty_name);
  confirmDynastyName();
  return 0;
}
//===========================================================================================================//
int confirmDynastyName()
{
  char confirmDynastyNameInput[10];
  printf("Is this correct? (y/n): ");
  fgets(confirmDynastyNameInput, sizeof(confirmDynastyNameInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(confirmDynastyNameInput);
  if (IS_YES(confirmDynastyNameInput))
  {
    heroGenderCheck();
  }
  else if (IS_NO(confirmDynastyNameInput))
  {
    getDynastyName();
  }
  else
  {
    printf("You may have entered to many characters. Please Try Again\n");
  }
}
//===========================================================================================================//
// The results of this function running will have no effect on the game itself
int heroGenderCheck()
{
  char heroGenderDecision[10];
  char heroGenderDecisionConfirmation[10];
  printf("Would you like to choose a gender for your hero? (y/n): ");
  fgets(heroGenderDecision, sizeof(heroGenderDecision), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(heroGenderDecision);
  if (IS_YES(heroGenderDecision))
  {
    getHeroGender();
  }
  else if (IS_NO(heroGenderDecision))
  {
    printf("Are you sure you do not have a gender? (y/n): ");
    fgets(heroGenderDecisionConfirmation, sizeof(heroGenderDecisionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroGenderDecisionConfirmation);

    if (IS_YES(heroGenderDecisionConfirmation))
    {
      getHeroHomeland();
    }
    else if (IS_NO(heroGenderDecisionConfirmation))
    {
      heroGenderCheck();
    }
    else
    {
      MAKE_VALID_DECISION;
      heroGenderCheck();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    heroGenderCheck();
  }
  return 0;
}
//===========================================================================================================//
// Rather than specifying male or female I figure it would be easier to just let the player choose whatever they want
// But still preform a check for male or female.
int getHeroGender()
{
  char heroGenderInput[10];
  printf("Please tell me your gender \n");

  fgets(heroGenderInput, sizeof(heroGenderInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(heroGenderInput);
  strcpy(hero_gender, heroGenderInput);
  printf("You are a %s \n", hero_gender);

  if (strcmp(heroGenderInput, "male") == 0 ||
      strcmp(heroGenderInput, "Male") == 0 ||
      strcmp(heroGenderInput, "man") == 0 ||
      strcmp(heroGenderInput, "Man") == 0 ||
      strcmp(heroGenderInput, "m") == 0 ||
      strcmp(heroGenderInput, "M") == 0)
  {
    confirmHeroGender();
  }
  else if (strcmp(heroGenderInput, "female") == 0 ||
           strcmp(heroGenderInput, "Female") == 0 ||
           strcmp(heroGenderInput, "woman") == 0 ||
           strcmp(heroGenderInput, "Woman") == 0 ||
           strcmp(heroGenderInput, "f") == 0 ||
           strcmp(heroGenderInput, "F") == 0)
  {
    confirmHeroGender();
  }
  else
  {
    MAKE_VALID_DECISION;
  }
}
//===========================================================================================================//
int confirmHeroGender()
{
  char confirmHeroGenderInput[10];
  printf("Is this correct? (y/n): ");
  fgets(confirmHeroGenderInput, sizeof(confirmHeroGenderInput), stdin);

  REMOVE_NEWLINE_CHARACTER(confirmHeroGenderInput);
  if (IS_YES(confirmHeroGenderInput))
  {
    getHeroHomeland();
  }
  else if (IS_NO(confirmHeroGenderInput))
  {
    getHeroGender();
  }
  else
  {
    printf("Error\n");
  }
  return 0;
}
//===========================================================================================================//
// This is function is huge. TODO figure out how to make it smaller
int getHeroHomeland()
{
  char heroOriginDecision[10];
  char heroOriginInput[10];
  char possibleOrigins[5][15] = {
      "1: Empyrea",
      "2: Wesward",
      "3: Magdalar",
      "4: Ashvadan",
      "5: Nadafia"};

  printf("Which of these Countries do you hail from? \n");
  for (int i = 0; i < 5; i++)
  {
    printf("%s \n", possibleOrigins[i]);
  }
  fgets(heroOriginInput, sizeof(heroOriginInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(heroOriginInput);
  if (strcmp(heroOriginInput, "1") == 0 ||
      strcmp(heroOriginInput, "Empyrea") == 0 ||
      strcmp(heroOriginInput, "empyrea") == 0 ||
      strcmp(heroOriginInput, "EMPYERA") == 0)
  {
    showEmpyreaDescription();
    printf("Is Empyrea the country you hail from? (y/n):\n");

    fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroOriginDecision);
    if (IS_YES(heroOriginDecision))
    {
      strcpy(hero_homeland, "Empyrea");
      printf("So you are from %s \n", hero_homeland);
      getHeroProfession();
    }
    else if (IS_NO(heroOriginDecision))
    {
      getHeroHomeland();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomeland();
    }
  }
  else if (strcmp(heroOriginInput, "2") == 0 ||
           strcmp(heroOriginInput, "Wesward") == 0 ||
           strcmp(heroOriginInput, "wesward") == 0 ||
           strcmp(heroOriginInput, "WESTWARD") == 0)
  {
    showWeswardDescription();
    printf("Is Wesward the country you hail from? (y/n):\n");

    fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroOriginDecision);
    if (IS_YES(heroOriginDecision))
    {
      strcpy(hero_homeland, "Wesward");
      printf("So you are from %s \n", hero_homeland);
      getHeroProfession();
    }
    else if (IS_NO(heroOriginDecision))
    {
      getHeroHomeland();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomeland();
    }
  }
  else if (strcmp(heroOriginInput, "3") == 0 ||
           strcmp(heroOriginInput, "Magdalar") == 0 ||
           strcmp(heroOriginInput, "magdalar") == 0 ||
           strcmp(heroOriginInput, "Magdalar") == 0)
  {
    showMagdalarDescription();
    printf("Is Magdalar the country you hail from? (y/n): \n");

    fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroOriginDecision);
    if (IS_YES(heroOriginDecision))
    {
      strcpy(hero_homeland, "Magdalar");
      printf("So you are from %s \n", hero_homeland);
      getHeroProfession();
    }
    else if (IS_NO(heroOriginDecision))
    {
      getHeroHomeland();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomeland();
    }
  }
  else if (strcmp(heroOriginInput, "4") == 0 ||
           strcmp(heroOriginInput, "Ashvadan") == 0 ||
           strcmp(heroOriginInput, "ashvadan") == 0 ||
           strcmp(heroOriginInput, "ASHVADAN") == 0)
  {
    showAshvadanDescription();
    printf("Is Ashvadan the country you hail from? (y/n): \n");

    fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroOriginDecision);
    if (IS_YES(heroOriginDecision))
    {
      strcpy(hero_homeland, "Ashvadan");
      printf("So you are from %s \n", hero_homeland);
      getHeroProfession();
    }
    else if (IS_NO(heroOriginDecision))
    {
      getHeroHomeland();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomeland();
    }
  }

  else if (strcmp(heroOriginInput, "5") == 0 ||
           strcmp(heroOriginInput, "Nadafia") == 0 ||
           strcmp(heroOriginInput, "nadafia") == 0 ||
           strcmp(heroOriginInput, "NADAFIA") == 0)
  {
    showNadafiaDescription();
    printf("Is Nadafia the country you hail from? (y/n):\n");

    fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroOriginDecision);
    if (IS_YES(heroOriginDecision))
    {
      strcpy(hero_homeland, "Nadafia");
      printf("So you are from %s \n", hero_homeland);
      getHeroProfession();
    }
    else if (IS_NO(heroOriginDecision))
    {
      getHeroHomeland();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomeland();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    getHeroHomeland();
  }
}
//===========================================================================================================//
// This function is only here in the even that someone wants to pick a country without reading the descriptions again
int getHeroHomelandWithoutDescriptions()
{
  char confirmHomelandDecision[10];
  char heroOriginInput[10];
  char possibleOrigins[5][15] = {"1: Empyrea", "2: Wesward", "3: Magdalar", "4: Ashvadan", "5: Nadafia"};
  printf("Which of these Countries do you hail from? \n");
  for (int i = 0; i < 5; i++)
  {
    printf("%s \n", possibleOrigins[i]);
  }
  fgets(heroOriginInput, sizeof(heroOriginInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(heroOriginInput);

  if (strcmp(heroOriginInput, "1") == 0 ||
      strcmp(heroOriginInput, "Empyrea") == 0 ||
      strcmp(heroOriginInput, "empyrea") == 0 ||
      strcmp(heroOriginInput, "EMPYERA") == 0)
  {
    printf("Is Empyrea the country you hail from? (y/n): ");

    fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmHomelandDecision);
    if (IS_YES(confirmHomelandDecision))
    {
      strcpy(hero_homeland, "Empyrea");
      getHeroProfession();
    }
    else if (IS_NO(confirmHomelandDecision))
    {
      getHeroHomelandWithoutDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomelandWithoutDescriptions();
    }
  }
  else if (strcmp(heroOriginInput, "2") == 0 ||
           strcmp(heroOriginInput, "Wesward") == 0 ||
           strcmp(heroOriginInput, "wesward") == 0 ||
           strcmp(heroOriginInput, "WESTWARD") == 0)
  {
    printf("Is Wesward the country you hail from? (y/n): ");

    fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmHomelandDecision);
    if (IS_YES(confirmHomelandDecision))
    {
      strcpy(hero_homeland, "Wesward");
      getHeroProfession();
    }
    else if (IS_NO(confirmHomelandDecision))
    {
      getHeroHomelandWithoutDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomelandWithoutDescriptions();
    }
  }
  else if (strcmp(heroOriginInput, "3") == 0 ||
           strcmp(heroOriginInput, "Magdalar") == 0 ||
           strcmp(heroOriginInput, "magdalar") == 0 ||
           strcmp(heroOriginInput, "Magdalar") == 0)
  {
    printf("Is Magdalar the country you hail from? (y/n): ");

    fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmHomelandDecision);
    if (IS_YES(confirmHomelandDecision))
    {
      strcpy(hero_homeland, "Magdalar");
      getHeroProfession();
    }
    else if (IS_NO(confirmHomelandDecision))
    {
      getHeroHomelandWithoutDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomelandWithoutDescriptions();
    }
  }
  else if (strcmp(heroOriginInput, "4") == 0 ||
           strcmp(heroOriginInput, "Ashvadan") == 0 ||
           strcmp(heroOriginInput, "ashvadan") == 0 ||
           strcmp(heroOriginInput, "ASHVADAN") == 0)
  {
    printf("Is Ashvadan the country you hail from? (y/n): ");

    fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmHomelandDecision);
    if (IS_YES(confirmHomelandDecision))
    {
      strcpy(hero_homeland, "Ashvadan");
      getHeroProfession();
    }
    else if (IS_NO(confirmHomelandDecision))
    {
      getHeroHomelandWithoutDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomelandWithoutDescriptions();
    }
  }

  else if (strcmp(heroOriginInput, "5") == 0 ||
           strcmp(heroOriginInput, "Nadafia") == 0 ||
           strcmp(heroOriginInput, "nadafia") == 0 ||
           strcmp(heroOriginInput, "NADAFIA") == 0)
  {
    printf("Is Nadafia the country you hail from? (y/n): ");

    fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmHomelandDecision);
    if (IS_YES(confirmHomelandDecision))
    {
      strcpy(hero_homeland, "Nadafia");
      getHeroProfession();
    }
    else if (IS_NO(confirmHomelandDecision))
    {
      getHeroHomelandWithoutDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroHomelandWithoutDescriptions();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    getHeroHomelandWithoutDescriptions();
  }
}
//===========================================================================================================//
int seeHomelandDescriptions()
{
  char seeDescriptionInput[10];
  char confirmDescriptionDecision[10];
  printf("Which country would you like to learn about? \n");
  printf("1: Empyrea \n");
  printf("2: Wesward \n");
  printf("3: Magdalar \n");
  printf("4: Ashvadan \n");
  printf("5: Nadafia \n");
  // TODO maybe provide an option to see all of them???

  fgets(seeDescriptionInput, sizeof(seeDescriptionInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(seeDescriptionInput);

  // START OF EMPYREA DESCRIPTION CHECK
  if (strcmp(seeDescriptionInput, "1") == 0 ||
      strcmp(seeDescriptionInput, "Empyrea") == 0 ||
      strcmp(seeDescriptionInput, "empyrea") == 0 ||
      strcmp(seeDescriptionInput, "EMPYERA") == 0)
  {
    showEmpyreaDescription();
    printf("Is Empyrea the country you hail from? (y/n):\n");
    fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmDescriptionDecision);
    if (IS_YES(confirmDescriptionDecision))
    {
      getHeroHomelandWithoutDescriptions();
    }
    else if (IS_NO(confirmDescriptionDecision))
    {
      seeHomelandDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      seeHomelandDescriptions();
    }
  }
  // END OF EMPYREA DESCRIPTION CHECK

  // START OF WESWARD DESCRIPTION CHECK
  else if (strcmp(seeDescriptionInput, "2") == 0 ||
           strcmp(seeDescriptionInput, "Wesward") == 0 ||
           strcmp(seeDescriptionInput, "wesward") == 0 ||
           strcmp(seeDescriptionInput, "WESTWARD") == 0)
  {
    showWeswardDescription();
    printf("Is Wesward the country you hail from? (y/n):\n ");
    fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmDescriptionDecision);
    if (IS_YES(confirmDescriptionDecision))
    {
      getHeroHomelandWithoutDescriptions();
      printf("This is a test to check that the user entered Wesward\n");
    }
    else if (IS_NO(confirmDescriptionDecision))
    {
      seeHomelandDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      seeHomelandDescriptions();
    }
  }
  // END OF WESWARD DESCRIPTION CHECK

  // START OF MAGDALAR DESCRIPTION CHECK
  else if (strcmp(seeDescriptionInput, "3") == 0 ||
           strcmp(seeDescriptionInput, "Magdalar") == 0 ||
           strcmp(seeDescriptionInput, "magdalar") == 0 ||
           strcmp(seeDescriptionInput, "Magdalar") == 0)
  {
    showMagdalarDescription();
    printf("Is Magdalar the country you hail from? (y/n):\n ");
    fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmDescriptionDecision);
    if (IS_YES(confirmDescriptionDecision))
    {
      getHeroHomelandWithoutDescriptions();
      printf("This is a test to check that the user entered Magdalar\n");
    }
    else if (IS_NO(confirmDescriptionDecision))
    {
      seeHomelandDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      seeHomelandDescriptions();
    }
  }
  // END OF MAGDALAR DESCRIPTION CHECK

  // START OF ASHVADAN DESCRIPTION CHECK
  else if (strcmp(seeDescriptionInput, "4") == 0 ||
           strcmp(seeDescriptionInput, "Ashvadan") == 0 ||
           strcmp(seeDescriptionInput, "ashvadan") == 0 ||
           strcmp(seeDescriptionInput, "ASHVADAN") == 0)
  {
    showAshvadanDescription();
    printf("Is Ashvadan the country you hail from? (y/n):\n ");
    fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmDescriptionDecision);
    if (IS_YES(confirmDescriptionDecision))
    {
      getHeroHomelandWithoutDescriptions();
      printf("This is a test to check that the user entered Ashvadan\n");
    }
    else if (IS_NO(confirmDescriptionDecision))
    {
      seeHomelandDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      seeHomelandDescriptions();
    }
  }
  // END OF ASHVADAN DESCRIPTION CHECK

  // START OF NADAFIA DESCRIPTION CHECK
  else if (strcmp(seeDescriptionInput, "5") == 0 ||
           strcmp(seeDescriptionInput, "Nadafia") == 0 ||
           strcmp(seeDescriptionInput, "nadafia") == 0 ||
           strcmp(seeDescriptionInput, "NADAFIA") == 0)
  {
    showNadafiaDescription();
    printf("Is Nadafia the country you hail from? (y/n):\n ");
    fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(confirmDescriptionDecision);
    if (IS_YES(confirmDescriptionDecision))
    {
      getHeroHomelandWithoutDescriptions();
      printf("This is a test to check that the user entered Nadafia\n");
    }
    else if (IS_NO(confirmDescriptionDecision))
    {
      seeHomelandDescriptions();
    }
    else
    {
      MAKE_VALID_DECISION;
      seeHomelandDescriptions();
    }
  }
  // END OF NADAFIA DESCRIPTION CHECK

  else
  {
    printf("ERROR: Please make a valid decision \n");
  }
}
//===========================================================================================================//
int getHeroProfession()
{
  char heroProfessionConfirmation[10];
  char heroProfessionInput[15];
  char heroProfessionChoice[15];
  char possibleProfessions[9][15] = {
      "1: Blacksmith",
      "2: Merchant",
      "3: Farmer",
      "4: Hunter",
      "5: Soldier",
      "6: Sailor",
      "7: Scholar",
      "8: Thief",
      "9: None"};

  printf("What is your profession? \n");
  for (int i = 0; i < 9; i++)
  {
    printf("%s \n", possibleProfessions[i]);
  }
  fgets(heroProfessionInput, sizeof(heroProfessionInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(heroProfessionInput);

  if (strcmp(heroProfessionInput, "1") == 0 ||
      strcmp(heroProfessionInput, "Blacksmith") == 0 ||
      strcmp(heroProfessionInput, "blacksmith") == 0 ||
      strcmp(heroProfessionInput, "BLACKSMITH") == 0)
  {
    strcpy(heroProfessionChoice, "Blacksmith");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Blacksmith");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "2") == 0 ||
           strcmp(heroProfessionInput, "Merchant") == 0 ||
           strcmp(heroProfessionInput, "merchant") == 0 ||
           strcmp(heroProfessionInput, "MERCHANT") == 0)
  {
    strcpy(heroProfessionChoice, "Merchant");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Merchant");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "3") == 0 ||
           strcmp(heroProfessionInput, "Farmer") == 0 ||
           strcmp(heroProfessionInput, "farmer") == 0 ||
           strcmp(heroProfessionInput, "FARMER") == 0)
  {
    strcpy(heroProfessionChoice, "Farmer");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Farmer");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "4") == 0 ||
           strcmp(heroProfessionInput, "Hunter") == 0 ||
           strcmp(heroProfessionInput, "hunter") == 0 ||
           strcmp(heroProfessionInput, "HUNTER") == 0)
  {
    strcpy(heroProfessionChoice, "Hunter");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Hunter");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "5") == 0 ||
           strcmp(heroProfessionInput, "Soldier") == 0 ||
           strcmp(heroProfessionInput, "soldier") == 0 ||
           strcmp(heroProfessionInput, "SOLDIER") == 0)
  {
    strcpy(heroProfessionChoice, "Soldier");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Soldier");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "6") == 0 ||
           strcmp(heroProfessionInput, "Sailor") == 0 ||
           strcmp(heroProfessionInput, "sailor") == 0 ||
           strcmp(heroProfessionInput, "SAILOR") == 0)
  {
    strcpy(heroProfessionChoice, "Sailor");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Sailor");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "7") == 0 ||
           strcmp(heroProfessionInput, "Scholar") == 0 ||
           strcmp(heroProfessionInput, "scholar") == 0 ||
           strcmp(heroProfessionInput, "SCHOLAR") == 0)
  {
    strcpy(heroProfessionChoice, "Scholar");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Scholar");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "8") == 0 ||
           strcmp(heroProfessionInput, "Thief") == 0 ||
           strcmp(heroProfessionInput, "thief") == 0 ||
           strcmp(heroProfessionInput, "THIEF") == 0)
  {
    strcpy(heroProfessionChoice, "Thief");
    printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "Thief");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else if (strcmp(heroProfessionInput, "9") == 0 ||
           strcmp(heroProfessionInput, "None") == 0 ||
           strcmp(heroProfessionInput, "none") == 0 ||
           strcmp(heroProfessionInput, "NONE") == 0)
  {
    strcpy(heroProfessionChoice, "None");
    printf("You have chosen not to have a profession.\n");
    sleep(1);
    printf("This may have effects on gameplay aspects\n");
    printf("Are you sure you do not want a profession? (y/n)\n");

    fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroProfessionConfirmation);
    if (IS_YES(heroProfessionConfirmation))
    {
      strcpy(hero_profession, "None");
      getHeroClass();
    }
    else if (IS_NO(heroProfessionConfirmation))
    {
      getHeroProfession();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroProfession();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    getHeroProfession();
  }
}
//===========================================================================================================//
int getHeroClass()
{
  char heroClassConfirmation[10];
  char heroClassInput[15];
  char possibleClasses[5][15] = {
      "1: Warrior",
      "2: Mage",
      "3: Rogue",
      "4: Cleric",
      "5: Bard"};

  printf("Which of the following classes do you specialize in? \n");
  for (int i = 0; i < 5; i++)
  {
    printf("%s \n", possibleClasses[i]);
  }

  fgets(heroClassInput, sizeof(heroClassInput), stdin);

  // Remove the trailing newline character from the input
  REMOVE_NEWLINE_CHARACTER(heroClassInput);

  if (strcmp(heroClassInput, "1") == 0 ||
      strcmp(heroClassInput, "Warrior") == 0 ||
      strcmp(heroClassInput, "warrior") == 0)
  {
    printf("So you are a mighty warrior is that correct? (y/n)\n");
    fgets(heroClassConfirmation, sizeof(heroClassConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroClassConfirmation);
    if (IS_YES(heroClassConfirmation))
    {
      strcpy(hero_class, "Warrior");
    }
    else if (IS_NO(heroClassConfirmation))
    {
      getHeroClass();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroClass();
    }
  }

  else if (strcmp(heroClassInput, "2") == 0 ||
           strcmp(heroClassInput, "Mage") == 0 ||
           strcmp(heroClassInput, "mage") == 0)
  {
    printf("So you are a powerful mage is that correct? (y/n)\n");
    fgets(heroClassConfirmation, sizeof(heroClassConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroClassConfirmation);
    if (IS_YES(heroClassConfirmation))
    {
      strcpy(hero_class, "Mage");
    }
    else if (IS_NO(heroClassConfirmation))
    {
      getHeroClass();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroClass();
    }
  }

  else if (strcmp(heroClassInput, "3") == 0 ||
           strcmp(heroClassInput, "Rogue") == 0 ||
           strcmp(heroClassInput, "rogue") == 0)
  {
    printf("So you are a sneaky rogue is that correct? (y/n)\n");
    fgets(heroClassConfirmation, sizeof(heroClassConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroClassConfirmation);
    if (IS_YES(heroClassConfirmation))
    {
      strcpy(hero_class, "Rogue");
    }
    else if (IS_NO(heroClassConfirmation))
    {
      getHeroClass();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroClass();
    }
  }

  else if (strcmp(heroClassInput, "4") == 0 ||
           strcmp(heroClassInput, "Cleric") == 0 ||
           strcmp(heroClassInput, "cleric") == 0)
  {
    printf("So you are a holy cleric is that correct? (y/n)\n");
    fgets(heroClassConfirmation, sizeof(heroClassConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroClassConfirmation);
    if (IS_YES(heroClassConfirmation))
    {
      strcpy(hero_class, "Cleric");
    }
    else if (IS_NO(heroClassConfirmation))
    {
      getHeroClass();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroClass();
    }
  }

  else if (strcmp(heroClassInput, "5") == 0 ||
           strcmp(heroClassInput, "Bard") == 0 ||
           strcmp(heroClassInput, "bard") == 0)
  {
    printf("So you are a talented bard is that correct? (y/n)\n");
    fgets(heroClassConfirmation, sizeof(heroClassConfirmation), stdin);

    // Remove the trailing newline character from the input
    REMOVE_NEWLINE_CHARACTER(heroClassConfirmation);
    if (IS_YES(heroClassConfirmation))
    {
      strcpy(hero_class, "Bard");
    }
    else if (IS_NO(heroClassConfirmation))
    {
      getHeroClass();
    }
    else
    {
      MAKE_VALID_DECISION;
      getHeroClass();
    }
  }
  else
  {
    MAKE_VALID_DECISION;
    getHeroClass();
  }
}
//===========================================================================================================//
void logCreationData(FILE *logFile, const char *category, const char *value)
{
  fprintf(logFile, "%s: %s\n", category, value);
  fflush(logFile);
}
//===========================================================================================================//
int appendToLog()
{
  FILE *logFile = fopen("logs/creation.log", "a");
  if (logFile == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  fprintf(logFile, "Hero Information: \n");
  fprintf(logFile, "Hero Creation Date: %s \n", __DATE__);
  logCreationData(logFile, "First Name", hero_first_name);
  logCreationData(logFile, "Dynasty Name", hero_dynasty_name);
  logCreationData(logFile, "Gender", hero_gender);
  logCreationData(logFile, "Home of Origin", hero_homeland);
  logCreationData(logFile, "Profession", hero_profession);
  logCreationData(logFile, "Class", hero_class);
  logCreationData(logFile, "+===========================+", NULL);
  fclose(logFile);
  return 0;
}
//===========================================================================================================//
// ??? possibly add race option during hero creation
// KEEP THIS FUNCTION AT THE BOTTOM OF THE FILE
int startHeroCreation()
{
  sleep(1);
  printf("Let's begin by creating your character! \n");
  sleep(1);
  usleep(500000);
  getFirstName();
  appendToLog(); // this logs all the info from the hero creation see logs/creation.log
  printf("Welcome to the world of Aethoria! %s %s %s! \n", hero_class, hero_first_name, hero_dynasty_name);
}