#ifndef MACROS_H
#define MACROS_H

//?++++++++++++++++++++++++START OF MACROS++++++++++++++++++++++++?//
// This macro is used to make sure the user enters a valid decision
#define MAKE_VALID_DECISION printf("Please make a valid decision\n")

// This macro is used to check if the user input is yes
#define IS_YES(param) (strcmp(param, "y") == 0 || strcmp(param, "Y") == 0 || \
                       strcmp(param, "yes") == 0 || strcmp(param, "Yes") == 0)

// This macro is used to check if the user input is no
#define IS_NO(param) (strcmp(param, "n") == 0 || strcmp(param, "N") == 0 || \
                      strcmp(param, "no") == 0 || strcmp(param, "No") == 0)

//! IMPORTANT ! This macro is used to remove the newline character from the input
#define REMOVE_NEWLINE_CHARACTER(param)    \
  do                                       \
  {                                        \
    size_t len = strlen(param);            \
    if (len > 0 && param[len - 1] == '\n') \
    {                                      \
      param[len - 1] = '\0';               \
    }                                      \
  } while (0)


// TODO add comments explaining these macros
  #define CHOOSE_STRENGTH(param)(strcmp(param, "strength") == 0 )
  #define CHOOSE_INTELLIGENCE(param)(strcmp(param, "Intelligence") == 0 )
  #define CHOOSE_DEXTERITY(param)(strcmp(param, "strength") == 0 )
  #define CHOOSE_LUCK(param)(strcmp(param, "Luck") == 0 )



//this macro will add whatever number the suer enters for a skill,,,amount is user input, param is the skill, num is either 1,2,3,4. All skills cap @ 4
#define ALLOCATION(amount, param, num) \
    if (amount == num) { \
        printf("you entered %d\n", num); \
        param = param + num; \
        printf("The hero strength is %d \n", param); \
    }
//?++++++++++++++++++++++++END OF MACROS++++++++++++++++++++++++?//

#endif