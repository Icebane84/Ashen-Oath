// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "AshenOath_ThreatPerceptionComponent.generated.h"

class UAIPerceptionComponent;
class UAICognitiveComponent;

USTRUCT(BlueprintType)
struct FAshenThreatScoringParams
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Threat")
	float DistanceWeight = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Threat")
	float MaxEngagementRange = 6000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Threat")
	float DamageAggroWeight = 2.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Threat")
	float DamageAggroHalfLifeSeconds = 4.0f;
};

/**
 * UAshenOath_ThreatPerceptionComponent
 * Sole owner of perception ingestion and threat-scoring policy for Cognitive AI.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_ThreatPerceptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_ThreatPerceptionComponent();

	void NotifyDamageReceived(APawn* Instigator, float DamageAmount);

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UFUNCTION()
	void HandlePerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	void RecomputeThreatTable();
	float ScoreCandidate(const APawn* Candidate, float LastSeenAge) const;

	UPROPERTY(EditDefaultsOnly, Category = "Threat")
	FAshenThreatScoringParams ScoringParams;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAIPerceptionComponent> PerceptionComp;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAICognitiveComponent> CognitiveComp;

	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<APawn>, float> DamageAggroLog;
};
