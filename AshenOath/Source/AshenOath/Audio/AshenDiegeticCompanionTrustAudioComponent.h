// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenDiegeticCompanionTrustAudioComponent.generated.h"

class UAshenSoulPublisher;

/**
 * UAshenDiegeticCompanionTrustAudioComponent
 * Audio component playing harmony chords during ResonanceSync and discordant drones
 * during trust divergence, subscribing directly to UAshenSoulPublisher.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCompanionTrustAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticCompanionTrustAudioComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Audio")
	void TriggerResonanceHarmonyChord();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Audio")
	void TriggerDivergenceDiscordDrone(float TrustDivergenceDelta);

	UFUNCTION()
	void HandleRelationalMatrixUpdated(const FRelationalMatrix_V2& NewMatrix);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Audio")
	bool IsHarmonyActive() const { return bIsHarmonyActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Audio")
	bool bIsHarmonyActive = false;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
