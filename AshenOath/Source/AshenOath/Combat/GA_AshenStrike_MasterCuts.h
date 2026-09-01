// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Combat/AshenGameplayAbility_CombatStrike.h"
#include "GA_AshenStrike_MasterCuts.generated.h"

/**
 * UGA_AshenStrike_Zornhau
 * 1. Zornhau (Wrath Hew): Heavy diagonal descending strike from Vom Tag.
 */
UCLASS()
class ASHENOATH_API UGA_AshenStrike_Zornhau : public UAshenGameplayAbility_CombatStrike
{
	GENERATED_BODY()
public:
	UGA_AshenStrike_Zornhau();
};

/**
 * UGA_AshenStrike_Krumphau
 * 2. Krumphau (Crooked Hew): Crossed-wrist off-axis strike from Ochs that crushes shields and breaks poise.
 */
UCLASS()
class ASHENOATH_API UGA_AshenStrike_Krumphau : public UAshenGameplayAbility_CombatStrike
{
	GENERATED_BODY()
public:
	UGA_AshenStrike_Krumphau();
};

/**
 * UGA_AshenStrike_Zwerchhau
 * 3. Zwerchhau (Thwart Hew): Horizontal false-edge helicopter roof strike from Ochs with infinite 115 BPM chain capability.
 */
UCLASS()
class ASHENOATH_API UGA_AshenStrike_Zwerchhau : public UAshenGameplayAbility_CombatStrike
{
	GENERATED_BODY()
public:
	UGA_AshenStrike_Zwerchhau();
};

/**
 * UGA_AshenStrike_Schielhau
 * 4. Schielhau (Squinting Hew): Dipped point false-edge strike from Pflug that counters incoming thrusts with 50% armor penetration.
 */
UCLASS()
class ASHENOATH_API UGA_AshenStrike_Schielhau : public UAshenGameplayAbility_CombatStrike
{
	GENERATED_BODY()
public:
	UGA_AshenStrike_Schielhau();
};

/**
 * UGA_AshenStrike_Scheitelhau
 * 5. Scheitelhau (Crown Hew): Direct vertical descending strike from Vom Tag aimed at the crown of the head.
 */
UCLASS()
class ASHENOATH_API UGA_AshenStrike_Scheitelhau : public UAshenGameplayAbility_CombatStrike
{
	GENERATED_BODY()
public:
	UGA_AshenStrike_Scheitelhau();
};

/**
 * UGA_AshenStrike_Mordhau
 * 6. Mordhau (Pommel / Half-Sword Strike): Inverted weapon grip hitting with crossguard/pommel for 100% armor penetration blunt damage.
 */
UCLASS()
class ASHENOATH_API UGA_AshenStrike_Mordhau : public UAshenGameplayAbility_CombatStrike
{
	GENERATED_BODY()
public:
	UGA_AshenStrike_Mordhau();
};
