// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticCompanionFatigueAudioComponent.generated.h"

/**
 * UAshenDiegeticCompanionFatigueAudioComponent
 * Manages diegetic heavy breathing, fatigue grunts, and harmonious Resonance Sync bell chimes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCompanionFatigueAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticCompanionFatigueAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayFatigueBreathingCue(FName CompanionID, float FatigueLevel);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayResonanceHarmonicChime();
};
