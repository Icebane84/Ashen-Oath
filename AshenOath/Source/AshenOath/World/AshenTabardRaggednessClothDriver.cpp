// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenTabardRaggednessClothDriver.h"

UAshenTabardRaggednessClothDriver::UAshenTabardRaggednessClothDriver()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTabardRaggednessClothDriver::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenTabardRaggednessClothDriver::ApplyTabardRaggednessParameters(float RaggednessMask)
{
	ClothTabardOpacityScalar = FMath::Clamp(1.0f - RaggednessMask, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenTabardRaggednessClothDriver: Applied tabard raggedness parameters (Opacity Scalar: %f)"), ClothTabardOpacityScalar);
}
