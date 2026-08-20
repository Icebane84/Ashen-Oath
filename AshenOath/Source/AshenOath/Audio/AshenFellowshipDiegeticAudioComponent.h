// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenFellowshipDiegeticAudioComponent.generated.h"

class USoundBase;
class UAudioComponent;

/**
 * UAshenFellowshipDiegeticAudioComponent
 * 
 * Modulates diegetic fellowship audio:
 * - Synchronized combat breathing rhythms during high flow
 * - Blade whetstone resonance at campfires
 * - Tense silence and avoided vocal barks during ActiveRupture
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFellowshipDiegeticAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFellowshipDiegeticAudioComponent();

	virtual void BeginPlay() override;

	/** Updates audio timbre and acoustic tension from relational rupture state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Fellowship")
	void UpdateRelationalAudio(ERelationalRuptureState RuptureState, float TrioResonance);

	/** Plays subtle wordless acknowledgement sound */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Audio|Fellowship")
	void PlayWordlessAcknowledgement(USoundBase* CueSound);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* BreathingAudioComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* AmbientFellowshipAudioComponent;
};
