// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSerafinaRadiantPurgeNovaSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRadiantPurgeExecutedSignature, float, CleansedStainPercent, float, NewSpiritualStain);

/**
 * UAshenSerafinaRadiantPurgeNovaSubsystem
 *
 * Radial burst cleansing Kaelen's spiritual stain during critical high-corruption moments (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaRadiantPurgeNovaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaPurge")
	void ExecuteRadiantPurgeNova(float CurrentSpiritualStain);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaPurge|Events")
	FOnRadiantPurgeExecutedSignature OnRadiantPurgeExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaPurge")
	int32 TotalPurgesExecuted = 0;
};
