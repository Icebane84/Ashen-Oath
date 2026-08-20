// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCombatAudioComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(
	FOnCombatMusicStemsUpdatedSignature,
	float, RhythmVol,
	float, MelodyVol,
	float, CorruptionDissonanceVol,
	float, TriumphVol
);

/**
 * UAshenCombatAudioComponent
 *
 * Dynamic 4-stem combat music controller driving MetaSounds and audio parameter buses:
 *   - Stem 1 (Base Rhythm): Combat engagement activity (0.0 to 1.0)
 *   - Stem 2 (Melody / Hope): Inverse HP ratio (softer when healthy, frantic when dying)
 *   - Stem 3 (Corruption Dissonance): Scaled directly by Kaelen's Shadow Mark corruption C
 *   - Stem 4 (Symbiotic Triumph): Active during Symbiotic Resonance flow states
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatAudioComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void SetInCombat(bool bInCombat);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void UpdateStems(float CurrentHPFrac, float Corruption, bool bResonanceActive);

	// --- Stem Volumes ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Audio")
	float RhythmStemVolume = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Audio")
	float MelodyStemVolume = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Audio")
	float CorruptionDissonanceStemVolume = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Audio")
	float TriumphStemVolume = 0.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Audio|Events")
	FOnCombatMusicStemsUpdatedSignature OnStemsUpdated;

private:
	bool bIsInCombat = false;
	float InterpSpeed = 3.0f;
};
