// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenDiegeticShadowSeepageAudioComponent.generated.h"

/**
 * UAshenDiegeticShadowSeepageAudioComponent
 * Manages spatial sound effects for sizzling bile acid drips, skin-tearing static crackles, and low-frequency eldritch hums.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticShadowSeepageAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticShadowSeepageAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateSeepageAudio(EShadowSeepagePhase Phase, float Corruption);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayCrimsonStaticBurstCue();
};
