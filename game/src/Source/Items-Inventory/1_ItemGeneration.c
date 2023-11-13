#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Items-Inventory.h"
#include "../../Utils/Utils.h"

Hero hero;
// START OF WEAPON GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
//===============================================================================//
char WeaponList[50][10][100] = {
    {"Excalibur", "The legendary sword of King Arthur", "Weapon", "Legendary", "50", "0", "0", "100"},
    {"Stormbringer", "A dark and cursed blade", "Weapon", "Epic", "40", "0", "0", "90"},
    {"Dragonfang Blade", "Forged from a dragon's tooth", "Weapon", "Rare", "30", "0", "0", "70"},
    {"Frostreaver", "Infused with the power of ice", "Weapon", "Epic", "45", "0", "0", "95"},
    {"Serpent's Kiss", "Venomous dagger with a deadly bite", "Weapon", "Rare", "35", "0", "0", "75"},
    {"Warhammer of the Titans", "A colossal hammer of titanic strength", "Weapon", "Epic", "60", "0", "0", "110"},
    {"Elven Longbow", "Crafted by the finest elven archers", "Weapon", "Rare", "40", "0", "0", "80"},
    {"Mjölnir", "The mighty hammer of Thor", "Weapon", "Legendary", "55", "0", "0", "105"},
    {"Doombringer", "A sword that brings doom to its foes", "Weapon", "Epic", "48", "0", "0", "98"},
    {"Staff of Arcane Power", "Empowered with ancient magic", "Weapon", "Rare", "38", "0", "0", "78"},
    {"Soulrender", "A sword that steals the souls of its victims", "Weapon", "Epic", "47", "0", "0", "97"},
    {"Bow of the Celestial Archer", "Blessed by celestial deities", "Weapon", "Rare", "42", "0", "0", "82"},
    {"Dagger of Shadows", "Cloaked in dark and elusive shadows", "Weapon", "Epic", "36", "0", "0", "76"},
    {"Scorchblade", "A blade that burns with eternal fire", "Weapon", "Epic", "50", "0", "0", "100"},
    {"Sword of the Phoenix", "Forged from phoenix feathers", "Weapon", "Rare", "44", "0", "0", "84"},
    {"Waraxe of the Barbarian King", "The weapon of a savage ruler", "Weapon", "Epic", "52", "0", "0", "102"},
    {"Enchanted Flute", "An enchanted musical weapon", "Weapon", "Rare", "35", "0", "0", "75"},
    {"Grim Scythe", "The reaper's deadly harvest tool", "Weapon", "Epic", "49", "0", "0", "99"},
    {"Sword of Justice", "A weapon for the champions of justice", "Weapon", "Rare", "41", "0", "0", "81"},
    {"Thunderstrike Warhammer", "Strikes with the fury of a thunderstorm", "Weapon", "Epic", "57", "0", "0", "107"},
    {"Whispering Bow", "Silent and deadly, a bow for assassins", "Weapon", "Rare", "39", "0", "0", "79"},
    {"Venomous Fang Dagger", "Infused with deadly snake venom", "Weapon", "Epic", "46", "0", "0", "96"},
    {"Blazing Inferno Blade", "Burns with the flames of hell", "Weapon", "Epic", "53", "0", "0", "103"},
    {"Warstaff of the Archmage", "A staff for master spellcasters", "Weapon", "Rare", "43", "0", "0", "83"},
    {"Sword of the Dark Moon", "Wields the power of the lunar eclipse", "Weapon", "Epic", "45", "0", "0", "95"},
    {"Scepter of the Celestial King", "Holds the power of celestial rulers", "Weapon", "Legendary", "58", "0", "0", "108"},
    {"Starfall Bow", "Shoots arrows formed from falling stars", "Weapon", "Rare", "37", "0", "0", "77"},
    {"Blade of the Bloodmoon", "Cuts through the night with crimson power", "Weapon", "Epic", "51", "0", "0", "101"},
    {"Staff of Eternal Wisdom", "A staff that holds the wisdom of ages", "Weapon", "Rare", "40", "0", "0", "80"},
    {"Abyssal Trident", "Forged in the depths of the abyss", "Weapon", "Epic", "55", "0", "0", "105"},
    {"Sword of the Eldritch", "Infused with eldritch enchantments", "Weapon", "Epic", "48", "0", "0", "98"},
    {"Axe of Doom", "An axe that brings destruction to foes", "Weapon", "Rare", "42", "0", "0", "82"},
    {"Scepter of the Frozen Throne", "Frozen scepter of an ancient ruler", "Weapon", "Legendary", "60", "0", "0", "110"},
    {"Berserker's Warblade", "Wielded by fierce berserker warriors", "Weapon", "Epic", "52", "0", "0", "102"},
    {"Wand of Enchantment", "Wand that enchants with magic spells", "Weapon", "Rare", "38", "0", "0", "78"},
    {"The Reaper's Scythe", "Harvests souls for the reaper", "Weapon", "Epic", "56", "0", "0", "106"},
    {"Sword of the Ancient Kings", "A weapon of long-lost monarchs", "Weapon", "Rare", "41", "0", "0", "81"},
    {"Warhammer of Thunderclap", "Strikes like a thunderclap", "Weapon", "Epic", "54", "0", "0", "104"},
    {"Eldertree Bow", "Made from the wood of an ancient eldertree", "Weapon", "Rare", "39", "0", "0", "79"},
    {"Venomous Serpentblade", "A blade that delivers venomous strikes", "Weapon", "Epic", "47", "0", "0", "97"},
    {"Blazing Sunblade", "Burns with the power of the sun", "Weapon", "Epic", "58", "0", "0", "108"},
    {"Staff of the Moonlit Enchanter", "Wields the magic of moonlight", "Weapon", "Rare", "43", "0", "0", "83"}};

void generate_weapon()
{
    generate_item(WeaponList);
}
// END OF WEAPON GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
//===============================================================================//

//===============================================================================//
// START OF HEAD ARMOR GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
char HeadArmorList[50][10][100] = {
    // 30 items, 10 attributes, 100 characters
    // Name, Desc, Type, Rarity, Damage Added, Health Added, Weight, Value
    {"Adamantite Helm", "Sturdy and protective", "Head", "Uncommon", "0", "10", "30", "40"},
    {"Sylvan Hood", "Lightweight and flexible", "Head", "Common", "0", "5", "20", "25"},
    {"Chainmail Coif", "Artistry of the Forge Lords", "Head", "Rare", "0", "14", "50", "70"},
    {"Wizard's Hat", "Empowered by Arcane", "Head", "Uncommon", "20", "0", "70", "90"},
    {"Ranger's Hood", "Camouflaged Wildwood", "Head", "Common", "7", "0", "28", "40"},
    {"Paladin's Crown", "Blessed by Divine Light", "Head", "Uncommon", "0", "18", "60", "75"},
    {"Frost Barbarian Helm", "Helm of the Northlands", "Head", "Rare", "0", "16", "55", "65"},
    {"Shadow Veil", "Veil of Shadows", "Head", "Common", "4", "15", "0", "25"},
    {"Enchanted Tiara", "Mystic Enchantment", "Head", "Rare", "22", "0", "75", "90"},
    {"Tribal Feathered Headdress", "Tribal Spirit Feather", "Head", "Common", "0,", "9", "32", "45"},
    {"Eldritch Diadem", "Mystical headpiece", "Head", "Common", "0", "15", "45", "60"},
    {"Sylvan Hood", "Lightweight and flexible", "Head", "Common", "0", "5", "20", "25"},
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

void generate_head_armor()
{
    generate_item(HeadArmorList);
}
// END OF HEAD ARMOR GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
//===============================================================================//

//===============================================================================//
// START OF CHEST ARMOR GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
char ChestArmorList[50][10][100] = {
    // Name, Desc, Type, Rarity, Damage Added, Health Added, Weight, Value
    {"Dragonscale Plate Armor", "Forged from dragon scales", "Chest", "Uncommon", "0", "45", "100", "120"},
    {"Elven Leafweave Tunic", "Woven by forest elves", "Chest", "Common", "0", "20", "50", "60"},
    {"Phoenix Feathered Robes", "Blessed by the firebird", "Chest", "Rare", "0", "70", "140", "170"},
    {"Sorcerer's Arcane Garb", "Infused with arcane energy", "Chest", "Uncommon", "30", "15", "60", "80"},
    {"Celestial Guardian Plate", "Gifted by celestial beings", "Chest", "Rare", "0", "75", "160", "190"},
    {"Dwarven Forgeguard Cuirass", "Crafted in the mountain halls", "Chest", "Rare", "0", "55", "125", "150"},
    {"Mystic Ethereal Robes", "Enchanted with ethereal magic", "Chest", "Uncommon", "25", "20", "50", "65"},
    {"Kraken's Abyssal Shell", "Forged in the deep sea abyss", "Chest", "Epic", "0", "90", "180", "220"},
    {"Warrior of Valhalla Plate", "Worn by Valhalla's champions", "Chest", "Epic", "0", "85", "170", "210"},
    {"Elven Starweave Garb", "Woven with starlight threads", "Chest", "Uncommon", "0", "30", "70", "85"},
    {"Ancient Eldritch Vestment", "Ancient and eldritch", "Chest", "Rare", "0", "65", "130", "160"},
    {"Beholder's All-Seeing Robes", "Adorned with beholder eyes", "Chest", "Epic", "0", "80", "160", "200"},
    {"Moonshadow Assassin Armor", "Concealed in moonshadow", "Chest", "Rare", "0", "50", "115", "140"},
    {"Paladin's Divine Cuirass", "Blessed by divine power", "Chest", "Uncommon", "0", "55", "110", "130"},
    {"Plague Doctor's Attire", "Worn by plague healers", "Chest", "Common", "0", "25", "55", "70"},
    {"Shadowfiend's Cloak", "Infused with shadow magic", "Chest", "Rare", "0", "70", "150", "180"},
    {"Valkyrie Battleplate", "Worn by Valkyries of legend", "Chest", "Epic", "0", "90", "180", "220"},
    {"Titanium Guardian Chestpiece", "Crafted from titanium", "Chest", "Uncommon", "0", "40", "90", "110"},
    {"Feywild Warder Robes", "Woven from the Feywild's essence", "Chest", "Rare", "0", "75", "140", "170"},
    {"Demonlord's Infernal Plate", "Forged in the depths of hell", "Chest", "Epic", "0", "85", "170", "210"},
    {"Starfall Celestial Armor", "Crafted from starfall shards", "Chest", "Epic", "0", "100", "190", "230"},
    {"Grim Reaper's Cloak", "Worn by the harbingers of death", "Chest", "Rare", "0", "60", "130", "160"},
    {"Forest Guardian's Barkplate", "Infused with ancient forest magic", "Chest", "Uncommon", "0", "45", "95", "115"},
    {"Dragonrider's Scales", "Worn by those who ride dragons", "Chest", "Epic", "0", "95", "190", "230"},
    {"Archmage's Arcane Robes", "Worn by master spellcasters", "Chest", "Rare", "0", "70", "140", "170"},
    {"Necromancer's Deathshroud", "Infused with necromantic power", "Chest", "Uncommon", "0", "35", "75", "90"},
    {"Starforge Celestial Plate", "Forged in the heart of a star", "Chest", "Epic", "0", "110", "200", "240"},
    {"Ancient Runekeeper Vestment", "Inscribed with ancient runes", "Chest", "Rare", "0", "65", "130", "160"},
    {"Leviathan's Oceanic Armor", "Crafted from leviathan scales", "Chest", "Epic", "0", "100", "190", "230"}};

void generate_chest_armor()
{
    generate_item(ChestArmorList);
}
// END OF CHEST ARMOR GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
//===============================================================================//

//===============================================================================//
// START OF LEG ARMOR GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
char LegArmorList[50][10][100] = {
    {"Dragonscale Legguards", "Forged from ancient dragon scales", "Legs", "Epic", "0", "50", "110", "130"},
    {"Elven Shadowweave Leggings", "Woven with eldritch shadow", "Legs", "Rare", "0", "25", "60", "75"},
    {"Abyssal Demon Greaves", "Forged in the depths of the abyss", "Legs", "Epic", "0", "70", "140", "170"},
    {"Mage's Astral Legwraps", "Infused with astral magic", "Legs", "Uncommon", "20", "10", "45", "60"},
    {"Cursed Phantom Legplates", "Empowered by restless spirits", "Legs", "Rare", "0", "40", "80", "100"},
    {"Golemheart Iron Legguards", "Crafted with golem heartstones", "Legs", "Epic", "0", "60", "120", "140"},
    {"Feywild Enchanter's Leggings", "Woven from the Feywild's essence", "Legs", "Uncommon", "0", "30", "70", "85"},
    {"Abyssal Shadow Dancer Leggings", "Dancing through abyssal shadows", "Legs", "Epic", "0", "80", "160", "200"},
    {"Warlord's Battleplate Greaves", "Worn by warlord conquerors", "Legs", "Epic", "0", "75", "150", "180"},
    {"Spectral Wraith Legwraps", "Worn by spectral wraiths", "Legs", "Rare", "0", "45", "95", "115"},
    {"Titanium Plate Legguards", "Crafted from reinforced titanium", "Legs", "Uncommon", "0", "40", "90", "110"},
    {"Forest Guardian Legplates", "Infused with ancient forest magic", "Legs", "Rare", "0", "60", "130", "160"},
    {"Inferno Demon Infernal Leggings", "Forged in infernal flames", "Legs", "Epic", "0", "70", "140", "170"},
    {"Phoenix Feathered Trousers", "Woven from sacred firebird feathers", "Legs", "Epic", "0", "85", "170", "210"},
    {"Paladin's Divine Legplates", "Blessed by divine light", "Legs", "Uncommon", "0", "50", "110", "130"},
    {"Plague Doctor's Plagueproof Pants", "Protection from deadly plagues", "Legs", "Common", "0", "35", "75", "90"},
    {"Shadowfiend's Shadow Mantle", "Infused with malevolent shadowfiend essence", "Legs", "Rare", "0", "70", "150", "180"},
    {"Valkyrie Valkyric Greaves", "Worn by the fearless Valkyries", "Legs", "Epic", "0", "90", "180", "220"},
    {"Frostforged Barbarian Legplates", "Forged in the icy realms of the north", "Legs", "Rare", "0", "65", "130", "160"},
    {"Celestial Celestial Greaves", "Gifted by benevolent celestial beings", "Legs", "Epic", "0", "100", "190", "230"},
    {"Kraken Krakenhide Legguards", "Crafted from impenetrable krakenhide", "Legs", "Epic", "0", "95", "180", "220"},
    {"Warlock's Warlock Robes", "Cloaked in sorcerer's attire", "Legs", "Uncommon", "0", "60", "120", "140"},
    {"Beholder's Eye-Cloaked Pants", "Cloaked in the eyes of the beholder", "Legs", "Epic", "0", "85", "170", "210"},
    {"Shadow Assassin Stealth Leggings", "Worn by stealthy assassins", "Legs", "Rare", "0", "50", "110", "130"},
    {"Starfall Starlight Legwraps", "Woven with starfall starlight threads", "Legs", "Uncommon", "0", "30", "70", "85"},
    {"Ancient Runekeeper Legplates", "Inscribed with ancient mystic runes", "Legs", "Rare", "0", "55", "120", "140"},
    {"Leviathan Leviathanhide Legguards", "Crafted from formidable leviathanhide", "Legs", "Epic", "0", "90", "180", "220"},
    {"Ghostly Ethereal Leggings", "Infused with ethereal ghostly essence", "Legs", "Rare", "0", "70", "150", "180"}};

void generate_leg_armor()
{
    generate_item(LegArmorList);
}
// END OF LEG ARMOR GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
//===============================================================================//

//===============================================================================//
// START OF CONSUMABLE ITEM GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
char ConsumableItemList[50][10][100] = {
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Uncommon", "0", "75", "0", "30"},
    {"Potion of Max Healing", "Heal All of The Heros health", "Consumable", "Rare", "0", "25", "0", "50"},
    {"Daal's Grace", "Increase your damage by 5", "Consumable", "Uncommon", "5", "0", "0", "13"},
    {"Elixir of Steel", "Increase your damage by 20", "Consumable", "Rare", "20", "0", "0", "30"},
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Rare", "0", "75", "0", "30"},
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Rare", "0", "75", "0", "30"},
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Uncommon", "0", "75", "0", "30"},
    {"Potion of Max Healing", "Heal All of The Heros health", "Consumable", "Rare", "0", "25", "0", "50"},
    {"Daal's Grace", "Increase your damage by 5", "Consumable", "Uncommon", "5", "0", "0", "13"},
    {"Elixir of Steel", "Increase your damage by 20", "Consumable", "Rare", "20", "0", "0", "30"},
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Rare", "0", "75", "0", "30"},
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Rare", "0", "75", "0", "30"},
    {"Potion of Minor Healing", "Heal 1/4 of The Heros health", "Consumable", "Common", "0", "25", "0", "10"},
    {"Potion of Humble Healing", "Heal 1/2 of The Heros health", "Consumable", "Uncommon", "0", "50", "0", "20"},
    {"Potion of Grand Healing", "Heal 3/4 of The Heros health", "Consumable", "Uncommon", "0", "75", "0", "30"},
    {"Potion of Max Healing", "Heal All of The Heros health", "Consumable", "Rare", "0", "25", "0", "50"},
    {"Daal's Grace", "Increase your damage by 5", "Consumable", "Uncommon", "5", "0", "0", "13"}};
// TODO need to add in mana potions. This means I need to add in a member called 'manaAdded'to the Item struct
void generate_consumable_item()
{
    generate_item(ConsumableItemList);
}
// END OF CONSUMABLE ITEM GENERATION. FOR LOGIC SEE generate_item() FUNCTION BELOW
//===============================================================================//
// this is all the logic that is used to generate items. It is used in the above functions. pass in the appropriate array to generate the items example: generate_item(HeadArmorList);
int generate_item(char ItemList[50][10][100])
{
    srand(time(NULL));

    int randomIndex;
    int itemGenerated = 0;

    for (int i = 0; i < 30; i++)
    {
        int randomIndex = rand() % 30;
        char *itemName = ItemList[randomIndex][0];
        char *itemDesc = ItemList[randomIndex][1];
        char *itemType = ItemList[randomIndex][2];
        char *itemRarity = ItemList[randomIndex][3];
        int itemDamageAdded = atoi(ItemList[randomIndex][4]);
        int itemHealthAdded = atoi(ItemList[randomIndex][5]);
        int itemWeight = atoi(ItemList[randomIndex][6]);
        int itemValue = atoi(ItemList[randomIndex][7]);

        if ((strcmp(ItemList[randomIndex][3], "Common") == 0 ||
             strcmp(ItemList[randomIndex][3], "Uncommon") == 0 ||
             strcmp(ItemList[randomIndex][3], "Rare") == 0 ||
             strcmp(ItemList[randomIndex][3], "Epic") == 0) &&
            itemGenerated == 0)
        {
            randomIndex = rand() % 30;
            if (strcmp(ItemList[randomIndex][3], "Uncommon") == 0)
            {
                strcpy(itemName, ItemList[randomIndex][0]);
                strcpy(itemDesc, ItemList[randomIndex][1]);
                strcpy(itemType, ItemList[randomIndex][2]);
                strcpy(itemRarity, ItemList[randomIndex][3]);
                show_loot_chest_contents(itemName, itemDesc, itemType, itemRarity, itemHealthAdded, itemDamageAdded, itemWeight, itemValue);
                itemGenerated = TRUE;
            }
            else if (strcmp(ItemList[randomIndex][3], "Common") == 0)
            {
                strcpy(itemName, ItemList[randomIndex][0]);
                strcpy(itemDesc, ItemList[randomIndex][1]);
                strcpy(itemType, ItemList[randomIndex][2]);
                strcpy(itemRarity, ItemList[randomIndex][3]);
                show_loot_chest_contents(itemName, itemDesc, itemType, itemRarity, itemHealthAdded, itemDamageAdded, itemWeight, itemValue);
                itemGenerated = TRUE;
            }
            else if (strcmp(ItemList[randomIndex][3], "Rare") == 0)
            {
                strcpy(itemName, ItemList[randomIndex][0]);
                strcpy(itemDesc, ItemList[randomIndex][1]);
                strcpy(itemType, ItemList[randomIndex][2]);
                strcpy(itemRarity, ItemList[randomIndex][3]);
                show_loot_chest_contents(itemName, itemDesc, itemType, itemRarity, itemHealthAdded, itemDamageAdded, itemWeight, itemValue);
                itemGenerated = TRUE;
            }
            else if (strcmp(ItemList[randomIndex][3], "Epic") == 0)
            {
                strcpy(itemName, ItemList[randomIndex][0]);
                strcpy(itemDesc, ItemList[randomIndex][1]);
                strcpy(itemType, ItemList[randomIndex][2]);
                strcpy(itemRarity, ItemList[randomIndex][3]);
                show_loot_chest_contents(itemName, itemDesc, itemType, itemRarity, itemHealthAdded, itemDamageAdded, itemWeight, itemValue);
                itemGenerated = TRUE;
            }
            else
            {
                puts("Error in generate_item()");
                puts("You should not be here...Turn back now");
                return 1;
            }
        }
        if (itemGenerated)
        {
            break;
        }
    }
    return 0;
}
//===============================================================================//
// This function takes a random number and then uses that number to determine which function is called thus determining which item to generate
int call_generate_function()
{
    srand(time(NULL));
    int randomNum = rand() % 5;

    if (randomNum == 0)
    {
        generate_weapon();
    }
    else if (randomNum == 1)
    {
        generate_head_armor();
    }
    else if (randomNum == 2)
    {
        generate_chest_armor();
    }
    else if (randomNum == 3)
    {
        generate_leg_armor();
    }
    else if (randomNum == 4)
    {
        generate_consumable_item();
    }
    else
    {

        puts("Error in call_generate_function()");
        return 1;
    }
    return 0;
}

//==========================================================================================//
// this function is called when the player finds a loot chest. It asks the player if they want to search the chest or leave it alone.
// if searched then the open_loot_chest() function is called
void found_loot_chest()
{
    char input[10];
    printf("You've found a chest what would you like to do?\n");
    printf("1:Search The Chest\n");
    printf("2:Leave the chest\n");
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (strcmp(input, "1") == 0 || strcmp(input, "search") == 0 || strcmp(input, "Search") == 0)
    {
        open_loot_chest();
    }
    else if (strcmp(input, "2") == 0 || strcmp(input, "leave") == 0 || strcmp(input, "Leave") == 0)
    {
        printf("You decided to leave the chest alone.\n");
        return 0;
    }
    else
    {
        MAKE_VALID_DECISION;
        found_loot_chest();
    }
}
//==========================================================================================//
// this function is called when the player decides to search the chest. It prints out a message and then calls the generate_loot_chest_contents() function
void open_loot_chest()
{
    PRINT_SLOWLY("Opening Chest......", 40000);
    sleep(1);
    PRINT_SLOWLY("Searching......", 40000);
    sleep(2);
    generate_loot_chest_contents();
}
//==========================================================================================//
// this function is called when the player decides to search the chest.  the call_generate_function() function is called
void generate_loot_chest_contents()
{
    /*putting this function in here because might get to the
    point where I want to have up to 3 items be found in a chest.*/
    call_generate_function();
}
//==========================================================================================//
// this function shows the player the contents of the chest and asks them if they want to pick up the item or leave it behind
void show_loot_chest_contents(char *itemName, char *itemDesc, char *itemType, char *itemRarity, int *itemHealthAdded, int *itemDamageAdded, int *itemWeight, int *itemValue)
{
    printf("You've found: %s!\n", itemName);
    printf("Description: %s\n", itemDesc);
    printf("Type: %s\n", itemType);
    printf("Rarity: %s\n", itemRarity);
    if (strcmp(itemType, "Head") == 0 || strcmp(itemType, "Chest") == 0 || strcmp(itemType, "Legs") == 0)
    {
        printf("Health Points Added:" GREEN "%d. " RESET "If equipped your new health would be " GREEN "%d" RESET "\n", itemHealthAdded, itemHealthAdded + hero.Health);
    }
    else if (strcmp(itemType, "Weapon") == 0)
    {
        printf("Damage Points Added: %d.\n", itemDamageAdded);
        printf("%s damage Increase if equipped: " GREEN "%d." RESET "\n", hero.Ability1.Name, itemDamageAdded + hero.Ability1.Damage);
        printf("%s damage Increase if equipped: " GREEN "%d." RESET "\n", hero.Ability2.Name, itemDamageAdded + hero.Ability2.Damage);
        printf("%s damage Increase if equipped: " GREEN "%d." RESET "\n", hero.Ability3.Name, itemDamageAdded + hero.Ability3.Damage);
    }
    printf("Weight(lbs): %d\n", itemWeight);
    printf("Value(gold): %d\n", itemValue);

    ask_to_pick_up(itemName, itemDesc, itemType, itemRarity, itemHealthAdded, itemDamageAdded, itemWeight, itemValue);
}

//==========================================================================================//
// asks the player if they want to pick up the item or leave it behind
void ask_to_pick_up(char *itemName, char *itemDesc, char *itemType, char *itemRarity, int *itemHealthAdded, int *itemDamageAdded, int *itemWeight, int *itemValue)
{
    char input[10];
    printf("Would you like to pick up %s?(y/n)\n", itemName);
    FGETS(input);
    REMOVE_NEWLINE_CHAR(input);

    if (INPUT_IS_YES(input))
    {
        pick_up_item(itemName, itemDesc, itemType, itemRarity, itemHealthAdded, itemDamageAdded, itemWeight, itemValue);
    }
    else if (INPUT_IS_NO(input))
    {
        puts("Very well you left the item behind...");
        system("clear");
        return 0;
    }
}
