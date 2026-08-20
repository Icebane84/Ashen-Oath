// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenSanctuaryRestorationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryRekindledSignature, FName, SanctuaryID, int32, TotalActiveSanctuaries);

/**
 * UAshenSanctuaryRestorationSubsystem
 *
 * Player-driven world restoration subsystem allowing rekindling of Dormant Heartstones to create new safe havens.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryRestorationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanctuaryRestoration")
	bool RekindleDormantHeartstone(FName SanctuaryID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|SanctuaryRestoration")
	int32 GetActiveSanctuaryCount() const { return ActiveSanctuaries.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanctuaryRestoration|Events")
	FOnSanctuaryRekindledSignature OnSanctuaryRekindled;

private:
	TSet<FName> ActiveSanctuaries;
};
