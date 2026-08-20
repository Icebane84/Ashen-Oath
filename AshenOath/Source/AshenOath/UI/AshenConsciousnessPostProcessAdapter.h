// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenConsciousnessPostProcessAdapter.generated.h"

/**
 * UAshenConsciousnessPostProcessAdapter
 * Modulates subtle audio-reactive screen edge pulses matching controller speaker tactical bursts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConsciousnessPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenConsciousnessPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void TriggerTacticalAudioEdgePulse(float Intensity);
};
