// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenPRSGenesisGraphSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenPRSNodeLabel : uint8
{
	Character   UMETA(DisplayName = "char- Character"),
	Enemy       UMETA(DisplayName = "enemy- Enemy"),
	Artifact    UMETA(DisplayName = "artif- Artifact"),
	Location    UMETA(DisplayName = "loc- Location"),
	Cosmology   UMETA(DisplayName = "cosm- Cosmology"),
	CAN         UMETA(DisplayName = "can- Canonical Anchor of Nuance"),
	Faction     UMETA(DisplayName = "faction- Faction"),
	Event       UMETA(DisplayName = "event- Event"),
	Phenomenon  UMETA(DisplayName = "phen- Phenomenon"),
	Narrative   UMETA(DisplayName = "narr- Narrative")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPRSNodeQueriedSignature, FName, NodeID, EAshenPRSNodeLabel, Label, bool, bIsCanonical);

/**
 * UAshenPRSGenesisGraphSubsystem
 *
 * Subsystem federating with prs_001_ashen_genesis knowledge graph nodes & edge relation verification.
 */
UCLASS()
class ASHENOATH_API UAshenPRSGenesisGraphSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PRSGenesis")
	bool QueryPRSNodeReference(FName NodeID, EAshenPRSNodeLabel ExpectedLabel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PRSGenesis|Events")
	FOnPRSNodeQueriedSignature OnPRSNodeQueried;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PRSGenesis")
	int32 TotalNodesFederated = 0;
};
