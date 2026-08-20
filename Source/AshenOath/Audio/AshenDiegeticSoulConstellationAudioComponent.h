// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticSoulConstellationAudioComponent.generated.h"

/**
 * UAshenDiegeticSoulConstellationAudioComponent
 * Audio component modulating Heartstone resonance chimes, imprint crystallisation tones, and Integration Debt escalation drones.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticSoulConstellationAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticSoulConstellationAudioComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float HeartstoneResonanceVolume = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerHeartstoneResonanceChime();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerDebtEscalationDrone(float DebtLevel);
};
