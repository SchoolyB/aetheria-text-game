#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "./Player/Creation.h"
#include "./Countries/Description.c"

char hero_first_name[10];
char hero_dynasty_name[10];
char hero_gender[10];
char hero_homeland[10];
char hero_profession[15];
char hero_class[10];  

int main() {
  startHeroCreation();
  return 0;
}


int getFirstName() {
    char firstNameInput[10];
    printf("Enter your first name: ");
    fgets(firstNameInput, sizeof(firstNameInput), stdin);

    // Remove the trailing newline character from the input
    // !This step is important and must be had for every function that uses fgets to store data
    size_t len = strlen(firstNameInput);
    if (len > 0 && firstNameInput[len - 1] == '\n') {
        firstNameInput[len - 1] = '\0';
    }
    //this copies the input from the user into the hero_first_name variable 
    strcpy(hero_first_name, firstNameInput);
    printf("Your first name is: %s\n", hero_first_name);
    return 0;
}
//===========================================================================================================//
int dynastyNameCheck() {
    char dynastyNameDecision[10];
    char confirmDynastyDecision[10];
    printf("Do you have a dynasty name? (y/n): ");
    fgets(dynastyNameDecision, sizeof(dynastyNameDecision), stdin);

    // Remove the trailing newline character from the input
    size_t len = strlen(dynastyNameDecision);
    if (len > 0 && dynastyNameDecision[len - 1] == '\n') {
        dynastyNameDecision[len - 1] = '\0';
    }
  // Compare dynastyNameDecision with strings using strcmp
  if (strcmp(dynastyNameDecision, "y") == 0 ||
    strcmp(dynastyNameDecision, "Y") == 0 ||
    strcmp(dynastyNameDecision, "yes") == 0||
    strcmp(dynastyNameDecision, "Yes") == 0){
    getDynastyName();
    }
   else if (strcmp(dynastyNameDecision, "n") == 0 ||
    strcmp(dynastyNameDecision, "N") == 0 ||
    strcmp(dynastyNameDecision, "no") == 0 ||
    strcmp(dynastyNameDecision, "No") == 0){
    sleep(1);
    printf("You have chosen not to have a dynasty name\n");
    sleep(1);
    printf("Are you sure you do not come from a great dynasty? (y/n): ");
    fgets(confirmDynastyDecision, sizeof(confirmDynastyDecision), stdin);

    // Remove the trailing newline character from the input
    size_t len = strlen(confirmDynastyDecision);
    if (len > 0 && confirmDynastyDecision[len - 1] == '\n') {
        confirmDynastyDecision[len - 1] = '\0';
    }
    if (strcmp(confirmDynastyDecision, "y") == 0 ||
    strcmp(confirmDynastyDecision, "Y") == 0 ||
    strcmp(confirmDynastyDecision, "yes") == 0 ||
    strcmp(confirmDynastyDecision, "Yes") == 0){
      printf("You have chosen not to have a dynasty name\n");
      getHeroGender();
    }
    else if (strcmp(confirmDynastyDecision, "n") == 0 ||
    strcmp(confirmDynastyDecision, "N") == 0 ||
    strcmp(confirmDynastyDecision, "no") == 0 ||
    strcmp(confirmDynastyDecision, "No") == 0){
      getDynastyName();
    }
    else{
      printf("Please make a valid decision \n");
      dynastyNameCheck();
    }


  } else {
      printf("Error\n");
  }
  return 0;
}
//===========================================================================================================//
// This function is what gets the dynasty name if the player has chooses to have one
int getDynastyName() {
    char dynastyNameInput[20];
    printf("Enter your dynasty name: ");
    fgets(dynastyNameInput, sizeof(dynastyNameInput), stdin);

    // Remove the trailing newline character from the input
    size_t len = strlen(dynastyNameInput);
    if (len > 0 && dynastyNameInput[len - 1] == '\n') {
        dynastyNameInput[len - 1] = '\0';
    }
    // this copies the input from the user into the hero_dynasty_name variable
    strcpy(hero_dynasty_name, dynastyNameInput);
    printf("Your dynasty name is: %s\n", hero_dynasty_name);
    confirmDynastyName();
    return 0;
}
//===========================================================================================================//
int confirmDynastyName(){
  char confirmDynastyNameInput[10];
  printf("Is this correct? (y/n): ");
  fgets(confirmDynastyNameInput, sizeof(confirmDynastyNameInput), stdin);


   // Remove the trailing newline character from the input
   size_t len = strlen(confirmDynastyNameInput);
    if (len > 0 && confirmDynastyNameInput[len - 1] == '\n') {
        confirmDynastyNameInput[len - 1] = '\0';
    }
    if (strcmp(confirmDynastyNameInput, "y") == 0 ||
      strcmp(confirmDynastyNameInput, "Y") == 0 ||
      strcmp(confirmDynastyNameInput, "yes") == 0 ||
      strcmp(confirmDynastyNameInput, "Yes") == 0){
      heroGenderCheck();
        printf("Pass\n");
    
    } else if (strcmp(confirmDynastyNameInput, "n") == 0 ||
      strcmp(confirmDynastyNameInput, "N") == 0 ||
      strcmp(confirmDynastyNameInput, "no") == 0 ||
      strcmp(confirmDynastyNameInput, "No") == 0){
        printf("Fail\n");
        getDynastyName();
    } else {
        printf("You may have entered to many characters. Please Try Again\n");
    }
  
}
//===========================================================================================================//
// The results of this function running will have no effect on the game itself
int heroGenderCheck(){
  char heroGenderDecision[10];
  printf("Would you like to choose a gender for your hero? (y/n): ");
  fgets(heroGenderDecision, sizeof(heroGenderDecision), stdin);

  // Remove the trailing newline character from the input
  size_t len = strlen(heroGenderDecision);
  if(len > 0 && heroGenderDecision[len - 1] == '\n'){
    heroGenderDecision[len - 1] = '\0';
  }

  if (strcmp(heroGenderDecision, "y") == 0 || 
    strcmp(heroGenderDecision, "Y") == 0 ||
    strcmp(heroGenderDecision, "yes") == 0 ||
    strcmp(heroGenderDecision, "Yes") == 0){
        printf("Passeroni\n");
        getHeroGender();
    } else if (strcmp(heroGenderDecision, "n") == 0 ||
      strcmp(heroGenderDecision, "N") == 0 || 
      strcmp(heroGenderDecision, "no") == 0 ||
      strcmp(heroGenderDecision, "No") == 0) {
        printf("Faileroni\n");
        getHeroHomeland();
    } else {
        printf("Error\n");
    }
    return 0;
}
//===========================================================================================================//
// Rather than specifying male or female I figure it would be easier to just let the player choose whatever they want
// But still preform a check for male or female.
int getHeroGender(){
  char heroGenderInput[10];
  printf("Please tell me your gender \n");

  fgets(heroGenderInput, sizeof(heroGenderInput), stdin);

  // Remove the trailing newline character from the input
  size_t len = strlen(heroGenderInput);
  if(len > 0 && heroGenderInput[len - 1] == '\n'){
    heroGenderInput[len - 1] = '\0';
  }
  strcpy(hero_gender, heroGenderInput) ;
  printf("You are a %s \n", hero_gender );

  if(strcmp(heroGenderInput, "male") == 0||
   strcmp(heroGenderInput, "Male") == 0 ||
   strcmp(heroGenderInput, "man") == 0||
   strcmp(heroGenderInput, "Man") == 0||
   strcmp(heroGenderInput, "m" ) == 0 ||
   strcmp(heroGenderInput, "M") == 0){
    printf("This is a test to check that the user entered male\n");
    confirmHeroGender();
  }
    else if(strcmp(heroGenderInput, "female") == 0 ||
      strcmp(heroGenderInput, "Female") == 0 ||
      strcmp(heroGenderInput, "woman") == 0 ||
      strcmp(heroGenderInput, "Woman") == 0 ||
      strcmp(heroGenderInput, "f") == 0 ||
      strcmp(heroGenderInput, "F") == 0){
        printf("This is a test to check that the user entered female\n");
        confirmHeroGender();
      }
      else{
        printf("Please make a valid decision \n");
      }
}
//===========================================================================================================//
int confirmHeroGender(){
  char confirmHeroGenderInput[10];
  printf("Is this correct? (y/n): ");
  fgets(confirmHeroGenderInput, sizeof(confirmHeroGenderInput), stdin);


  size_t len = strlen(confirmHeroGenderInput);
  if(len > 0 && confirmHeroGenderInput[len - 1] == '\n'){
    confirmHeroGenderInput[len - 1] = '\0';
  }

  if (strcmp(confirmHeroGenderInput, "y") == 0 || 
    strcmp(confirmHeroGenderInput, "Y") == 0 ||
    strcmp(confirmHeroGenderInput, "yes") == 0 ||
    strcmp(confirmHeroGenderInput, "Yes") == 0){
        printf("This one passed too\n");
        getHeroHomeland();

    } else if (strcmp(confirmHeroGenderInput, "n") == 0 ||
      strcmp(confirmHeroGenderInput, "N") == 0 || 
      strcmp(confirmHeroGenderInput, "no") == 0 ||
      strcmp(confirmHeroGenderInput, "No") == 0) {
        printf("this one fails \n");
        getHeroGender();
    } else {
        printf("Error\n");
    }
    return 0;
}
//===========================================================================================================//
// This is function is huge. TODO figure out how to make it smaller
int getHeroHomeland(){
  char heroOriginDecision[10];
  char heroOriginInput[10];
  char possibleOrigins[5][15] = {
  "1: Empyrea",
  "2: Wesward",
  "3: Magdalar",
  "4: Ashvadan",
  "5: Nadafia"
  };

  printf("Which of these Countries do you hail from? \n");
  for (int i = 0; i < 5; i++){
  printf("%s \n", possibleOrigins[i]);
  }
  fgets(heroOriginInput, sizeof(heroOriginInput), stdin);

  // Remove the trailing newline character from the input
  size_t len = strlen(heroOriginInput);
  if(len > 0 && heroOriginInput[len - 1] == '\n'){
    heroOriginInput[len - 1] = '\0';
    }

  if(strcmp(heroOriginInput, "1") == 0 ||
    strcmp(heroOriginInput, "Empyrea") == 0 ||
    strcmp(heroOriginInput, "empyrea") == 0 ||
    strcmp(heroOriginInput, "EMPYERA") == 0){
      showEmpyreaDescription();
      printf("Is Empyrea the country you hail from? (y/n):\n");

      fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(heroOriginDecision);
      if(len > 0 && heroOriginDecision[len - 1] == '\n'){
        heroOriginDecision[len - 1] = '\0';
      }
        if(strcmp(heroOriginDecision, "y") == 0 ||
        strcmp(heroOriginDecision, "Y") == 0 ||
        strcmp(heroOriginDecision, "yes") == 0 ||
        strcmp(heroOriginDecision, "Yes") == 0){
          strcpy(hero_homeland, "Empyrea");
          printf("So you are from %s \n", hero_homeland);
          getHeroProfession();
        }
        else if(strcmp(heroOriginDecision, "n") == 0 ||
        strcmp(heroOriginDecision, "N") == 0 ||
        strcmp(heroOriginDecision, "no") == 0 ||
        strcmp(heroOriginDecision, "No") == 0){
          getHeroHomeland();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomeland();
        }
      
      }
    else if(strcmp(heroOriginInput, "2") == 0 ||
    strcmp(heroOriginInput, "Wesward") == 0 ||
    strcmp(heroOriginInput, "wesward") == 0 ||
    strcmp(heroOriginInput, "WESTWARD") == 0){
      showWeswardDescription();
      printf("Is Wesward the country you hail from? (y/n):\n");
      
      fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(heroOriginDecision);
      if(len > 0 && heroOriginDecision[len - 1] == '\n'){
        heroOriginDecision[len - 1] = '\0';
      }
        if(strcmp(heroOriginDecision, "y") == 0 ||
        strcmp(heroOriginDecision, "Y") == 0 ||
        strcmp(heroOriginDecision, "yes") == 0 ||
        strcmp(heroOriginDecision, "Yes") == 0){
          strcpy(hero_homeland, "Wesward");
          printf("So you are from %s \n", hero_homeland);
          getHeroProfession();
        }
        else if(strcmp(heroOriginDecision, "n") == 0 ||
        strcmp(heroOriginDecision, "N") == 0 ||
        strcmp(heroOriginDecision, "no") == 0 ||
        strcmp(heroOriginDecision, "No") == 0){
          getHeroHomeland();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomeland();
        }
    }
    else if(strcmp(heroOriginInput, "3") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0 ||
    strcmp(heroOriginInput, "magdalar") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0){
      showMagdalarDescription();
      printf("Is Magdalar the country you hail from? (y/n): \n");
      
      fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(heroOriginDecision);
      if(len > 0 && heroOriginDecision[len - 1] == '\n'){
        heroOriginDecision[len - 1] = '\0';
      }
        if(strcmp(heroOriginDecision, "y") == 0 ||
        strcmp(heroOriginDecision, "Y") == 0 ||
        strcmp(heroOriginDecision, "yes") == 0 ||
        strcmp(heroOriginDecision, "Yes") == 0){
          strcpy(hero_homeland, "Magdalar");
          printf("So you are from %s \n", hero_homeland);
          getHeroProfession();
        }
        else if(strcmp(heroOriginDecision, "n") == 0 ||
        strcmp(heroOriginDecision, "N") == 0 ||
        strcmp(heroOriginDecision, "no") == 0 ||
        strcmp(heroOriginDecision, "No") == 0){
          getHeroHomeland();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomeland();
        }
    }
    else if(strcmp(heroOriginInput, "4") == 0 ||
    strcmp(heroOriginInput, "Ashvadan") == 0 ||
    strcmp(heroOriginInput, "ashvadan") == 0 ||
    strcmp(heroOriginInput, "ASHVADAN") == 0){
      showAshvadanDescription();
      printf("Is Ashvadan the country you hail from? (y/n): \n");
      
      fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);
      
      // Remove the trailing newline character from the input
      size_t len = strlen(heroOriginDecision);
      if(len > 0 && heroOriginDecision[len - 1] == '\n'){
        heroOriginDecision[len - 1] = '\0';
      }
        if(strcmp(heroOriginDecision, "y") == 0 ||
        strcmp(heroOriginDecision, "Y") == 0 ||
        strcmp(heroOriginDecision, "yes") == 0 ||
        strcmp(heroOriginDecision, "Yes") == 0){
          strcpy(hero_homeland, "Ashvadan");
          printf("So you are from %s \n", hero_homeland);
          getHeroProfession();
        }
        else if(strcmp(heroOriginDecision, "n") == 0 ||
        strcmp(heroOriginDecision, "N") == 0 ||
        strcmp(heroOriginDecision, "no") == 0 ||
        strcmp(heroOriginDecision, "No") == 0){
          getHeroHomeland();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomeland();
        }
    }

    else if(strcmp(heroOriginInput, "5") == 0 ||
    strcmp(heroOriginInput, "Nadafia") == 0 ||
    strcmp(heroOriginInput, "nadafia") == 0 ||
    strcmp(heroOriginInput, "NADAFIA") == 0){
      showNadafiaDescription();
      printf("Is Nadafia the country you hail from? (y/n):\n");
      
      fgets(heroOriginDecision, sizeof(heroOriginDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(heroOriginDecision);
      if(len > 0 && heroOriginDecision[len - 1] == '\n'){
        heroOriginDecision[len - 1] = '\0';
      }
        if(strcmp(heroOriginDecision, "y") == 0 ||
        strcmp(heroOriginDecision, "Y") == 0 ||
        strcmp(heroOriginDecision, "yes") == 0 ||
        strcmp(heroOriginDecision, "Yes") == 0){
          strcpy(hero_homeland, "Nadafia");
          printf("So you are from %s \n", hero_homeland);
          getHeroProfession();
        }
        else if(strcmp(heroOriginDecision, "n") == 0 ||
        strcmp(heroOriginDecision, "N") == 0 ||
        strcmp(heroOriginDecision, "no") == 0 ||
        strcmp(heroOriginDecision, "No") == 0){
          getHeroHomeland();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomeland();
        }
      }
    else{
      printf("Please make a valid decision \n");
      getHeroHomeland();
    }
}
//===========================================================================================================//
// This function is only here in the even that someone wants to pick a country without reading the descriptions again
int getHeroHomelandWithoutDescriptions(){
  char confirmHomelandDecision[10];
  char heroOriginInput[10];
  char possibleOrigins[5][15] = {"1: Empyrea", "2: Wesward", "3: Magdalar", "4: Ashvadan", "5: Nadafia"};
  printf("Which of these Countries do you hail from? \n");
  for (int i = 0; i < 5; i++){
  printf("%s \n", possibleOrigins[i]);
  }
  fgets(heroOriginInput, sizeof(heroOriginInput), stdin);

  // Remove the trailing newline character from the input
  size_t len = strlen(heroOriginInput);
  if(len > 0 && heroOriginInput[len - 1] == '\n'){
    heroOriginInput[len - 1] = '\0';
    }

  if(strcmp(heroOriginInput, "1") == 0 ||
    strcmp(heroOriginInput, "Empyrea") == 0 ||
    strcmp(heroOriginInput, "empyrea") == 0 ||
    strcmp(heroOriginInput, "EMPYERA") == 0){
      printf("Is Empyrea the country you hail from? (y/n): ");

      fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmHomelandDecision);
      if(len > 0 && confirmHomelandDecision[len - 1] == '\n'){
        confirmHomelandDecision[len - 1] = '\0';
      }
        if(strcmp(confirmHomelandDecision, "y") == 0 ||
        strcmp(confirmHomelandDecision, "Y") == 0 ||
        strcmp(confirmHomelandDecision, "yes") == 0 ||
        strcmp(confirmHomelandDecision, "Yes") == 0){
          strcpy(hero_homeland, "Empyrea");
          getHeroProfession();
        }
        else if(strcmp(confirmHomelandDecision, "n") == 0 ||
        strcmp(confirmHomelandDecision, "N") == 0 ||
        strcmp(confirmHomelandDecision, "no") == 0 ||
        strcmp(confirmHomelandDecision, "No") == 0){
          getHeroHomelandWithoutDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomelandWithoutDescriptions();
        }
      
      
  
      }
    else if(strcmp(heroOriginInput, "2") == 0 ||
    strcmp(heroOriginInput, "Wesward") == 0 ||
    strcmp(heroOriginInput, "wesward") == 0 ||
    strcmp(heroOriginInput, "WESTWARD") == 0){
      printf("Is Wesward the country you hail from? (y/n): ");

      fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmHomelandDecision);
      if(len > 0 && confirmHomelandDecision[len - 1] == '\n'){
        confirmHomelandDecision[len - 1] = '\0';
      }
        if(strcmp(confirmHomelandDecision, "y") == 0 ||
        strcmp(confirmHomelandDecision, "Y") == 0 ||
        strcmp(confirmHomelandDecision, "yes") == 0 ||
        strcmp(confirmHomelandDecision, "Yes") == 0){
          strcpy(hero_homeland, "Wesward");
          getHeroProfession();
        }
        else if(strcmp(confirmHomelandDecision, "n") == 0 ||
        strcmp(confirmHomelandDecision, "N") == 0 ||
        strcmp(confirmHomelandDecision, "no") == 0 ||
        strcmp(confirmHomelandDecision, "No") == 0){
          getHeroHomelandWithoutDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomelandWithoutDescriptions();
        }
    }
    else if(strcmp(heroOriginInput, "3") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0 ||
    strcmp(heroOriginInput, "magdalar") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0){
      printf("Is Magdalar the country you hail from? (y/n): ");

      fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmHomelandDecision);
      if(len > 0 && confirmHomelandDecision[len - 1] == '\n'){
        confirmHomelandDecision[len - 1] = '\0';
      }
        if(strcmp(confirmHomelandDecision, "y") == 0 ||
        strcmp(confirmHomelandDecision, "Y") == 0 ||
        strcmp(confirmHomelandDecision, "yes") == 0 ||
        strcmp(confirmHomelandDecision, "Yes") == 0){
          strcpy(hero_homeland, "Magdalar");
          getHeroProfession();
        }
        else if(strcmp(confirmHomelandDecision, "n") == 0 ||
        strcmp(confirmHomelandDecision, "N") == 0 ||
        strcmp(confirmHomelandDecision, "no") == 0 ||
        strcmp(confirmHomelandDecision, "No") == 0){
          getHeroHomelandWithoutDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomelandWithoutDescriptions();
        }
    }
    else if(strcmp(heroOriginInput, "4") == 0 ||
    strcmp(heroOriginInput, "Ashvadan") == 0 ||
    strcmp(heroOriginInput, "ashvadan") == 0 ||
    strcmp(heroOriginInput, "ASHVADAN") == 0){
      printf("Is Ashvadan the country you hail from? (y/n): ");

      fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmHomelandDecision);
      if(len > 0 && confirmHomelandDecision[len - 1] == '\n'){
        confirmHomelandDecision[len - 1] = '\0';
      }
        if(strcmp(confirmHomelandDecision, "y") == 0 ||
        strcmp(confirmHomelandDecision, "Y") == 0 ||
        strcmp(confirmHomelandDecision, "yes") == 0 ||
        strcmp(confirmHomelandDecision, "Yes") == 0){
          strcpy(hero_homeland, "Ashvadan");
          getHeroProfession();
        }
        else if(strcmp(confirmHomelandDecision, "n") == 0 ||
        strcmp(confirmHomelandDecision, "N") == 0 ||
        strcmp(confirmHomelandDecision, "no") == 0 ||
        strcmp(confirmHomelandDecision, "No") == 0){
          getHeroHomelandWithoutDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomelandWithoutDescriptions();
        }
    }

    else if(strcmp(heroOriginInput, "5") == 0 ||
    strcmp(heroOriginInput, "Nadafia") == 0 ||
    strcmp(heroOriginInput, "nadafia") == 0 ||
    strcmp(heroOriginInput, "NADAFIA") == 0){
      printf("Is Nadafia the country you hail from? (y/n): ");

      fgets(confirmHomelandDecision, sizeof(confirmHomelandDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmHomelandDecision);
      if(len > 0 && confirmHomelandDecision[len - 1] == '\n'){
        confirmHomelandDecision[len - 1] = '\0';
      }
        if(strcmp(confirmHomelandDecision, "y") == 0 ||
        strcmp(confirmHomelandDecision, "Y") == 0 ||
        strcmp(confirmHomelandDecision, "yes") == 0 ||
        strcmp(confirmHomelandDecision, "Yes") == 0){
          strcpy(hero_homeland, "Nadafia");
          getHeroProfession();
        }
        else if(strcmp(confirmHomelandDecision, "n") == 0 ||
        strcmp(confirmHomelandDecision, "N") == 0 ||
        strcmp(confirmHomelandDecision, "no") == 0 ||
        strcmp(confirmHomelandDecision, "No") == 0){
          getHeroHomelandWithoutDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroHomelandWithoutDescriptions();
        }
    }
    else{
      printf("Please make a valid decision \n");
      getHeroHomelandWithoutDescriptions();
    }
}
//===========================================================================================================//
int seeHomelandDescriptions(){ 
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
  size_t len = strlen(seeDescriptionInput);
  if(len > 0 && seeDescriptionInput[len - 1] == '\n'){
    seeDescriptionInput[len - 1] = '\0';
  }

  // START OF EMPYREA DESCRIPTION CHECK
  if(strcmp(seeDescriptionInput, "1") == 0 ||
    strcmp(seeDescriptionInput, "Empyrea") == 0 ||
    strcmp(seeDescriptionInput, "empyrea") == 0 ||
    strcmp(seeDescriptionInput, "EMPYERA") == 0){
      showEmpyreaDescription();
      printf("Is Empyrea the country you hail from? (y/n):\n");
      fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmDescriptionDecision);
      if(len > 0 && confirmDescriptionDecision[len - 1] == '\n'){
        confirmDescriptionDecision[len - 1] = '\0';
      }
        if(strcmp(confirmDescriptionDecision, "y") == 0 ||
        strcmp(confirmDescriptionDecision, "Y") == 0 ||
        strcmp(confirmDescriptionDecision, "yes") == 0 ||
        strcmp(confirmDescriptionDecision, "Yes") == 0){
          printf("This is a test to check that the user entered Empyrea\n");
          getHeroHomelandWithoutDescriptions();
        }
        else if(strcmp(confirmDescriptionDecision, "n") == 0 ||
        strcmp(confirmDescriptionDecision, "N") == 0 ||
        strcmp(confirmDescriptionDecision, "no") == 0 ||
        strcmp(confirmDescriptionDecision, "No") == 0){
          seeHomelandDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          seeHomelandDescriptions();
        }
    }
      // END OF EMPYREA DESCRIPTION CHECK


    // START OF WESWARD DESCRIPTION CHECK
    else if(strcmp(seeDescriptionInput, "2") == 0 ||
    strcmp(seeDescriptionInput, "Wesward") == 0 ||
    strcmp(seeDescriptionInput, "wesward") == 0 ||
    strcmp(seeDescriptionInput, "WESTWARD") == 0){
      showWeswardDescription();
      printf("Is Wesward the country you hail from? (y/n):\n ");
      fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmDescriptionDecision);
      if(len > 0 && confirmDescriptionDecision[len - 1] == '\n'){
        confirmDescriptionDecision[len - 1] = '\0';
      }
        if(strcmp(confirmDescriptionDecision, "y") == 0 ||
        strcmp(confirmDescriptionDecision, "Y") == 0 ||
        strcmp(confirmDescriptionDecision, "yes") == 0 ||
        strcmp(confirmDescriptionDecision, "Yes") == 0){
          getHeroHomelandWithoutDescriptions();
          printf("This is a test to check that the user entered Wesward\n");
        }
        else if(strcmp(confirmDescriptionDecision, "n") == 0 ||
        strcmp(confirmDescriptionDecision, "N") == 0 ||
        strcmp(confirmDescriptionDecision, "no") == 0 ||
        strcmp(confirmDescriptionDecision, "No") == 0){
          seeHomelandDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          seeHomelandDescriptions();
        }
    }
    // END OF WESWARD DESCRIPTION CHECK

    // START OF MAGDALAR DESCRIPTION CHECK
    else if(strcmp(seeDescriptionInput, "3") == 0 ||
    strcmp(seeDescriptionInput, "Magdalar") == 0 ||
    strcmp(seeDescriptionInput, "magdalar") == 0 ||
    strcmp(seeDescriptionInput, "Magdalar") == 0){
      showMagdalarDescription();
      printf("Is Magdalar the country you hail from? (y/n):\n ");
      fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmDescriptionDecision);
      if(len > 0 && confirmDescriptionDecision[len - 1] == '\n'){
        confirmDescriptionDecision[len - 1] = '\0';
      }
        if(strcmp(confirmDescriptionDecision, "y") == 0 ||
        strcmp(confirmDescriptionDecision, "Y") == 0 ||
        strcmp(confirmDescriptionDecision, "yes") == 0 ||
        strcmp(confirmDescriptionDecision, "Yes") == 0){
          getHeroHomelandWithoutDescriptions();
          printf("This is a test to check that the user entered Magdalar\n");
        }
        else if(strcmp(confirmDescriptionDecision, "n") == 0 ||
        strcmp(confirmDescriptionDecision, "N") == 0 ||
        strcmp(confirmDescriptionDecision, "no") == 0 ||
        strcmp(confirmDescriptionDecision, "No") == 0){
          seeHomelandDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          seeHomelandDescriptions();
        }
      
    }
      // END OF MAGDALAR DESCRIPTION CHECK

    // START OF ASHVADAN DESCRIPTION CHECK
    else if(strcmp(seeDescriptionInput, "4") == 0 ||
    strcmp(seeDescriptionInput, "Ashvadan") == 0 ||
    strcmp(seeDescriptionInput, "ashvadan") == 0 ||
    strcmp(seeDescriptionInput, "ASHVADAN") == 0){
      showAshvadanDescription();
      printf("Is Ashvadan the country you hail from? (y/n):\n ");
      fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmDescriptionDecision);
      if(len > 0 && confirmDescriptionDecision[len - 1] == '\n'){
        confirmDescriptionDecision[len - 1] = '\0';
      }
        if(strcmp(confirmDescriptionDecision, "y") == 0 ||
        strcmp(confirmDescriptionDecision, "Y") == 0 ||
        strcmp(confirmDescriptionDecision, "yes") == 0 ||
        strcmp(confirmDescriptionDecision, "Yes") == 0){
          getHeroHomelandWithoutDescriptions(); 
          printf("This is a test to check that the user entered Ashvadan\n");
        }
        else if(strcmp(confirmDescriptionDecision, "n") == 0 ||
        strcmp(confirmDescriptionDecision, "N") == 0 ||
        strcmp(confirmDescriptionDecision, "no") == 0 ||
        strcmp(confirmDescriptionDecision, "No") == 0){
          seeHomelandDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          seeHomelandDescriptions();
        }
      
    }
      // END OF ASHVADAN DESCRIPTION CHECK

    // START OF NADAFIA DESCRIPTION CHECK
    else if(strcmp(seeDescriptionInput, "5") == 0 ||
    strcmp(seeDescriptionInput, "Nadafia") == 0 ||
    strcmp(seeDescriptionInput, "nadafia") == 0 ||
    strcmp(seeDescriptionInput, "NADAFIA") == 0){
      showNadafiaDescription();
      printf("Is Nadafia the country you hail from? (y/n):\n ");
      fgets(confirmDescriptionDecision, sizeof(confirmDescriptionDecision), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(confirmDescriptionDecision);
      if(len > 0 && confirmDescriptionDecision[len - 1] == '\n'){
        confirmDescriptionDecision[len - 1] = '\0';
      }
        if(strcmp(confirmDescriptionDecision, "y") == 0 ||
        strcmp(confirmDescriptionDecision, "Y") == 0 ||
        strcmp(confirmDescriptionDecision, "yes") == 0 ||
        strcmp(confirmDescriptionDecision, "Yes") == 0){
          getHeroHomelandWithoutDescriptions();
          printf("This is a test to check that the user entered Nadafia\n");
        }
        else if(strcmp(confirmDescriptionDecision, "n") == 0 ||
        strcmp(confirmDescriptionDecision, "N") == 0 ||
        strcmp(confirmDescriptionDecision, "no") == 0 ||
        strcmp(confirmDescriptionDecision, "No") == 0){
          seeHomelandDescriptions();
        }
        else{
          printf("Please make a valid decision \n");
          seeHomelandDescriptions();
        }
      }
      // END OF NADAFIA DESCRIPTION CHECK

    else{
      printf("ERROR: Please make a valid decision \n");
    }
}
//===========================================================================================================//
int getHeroProfession(){
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
  for (int i = 0; i < 9; i++){
    printf("%s \n", possibleProfessions[i]);
  }
  fgets(heroProfessionInput, sizeof(heroProfessionInput), stdin);

  // Remove the trailing newline character from the input
  size_t len = strlen(heroProfessionInput);
  if(len > 0 && heroProfessionInput[len - 1] == '\n'){
    heroProfessionInput[len - 1] = '\0';
  }

  if(strcmp(heroProfessionInput, "1") == 0 ||
    strcmp(heroProfessionInput, "Blacksmith") == 0 ||
    strcmp(heroProfessionInput, "blacksmith") == 0 ||
    strcmp(heroProfessionInput, "BLACKSMITH") == 0){
      strcpy(heroProfessionChoice, "Blacksmith");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);

      fgets(heroProfessionConfirmation, sizeof(heroProfessionConfirmation), stdin);

      // Remove the trailing newline character from the input
      size_t len = strlen(heroProfessionConfirmation);
      if(len > 0 && heroProfessionConfirmation[len - 1] == '\n'){
        heroProfessionConfirmation[len - 1] = '\0';
      }
        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
        strcpy(hero_profession, "Blacksmith");
          
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }
    
    else if(strcmp(heroProfessionInput, "2") == 0 ||
      strcmp(heroProfessionInput, "Merchant") == 0 ||
      strcmp(heroProfessionInput, "merchant") == 0 ||
      strcmp(heroProfessionInput, "MERCHANT") == 0){
      strcpy(heroProfessionChoice, "Merchant");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        
        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){ 
          strcpy(hero_profession, "Merchant");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }

    else if(strcmp(heroProfessionInput, "3") == 0 ||
      strcmp(heroProfessionInput, "Farmer") == 0 ||
      strcmp(heroProfessionInput, "farmer") == 0 ||
      strcmp(heroProfessionInput, "FARMER") == 0){
      strcpy(heroProfessionChoice, "Farmer");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        // Do stuff

        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "Farmer");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }

    }

    else if(strcmp(heroProfessionInput, "4") == 0 ||
      strcmp(heroProfessionInput, "Hunter") == 0 ||
      strcmp(heroProfessionInput, "hunter") == 0 ||
      strcmp(heroProfessionInput, "HUNTER") == 0){
      strcpy(heroProfessionChoice, "Hunter");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        // Do stuff

        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "Hunter");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }

    else if(strcmp(heroProfessionInput, "5") == 0 ||
      strcmp(heroProfessionInput, "Soldier") == 0 ||
      strcmp(heroProfessionInput, "soldier") == 0 ||
      strcmp(heroProfessionInput, "SOLDIER") == 0){
      strcpy(heroProfessionChoice, "Soldier");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        // Do stuff
        
        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "Soldier");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }

    else if(strcmp(heroProfessionInput, "6") == 0 ||
      strcmp(heroProfessionInput, "Sailor") == 0 ||
      strcmp(heroProfessionInput, "sailor") == 0 ||
      strcmp(heroProfessionInput, "SAILOR") == 0){
      strcpy(heroProfessionChoice, "Sailor");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        // Do stuff

        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "Sailor");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }

    else if(strcmp(heroProfessionInput, "7") == 0 ||
      strcmp(heroProfessionInput, "Scholar") == 0 ||
      strcmp(heroProfessionInput, "scholar") == 0 ||
      strcmp(heroProfessionInput, "SCHOLAR") == 0){
      strcpy(heroProfessionChoice, "Scholar");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        // Do stuff

        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "Scholar");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }

    else if(strcmp(heroProfessionInput, "8") == 0 ||
      strcmp(heroProfessionInput, "Thief") == 0 ||
      strcmp(heroProfessionInput, "thief") == 0 ||
      strcmp(heroProfessionInput, "THIEF") == 0){
      strcpy(heroProfessionChoice, "Thief");
      printf("So you are a %s is that correct? (y/n)\n", heroProfessionChoice);
        // Do stuff

        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "Thief");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }
    // TODO found bug when choosing none option. need to fix
    else if(strcmp(heroProfessionInput, "9") == 0 ||
      strcmp(heroProfessionInput, "None") == 0 ||
      strcmp(heroProfessionInput, "none") == 0 ||
      strcmp(heroProfessionInput, "NONE") == 0){
      printf("So you you do not have a profession is that correct? (y/n)\n");
        // Do stuff

        if(strcmp(heroProfessionConfirmation, "y") == 0 ||
        strcmp(heroProfessionConfirmation, "Y") == 0 ||
        strcmp(heroProfessionConfirmation, "yes") == 0 ||
        strcmp(heroProfessionConfirmation, "Yes") == 0){
          strcpy(hero_profession, "None");
        }
        else if(strcmp(heroProfessionConfirmation, "n") == 0 ||
        strcmp(heroProfessionConfirmation, "N") == 0 ||
        strcmp(heroProfessionConfirmation, "no") == 0 ||
        strcmp(heroProfessionConfirmation, "No") == 0){
          getHeroProfession();
        }
        else{
          printf("Please make a valid decision \n");
          getHeroProfession();
        }
    }
    else{
      printf("Please make a valid decision \n");
      getHeroProfession();
    }
}



// KEEP THIS FUNCTION AT THE BOTTOM OF THE FILE
int startHeroCreation(){
    getFirstName();
    dynastyNameCheck();
}