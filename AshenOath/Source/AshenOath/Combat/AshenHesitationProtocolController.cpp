// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenHesitationProtocolController.h"

UAshenHesitationProtocolController::UAshenHesitationProtocolController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenHesitationProtocolController::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenHesitationProtocolController::ResolveDefaultCharacterInstinct()
{
	bDefaultInstinctExecuted = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenHesitationProtocolController: Resolved Kaelen's default character agency instinct following player hesitation."));
	return bDefaultInstinctExecuted;
}
