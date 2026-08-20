// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticWhiteFlameAudioComponent.generated.h"

/**
 * UAshenDiegeticWhiteFlameAudioComponent
 * Plays triumphant incandescent audio: rushing white flame whooshes, resonant angelic choir swells, and crystalline bell chimes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticWhiteFlameAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticWhiteFlameAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayWhiteFlameIgnitionSFX();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPyreCleaveImpactSFX();
};
