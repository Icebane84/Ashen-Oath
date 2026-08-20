// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenMapGeographyPassController.h"

UAshenMapGeographyPassController::UAshenMapGeographyPassController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMapGeographyPassController::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenMapGeographyPassController::RenderGeographyPass()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMapGeographyPassController: Rendered Pass #1 (Geography Base Layer) clean."));
	return true;
}
