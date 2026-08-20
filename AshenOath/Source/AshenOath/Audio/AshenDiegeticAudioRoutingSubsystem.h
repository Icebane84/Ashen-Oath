// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenDiegeticAudioRoutingSubsystem.generated.h"

/**
 * UAshenDiegeticAudioRoutingSubsystem
 * GameInstance Subsystem managing the Proximity of Consciousness audio architecture, routing voices across World, Controller Speaker, and Somatic channels.
 */
UCLASS()
class ASHENOATH_API UAshenDiegeticAudioRoutingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	bool bControllerSpeakerEnabled = true;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	bool bHeadphoneDownmixActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	EAudioConsciousnessChannel ResolveEffectiveChannel(EAudioConsciousnessChannel RequestedChannel) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void DispatchVoiceCue(const FDualSenseVoiceCue& Cue);
};
