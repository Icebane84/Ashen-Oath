// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AshenIdentityCompilerTypes.generated.h"

/**
 * EImprintSalienceCategory
 * Classification of memories determining asymmetric decay rate during rest cycles.
 */
UENUM(BlueprintType)
enum class EImprintSalienceCategory : uint8
{
	Trauma              UMETA(DisplayName = "Trauma (Persistent Decay: lambda = 0.02)"),
	CompanionBond       UMETA(DisplayName = "Companion Bond (Standard Decay: lambda = 0.08)"),
	HistoricalEpiphany  UMETA(DisplayName = "Historical Epiphany (Slow Decay: lambda = 0.03)"),
	CombatTithe         UMETA(DisplayName = "Combat Tithe (Fast Decay: lambda = 0.12)")
};

/**
 * FAshenIdentityCognitiveStateVector
 * The authoritative numerical system driving Kaelen's cognitive reality (RIC-003).
 */
USTRUCT(BlueprintType)
struct FAshenIdentityCognitiveStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Identity")
	float Resolve = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Identity")
	float Corruption = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Identity")
	float Isolation = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Identity")
	float CompanionTrust = 0.5f;
};

/**
 * FAshenIdentityDeltaPayload
 * Structured sub-object sent from the offline SLM containing proposed state shifts.
 */
USTRUCT(BlueprintType)
struct FAshenIdentityDeltaPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Governance")
	FString TargetAxiom; // e.g., "Corruption", "Resolve", "Isolation", "CompanionTrust"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Governance")
	float ProposedDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Governance")
	TArray<FString> SupportingMemories; // Evidence Pack: Pointers back to the Imprint Buffer

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Governance")
	FGameplayTagContainer AssertedTags;
};

/**
 * FAshenImprintRecord
 * Authoritative record of an unsealed memory in Kaelen's Imprint Buffer.
 */
USTRUCT(BlueprintType)
struct FAshenImprintRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Memory")
	FString MemoryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Memory")
	EImprintSalienceCategory Category = EImprintSalienceCategory::Trauma;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Memory")
	float Salience = 1.0f; // S in [0.0, 1.0]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|Memory")
	int32 RestCyclesElapsed = 0;
};
