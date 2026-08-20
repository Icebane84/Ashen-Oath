// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenInnerVoiceMeshTremorAdapter.generated.h"

/**
 * UAshenInnerVoiceMeshTremorAdapter
 * 
 * Drives subtle hand and weapon skeletal tremors when Kaelen's internal monologue
 * conflicts with his physical stance (e.g. Parasite whisper during Grace stance).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerVoiceMeshTremorAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerVoiceMeshTremorAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates dynamic tremor intensity */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Tremor")
	void UpdateTremor(EVoiceChannel ActiveChannel, float DistortionIntensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Tremor")
	float GetCurrentTremorScalar() const { return CurrentTremor; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Combat|Tremor")
	float TremorInterpSpeed = 5.0f;

private:
	float CurrentTremor = 0.0f;
	float TargetTremor = 0.0f;
};
