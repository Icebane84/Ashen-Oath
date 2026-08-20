// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenDiegeticBossEncounterAudioComponent.generated.h"

/**
 * UAshenDiegeticBossEncounterAudioComponent
 * Manages multi-phase dynamic boss music intensity layers, sub-bass void tremors, and cataclysm roar acoustics.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBossEncounterAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticBossEncounterAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TransitionPhaseMusic(EBossPhaseState Phase);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayCataclysmTremorSFX();
};
