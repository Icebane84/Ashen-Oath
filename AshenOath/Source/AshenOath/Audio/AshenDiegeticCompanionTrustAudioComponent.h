// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticCompanionTrustAudioComponent.generated.h"

/**
 * UAshenDiegeticCompanionTrustAudioComponent
 * Audio component playing harmony chords during ResonanceSync and discordant drones during trust divergence.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCompanionTrustAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticCompanionTrustAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerResonanceHarmonyChord();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerDivergenceDiscordDrone(float TrustDivergenceDelta);
};
