// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenCampfireContemplationDirectorComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenSoulTypes.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenCampfireContemplationDirectorComponent::UAshenCampfireContemplationDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentMood = ECampfireReflectionMood::TemperedResolve;
}

void UAshenCampfireContemplationDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
	EvaluateCampfireMood();
}

ECampfireReflectionMood UAshenCampfireContemplationDirectorComponent::EvaluateCampfireMood(
	float TrustScore01,
	float Debt01)
{
	float EvaluatedTrust = TrustScore01;
	float EvaluatedDebt = Debt01;

	if (EvaluatedTrust < 0.0f || EvaluatedDebt < 0.0f)
	{
		if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
		{
			const FSoulStateVector State = Publisher->GetSoulState();
			EvaluatedTrust = (State.GarrettTrust + State.SerafinaTrust) * 0.5f;
			EvaluatedDebt = State.IntegrationDebt;
		}
		else
		{
			EvaluatedTrust = 0.50f;
			EvaluatedDebt = 0.0f;
		}
	}

	if (EvaluatedDebt >= 0.70f || EvaluatedTrust < 0.40f)
	{
		CurrentMood = ECampfireReflectionMood::SomberSilence;
	}
	else if (EvaluatedTrust >= 0.75f)
	{
		CurrentMood = ECampfireReflectionMood::SharedCatharsis;
	}
	else
	{
		CurrentMood = ECampfireReflectionMood::TemperedResolve;
	}

	return CurrentMood;
}

float UAshenCampfireContemplationDirectorComponent::RestAtCampfire(float RestDurationSeconds)
{
	// 5 seconds rest restores up to 25% sanity (0.05 per sec)
	const float SanityRestored = FMath::Clamp(RestDurationSeconds * 0.05f, 0.0f, 0.25f);

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		FSoulStateVector Delta;
		Delta.Resolve = SanityRestored * 0.80f;
		Delta.Corruption = -SanityRestored * 0.50f;
		Delta.IntegrationDebt = -SanityRestored * 0.40f;
		Delta.Isolation = -SanityRestored; // Purge dysregulation (N)
		Delta.GarrettTrust = SanityRestored * 0.20f;
		Delta.SerafinaTrust = SanityRestored * 0.20f;
		Publisher->CommitState(Delta);

		// Reset companion fatigue & burnout
		FRelationalMatrix_V2 RelMatrix = Publisher->GetRelationalMatrix();
		RelMatrix.SerafinaProfile.TransferenceBurnout = 0.0f;
		RelMatrix.GarrettProfile.SomaticDread = FMath::Max(0.0f, RelMatrix.GarrettProfile.SomaticDread - 0.30f);
		Publisher->SetRelationalMatrix(RelMatrix);
	}

	EvaluateCampfireMood();
	OnCampfireRestCompleted.Broadcast(SanityRestored, CurrentMood);

	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireContemplationDirectorComponent: Rest completed (+%.2f Sanity/Resolve, Fatigue Reset, Mood=%d)."),
		SanityRestored, (int32)CurrentMood);

	return SanityRestored;
}

UAshenSoulPublisher* UAshenCampfireContemplationDirectorComponent::GetSoulPublisher() const
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
