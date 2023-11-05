// build a function that randomly generates an armor pickup(could be head, chest, or legs)
// build a function that randomly generates a weapon pickup. (could be sword, axe, mace, staff, bow, etc)
// build a function that says the hero has found an item. inside this function call all the others
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"
// Define structures for Armor types
// Arrays for possible armor names and added health values

char HeadArmorList[50][10][100] = {
    // 30 items, 10 attributes, 100 characters
    {"Adamantite Helm", "Sturdy and protective", "Head", "Uncommon", "0", "10", "30", "40"},
    {"Sylvan Hood", "Lightweight and flexible", "Head", "Common", "0", "5", "20", "25"},
    {"Chainmail Coif", "Artistry of the Forge Lords", "Head", "Rare", "0", "14", "50", "70"},
    {"Wizard's Hat", "Empowered by Arcane", "Head", "Uncommon", "20", "0", "70", "90"},
    {"Ranger's Hood", "Camouflaged Wildwood", "Head", "Common", "7", "0", "28", "40"},
    {"Paladin's Crown", "Blessed by Divine Light", "Head", "Uncommon", "0", "18", "60", "75"},
    {"Frost Barbarian Helm", "Helm of the Northlands", "Head", "Rare", "0", "16", "55", "65"},
    {"Shadow Veil", "Veil of Shadows", "Head", "Common", "4", "15", "0", "25"},
    {"Enchanted Tiara", "Mystic Enchantment", "Head", "Rare", "22", "0", "75", "90"},
    {"Tribal Feathered Headdress", "Tribal Spirit Feather", "Head", "Common", "0,"
                                                                              "9",
     "32", "45"},
    {"Eldritch Diadem", "Mystical headpiece", "Head", "Common", "15", "0", "45", "60"},
    {"Sylvan Hood", "Lightweight and flexible", "Head", "Common", "5", "0", "20", "25"},
    {"Dragonhide Helmet", "Scale of the Fire Drakes", "Head", "Rare", "0", "25", "90", "110"},
    {"Elven Circlet", "Elegance of the Woodlands", "Head", "Uncommon", "0", "8", "35", "50"},
    {"Dwarven Forged Helm", "Craftsmanship of the Mountain Folk", "Head", "Rare", "0", "12", "65", "75"},
    {"Mithril Cap", "Lightweight and durable", "Head", "Common", "0", "6", "25", "35"},
    {"Plague Alchemist Mask", "Protection from the Plague", "Head", "Common", "0", "13", "42", "55"},
    {"Warlock's Cowl", "Cursed Sorcerer's Hood", "Head", "Uncommon", "0", "19", "70", "90"},
    {"Pharaoh's Circlet", "Royal of the Sphinx Empire", "Head", "Rare", "0", "23", "85", "110"},
    {"Goblin Skullcap", "Crude Goblin Headpiece", "Head", "Common", "0", "2", "9", "15"},
    {"Troll Skull Helmet", "Trollforged Headgear", "Head", "Common", "0", "3", "7", "12"},
    {"Celestial Diadem", "Blessings from Celestial Realms", "Head", "Epic", "0", "30", "110", "140"},
    {"Pirate Bandana", "Pirate's Sea Scarf", "Head", "Uncommon", "0", "8", "40", "55"},
    {"Beholder's Gaze", "Eye-themed Mystic Helmet", "Head", "Epic", "0", "24", "95", "120"},
    {"Inferno Demon Helm", "Infernal Fiery Headgear", "Head", "Epic", "0", "28", "105", "130"},
    {"Ghostly Veil", "Veil of Spirits", "Head", "Rare", "0", "26", "100", "125"},
    {"Shadow Assassin Hood", "Assassin's Veil", "Head", "Uncommon", "0", "21", "80", "100"},
    {"Phoenix Crown", "Crown of the Firebird", "Head", "Epic", "0", "35", "130", "160"},
    {"Mystic Sentinel Helm", "Ancient Empire's Headpiece", "Head", "Rare", "0", "17", "60", "75"},
    {"Kraken's Helm", "Helm of the Deep Seas", "Head", "Epic", "0", "32", "120", "150"}};

int generate_head_armor()
{
    srand(time(NULL));

    int randomIndex;
    int itemGenerated = 0; // 0 = false, 1 = true

    for (int i = 0; i < 30; i++)
    {
        char *itemName = HeadArmorList[i][0];
        char *itemDesc = HeadArmorList[i][1];
        char *itemType = HeadArmorList[i][2];
        char *itemRarity = HeadArmorList[i][3];
        int itemDamageAdded = atoi(HeadArmorList[i][4]);
        int itemHealthAdded = atoi(HeadArmorList[i][5]);
        int itemWeight = atoi(HeadArmorList[i][6]);
        int itemValue = atoi(HeadArmorList[i][7]);

        if ((strcmp(HeadArmorList[i][3], "Common") == 0 ||
             strcmp(HeadArmorList[i][3], "Uncommon") == 0 ||
             strcmp(HeadArmorList[i][3], "Rare") == 0 ||
             strcmp(HeadArmorList[i][3], "Epic") == 0) &&
            itemGenerated == 0)
        {
            randomIndex = rand() % 30; // Randomly select an index within the range of available items
            if (strcmp(HeadArmorList[randomIndex][3], "Uncommon") == 0)
            {

                strcpy(itemName, HeadArmorList[randomIndex][0]);
                strcpy(itemDesc, HeadArmorList[randomIndex][1]);
                strcpy(itemType, HeadArmorList[randomIndex][2]);
                strcpy(itemRarity, HeadArmorList[randomIndex][3]);
                // TODO, CURRENTLY PASSING IN ITEM RARITY INTO THIS FUNCTION WHERE 'TYPE SHOULD GO.. REMEMEBER TO CHANGE THIS
                pick_up_item(itemName, itemDesc, itemType, itemRarity, itemDamageAdded, itemHealthAdded, itemWeight, itemValue);
                itemGenerated = 1;
            }

            else if (strcmp(HeadArmorList[randomIndex][3], "Common") == 0)
            {
                strcpy(itemName, HeadArmorList[randomIndex][0]);
                strcpy(itemDesc, HeadArmorList[randomIndex][1]);
                strcpy(itemType, HeadArmorList[randomIndex][2]);
                strcpy(itemRarity, HeadArmorList[randomIndex][3]);
                pick_up_item(itemName, itemDesc, itemType, itemRarity, itemDamageAdded, itemHealthAdded, itemWeight, itemValue);
                itemGenerated = 1; // Set itemGenerated to true
            }
            else if (strcmp(HeadArmorList[randomIndex][3], "Rare") == 0)
            {
                strcpy(itemName, HeadArmorList[randomIndex][0]);
                strcpy(itemDesc, HeadArmorList[randomIndex][1]);
                strcpy(itemType, HeadArmorList[randomIndex][2]);
                strcpy(itemRarity, HeadArmorList[randomIndex][3]);
                pick_up_item(itemName, itemDesc, itemType, itemRarity, itemDamageAdded, itemHealthAdded, itemWeight, itemValue);
                itemGenerated = 1; // Set itemGenerated to true
            }

            else if (strcmp(HeadArmorList[randomIndex][3], "Epic") == 0)
            {
                strcpy(itemName, HeadArmorList[randomIndex][0]);
                strcpy(itemDesc, HeadArmorList[randomIndex][1]);
                strcpy(itemType, HeadArmorList[randomIndex][2]);
                strcpy(itemRarity, HeadArmorList[randomIndex][3]);
                pick_up_item(itemName, itemDesc, itemType, itemRarity, itemDamageAdded, itemHealthAdded, itemWeight, itemValue);
                itemGenerated = 1; // Set itemGenerated to true
            }
            else
            {
                puts("You should not be seeing this...Turn back now");
                return 1;
            }
        }

        if (itemGenerated)
        {
            break; // Exit the loop after an item is printed
        }
    }
    return 0;
}
