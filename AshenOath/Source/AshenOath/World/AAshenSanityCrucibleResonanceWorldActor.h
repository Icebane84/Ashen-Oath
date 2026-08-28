// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AAshenSanityCrucibleResonanceWorldActor.generated.h"

/**
 * AAshenSanityCrucibleResonanceWorldActor
 * 
 * Spatial sanctuary altar actor channeling White Flame acoustic harmonic purges, instantly cleansing wielder delirium and resetting blade hunger.
 */
UCLASS()
class ASHENOATH_API AAshenSanityCrucibleResonanceWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanityCrucibleResonanceWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence")
	float GetCrucibleRadiusUU() const { return CrucibleRadiusUU; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence")
	float GetSanityPurgeRatePerSec() const { return SanityPurgeRatePerSec; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float CrucibleRadiusUU = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float SanityPurgeRatePerSec = 15.0f;
};
