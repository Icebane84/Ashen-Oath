// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticOathBreachAudioComponent.generated.h"

/**
 * UAshenDiegeticOathBreachAudioComponent
 * Audio component executing the signature -50 cents pitch drop, shattering glass stingers, and resonant remorse drones.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticOathBreachAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticOathBreachAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerOathBreachAudioStinger();
};
