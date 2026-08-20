// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenMapWorldviewOverlayController.h"

UAshenMapWorldviewOverlayController::UAshenMapWorldviewOverlayController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMapWorldviewOverlayController::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenMapWorldviewOverlayController::RenderWorldviewOverlayPass(FName AuthorName)
{
	ActiveWorldviewAuthor = AuthorName;
	UE_LOG(LogTemp, Log, TEXT("UAshenMapWorldviewOverlayController: Rendered Pass #4 (Worldview Overlays for %s) clean."), *ActiveWorldviewAuthor.ToString());
	return true;
}
