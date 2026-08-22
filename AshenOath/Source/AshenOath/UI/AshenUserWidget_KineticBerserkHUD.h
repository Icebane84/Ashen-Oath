// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenUserWidget_KineticBerserkHUD.generated.h"

/**
 * UAshenUserWidget_KineticBerserkHUD
 * 
 * UMG widget visualizing angular riposte compass angles, Chaos debris audio LPF, and kinetic Joules output.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_KineticBerserkHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_KineticBerserkHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates kinetic diagnostics on the HUD */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|KineticBerserk")
	void UpdateKineticDiagnostics(
		EAshenCounterAttackZone CounterZone,
		float CounterAngleDegrees,
		float DebrisCutoffFrequency,
		float KineticJoules);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|KineticBerserk")
	EAshenCounterAttackZone DisplayedCounterZone = EAshenCounterAttackZone::VerticalOverhead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|KineticBerserk")
	float DisplayedAngleDegrees = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|KineticBerserk")
	float DisplayedCutoffFrequency = 20000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|KineticBerserk")
	float DisplayedKineticJoules = 4500.0f;
};
