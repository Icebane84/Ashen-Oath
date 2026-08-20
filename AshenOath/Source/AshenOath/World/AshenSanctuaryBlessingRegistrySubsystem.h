// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSanctuaryBlessingRegistrySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryBlessingRegisteredSignature, FName, BlessingID, float, StatBonusPercent);

/**
 * UAshenSanctuaryBlessingRegistrySubsystem
 *
 * Subsystem registering persistent sanctuary bonfire blessings.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryBlessingRegistrySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BlessingRegistry")
	void RegisterSanctuaryBlessing(FName BlessingID, float StatBonusPercent = 10.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BlessingRegistry|Events")
	FOnSanctuaryBlessingRegisteredSignature OnBlessingRegistered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BlessingRegistry")
	TArray<FName> ActiveBlessings;
};
