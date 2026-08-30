// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenMartyrSolitaryParryGASAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenMartyrSolitaryParryGASAbility::UAshenMartyrSolitaryParryGASAbility()
{
	ParryWindowBonusRatio = 0.10f;
	TrustDrainPerParry = 0.05f;
}

bool UAshenMartyrSolitaryParryGASAbility::ExecuteMartyrParry(float& OutTrustPenalty)
{
	OutTrustPenalty = TrustDrainPerParry;

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		FSoulStateVector Delta;
		Delta.Resolve = 0.05f; // Self-reliance bolsters resolve
		Delta.Corruption = 0.0f;
		Delta.IntegrationDebt = 0.0f;
		Delta.Isolation = 0.05f; // Canonical Dysregulation (N) increases
		Delta.GarrettTrust = -TrustDrainPerParry;
		Delta.SerafinaTrust = -TrustDrainPerParry;
		Publisher->CommitState(Delta);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrSolitaryParryGASAbility: MARTYR PARRY EXECUTED (+%.1f%% Windows, -%.1f%% Trust committed to SSoT)!"),
		ParryWindowBonusRatio * 100.0f, OutTrustPenalty * 100.0f);
	return true;
}

UAshenSoulPublisher* UAshenMartyrSolitaryParryGASAbility::GetSoulPublisher() const
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
