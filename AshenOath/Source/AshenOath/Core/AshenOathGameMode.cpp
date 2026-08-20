// Copyright Epic Games, Inc. All Rights Reserved.

#include "AshenOathGameMode.h"
#include "Combat/AshenCombatCharacter.h"

AAshenOathGameMode::AAshenOathGameMode()
{
	DefaultPawnClass = AAshenCombatCharacter::StaticClass();
}
