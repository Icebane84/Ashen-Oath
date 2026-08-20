// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenDiegeticCombatStanceAudioComponent.generated.h"

/**
 * UAshenDiegeticCombatStanceAudioComponent
 * Manages stance-specific audio signatures: heavy iron clash (Aegis), blood rush pulse (Berserk), and harmonic chime (Flow).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCombatStanceAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticCombatStanceAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayStanceTransitionAudio(ECombatStance NewStance);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayFlankCriticalImpactCue();
};
