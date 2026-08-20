// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenDebtEscalationAudioModulator.generated.h"

/**
 * UAshenDebtEscalationAudioModulator
 * Audio component modulating MetaSounds whisper frequency, pitch variance, and low-pass edge filtering based on current EAshenIntegrationDebtStage.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDebtEscalationAudioModulator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDebtEscalationAudioModulator();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	float WhisperSpawnFrequency = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	float PitchVarianceMultiplier = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateAudioModulationForDebtStage(EAshenIntegrationDebtStage Stage);
};
