// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenMemoryBleedVisualController.h"

UAshenMemoryBleedVisualController::UAshenMemoryBleedVisualController()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryBleedVisualController::BeginPlay() { Super::BeginPlay(); }

void UAshenMemoryBleedVisualController::ApplyMemoryBleedVisualEffects(EAshenIntegrationDebtStage Stage)
{
	switch (Stage)
	{
	case EAshenIntegrationDebtStage::MemoryBleed:
		EdgeDesaturationIntensity = 0.40f;
		HUDJitterFrequency = 2.0f;
		break;
	case EAshenIntegrationDebtStage::RuntimeNoise:
		EdgeDesaturationIntensity = 0.75f;
		HUDJitterFrequency = 8.0f;
		break;
	case EAshenIntegrationDebtStage::ForcedCollapse:
		EdgeDesaturationIntensity = 1.0f;
		HUDJitterFrequency = 15.0f;
		break;
	default:
		EdgeDesaturationIntensity = 0.0f;
		HUDJitterFrequency = 0.0f;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBleedVisualController: Visual effects updated for stage %d (Desat=%f, Jitter=%f)"),
		(int32)Stage, EdgeDesaturationIntensity, HUDJitterFrequency);
}
