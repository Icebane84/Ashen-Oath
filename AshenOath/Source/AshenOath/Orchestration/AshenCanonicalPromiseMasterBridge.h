// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenCanonicalPromiseMasterBridge.generated.h"

/**
 * UAshenCanonicalPromiseMasterBridge
 * 
 * Master orchestrator connecting canonical promise lifecycles, crisis reactivations,
 * and retroactive journal annotations across downstream subsystems.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCanonicalPromiseMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCanonicalPromiseMasterBridge();

	/** Broadcasts promise registration */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Promise")
	void BroadcastPromiseRegistered(const FCanonicalPromiseRecord& Record);

	/** Broadcasts promise crisis reactivation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Promise")
	void BroadcastPromiseCrisisReactivated(const FCanonicalPromiseRecord& Record);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Promise")
	FOnPromiseRegistered OnPromiseRegistered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Promise")
	FOnPromiseCrisisReactivated OnPromiseCrisisReactivated;
};
