// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenSomaticPresentationController.h"

UAshenSomaticPresentationController::UAshenSomaticPresentationController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPresentationController::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticPresentationController::UpdateSomaticPresentation(float Sanity, float Corruption)
{
	InkBleedScalar = FMath::Clamp(Corruption, 0.0f, 1.0f);
	HandwritingWobbleIntensity = FMath::Clamp(1.0f - Sanity, 0.0f, 1.0f);
	CalculatedHandwritingWobble = HandwritingWobbleIntensity;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPresentationController: Updated somatic presentation (InkBleed: %f, Wobble: %f)."), InkBleedScalar, HandwritingWobbleIntensity);
}

void UAshenSomaticPresentationController::EvaluateSomaticPresentation(float PhysicalExhaustion, float MentalTrauma, float EnvironmentalCorruption)
{
	CalculatedHandwritingWobble = (PhysicalExhaustion * EnvironmentalCorruption) + MentalTrauma;
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPresentationController: Evaluated somatic presentation (Wobble: %f)."), CalculatedHandwritingWobble);
}
