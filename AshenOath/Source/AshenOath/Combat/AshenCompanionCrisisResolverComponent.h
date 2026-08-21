// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenCompanionCrisisResolverComponent.generated.h"

/**
 * UAshenCompanionCrisisResolverComponent
 * 
 * Manages the 3.0s companion pinning crisis decision window and outcome logic.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionCrisisResolverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionCrisisResolverComponent();

	/** Opens a crisis decision window */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Crisis")
	FCompanionCrisisContext OpenCrisisWindow(FName CompanionName, float WindowSeconds);

	/** Resolves the crisis via player choice */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Crisis")
	bool ResolveCrisis(bool bIntervenedViaTransference, ECompanionCrisisState& OutOutcome, float& OutTrustDelta);

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Crisis")
	FCompanionCrisisContext GetCurrentContext() const { return CurrentContext; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Boss|Crisis")
	FCompanionCrisisContext CurrentContext;
};
