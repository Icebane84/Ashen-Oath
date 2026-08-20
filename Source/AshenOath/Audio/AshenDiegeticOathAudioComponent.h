// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenDiegeticOathAudioComponent.generated.h"

/**
 * UAshenDiegeticOathAudioComponent
 * Manages ethereal oath vow chimes, demonic parasitic whispers, and oathbreaker glass shattering sound cues.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticOathAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticOathAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayOathSwornChime();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayOathbreakerShatterSound();
};
