// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenInnerWorldTypes.h"
#include "AshenInnerWorldLandscapeSubsystem.generated.h"

/**
 * UAshenInnerWorldLandscapeSubsystem
 * World Subsystem managing the metaphysical, fluid landscape of Oathbringer's Inner World based on Kaelen's psychological state.
 */
UCLASS()
class ASHENOATH_API UAshenInnerWorldLandscapeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Inner World")
	FOnInnerWorldLandscapeShifted OnInnerWorldLandscapeShifted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Inner World")
	EAshenInnerWorldLandscapeState CurrentLandscapeState = EAshenInnerWorldLandscapeState::SunDappledGlade;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Inner World")
	void EvaluateLandscapeStateFromSoulVector(float HopeScore, float DespairScore, float IntegrationDebt);
};
