// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenParasiteGutturalHeartbeatAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGutturalHeartbeatAudioUpdatedSignature, float, HeartbeatPitch, float, DistantCompanionScreamVolume);

/**
 * UAshenParasiteGutturalHeartbeatAudioModulator
 *
 * Audio Modulator handling muffled environmental audio, wet heartbeat pitch escalation, and distant companion screams (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenParasiteGutturalHeartbeatAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|HeartbeatAudio")
	void UpdateHeartbeatAudioPressure(float PromptTimerRemainingRatio);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HeartbeatAudio|Events")
	FOnGutturalHeartbeatAudioUpdatedSignature OnHeartbeatAudioUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|HeartbeatAudio")
	int32 TotalAudioPulsesPlayed = 0;
};
