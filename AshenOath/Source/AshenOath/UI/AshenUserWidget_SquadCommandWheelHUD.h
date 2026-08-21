// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenUserWidget_SquadCommandWheelHUD.generated.h"

/**
 * UAshenUserWidget_SquadCommandWheelHUD
 * 
 * UMG/Slate widget displaying the 8-sector radial companion command wheel.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SquadCommandWheelHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_SquadCommandWheelHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the selected wheel sector based on gamepad stick angle */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Tactics")
	void UpdateSelectedSector(float StickAngleDegrees);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Tactics")
	int32 GetSelectedSectorIndex() const { return SelectedSectorIndex; }

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Tactics")
	ETacticalCommandType GetSelectedCommand() const { return SelectedCommand; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tactics")
	int32 SelectedSectorIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Tactics")
	ETacticalCommandType SelectedCommand = ETacticalCommandType::None;
};
