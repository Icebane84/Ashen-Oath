// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenUserWidget_KeystoneMemoryCrucibleHUD.generated.h"

/**
 * UAshenUserWidget_KeystoneMemoryCrucibleHUD
 * Mindscape UI presenting memory echoes and the 3 Interpretive Lenses (Accountability, Grace, Utility) to permanently compile identity.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_KeystoneMemoryCrucibleHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName ActiveMemoryID = NAME_None;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayMemoryCrucible(FName MemoryID);
};
