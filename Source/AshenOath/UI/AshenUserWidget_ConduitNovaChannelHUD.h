// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ConduitNovaChannelHUD.generated.h"

/**
 * UAshenUserWidget_ConduitNovaChannelHUD
 * Visual channel progress bar linking Serafina and Kaelen during Conduit Nova execution.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ConduitNovaChannelHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ChannelProgress = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsChannelActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateChannelHUD(bool bActive, float Progress);
};
