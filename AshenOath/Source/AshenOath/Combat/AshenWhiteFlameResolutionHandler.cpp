// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenWhiteFlameResolutionHandler.h"

UAshenWhiteFlameResolutionHandler::UAshenWhiteFlameResolutionHandler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWhiteFlameResolutionHandler::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenWhiteFlameResolutionHandler::ExecuteWhiteFlameRestraint()
{
	bWillpowerUnbrokenBuffActive = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameResolutionHandler: Executed Path B: Restraint (The White Flame Resolution). Applied State.Willpower.Unbroken buff and enemy momentum shatter AI."));
	return bWillpowerUnbrokenBuffActive;
}
