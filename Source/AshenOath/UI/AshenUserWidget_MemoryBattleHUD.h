// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MemoryBattleHUD.generated.h"

/**
 * UAshenUserWidget_MemoryBattleHUD
 * Displays active memory battle enemy trauma meter and imprint resolution gauge.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryBattleHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName DisplayedEchoID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float TraumaMeterPercent = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateMemoryBattleHUD(FName EchoID, float TraumaPercent);
};
