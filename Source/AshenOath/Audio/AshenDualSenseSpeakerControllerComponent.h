// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenDualSenseSpeakerControllerComponent.generated.h"

/**
 * UAshenDualSenseSpeakerControllerComponent
 * Manages DualSense hardware speaker output endpoint, volume attenuation, and synchronized haptic pulses for actionable tactical calls.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseSpeakerControllerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualSenseSpeakerControllerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float SpeakerVolume = 1.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	bool PlayControllerVoiceCue(const FString& Line, float HapticStrength);
};
