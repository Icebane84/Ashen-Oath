// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 657: Ashen Devils Bargain Transformation Subsystem

#include "AshenDevilsBargainTransformationSubsystem.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "Engine/GameInstance.h"

void UAshenDevilsBargainTransformationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsUnchainedBerserkActive = false;
	ActiveAttackSpeedMultiplier = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainTransformationSubsystem: Initialized — Devil's Bargain Subsystem ONLINE."));
}

void UAshenDevilsBargainTransformationSubsystem::AcceptDevilsBargain()
{
	bIsUnchainedBerserkActive = true;
	ActiveAttackSpeedMultiplier = 3.0f; // +200% Attack Speed (3.0x multiplier)
	const float TrustAtrophy = 25.0f;
	const float SpiritualStain = 20.0f;

	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenDevilsBargainTrustAtrophyDirector* AtrophyDirector = GI->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>())
		{
			AtrophyDirector->ApplyDevilsBargainTrustAtrophy(TrustAtrophy);
		}
	}

	OnBargainAccepted.Broadcast(ActiveAttackSpeedMultiplier, TrustAtrophy, SpiritualStain);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainTransformationSubsystem: DEVIL'S BARGAIN ACCEPTED -> Stance.UnchainedBerserk ACTIVE | Speed: %.1fx | Trust Atrophy: -%.1f | Stain: %.1f%%."),
		ActiveAttackSpeedMultiplier, TrustAtrophy, SpiritualStain);
}
