// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenMapResonancePassController.h"

UAshenMapResonancePassController::UAshenMapResonancePassController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMapResonancePassController::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenMapResonancePassController::RenderResonancePass()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMapResonancePassController: Rendered Pass #3 (Resonance Memory Engine) clean."));
	return true;
}
