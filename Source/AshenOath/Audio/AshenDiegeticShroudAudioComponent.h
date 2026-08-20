// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticShroudAudioComponent.generated.h"

/**
 * UAshenDiegeticShroudAudioComponent
 * Eerie spectral phasing whoosh, searing white flame roar, creeping paranoia heartbeat.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticShroudAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticShroudAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlaySpectralPhaseSound();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPurifierFlameRoar();
};
