// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticResonanceTetherActor.generated.h"

class USplineComponent;
class USplineMeshComponent;
class UAudioComponent;

/**
 * AAshenSomaticResonanceTetherActor
 * 
 * 3D world visual spline tether and spatial audio resonance actor linking Kaelen,
 * Garrett, and Serafina during High Relational Flow states (Psi >= 0.75).
 */
UCLASS()
class ASHENOATH_API AAshenSomaticResonanceTetherActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSomaticResonanceTetherActor();

	virtual void Tick(float DeltaTime) override;

	/** Updates the 3D tether endpoints connecting Kaelen to companion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Resonance")
	void UpdateTetherEndpoints(const FVector& KaelenLocation, const FVector& CompanionLocation, float RelationalFlow);

	/** Enables or disables the visual tether resonance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Resonance")
	void SetTetherActive(bool bActive, float FadeDuration = 0.5f);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Resonance")
	bool IsTetherActive() const { return bTetherActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USplineComponent* TetherSpline;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* ResonanceAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Resonance")
	float MaxTetherDistance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Resonance")
	float CurrentResonanceGlow = 0.0f;

private:
	bool bTetherActive = false;
	float TargetGlow = 0.0f;
};
