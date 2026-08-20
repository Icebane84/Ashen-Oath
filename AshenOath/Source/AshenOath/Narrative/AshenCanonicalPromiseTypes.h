// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCanonicalPromiseTypes.generated.h"

// -----------------------------------------------------------------------------------
// CANONICAL PROMISE & MARGINALIA ENUMS (PROMISE-SPEC-059)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EPromiseResolutionStatus : uint8
{
	Active              UMETA(DisplayName = "Active (Bound & Ongoing)"),
	Fulfilled           UMETA(DisplayName = "Fulfilled (Honored in Crisis)"),
	Betrayed            UMETA(DisplayName = "Betrayed (Broken under Strain)"),
	Transcended         UMETA(DisplayName = "Transcended (Evolved into Higher Oath)")
};

UENUM(BlueprintType)
enum class EPromiseDomainScope : uint8
{
	PersonalCompanion   UMETA(DisplayName = "Personal Companion (e.g. Garrett or Serafina)"),
	CivilianSanctuary   UMETA(DisplayName = "Civilian Sanctuary (e.g. Defend Outpost)"),
	SacredVow           UMETA(DisplayName = "Sacred Vow (Order of the White Flame)")
};

UENUM(BlueprintType)
enum class EMarginaliaInkMedium : uint8
{
	KaelenIronGallInk   UMETA(DisplayName = "Kaelen's Iron Gall Ink (Standard Text)"),
	GarrettCharcoal     UMETA(DisplayName = "Garrett's Charcoal (Sharp Tactical Notes)"),
	SerafinaGoldenInk   UMETA(DisplayName = "Serafina's Golden Ink (Empathic Reflections)")
};

// -----------------------------------------------------------------------------------
// CANONICAL PROMISE & MARGINALIA STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Authoritative record of a canonical promise sworn by Kaelen.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCanonicalPromiseRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	FString PromiseId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	FName TargetCompanionName = FName(TEXT("Garrett"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	FString PromiseText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	EPromiseResolutionStatus Status = EPromiseResolutionStatus::Active;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	EPromiseDomainScope Scope = EPromiseDomainScope::PersonalCompanion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	FGameplayTag TriggerContextTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Promise")
	double SwornGameTime = 0.0;
};

/**
 * Secret unnotified annotation written by a companion on an existing journal entry.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FRetroactiveMarginaliaEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString EntryId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	int32 TargetJournalPageIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FName InscribingAuthor = FName(TEXT("Serafina"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	FString MarginaliaContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	EMarginaliaInkMedium Medium = EMarginaliaInkMedium::SerafinaGoldenInk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Journal")
	bool bDiscoveredByPlayer = false;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPromiseRegistered, const FCanonicalPromiseRecord&, Record);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPromiseStatusChanged, const FString&, PromiseId, EPromiseResolutionStatus, NewStatus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPromiseCrisisReactivated, const FCanonicalPromiseRecord&, Record);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRetroactiveMarginaliaInscribed, const FRetroactiveMarginaliaEntry&, Entry);
