// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliablePerceptionPhenotypeController.h"

UAshenUnreliablePerceptionPhenotypeController::UAshenUnreliablePerceptionPhenotypeController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliablePerceptionPhenotypeController::UpdatePerceptionDistortion(float IntegrationDebt)
{
	PerceptionDistortionScalar = FMath::Clamp(IntegrationDebt, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliablePerceptionPhenotypeController: Perception distortion scalar updated to %.2f"), PerceptionDistortionScalar);
}
