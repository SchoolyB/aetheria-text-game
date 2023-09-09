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

int main() {
    // getFirstName();
    // dynastyNameCheck();
getHeroHomeland();  
    return 0;
}

int getFirstName() {
    char firstNameInput[10];
    printf("Enter your first name: ");
    fgets(firstNameInput, sizeof(firstNameInput), stdin);

    // Remove the trailing newline character from the input
    size_t len = strlen(firstNameInput);
    if (len > 0 && firstNameInput[len - 1] == '\n') {
        firstNameInput[len - 1] = '\0';
    }
    //this copies the input from the user into the hero_first_name variable 
    strcpy(hero_first_name, firstNameInput);
    printf("Your first name is: %s\n", hero_first_name);
    return 0;
}

int dynastyNameCheck() {
    char dynastyNameDecision[10];
    printf("Do you have a dynasty name? (y/n): ");
    fgets(dynastyNameDecision, sizeof(dynastyNameDecision), stdin);

    // Remove the trailing newline character from the input
    size_t len = strlen(dynastyNameDecision);
    if (len > 0 && dynastyNameDecision[len - 1] == '\n') {
        dynastyNameDecision[len - 1] = '\0';
    }

// TODO need to format this to not be so ugly
    // Compare dynastyNameDecision with strings using strcmp
    if (strcmp(dynastyNameDecision, "y") == 0 || strcmp(dynastyNameDecision, "Y") == 0 ||
        strcmp(dynastyNameDecision, "yes") == 0 || strcmp(dynastyNameDecision, "Yes") == 0) {
        printf("Pass\n");
        getDynastyName();

    } else if (strcmp(dynastyNameDecision, "n") == 0 || strcmp(dynastyNameDecision, "N") == 0 ||
               strcmp(dynastyNameDecision, "no") == 0 || strcmp(dynastyNameDecision, "No") == 0) {
        printf("Fail\n");
    } else {
        printf("Error\n");
    }
    return 0;
}

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

int confirmDynastyName(){
  char confirmDynastyNameInput[10];
  printf("Is this correct? (y/n): ");
  fgets(confirmDynastyNameInput, sizeof(confirmDynastyNameInput), stdin);


   // Remove the trailing newline character from the input
   size_t len = strlen(confirmDynastyNameInput);
    if (len > 0 && confirmDynastyNameInput[len - 1] == '\n') {
        confirmDynastyNameInput[len - 1] = '\0';
    }
  // TODO need to format this to not be so ugly
    if (strcmp(confirmDynastyNameInput, "y") == 0 || strcmp(confirmDynastyNameInput, "Y") == 0 ||
        strcmp(confirmDynastyNameInput, "yes") == 0 || strcmp(confirmDynastyNameInput, "Yes") == 0) {
        heroGenderCheck();
        printf("Pass\n");
    
    } else if (strcmp(confirmDynastyNameInput, "n") == 0 || strcmp(confirmDynastyNameInput, "N") == 0 ||
               strcmp(confirmDynastyNameInput, "no") == 0 || strcmp(confirmDynastyNameInput, "No") == 0) {
        printf("Fail\n");
        getDynastyName();
    } else {
        printf("You may have entered to many characters. Please Try Again\n");
    }
  
}
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
    } else {
        printf("Error\n");
    }
    return 0;
}


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
// This is function is huge. TODO figure out how to make it smaller
int getHeroHomeland(){
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
      showEmpyreaDescription();
      printf("Is Empyrea the country you hail from? (y/n): ");
      confirmHeroHomeLand();
      }
    else if(strcmp(heroOriginInput, "2") == 0 ||
    strcmp(heroOriginInput, "Wesward") == 0 ||
    strcmp(heroOriginInput, "wesward") == 0 ||
    strcmp(heroOriginInput, "WESTWARD") == 0){
      showWeswardDescription();
      printf("Is Wesward the country you hail from? (y/n): ");
      confirmHeroHomeLand();
    }
    else if(strcmp(heroOriginInput, "3") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0 ||
    strcmp(heroOriginInput, "magdalar") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0){
      showMagdalarDescription();
      printf("Is Magdalar the country you hail from? (y/n): ");
      confirmHeroHomeLand();
    }
    else if(strcmp(heroOriginInput, "4") == 0 ||
    strcmp(heroOriginInput, "Ashvadan") == 0 ||
    strcmp(heroOriginInput, "ashvadan") == 0 ||
    strcmp(heroOriginInput, "ASHVADAN") == 0){
      showAshvadanDescription();
      printf("Is Ashvadan the country you hail from? (y/n): ");
      confirmHeroHomeLand();
    }

    else if(strcmp(heroOriginInput, "5") == 0 ||
    strcmp(heroOriginInput, "Nadafia") == 0 ||
    strcmp(heroOriginInput, "nadafia") == 0 ||
    strcmp(heroOriginInput, "NADAFIA") == 0){
      showNadafiaDescription();
      printf("Is Nadafia the country you hail from? (y/n): ");
      confirmHeroHomeLand();
      }
    else{
      printf("Please make a valid decision \n");
    }
}

// This function is only here in the even that someone wants to pick a country without reading the descriptions again
int getHeroHomelandWithoutDescriptions(){
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
      // showEmpyreaDescription();
      printf("Is Empyrea the country you hail from? (y/n): ");
    // TODO ADD A FUNCTION TO CONFIRM THE HERO'S HOMELAND
      }
    else if(strcmp(heroOriginInput, "2") == 0 ||
    strcmp(heroOriginInput, "Wesward") == 0 ||
    strcmp(heroOriginInput, "wesward") == 0 ||
    strcmp(heroOriginInput, "WESTWARD") == 0){
      // showWeswardDescription();
      printf("Is Wesward the country you hail from? (y/n): ");
    }
    else if(strcmp(heroOriginInput, "3") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0 ||
    strcmp(heroOriginInput, "magdalar") == 0 ||
    strcmp(heroOriginInput, "Magdalar") == 0){
      // showMagdalarDescription();
      printf("Is Magdalar the country you hail from? (y/n): ");

    }
    else if(strcmp(heroOriginInput, "4") == 0 ||
    strcmp(heroOriginInput, "Ashvadan") == 0 ||
    strcmp(heroOriginInput, "ashvadan") == 0 ||
    strcmp(heroOriginInput, "ASHVADAN") == 0){
      // showAshvadanDescription();
      printf("Is Ashvadan the country you hail from? (y/n): ");
    }

    else if(strcmp(heroOriginInput, "5") == 0 ||
    strcmp(heroOriginInput, "Nadafia") == 0 ||
    strcmp(heroOriginInput, "nadafia") == 0 ||
    strcmp(heroOriginInput, "NADAFIA") == 0){
      // showNadafiaDescription();
      printf("Is Nadafia the country you hail from? (y/n): ");
    }
    else{
      printf("Please make a valid decision \n");
    }
}

int confirmHeroHomeLand(){
  char seeDescriptionsDecision[10];
  char seeDescriptionInput[10];
  char confirmHeroHomeLandInput[10];
  printf("Is this correct? (y/n): ");
  fgets(confirmHeroHomeLandInput, sizeof(confirmHeroHomeLandInput), stdin);

  if(strcmp(confirmHeroHomeLandInput, "y") == 0 ||
  strcmp(confirmHeroHomeLandInput, "Y") == 0 ||
  strcmp(confirmHeroHomeLandInput, "yes") == 0 ||
  strcmp(confirmHeroHomeLandInput, "Yes") == 0){
    // DO STUFF
  }
  else if(strcmp(confirmHeroHomeLandInput, "n") == 0 ||
  strcmp(confirmHeroHomeLandInput, "N") == 0 ||
  strcmp(confirmHeroHomeLandInput, "no") == 0 ||
  strcmp(confirmHeroHomeLandInput, "No") == 0){
    printf("Would you like to see the description of a country? (y/n): ");
    if(strcmp(seeDescriptionInput, "y") == 0 ||
    strcmp(seeDescriptionInput, "Y") == 0 ||
    strcmp(seeDescriptionInput, "yes") == 0 ||
    strcmp(seeDescriptionInput, "Yes") == 0 ){ 
      printf("Which country would you like to see the description of? \n");
      printf("1: Empyrea \n");
      printf("2: Wesward \n");
      printf("3: Magdalar \n");
      printf("4: Ashvadan \n");
      printf("5: Nadafia \n");
      fgets(seeDescriptionInput, sizeof(seeDescriptionInput), stdin);

      if(strcmp(seeDescriptionInput, "1") == 0 ||
      strcmp(seeDescriptionInput, "Empyrea") == 0 ||
      strcmp(seeDescriptionInput, "empyrea") == 0 ||
      strcmp(seeDescriptionInput, "EMPYERA") == 0){
        showEmpyreaDescription();
        getHeroHomelandWithoutDescriptions();
      }
      else if(strcmp(seeDescriptionInput, "2") == 0 ||
      strcmp(seeDescriptionInput, "Wesward") == 0 ||
      strcmp(seeDescriptionInput, "wesward") == 0 ||
      strcmp(seeDescriptionInput, "WESTWARD") == 0){
        showWeswardDescription();
        getHeroHomelandWithoutDescriptions();

      }
      else if(strcmp(seeDescriptionInput, "3") == 0 ||
      strcmp(seeDescriptionInput, "Magdalar") == 0 ||
      strcmp(seeDescriptionInput, "magdalar") == 0 ||
      strcmp(seeDescriptionInput, "Magdalar") == 0){
        showMagdalarDescription();
        getHeroHomelandWithoutDescriptions();
      }
      else if(strcmp(seeDescriptionInput, "4") == 0 ||
      strcmp(seeDescriptionInput, "Ashvadan") == 0 ||
      strcmp(seeDescriptionInput, "ashvadan") == 0 ||
      strcmp(seeDescriptionInput, "ASHVADAN") == 0){
        showAshvadanDescription();
        getHeroHomelandWithoutDescriptions();
      }
      else if(strcmp(seeDescriptionInput, "5") == 0 ||
      strcmp(seeDescriptionInput, "Nadafia") == 0 ||
      strcmp(seeDescriptionInput, "nadafia") == 0 ||
      strcmp(seeDescriptionInput, "NADAFIA") == 0){
        showNadafiaDescription();
        getHeroHomelandWithoutDescriptions();
      }
      else{
        printf("Please make a valid decision \n");
        getHeroHomeland();
      }
    }  
    else if(strcmp(seeDescriptionInput, "n") == 0 ||
    strcmp(seeDescriptionInput, "N") == 0 ||
    strcmp(seeDescriptionInput, "no") == 0 ||
    strcmp(seeDescriptionInput, "No") == 0 ){
// TODO COME BACK TO LATER FOR NOW IN THE EVENT OF NO THIS WILL JUST CRASH GAME
    }
  }
  else{
    printf("Please make a valid decision \n");
    confirmHeroHomeLand();
  }

}