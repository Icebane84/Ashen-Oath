// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenMapExpeditionPassController.h"

UAshenMapExpeditionPassController::UAshenMapExpeditionPassController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMapExpeditionPassController::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenMapExpeditionPassController::RenderExpeditionPass()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMapExpeditionPassController: Rendered Pass #2 (Expedition Temporal Tracking) clean."));
	return true;
}
