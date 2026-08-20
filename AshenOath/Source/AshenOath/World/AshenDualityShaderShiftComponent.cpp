// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDualityShaderShiftComponent.h"

UAshenDualityShaderShiftComponent::UAshenDualityShaderShiftComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDualityShaderShiftComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDualityShaderShiftComponent::SetDualityBlendRatio(float NewRatio)
{
	CurrentDualityBlendRatio = FMath::Clamp(NewRatio, 0.0f, 1.0f);
	if (OnBlendRatioChanged.IsBound())
	{
		OnBlendRatioChanged.Broadcast(CurrentDualityBlendRatio);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenDualityShaderShiftComponent: Duality blend ratio updated to %.2f"), CurrentDualityBlendRatio);
}
