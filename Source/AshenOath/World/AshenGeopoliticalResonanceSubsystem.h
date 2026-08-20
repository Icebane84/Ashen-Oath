// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenGeopoliticalResonanceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFactionReputationShiftedSignature, FName, FactionID, float, ReputationScore);

/**
 * UAshenGeopoliticalResonanceSubsystem
 *
 * World Subsystem updating regional faction trust and corruption spread across Oakhaven & Fortress of Light.
 */
UCLASS()
class ASHENOATH_API UAshenGeopoliticalResonanceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Geopolitical")
	void ModifyFactionReputation(FName FactionID, float Delta);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Geopolitical|Events")
	FOnFactionReputationShiftedSignature OnReputationShifted;
};
