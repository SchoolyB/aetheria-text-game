#include <stdbool.h> 
#include <stdio.h>
#include "setPlayerInfo.c"
#include "./headers/Perks.h"
#include "./headers/PlayerInfoAndStats.h"


// This function asks the player for their first name and confirms that they have entered it correctly. If they have not, the function is called again. If they have, the function ends.
int setPlayerFirstName(){
    bool playerHasFirstName; //does the player have a first name? true or false 
    char playerFirstName[12];
    char confirmPlayerFirstName;
    printf("What is your first name?\n");
    scanf("%s", playerFirstName);
    printf("Your first name is %s. Is this correct? (y/n)\n", playerFirstName);
    scanf(" %c", &confirmPlayerFirstName);

    switch(confirmPlayerFirstName){
      case 'y':
        playerHasFirstName = true;
        printf("Very well then %s\n", playerFirstName);
        break;
      case 'n':
        playerHasFirstName = false;
        setPlayerFirstName();
        break;
        default:
        printf("Please enter y or n\n");
        setPlayerFirstName();
    }
    return 0;
};

// This function asks the player if they come from a great house. If they do, they are asked to enter their house name. If they do not, they are asked to confirm that they do not come from a great house. If they do not confirm that they do not come from a great house, they are asked to enter their house name. If they do confirm that they do not come from a great house, the function ends.
int playerDynastyCheck(playerFirstName){
  bool playerHasDynasty; //does player come from a great house? true or false this is going to be a stat 
  char playerDynastyDecision;  //whether or not the player comes from a great house
  char confirmNoGreatHouse;
  printf("Do you come from a great house? (y/n)\n");
  scanf(" %c", &playerDynastyDecision);

switch(playerDynastyDecision){
  case 'y':
    bool playerHasDynasty;
    char confirmPlayerDynastyName; //whether or not the player confirms their house name
    char playerDynastyName[20]; //the name of the player's house
    printf("Ah so you do come from a great house Tell me more about it.\n");
    printf("Please tell me your house's name. \n");
    scanf("%s", playerDynastyName); //player enters their house name
    printf("So you hail from house %s. Is this correct? (y/n)\n", playerDynastyName);
    scanf(" %c", &confirmPlayerDynastyName); //player confirms their house name
    
    switch(confirmPlayerDynastyName){
      case 'y':
        printf("Very well then. \n");
        playerHasDynasty = true;
        setPlayerOrigin();
        break;
      case 'n':
        playerDynastyCheck();
        break;
        default:
        printf("Please enter y or n\n");
        playerDynastyCheck();
    }
    break;
  case 'n':
    printf("Are you sure that you do not come from a great house? (y/n) \n");
    scanf(" %c", &confirmNoGreatHouse);
      if(confirmNoGreatHouse == 'y'){
        printf("Very well then\n");
        playerHasDynasty = false;
        setPlayerOrigin();
        }
      else if(confirmNoGreatHouse == 'n'){  
        playerDynastyCheck();
      }
    break;
    default:
    printf("Please enter y or n\n");
    playerDynastyCheck();
  }
}

// This function asks the player for their continent of origin and confirms that they have entered it correctly. If they have not, the function is called again. If they have, the function ends.
int setPlayerOrigin(){
  char playerOriginDecision;
  char possibleOrigins[5][20]  = {
    "A: Nordorard",
    "B: Ashar-Borlach",
    "C: Sudvich",
    "D: Raelia",
    "E: Cazidor"
    };

  printf("What is your continent of origin?\n");
  for (int i = 0; i < 5; i++){ // prints out the possible origins for the player to choose from
    printf("%s\n", possibleOrigins[i]);
  }

// Gets the player's choice for their continent of origin
 scanf(" %c", &playerOriginDecision);

//This switch evaluates the player's choice and prints out the name of the continent that they chose. 
 switch (playerOriginDecision){
  case 'a':
    printf("You are from Nordorard\n");
    break;
  case 'b':
    printf("You are from Al-Ashar\n");
    break;
  case 'c':
    printf("You are from Sudvich\n");
    break;
  case 'd':
    printf("You are from Raelia\n");
    break;
  case 'e':
    printf("You are from Cazidor\n");
    break;
    default:
    printf("Please enter a valid choice\n");
    setPlayerOrigin();
 }
printf("Is this correct? (y/n)\n");
confirmPlayerOrigin();
}

// This function confirms that the player has entered their continent of origin correctly. If they have not, the function is called again. If they have, the function ends.
int confirmPlayerOrigin(){
bool playerHasOrigin; //does the player come from a continent? true or false
char confirmPlayerOriginDecision;

scanf(" %c", &confirmPlayerOriginDecision);
if (confirmPlayerOriginDecision == 'n'){
  playerHasOrigin = false;
  setPlayerOrigin();
}
else if (confirmPlayerOriginDecision == 'y'){
  playerHasOrigin = true;
  printf("Very well then.\n");
  setPlayerAge();
  // printf("tests");
}
}

// This function asks the player for their age and confirms that they have entered it correctly. If they have not, the function is called again. If they have, the function ends.
int setPlayerAge(){
  bool playerHasAge; 
  char confirmPlayerAge;
  int  playerAge;
  bool playerAgeIs21; 
  bool playerAgeIs30;
  bool playerAgeIs50;

  printf("How old are you? (21/30/50)\n");
  scanf(" %d", &playerAge);
  printf("You are %d years old. Is this correct? (y/n)\n", playerAge);

  scanf(" %c", &confirmPlayerAge);
  if(confirmPlayerAge == 'n'){
    setPlayerAge();
  }
  else if(confirmPlayerAge == 'y'){
    playerHasAge = true;
    printf("%d\n" , playerAge);
    setPlayerProfession();
  }
  else{
    printf("Please enter y or n\n");
    setPlayerAge();
  }
  switch(playerAge){
    case 21:
      playerAgeIs21 = true;
      playerAgeIs30 = false;
      playerAgeIs50 = false;
      break;
    case 30:
      playerAgeIs21 = false;
      playerAgeIs30 = true;
      playerAgeIs50 = false;
      break;
    case 50:
      playerAgeIs21 = false;
      playerAgeIs30 = false;
      playerAgeIs50 = true;
      break;  
  }
}

// PLAYER PROFESSION STUFF
int setPlayerProfession(){
  bool playerHasProfession;
  bool isSoldier;
  bool isMerchant;
  bool isFarmer;
  char playersProfession;
  char confirmPlayerProfession;
  char starterProfession[3][10] = {
    "A: Soldier",
    "B: Merchant",
    "C: Farmer"
  };


  // TODO FIGURE OUT HOW TO MAKE THIS PRINT OUT IN A COLUMN
  printf("What is your profession?\n");
  for (int i = 0; i < 3; i++){ // prints out the possible origins for the player to choose from
    printf("%s\n ", starterProfession[i]);
  }
  scanf(" %c", &playersProfession);
  switch(playersProfession){
    case 'a':
      printf("You are a soldier\n");
      printf("Is this correct? (y/n)\n");

      scanf(" %c", &confirmPlayerProfession);

      if(confirmPlayerProfession == 'n'){
        setPlayerProfession();
      }
      else if(confirmPlayerProfession == 'y'){
        playerHasProfession = true;
        isSoldier = true;
        setSoldierPerks(); //see setPerks.c for this function and Perks.h for the structs
      }
      break;

    case 'b':
      printf("You are a merchant\n");
      printf("Is this correct? (y/n)\n");

      scanf(" %c", &confirmPlayerProfession);

      if(confirmPlayerProfession == 'n'){
        setPlayerProfession();
      }
      else if(confirmPlayerProfession == 'y'){
        playerHasProfession = true;
        isMerchant = true;
        setMerchantPerks(); //see setPerks.c for this function and Perks.h for the structs
      }
      else{
        printf("Please enter y or n\n");
        setPlayerProfession();
      }
      break;

    case 'c':
      printf("You are a farmer\n");
      printf("Is this correct? (y/n)\n");

      scanf(" %c", &confirmPlayerProfession);

      if(confirmPlayerProfession == 'n'){
        setPlayerProfession();
      }
      else if(confirmPlayerProfession == 'y'){
        playerHasProfession = true;
        isFarmer = true;
        setFarmerPerks(); //see setPerks.c for this function and Perks.h for the structs
        // solidifyPlayerInfo();
      }

      break;
    default:
      printf("Please enter a valid choice\n");
      setPlayerProfession();
  }
}