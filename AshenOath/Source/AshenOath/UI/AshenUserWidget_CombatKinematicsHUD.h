// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenUserWidget_CombatKinematicsHUD.generated.h"

/**
 * UAshenUserWidget_CombatKinematicsHUD
 * 
 * Somatosensory combat HUD widget visualizing weight class, dynamic i-frame timing bar, cardiac pulse indicator, and riposte surge timer.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CombatKinematicsHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_CombatKinematicsHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed kinematics telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Kinematics")
	void UpdateKinematicsHUD(const FCombatKinematicsVector& Kinematics);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Kinematics")
	FCombatKinematicsVector DisplayedKinematics;
};
