// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenMultiAuthorMarginaliaEvaluator.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenMultiAuthorMarginaliaEvaluator::UAshenMultiAuthorMarginaliaEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenMultiAuthorMarginaliaEvaluator::IsAuthorMarginaliaUnlocked(
	EForensicMarginaliaAuthor Author,
	float TrustScore01) const
{
	float EvaluatedTrust = TrustScore01;

	if (EvaluatedTrust < 0.0f)
	{
		if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
		{
			const FSoulStateVector State = Publisher->GetSoulState();
			if (Author == EForensicMarginaliaAuthor::Garrett)
			{
				EvaluatedTrust = State.GarrettTrust;
			}
			else if (Author == EForensicMarginaliaAuthor::Serafina)
			{
				EvaluatedTrust = State.SerafinaTrust;
			}
			else
			{
				EvaluatedTrust = 1.0f; // Kaelen always unlocked
			}
		}
		else
		{
			EvaluatedTrust = 0.50f;
		}
	}

	switch (Author)
	{
	case EForensicMarginaliaAuthor::Kaelen:
		// Kaelen's notes are always unlocked
		return true;

	case EForensicMarginaliaAuthor::Garrett:
		// Garrett writes when trust reaches 40% (0.40)
		return EvaluatedTrust >= 0.40f;

	case EForensicMarginaliaAuthor::Serafina:
		// Serafina writes when trust reaches 70% (0.70)
		return EvaluatedTrust >= 0.70f;

	default:
		return false;
	}
}

FLinearColor UAshenMultiAuthorMarginaliaEvaluator::GetAuthorInkColor(EForensicMarginaliaAuthor Author) const
{
	switch (Author)
	{
	case EForensicMarginaliaAuthor::Kaelen:
		// Charcoal Black
		return FLinearColor(0.08f, 0.08f, 0.08f, 1.0f);

	case EForensicMarginaliaAuthor::Garrett:
		// Copper Brown
		return FLinearColor(0.65f, 0.35f, 0.15f, 1.0f);

	case EForensicMarginaliaAuthor::Serafina:
		// Silver Blue
		return FLinearColor(0.40f, 0.60f, 0.85f, 1.0f);

	default:
		return FLinearColor::Black;
	}
}

UAshenSoulPublisher* UAshenMultiAuthorMarginaliaEvaluator::GetSoulPublisher() const
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
