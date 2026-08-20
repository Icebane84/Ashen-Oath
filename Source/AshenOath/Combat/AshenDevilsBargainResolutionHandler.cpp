// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDevilsBargainResolutionHandler.h"

UAshenDevilsBargainResolutionHandler::UAshenDevilsBargainResolutionHandler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDevilsBargainResolutionHandler::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDevilsBargainResolutionHandler::ExecuteDevilsBargainSurrender()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainResolutionHandler: Executed Path A: Surrender (The Devil's Bargain). Triggered enemy recoil/panic AI and trust atrophy (%f)."), TrustAtrophyAmount);
	return true;
}
