// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenCompanionTrustDialogueTreeAdapter.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenCompanionTrustDialogueTreeAdapter::UAshenCompanionTrustDialogueTreeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionTrustDialogueTreeAdapter::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenCompanionTrustDialogueTreeAdapter::IsDialogueNodeUnlockedByTrust(
	FName CompanionID,
	FName NodeID,
	float ManualTrust)
{
	float EvaluatedTrust = ManualTrust;

	if (EvaluatedTrust < 0.0f)
	{
		if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
		{
			const FSoulStateVector State = Publisher->GetSoulState();
			if (CompanionID == FName("Garrett"))
			{
				EvaluatedTrust = State.GarrettTrust;
			}
			else if (CompanionID == FName("Serafina"))
			{
				EvaluatedTrust = State.SerafinaTrust;
			}
			else
			{
				EvaluatedTrust = 0.50f;
			}
		}
		else
		{
			EvaluatedTrust = 0.50f;
		}
	}

	const float RequiredTrust = GetRequiredTrustForNode(NodeID);
	const bool bUnlocked = EvaluatedTrust >= RequiredTrust;

	UE_LOG(LogTemp, Verbose, TEXT("UAshenCompanionTrustDialogueTreeAdapter: Node '%s' for '%s' (Trust: %.2f / Required: %.2f) -> %s"),
		*NodeID.ToString(), *CompanionID.ToString(), EvaluatedTrust, RequiredTrust, bUnlocked ? TEXT("UNLOCKED") : TEXT("LOCKED"));

	return bUnlocked;
}

float UAshenCompanionTrustDialogueTreeAdapter::GetRequiredTrustForNode(FName NodeID) const
{
	if (NodeID == FName("Node_Intro") || NodeID == FName("Intro"))
	{
		return 0.0f;
	}
	if (NodeID == FName("Node_Vulnerability") || NodeID == FName("Vulnerability"))
	{
		return 0.40f;
	}
	if (NodeID == FName("Node_TraumaConfession") || NodeID == FName("TraumaConfession"))
	{
		return 0.65f;
	}
	if (NodeID == FName("Node_ApotheosisPact") || NodeID == FName("ApotheosisPact"))
	{
		return 0.85f;
	}

	// Default unlock threshold for unknown narrative nodes
	return 0.30f;
}

UAshenSoulPublisher* UAshenCompanionTrustDialogueTreeAdapter::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
