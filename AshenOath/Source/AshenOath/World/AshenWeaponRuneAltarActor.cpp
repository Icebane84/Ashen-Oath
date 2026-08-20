// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenWeaponRuneAltarActor.h"

AAshenWeaponRuneAltarActor::AAshenWeaponRuneAltarActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenWeaponRuneAltarActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenWeaponRuneAltarActor: Weapon rune altar actor initialized."));
}

void AAshenWeaponRuneAltarActor::ConsecrateWeaponAtAltar()
{
	bIsAltarConsecrated = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenWeaponRuneAltarActor: Weapon consecrated at ancient rune altar!"));
}
