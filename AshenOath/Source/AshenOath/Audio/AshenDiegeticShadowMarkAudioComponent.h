// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticShadowMarkAudioComponent.generated.h"

/**
 * UAshenDiegeticShadowMarkAudioComponent
 * Audio component for Shadow Mark crackle and emissive hum sounds.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticShadowMarkAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticShadowMarkAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerShadowMarkCrackleHum(float EmissiveIntensity);
};
