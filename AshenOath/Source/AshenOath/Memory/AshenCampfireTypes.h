// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenSoulTypes.h"
#include "Companions/AshenOathTrustTypes.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"
#include "AshenCampfireTypes.generated.h"

UENUM(BlueprintType)
enum class ECampfireReflectionPhase : uint8
{
	Resting             UMETA(DisplayName = "Resting at Campfire"),
	Reflecting          UMETA(DisplayName = "Reviewing Soul Constellation"),
	DialogueEngagement  UMETA(DisplayName = "Engaging Companion Confessions"),
	LociInscription     UMETA(DisplayName = "Inscribing 4-Guard Loci"),
	MorphingBlade       UMETA(DisplayName = "Morphing Oathbringer Metallurgy"),
	Completed           UMETA(DisplayName = "Reflection Sealed (Debt Paid)")
};

USTRUCT(BlueprintType)
struct FCampfireMemoryFragment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Campfire|Memory")
	FName MemoryID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Campfire|Memory")
	FText Title = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Campfire|Memory")
	FText NarrativeDescription = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Campfire|Memory")
	float RawTraumaWeight = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Campfire|Memory")
	bool bIsCompanionRelated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Campfire|Memory")
	EAshenOathCompanion AssociatedCompanion = EAshenOathCompanion::Garrett;
};

USTRUCT(BlueprintType)
struct FCampfireIntegrationResult
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	EInterpretiveLens AppliedLens = EInterpretiveLens::Accountability;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	float ResolveGained = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	float CorruptionGained = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	float TrustGained = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	float DebtCleared = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	EOathbringerMetallurgicalTier ResultingMetallurgyTier = EOathbringerMetallurgicalTier::BurdenedIron;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Campfire|Result")
	float ResultingWeaponMass = 80.0f;
};
