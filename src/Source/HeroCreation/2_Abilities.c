#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeroCreation.h"
#include "../../Utils/Utils.h"

Hero hero;

//=================================================================================================//
#define IS_OF_CLASS(classname, string) (strcmp(classname, string) == 0)

int set_abilities()
{
    if (IS_OF_CLASS(hero.Class, "Warrior"))
    {
        // TODO move the health and mana declarations to their own file
        //  Setting Starting health and mana
        hero.Health = 75;
        hero.Mana = 20;

        // Declaring Abilities
        struct Ability1 Slash = {
            "Slash",
            "Slash an enemy with your weapon.",
            "Physical", // Type
            20,         // Damage
            0           // ManaCost
        };

        struct Ability2 Charge = {
            "Charge",
            "Charge at an enemy with your weapon.",
            "Physical", // Type
            25,         // Damage
            0           // ManaCost
        };

        struct Ability3 Whirlwind = {
            "Whirlwind",
            "Spin around with your weapon, hitting all enemies around you.",
            "Physical", // Type
            45,         // Damage
            10          // ManaCost
        };

        // Setting Abilities
        hero.Ability1 = Slash;
        hero.Ability2 = Charge;
        hero.Ability3 = Whirlwind;
    }
    else if (IS_OF_CLASS(hero.Class, "Mage"))
    {

        // Setting Starting health and mana
        hero.Health = 40;
        hero.Mana = 70;

        // Declaring Abilities
        struct Ability1 Fireball = {
            "Fireball",
            "Shoot a fireball at an enemy.",
            "Fire", // Type
            30,     // Damage
            15      // ManaCost
        };

        struct Ability2 Frostbolt = {
            "Frostbolt",
            "Shoot a frostbolt at an enemy.",
            "Frost", // Type
            30,      // Damage
            15       // ManaCost
        };

        struct Ability3 ArcaneBlast = {
            "Punch",
            "Punch your enemy.",
            "Physical", // Type
            10,         // Damage
            0           // ManaCost
        };
        // Setting Abilities
        hero.Ability1 = Fireball;
        hero.Ability2 = Frostbolt;
        hero.Ability3 = ArcaneBlast;
    }
    else if (IS_OF_CLASS(hero.Class, "Rogue"))
    {

        // Setting Starting health and mana
        hero.Health = 30;
        hero.Mana = 40;

        // Declaring Abilities
        struct Ability1 Backstab = {
            "Backstab",
            "Stab an enemy in the back.",
            "Physical", // Type
            30,         // Damage
            15          // ManaCost
        };

        struct Ability2 Shadowstep = {
            "Shadow Step",
            "Cloak yourself with invisibility then sneak up on an enemy.",
            "Dark", // Type
            30,     // Damage
            15      // ManaCost
        };
        struct Ability3 Shadowstrike = {
            "Shadow Strike",
            "Strike an enemy with dark energy.",
            "Dark", // Type
            30,     // Damage
            15      // ManaCost
        };
        // Setting Abilities
        hero.Ability1 = Backstab;
        hero.Ability2 = Shadowstep;
        hero.Ability3 = Shadowstrike;
    }
    else if (IS_OF_CLASS(hero.Class, "Cleric"))
    {

        // Setting Starting health and mana
        hero.Health = 60;
        hero.Mana = 50;

        // Declaring Abilities
        struct Ability1 Smite = {
            "Smite",
            "Smite an enemy with holy energy.",
            "Light", // Type
            30,      // Damage
            15       // ManaCost
        };

        struct Ability2 Heal = {
            "Heal",
            "Heal yourself.",
            "Physical", // Type
            30,         // Damage
            15          // ManaCost
        };

        struct Ability3 HolyBolt = {
            "Holy Bolt",
            "Shoot a bolt of holy energy at an enemy.",
            "Light", // Type
            30,      // Damage
            15       // ManaCost
        };
        // Setting Abilities
        hero.Ability1 = Smite;
        hero.Ability2 = Heal;
        hero.Ability3 = HolyBolt;
    }
    else if (IS_OF_CLASS(hero.Class, "Bard"))
    {

        // Setting Starting health and mana
        hero.Health = 40;
        hero.Mana = 60;

        // Declaring Abilities
        struct Ability1 CacophonousBlast = {
            "Cacophonous Blast",
            "Unleash a cacophonous blast of sound that shatters your enemies.",
            "Arcane", // Type
            100,      // Damage
            60        // ManaCost
        };

        struct Ability2 MelodicFury = {
            "Melodic Fury",
            "Go into a frenzy, striking your foes with a series of rapid, damaging notes.",
            "Arcane", // Type
            20,       // Damage per hit
            50        // ManaCost
        };

        struct Ability3 ResonantSurge = {
            "Resonant Surge",
            "Channel the power of resonance to unleash a devastating surge of energy.",
            "Arcane", // Type
            120,      // Single target damage
            70        // ManaCost
        };
        // Setting Abilities
        hero.Ability1 = CacophonousBlast;
        hero.Ability2 = MelodicFury;
        hero.Ability3 = ResonantSurge;
    }

    else
    {
        perror("Invalid class name you should'nt have made it this far, that means you broke something..\n");

        return 1;
    }
}
