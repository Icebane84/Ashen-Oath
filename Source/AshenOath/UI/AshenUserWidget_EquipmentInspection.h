// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_EquipmentInspection.generated.h"

/**
 * UAshenUserWidget_EquipmentInspection
 *
 * UMG backing widget for Equipment Inspection ("What am I carrying?").
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_EquipmentInspection : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void InspectEquipmentStoryWear(FName WeaponID, FString BattleMarkNotes, float SootDarkeningPercent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveInspectedWeaponID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FString ActiveBattleMarkNotes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveSootDarkeningPercent = 0.0f;
};
