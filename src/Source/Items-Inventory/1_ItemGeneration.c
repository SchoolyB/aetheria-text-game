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
    {"Adamantite Helm", "Sturdy and protective", "Uncommon", "10", "30", "40"},
    {"Sylvan Hood", "Lightweight and flexible", "Common", "5", "20", "25"},
    {"Chainmail Coif", "Artistry of the Forge Lords", "Rare", "14", "50", "70"},
    {"Wizard's Hat", "Empowered by Arcane", "Uncommon", "20", "70", "90"},
    {"Ranger's Hood", "Camouflaged Wildwood", "Common", "7", "28", "40"},
    {"Paladin's Crown", "Blessed by Divine Light", "Uncommon", "18", "60", "75"},
    {"Frost Barbarian Helm", "Helm of the Northlands", "Rare", "16", "55", "65"},
    {"Shadow Veil", "Veil of Shadows", "Common", "4", "15", "25"},
    {"Enchanted Tiara", "Mystic Enchantment", "Rare", "22", "75", "90"},
    {"Tribal Feathered Headdress", "Tribal Spirit Feather", "Common", "9", "32", "45"},
    {"Eldritch Diadem", "Mystical headpiece", "Common", "15", "45", "60"},
    {"Sylvan Hood", "Lightweight and flexible", "Common", "5", "20", "25"},
    {"Dragonhide Helmet", "Scale of the Fire Drakes", "Rare", "25", "90", "110"},
    {"Elven Circlet", "Elegance of the Woodlands", "Uncommon", "8", "35", "50"},
    {"Dwarven Forged Helm", "Craftsmanship of the Mountain Folk", "Rare", "12", "65", "75"},
    {"Mithril Cap", "Lightweight and durable", "Common", "6", "25", "35"},
    {"Plague Alchemist Mask", "Protection from the Plague", "Common", "13", "42", "55"},
    {"Warlock's Cowl", "Cursed Sorcerer's Hood", "Uncommon", "19", "70", "90"},
    {"Pharaoh's Circlet", "Royal of the Sphinx Empire", "Rare", "23", "85", "110"},
    {"Goblin Skullcap", "Crude Goblin Headpiece", "Common", "2", "9", "15"},
    {"Troll Skull Helmet", "Trollforged Headgear", "Common", "3", "7", "12"},
    {"Celestial Diadem", "Blessings from Celestial Realms", "Epic", "30", "110", "140"},
    {"Pirate Bandana", "Pirate's Sea Scarf", "Uncommon", "8", "40", "55"},
    {"Beholder's Gaze", "Eye-themed Mystic Helmet", "Epic", "24", "95", "120"},
    {"Inferno Demon Helm", "Infernal Fiery Headgear", "Epic", "28", "105", "130"},
    {"Ghostly Veil", "Veil of Spirits", "Rare", "26", "100", "125"},
    {"Shadow Assassin Hood", "Assassin's Veil", "Uncommon", "21", "80", "100"},
    {"Phoenix Crown", "Crown of the Firebird", "Epic", "35", "130", "160"},
    {"Mystic Sentinel Helm", "Ancient Empire's Headpiece", "Rare", "17", "60", "75"},
    {"Kraken's Helm", "Helm of the Deep Seas", "Epic", "32", "120", "150"}};
void generate_head_armor()
{
    srand(time(NULL));
    for (int i = 0; i < 47; i++)
    {
        int itemHealthAdded = atoi(HeadArmorList[i][3]);
        int itemWeight = atoi(HeadArmorList[i][4]);
        int itemValue = atoi(HeadArmorList[i][5]);

        // printf("Name: %s, Desc: %s, Rarity: %s, Health Added: %d, Weight: %d, Value: %d\n", HeadArmorList[i][0], HeadArmorList[i][1], HeadArmorList[i][2], itemHealthAdded, itemWeight, itemValue); // prints array
        if (strcmp(HeadArmorList[i][2], "Common") == 0)
        {
            int random = rand() % 10;
            // Generate a random index within the range of Common head armor items
            // printf("Common Head Armor: %s\n", HeadArmorList[random][0]); // Print the name of the randomly selected item
        }
        else if (strcmp(HeadArmorList[i][2], "Uncommon") == 0)
        {
            int random = rand() % 7;
        }
        else if (strcmp(HeadArmorList[i][2], "Rare") == 0)
        {
            int random = rand() % 9;
        }
        else if (strcmp(HeadArmorList[i][2], "Epic") == 0)
        {
            int random = rand() % 5;
        }
    }
}
// Function to generate random armor pickup