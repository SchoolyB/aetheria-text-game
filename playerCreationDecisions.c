#include <stdbool.h> 
#include <stdio.h>
#include "setPlayerInfo.c"
#include "Perks.h"
#include "PlayerInfoAndStats.h"


// This function asks the player for their first name and confirms that they have entered it correctly. If they have not, the function is called again. If they have, the function ends.
int setPlayerFirstName(){
    bool playerHasFirstName; //does the player have a first name? true or false 
    char playerFirstName[20];
    char confirmPlayerFirstName;
    printf("What is your first name?\n");
    scanf("%s", playerFirstName);
    printf("Your first name is %s. Is this correct? (y/n)\n", playerFirstName);
    scanf(" %c", &confirmPlayerFirstName);

    if (confirmPlayerFirstName == 'n'){
      setPlayerFirstName(); // If the player does not confirm their name, the function is called again.
      playerHasFirstName = false;
    }

    else if (confirmPlayerFirstName == 'y'){
      printf("Welcome, %s\n", playerFirstName);
      playerHasFirstName = true;
    }

    else{
      printf("Please enter y or n\n");
      setPlayerFirstName();
    }
    return 0;
};

// This function asks the player if they come from a great house. If they do, they are asked to enter their house name. If they do not, they are asked to confirm that they do not come from a great house. If they do not confirm that they do not come from a great house, they are asked to enter their house name. If they do confirm that they do not come from a great house, the function ends.
int playerDynastyCheck(){
  bool playerHasDynasty; //does player come from a great house? true or false this is going to be a stat 
  char playerDynastyDecision;  //whether or not the player comes from a great house
  printf("Do you come from a great house? (y/n)\n");
  scanf(" %c", &playerDynastyDecision);
  if (playerDynastyDecision == 'y'){
    playerHasDynasty = true;
    printf("Ah so you do come from a great house Tell me more about it.\n");
    setPlayerDynastyName();  
  }
  else if(playerDynastyDecision == 'n'){
    char confirmNoGreatHouse;
    playerHasDynasty = false;
    printf("Are you sure that you do not come from a great house? \n");
    scanf(" %c", &confirmNoGreatHouse);

    if(confirmNoGreatHouse == 'y'){
      printf("Very well then. \n");
    }
    else if(confirmNoGreatHouse == 'n'){
      printf("Ah so you do come from a great house Tell me more about it.\n");
      setPlayerDynastyName();
  }
    else{
      printf("Please enter y or n\n");
      playerDynastyCheck();
  }
  }
}

// this function asks the player to enter their house name and confirms that they have entered it correctly. If they have not, the function is called again. If they have, the function ends.
int setPlayerDynastyName(){
  char playerDynastyName[20]; //the name of the player's house
  char confirmPlayerDynastyName; //whether or not the player confirms their house name

  printf("Please tell me your house's name. \n");
  scanf("%s", playerDynastyName); //player enters their house name
  printf("Your house name is %s. Is this correct? (y/n)\n", playerDynastyName);
  scanf(" %c", &confirmPlayerDynastyName); //player confirms their house name

  if (confirmPlayerDynastyName == 'y'){
    printf("Very well then. \n");
    setPlayerOrigin();
  }
  else if(confirmPlayerDynastyName == 'n'){
    setPlayerDynastyName();
  }
  else{
    printf("Please enter y or n\n");
    setPlayerDynastyName();
  }
}

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
  int playerAge;
  bool young_age_player; 
  bool average_age_player;
  bool old_age_player;

  printf("How old are you?\n");
  scanf(" %d", &playerAge);
  printf("You are %d years old. Is this correct? (y/n)\n", playerAge);
  
  scanf(" %c", &confirmPlayerAge);
  if(confirmPlayerAge == 'n'){
    setPlayerAge();
  }
  else if(confirmPlayerAge == 'y'){
    playerHasAge = true;
    setPlayerProfession();
  }
  else{
    printf("Please enter y or n\n");
    setPlayerAge();
  }
  
  
  if(playerAge >= 18 && playerAge <= 25){
    young_age_player = true;
    average_age_player = false;
    old_age_player = false;
  }
  else if(playerAge >= 26 && playerAge <= 40){
    young_age_player = false;
    average_age_player = true;
    old_age_player = false;
  }
  else if(playerAge >= 41 && playerAge <= 60){
    young_age_player = false;
    average_age_player = false;
    old_age_player = true;
  }
  else{
    printf("Please enter a valid age.\n");
    setPlayerAge();
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

  printf("What is your profession?\n");
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
        solidifyPlayerInfo();
      }

      break;
    default:
      printf("Please enter a valid choice\n");
      setPlayerProfession();
  }

}

