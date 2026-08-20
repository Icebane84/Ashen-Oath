// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCorpseRunRecoverySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCorpseRunMarkerStateChangedSignature, FVector, MarkerLocation, float, DroppedEmbers);

/**
 * UAshenCorpseRunRecoverySubsystem
 *
 * World Subsystem dropping a portion of unspent Ember currency at site of party wipe, creating a retrieval marker.
 */
UCLASS()
class ASHENOATH_API UAshenCorpseRunRecoverySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CorpseRun")
	void SpawnCorpseRunMarker(FVector DeathLocation, float EmbersLost);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CorpseRun")
	float RecoverCorpseRunEmbers();

	UFUNCTION(BlueprintPure, Category = "AshenOath|CorpseRun")
	bool HasActiveCorpseRunMarker() const { return bHasActiveMarker; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CorpseRun|Events")
	FOnCorpseRunMarkerStateChangedSignature OnCorpseMarkerStateChanged;

private:
	FVector CorpseLocation = FVector::ZeroVector;
	float StoredDroppedEmbers = 0.0f;
	bool bHasActiveMarker = false;
};
