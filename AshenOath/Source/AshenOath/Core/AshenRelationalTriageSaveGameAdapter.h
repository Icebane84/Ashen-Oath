// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenRelationalTriageSaveGameAdapter.generated.h"

/**
 * UAshenRelationalTriageSaveGameAdapter
 * Serializes compiled stances, pairwise trust values, and historical triage incident choices.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalTriageSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRelationalTriageSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveTriageHistory(const TArray<FTriageIncidentRecord>& Incidents, const FPairwiseTrustVector& Trust);
};
