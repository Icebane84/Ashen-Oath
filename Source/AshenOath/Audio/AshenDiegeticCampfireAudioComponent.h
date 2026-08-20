// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticCampfireAudioComponent.generated.h"

/**
 * UAshenDiegeticCampfireAudioComponent
 * Crackling hearth ember pops, soothing acoustic resonance, warm sanctuary hum.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCampfireAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticCampfireAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayCampfireIgniteAmbience();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayHeartstoneResonanceChime();
};
