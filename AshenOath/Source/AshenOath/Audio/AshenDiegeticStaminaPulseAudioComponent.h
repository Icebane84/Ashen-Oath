// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticStaminaPulseAudioComponent.generated.h"

/**
 * UAshenDiegeticStaminaPulseAudioComponent
 * Dynamic cardiac heartbeat audio that speeds up and amplifies as stamina approaches critical exhaustion.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticStaminaPulseAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticStaminaPulseAudioComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	bool bIsPulseActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateCardiacPulse(float CurrentStaminaRatio);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateStaminaPulseState(float CurrentStamina, float MaxStamina);
};
