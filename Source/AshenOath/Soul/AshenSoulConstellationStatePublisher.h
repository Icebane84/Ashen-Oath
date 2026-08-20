// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSoulConstellationStatePublisher.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAshenSoulConstellationStateInvalidatedSignature, const FSoulStateVector&, NewState);

/**
 * UAshenSoulConstellationStatePublisher
 *
 * World subsystem that acts as the single authoritative state publisher.
 * Broadcasts state invalidation pulses to all downstream behavioral phenotypes.
 */
UCLASS()
class ASHENOATH_API UAshenSoulConstellationStatePublisher : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Soul")
	FOnAshenSoulConstellationStateInvalidatedSignature OnStateVectorInvalidated;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Soul")
	void PublishStateVector(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Soul")
	FSoulStateVector GetCurrentPublishedState() const { return PublishedState; }

private:
	UPROPERTY()
	FSoulStateVector PublishedState;
};
