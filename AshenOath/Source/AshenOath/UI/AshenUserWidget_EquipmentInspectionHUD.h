// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_EquipmentInspectionHUD.generated.h"

/**
 * UAshenUserWidget_EquipmentInspectionHUD
 * 3D inspection view showcasing inscribed weapon runes, blade sharpness, and oil coatings.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_EquipmentInspectionHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName InspectedItemName = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 InscribedRuneCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void InspectWeapon(FName ItemName, int32 RuneCount);
};
