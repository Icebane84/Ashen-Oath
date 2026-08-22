// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenBerserkTargetTrackingComponent.generated.h"

/**
 * UAshenBerserkTargetTrackingComponent
 * 
 * Executes automated sphere-sweep hostile target acquisition and control rotation overrides during frenzy.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBerserkTargetTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBerserkTargetTrackingComponent();

	/** Evaluates target rotation lock towards closest hostile target */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|KineticBerserk")
	FRotator EvaluateTargetTrackingRotation(
		const FVector& CurrentLocation,
		const FRotator& CurrentRotation,
		const FVector& TargetLocation,
		float InterpSpeed = 12.0f,
		float DeltaSeconds = 0.016f) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|KineticBerserk")
	void SetTrackingMode(EAshenTargetTrackingMode NewMode);

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|KineticBerserk")
	EAshenTargetTrackingMode GetTrackingMode() const { return TrackingMode; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Combat|KineticBerserk")
	EAshenTargetTrackingMode TrackingMode = EAshenTargetTrackingMode::ManualFreeLook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Combat|KineticBerserk")
	float TrackingRadiusCentimeters = 1200.0f;
};
