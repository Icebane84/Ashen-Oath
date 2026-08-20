// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEchoingWoundSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEchoingWoundInflictedSignature, FName, WoundID, float, TraumaSeverity);

/**
 * UAshenEchoingWoundSubsystem
 *
 * World Subsystem tracking lingering psychological trauma wounds across encounters.
 */
UCLASS()
class ASHENOATH_API UAshenEchoingWoundSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EchoingWound")
	void InflictEchoingWound(FName WoundID, float TraumaSeverity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|EchoingWound")
	int32 GetActiveEchoingWoundCount() const { return ActiveEchoingWounds.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EchoingWound|Events")
	FOnEchoingWoundInflictedSignature OnWoundInflicted;

private:
	TArray<FName> ActiveEchoingWounds;
};
