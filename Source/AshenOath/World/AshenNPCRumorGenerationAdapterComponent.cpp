// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCRumorGenerationAdapterComponent.h"

UAshenNPCRumorGenerationAdapterComponent::UAshenNPCRumorGenerationAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveRumorTag = FName("Rumor_WanderingSwordsman");
}

void UAshenNPCRumorGenerationAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	if (NewState.Corruption >= 0.6f)
	{
		ActiveRumorTag = FName("Rumor_ShadowCurseInquisitor");
	}
	else if (NewState.Corruption >= 0.3f)
	{
		ActiveRumorTag = FName("Rumor_TaintedMercenary");
	}
	else
	{
		ActiveRumorTag = FName("Rumor_WanderingSwordsman");
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenNPCRumorGenerationAdapterComponent: Active NPC rumor tag set to '%s'"), *ActiveRumorTag.ToString());
}
